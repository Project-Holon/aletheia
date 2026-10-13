/*
 * function: BSUBWAY_RECORD_LIST_InitCursor
 * address: 0x021B9F24
 * packet: pkt_ov069_021B9F24
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02025CD0 0x02025CD0 thumb
 *   BSUBWAY_RECORD_LIST_PlaceCursorActor 0x021B9FC8 thumb ov069
 *   sCursorEntries 0x021BA71C data a4
 *   sCursorCallbacks 0x021BA5EC data a4
 */
#include "../include/Obj09876.h"
extern const char sCursorEntries[], sCursorCallbacks[];
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Struct_02025CD0;
extern struct Struct_02025CD0 *func_02025CD0(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 heapId);
extern void BSUBWAY_RECORD_LIST_PlaceCursorActor(char *p, int i);
void BSUBWAY_RECORD_LIST_InitCursor(char *p)
{
    ((struct Obj09876 *)p)->f14C = func_02025CD0((u32)sCursorEntries, (u32)sCursorCallbacks, (u32)p, 1, 0, 0x80);
    BSUBWAY_RECORD_LIST_PlaceCursorActor(p, 0);
}
