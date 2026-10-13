/*
 * function: TR_AI_ComparePartyMajorStatus
 * address:  0x02188FCC
 * packet:   pkt_ov096_02188FCC
 * region:   ov096
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   TR_AI_GetPosition  0x0218A160  thumb  ov096
 *   TR_AI_GetSlotPoke  0x0218A308  thumb  ov096
 *   TR_AI_Compare  0x0218A0F4  thumb  ov096
 *   BTL_MAIN_GetSlotClientIdThunk  0x021B8DE4  thumb  ov093
 *   BTL_MAIN_GetPositionsPerClientThunk  0x021B99B8  thumb  ov093
 *   BTL_SLOT_GetCount  0x021B9B94  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   ITEMMENU_FreeGraphics  0x021B9AF8  thumb  ov070
 */
#include "../include/Obj10180.h"

typedef unsigned char u8;
typedef unsigned int u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern u8 TR_AI_GetPosition(u8 *p, int k);
extern u8 BTL_MAIN_GetSlotClientIdThunk(char *p, int i);
extern char *ITEMMENU_FreeGraphics(char *p, int i);
extern int BTL_MAIN_GetPositionsPerClientThunk(void *pp, unsigned int b);
struct Q1;
extern u8 BTL_SLOT_GetCount(struct Q1 *p);
extern u8 *TR_AI_GetSlotPoke(void *, u32);
extern int BTL_POKEPARAM_IsFainted(void *);
struct Unk021D62A8;
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p);
extern int TR_AI_Compare(u8 *a, int op, int x, int y, int z);

void TR_AI_ComparePartyMajorStatus(struct Cursor *a, int b, int c)
{
    int t0;
    int t1;
    int n;
    char *handle;
    int i;

    t0 = VM_GetU32(a);
    t1 = VM_GetU32(a);
    n = BTL_MAIN_GetSlotClientIdThunk((char *)(((struct Obj10180 *)b)->fB0), TR_AI_GetPosition((u8 *)b, t0));
    handle = ITEMMENU_FreeGraphics(*(char * *)&((struct Obj10180 *)b)->fB8, n);
    for (i = BTL_MAIN_GetPositionsPerClientThunk((void *)(((struct Obj10180 *)b)->fB0), n);
         i < BTL_SLOT_GetCount((struct Q1 *)handle); i++) {
        u8 *t = TR_AI_GetSlotPoke(handle, (unsigned char)i);

        if (BTL_POKEPARAM_IsFainted(t) == 0) {
            if (TR_AI_Compare((u8 *)a, c, BTL_POKEPARAM_GetMajorStatusIndex((struct Unk021D62A8 *)t), 0, t1) != 0)
                break;
        }
    }
}
