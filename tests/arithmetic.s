# Projet MIPS 2022-2023
# Auteurs : Cocagne_Strainovic

ADDI $5, $0, 5
ADDI $2, $0, 11
ADD $7, $5, $2
ADDI $11, $10, 7
SUB $8, $3, $2
DIV $5, $2
MFHI $9
MFLO $10
MULT $5, $2


# EXPECTED_ASSEMBLY
# 20050005
# 2002000B
# 00A23820
# 214B0007
# 00624022
# 00A2001A
# 00004810
# 00005012
# 00A20018

# EXPECTED_FINAL_STATE
# $02:11
# $05:5
# $07:16
# $08:-11
# $09:5
# $10:0
# $11:7
# HI:0
# LO:55