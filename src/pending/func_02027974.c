/*
 * function: func_02027974
 * address:  0x02027974
 * packet:   pkt_02027974
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * field_sound_system.c.  Blocked on: label/matched.  Every concrete byte
 * reproduces; the two unresolved relocations are the calls to func_02027D44
 * and func_02027E3C, whose only branch anywhere in the image is the one
 * inside this function, and neither address has a manifest entry yet.  A
 * split cannot help: both call sites sit in this single function.  Filing
 * either callee EXACT would promote this file to EXACT unchanged.
 * symbols:
 *   func_020278F4  0x020278F4  thumb
 *   func_02027D44  0x02027D44  thumb
 *   func_02027E3C  0x02027E3C  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_02027B30  0x02027B30  thumb
 *   func_02027B60  0x02027B60  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct S;

typedef struct {
    u8   f00;
    u8   f01;
    u16  f02;
    u16  f04;
    u8   pad06[0x0c - 0x06];
    u32  f0c;
    u8   pad10[0x14 - 0x10];
    u32  f14;
    u32 *f18;
    u8   pad1c[0x34 - 0x1c];
    struct S *f34;
} Obj;

extern void func_020278F4(Obj *p);
extern void func_02027D44(Obj *p);
extern void func_02027E3C(Obj *p);
extern u32  _u32_div_f(u32 a, u32 b);
extern void func_02027B30(u32 a, struct S *s, int mode);
extern void func_02027B60(u16 *phase, u16 *out, u32 mode, u32 slot);

void func_02027974(Obj *p)
{
    u32 step;
    u16 *q;

    func_020278F4(p);
    if (p->f0c == 0) {
        func_02027D44(p);
        if (p->f0c == 0) {
            func_02027E3C(p);
        }
    } else {
        step = _u32_div_f(4, p->f14);
        if ((u8)(_u32_div_f(p->f01, step) & 1) == 0) {
            func_02027B30(p->f18[p->f00], p->f34, 1);
        } else {
            func_02027B30(p->f18[p->f00], p->f34, 0);
        }
        p->f01 = (u8)(p->f01 + 1);
    }
    q = (u16 *)p->f34;
    func_02027B60(&p->f02, &p->f04, (u8)q[0], (u8)q[1]);
}
