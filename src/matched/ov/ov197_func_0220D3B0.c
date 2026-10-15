/*
 * function: func_0220D3B0
 * address: 0x0220D3B0
 * packet: pkt_ov197_0220D3B0
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: explicit if/else field stores preserve one-first branch and shared store.
 * symbols:
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   WIPE_SYS_ExeEnd 0x020221B8 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   func_0220BD14 0x0220BD14 thumb ov197
 *   func_0220C448 0x0220C448 thumb ov197
 *   B_BAG_MAIN_ExitWindows 0x0220B1A0 thumb ov197
 *   func_0220D7D0 0x0220D7D0 thumb ov197
 *   func_0220D6B8 0x0220D6B8 thumb ov197
 *   TCBL_Destroy 0x02031140 arm
 *   func_0220D914 0x0220D914 thumb ov197
 *   B_APP_TOOL_Delete 0x0220AF64 thumb ov196
 *   func_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj00846.h"
#include "../include/Obj25091.h"
#include "../include/Obj25092.h"
#include "../include/Obj25093.h"
#include "../include/Obj25095.h"
#include "../include/Obj25097.h"
typedef unsigned char u8;
struct PrintSys;
struct Rec3;
struct S02031140;
struct Node;
extern unsigned PRINTSYS_QUE_IsFinished(const struct PrintSys *);
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
extern unsigned WIPE_SYS_EndCheck(void);
extern void WIPE_SYS_ExeEnd(void);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *);
extern void func_0220BD14(char *);
extern void func_0220C448(char *);
extern void B_BAG_MAIN_ExitWindows(char *);
extern void func_0220D7D0(char *);
extern void func_0220D6B8(void);
extern void TCBL_Destroy(struct S02031140 *);
extern unsigned func_0220D914(u8 *);
extern void B_APP_TOOL_Delete(void *);
extern void func_02030EAC(struct Node *);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
int func_0220D3B0(struct Node *task, char *p)
{
    if (((struct Obj00846 *)p)->f5A0 == 1) {
        if (PRINTSYS_QUE_IsFinished(*(struct PrintSys * *)&((struct Obj00846 *)p)->f18) == 0) {
            if (((struct Obj25091 *)(*(char * *)&((struct Obj00846 *)p)->f0))->f24 == 1) PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj00846 *)p)->f18);
            else return 0;
        }
        if (WIPE_SYS_EndCheck() == 0) {
            if (((struct Obj25092 *)(*(char * *)&((struct Obj00846 *)p)->f0))->f24 == 1) WIPE_SYS_ExeEnd();
            else return 0;
        }
        if (*(struct Rec3 * *)&((struct Obj00846 *)p)->f1C) PRINTSYS_PrintStreamDelete(*(struct Rec3 * *)&((struct Obj00846 *)p)->f1C);
        func_0220BD14(p);
        func_0220C448(p);
        B_BAG_MAIN_ExitWindows(p);
        func_0220D7D0(p);
        func_0220D6B8();
        TCBL_Destroy(*(struct S02031140 * *)&((struct Obj00846 *)p)->f4);
        func_0220D914((u8 *)p);
        B_APP_TOOL_Delete(((struct Obj00846 *)p)->f148);
        if (((struct Obj00846 *)p)->f598 == 1) {
            **(u8 * *)&((struct Obj25093 *)(*(char * *)&((struct Obj00846 *)p)->f0))->f2C = 1;
        } else {
            **(u8 * *)&((struct Obj25095 *)(*(char * *)&((struct Obj00846 *)p)->f0))->f2C = 0;
        }
    }
    ((struct Obj25097 *)(*(char * *)&((struct Obj00846 *)p)->f0))->f19 = 1;
    func_02030EAC(task);
    func_020307B0(p);
    return 1;
}
