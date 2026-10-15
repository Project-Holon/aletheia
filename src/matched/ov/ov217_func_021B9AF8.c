/*
 * function: RESEARCH_TOP_DestroyListObject
 * address:  0x021B9AF8
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
 *   RESEARCH_TOP_FreeListObject  0x021BA4FC  thumb  ov217
 *   RESEARCH_TOP_DestroyCommandQueue  0x021BA68C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 RESEARCH_TOP_FreeListObject(void *a0);
extern void RESEARCH_TOP_DestroyCommandQueue(void *p);
u32 RESEARCH_TOP_DestroyListObject(void *a0)
{
    RESEARCH_TOP_DestroyCommandQueue((void *)a0);
    return RESEARCH_TOP_FreeListObject(a0);
}

