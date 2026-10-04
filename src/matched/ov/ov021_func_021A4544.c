/*
 * function: func_021A4544
 * address:  0x021A4544
 * packet:   pkt_ov021_021A4544
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_021A4598  0x021A4598  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_0216D3CC(int a0);
extern u16 func_0216D5F8(void *p);
extern int func_021A4598(u8 *a, void *b, u8 *c);

int func_021A4544(u8 *p, u32 r, u8 *q)
{
    if (func_0216D3CC(r) == 1) {
        if (*(u16 *)(q + 8) != 9) {
            if (*(u16 *)(q + 8) != func_0216D5F8((void *)r) && *(u32 *)(q + 0x10) == 0) {
                if ((*(u32 *)(q + 0xc) & 1) == 0) {
                    return 3;
                }
                if ((2 & *(u32 *)(q + 4)) == 0) {
                    return 3;
                }
            }
            return func_021A4598(p, (void *)r, q);
        }
        return 1;
    }
    return 0;
}
