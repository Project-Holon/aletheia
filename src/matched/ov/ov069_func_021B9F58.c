/*
 * unit: yes
 * function: BSUBWAY_RECORD_LIST_DeleteCursor, BSUBWAY_RECORD_LIST_CursorCallbackNop0, BSUBWAY_RECORD_LIST_CursorCallbackNop1
 * address: 0x021B9F58
 * packet: pkt_ov069_021B9F58
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * evidence: 02025D14 forwards r0 to 02030164, whose body reads the pointer
 * and returns a predicate; its legacy void(void) declaration is incomplete.
 * symbols:
 *   CURSOR_MOVE_Delete 0x02025D14 thumb
 */
#include "../include/Obj01132.h"
typedef unsigned int   u32;
extern u32 CURSOR_MOVE_Delete(void *a0);
int BSUBWAY_RECORD_LIST_DeleteCursor(char *p)
{
    return CURSOR_MOVE_Delete(((struct Obj01132 *)p)->f14C);
}
void BSUBWAY_RECORD_LIST_CursorCallbackNop0(void) {}
void BSUBWAY_RECORD_LIST_CursorCallbackNop1(void) {}
