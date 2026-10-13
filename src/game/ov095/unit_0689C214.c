/*
 * file:     unit_0689C214.c
 * function: func_0689C214
 * address: 0x0689C214
 * packet: pkt_ov095_0689C214
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent remainder: two-byte alignment padding at 0x0689C242.
 * symbols:
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb
 */
#include "../../matched/include/Obj13639.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_POKEPARAM_GetPokeId(void *);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(void *, int, int);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *, void *);
void func_0689C214(void *a, void *b)
{
    void *r;
    r = BTL_SERVER_FLOW_AllocCmdRecord(a, 0x21, BTL_POKEPARAM_GetPokeId(b));
    ((struct Obj13639 *)((u32)r))->f4 = BTL_POKEPARAM_GetPokeId(b);
    ((struct Obj13639 *)((u32)r))->f8 = 1;
    BTL_SERVER_FLOW_CommitCmdRecord(a, r);
}
