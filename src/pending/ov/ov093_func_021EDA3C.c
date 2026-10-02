/*
 * function: func_021EDA3C
 * address:  0x021EDA3C
 * packet:   pkt_ov093_021EDA3C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-02 (wave B2 lane 06): all instructions match except the return-block layout.
 * Original: cmp r0,#0; beq L; movs r0,#0; pop; L: movs r0,#1; pop. Every spelling tried
 * (if/else, early return, ternary, !call, == 0, int local, u8/u32 return, u8/u32 callee)
 * compiles to cmp; bne L; movs r0,#1; pop; L: movs r0,#0; pop (3 bytes differ).
 * Callee is called as (p, byte) and the only caller family passes the record index through it.
 *
 * symbols:
 *   func_021B9AE0  0x021B9AE0  thumb  ov093
 *   func_021B8BD0  0x021B8BD0  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 func_021B9AE0(u32);
extern int func_021B8BD0(u8 *, u8);
int func_021EDA3C(u8 *p, u32 x)
{
    if (func_021B8BD0(p, func_021B9AE0(x)) == 0)
        return 1;
    return 0;
}
