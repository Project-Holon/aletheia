/*
 * function: ZKNSEARCH_MAIN_EnterMessageDialog
 * address:  0x021BE0C4
 * packet:   pkt_ov210_021BE0C4
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZKNSEARCH_MAIN_DeleteCursorMove  0x021BFF18  thumb  ov210
 *   ZKNSEARCH_MAIN_StartScrollMove  0x021BCE0C  thumb  ov210
 *   ZKNSEARCH_MAIN_RequestPaletteFade  0x021BC82C  thumb  ov210
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
extern void ZKNSEARCH_MAIN_DeleteCursorMove(int p);
extern void ZKNSEARCH_MAIN_StartScrollMove(char *p, int delta);
extern void ZKNSEARCH_MAIN_RequestPaletteFade(char *p, u8 b, u8 c);

u32 ZKNSEARCH_MAIN_EnterMessageDialog(u8 *p)
{
    ZKNSEARCH_MAIN_DeleteCursorMove((int)p);
    ZKNSEARCH_MAIN_StartScrollMove((char *)p, 8);
    ZKNSEARCH_MAIN_RequestPaletteFade((char *)p, 0, 16);
    return 1;
}
