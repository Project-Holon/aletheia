/*
 * function: func_021D51DC
 * address: 0x021D51DC
 * packet: pkt_ov093_021D51DC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_POKEPARAM_SetMoveInfo 0x021D5208 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S { u16 h[6]; u8 f0c; };
extern void BTL_POKEPARAM_SetMoveInfo(struct S *p, u32 a, u32 b);
void func_021D51DC(struct S *p, u32 a, u32 b, u32 c)
{
    if (c != 0) {
        BTL_POKEPARAM_SetMoveInfo(p, a, b);
        if (p->f0c != 0) {
            p->h[3] = p->h[0];
            p->h[4] = p->h[1];
            p->h[5] = p->h[2];
        }
    } else {
        BTL_POKEPARAM_SetMoveInfo((struct S *)(p->h + 3), a, b);
        p->f0c = 0;
    }
}
