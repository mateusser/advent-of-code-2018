let fs = require('fs')

let data = ''
let readStream = fs.createReadStream('input.in', 'utf8')

readStream.on('data', function(chunk) {  
  data += chunk
}).on('end', function() {
  const inputs = data.split('\r\n').map(line => {
    let [date, hour, action, id] = line.split(' ')

    date = date.replace('[', '')
    hour = hour.replace(']', '')
    id = id.replace('#', '')

    if (action === 'wakes' || action === 'falls') id = ''

    return { date, hour, action, id }
  })

  inputs.sort((a, b) => {
    // same date, goes for hour
    if (a.date.localeCompare(b.date) === 0) {
      return a.hour.localeCompare(b.hour)
    }

    return a.date.localeCompare(b.date)
  })

  // console.log(inputs)

  let guards = {}
  let id = -1
  let awake = true
  let sleepedAt = 0
  inputs.forEach(input => {
    switch (input.action) {
      case 'Guard': // guard started shift
        // save info from past guard
        if (id !== -1 && !awake) {
          console.log('DANGER') // just to make sure no guard is sleeping by the end of the shift
        }
        // set up for new guard
        id = input.id
        if (!guards[id]) {
          guards[id] = {
            minutesSleeping: 0,
            '0': 0,
            '1': 0,
            '2': 0,
            '3': 0,
            '4': 0,
            '5': 0,
            '6': 0,
            '7': 0,
            '8': 0,
            '9': 0,
            '10': 0,
            '11': 0,
            '12': 0,
            '13': 0,
            '14': 0,
            '15': 0,
            '16': 0,
            '17': 0,
            '18': 0,
            '19': 0,
            '20': 0,
            '21': 0,
            '22': 0,
            '23': 0,
            '24': 0,
            '25': 0,
            '26': 0,
            '27': 0,
            '28': 0,
            '29': 0,
            '30': 0,
            '31': 0,
            '32': 0,
            '33': 0,
            '34': 0,
            '35': 0,
            '36': 0,
            '37': 0,
            '38': 0,
            '39': 0,
            '40': 0,
            '41': 0,
            '42': 0,
            '43': 0,
            '44': 0,
            '45': 0,
            '46': 0,
            '47': 0,
            '48': 0,
            '49': 0,
            '50': 0,
            '51': 0,
            '52': 0,
            '53': 0,
            '54': 0,
            '55': 0,
            '56': 0,
            '57': 0,
            '58': 0,
            '59': 0
          }
        }
        awake = true
        break
      case 'wakes': // guard waked up
        if (!awake) { // count minutes sleeping
          const awakeAt = Number(input.hour.split(':')[1])
          const minutesSleeping = awakeAt - sleepedAt
          for (let i = sleepedAt; i < awakeAt; i = i + 1) {
            guards[id][i] = guards[id][i] + 1
          }
          guards[id].minutesSleeping = guards[id].minutesSleeping + minutesSleeping
        }
        awake = true
        break
      case 'falls': // guard is sleeping
        awake = false
        sleepedAt = Number(input.hour.split(':')[1])
        break
    }
  })

  // get the guard who sleeps the most
  let sleepMost = 0
  let sleepMostId = -1
  Object.keys(guards).forEach(id => {
    if (guards[id].minutesSleeping > sleepMost) {
      sleepMost = guards[id].minutesSleeping
      sleepMostId = id
    }
  })

  // get the minute he sleeps the most
  let minuteMost = 0
  let minuteMostId = -1
  Object.keys(guards[sleepMostId]).forEach(minute => {
    if (isNaN(minute)) return
    if (guards[sleepMostId][minute] > minuteMost) {
      minuteMost = guards[sleepMostId][minute]
      minuteMostId = minute
    }
  })

  console.log('ID:', sleepMostId)
  console.log('Clock Minutes:', minuteMostId)
  console.log('ID * Minute:', minuteMostId * sleepMostId)

})
