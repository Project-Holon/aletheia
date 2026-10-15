/*
 * unit: yes
 * function: WIFI_2DCHAR_StepActorAnimDispatch, WIFI_2DCHAR_SetAnimSeq, WIFI_2DCHAR_SetAnimSeq4, WIFI_2DCHAR_SetAnimSeqPlus5
 * address: 0x021C4634
 * packet: pkt_ov127_021C4634
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   sWifi2dcharAnimStepTable 0x021C5FE4 data a4
 *   CLACT_ChangeActorAnimSeq 0x0204B8A0 arm
 */
#include "../include/Obj14021.h"
#include "../include/Obj14022.h"
#include "../include/Obj14023.h"
#include "../include/Obj23024.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void (*const sWifi2dcharAnimStepTable[])(u8 *);
struct Obj;
extern void CLACT_ChangeActorAnimSeq(struct Obj *p, u16 v);
void WIFI_2DCHAR_StepActorAnimDispatch(u8 *p)
{
    void (*f)(u8 *);
    f = sWifi2dcharAnimStepTable[((struct Obj23024 *)p)->fC];
    if (f) f(p);
}
void WIFI_2DCHAR_SetAnimSeq(u8 *p, u32 i)
{
    ((struct Obj14021 *)p)->f10 = i;
    CLACT_ChangeActorAnimSeq(((struct Obj14021 *)p)->f4, i);
}
void WIFI_2DCHAR_SetAnimSeq4(u8 *p, u32 i)
{
    ((struct Obj14022 *)p)->f10 = i;
    CLACT_ChangeActorAnimSeq(((struct Obj14022 *)p)->f4, 4);
}
void WIFI_2DCHAR_SetAnimSeqPlus5(u8 *p, u32 i)
{
    ((struct Obj14023 *)p)->f10 = i;
    CLACT_ChangeActorAnimSeq(((struct Obj14023 *)p)->f4, i + 5);
}
