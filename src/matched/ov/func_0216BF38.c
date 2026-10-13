/*
 * function: FIELD_G3D_MAP_ScrCmdReadSaveByte
 * address:  0x0216BF38
 * packet:   pkt_0216BF38
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 60 compiled 58
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200D418  0x0200D418  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   func_0200D468  0x0200D468  thumb
 */
#include "../include/Obj00005.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;

extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200D418(void *sys);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern unsigned short *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
struct Blk38;
extern u8 func_0200D468(struct Blk38 *p, u32 i);

int FIELD_G3D_MAP_ScrCmdReadSaveByte(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    void *t7;
    void *p;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    p = SCRCMD_WORK_GetGameData((void *)a0);
loc_0216BF44:
    p = GAME_DATA_GetSaveControl((struct Big *)p);
loc_0216BF48:
    t7 = func_0200D418(p);
loc_0216BF4C:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
loc_0216BF56:
a0 = a0 << 0x18;
t4 = (unsigned)a0 >> 0x18;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = (int)SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1); /* int-typed on purpose: pointer local changes codegen */
loc_0216BF62:
t5 = a0 + 0;
a1 = t4 + 0;
    a0 = func_0200D468(t7, a1);
loc_0216BF6C:
*(u16 *)&((struct Obj00005 *)((char *)t5))->f0 = a0;
a0 = 0;
    return a0;}
