/*
 * function: STARTMENU_MenuExit
 * address:  0x021BA014
 * packet:   pkt_ov088_021BA014
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020315D4  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   GAME_BEACON_RegisterClearCallback  0x020274C8  thumb
 *   STARTMENU_ReplaceWithBattleFlagProcNoSave  0x021BC114  thumb  ov088
 *   STARTMENU_ReplaceWithBattleFlagProcWithSave  0x021BC0FC  thumb  ov088
 *   STARTMENU_ChangeToIntroProc  0x021BC0E4  thumb  ov088
 *   func_02030734  0x02030734  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   PROCSYS_ReplaceGlobal  0x020312F8  arm
 *   d_021BDA00     0x021BDA00  data  ov088  a1
 *   d_021DF538     0x021DF538  data  ov121  a4
 *   d_02213C4C     0x02213C4C  data  a4
 *   d_0209DEF0     0x0209DEF0  data  a4
 *   d_021D77AC     0x021D77AC  data  ov016  a4
 *   d_02184904     0x02184904  data  ov168  a4
 *   d_021F6D78     0x021F6D78  data  ov107  a4
 *   d_021BD574     0x021BD574  data  a4
 *   ov121_id       0x00000079  data
 *   ov199_id       0x000000C7  data
 *   ov016_id       0x00000010  data
 *   ov168_id       0x000000A8  data
 *   ov107_id       0x0000006B  data
 *   ov088_id       0x00000058  data
 */
#include "../include/Obj09921.h"
#include "../include/Obj13231.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
extern void GAME_BEACON_RegisterClearCallback(void);
extern void STARTMENU_ReplaceWithBattleFlagProcNoSave(void);
extern void STARTMENU_ReplaceWithBattleFlagProcWithSave(void);
extern void STARTMENU_ChangeToIntroProc(void);
typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *, int, int);
extern void PROCSYS_ReplaceGlobal(u32 a1, u32 a2, u32 a3);
extern char d_021BDA00[];
extern char d_021DF538[];
extern char d_02213C4C[];
extern char d_0209DEF0[];
extern char d_021D77AC[];
extern char d_02184904[];
extern char d_021F6D78[];
extern char d_021BD574[];
extern char ov121_id[];
extern char ov199_id[];
extern char ov016_id[];
extern char ov168_id[];
extern char ov107_id[];
extern char ov088_id[];

int STARTMENU_MenuExit(int a0, int a1, int a2, char *a3)
{
    u8 sel = ((struct Obj13231 *)a3)->f129;
    u8 flag = ((struct Obj13231 *)a3)->f12C;
    char *w;

    func_020315D4((struct S020315D4 *)a0);
    GFL_HEAP_DeleteChecked(0xb);
    switch (sel) {
    case 0:
        GAME_BEACON_RegisterClearCallback();
        if (flag == 0)
            STARTMENU_ReplaceWithBattleFlagProcNoSave();
        else
            STARTMENU_ReplaceWithBattleFlagProcWithSave();
        break;
    case 1:
        GAME_BEACON_RegisterClearCallback();
        STARTMENU_ChangeToIntroProc();
        break;
    case 2:
        PROCSYS_ReplaceGlobal((int)ov121_id, (u32)d_021DF538, 0);
        break;
    case 3:
        w = func_02030734(1, 0x14, 0, d_021BDA00, 0x200);
        MI_CpuFill8(w, 0, 0x14);
        ((struct Obj09921 *)w)->f8 = 0;
        ((struct Obj09921 *)w)->f10 = 1;
        PROCSYS_ReplaceGlobal((int)ov199_id, (u32)d_02213C4C, (u32)w);
        break;
    case 4:
        PROCSYS_ReplaceGlobal(-1, (u32)d_0209DEF0, 0);
        break;
    case 5:
        PROCSYS_ReplaceGlobal((int)ov016_id, (u32)d_021D77AC, 0);
        break;
    case 6:
        PROCSYS_ReplaceGlobal((int)ov168_id, (u32)d_02184904, 0);
        break;
    case 7:
        w = func_02030734(1, 8, 1, d_021BDA00, 0x216);
        ((struct Obj09921 *)w)->f0 = 1;
        PROCSYS_ReplaceGlobal((int)ov107_id, (u32)d_021F6D78, (u32)w);
        break;
    default:
        PROCSYS_ReplaceGlobal((int)ov088_id, (u32)d_021BD574, 0);
        break;
    }
    return 1;
}
