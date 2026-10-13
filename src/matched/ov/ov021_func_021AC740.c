/*
 * function: FLDEFF_GRASS_DeleteSlots
 * address:  0x021AC740
 * packet:   pkt_ov021_021AC740
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BILLBOARD_ACT_DeleteSlots  0x02050278  arm  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct X { u32 f0; u32 f4; u16 h[8]; } X;

struct BbActSys;
extern void BILLBOARD_ACT_DeleteSlots(struct BbActSys *o, u32 first, u32 count);

void FLDEFF_GRASS_DeleteSlots(X *x)
{
    int i;

    for (i = 0; i < 8; i++)
        BILLBOARD_ACT_DeleteSlots((struct BbActSys *)x->f4, x->h[i], 1);
}
