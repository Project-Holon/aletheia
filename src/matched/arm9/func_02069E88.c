/*
 * function: NNS_G3dRenderObjAddAnmObj
 * address:  0x02069E88
 * packet:   pkt_02069D68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_G3dAnmObjCollectMapDataMask    0x02069E20  arm
 *   NNSi_G3dAnmObjInsertByPriority    0x02069D68  arm
 *
 * 2026-09-21: unblocked. 128 bytes, zero mismatches, and now 6 of 6
 * relocation sites resolved: the three calls to 0x02069E20 take the
 * `matched` class from src/matched/NNSi_G3dAnmObjCollectMapDataMask.c, filed EXACT under the
 * per-file pin `compiler: ../2.0/sp2` (the "kept branches" tell, see
 * docs/FRONTEND-PINS.md and docs/notes/NNSi_G3dAnmObjCollectMapDataMask.c.txt). This file
 * itself stays on the pinned default 1.1p1; only its callee is pinned.
 *
 * Dispatches on the tag byte at *(item->tag08): 0x4D, 0x4A and 0x56 each
 * pair one mask-collect call with one priority insert, into the owner's
 * (+0x3C,+0x08), (+0x44,+0x10) and (+0x4C,+0x18) slots respectively. The
 * case ORDER in the source is 0x4D, 0x4A, 0x56 (the emitted compare chain
 * tests 0x4A first because the compiler reorders the tests, not the arms).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/NNS_G3dRenderObjAddAnmObj.c \
 *       --func NNS_G3dRenderObjAddAnmObj --addr 0x02069E88 --cc 1.1p1 --arm
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Node { u8 unk00[8]; u8 *tag08; u8 unk0C[4]; struct Node *next; } Node;

typedef struct {
    u32 flags00;
    u32 pad04;
    Node *l08;
    u32 pad0C;
    Node *l10;
    u32 pad14;
    Node *l18;
    u8  pad1C[0x20];
    u32 m3C;
    u32 pad40;
    u32 m44;
    u32 pad48;
    u32 m4C;
} Owner;

extern void NNSi_G3dAnmObjCollectMapDataMask(u32 *mask, Node *n);
extern void NNSi_G3dAnmObjInsertByPriority(Node **head, Node *item);

void NNS_G3dRenderObjAddAnmObj(Owner *o, Node *item)
{
    u8 *tag;

    if (item == 0) return;
    tag = item->tag08;
    if (tag == 0) return;
    switch (*tag) {
    case 0x4d:
        NNSi_G3dAnmObjCollectMapDataMask(&o->m3C, item);
        NNSi_G3dAnmObjInsertByPriority(&o->l08, item);
        break;
    case 0x4a:
        NNSi_G3dAnmObjCollectMapDataMask(&o->m44, item);
        NNSi_G3dAnmObjInsertByPriority(&o->l10, item);
        break;
    case 0x56:
        NNSi_G3dAnmObjCollectMapDataMask(&o->m4C, item);
        NNSi_G3dAnmObjInsertByPriority(&o->l18, item);
        break;
    }
}
