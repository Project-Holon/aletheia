/*
 * function: func_021CF748
 * address:  0x021CF748
 * packet:   pkt_ov021_021CF748
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Picks a value pair from two small tables, or a state code from the field
 * state when the index is out of range.
 *
 * symbols:
 *   func_0202A230  0x0202A230  thumb
 *   func_0202A3FC  0x0202A3FC  thumb
 *   func_0202A3D8  0x0202A3D8  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A30C8  0x021A30C8  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_021AB37C  0x021AB37C  thumb  ov021
 *   func_02188D58  0x02188D58  thumb  ov021
 *   func_020140D8  0x020140D8  thumb
 *   d_021DB7E0     0x021DB7E0  data  ov021  a2
 *   d_021DB7F6     0x021DB7F6  data  ov021  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern const u16 d_021DB7E0[];
extern const u8  d_021DB7F6[];

extern u32  func_0202A230(u32 a, u32 b);
extern u32  func_0202A3FC(u32 a);
extern u32  func_0202A3D8(u32 a);
extern void *func_02188CB4(unsigned char *p);
extern u32  func_021A30C8(u32 a);
extern u32  func_021AB0F0(u32 a);
extern u32  func_021AB0F8(u32 a);
extern u32  func_021AB37C(u32 a);
extern u32  func_02188D58(u32 x);
extern u32  func_020140D8(u32 a);

void func_021CF748(u32 a, u32 x, int *out, u16 *out2)
{
    int flag = 1;
    u32 t = func_0202A230(a, 1);
    u32 k = func_0202A3FC(t);
    u32 m = func_0202A3D8(t);
    int code;

    if (k < 0xb) {
        *out2 = d_021DB7E0[k];
        *out = d_021DB7F6[m];
        return;
    }
    {
        u32 y = func_021A30C8(func_02188CB4((void *)x));
        u32 z = func_021AB0F0(y);

        if (func_021AB0F8(y) & 2) {
            code = 6;
        } else if (func_021AB37C(z) != 0) {
            code = 8;
        } else {
            if (func_020140D8(func_02188D58(x)) == 0) {
                flag = 0;
            }
            code = 5;
            if (flag == 0) {
                code = 7;
            }
        }
    }
    *out2 = 0x46a;
    *out = code;
}
