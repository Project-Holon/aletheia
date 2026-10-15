/*
 * function: CTVT_TALK_OpenConfirmMenu
 * address: 0x021B9C9C
 * packet: pkt_ov172_021B9C9C
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   COMM_TVT_SYS_GetComm 0x021BDFE4 thumb ov172
 *   func_021B80E4 0x021B80E4 thumb ov172
 *   COMM_TVT_SYS_GetSelfSlot 0x021BE0A4 thumb ov172
 *   COMM_TVT_SYS_GetMemberCount 0x021BE054 thumb ov172
 *   CTVT_TALK_ShowMessage 0x021B9C1C thumb ov172
 *   COMM_TVT_SYS_OpenConfirmMenu 0x021BE11C thumb ov172
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 */
#include "../include/Obj08259.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 COMM_TVT_SYS_GetComm(void *);
extern u32 func_021B80E4(int, char *);
extern u32 COMM_TVT_SYS_GetSelfSlot(void *p);
extern u8 COMM_TVT_SYS_GetMemberCount(void *);
extern void CTVT_TALK_ShowMessage(void *p, char *q, int id);
extern u32 COMM_TVT_SYS_OpenConfirmMenu(u8 *p);
struct Actor;
struct Obj;
typedef unsigned short u16;
extern u32 CLACT_IsActorAnimActive(struct Actor *);
extern void CLACT_SetActorAnimSeq(struct Obj *, u16);
void CTVT_TALK_OpenConfirmMenu(void *p, char *q)
{
    if (func_021B80E4((int)p, (char *)COMM_TVT_SYS_GetComm(p)) == 5) {
        CTVT_TALK_ShowMessage(p, q, 32);
    } else if (COMM_TVT_SYS_GetSelfSlot(p) == 0 && COMM_TVT_SYS_GetMemberCount(p) > 1) {
        CTVT_TALK_ShowMessage(p, q, 33);
    } else {
        CTVT_TALK_ShowMessage(p, q, 32);
    }
    ((struct Obj08259 *)q)->f80 = (void *)COMM_TVT_SYS_OpenConfirmMenu(p);
    ((struct Obj08259 *)q)->f0 = 10;
    if (CLACT_IsActorAnimActive(((struct Obj08259 *)q)->f98) == 0)
        CLACT_SetActorAnimSeq(((struct Obj08259 *)q)->f98, 15);
}
