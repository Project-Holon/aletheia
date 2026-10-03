/*
 * unit:     yes
 * function: func_021D9B40, func_021D9B98
 * address:  0x021D9B40
 * packet:   pkt_ov093_021D9B40
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   d_021F0870     0x021F0870  data   ov093  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int);
extern int func_021D76BC(int, int);
extern void *func_021C7CF4(void *a, int b);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern int func_021D7B74(u8 *p, u32 k);
extern int d_021F0870[];

void func_021D9B40(int a, void *b, int c)
{
    void *q;
    u8 *p;

    if (c == func_021D775C(2) && func_021D775C(0x1d) == 5) {
        q = func_021C7CF4(b, c);
        func_021D76BC(0x32, 0);
        p = func_021C88A4(b, 5, c);
        *(u16 *)(p + 4) = func_021D7B74(q, 8);
        p[6] = c;
        *(u32 *)p |= 0x800000;
        func_021C88C8(b, p);
    }
}

int *func_021D9B98(int *p)
{
    *p = 1;
    return d_021F0870;
}
