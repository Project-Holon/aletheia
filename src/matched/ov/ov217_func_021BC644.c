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
 *   func_021C0DF0 0x021C0DF0 thumb ov217
 *   func_021C0DF4 0x021C0DF4 thumb ov217
 *   func_021C0DF8 0x021C0DF8 thumb ov217
 *   func_021BC3B8 0x021BC3B8 thumb ov217
 */
struct S { char pad0[4]; void *f4; char pad8[0x2a]; unsigned char f32; char pad33; int f34; };
extern int func_021C0DF0(void *p);
extern int func_021C0DF4(void *p);
extern int func_021C0DF8(void *p);
extern void func_021BC3B8(int v);

void func_021BC644(struct S *p)
{
    int v;
    if (p->f4 != 0) {
        v = func_021C0DF8(p->f4);
        if (v < -24) {
            v = -24;
        }
        if (v > 72) {
            v = 72;
        }
        func_021BC3B8(v);
        v = func_021C0DF4(p->f4);
        if (v < 0) {
            v = 0;
        }
        if (v > 240) {
            v = 240;
        }
        p->f34 = v;
        p->f32 = func_021C0DF0(p->f4);
    }
}
