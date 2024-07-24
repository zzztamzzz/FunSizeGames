const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let board = [
    ['1', '2', '3'],
    ['4', '5', '6'],
    ['7', '8', '9']
];

let currentPlayer = 'X';

function printBoard() {
    console.log('\n');
    board.forEach(row => {
        console.log(row.join(' | '));
    });
    console.log('\n');
}

function checkWin(player) {
    // Check rows, columns and diagonals
    for (let i = 0; i < 3; i++) {
        if (board[i][0] === player && board[i][1] === player && board[i][2] === player) return true;
        if (board[0][i] === player && board[1][i] === player && board[2][i] === player) return true;
    }
    if (board[0][0] === player && board[1][1] === player && board[2][2] === player) return true;
    if (board[0][2] === player && board[1][1] === player && board[2][0] === player) return true;
    return false;
}

function checkDraw() {
    return board.flat().every(cell => cell === 'X' || cell === 'O');
}

function makeMove(position) {
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            if (board[i][j] === position) {
                board[i][j] = currentPlayer;
                return true;
            }
        }
    }
    return false;
}

function switchPlayer() {
    currentPlayer = currentPlayer === 'X' ? 'O' : 'X';
}

function promptMove() {
    printBoard();
    rl.question(`Player ${currentPlayer}, enter a position (1-9): `, (position) => {
        if (makeMove(position)) {
            if (checkWin(currentPlayer)) {
                printBoard();
                console.log(`Player ${currentPlayer} wins!`);
                rl.close();
                return;
            }
            if (checkDraw()) {
                printBoard();
                console.log('The game is a draw!');
                rl.close();
                return;
            }
            switchPlayer();
        } else {
            console.log('Invalid move. Try again.');
        }
        promptMove();
    });
}

console.log('Welcome to Tic-Tac-Toe!');
promptMove();
