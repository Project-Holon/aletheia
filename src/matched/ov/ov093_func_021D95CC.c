/*
 * unit:     yes
 * function: func_021D95CC, func_021D963C
 * address:  0x021D95CC
 * packet:   pkt_ov093_021D95CC
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
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F0CC4     0x021F0CC4  data   ov093  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int);
extern int func_021D76BC(int key, u32 val);
extern void func_021C88B4(void *a, int k, int b);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);
extern int d_021F0CC4[];

void func_021D95CC(int a, void *b, int c)
{
    u8 *p;

    if (c == func_021D775C(4) && (u16)func_021D775C(0x12) == 0x1bd) {
        if (func_021D76BC(0x40, 1) != 0) {
            func_021C88B4(b, 2, c);
            p = func_021C88A4(b, 4, c);
            func_021C8838(p + 4, 2, 0xd2);
            func_021C8860((struct S *)(p + 4), c);
            func_021C88C8(b, p);
            func_021C88B4(b, 3, c);
        }
    }
}

int *func_021D963C(int *p)
{
    *p = 5;
    return d_021F0CC4;
}
