/*
 * function: func_021D3688
 * address:  0x021D3688
 * packet:   pkt_ov093_021D3688
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021EA788  0x021EA788  thumb  ov093
 *   func_021EA798  0x021EA798  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021B8D8C(void *p, void *a, u32 b);
extern void func_021EA788(u32 *p, u32 a2);
extern int func_021EA798(u32 a, int b);

int func_021D3688(u32 *a, int *b, u32 *c)
{
    int s;

    s = func_021B8D8C((void *)a[0], (void *)a[1], (u8)c[0]);
    switch (*b) {
    case 0:
        func_021EA788((u32 *)a[0x15], s);
        (*b)++;
        break;
    case 1:
        if (func_021EA798(a[0x15], s) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}
