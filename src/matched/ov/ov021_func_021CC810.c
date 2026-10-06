/*
 * function: func_021CC810
 * address:  0x021CC810
 * packet:   pkt_ov021_021CC810
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Task state machine on the byte at +0xc0. The inner switch on an unsigned
 * result (cases 2, -2, -1) is what gives the compare order 2, -2, -1 and
 * the dead second -1 test.
 *
 * symbols:
 *   func_021CCFC0  0x021CCFC0  thumb  ov021
 *   func_021CCFE4  0x021CCFE4  thumb  ov021
 *   func_021CCFF8  0x021CCFF8  thumb  ov021
 *   func_021CCEFC  0x021CCEFC  thumb  ov021
 *   func_0219049C  0x0219049C  thumb  ov021
 *   func_021CCF54  0x021CCF54  thumb  ov021
 *   func_021CCF48  0x021CCF48  thumb  ov021
 *   func_021CD1AC  0x021CD1AC  thumb  ov021
 *   func_021CCFD8  0x021CCFD8  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Obj {
    u8 pad0[0xa4];
    u32 fA4;
    u8 padA8[0xbc - 0xa8];
    u32 fBC;
    u8 fC0;
    u8 fC1;
} Obj;

extern void func_021CCFC0(Obj *p);
extern int func_021CCFE4(u32 a, u32 b);
extern int func_021CCFF8(Obj *p);
extern void func_021CCEFC(u8 *p);
extern int func_0219049C(u32 a);
extern u32 func_021CCF54(Obj *p);
extern void func_021CCF48(u8 *p);
extern void func_021CD1AC(Obj *p);
extern void func_021CCFD8(u8 *p);

int func_021CC810(Obj *p)
{
    u32 r;

    switch (p->fC0) {
    case 0:
        func_021CCFC0(p);
        func_021CCFE4((u32)p, 3);
        p->fC0 = p->fC0 + 1;
        break;
    case 1:
        if (func_021CCFF8(p) == 1) {
            func_021CCEFC((u8 *)p);
            p->fC0 = p->fC0 + 1;
        }
        break;
    case 2:
        if (func_0219049C(p->fA4) == 1) {
            r = func_021CCF54(p);
            if (r == -1)
                break;
            func_021CCF48((u8 *)p);
            func_021CD1AC(p);
            func_021CCFD8((u8 *)p);
            switch (r) {
            case 2:
            case -2:
                p->fBC = 2;
                p->fC0 = p->fC0 + 1;
                break;
            case -1:
                break;
            default:
                p->fBC = r;
                p->fC0 = p->fC0 + 1;
                break;
            }
        }
        break;
    default:
        p->fC1 = 1;
        return 1;
    }
    return 0;
}
