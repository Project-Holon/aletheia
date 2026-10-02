/*
 * function: func_021A666C
 * address:  0x021A666C
 * packet:   pkt_ov021_021A666C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A652C  0x021A652C  thumb  ov021
 *   func_021A658C  0x021A658C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 func_0216D5F8(void *o);
extern void func_0216D4B4(void *o);
extern int func_0216D3CC(void *o);
extern u32 func_021A652C(void *a, void *b, u32 c, u32 d, u32 e, u32 f);
extern u32 func_021A658C(void *a, void *b, u32 c, u32 d, u32 e, u32 f);

u32 func_021A666C(void *a, void *b, u32 c, u32 d, u32 e, u32 f)
{
    u32 r0 = func_0216D5F8(b);

    if (e != 9 && e != r0) {
        func_0216D4B4(b);
        return func_021A658C(a, b, c, d, e, f);
    }
    if (!func_0216D3CC(b))
        return 0;
    if (e == 9)
        return func_021A652C(a, b, c, d, e, f);
    return func_021A658C(a, b, c, d, e, f);
}
