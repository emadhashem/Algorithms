function createMatrix(a, b) {
    return new Array(a).fill(0).map(() => new Array(b).fill(0))
}
function solve(arr = [], n) {
    // array size
    let blks_sz = arr.length;
    let max_row = 0;
    let number_of_aisel_seats = 0;
    // col, row => row, col
    for (let i in arr) {
        let block = arr[i]
        block = [block[1], block[0]]
        arr[i] = block
        max_row = Math.max(block[0], max_row)
        number_of_aisel_seats += 2 * block[0]
    }
    number_of_aisel_seats -= arr[0][0] + arr[blks_sz - 1][0];
    let ansTable = []
    for (let block of arr) {
        let cur = createMatrix(...block)
        ansTable.push(cur)
    }
    let start = 1;

    // aisle seats
    let cur_row = 1;
    while (start <= number_of_aisel_seats && cur_row <= max_row) {
        for (let i = 0; i < blks_sz; i++) {
            // size of cur col of the block
            let y = arr[i][1], x = arr[i][0];
            if (cur_row > x) continue;
            if (i == 0) {
                ansTable[i][cur_row - 1][y - 1] = start++;
            } else if (i == blks_sz - 1) {
                ansTable[i][cur_row - 1][0] = start++;
            } else {
                ansTable[i][cur_row - 1][0] = start++;
                if (y > 1) ansTable[i][cur_row - 1][y - 1] = start++;
            }
        }
        cur_row++;
    }

    // window seats
    cur_row = 1;
    let x1 = arr[0][0], x2 = arr[blks_sz - 1][0];
    let y = arr[blks_sz - 1][1];
    while (start <= n && cur_row <= max_row) {
        if (cur_row <= x1) {
            ansTable[0][cur_row - 1][0] = start++;
        }
        if (cur_row <= x2) {
            ansTable[blks_sz - 1][cur_row - 1][y - 1] = start++;
        }
        cur_row++;
    }

    // middle seats (any order)
    for (let block in ansTable) {

        for (let i = 0; i < ansTable[block].length; i++) {
            if (start > n) break
            for (let j = 0; j < ansTable[block][i].length; j++) {
                if (start > n) break
                if (ansTable[block][i][j] == 0) ansTable[block][i][j] = start++
            }
        }
        if (start > n) break
    }

    printAns(ansTable)
}
function printAns(ansTable) {
    for (let block of ansTable) {
        let s = ''
        for (let i in block) {

            for (let j in block[i]) {

                s += (block[i][j] + ' ')
            }
            s += '\n'
        }
        console.log(s);
    }

}


const arr = [
    [3, 2],
    [4, 3],
    [2, 3],
    [3, 4],
]
solve(arr, 30)

/**
 * 
 *  Let say that each block of seats is of (n * m) size and the Airplane contains b block of seats.
 *  The Time complexity is (n * m * b)
 *  The Space complexity is (n * m * b)
 */