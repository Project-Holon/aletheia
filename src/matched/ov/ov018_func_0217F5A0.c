/*
 * function: func_0217F5A0
 * address:  0x0217F5A0
 * packet:   pkt_ov018_0217F5A0
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02175DA8  0x02175DA8  thumb  ov011
 *   func_02175B34  0x02175B34  thumb  ov011
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad0[0x30];
    u16 f30;
} Rec;

typedef struct {
    u8 pad0[0x1A5];
    u8 lo1A5 : 2;
    u8 bit1A5 : 1;
} Ov018Obj;

int func_02175DA8(u8 *p);
u8 *func_02175B34(u8 *p);

int func_0217F5A0(Ov018Obj *p)
{
    Rec *r;

    if (func_02175DA8((u8 *)p) == 1) {
        return 4;
    }
    r = (Rec *)func_02175B34((u8 *)p);
    if (r == 0) {
        return 0;
    }
    if (r->f30 == 0) {
        if (p->bit1A5 == 1) {
            return 3;
        }
        return 1;
    }
    if (p->bit1A5 == 1) {
        return 2;
    }
    return 1;
}
