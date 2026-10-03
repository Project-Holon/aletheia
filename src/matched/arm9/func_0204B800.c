/*
 * function: func_0204B800
 * address:  0x0204B800
 * packet:   pkt_0204B764
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0204CA30  0x0204CA30  arm
 *   func_0204C98C  0x0204C98C  arm
 *
 * Field at +0x60 is an 8-bit bitfield in a whole word: the original is a
 * word load, and/bic/orr, word store, never a ldrb/strb.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Node {
    u8   pad_000[8];
    void *unk_008;
    u8   pad_00c[0x60 - 0x0c];
    u32  unk_060 : 8;
};

struct Mgr;
extern void func_0204CA30(struct Mgr *m, struct Node *l);
extern void func_0204C98C(void *p, struct Node *node);

void func_0204B800(struct Node *node, u32 val)
{
    node->unk_060 = val;
    func_0204CA30(node->unk_008, node);
    func_0204C98C(node->unk_008, node);
}
