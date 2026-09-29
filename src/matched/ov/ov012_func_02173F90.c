/*
 * function: func_02173F90
 * address:  0x02173F90
 * packet:   pkt_ov012_02173F90
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02087C6C  0x02087C6C  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D4D0  0x0203D4D0  arm
 */

typedef struct { int w[8]; } B32;
typedef struct { B32 a; unsigned char t[8]; } Msg;

extern void func_02082BCC(void *p, int v, int n);
extern void func_02087C6C(void *p);
extern int func_020399A8(void);
extern int func_0203D4D0(int a, int b, int c, int d, void *e, int f, int g, int h);

void func_02173F90(int a, B32 *src)
{
    Msg m;

    func_02082BCC(&m, 0, 0x28);
    m.a = *src;
    func_02087C6C(m.t);
    func_0203D4D0(func_020399A8(), a, 0x1411, 0x28, &m, 1, 0, 0);
}
