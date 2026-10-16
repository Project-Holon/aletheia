/*
 * function: OPTION_MENU_PrintMessage
 * address: 0x021BAF0C
 * packet: pkt_ov068_021BAF0C
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Interface: full-width r1 is forwarded through 021BA278 to 021BA28C;
 * the legacy u16 extern has no caller truncation witness here.
 * symbols:
 *   G2x_SetBlendBrightness_ 0x0207D658 arm
 *   func_02040588 0x02040588 arm
 *   OPTION_MENU_PrintText 0x021BA278 thumb ov068
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void G2x_SetBlendBrightness_(u32, int, int);
typedef unsigned char  u8;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void OPTION_MENU_PrintText(u8 *p, u32 a, u32 b, u32 c);
void OPTION_MENU_PrintMessage(void *p, u32 id, u32 value)
{
    G2x_SetBlendBrightness_(0x04000050, 23, 8);
    func_02040588(3, 1);
    OPTION_MENU_PrintText(p, id, value, 1);
}
