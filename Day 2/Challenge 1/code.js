var fs = require('fs')

var data = ''

var readStream = fs.createReadStream('input.in', 'utf8')

readStream.on('data', function(chunk) {  
  data += chunk
}).on('end', function() {
  const ids = data.split('\r\n')
  let total2 = 0
  let total3 = 0
  ids.forEach(id => {
    let sum2 = false
    let sum3 = false
    for (let i = 0; i < id.length; i = i + 1) {
      const char = id.charAt(i)
      const newStr = id.replace(RegExp(char, 'g'), '')
      console.log(newStr)
      const diff = id.length - newStr.length
      if (diff === 2) sum2 = true
      else if (diff === 3) sum3 = true
    }
    if (sum2) total2 = total2 + 1
    if (sum3) total3 = total3 + 1
  })
  console.log(`Total 2: ${total2}`)
  console.log(`Total 3: ${total3}`)
  console.log(total2 * total3)
})
