/*
 * function: func_021D7474
 * address:  0x021D7474
 * packet:   pkt_ov093_021D7474
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   data_021F3CB0  0x021F3CB0  data
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
struct Node *func_021D7474(void)
{
    u32 i;
    if (data_021F3CB0.used == 0x84) return 0;
    i = data_021F3CB0.used++;
    return data_021F3CB0.pool[i];
}
