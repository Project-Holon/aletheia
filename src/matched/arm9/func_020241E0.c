/*
 * function: func_020241E0
 * address:  0x020241E0
 * packet:   pkt_020241E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


struct T {
    u8  pad00[1];
    u8  f01;
    u8  f02;
    u8  pad03[0xd];
    u16 f10;
    u16 f12;
    u16 f14;
    u16 f16;
    u16 f18;
    u16 f1a;
};

extern u32 func_0202419C(struct T *p);

void func_020241E0(struct T *p, u16 *a1, u16 *a2)
{
    int i;

    p->f02 = (func_0202419C(p) == 0);
    p->f01 = 0;
    for (i = 0; i < 2; i++) {
        *(u16 *)((char *)p + i * 2 + 0x18) = a1[i];
    }
    p->f10 = a2[0];
    p->f12 = a2[1];
    p->f14 = a2[2];
    p->f16 = a2[3];
}
