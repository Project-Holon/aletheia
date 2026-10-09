/*
 * file:     unit_021DCA98.c
 * function: func_021DCA98, func_021DCACC, func_021DCAD8, func_021DCAE0
 * address:  0x021DCA98
 * packet:   pkt_ov093_021DCA98
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E8798  0x021E8798  thumb  ov093
 *   func_021E8744  0x021E8744  thumb  ov093
 *   d_021F0630     0x021F0630  data   ov093  a4
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_0201C1E8  0x0201C1E8  thumb
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_0201C1E8(int a);
extern int func_021D76BC(int key, u32 val);

void func_021DCA98(int a, int b, int c)
{
    u8 v;

    if (c == func_021D775C(3) && func_0201C1E8((u16)func_021D775C(0x12)) == 0) {
        v = func_021D775C(0x18);
        func_021D76BC(0x18, v + 1);
    }
}


extern int d_021F0630[];
int *func_021DCACC(int *p);

int *func_021DCACC(int *p)
{
    *p = 1;
    return d_021F0630;
}


void func_021E8744(int u, void *a, int b, int d);
void func_021DCAD8(int u, void *a, int b, int d);

void func_021DCAD8(int u, void *a, int b, int d)
{
    func_021E8744(u, a, b, d);
}


void func_021E8798(int u, void *a, int b, int d);
void func_021DCAE0(int u, void *a, int b, int d);

void func_021DCAE0(int u, void *a, int b, int d)
{
    func_021E8798(u, a, b, d);
}
