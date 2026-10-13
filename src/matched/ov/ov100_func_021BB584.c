/*
 * function: func_021BB584
 * address: 0x021BB584
 * packet: pkt_ov100_021BB584
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: original lead code ends021BB64E, alignment nop at64E, pool650..65C;
 *   021BB65C..021BB8C0 are trailing rodata tables, descriptors and filename.
 * lever: bounded u16 off=0x28C avoids cached widened print/node offsets;
 *   off never changes and all additions promote to int, preserving offsets.
 *   C3-u16 EXACT216 after five iterations, manual order/extraction cap2.
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   BUTTON_MAN_Delete 0x02051C6C arm
 *   func_020307B0 0x020307B0 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_021BAC08 0x021BAC08 thumb ov100
 *   func_02030EAC 0x02030EAC arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
#include "../include/Obj02805.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct TaskMenu;struct WordSet;struct PrintSys;struct Node;struct Bank;struct S020315D4;
extern u32 WIPE_SYS_EndCheck(void);
extern int GFL_NET_GetRunState(void);
extern void GFL_NET_COMMAND_DeleteCommandTable(u32);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *);
extern void APP_TASKMENU_WIN_Delete(u8 *);
extern void BUTTON_MAN_Delete(void *);
extern u32 func_020307B0(void *p);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_021BAC08(int);
extern void func_02030EAC(struct Node *);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
extern void PRINTSYS_QUE_Delete(struct PrintSys *);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int);
enum Offset { Words=0x28c };
enum Zero { Clear=0 };
enum PrintOffset { PrintBase=0xcb4 };
static inline struct PrintSys *printSys(u8 *p) { enum PrintOffset t=PrintBase; t+=4; return *(struct PrintSys **)(p+t); }
static inline struct Node *node(u8 *p,enum Offset off) { return *(struct Node **)(p+(off+0x80)); }
static inline void clearNode(u8 *p,enum Offset off,enum Zero zero) { *(int *)(p+(off+0x80))=zero; *(int *)(p+(off+0x84))=zero; }
int func_021BB584(struct S020315D4 *a,int b,int c,u8 *p)
{
    u16 off;
    long zero;
    if(!WIPE_SYS_EndCheck()) return 0;
    if(GFL_NET_GetRunState()) GFL_NET_COMMAND_DeleteCommandTable(0xc00);
    if(*(struct TaskMenu * *)&((struct Obj02805 *)p)->fCC0) APP_TASKMENU_CloseMenu(*(struct TaskMenu * *)&((struct Obj02805 *)p)->fCC0);
    if(*(u8 * *)&((struct Obj02805 *)p)->fCE0) APP_TASKMENU_WIN_Delete(*(u8 * *)&((struct Obj02805 *)p)->fCE0);
    if(*(u8 * *)&((struct Obj02805 *)p)->fCE4) APP_TASKMENU_WIN_Delete(*(u8 * *)&((struct Obj02805 *)p)->fCE4);
    if(((struct Obj02805 *)p)->fCA4) BUTTON_MAN_Delete(((struct Obj02805 *)p)->fCA4);
    func_020307B0(((struct Obj02805 *)p)->fCB4);
    off=Words;
    zero=Clear;
    *(int *)&((struct Obj02805 *)p)->fCA4=zero;
    func_0201ED04(*(struct WordSet **)(p+off));
    func_021BAC08((int)p);
    func_02030EAC(*(struct Node **)(p+(off+0x24)));
    CLACT_DeleteUnit(*(struct Bank **)(p+(off+0x28)));
    CLACT_ExitSystem();
    PRINTSYS_QUE_Clear(printSys(p));
    PRINTSYS_QUE_Delete(printSys(p));
    if(node(p,off)) {
        func_02030EAC(node(p,off));
        clearNode(p,off,zero);
    }
    func_020315D4(a);
    func_020306F0(31);
    return 1;
}
