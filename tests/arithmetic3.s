ADDI $1, $1, 14
ADD $3, $2, $1
SUB $4, $2, $1
MULT $4, $3
MFHI $5
MFLO $6
DIV $1, $2
SLT $9, $5, $6
AND $10, $7, $8
OR $11, $9, $7
LW $12, 2($9)
SW $11, 4($9)
SLL $7, $18, 9
SRL $11, $6, 19
XOR $8, $5, $3
JR $17
LUI $17, 11

# EXPECTED_ASSEMBLY
# 2021000E
# 00411820
# 00412022
# 00830018
# 00002810
# 00003012
# 0022001A
# 00A6482A
# 00E85024
# 01275825
# 8D2C0002
# AD2B0004
# 00123A40
# 00065CC2
# 00A34026
# 02200008
# 3C11000B
