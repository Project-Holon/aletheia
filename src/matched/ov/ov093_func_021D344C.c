/*
 * function: func_021D344C
 * address:  0x021D344C
 * packet:   pkt_ov093_021D344C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_021D6C2C  0x021D6C2C  thumb  ov093
 *   func_021EA868  0x021EA868  thumb  ov093
 *   func_021EA878  0x021EA878  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021B8D8C(void *p, void *a, u32 b);
extern u8 *func_021B9934(char *p, int i);
extern u32 func_021CD9E0(u8 *p);
extern void func_021D6C2C(u8 *m);
extern void func_021EA868(u32 a, int b, int c);
extern int func_021EA878(u32 a);

int func_021D344C(u32 *a, int *b, u32 *c)
{
    u32 u;
    int s;
    u8 *m;
    int f;

    switch (*b) {
    case 0:
        u = (u8)c[0];
        s = func_021B8D8C((void *)a[0], (void *)a[1], u);
        m = func_021B9934((char *)a[1], u);
        f = func_021CD9E0((u8 *)a);
        func_021D6C2C(m);
        func_021EA868(a[0x15], s, f);
        (*b)++;
        break;
    case 1:
        if (func_021EA878(a[0x15]) != 0) {
            (*b)++;
        }
        break;
    default:
        return 1;
    }
    return 0;
}
