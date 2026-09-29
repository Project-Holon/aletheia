/*
 * function: func_02166A6C
 * address:  0x02166A6C
 * packet:   pkt_ov010_02166A6C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_02172BA4  0x02172BA4  data  ov010  a4
 *   d_021729FC  0x021729FC  data  ov010  a4
 *   func_0207AD58  0x0207AD58  thumb
 *   func_0207D59C  0x0207D59C  arm
 *   _fadd  0x0209C95C  arm
 *   _fdiv  0x0209CE10  arm
 *   _fgr  0x0209BBB0  arm
 *   _fmul  0x0209C77C  arm
 *   _fsub  0x0209CB8C  arm
 *   _ffix  0x0209C494  arm
 */

typedef unsigned short u16;

extern float d_02172BA4;
extern float d_021729FC;
extern void func_0207AD58(void *dst, int a, int b);
extern void func_0207D59C(void *reg, void *m, int a, int b, int c, int d);

void func_02166A6C(void)
{
    int i;
    int m[4];
    float x;
    float t;
    float z = 0.0f;
    if (*(volatile u16 *)0x04000004 & 1) {
        x = d_02172BA4 + d_021729FC;
        d_02172BA4 = x;
        if (1.0f / x > z)
            t = 4096.0f * (1.0f / x) + 0.5f;
        else
            t = 4096.0f * (1.0f / x) - 0.5f;
        i = (int)t;
        func_0207AD58(m, i, i);
        func_0207D59C((void *)0x04000020, m, 0x80, 0x5c, 0, 0);
    }
}
