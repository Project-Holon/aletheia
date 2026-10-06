/*
 * function: func_021A5A34
 * address:  0x021A5A34
 * packet:   pkt_ov021_021A5A34
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_021A3964  0x021A3964  thumb  ov021
 */

typedef unsigned int u32;

typedef unsigned short u16;
typedef unsigned char  u8;
u16 func_0216D5F8(void *p);
void *func_0216D4B4(char *p);
void func_0216D5E0(int a0, int a1);
void func_0216D674(void *p, u16 v);
void func_021A3964(u8 *p, u32 v);

void func_021A5A34(u32 *p)
{
    u32 h;
    int v;

    if (p[0] == 3) {
        h = p[7];
        v = func_0216D5F8((void *)h);
        func_0216D4B4((char *)h);
        func_0216D5E0(h, v);
        func_0216D674((void *)h, 0);
        func_021A3964((u8 *)p[5], 0);
    }
}
