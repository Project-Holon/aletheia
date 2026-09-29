/*
 * function: func_021D34E8
 * address:  0x021D34E8
 * packet:   pkt_ov093_021D34E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B8E70  0x021B8E70  thumb  ov093
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_021B8590  0x021B8590  thumb  ov093
 *   func_021D3558  0x021D3558  thumb
 *   func_021EA3B8  0x021EA3B8  thumb  ov093
 *   func_021EA3D4  0x021EA3D4  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 func_021B8E70(u8 *p, u32 k);
extern u32 func_021CD9E0(u8 *p);
extern int func_021B8590(u32 p);
extern int func_021D3558(u16 v);
extern void func_021EA3B8(u32 a, int b, u16 c);
extern int func_021EA3D4(u32 a);

int func_021D34E8(u32 *a, int *b, u32 *c)
{
    u8 k;

    k = func_021B8E70((u8 *)a[0], (u8)c[0]);
    if (*b == 0) {
        if (func_021CD9E0((u8 *)a) != 0) {
            return 1;
        }
        if (func_021B8590(a[0]) == 0) {
            if (func_021D3558((u16)c[1]) != 0) {
                return 1;
            }
        }
        func_021EA3B8(a[0x15], k, (u16)c[1]);
        (*b)++;
    } else {
        if (func_021EA3D4(a[0x15]) != 0) {
            return 1;
        }
    }
    return 0;
}
