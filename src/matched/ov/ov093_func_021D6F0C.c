/*
 * function: func_021D6F0C
 * address:  0x021D6F0C
 * packet:   pkt_ov093_021D6F0C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   data_021F3CB0  0x021F3CB0  data
 *   func_021D7474  0x021D7474  thumb  ov093
 *   func_021D6F08  0x021D6F08  thumb  ov093
 *   MI_CpuFill8    0x02082BCC  arm
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
extern struct Node *func_021D7474(void);
extern void func_021D6F08(void);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
struct Node *func_021D6F0C(int id, u16 key, int pri, u32 sub_pri, u8 sub, u32 f8, u16 f16)
{
    struct Node *n = func_021D7474();
    struct Node *cur;
    struct Node *prev;
    int f;

    if (n != 0) {
        n->prio = ((7 - pri) << 24) | sub_pri;
        n->id = id;
        n->prev = 0;
        n->next = 0;
        n->f8 = f8;
        n->f16 = f16;
        n->key = key;
        n->b24 = 0;
        n->mark = 0;
        n->b30 = 0;
        n->b26 = 0;
        n->fC = 0;
        n->sub = sub;
        n->busy = 0;
        n->b28 = 0;
        n->serial = data_021F3CB0.serial;
        n->b29 = 1;
        f = 0;
        if (id == 0 || id == 4 || id == 5) f = 1;
        n->kind = f ? sub : 0x1F;
        MI_CpuFill8(n->f1C, 0, sizeof(n->f1C));

        prev = data_021F3CB0.head;
        if (prev == 0) {
            data_021F3CB0.head = n;
        } else if (n->prio > prev->prio) {
            prev->prev = n;
            n->next = data_021F3CB0.head;
            n->prev = 0;
            data_021F3CB0.head = n;
        } else {
            for (cur = prev->next; cur != 0; prev = cur, cur = cur->next) {
                if (n->prio > cur->prio) {
                    n->next = cur;
                    n->prev = cur->prev;
                    cur->prev->next = n;
                    cur->prev = n;
                    break;
                }
            }
            if (cur == 0) {
                prev->next = n;
                n->prev = prev;
            }
        }
        func_021D6F08();
        return n;
    }
    return 0;
}
