/*
 * function: func_0216CC58
 * address:  0x0216CC58
 * packet:   pkt_ov010_0216CC58
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_0216E280  0x0216E280  thumb  ov010
 *   d_02172B48     0x02172B48  data  ov010  a1
 */

extern int func_02030734(int, int, int, char *, int);
extern void func_0216E280(void *, int);
extern char d_02172B48[];

char *func_0216CC58(int a, int b, int c)
{
    char *p = (char *)func_02030734(a, 0x48, 1, d_02172B48, 0xc3);
    *(int *)(p + 0x18) = func_02030734(a, b << 8, 1, d_02172B48, 0xc4);
    *(short *)(p + 4) = b;
    *(short *)(p + 8) = a;
    *(int *)(p + 0x2c) = c;
    *(short *)(p + 0xc) = 0x80;
    func_0216E280(p, a);
    *(int *)(p + 0x44) = func_02030734(a, 0xc4 << 2, 1, d_02172B48, 0xcf);
    return p;
}
