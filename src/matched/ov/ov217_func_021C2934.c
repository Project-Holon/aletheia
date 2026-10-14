/*
 * function: PERCENTAGE_Setup
 * address:  0x021C2934
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
 *   PERCENTAGE_StoreUnit  0x021C2958  thumb  ov217
 *   PERCENTAGE_CreateActors  0x021C295C  thumb  ov217
 *   PERCENTAGE_StoreTemplate  0x021C29B4  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void PERCENTAGE_StoreUnit(void *p, u32 v);
extern u32 PERCENTAGE_CreateActors();
extern void PERCENTAGE_StoreTemplate(void *p, const void *src);
u32 PERCENTAGE_Setup(u32 a0, u32 a1, u32 a2)
{
    PERCENTAGE_StoreUnit((void *)a0, a2);
    PERCENTAGE_StoreTemplate((void *)a0, (const void *)a1);
    return PERCENTAGE_CreateActors(a0);
}

