/*
 * function: STARTMENU_NewGameIntroEnd
 * address:  0x021BC2FC
 * packet:   pkt_ov088_021BC2FC
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020070A4  0x020070A4  thumb
 *   func_02005B04  0x02005B04  thumb
 *   SAVE_CONTROL_INTR_Delete  0x021BD29C  thumb  ov088
 *   func_02008730  0x02008730  thumb
 *   MYSTATUS_Copy  0x02008494  thumb
 *   func_0200873C  0x0200873C  thumb
 *   CONFIG_Copy  0x02008314  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_0203133C  0x0203133C  arm
 *   func_02007210  0x02007210  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   SAVE_OUTSIDE_Load  0x021DFC20  thumb  ov228
 *   SAVE_OUTSIDE_IsLoaded  0x021DFE90  thumb  ov228
 *   SAVE_OUTSIDE_CopyPayload  0x021DFEB0  thumb  ov228
 *   SAVE_OUTSIDE_Free  0x021DFDB8  thumb  ov228
 *   GAMESYSTEM_SetupInitWork  0x02011EEC  thumb
 *   NAMEIN_SETUP_FreeArgs  0x0216C0C0  thumb  ov010
 *   func_020315D4  0x020315D4  arm
 *   PROCSYS_ReplaceGlobal  0x020312F8  arm
 *   ov228_id       0x000000E4  data
 *   d_0209DF9C     0x0209DF9C  data  a4
 */
#include "../include/Obj03676.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Rec12 {
    u32 a, b, c;
} Rec12;

struct Sub02007084Ctrl;
struct Sub020071E4Ctrl;
struct Sub0200852CObj;
struct Sub02008700Obj;
extern struct Sub02007084Ctrl *func_020070A4(void);
extern void func_02005B04(const u32 *arg);
extern void SAVE_CONTROL_INTR_Delete(void *p);
extern struct Sub0200852CObj *func_02008730(void *sys);
extern void MYSTATUS_Copy(void *, void *);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern void CONFIG_Copy(void *, void *);
extern u32 func_020307B0(void *p);
struct S020314B8;
extern void func_0203133C(struct S020314B8 *p);
extern u8 func_02007210(const struct Sub020071E4Ctrl *ctrl);
extern int func_02034AC4(int id);
extern void func_02034A5C(int id);
extern void *SAVE_OUTSIDE_Load(u32 heap);
extern u8 SAVE_OUTSIDE_IsLoaded(u8 *p);
extern void SAVE_OUTSIDE_CopyPayload(char *p, void *ctrl);
extern void SAVE_OUTSIDE_Free(void *);
extern void *GAMESYSTEM_SetupInitWork(u32 a0, u16 a1, struct Rec12 *a2, int a3);
extern int NAMEIN_SETUP_FreeArgs(int);
struct Proc;
extern void func_020315D4(struct Proc *p);
extern void PROCSYS_ReplaceGlobal(u32 a1, u32 a2, u32 a3);
extern u8 ov228_id[];
extern char d_0209DF9C[];

int STARTMENU_NewGameIntroEnd(int a, int b, int c, char *t)
{
    void *r4 = func_020070A4();
    void *r6;
    Rec12 z = {0, 0, 0};
    func_02005B04((const u32 *)(((struct Obj03676 *)t)->f34));
    SAVE_CONTROL_INTR_Delete((void *)(((struct Obj03676 *)t)->f2C));
    MYSTATUS_Copy(((struct Obj03676 *)t)->f54, func_02008730(r4));
    CONFIG_Copy(((struct Obj03676 *)t)->f58, func_0200873C(r4));
    func_020307B0(((struct Obj03676 *)t)->f54);
    func_020307B0(((struct Obj03676 *)t)->f58);
    func_0203133C((struct S020314B8 *)((struct Obj03676 *)t)->f30);
    if (func_02007210(r4) == 1) {
        func_02034AC4((int)ov228_id);
        r6 = SAVE_OUTSIDE_Load(1);
        if (SAVE_OUTSIDE_IsLoaded(r6) == 1)
            SAVE_OUTSIDE_CopyPayload(r6, r4);
        SAVE_OUTSIDE_Free(r6);
        func_02034A5C((int)ov228_id);
    }
    r4 = GAMESYSTEM_SetupInitWork(0, 0, &z, 0);
    NAMEIN_SETUP_FreeArgs(((struct Obj03676 *)t)->f28);
    func_020315D4((struct Proc *)a);
    PROCSYS_ReplaceGlobal(-1, (u32)d_0209DF9C, (u32)r4);
    return 1;
}
