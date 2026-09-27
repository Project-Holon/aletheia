/*
 * function: func_021B9530
 * address:  0x021B9530
 * packet:   pkt_021B9530
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
  * status:   EXACT
 *
 * symbols:
 *   func_021B94D8  0x021B94D8  thumb
 *   func_021B87D8  0x021B87D8  thumb
 *   func_021B8514  0x021B8514  thumb
 *   func_021B86A4  0x021B86A4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int func_021B94D8(u16 *r, u8 *tbl, u8 *sr);
u8 *func_021B87D8(u8 *p, u32 idx);
u8 *func_021B8514(u8 *p, u32 v, u8 *q, u16 *r, int flag);
void func_021B86A4(u8 *t, u8 *q, u32 *out1, u32 *out2, u8 *a5, u32 a6);

void func_021B9530(u16 *t, u8 *p, int dx, int dy, int a6)
{
    if (func_021B94D8(t, *(u8 **)(p + 4), *(u8 **)(p + 0x24)) != 0) {
        u8 *row = func_021B87D8(*(u8 **)(p + 0x24), **(u32 **)(p + 4));
        u8 *res = func_021B8514(row, a6, *(u8 **)(p + 0x24), t, 0);
        u32 out1, out2;

        func_021B86A4(*(u8 **)(p + 0x24), *(u8 **)(p + 4), &out1, &out2,
                      (u8 *)t, *(u32 *)(p + 0x1c));
        *(int *)(p + 0xc) += dx;
        *(int *)(p + 0x14) += dy;
        if (*(int *)(p + 0xc) > (int)out1)
            *(int *)(p + 0xc) = out1;
        if (res == 0) {
            int f = *(int *)(p + 0x14);
            int a = f < 0 ? -f : f;
            if (a > (int)out2) {
                if (f > 0)
                    *(int *)(p + 0x14) = out2;
                else
                    *(int *)(p + 0x14) = -(int)out2;
            }
        }
        return;
    }
    *(int *)(p + 0xc) += dx;
    *(int *)(p + 0x14) += dy;
}
