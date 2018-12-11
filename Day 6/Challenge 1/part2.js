let areas = [830, 7124, 2286, 2801, 22678, 3420, 2417, 1866, 2670, 5278, 3925, 478, 3414, 6670, 801, 2360, 3150, 2199, 1349, 3212, 2598, 7039, 2439, 14288, 2294, 1759, 8576, 2988, 1268, 7454, 1329, 1661, 12156, 7982, 1024, 1446, 3536, 914, 3040, 920, 2085, 2386, 1070, 1264, 924, 1323, 4746, 19799, 10480, 3700]

let excluded = [48, 21, 13, 29, 4, 44, 27, 2, 38, 34, 0, 36, 10, 47, 19, 26, 32, 23, 3, 46, 1, 9, 33, 49, 15]

let filtered = areas.filter((area, idx) => excluded.findIndex(a => a === idx) === -1)

console.log(filtered.sort((a, b) => a - b))
console.log(filtered.length)