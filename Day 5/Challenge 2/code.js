const fs = require('fs')

let data = ''
let readStream = fs.createReadStream('../input.in', 'utf8')

readStream.on('data', function(chunk) {  
  data += chunk
}).on('end', function() {
  const polymer = data
  let minSize = polymer.length

  const start = 'A'.charCodeAt(0)
  const end = 'Z'.charCodeAt(0)

  for (let i = start; i <= end; i = i + 1) {
    let regex = new RegExp(String.fromCharCode(i), 'gi')
    let newPolymer = polymer.replace(regex, '')
    const newSize = react(newPolymer)
    if (newSize < minSize) minSize = newSize
  }
  console.log(minSize)
})

const react = (polymer) => {
  for (let i = 0; i < (polymer.length - 1); i = i + 1) {
    const code = polymer.charCodeAt(i)
    const codeNext = polymer.charCodeAt(i + 1)
    const diff = code - codeNext
    if (diff === 32 || diff === -32) { // react and destroy
      const before = polymer.slice(0, i)
      const after = polymer.slice(i + 2, polymer.length)
      polymer = before + after
      i = -1
    }
  }

  return polymer.length
}