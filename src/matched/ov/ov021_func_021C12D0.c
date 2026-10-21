/*
 * function: FIELD_PLAYER_GRID_EVENT_DeleteJumpTask
 * address:  0x021C12D0
 * packet:   pkt_ov021_021C12D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Frees the resource buffer, then releases the handle.
 *
 * symbols:
 *   TCBL_GetOwnedWork  0x02030EE8  arm  arm9
 */

typedef unsigned int   u32;
struct S02030EE8;
extern u32 TCBL_GetOwnedWork(struct S02030EE8 *p);
extern u32 func_020307B0(void *p);
struct Node;
extern void func_02030EAC(struct Node *n);

void FIELD_PLAYER_GRID_EVENT_DeleteJumpTask(void *h)
{
    func_020307B0((void *)TCBL_GetOwnedWork(h));
    func_02030EAC(h);
}
