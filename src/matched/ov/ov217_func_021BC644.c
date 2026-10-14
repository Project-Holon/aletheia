/*
 * function: func_021BC644
 * address: 0x021BC644
 * packet: pkt_ov217_021BC644
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 *
 * symbols:
 *   ListViewState_GetMode 0x021C0DF0 thumb ov217
 *   ListViewState_GetScrollX 0x021C0DF4 thumb ov217
 *   ListViewState_GetScrollY 0x021C0DF8 thumb ov217
 *   func_021BC3B8 0x021BC3B8 thumb ov217
 */
struct S { char pad0[4]; void *f4; char pad8[0x2a]; unsigned char f32; char pad33; int f34; };
typedef unsigned int   u32;
extern u32 ListViewState_GetMode(void *p);
extern u32 ListViewState_GetScrollX(void *p);
extern u32 ListViewState_GetScrollY(void *p);
extern void func_021BC3B8(u32 a0);

void func_021BC644(struct S *p)
{
    int v;
    if (p->f4 != 0) {
        v = ListViewState_GetScrollY(p->f4);
        if (v < -24) {
            v = -24;
        }
        if (v > 72) {
            v = 72;
        }
        func_021BC3B8(v);
        v = ListViewState_GetScrollX(p->f4);
        if (v < 0) {
            v = 0;
        }
        if (v > 240) {
            v = 240;
        }
        p->f34 = v;
        p->f32 = ListViewState_GetMode(p->f4);
    }
}
