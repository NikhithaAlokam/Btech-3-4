Assume CS: Code DS: Data
DATA SEGMENT
    ANS DW 0
    DATA ENDS
CODE SEGMENT
    START:
    MOV AX, @DATA
    MOV DS, AX
    MOV AX, 6
    MOV CX, AX
    DEC CX
    MOV BX, AX
    DEC BX
    L:
    MUL BX
    DEC BX
    LOOP L
    MOV ANS, AX
    CODE ENDS
END START       
