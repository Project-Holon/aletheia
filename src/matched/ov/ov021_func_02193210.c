/*
 * function: func_02193210
 * address:  0x02193210
 * packet:   pkt_ov021_02193210
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02012FFC  0x02012FFC  thumb  arm9
 *   func_02013080  0x02013080  thumb  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern signed char func_02013080(u32 idx);
extern signed char func_02012FFC(void);

u32 func_02193210(u8 *p)
{
    if (*p != 0)
        return func_02013080(1);
    return func_02012FFC();
}
