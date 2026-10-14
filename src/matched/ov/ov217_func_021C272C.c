/*
 * function: PERCENTAGE_SetValue
 * address:  0x021C272C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   PERCENTAGE_Layout  0x021C278C  thumb  ov217
 *   PERCENTAGE_StoreValue  0x021C2888  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 PERCENTAGE_Layout();
extern void PERCENTAGE_StoreValue(void *p, u8 v);
u32 PERCENTAGE_SetValue(u32 a0, u32 a1)
{
    PERCENTAGE_StoreValue((void *)a0, ((u32)((u32)a1 << 24) >> 24));
    return PERCENTAGE_Layout(a0);
}

