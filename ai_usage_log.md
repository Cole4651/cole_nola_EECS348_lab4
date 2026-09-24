# AI Usage Log

## Interaction 1
### User
Can you help me write a C program that determines all possible combinations of scoring plays for an NFL game given a score?

### Assistant Summary
The assistant inspected the empty project files and implemented `task1.c`. The program accepts a non-negative score and recursively enumerates combinations of 2-point plays, 3-point field goals, 6-point touchdowns, 7-point touchdowns with an extra-point kick, and 8-point touchdowns with a 2-point conversion. The assistant compiled the program with strict compiler warnings and tested it with score 10 and an impossible low score.

## Interaction 2
### User
Can you make a Makefile to compile this program and remove both executables: "all" and "clean"?

### Assistant Summary
The assistant inspected the project and created a `Makefile` with `all` and `clean` targets. The build uses `gcc -std=c11 -Wall -Wextra -pedantic`. The assistant verified that `make all` builds `task1`, that the executable runs, and that `make clean` removes it.

## Interaction 3
### User
For task 1 can you change the format so it is like this where the zeros are changing:

`0 TD + 2pt, 0 TD + FG, 0 TD, 0 3pt FG, 0 Safety`

### Assistant Summary
The assistant changed the output format in `task1.c` so combinations are displayed in the requested order: touchdown plus 2-point conversion, touchdown plus field goal, touchdown, 3-point field goal, and safety. The assistant compiled and ran the program with score 10 to verify the output.

## Interaction 4
### User
Write a C program that performs temperature conversions between Fahrenheit, Celsius, and Kelvin. The program should prompt for a temperature, input scale, and conversion target; display the converted temperature; categorize it; and provide a weather advisory.

### Assistant Summary
The assistant implemented `task2.c`. It supports Fahrenheit, Celsius, and Kelvin conversions, validates scale choices, rejects negative Kelvin input, converts through Celsius, categorizes the result as Freezing, Cold, Comfortable, Hot, or Extreme Heat, and displays a weather advisory. The assistant interpreted the stated Hot range as 25°C to below 35°C because that matches the surrounding category descriptions. The program was compiled with strict warnings and tested at category boundaries.

The assistant also updated the `Makefile` so `make all` builds both `task1` and `task2`, while `make clean` removes both executables. The complete build and cleanup process was verified successfully.
