/*
 * function: WIFIBATTLEMATCH_NET_CopyCompBox
 * address: 0x021D9A50
 * packet: pkt_ov175_021D9A50
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_BOX_GetFromSave 0x0200BAC8 thumb
 *   func_0200BAF4 0x0200BAF4 thumb
 *   POKEPARTY_Init 0x0201A948 thumb
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj00013.h"
#include "../include/Obj24310.h"
#include "../include/Obj24311.h"
extern void MI_CpuFill8(void *, int, int);
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *BATTLE_BOX_GetFromSave(void *);
extern void *func_0200BAF4(int a0, int a1);
extern void *POKEPARTY_Init(void *);
extern int POKE_REGULATION_GetDataSize(void *);
extern void MI_CpuCopy8(const void *, void *, int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void WIFIBATTLEMATCH_NET_CopyCompBox(char *dest, char *ctx)
{
    void *records;
    MI_CpuFill8(dest, 0, 212);
    records = func_0200BAF4((int)BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(**(void ** *)&((struct Obj24311 *)(*(char * *)&((struct Obj00013 *)ctx)->f104))->f8)), 87);
    MI_CpuCopy8(records, dest + 212, POKE_REGULATION_GetDataSize(POKEPARTY_Init(dest + 212)));
    func_020307B0(records);
    ((struct Obj24310 *)dest)->f44 = 100;
}
