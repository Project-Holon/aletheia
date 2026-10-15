/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_MenuCardCheck1
 * address: 0x0217B594
 * packet: pkt_ov176_0217B594
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   DIGITALCARDCHECK_Create 0x0217D398 thumb ov176
 *   DIGITALCARDCHECK_DeleteAlt 0x0217D434 thumb ov176
 *   DIGITALCARDCHECK_GetProcResult 0x0217D44C thumb ov176
 *   DIGITALCARDCHECK_Delete 0x0217D410 thumb ov176
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse 0x0217B4A0 thumb ov176
 */
#include "../include/Obj02221.h"
typedef struct { int mode; int a,b,c,d,e,f,g; } Config;
extern void MI_CpuFill8(void *,int,int);
extern int DIGITALCARDCHECK_Create(Config *,int);
extern void DIGITALCARDCHECK_DeleteAlt(int *p);
extern int DIGITALCARDCHECK_GetProcResult(int *p);
extern void DIGITALCARDCHECK_Delete(int *p);
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *p, int v);
extern void BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse(int p, unsigned *state, int *q);
void BATTLE_CHAMPIONSHIP_FLOW_MenuCardCheck1(int p, int *state, char *q)
{
    Config config;
    switch (*state) {
    case 0:
        MI_CpuFill8(&config, 0, 32);
        config.mode = 0;
        config.a = ((struct Obj02221 *)q)->f18;
        config.b = ((struct Obj02221 *)q)->f1C;
        config.c = ((struct Obj02221 *)q)->f20;
        config.d = ((struct Obj02221 *)q)->f24;
        config.e = ((struct Obj02221 *)q)->f28;
        config.f = ((struct Obj02221 *)q)->f2C;
        config.g = ((struct Obj02221 *)q)->f30;
        ((struct Obj02221 *)q)->f38 = DIGITALCARDCHECK_Create(&config, ((struct Obj02221 *)q)->f34);
        (*state)++;
        break;
    case 1:
        DIGITALCARDCHECK_DeleteAlt((int *)(((struct Obj02221 *)q)->f38));
        if (DIGITALCARDCHECK_GetProcResult((int *)(((struct Obj02221 *)q)->f38))) (*state)++;
        break;
    case 2:
        DIGITALCARDCHECK_Delete((int *)(((struct Obj02221 *)q)->f38));
        WIFIBATTLEMATCH_UTIL_SetCallback((int *)p, (int)BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse);
        break;
    }
}
