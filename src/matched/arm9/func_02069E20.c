/*
 * function: NNSi_G3dAnmObjCollectMapDataMask
 * address:  0x02069E20
 * packet:   pkt_02069D68
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Per-file compiler pin, "kept branches" tell (docs/FRONTEND-PINS.md).
 * The original keeps `tst r2,#0x100` / `beq` over a five-instruction guard
 * body at 0x02069E60..0x02069E74; dsi/1.1p1 -O4,p always predicates a guard
 * block of five instructions or fewer (docs/idioms/an-arm-guard-block-of-
 * five-instructions-or-fewer-is-predicated.md) and emits asrne/andne/ldrne/
 * orrne/strne for 100 bytes against the original's 104. No C spelling under
 * the pinned front end can restore the branch; ../2.0/sp2 keeps it, giving
 * 104 bytes and 0 mismatches. Evidence and the ruled-out spellings are in
 * docs/notes/NNSi_G3dAnmObjCollectMapDataMask.c.txt.
 *
 * Walk the linked list from `n`, and for each entry set bit i of `mask`
 * for every tab1A[i] (i < cnt19) whose 0x100 flag is set.
 */

typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct Node {
    u8 unk00[0x10];
    struct Node *next;
    u8 unk14[5];
    u8 cnt19;
    u16 tab1A[1];
} Node;

void NNSi_G3dAnmObjCollectMapDataMask(u32 *mask, Node *n)
{
    s32 i;

    if (n == 0) return;
    do {
        for (i = 0; i < (s32)n->cnt19; i++) {
            if (n->tab1A[i] & 0x100) {
                mask[i >> 5] |= 1 << (i & 0x1f);
            }
        }
        n = n->next;
    } while (n != 0);
}
