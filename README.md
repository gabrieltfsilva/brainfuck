# brainfuck
brainfuck interpreter

How to use:\
\
brainfuck.exe -s "string"\
brainfuck.exe -f "file.bf"\
String: maximum 100 characters.\
File: maximum 50,000 characters.\
\
Instructions\
 \
`>` = Moves memory pointer to the right by 1 block.\
`<` = Moves memory pointer to the left by 1 block.\
`+` = Increases the memory value by 1.\
`-` = Decreases the memory value by 1.\
`[` = Starts a loop.\
`]` = If current blocks's value is not zero, goes to `[`.\
`,` = Input 1 character from the console.\
`.` = Print 1 character to the console.\
 \
Memory map\
\
Addresses: 0 - 60,000 (0x0000 - 0xEA60)\
Starting Address: 30,000 (0x7530)
