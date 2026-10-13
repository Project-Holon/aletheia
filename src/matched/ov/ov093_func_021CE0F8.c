/*
 * function: BTL_CLIENT_BuildActionPromptMessage
 * address:  0x021CE0F8
 * packet:   pkt_ov093_021CE0F8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetRule  0x021B8588  thumb  ov093
 *   func_021EAF18  0x021EAF18  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   func_021EAF50  0x021EAF50  thumb  ov093
 *   func_021EAF78  0x021EAF78  thumb  ov093
 */
#include "../include/Obj13355.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 BTL_MAIN_GetRule(void **p);
struct L;
extern void func_021EAF18(struct L *p, int kind, int id);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void func_021EAF50(struct L *p, u32 val);
extern void func_021EAF78(u8 *o, u8 v);

void BTL_CLIENT_BuildActionPromptMessage(u8 *p, u8 *q, u8 *o)
{
    if (BTL_MAIN_GetRule(*(void ** *)&((struct Obj13355 *)p)->f0) != 3) {
        func_021EAF18((struct L *)o, 1, 0x45);
        func_021EAF50((struct L *)o, BTL_POKEPARAM_GetPokeId(q));
        func_021EAF78(o, 0);
    } else {
        func_021EAF18((struct L *)o, 1, 0x46);
        func_021EAF50((struct L *)o, p[0x1a6]);
        func_021EAF78(o, 0);
    }
}
