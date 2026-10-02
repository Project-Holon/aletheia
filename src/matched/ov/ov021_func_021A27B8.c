/*
 * function: func_021A27B8
 * address:  0x021A27B8
 * packet:   pkt_ov021_021A27B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3DC  0x0204B3DC  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct Node021A27B8 {
    u32 pad0;
    u32 handle;
    u8 pad8[0x28];
    struct Node021A27B8 *prev;
    struct Node021A27B8 *next;
} Node021A27B8;

typedef struct {
    u8 pad[0x774];
    Node021A27B8 *head;
    int count;
} Obj021A27B8;

void func_021A27B8(Obj021A27B8 *p, Node021A27B8 *n)
{
    p->count--;
    if (p->head == n) {
        if (n->next == n)
            p->head = 0;
        else
            p->head = n->next;
    }
    n->next->prev = n->prev;
    n->prev->next = n->next;
    n->next = 0;
    n->prev = 0;
    func_0204B3DC(n->handle, 0);
}
