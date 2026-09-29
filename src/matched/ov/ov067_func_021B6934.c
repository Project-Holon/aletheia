/*
 * function: func_021B6934
 * address:  0x021B6934
 * packet:   pkt_ov067_021B6934
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B3F4  0x0204B3F4  arm
 *   func_02035D20  0x02035D20  arm
 *   func_020355D8  0x020355D8  arm
 *   func_020362DC  0x020362DC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

typedef struct S {
    u32 f00;
    u32 f04;
    u32 f08;
    void (*f0c)(struct S *);
    u8 pad10[0x1c - 0x10];
    s16 f1c;
    s16 f1e;
    u8 pad20[0x30 - 0x20];
    u32 f30;
} S;

extern u32 func_0204B3F4(u32 a);
extern int func_02035D20(u32 *x, u32 *y);
extern void func_020355D8(int v);
extern u32 func_020362DC(void);

int func_021B6934(S *p)
{
    u32 x;
    u32 y;
    int hit = 0;

    if (func_0204B3F4(p->f00) & p->f04) {
        if (func_02035D20(&x, &y)) {
            if (x - p->f1c <= 0x18 && y - p->f1e <= 0x18) {
                hit = 1;
                func_020355D8(1);
            }
        }
        if (p->f30 != 0 && (func_020362DC() & p->f30)) {
            func_020355D8(0);
            hit = 1;
        }
        if (hit) {
            p->f0c(p);
            return 1;
        }
    }
    return 0;
}
