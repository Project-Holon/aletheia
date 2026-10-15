/*
 * unit: yes
 * function: WIFI_2DCHAR_AdvanceAnimSeq, WIFI_2DCHAR_SetAnimSeqPlus9, WIFI_2DCHAR_SetAnimSeqPlus5B, WIFI_2DCHAR_SetAnimSeqPlus5C, WIFI_2DCHAR_SetAnimSeqPlus5D, WIFI_2DCHAR_SetAnimSeqPlus5E, WIFI_2DCHAR_AddAnimFrame, WIFI_2DCHAR_AddAnimFrame2
 * address: 0x021C4680
 * packet: pkt_ov127_021C4680
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_ChangeActorAnimSeq 0x0204B8A0 arm
 *   CLACT_AddActorAnimFrame 0x0204B8D4 arm
 */
#include "../include/Obj10468.h"
#include "../include/Obj14024.h"
#include "../include/Obj14025.h"
#include "../include/Obj14026.h"
#include "../include/Obj14027.h"
#include "../include/Obj14028.h"
#include "../include/Obj23025.h"
#include "../include/Obj23026.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_ChangeActorAnimSeq(struct Obj *p, u16 v);
extern void CLACT_AddActorAnimFrame(struct Obj *p, u32 arg);
void WIFI_2DCHAR_AdvanceAnimSeq(u8 *p, u32 i)
{
    CLACT_ChangeActorAnimSeq(((struct Obj10468 *)p)->f4, ((struct Obj10468 *)p)->f10 + 5);
    ((struct Obj10468 *)p)->f10 = i;
}
void WIFI_2DCHAR_SetAnimSeqPlus9(u8 *p, u32 i)
{
    ((struct Obj14024 *)p)->f10 = i;
    CLACT_ChangeActorAnimSeq(((struct Obj14024 *)p)->f4, i + 9);
}
void WIFI_2DCHAR_SetAnimSeqPlus5B(u8 *p, u32 i)
{
    ((struct Obj14025 *)p)->f10 = i;
    CLACT_ChangeActorAnimSeq(((struct Obj14025 *)p)->f4, i + 5);
}
void WIFI_2DCHAR_SetAnimSeqPlus5C(u8 *p, u32 i)
{
    ((struct Obj14026 *)p)->f10 = i;
    CLACT_ChangeActorAnimSeq(((struct Obj14026 *)p)->f4, i + 5);
}
void WIFI_2DCHAR_SetAnimSeqPlus5D(u8 *p, u32 i)
{
    ((struct Obj14027 *)p)->f10 = i;
    CLACT_ChangeActorAnimSeq(((struct Obj14027 *)p)->f4, i + 5);
}
void WIFI_2DCHAR_SetAnimSeqPlus5E(u8 *p, u32 i)
{
    ((struct Obj14028 *)p)->f10 = i;
    CLACT_ChangeActorAnimSeq(((struct Obj14028 *)p)->f4, i + 5);
}
void WIFI_2DCHAR_AddAnimFrame(u8 *p) { CLACT_AddActorAnimFrame(((struct Obj23025 *)p)->f4, 8192); }
void WIFI_2DCHAR_AddAnimFrame2(u8 *p) { CLACT_AddActorAnimFrame(((struct Obj23026 *)p)->f4, 8192); }
