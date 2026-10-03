/*
 * function: func_021A90A4
 * address:  0x021A90A4
 * packet:   pkt_ov021_021A90A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B878  0x0204B878  arm
 *   func_021A8E78  0x021A8E78  thumb
 */

typedef unsigned char u8;

typedef struct {
    int pad0;
    int f0;
    int pad8[5];
} E;

typedef struct {
    int pad0[3];
    int fc;
    int pad10[3];
    char pad1c[2];
    u8 b1e;
    u8 b1f;
    int pad20[2];
    int f28;
    int pad2c;
    int f30;
    int pad34;
    E e[7];
    char padfc[0x128 - 0xfc];
    int f128;
} S;

extern void func_0204B878(int a, int b);
typedef unsigned int   u32;
extern int func_021A8E78(u32 a, u32 b);

void func_021A90A4(S *s, int m)
{
    if (m == 1) {
        s->f28 = 1;
        s->fc = 4;
        func_0204B878(s->f128, 8);
    } else {
        s->f28 = 0;
        s->fc = 5;
        s->f30 = s->e[func_021A8E78(s->b1e, s->b1f)].f0;
    }
}
