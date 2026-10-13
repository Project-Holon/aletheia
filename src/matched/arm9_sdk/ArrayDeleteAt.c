/*
 * function: GFL_USE_CancelChangeAndPlayBgm
 * address:  0x02005D90
 * packet:   pkt_02005D90
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_CancelBgmChange 0x02005F90 thumb
 *   GFL_USE_PlayBgm 0x02005D34 thumb
 */

typedef unsigned int u32;
extern void GFL_USE_CancelBgmChange(void);
extern void *GFL_USE_PlayBgm(u32 a0, u32 a1);

void GFL_USE_CancelChangeAndPlayBgm(u32 a0, u32 a1)
{
    GFL_USE_CancelBgmChange();
    GFL_USE_PlayBgm(a0, a1);
}
