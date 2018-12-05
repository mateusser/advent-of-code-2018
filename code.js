const fs = require('fs')

let data = ''

const readStream = fs.createReadStream('input.in', 'utf8')

readStream.on('data', function(chunk) {  
  data += chunk
}).on('end', () => {
  const ids = data.split('\r\n')
  const values = []
  for (let i = 0; i < ids.length; i = i + 1) {
    for (let j = 0; j < ids.length; j = j + 1) {
      const str1 = ids[i]
      const str2 = ids[j]
      let id = ''
      for (let k = 0; k < 26; k = k + 1) {
        const char1 = str1.charCodeAt(k)
        const char2 = str2.charCodeAt(k)
        if (char1 === char2) {
          id = `${id}${String.fromCharCode(char1)}`
        }
      }
      if ((str1.length - id.length) === 1) {
        console.log(id)
        return
      }
      values.push(id)
    }
  }
  values.sort((id1, id2) => id2.length - id1.length)
  console.log('Final value', values[0])
})
