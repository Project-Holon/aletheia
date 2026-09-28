/*
 * unit:     no
 * function: func_0202465C
 * address:  0x0202465C
 * packet:   pkt_020245D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02024584  0x02024584  thumb
 *   func_02024498  0x02024498  thumb
 *   func_020246C8  0x020246C8  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct T {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
};

extern u32 func_02024584(u32 a);
extern u32 func_02024498(u32 a0, u32 a1, u32 a2);
extern u32 func_020246C8(u16 *p, u32 a1, u32 a2);

u32 func_0202465C(struct T *p, u32 a1, u32 a2)
{
    u32 ok = 1;
    u32 n;
    u32 i;

    if (p->f00 >= 7 || p->f02 >= func_02024584(p->f00)) {
        ok = 0;
        p->f00 = 0;
        p->f02 = 0;
    }

    n = func_02024498(p->f00, p->f02, (u16)((a2 & 0x7FFF) | 0x8000));
    if (n > 2) {
        n = 2;
    }
    for (i = 0; i < n; i++) {
        if (func_020246C8(&p->f04 + i, a1, 1) == 0) {
            ok = 0;
        }
    }
    return ok;
}
