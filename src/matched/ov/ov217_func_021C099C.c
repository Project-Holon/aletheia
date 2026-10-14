/*
 * function: RESEARCH_COMMON_Destroy
 * address:  0x021C099C
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
 *   RESEARCH_COMMON_Free  0x021C0A54  thumb  ov217
 *   RESEARCH_COMMON_Exit  0x021C0AA4  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 RESEARCH_COMMON_Free(void *a0);
extern u32 RESEARCH_COMMON_Exit(u32);
u32 RESEARCH_COMMON_Destroy(void *a0)
{
    RESEARCH_COMMON_Exit((u32)a0);
    return RESEARCH_COMMON_Free(a0);
}

