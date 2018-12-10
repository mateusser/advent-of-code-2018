const fs = require('fs')

let data = ''
let readStream = fs.createReadStream('../input.in', 'utf8')

readStream.on('data', function(chunk) {  
  data += chunk
}).on('end', function() {
  const before = data.length

  for (let i = 0; i < (data.length - 1); i = i + 1) {
    const code = data.charCodeAt(i)
    const codeNext = data.charCodeAt(i + 1)
    const diff = code - codeNext
    if (diff === 32 || diff === -32) { // react and destroy
      const before = data.slice(0, i)
      const after = data.slice(i + 2, data.length)
      data = before + after
      i = -1
    }
  }

  console.log('Before:', before)
  console.log('After: ', data.length)
})
