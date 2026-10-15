/*
 * function: ZKNSEARCH_MAIN_ExitListPage1
 * address:  0x021BD640
 * packet:   pkt_021BD640
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZKNSEARCH_MAIN_SetFadeStateB  0x021BCD3C  thumb  ov210
 *   ZKNSEARCH_MAIN_HideAllActors  0x021BF38C  thumb  ov210
 *   ZKNSEARCH_RESULT_DeleteFrameList  0x021C0550  thumb  ov210
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void ZKNSEARCH_MAIN_SetFadeStateB(u8 *p);
extern void ZKNSEARCH_MAIN_HideAllActors(u8 *p);
extern void ZKNSEARCH_RESULT_DeleteFrameList(int p);

u32 ZKNSEARCH_MAIN_ExitListPage1(u32 p)
{
    ZKNSEARCH_MAIN_SetFadeStateB((u8 *)p);
    ZKNSEARCH_MAIN_HideAllActors((u8 *)p);
    ZKNSEARCH_RESULT_DeleteFrameList(p);
    return 3;
}
