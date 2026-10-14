/*
 * function: GURU2_RECEIPT_StateOpenCancelMenu
 * address: 0x021DDBB0
 * packet: pkt_ov137_021DDBB0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: original r0 holds p at the call to GURU2_RECEIPT_Noop; retain that
 * explicit input despite the pending empty callee's no-argument declaration.
 * symbols:
 *   GURU2_RECEIPT_Noop 0x021DD924 thumb ov137
 *   BMP_MENU_CreateYesNo 0x0201FDA0 thumb
 *   gGuru2YesNoMenuTemplate 0x021E1AE8 data a2
 */
#include "../include/Obj14211.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GURU2_RECEIPT_Noop(char *p);
typedef struct {u8 frame,x,y,pal;u16 chr;} WinDat;
struct BmpMenu;
extern const WinDat gGuru2YesNoMenuTemplate;
extern struct BmpMenu *BMP_MENU_CreateYesNo(const WinDat *,u16,u8,u8,u16);
int GURU2_RECEIPT_StateOpenCancelMenu(char *p,int state) {*(struct BmpMenu * *)&((struct Obj14211 *)p)->fE8=BMP_MENU_CreateYesNo(&gGuru2YesNoMenuTemplate,31,11,0,114);((struct Obj14211 *)p)->f118=23;GURU2_RECEIPT_Noop(p);return state;}
