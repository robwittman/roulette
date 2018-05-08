Line 29: Missing `{` after else keyword

Comparison using `=`, which assigns value, as opposed to `==`, which will compare

Dont need `(roll != choice2)`. `if (roll == choice2)` assumes that any cases entering the else block are not equal

`while (choice2 <= 36)` causes an infinite loop, since if they choose 12, that while loop never exits

They can select a bet type, but not an actual bet

`STDIN` reads input as string. Comparing the string inputs choice to the integer `1` or `2` will be false. `1 !== '1'`
