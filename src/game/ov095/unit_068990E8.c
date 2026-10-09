/*
 * file:     unit_068990E8.c
 * function: func_068990E8
 * address:  0x068990E8
 * packet:   pkt_ov095_068990E8
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_06899144  0x06899144  thumb
 *   func_06899154  0x06899154  thumb
 *   func_06899164  0x06899164  thumb
 *   func_06899174  0x06899174  thumb
 *   func_06899184  0x06899184  thumb
 *   func_06899194  0x06899194  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_06899144(int a);
extern int func_06899154(int a);
extern u8 *func_06899164(int p, int n, int v);
extern void func_06899174(u8 *p, int n, int c);
extern void func_06899184(u8 *p, int v);
extern void func_06899194(int p, u8 *q);

void func_068990E8(int a0, int p, int a2, int *s)
{
    int k;
    u8 v;
    u8 *t;

    if (s[0] != 0) {
        k = func_06899144(0x19);
        if (k == 0 || s[1] != k) {
            v = func_06899154(2);
            t = func_06899164(p, 4, v);
            func_06899174(t + 4, 2, 0x34a);
            func_06899184(t + 4, v);
            func_06899194(p, t);
            s[1] = k;
        }
        s[0] = 0;
    }
}
