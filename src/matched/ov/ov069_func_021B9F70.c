/*
 * function: BSUBWAY_RECORD_LIST_CursorCallbackMoved
 * address: 0x021B9F70
 * packet: pkt_ov069_021B9F70
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BSUBWAY_RECORD_LIST_ShowRecordDetails 0x021B9FF0 thumb ov069
 *   BSUBWAY_RECORD_LIST_PlaceCursorActor 0x021B9FC8 thumb ov069
 *   func_020061E4 0x020061E4 thumb
 */
#include "../include/Obj13148.h"
struct Rec;
extern void BSUBWAY_RECORD_LIST_ShowRecordDetails(char *p, struct Rec *tbl, int idx);
extern void BSUBWAY_RECORD_LIST_PlaceCursorActor(char *p, int i);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
void BSUBWAY_RECORD_LIST_CursorCallbackMoved(char *p, int i)
{
    BSUBWAY_RECORD_LIST_ShowRecordDetails(p, ((struct Obj13148 *)p)->f8, (int)((unsigned)i + (unsigned)((struct Obj13148 *)p)->f160 * 10u));
    BSUBWAY_RECORD_LIST_PlaceCursorActor(p, i);
    func_020061E4(0x548);
}
