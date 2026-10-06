/*
 * function: func_0204C98C
 * address:  0x0204C98C
 * packet:   pkt_0204C944
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0204B838  0x0204B838  arm
 *   func_0204CA74  0x0204CA74  arm
 *   func_0204CAAC  0x0204CAAC  arm
 *
 * Sorted insert into a circular doubly-linked list whose head pointer sits
 * at a0+4 and whose links are {next @0, prev @4}.  The empty list seeds a
 * self-loop; a first key below the head's key goes in front of the tail;
 * otherwise the average of the head and tail keys picks the half to search
 * and func_0204CA74/func_0204CAAC return the node to insert after.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204C98C.c \
 *       --func func_0204C98C --addr 0x0204C98C --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct Node0204C98C Node0204C98C;

struct Node0204C98C {
    Node0204C98C *next;
    Node0204C98C *prev;
};

typedef struct {
    u32            unk00;
    Node0204C98C  *head;
} List0204C98C;

extern int func_0204B838(int a0);
struct Node;
extern void *func_0204CA74(struct Node *head, u32 key);
extern struct Node *func_0204CAAC(struct Node *head, u32 key);

void func_0204C98C(List0204C98C *a0, Node0204C98C *a1)
{
    Node0204C98C *pos;

    if (a0->head == 0) {
        a0->head = a1;
        a1->next = a1;
        a0->head->prev = a1;
        return;
    }
    {
        u32 key = func_0204B838((int)a1);
        u32 headkey = func_0204B838((int)a0->head);
        u32 tailkey;
        u8  avg;

        if (key < headkey) {
            pos = a0->head->prev;
            a0->head = a1;
        } else {
            tailkey = func_0204B838((int)a0->head->prev);
            avg = (u8)((int)(headkey + tailkey) / 2);
            if (avg >= key) {
                pos = func_0204CA74((struct Node *)a0->head, key);
            } else {
                pos = (Node0204C98C *)func_0204CAAC((struct Node *)a0->head->prev, key);
            }
        }
    }
    a1->prev = pos;
    a1->next = pos->next;
    pos->next->prev = a1;
    pos->next = a1;
}
