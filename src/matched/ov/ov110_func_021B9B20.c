/*
 * function: PMS_INPUT_VIEW_Delete
 * address: 0x021B9B20
 * packet: pkt_ov110_021B9B20
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02030EAC 0x02030EAC arm
 *   PMSIV_MENU_Delete 0x021BCA30 thumb ov110
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj05284.h"
#include "../include/Obj06380.h"
typedef unsigned char u8;
extern void ARC_TOOL_DeleteHandle(void *);
struct Bank;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void PMSIV_MENU_Delete(u8 *p);
extern unsigned int CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ReleasePalette(unsigned int);
extern void CLACT_ReleaseCharacter(unsigned int);
extern void CLACT_ReleaseCellAnim(unsigned int);
extern void CLACT_ExitSystem(void);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void PMS_INPUT_VIEW_Delete(u8 *p) {
    int i, j;
    if (p) {
        ARC_TOOL_DeleteHandle(((struct Obj06380 *)p)->f8C);
        for (i=0; i<4; ++i) {
            void *r = *(void **)(p+8+i*4);
            if (r) func_02030EAC(r);
        }
        func_02030EAC(((struct Obj06380 *)p)->f0);
        func_02030EAC(((struct Obj06380 *)p)->f4);
        PMSIV_MENU_Delete(((struct Obj06380 *)p)->f64);
        CLACT_DeleteUnit(((struct Obj06380 *)p)->f20);
        for (j=0; j<2; ++j) {
            u8 *r = p+j*12;
            CLACT_ReleasePalette(((struct Obj05284 *)r)->f24);
            CLACT_ReleaseCharacter(((struct Obj05284 *)r)->f28);
            CLACT_ReleaseCellAnim(((struct Obj05284 *)r)->f2C);
            CLACT_ReleasePalette(((struct Obj05284 *)r)->f3C);
            CLACT_ReleaseCharacter(((struct Obj05284 *)r)->f40);
            CLACT_ReleaseCellAnim(((struct Obj05284 *)r)->f44);
        }
        CLACT_ExitSystem();
        BMP_WIN_Exit();
        func_0203F9B4();
        func_020307B0(p);
    }
}
