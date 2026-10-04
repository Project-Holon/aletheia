/*
 * function: func_021D2930
 * address:  0x021D2930
 * packet:   pkt_ov093_021D2930
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021D7AD4  0x021D7AD4  thumb  ov093
 *   func_021EA1B8  0x021EA1B8  thumb  ov093
 *   func_021EA1F0  0x021EA1F0  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_021CD9E0(u8 *p);
extern int func_021B8D8C(void *p, void *a, u32 b);
extern int func_021D7AD4(int a);
extern void func_021EA1B8(u32 a, u32 b, int c, int d);
struct S;
extern int func_021EA1F0(struct S *s);

int func_021D2930(u32 *a, int *b, u32 *c)
{
    int t;

    switch (*b) {
    case 0:
        if (func_021CD9E0((u8 *)a) == 0) {
            t = func_021B8D8C((void *)a[0], (void *)a[1], (u8)c[0]);
            func_021EA1B8(a[0x15], (u16)c[2], t, func_021D7AD4(c[1]));
            (*b)++;
            break;
        }
        return 1;
    case 1:
        if (func_021EA1F0((struct S *)a[0x15]) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}
