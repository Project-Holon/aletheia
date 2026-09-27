/*
 * unit:     yes
 * function: _ll_mul, _ll_shl
 * address:  0x0209C054
 * packet:   pkt_0209C054_misc
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT (each verified independently with match.py one)
 *
 * PENDING, not filed to the manifest -- see converters.c in this same
 * scratchpad for the leak reason (tools/worklist.py's proven_game
 * short-circuit at a layout/runtime_arm9.txt address; no manifest kind
 * exists for hand-written runtime library code).
 *
 * _ll_mul: 64x64->64 multiply, `push {r4,r5,lr}` / `pop {r4,r5,lr}; bx lr`
 * rather than `pop {r4,r5,pc}` for a leaf -- one of the dead-prologue tells
 * in docs/notes/pkt_0209BDBC_runtime_library.c.txt.
 * _ll_shl: 64-bit shift left, immediately follows _ll_mul with no gap.
 *
 * Note: 0x0209D724 (_runtime_null_stub in the same docs note) is NOT a row
 * in the current layout/runtime_arm9.txt and is already filed as ordinary
 * game C, src/matched/func_0209D724.c (`void func_0209D724(void) {}`,
 * EXACT) -- nothing to do here for that address.
 *
 * Verified with:
 *   python tools/match.py one --src <this file> --func <name> --addr <addr>
 *     --cc 1.1p1 --arm
 */

asm void _ll_mul(void)
{
    stmdb sp!, {r4, r5, lr}
    umull r5, r4, r0, r2
    mla r4, r0, r3, r4
    mla r4, r2, r1, r4
    mov r1, r4
    mov r0, r5
    ldmia sp!, {r4, r5, lr}
    bx lr
}

asm void _ll_shl(void)
{
    ands r2, r2, #0x3f
    bxeq lr
    subs r3, r2, #0x20
    bge L_0209C098
    rsb r3, r2, #0x20
    mov r1, r1, lsl r2
    orr r1, r1, r0, lsr r3
    mov r0, r0, lsl r2
    bx lr
L_0209C098:
    mov r1, r0, lsl r3
    mov r0, #0
    bx lr
}
