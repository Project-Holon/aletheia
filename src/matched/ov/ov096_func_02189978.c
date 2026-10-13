/*
 * function: TR_AI_CmdLoadItemFieldNoSick19
 * address:  0x02189978
 * packet:   pkt_ov096_02189978
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   TR_AI_GetPosition  0x0218A160  thumb  ov096
 *   TR_AI_GetPoke  0x0218A2FC  thumb  ov096
 *   TR_AI_GetItemField  0x0218A3F4  thumb  ov096
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 */
#include "../include/Obj10187.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern u8 TR_AI_GetPosition(u8 *p, int k);
extern u8 *TR_AI_GetPoke(u8 *p, u8 i);
struct Unk021D62A8;
extern int TR_AI_GetItemField(int a, int b, int c);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
struct QI;
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);

int TR_AI_CmdLoadItemFieldNoSick19(struct Cursor *a, int b) {
    int r;
    u8 t;
    int s;
    r = VM_GetU32(a);
    t = TR_AI_GetPosition((u8 *)b, r);
    ((struct Obj10187 *)b)->f38 = 0;
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)TR_AI_GetPoke((u8 *)b, t), 0x13) == 0) {
        s = BTL_POKEPARAM_GetItem((struct QI *)TR_AI_GetPoke((u8 *)b, t));
        ((struct Obj10187 *)b)->f38 = TR_AI_GetItemField(b, (u16)s, 10);
    }
    return ((struct Obj10187 *)b)->fC4;
}
