/*
 * function: IRC_COMPATIBLE_MENU_ProcExit
 * address: 0x021B7734
 * packet: pkt_ov102_021B7734
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * IRC_APPBAR_Delete 0x021B71C0 thumb ov101
 * IRC_COMPATIBLE_MENU_ExitFloaters 0x021B89B8 thumb ov102
 * IRC_COMPATIBLE_MENU_ExitScrollEffect 0x021B87BC thumb ov102
 * IRC_COMPATIBLE_MENU_ExitButtons 0x021B85F4 thumb ov102
 * IRC_COMPATIBLE_MENU_ExitWindow 0x021B7DA8 thumb ov102
 * IRC_COMPATIBLE_MENU_ExitBackgrounds 0x021B7A60 thumb ov102
 * IRC_COMPATIBLE_MENU_ExitDisplay 0x021B78D0 thumb ov102
 * IRC_COMPATIBLE_MENU_ExitText 0x021B7C88 thumb ov102
 * func_020315D4 0x020315D4 arm
 * GFL_HEAP_DeleteChecked 0x020306F0 arm
 */
#include "../include/Obj22138.h"
extern void IRC_APPBAR_Delete(void *p);
typedef unsigned char  u8;
extern void IRC_COMPATIBLE_MENU_ExitFloaters(u8 *p);
extern void IRC_COMPATIBLE_MENU_ExitScrollEffect(void *);
extern void IRC_COMPATIBLE_MENU_ExitButtons(u8 *p);
extern void IRC_COMPATIBLE_MENU_ExitWindow(void *);
extern void IRC_COMPATIBLE_MENU_ExitBackgrounds(unsigned *p);
extern void IRC_COMPATIBLE_MENU_ExitDisplay(void *);
extern void IRC_COMPATIBLE_MENU_ExitText(void *);
struct Proc;
extern void func_020315D4(struct Proc *);
extern void GFL_HEAP_DeleteChecked(unsigned);
int IRC_COMPATIBLE_MENU_ProcExit(unsigned a,int b,int c,char *p) {
 IRC_APPBAR_Delete((void *)(((struct Obj22138 *)p)->f468));
 IRC_COMPATIBLE_MENU_ExitFloaters((u8 *)(p+0x118));
 IRC_COMPATIBLE_MENU_ExitScrollEffect(p+0xfc);
 IRC_COMPATIBLE_MENU_ExitButtons((u8 *)(p+0xc0));
 IRC_COMPATIBLE_MENU_ExitWindow(p+0x46c);
 IRC_COMPATIBLE_MENU_ExitWindow(p+0xac);
 IRC_COMPATIBLE_MENU_ExitBackgrounds((unsigned int *)(p+0x94));
 IRC_COMPATIBLE_MENU_ExitDisplay(p);
 IRC_COMPATIBLE_MENU_ExitText(p+0x9c);
 func_020315D4((struct Proc *)a);
 GFL_HEAP_DeleteChecked(0x3b);
 return 1;
}
