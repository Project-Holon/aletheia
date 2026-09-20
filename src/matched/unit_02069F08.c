/*
 * unit:     yes
 * function: func_02069F08
 * address:  0x02069F08
 * packet:   pkt_02069D68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The list-removal pair, folded into one translation unit so that
 * func_02069F7C's three calls to func_02069F08 are `local` relocations
 * attested by the unit's own layout rather than by a separate manifest
 * entry.
 *
 * func_02069F08  unlinks `target` from the list rooted at *head (next at
 *                +0x10), returning 1 on success and clearing the removed
 *                node's own next pointer.
 * func_02069F7C  tries all three of the owner's lists (+0x08, +0x10, +0x18)
 *                in turn and sets bit 4 of the owner's word at +0x00 if any
 *                of them claimed the node.
 *
 * Two shape notes from the derivation:
 *  - In func_02069F08, `q` must be DECLARED BEFORE `p`; with the natural
 *    order the trailing cursor takes r0 instead of r2 and eleven bytes go
 *    wrong across the search loop. The inner unlink is `p->next = q->next`,
 *    not `p->next = target->next`, so the load comes off the cursor.
 *  - In func_02069F7C the three guards must NEST (each failure falling into
 *    the next attempt) so the three success paths share one tail; three
 *    separate early returns duplicate the flag store.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02069F08.c \
 *       --addr 0x02069F08 --arm
 */

typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Node {
    u8 unk00[0x10];
    struct Node *next;
} Node;

typedef struct {
    u32 flags00;
    u32 pad04;
    Node *l08;
    u32 pad0C;
    Node *l10;
    u32 pad14;
    Node *l18;
} Owner;

u32 func_02069F08(Node **head, Node *target)
{
    Node *q;
    Node *p;

    p = *head;
    if (p == 0) return 0;
    if (p == target) {
        *head = p->next;
        target->next = 0;
        return 1;
    }
    for (q = p->next; q != 0; q = q->next) {
        if (q == target) {
            p->next = q->next;
            q->next = 0;
            return 1;
        }
        p = q;
    }
    return 0;
}

void func_02069F7C(Owner *o, Node *item)
{
    if (!func_02069F08(&o->l08, item)) {
        if (!func_02069F08(&o->l10, item)) {
            if (!func_02069F08(&o->l18, item)) {
                return;
            }
        }
    }
    o->flags00 |= 0x10;
}
