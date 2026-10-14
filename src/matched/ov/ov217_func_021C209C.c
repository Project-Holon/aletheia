/*
 * function: ARROW_Destroy
 * address:  0x021C209C
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
 *   ARROW_Free  0x021C25A8  thumb  ov217
 *   ARROW_DeleteUnit  0x021C25C4  thumb  ov217
 *   ARROW_DeleteActors  0x021C2614  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 ARROW_Free(void *a0);
extern void ARROW_DeleteUnit(u8 *a0);
extern void ARROW_DeleteActors(char *p);
u32 ARROW_Destroy(void *a0)
{
    ARROW_DeleteActors((char *)a0);
    ARROW_DeleteUnit((u8 *)a0);
    return ARROW_Free(a0);
}

