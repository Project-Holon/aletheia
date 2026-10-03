/*
 * unit:     yes
 * function: func_021E5680, func_021E56D4
 * address:  0x021E5680
 * packet:   pkt_ov093_021E5680
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7F24  0x021C7F24  thumb  ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F254C     0x021F254C  data   ov093  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021C7F24(u8 *p, int i);
extern int func_021C8010(u8 *p, unsigned int v);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern int d_021F254C[];

void func_021E5680(int a, void *b, int c)
{
    u8 *m;

    if (c == func_021D775C(3) && func_021C7F24(b, c) != 0) {
        m = (u8 *)func_021C88A4(b, 0x1e, c);
        *(int *)(m + 4) = 2;
        m[8] = func_021C8010(b, c);
        func_021C88C8(b, m);
        m = (u8 *)func_021C88A4(b, 0x13, c);
        m[4] = c;
        func_021C88C8(b, m);
    }
}

int *func_021E56D4(int *p)
{
    *p = 1;
    return d_021F254C;
}
