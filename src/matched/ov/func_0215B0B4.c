/*
 * function: SCRCMD_WORK_CmdGetPlayerSaveValue
 * address:  0x0215B0B4
 * packet:   pkt_0215B0B4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocked:  
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_020089C0  0x020089C0  thumb
 *   func_02008554  0x02008554  thumb
 *   CURSOR_MOVE_GetTableGroup  0x02025C88  thumb
 *   func_020089F4  0x020089F4  thumb
 *   func_02008A00  0x02008A00  thumb
 */
#include "../include/Obj17686.h"
#include "../include/Obj17687.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct SaveBlock;
struct Big;
struct Sub020089A8Obj;
extern unsigned short *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub020089A8Obj *func_020089C0(void *sys);
struct Sub0200852CObj;
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u32 CURSOR_MOVE_GetTableGroup(u32 x);
extern u8 func_020089F4(const struct Sub020089A8Obj *obj);
extern struct Sub020089A8Obj *func_02008A00(struct Sub020089A8Obj *obj);

int SCRCMD_WORK_CmdGetPlayerSaveValue(int a0, int a1)
{
    int t4;
    int t6;
    char *sb;
    void *p;
    struct Sub020089A8Obj *obj;
    unsigned short *v0;
    unsigned short *v1;
    void *v2;

t6 = a0 + 0;
t4 = a1 + 0;
    v0 = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
loc_0215B0BE:
a0 = t6 + 0;
a1 = t4 + 0;
    v1 = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
loc_0215B0C8:
a0 = t4 + 0;
    v2 = SCRCMD_WORK_GetGameData((void *)a0);
loc_0215B0D0:
    sb = GAME_DATA_GetMyPlayerWork((struct SaveBlock *)v2);
loc_0215B0D6:
    p = GAME_DATA_GetSaveControl((struct Big *)v2);
loc_0215B0DE:
    obj = func_020089C0(p);
loc_0215B0E2:
sb = sb + 0x20;
    a0 = func_02008554((const struct Sub0200852CObj *)sb);
loc_0215B0EC:
    a0 = CURSOR_MOVE_GetTableGroup(a0);
loc_0215B0F0:
((struct Obj17687 *)((char *)v1))->f0 = a0;
    a0 = func_020089F4(obj);
loc_0215B0F8:
((struct Obj17686 *)((char *)v0))->f0 = a0;
    a0 = (int)func_02008A00(obj);
loc_0215B100:
a0 = 0;
    return a0;}
