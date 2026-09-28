/*
 * function: func_0202419C
 * address:  0x0202419C
 * packet:   pkt_02023DDC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT

 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj {
    u8  f0;
    u8  pad1[0x17];
    u16 f18;    /* 0x18 */
    u16 f1A;    /* 0x1A */
};

extern u32 func_02024534(void *p, u32 a);

u32 func_0202419C(struct Obj *p, u16 *q, u32 a)
{
    switch (p->f0) {
    case 0:
        if (*q == p->f18) {
            return 1;
        }
        return 0;
    case 1:
        if (q[0] == p->f18 && q[1] == p->f1A) {
            return 1;
        }
        return 0;
    case 2:
        break;
    }

    return func_02024534((u8 *)p + 0x10, a);
}
