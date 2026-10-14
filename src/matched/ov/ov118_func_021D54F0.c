/*
 * function: func_021D54F0
 * address:  0x021D54F0
 * packet:   pkt_ov118_021D54F0
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKETRADE_PROC_IsHostSide  0x021D8AA8  thumb  ov119
 *   POKETRADE_PROC_GetSideMon  0x021D8FA4  thumb  ov119
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_PERSONAL_Create  0x0201ADE4  thumb
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb
 *   POKE_PERSONAL_Delete  0x0201AE14  thumb
 *   func_02008530  0x02008530  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj22664.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern int POKETRADE_PROC_IsHostSide(void *p);
extern void *POKETRADE_PROC_GetSideMon(void *p, int which);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 arg);
extern void *POKE_PERSONAL_Create(u32 a, int b, u32 heap);
struct Personal;
struct Sub0200852CObj;
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void POKE_PERSONAL_Delete(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);

void func_021D54F0(u8 *p, u8 *outSame, u8 *outFlag, u32 key, int enemy)
{
    int which;
    void *mon;
    u32 id;
    u32 a;
    u32 b;
    u32 egg;
    u32 h;
    u32 flag;

    if (enemy != 0) {
        if (POKETRADE_PROC_IsHostSide(p) != 0) {
            which = 1;
        } else {
            which = 0;
        }
    } else {
        if (POKETRADE_PROC_IsHostSide(p) != 0) {
            which = 0;
        } else {
            which = 1;
        }
    }
    mon = POKETRADE_PROC_GetSideMon(p, which);
    id = POKE_TOOL_GetPartyValue(mon, 7, 0);
    a = POKE_TOOL_GetPartyValue(mon, 0xAB, 0);
    b = POKE_TOOL_GetPartyValue(mon, 0x6F, 0);
    egg = POKE_TOOL_GetPartyValue(mon, 0x4C, 0);
    if (egg == 0) {
        h = (u32)POKE_PERSONAL_Create((u16)a, (u16)b, ((struct Obj22664 *)p)->f5F4);
        flag = POKE_PERSONAL_GetParam((const struct Personal *)h, 0x10);
        POKE_PERSONAL_Delete((void *)h);
    }
    if (egg != 0) {
        *outFlag = 1;
    } else if (flag != 0) {
        *outFlag = 1;
    } else {
        *outFlag = 0;
    }
    if (id != func_02008530((const struct Sub0200852CObj *)key)) {
        *outSame = 0;
    } else {
        *outSame = 1;
    }
}
