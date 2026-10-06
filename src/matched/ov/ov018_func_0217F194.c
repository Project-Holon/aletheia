/*
 * function: func_0217F194
 * address:  0x0217F194
 * packet:   pkt_ov018_0217F194
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0204B6F4  0x0204B6F4  arm
 */

typedef unsigned char u8;

typedef struct {
    u8 pad0[0x9C];
    void *f9C;
    u8 padA0[0x116 - 0xA0];
    u8 f116;
    u8 f117;
} Ov018Blink;

typedef unsigned int   u32;
struct Obj;
void func_0204B6F4(struct Obj *o, u32 v, u32 flag);

void func_0217F194(Ov018Blink *p)
{
    int t;

    if (p->f116 != 0) {
        t = p->f117;
        if (t % 2 == 0) {
            func_0204B6F4(p->f9C, (u8)(((unsigned)t >> 1) & 1 ? 6 : 7), (int)1);
        }
        if (p->f117 < 10) {
            p->f117++;
        }
    }
}
