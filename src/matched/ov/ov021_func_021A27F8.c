/*
 * function: func_021A27F8
 * address:  0x021A27F8
 * packet:   pkt_ov021_021A27F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct Node021A27F8 {
    u32 pad0;
    u32 handle;
    u8 pad8[0x28];
    struct Node021A27F8 *prev;
    struct Node021A27F8 *next;
} Node021A27F8;

typedef struct {
    u8 pad[0x48];
    void (*cb)(Node021A27F8 *n);
} Ops021A27F8;

typedef struct {
    u8 pad[0x20];
    Ops021A27F8 *ops;
    u8 pad24[0x750];
    Node021A27F8 *head;
} Obj021A27F8;

void func_021A27F8(Obj021A27F8 *p)
{
    Node021A27F8 *cur = p->head;
    Node021A27F8 *nx;

    if (cur != 0 && p->ops->cb != 0) {
        nx = cur->next;
        do {
            p->ops->cb(cur);
            cur = nx;
            nx = nx->next;
        } while (cur != p->head && p->head != 0);
    }
}
