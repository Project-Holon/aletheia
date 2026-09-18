/*
 * function: func_02052F58
 * address:  0x02052F58
 * packet:   pkt_0205250C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF, 44 of the original's 48 bytes: the original opens `stmfd sp!,{lr}; sub sp,sp,#4` (a live 4-byte frame) and masks with a pool-loaded 0xFFFF plus `and`; every spelling tried (`& 0xFFFF`, `(u16)` cast, local mask, ternary, 64-bit operand) folds the mask to lsl#16/lsr#13 and drops the frame
 *
 * The mask is spelled `& 0xFFFF`, not a `(u16)` cast: the cast folds into a
 * single lsl/lsr pair (see func_02051AA0), the mask costs a pool word plus a
 * live `and`.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02052F58.c \
 *       --func func_02052F58 --addr 0x02052F58 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32 g_020A8148;

int func_02052F58(int a, int b)
{
    return (((int (*)(int, int, int))g_020A8148)(a, b, 0) & 0xFFFF) << 3;
}
