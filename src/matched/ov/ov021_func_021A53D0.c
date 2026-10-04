/*
 * function: func_021A53D0
 * address:  0x021A53D0
 * packet:   pkt_ov021_021A53D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_021A3964  0x021A3964  thumb  ov021
 */

typedef unsigned int u32;

void *func_021A3960(unsigned char *p);
typedef unsigned short u16;
u16 func_0216D5F8(void *p);
void func_0216D4B4(char *p);
typedef unsigned char  u8;
void func_0216D5E0(int a0, int a1);
void func_0216D674(void *p, u16 v);
void func_021A3964(u8 *p, u32 v);

void func_021A53D0(u32 *p)
{
    void *h;
    int v;

    if (p[0] == 3) {
        h = func_021A3960(*(unsigned char **)(p + 3));
        v = func_0216D5F8(h);
        func_0216D4B4(h);
        func_0216D5E0((int)h, v);
        func_0216D674(h, 0);
        func_021A3964((u8 *)p[3], 0);
    }
}
