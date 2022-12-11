Assume CS: Code DS: Data
DATA SEGMENT
    ANS DW 8
    DATA ENDS
CODE SEGMENT
    START:
    MOV AX, @DATA
    MOV DS, AX
    MOV AX, 6
    MOV CX, 5
    MOV BX, AX
    SUB BX, 1
    L:
    MUL BX
    SUB BX, 1
    LOOP L
    MOV ANS, AX
    CODE ENDS
END START       
HLT