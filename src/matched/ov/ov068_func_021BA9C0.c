/*
 * function: OPTION_MENU_ClearListHighlight
 * address: 0x021BA9C0
 * packet: pkt_ov068_021BA9C0
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends in two zero alignment bytes at 021BA9DA.
 * symbols:
 *   OPTION_MENU_DrawList 0x021BAA0C thumb ov068
 *   func_02040588 0x02040588 arm
 *   OPTION_MENU_RestartScreenBlink 0x021B9964 thumb ov068
 */
typedef unsigned char u8;
extern void OPTION_MENU_DrawList(u8 *, int);
typedef unsigned int   u32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void OPTION_MENU_RestartScreenBlink(char *);
void OPTION_MENU_ClearListHighlight(u8 *p, char *q)
{
    OPTION_MENU_DrawList(p, 0);
    func_02040588(4, 0);
    OPTION_MENU_RestartScreenBlink(q);
}
