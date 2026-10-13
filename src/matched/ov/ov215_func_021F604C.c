/*
 * function: func_021F604C
 * address:  0x021F604C
 * packet:   pkt_021F604C
 * region:   ov215
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 */

extern int GFL_USE_PopBgm(void);
typedef unsigned int   u32;
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern void GFL_USE_FadeInBgmFull(u32 a);

void func_021F604C(void)
{
    GFL_USE_PopBgm();
    GFL_USE_SetBgmPlayerParam(0);
    GFL_USE_FadeInBgmFull(0x3c);
}