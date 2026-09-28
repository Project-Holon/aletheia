/*
 * function: func_021A99A8
 * address:  0x021A99A8
 * packet:   pkt_ov021_021A99A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   data_021D8DE8  0x021D8DE8  data
 *   func_0200D418  0x0200D418  thumb
 *   func_0200D454  0x0200D454  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_020142E8  0x020142E8  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Entry8 { u32 a, b; };

extern void *func_02012EBC(void *p);
extern void *func_0201296C(void *p);
extern int func_020142E8(void *p, u32 flag);
extern void *func_0200D418(void *p);
extern u32 func_0200D454(void *p);
extern const struct Entry8 data_021D8DE8[];

const struct Entry8 *func_021A99A8(void *p)
{
    void *q = func_02012EBC(p);
    u32 k;

    if (func_020142E8(func_0201296C(p), 0x960) == 0)
        return 0;
    k = func_0200D454(func_0200D418(q));
    if (k >= 0x11)
        k = 0;
    return &data_021D8DE8[k];
}
