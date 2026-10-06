/*
 * function: func_021D3630
 * address:  0x021D3630
 * packet:   pkt_ov093_021D3630
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_021EA768  0x021EA768  thumb  ov093
 *   func_021EA778  0x021EA778  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021B8D8C(void *p, void *a, u32 b);
extern u32 func_021CD9E0(u8 *p);
extern void func_021EA768(u32 *p, u32 a2, u32 a3);
extern int func_021EA778(u32 *p, u32 a2);

int func_021D3630(u32 *a, int *b, u32 *c)
{
    int s;

    s = func_021B8D8C((void *)a[0], (void *)a[1], (u8)c[0]);
    switch (*b) {
    case 0:
        if (func_021CD9E0((u8 *)a) != 0) {
            return 1;
        }
        func_021EA768((u32 *)a[0x15], s, 1);
        (*b)++;
        break;
    case 1:
        if (func_021EA778((u32 *)a[0x15], s) != 0) {
            (*b)++;
        }
        break;
    default:
        return 1;
    }
    return 0;
}
