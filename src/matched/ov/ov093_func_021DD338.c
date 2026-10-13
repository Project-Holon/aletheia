/*
 * function: BTL_HANDLER_ITEM_FindLastMoveEmptySlot
 * address: 0x021DD338
 * packet: pkt_ov093_021DD338
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte alignment padding.
 * symbols:
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_GetLastSelectedMoveId 0x021D67B8 thumb ov093
 *   BTL_POKEPARAM_FindMoveSlot 0x021D5778 thumb ov093
 *   BTL_POKEPARAM_GetMovePPChecked 0x021D5584 thumb ov093
 * prototype: C7CF4 result used and r1 supplied; 5584 index is the u8 return of 5778.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct UtilWork;
extern void *func_021C7CF4(int *p, int i);
extern u16 BTL_POKEPARAM_GetLastSelectedMoveId(u8 *p);
extern u8 BTL_POKEPARAM_FindMoveSlot(struct UtilWork *p, u16 id);
extern u8 BTL_POKEPARAM_GetMovePPChecked(struct UtilWork *p, u32 i);
u8 BTL_HANDLER_ITEM_FindLastMoveEmptySlot(void *a, int b)
{
    void *m;
    u8 slot;
    m = func_021C7CF4(a, b);
    slot = BTL_POKEPARAM_FindMoveSlot(m, BTL_POKEPARAM_GetLastSelectedMoveId(m));
    if (slot != 4 && BTL_POKEPARAM_GetMovePPChecked(m, slot) == 0) return slot;
    return 4;
}
