/*
 * function: WIFICLUB_ShowMessage
 * address: 0x021BAADC
 * packet: pkt_ov099_021BAADC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: Two bytes of alignment padding follow at 0x021BAB02.
 * symbols:
 *   WIFICLUB_DeleteWindow 0x021BA8BC thumb ov099
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   WIFICLUB_PrintTalkMessage 0x021BA978 thumb ov099
 */
#include "../include/Obj13684.h"
extern int WIFICLUB_DeleteWindow(void *);
extern void GF_FONT_SetDefaultTextColor(void);
extern void WIFICLUB_PrintTalkMessage(char *, int, int, int);
void WIFICLUB_ShowMessage(char *p, int a, int b)
{
    *(int *)&((struct Obj13684 *)p)->f19C = WIFICLUB_DeleteWindow(((struct Obj13684 *)p)->f19C);
    GF_FONT_SetDefaultTextColor();
    WIFICLUB_PrintTalkMessage(p, a, b, 0);
}
