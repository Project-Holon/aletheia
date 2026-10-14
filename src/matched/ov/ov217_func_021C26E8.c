/*
 * function: PERCENTAGE_Create
 * address:  0x021C26E8
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   PERCENTAGE_Alloc  0x021C28FC  thumb  ov217
 *   PERCENTAGE_ClearFields  0x021C291C  thumb  ov217
 *   PERCENTAGE_Setup  0x021C2934  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 PERCENTAGE_Alloc(u32 a0);
extern u32 PERCENTAGE_ClearFields();
extern u32 PERCENTAGE_Setup(u32 a0, u32 a1, u32 a2);
u32 PERCENTAGE_Create(u32 a0, u32 a1, u32 a2)
{
    u32 v1 = PERCENTAGE_Alloc(a0);
    PERCENTAGE_ClearFields(v1, a0);
    PERCENTAGE_Setup(v1, a1, a2);
    return v1;
}

