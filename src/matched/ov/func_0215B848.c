/*
 * function: SCRCMD_PROC_FindFirstPartyIndex
 * address:  0x0215B848
 * packet:   pkt_0215B848
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_FindFirstBattleReady  0x0201AB08  thumb
 *   POKEPARTY_FindFirstNonEgg  0x0201AB18  thumb
 */
#include "../include/Obj17690.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern unsigned short *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameData(void *a0);
struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u32 POKEPARTY_FindFirstBattleReady(void *p);
extern u32 POKEPARTY_FindFirstNonEgg(void *p);

int SCRCMD_PROC_FindFirstPartyIndex(int a0, int a1)
{
    int t4;
    int t5;
    unsigned short *v0;
    void *p;

t4 = a0 + 0;
t5 = a1 + 0;
    v0 = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
loc_0215B852:
a0 = t4 + 0;
a1 = t5 + 0;
    a0 = (int)SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
loc_0215B85C:
t4 = a0 + 0;
a0 = t5 + 0;
    p = SCRCMD_WORK_GetGameData((void *)a0);
loc_0215B864:
    p = GAME_DATA_GetMyParty(p);
loc_0215B868:
    if (t4 == 1) goto loc_0215B87A;
loc_0215B86C:
    if (t4 != 2) goto loc_0215B880;
loc_0215B870:
    a0 = POKEPARTY_FindFirstBattleReady(p);
loc_0215B874:
a0 = a0 << 0x10;
a0 = (unsigned)a0 >> 0x10;
    goto loc_0215B882;
loc_0215B87A:
    a0 = POKEPARTY_FindFirstNonEgg(p);
loc_0215B87E:
    goto loc_0215B874;
loc_0215B880:
a0 = 0;
loc_0215B882:
((struct Obj17690 *)((char *)v0))->f0 = a0;
a0 = 0;
    return a0;}
