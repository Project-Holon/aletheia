/*
 * unit: yes
 * function: BTL_HANDLER_ITEM_PushRecoverPp, BTL_HANDLER_ITEM_AddOranBerry
 * address: 0x021DD39C
 * packet: pkt_ov093_021DD39C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   BTL_HANDLER_ITEM_FindLastMoveEmptySlot 0x021DD338 thumb ov093
 *   BTL_HANDLER_ITEM_FindEmptyMoveSlot 0x021DD368 thumb ov093
 *   BTL_POKEPARAM_GetMoveCount 0x021D5448 thumb ov093
 *   BTL_POKEPARAM_GetMovePPLost 0x021D554C thumb ov093
 *   BTL_POKEPARAM_GetMoveId 0x021D54C0 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   BTL_EVENT_GetFactorKey 0x021D70A8 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   gHandlerTableOranBerry 0x021F1BB4 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct QG;
struct QQ;
extern void *func_021C7CF4(int *p, int i);
extern u8 BTL_HANDLER_ITEM_FindLastMoveEmptySlot(void *a, int b);
extern u8 BTL_HANDLER_ITEM_FindEmptyMoveSlot(void *a, int b);
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);
extern u8 BTL_POKEPARAM_GetMovePPLost(u8 *p, u8 i);
extern u16 BTL_POKEPARAM_GetMoveId(u8 *p, int i);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void func_021C88C8(void *a, void *b);
int BTL_HANDLER_ITEM_PushRecoverPp(int a, void *b, u8 c, int d, int e)
{
    void *m;
    u32 i;
    u32 n;
    u8 slot;
    u8 *r;
    m = func_021C7CF4(b, c);
    slot = BTL_HANDLER_ITEM_FindLastMoveEmptySlot(b, c);
    if (slot == 4) {
        slot = BTL_HANDLER_ITEM_FindEmptyMoveSlot(b, c);
        if (slot == 4 && e) {
            n = BTL_POKEPARAM_GetMoveCount(m);
            for (i = 0; i < n; i++) {
                if (BTL_POKEPARAM_GetMovePPLost(m, i)) {
                    slot = i;
                    break;
                }
            }
        }
    }
    if (slot != 4) {
        r = (u8 *)func_021C88A4(b, 9, c);
        r[4] = 10;
        r[5] = c;
        r[6] = slot;
        r[7] = (r[7] & ~1) | 1;
        func_021C8838(r + 8, 2, 0x38f);
        func_021C8860((struct S *)(r + 8), c);
        func_021C8860((struct S *)(r + 8), BTL_EVENT_GetFactorKey((void *)a));
        func_021C8860((struct S *)(r + 8), BTL_POKEPARAM_GetMoveId(m, slot));
        func_021C88C8(b, r);
        return 1;
    }
    return 0;
}
extern u8 gHandlerTableOranBerry[];
void *BTL_HANDLER_ITEM_AddOranBerry(int *p) { *p = 5; return gHandlerTableOranBerry; }
