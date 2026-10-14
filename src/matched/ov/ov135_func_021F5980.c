/*
 * function: WORLDTRADE_BOX_CreateStrings
 * address: 0x021F5980
 * packet: pkt_ov135_021F5980
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_BOX_RestoreCursorSave 0x021F6E08 thumb ov135
 *   STRBUF_Create 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02030734 0x02030734 arm
 *   str_02203B54 0x02203B54 data a1
 */
#include "../include/Obj04526.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WORLDTRADE_BOX_RestoreCursorSave(u8 *);
struct MsgBank;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char str_02203B54[];
void WORLDTRADE_BOX_CreateStrings(u8 *p)
{
    WORLDTRADE_BOX_RestoreCursorSave(p);
    ((struct Obj04526 *)p)->fB80 = STRBUF_Create(0x12, 0x48);
    ((struct Obj04526 *)p)->fB88 = STRBUF_Create(0xb4, 0x48);
    ((struct Obj04526 *)p)->fB84 = func_02045EC0(((struct Obj04526 *)p)->fB6C, 0x73);
    if (((struct Obj04526 *)p)->fC6 == 0x1e) {
        ((struct Obj04526 *)p)->fC6 = 0;
    }
    ((struct Obj04526 *)p)->fEAC = func_02030734(0x48, 0x78, 0, str_02203B54, 0x344);
}
