/*
 * function: func_021BB3E8
 * address:  0x021BB3E8
 * packet:   pkt_ov072_021BB3E8
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_020450F0  0x020450F0  arm
 *   func_020457B0  0x020457B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
} W;

extern void func_02082BCC(void *p, int v, int n);
extern int func_020450F0(int a, int b, int c, int d, int e, int f, int g);
extern int func_020457B0(int a, int b);

void func_021BB3E8(W *p, int a, int b, int c, u8 s0, u8 s1, u8 s2, u8 s3, u16 s4)
{
    func_02082BCC(p, 0, 0x10);
    p->f8 = b;
    p->fc = c;
    p->f0 = func_020450F0(a, s0, s1, s2, s3, 0xe, 0);
    p->f4 = func_020457B0(0xff, s4);
}
