var fs = require('fs')

const FABRIC_SIZE = 1000

var data = ''
var readStream = fs.createReadStream('input.in', 'utf8')

readStream.on('data', function(chunk) {  
  data += chunk
}).on('end', function() {
  const pieces = data.split('\r\n')

  let line = []
  for (let i = 0; i < FABRIC_SIZE; i = i + 1) line.push(`.`)
  let fabric = []
  for (let i = 0; i < FABRIC_SIZE; i = i + 1) fabric.push(line)

  pieces.forEach((piece, idx) => {
    if (idx > 0) return
    const [id, tail] = piece.split('@')
    const [starts, sizes] = tail.split(':')
    const [startX, startY] = starts.split(',')
    const [width, height] = sizes.split('x')
    console.log(`startX  `, startX)
    console.log(`startY   `, startY)
    console.log(`width   `, width)
    console.log(`height   `, height)
    let numAssing = 0
    for (let y = 0; y < height; y = y + 1) {
      for (let x = 0; x < width; x = x + 1) {
        const yValue = y + parseInt(startY)
        const xValue = x + parseInt(startX)
        const curr = fabric[yValue][xValue]
        console.log(curr)
        // console.log(xValue, yValue)
        if (curr.charCodeAt(0) === '.'.charCodeAt(0)) {
          console.log(xValue, yValue)
          console.log(`before`, fabric[yValue][xValue], fabric[yValue + 1][xValue], fabric[yValue + 2][xValue])
          fabric[yValue].splice(xValue, 1, '#')
          console.log(`after`, fabric[yValue][xValue], fabric[yValue + 1][xValue], fabric[yValue + 2][xValue])
        }
        else if (curr.charCodeAt(0) === '#'.charCodeAt(0)) {
          console.log(xValue, yValue)
          console.log(`before`, fabric[yValue][xValue])
          fabric[yValue].splice(xValue, 1, 'X')
          console.log(`after`, fabric[yValue][xValue])
        }
      numAssing = numAssing + 1
      }
    }
    console.log('numAssing', numAssing)
  })
  
  let sumP = 0
  let sumH = 0
  let sumX = 0
  for (let y = 0; y < FABRIC_SIZE; y = y + 1) {
    for (let x = 0; x < FABRIC_SIZE; x = x + 1) {
      if (fabric[y][x] === 'X') sumX = sumX + 1
      else if (fabric[y][x] === '.') sumP = sumP + 1
      else if (fabric[y][x] === '#') sumH = sumH + 1
    }
  }

  // const fb = fabric.join().replace(/,/g, '')
  // console.log(fb)
  // console.log(typeof fb)

  console.log('.', sumP)
  console.log('#', sumH)
  console.log('X', sumX)
  console.log(sumP + sumH + sumX)
})
