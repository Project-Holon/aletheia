/*
 * function: func_02069C14
 * address:  0x02069C14
 * packet:   pkt_020694D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Size of the payload described by (tag, node): dispatches on the tag byte
 * *tag (same 0x4D/0x4A/0x56 tag alphabet as func_02069E88 in the
 * neighbouring list module) and returns the node's element count scaled by
 * two, plus the 0x1C header, rounded down to a word. 0x4D counts from the
 * byte at +0x18, 0x4A and 0x56 share the byte at +0x17.
 */

typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Node {
    u8 unk00[0x17];
    u8 n17;
    u8 n18;
} Node;

u32 func_02069C14(const u8 *tag, const Node *n)
{
    if (tag == 0 || n == 0) return 0;
    switch (*tag) {
    case 0x4d:
        return ((n->n18 * 2) + 0x1c) & ~3;
    case 0x4a:
    case 0x56:
        return ((n->n17 * 2) + 0x1c) & ~3;
    }
    return 0;
}
