/*
 * function: func_021F52B0
 * address: 0x021F52B0
 * packet: pkt_ov076_021F52B0
 * region: ov076
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F52D8 0x021F52D8 thumb ov076
 *   func_02189A08 0x02189A08 thumb ov021
 *   func_021CF560 0x021CF560 thumb ov021
 */
typedef unsigned int u32;
extern void *func_021F52D8(void *, u32, u32, u32, int);
extern int func_02189A08(int);
extern u32 func_021CF560(u32 *);
void *func_021F52B0(void *a, u32 b, int c) {
    void *h;
    h = func_021F52D8(a,b,11,10,c);
    *(u32 *)(func_021CF560((u32 *)func_02189A08(b)) + 0x40) = 0x7F3;
    return h;
}
