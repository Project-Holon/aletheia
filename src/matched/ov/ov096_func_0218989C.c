/*
 * function: func_0218989C
 * address: 0x0218989C
 * packet: pkt_ov096_0218989C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Caller-visible return/second arguments override tail-forwarder declarations.
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   func_0218A160 0x0218A160 thumb ov096
 *   func_0218A2FC 0x0218A2FC thumb ov096
 *   func_0218A308 0x0218A308 thumb ov096
 *   func_0218A0F4 0x0218A0F4 thumb ov096
 *   BTL_MAIN_GetSlotClientIdThunk 0x021B8DE4 thumb ov093
 *   BTL_SIDE_GetSlotOfClientThunk 0x021B9AF8 thumb ov093
 *   BTL_MAIN_GetPositionsPerClientThunk 0x021B99B8 thumb ov093
 *   BTL_SLOT_GetCount 0x021B9B94 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_POKEPARAM_GetMoveCount 0x021D5448 thumb ov093
 *   BTL_POKEPARAM_GetMovePPLost 0x021D554C thumb ov093
 */
#include "../include/Obj07926.h"
typedef unsigned char u8;
struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *p);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
typedef unsigned int   u32;
extern u8 *func_0218A308(void *p, u32 i);
struct QG;
extern int func_0218A0F4(u8 *a, int op, int x, int y, int z);
extern u8 BTL_MAIN_GetSlotClientIdThunk(char *p, int i);
extern char *BTL_SIDE_GetSlotOfClientThunk(char *p, int i);
extern int BTL_MAIN_GetPositionsPerClientThunk(void *pp, unsigned int b);
struct Q1;
extern u8 BTL_SLOT_GetCount(struct Q1 *p);
extern int BTL_POKEPARAM_IsFainted(void *);
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);
extern u8 BTL_POKEPARAM_GetMovePPLost(u8 *p, u8 i);
int func_0218989C(struct Cursor *a, int b)
{
    int x, z, n;
    char *p;
    int i, j;
    u8 y;
    x = VM_GetU32(a);
    z = VM_GetU32(a);
    y = func_0218A160((u8 *)b, x);
    n = BTL_MAIN_GetSlotClientIdThunk((char *)(((struct Obj07926 *)b)->fB0), y);
    p = BTL_SIDE_GetSlotOfClientThunk(*(char * *)&((struct Obj07926 *)b)->fB8, n);
    i = BTL_MAIN_GetPositionsPerClientThunk((void *)(((struct Obj07926 *)b)->fB0), n);
    for (; i < BTL_SLOT_GetCount((struct Q1 *)p); i++) {
        if (BTL_POKEPARAM_IsFainted(func_0218A308(p, (u8)i)) == 0) {
            for (j = 0; j < BTL_POKEPARAM_GetMoveCount((struct QG *)func_0218A2FC((u8 *)b, y)); j++) {
                if (func_0218A0F4((u8 *)a, 3, BTL_POKEPARAM_GetMovePPLost(func_0218A2FC((u8 *)b, y), j), 0, z) != 0)
                    break;
            }
            if (j != BTL_POKEPARAM_GetMoveCount((struct QG *)func_0218A2FC((u8 *)b, y)))
                break;
        }
    }
    return ((struct Obj07926 *)b)->fC4;
}
