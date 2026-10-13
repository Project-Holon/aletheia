/*
 * function: HAND_WAZA_CanAddMoveHandler
 * address:  0x021E0354
 * packet:   pkt_ov093_021E0354
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_FindFactor  0x021D732C  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_EVENT_FindNextFactor  0x021D7360  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;
struct Node {
    struct Node *prev;
    struct Node *next;
    u32 f8;
    u32 fC;
    int id;
    u32 prio;
    u32 serial : 16;
    u32 f16 : 8;
    u32 b24 : 1;
    u32 mark : 1;
    u32 b26 : 1;
    u32 busy : 1;
    u32 b28 : 1;
    u32 b29 : 1;
    u32 b30 : 1;
    u32 b31 : 1;
    u8 f1C[0x1C];
    u16 key;
    u8 sub;
    u8 kind;
};
struct NodeList { u32 serial; struct Node *head; u32 used; struct Node *pool[0x84]; };
extern struct NodeList data_021F3CB0;
extern struct Node *BTL_EVENT_FindFactor(int id, int sub);
struct QQ;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern struct Node *BTL_EVENT_FindNextFactor(struct Node *n);
int HAND_WAZA_CanAddMoveHandler(int sub, int key, u8 *found)
{
    struct Node *n;
    u32 i = 0;
    for (n = BTL_EVENT_FindFactor(0, sub); n != 0; n = BTL_EVENT_FindNextFactor(n)) {
        if (key == BTL_EVENT_GetFactorKey((struct QQ *)n)) {
            *found = 1;
            return 0;
        }
        if (++i > 8) return 0;
    }
    return 1;
}
