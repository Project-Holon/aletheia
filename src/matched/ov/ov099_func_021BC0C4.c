/*
 * function: WIFICLUB_DeleteMenuAndIcons
 * address:  0x021BC0C4
 * packet:   pkt_ov099_021BC0C4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUB_DeletePartyIcons  0x021BBD80  thumb  ov099
 *   WIFICLUB_DeletePartyListWindow  0x021BBC0C  thumb  ov099
 *   WIFICLUB_DeleteWindow  0x021BA8BC  thumb  ov099
 *   BMP_MENULIST_Delete  0x0202020C  thumb
 *   BMP_MENUWORK_Delete  0x0201F868  thumb
 */
#include "../include/Obj05261.h"

typedef unsigned short u16;
struct Obj;
extern void WIFICLUB_DeletePartyIcons(char *s);
extern void WIFICLUB_DeletePartyListWindow(void *p);
extern int WIFICLUB_DeleteWindow(void *p);
extern void BMP_MENULIST_Delete(struct Obj *o, u16 *a, u16 *b);
typedef unsigned int   u32;
extern u32 BMP_MENUWORK_Delete(void *p);

void WIFICLUB_DeleteMenuAndIcons(char *p)
{
    if (((struct Obj05261 *)p)->f1A4 != 0) {
        WIFICLUB_DeletePartyIcons(p);
        WIFICLUB_DeletePartyListWindow(p);
        ((struct Obj05261 *)p)->f1A4 = (void *)WIFICLUB_DeleteWindow(((struct Obj05261 *)p)->f1A4);
        BMP_MENULIST_Delete(((struct Obj05261 *)p)->fBC, 0, 0);
        BMP_MENUWORK_Delete(((struct Obj05261 *)p)->fB8);
        ((struct Obj05261 *)p)->fB8 = 0;
    }
}
