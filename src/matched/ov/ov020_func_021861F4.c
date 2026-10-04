/*
 * function: func_021861F4
 * address:  0x021861F4
 * packet:   pkt_ov020_021861F4
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200855C  0x0200855C  thumb
 *   func_02008530  0x02008530  thumb
 *   func_021584F4  0x021584F4  thumb  ov010
 *   func_021866F8  0x021866F8  thumb  ov020
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef unsigned int   u32;
struct Sub0200852CObj;
u8 func_0200855C(const struct Sub0200852CObj *obj);
u32 func_02008530(const struct Sub0200852CObj *obj);
int func_021584F4(int a, int b);
void func_021866F8(char *p);

void func_021861F4(u16 *p, int x)
{
    int i;

    if (p[0] > 1)
        p[0] = 1;
    if (p[0] == 0 && p[1] != 2)
        p[1] = 2;
    if (p[0] == 1 && p[1] >= 2) {
        int r6 = func_0200855C((const struct Sub0200852CObj *)x);
        if (func_021584F4((u8)r6, func_02008530((const struct Sub0200852CObj *)x)) == 0x15)
            p[1] = 0;
        else
            p[1] = 1;
    }
    for (i = 0; i < 10; i++)
        func_021866F8((char *)p + 8 + i * 0x18);
}
