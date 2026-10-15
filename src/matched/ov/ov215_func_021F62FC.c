/*
 * unit: yes
 * function: EGG_DEMO_MENU_CreateDialog,EGG_DEMO_MENU_GetDialogResult
 * address: 0x021F62FC
 * packet: pkt_ov215_021F62FC
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: includes cleared tiny follower EGG_DEMO_MENU_GetDialogResult; no further code included.
 * symbols:
 *   BMP_MENU_CreateYesNo 0x0201FDA0 thumb
 */
#include "../include/Obj06706.h"
#include "../include/Obj25748.h"
struct WinDat;
struct BmpMenu;
extern struct BmpMenu *BMP_MENU_CreateYesNo(const struct WinDat *,unsigned short,unsigned char,unsigned char,unsigned short);
int EGG_DEMO_MENU_CreateDialog(int a,char *p){*(struct BmpMenu * *)&((struct Obj06706 *)p)->f78=BMP_MENU_CreateYesNo((const struct WinDat *)(p+0x70),((struct Obj06706 *)p)->f60,2,0,((struct Obj06706 *)p)->f0);((struct Obj06706 *)p)->f7C=2;((struct Obj06706 *)p)->f20=1;return 1;}
int EGG_DEMO_MENU_GetDialogResult(int a,char *p){return ((struct Obj25748 *)p)->f7C;}
