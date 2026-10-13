/*
 * function: P_STA_SKILL_UpdateInput
 * address: 0x021DA958
 * packet: pkt_ov131_021DA958
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment padding at 0x021DA996.
 * symbols:
 *   P_STA_SKILL_HandleKeys 0x021DA998 thumb ov131
 *   P_STA_SKILL_HandleTouch 0x021DABCC thumb ov131
 *   P_STA_SKILL_HandleKeysForget 0x021DAEE4 thumb ov131
 *   P_STA_SKILL_HandleTouchForget 0x021DB140 thumb ov131
 *   func_02035C38 0x02035C38 arm
 */
#include "../include/Obj00026.h"
typedef unsigned char u8;
extern int P_STA_SKILL_HandleKeys(u8 *,u8 *);
extern void P_STA_SKILL_HandleTouch(u8 *,u8 *);
extern int P_STA_SKILL_HandleKeysForget(u8 *,u8 *);
extern void P_STA_SKILL_HandleTouchForget(u8 *,u8 *);
extern int func_02035C38(void);
void P_STA_SKILL_UpdateInput(u8 *a,u8 *b) {
    if ((*(u8 **)(a+8))[13] != 2) {
        if (P_STA_SKILL_HandleKeys(a,b)==0) P_STA_SKILL_HandleTouch(a,b);
    } else {
        if (P_STA_SKILL_HandleKeysForget(a,b)==0) P_STA_SKILL_HandleTouchForget(a,b);
    }
    if (func_02035C38()==0) ((struct Obj00026 *)b)->f1C=0;
}
