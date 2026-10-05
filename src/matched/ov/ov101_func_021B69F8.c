/*
 * function: func_021B69F8
 * address: 0x021B69F8
 * packet: pkt_ov101_021B69F8
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * 2026-10-05: the callee func_021B6BFC is declared u32 here. Its matched definition
 * (ov101_func_021B6BFC.c) is void but tail-calls func_02031330, which returns u32, and
 * this caller tests r0 after the call. With the void declaration the old draft did not match.
 *
 * symbols:
 *   func_02005E50 0x02005E50 thumb
 *   func_021B6BFC 0x021B6BFC thumb ov101
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_02005E50(void);
extern u32 func_021B6BFC(u8 *);
int func_021B69F8(void *task, u32 *state, void *unused, u8 *p) {
    switch (*state) {
    case 0:
        if (!func_02005E50()) *state += 1;
        break;
    case 1:
        if (func_021B6BFC(p + 4) == 0)
            (*(void (**)(u8 *, u8 *))(p + 20))(p, p + 24);
        if (*(u32 *)(p + 28)) return 1;
        break;
    }
    return 0;
}
