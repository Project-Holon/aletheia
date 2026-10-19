/*
 * function: WORLDTRADE_BOX_GetMonCount
 * address:  0x021F6B80
 * packet:   pkt_021F6B80
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_BOX_IsPartyBox  0x021F6B34  thumb  ov135
 *   POKEPARTY_GetCount  0x0201AA18  thumb  arm9

 * Sentinel test picks between the direct query and the two-argument helper.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern int WORLDTRADE_BOX_IsPartyBox(int v);
extern u32 POKEPARTY_GetCount(void *p);
extern int func_020078C4(void *save, u32 box);

u32 WORLDTRADE_BOX_GetMonCount(u8 *p, u32 b, u32 c)
{
    if (WORLDTRADE_BOX_IsPartyBox(c) != 0) {
        return POKEPARTY_GetCount(p);
    }
    return func_020078C4((void *)b, c);
}
