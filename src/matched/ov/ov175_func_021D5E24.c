/*
 * function: WIFIBATTLEMATCH_NET_TaskStepM
 * address: 0x021D5E24
 * packet: pkt_ov175_021D5E24
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: source arm order is 0,3,1,2,4..11; numeric ordering differs
 * by 119 concrete bytes although the compiled size remains 476.
 * DC2C0's return r0 is tested here despite its legacy void declaration.
 * symbols:
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   WIFIBATTLEMATCH_NET_TaskStepN 0x021D6000 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskCleanupA 0x021D61A4 thumb ov175
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   WIFIBATTLEMATCH_NET_SendRegValue 0x021DC2C0 thumb ov175
 *   WIFIBATTLEMATCH_NET_TakeRegValue 0x021DC2D8 thumb ov175
 *   WIFIBATTLEMATCH_NET_HandleNetError 0x021D9F04 thumb ov175
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   MISC_SAVEDATA_GetBlock44 0x0200ED48 thumb
 *   func_02008530 0x02008530 thumb
 *   MISC_SAVEDATA_InsertRecentValue 0x0200ED54 thumb
 *   func_021E8AC0 0x021E8AC0 thumb ov177
 *   WIFIBATTLEMATCH_NET_ClearCancelFlag 0x021DA384 thumb ov175
 *   WIFIBATTLEMATCH_NET_StopMatchmaking 0x021DA390 thumb ov175
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   func_021E8AA8 0x021E8AA8 thumb ov177
 */
#include "../include/Obj02885.h"
typedef unsigned int u32;
typedef unsigned long ul;
typedef unsigned char u8;
struct Big;
struct L0200ED54;
extern void func_021E8AA0(int *, int);
struct Sub0200852CObj;
extern void WIFIBATTLEMATCH_NET_TaskStepN(unsigned sys, int *state, int *p);
extern void WIFIBATTLEMATCH_NET_TaskCleanupA(void *obj, int unused, u8 *p);
extern void func_021E8738(int *, int, int, int);
extern void func_021E8AB4(unsigned, unsigned);
extern int func_021E8844(const int *);
extern void func_021E8AB8(unsigned);
extern int WIFIBATTLEMATCH_NET_SendRegValue(ul, void *);
extern ul WIFIBATTLEMATCH_NET_TakeRegValue(char *, ul *);
extern int WIFIBATTLEMATCH_NET_HandleNetError(char *, void *, void *);
extern void *GAME_DATA_GetSaveControl(struct Big *);
extern void *MISC_SAVEDATA_GetBlock44(void *);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void MISC_SAVEDATA_InsertRecentValue(struct L0200ED54 *, u32);
extern void func_021E8AC0(int, int);
extern void WIFIBATTLEMATCH_NET_ClearCancelFlag(char *);
extern int WIFIBATTLEMATCH_NET_StopMatchmaking(char *);
extern int GAME_DATA_SaveStart(int);
extern int GAME_DATA_SaveMain(u8 *);
extern void func_021E8AA8(int);
#define P(k) (*(int *)(p + (k)))
#define TIMER (*(u32 *)(p + 0xe0))
void WIFIBATTLEMATCH_NET_TaskStepM(unsigned sys, int *state, char *p)
{
    char *q = (char *)P(0x40);
    void *list;
    switch (*state) {
    case 0:
        if (((struct Obj02885 *)q)->fC == 2) func_021E8AA0((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepN);
        else *state = 3;
        break;
    case 3:
        func_021E8738((int *)P(0x24), P(0x10), 43, 2);
        *state = 11;
        func_021E8AB4(sys, 1);
        TIMER = 0;
        break;
    case 1:
        if (WIFIBATTLEMATCH_NET_SendRegValue(P(0x30), *(char * *)&((struct Obj02885 *)q)->f2C + 0x10)) *state = 2;
        break;
    case 2:
        if (WIFIBATTLEMATCH_NET_TakeRegValue((char *)P(0x30), (ul *)(*(char * *)&((struct Obj02885 *)q)->f2C + 0x14))) *state = 4;
        switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)P(0x30), 0, (void *)1)) {
        case 1: case 4: TIMER = 0; *state = 7; break;
        case 2: TIMER = 0; func_021E8AA0((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        }
        break;
    case 4:
        list = MISC_SAVEDATA_GetBlock44(GAME_DATA_GetSaveControl((struct Big *)**(int * *)&((struct Obj02885 *)q)->f8));
        MISC_SAVEDATA_InsertRecentValue(list, func_02008530(((struct Obj02885 *)q)->f18));
        func_021E8AC0(**(int * *)&((struct Obj02885 *)q)->f8, **(int * *)&((struct Obj02885 *)q)->f2C);
        WIFIBATTLEMATCH_NET_ClearCancelFlag((char *)P(0x30));
        *state = 5;
        break;
    case 5:
        TIMER++;
        if (WIFIBATTLEMATCH_NET_StopMatchmaking((char *)P(0x30))) *state = 6;
        switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)P(0x30), 0, (void *)1)) {
        case 1: case 4: TIMER = 0; *state = 7; break;
        case 2: TIMER = 0; func_021E8AA0((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        }
        break;
    case 6:
        if (TIMER++ > 30) { TIMER = 0; *state = 7; }
        break;
    case 7:
        *state = 8;
        break;
    case 8:
        func_021E8738((int *)P(0x24), P(0x10), 40, 2);
        *state = 11;
        func_021E8AB4(sys, 9);
        break;
    case 9:
        GAME_DATA_SaveStart(**(int * *)&((struct Obj02885 *)q)->f8);
        *state = 10;
        break;
    case 10:
        switch (GAME_DATA_SaveMain((u8 *)**(int * *)&((struct Obj02885 *)q)->f8)) {
        case 0: case 1: break;
        case 2: case 3: ((struct Obj02885 *)q)->f4 = 2; func_021E8AA8(sys); break;
        }
        break;
    case 11:
        if (func_021E8844((int *)P(0x24))) func_021E8AB8(sys);
        break;
    }
}
