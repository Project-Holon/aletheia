# A compound add to a narrow parameter keeps the sum in its home register

summary: `value += x;` on an s16 parameter in each arm keeps the narrowed sum
in the parameter's callee-saved home and copies it into the argument
register; `value = value + x;`, a fresh local or one expression lets 1.1p1
narrow straight into the argument register and elide the copy (four bytes
short on ARM).

Found in: src/matched/sub_0204B49C.c (0x0204B49C)

The image (ARM, 1.1p1 -O4,p):

    mov   r6, r1                 ; s16 value homed in r6
    ...
    bl    func_0204CF74
    cmp   r4, #0
    ldrsheq r0, [sp]
    mov   r2, r4
    ldrshne r0, [sp, #2]
    add   r0, r6, r0
    lsl   r0, r0, #0x10
    asr   r6, r0, #0x10          ; back into the parameter's register
    mov   r0, r5
    mov   r1, r6                 ; the copy
    bl    sub_0204B550

`if (axis == 0) value += origin.x; else value += origin.y;` is EXACT (with
`!axis` too). Four waves of spellings stayed at 76 bytes with `asr r1` and
no copy: `value = value + origin.x` in the arms, a named s16 local for the
origin or the sum, the ternary in one expression, and every type and const
variation of those. A local initialised from the parameter and then `o +=`
in the arms was 13 out (homes right, copy still elided). When the only
residue is a missing `mov rArg, rHome` after a narrowing, write the update
as a compound assignment on the parameter itself.
