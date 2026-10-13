/*
 * function: PMS_INPUT_VIEW_TaskExit
 * address: 0x021B9FB4
 * packet: pkt_ov110_021B9FB4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 0x021BA058 reads hardware register 0x04000304 before updating it.
 * symbols:
 *   BMP_WIN_Delete 0x020452E8 arm
 *   PMSIV_EDIT_Delete 0x021BBCF0 thumb ov110
 *   PMSIV_CATEGORY_Delete 0x021BB2CC thumb ov110
 *   PMSIV_WORDWIN_Delete 0x021BF8BC thumb ov110
 *   func_020403F4 0x020403F4 arm
 *   PMS_INPUT_VIEW_EndTask 0x021B9CBC thumb ov110
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 *   WIPE_SYS_EndCheck  0x020221A4  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb  arm9
 */
#include "../include/Obj04441.h"
#include "../include/Obj07997.h"
#include "../include/Obj22329.h"
#include "../include/Obj22330.h"
#include "../include/Obj22331.h"
#include "../include/Obj22332.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern u32 WIPE_SYS_EndCheck(void);
struct Descriptor;
struct PrintSys;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void PMSIV_EDIT_Delete(u8 *p);
extern void PMSIV_CATEGORY_Delete(u8 *p);
extern void PMSIV_WORDWIN_Delete(u8 *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void func_020403F4(u32 i);
extern void PMS_INPUT_VIEW_EndTask(u8 *);
void PMS_INPUT_VIEW_TaskExit(int unused, u8 *p) {
    u8 *q = *(u8 * *)&((struct Obj04441 *)p)->f0;
    switch (((struct Obj04441 *)p)->f14) {
    case 0:
        WIPE_SYS_Start(0,0,0,0,5,1,42);
        ++((struct Obj04441 *)p)->f14;
        break;
    case 1:
        if (WIPE_SYS_EndCheck()) {
            BMP_WIN_Delete(((struct Obj22329 *)(*(u8 * *)&((struct Obj04441 *)p)->f0))->f6C);
            PMSIV_EDIT_Delete(((struct Obj22330 *)(*(u8 * *)&((struct Obj04441 *)p)->f0))->f54);
            PMSIV_CATEGORY_Delete(((struct Obj22331 *)(*(u8 * *)&((struct Obj04441 *)p)->f0))->f58);
            PMSIV_WORDWIN_Delete(((struct Obj22332 *)(*(u8 * *)&((struct Obj04441 *)p)->f0))->f5C);
            GF_FONT_Delete(((struct Obj07997 *)q)->f80);
            PRINTSYS_QUE_Clear(((struct Obj07997 *)q)->f7C);
            PRINTSYS_QUE_Delete(((struct Obj07997 *)q)->f7C);
            ((struct Obj07997 *)q)->f7C = 0;
            func_020403F4(0);
            func_020403F4(1);
            func_020403F4(2);
            func_020403F4(3);
            func_020403F4(4);
            func_020403F4(5);
            func_020403F4(6);
            *(volatile u16 *)0x04000304 |= 0x8000;
            PMS_INPUT_VIEW_EndTask(p);
        }
        break;
    }
}
