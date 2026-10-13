/*
 * function: NNSi_G3dAnmObjInsertByPriority
 * address:  0x02069D68
 * packet:   pkt_02069D68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Priority-ordered insert into the singly-linked list rooted at *head. The
 * list links through +0x10 and orders on the unsigned byte at +0x18, highest
 * first; `item` may itself already be a chain, so before splicing it in the
 * code walks to its own tail and attaches the displaced remainder there.
 *
 * Three shape notes:
 *  - The one-element case (*head has no next) is written out separately from
 *    the general search; that is what produces the `bne`/`beq` pair on one
 *    `cmp r2,#0` at +0x18 and +0x60, where the second branch re-uses the
 *    flags the first one set.
 *  - The search loop is TOP-TESTED (`while (nx != 0)` with the priority test
 *    inside). Rotating it into `while (nx->pri18 >= ...)` with a NULL check at
 *    the bottom compiles to 188 bytes, four too many.
 *  - The insert guard is `nx->pri18 >= item->pri18`; the reverse polarity is
 *    a single wrong byte at +0x70 (`bhs` for `blo`), the only difference
 *    between the two spellings.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_G3dAnmObjInsertByPriority.c \
 *       --func NNSi_G3dAnmObjInsertByPriority --addr 0x02069D68 --cc 1.1p1 --arm
 */

typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Node {
    u8 unk00[0x10];
    struct Node *next;
    u8 unk14[4];
    u8 pri18;
} Node;

void NNSi_G3dAnmObjInsertByPriority(Node **head, Node *item)
{
    Node *cur;
    Node *nx;
    Node *tail;

    cur = *head;
    if (cur == 0) { *head = item; return; }
    nx = cur->next;
    if (nx == 0) {
        if (cur->pri18 > item->pri18) {
            tail = item;
            if (item->next != 0) {
                do {
                    tail = tail->next;
                } while (tail->next != 0);
            }
            tail->next = cur;
            *head = item;
            return;
        }
        cur->next = item;
        return;
    }
    while (nx != 0) {
        if (nx->pri18 >= item->pri18) {
            tail = item;
            if (item->next != 0) {
                do {
                    tail = tail->next;
                } while (tail->next != 0);
            }
            cur->next = item;
            tail->next = nx;
            return;
        }
        cur = nx;
        nx = nx->next;
    }
    cur->next = item;
}
