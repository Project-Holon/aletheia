/*
 * function: WIFICLUB_ClosePartnerMenu
 * address: 0x021C0290
 * packet: pkt_ov099_021C0290
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends with two-byte alignment padding at 0x021C02C6.
 * symbols:
 *   WIFICLUB_DeleteWindow 0x021BA8BC thumb ov099
 *   BMP_MENULIST_Delete 0x0202020C thumb
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 */
#include "../include/Obj00008.h"
typedef unsigned short u16;
struct Obj;
extern int WIFICLUB_DeleteWindow(void *p);
extern void BMP_MENULIST_Delete(struct Obj *,u16 *,u16 *);
typedef unsigned int   u32;
extern u32 BMP_MENUWORK_Delete(void *p);
extern void WIFICLUB_ClearTalkWindow(char *);
void WIFICLUB_ClosePartnerMenu(char *p) {
 if (((struct Obj00008 *)p)->f1A4) {
  ((struct Obj00008 *)p)->f1A4=(void *)WIFICLUB_DeleteWindow(((struct Obj00008 *)p)->f1A4);
  BMP_MENULIST_Delete(*(struct Obj * *)&((struct Obj00008 *)p)->fBC,0,(u16 *)(p+0x23c));
  BMP_MENUWORK_Delete(((struct Obj00008 *)p)->fB8);
  WIFICLUB_ClearTalkWindow(p);
 }
}
