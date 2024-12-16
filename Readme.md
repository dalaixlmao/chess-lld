# Chess Validator

## Project Overview

This is a console-based Chess Validator implemented in C++ that allows two players to play chess with basic movement validation and turn-based gameplay.

## Features

### Piece Movement Validation
- Supports movement validation for all standard chess pieces:
  - Pawns
  - Rooks
  - Knights
  - Bishops
  - Queens
  - Kings

### Game Mechanics
- Turn-based gameplay
- Board rotation for alternating players
- Move input validation
- Real-time board display

## Project Structure

```
src/
│
├── models/
│   ├── Board.cpp       # Board representation and basic operations
│   └── Piece.cpp       # Piece class definition
│
├── services/
│   ├── GameService.cpp # Game logic and move coordination
│   └── PieceService.cpp # Piece-specific move validation
│
├── storage/
│   └── Storage.cpp     # Game state storage
│
└── main.cpp            # Main game loop and entry point
```

## Requirements

- C++ Compiler (C++11 or later)
- Standard Template Library (STL)

## Compilation

```bash
g++ -std=c++11 src/main.cpp -o chess_validator
./chess_validator
```

## How to Play

1. Run the executable
2. Input moves in algebraic notation (e.g., 'a2 a4')
3. Alternate between White (W) and Black (B) players
4. Game continues until manually terminated

### Move Input Format
- First input: Source cell (e.g., 'a2')
- Second input: Destination cell (e.g., 'a4')

### Example
```
Initial input: a2 a4
```

## Implemented Validations

- Cell Validation
- Color Validation
- Piece-Specific Move Validation

## Limitations

- No advanced chess rules implemented
  - No check/checkmate detection
  - No en passant
  - No castling
  - No pawn promotion

## Future Improvements

- Implement advanced chess rules
- Add check/checkmate detection
- Improve pawn movement logic
- Enhance error handling
- Create a more robust move validation system