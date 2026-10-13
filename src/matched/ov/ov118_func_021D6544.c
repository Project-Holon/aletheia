/*
 * function: func_021D6544
 * address:  0x021D6544
 * packet:   pkt_ov118_021D6544
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D8AA8  0x021D8AA8  thumb  ov119
 *   func_021D8FA4  0x021D8FA4  thumb  ov119
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_PERSONAL_Create  0x0201ADE4  thumb
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb
 *   POKE_PERSONAL_Delete  0x0201AE14  thumb
 *   func_02008530  0x02008530  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj22681.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern int func_021D8AA8(void *p);
extern void *func_021D8FA4(void *p, int which);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 arg);
extern void *POKE_PERSONAL_Create(unsigned int a, int b, unsigned int heap);
struct Personal;
struct Sub0200852CObj;
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void POKE_PERSONAL_Delete(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);

void func_021D6544(u8 *p, u8 *outSame, u8 *outFlag, u32 key, int enemy)
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
        if (func_021D8AA8(p) != 0) {
            which = 1;
        } else {
            which = 0;
        }
    } else {
        if (func_021D8AA8(p) != 0) {
            which = 0;
        } else {
            which = 1;
        }
    }
    mon = func_021D8FA4(p, which);
    id = POKE_TOOL_GetPartyValue(mon, 7, 0);
    a = POKE_TOOL_GetPartyValue(mon, 0xAB, 0);
    b = POKE_TOOL_GetPartyValue(mon, 0x6F, 0);
    egg = POKE_TOOL_GetPartyValue(mon, 0x4C, 0);
    if (egg == 0) {
        h = (u32)POKE_PERSONAL_Create((u16)a, (u16)b, ((struct Obj22681 *)p)->f5F4);
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
