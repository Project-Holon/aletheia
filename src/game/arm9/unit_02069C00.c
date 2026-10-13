/*
 * file:     unit_02069C00.c
 * unit:     yes
 * function: NNSi_G2dReadCharUTF16, GetTaggedPayloadSize
 * address:  0x02069C00
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct CharCursor {
    u8 *pCur;
    signed char pad_04;
    unsigned char pad_05;
} CharCursor;

typedef struct TaggedNode {
    u8 pad_00[0x17];
    u8 entryCount;
    u8 entryCountM;
} TaggedNode;

u16 NNSi_G2dReadCharUTF16(CharCursor *cursor);
u32 GetTaggedPayloadSize(const u8 *tag, const TaggedNode *node);


/*
 * The halfword post-increment reader over the bit reader's byte cursor
 * (+0x00), the unlabelled leaf after func_02069BA0 (seeded start).  The
 * cursor must be read into a typed u16 pointer and post-incremented; the
 * u8-pointer spelling `p = b->cur; b->cur = p + 2; return *(u16 *)p;`
 * schedules the store before the load (7 bytes).
 */
u16 NNSi_G2dReadCharUTF16(CharCursor *cursor)
{
    u16 *p = (u16 *)cursor->pCur;
    u16 v = *p++;
    cursor->pCur = (u8 *)p;
    return v;
}


/*
 * Size of the payload described by (tag, node): dispatches on the tag byte
 * *tag (same 0x4D/0x4A/0x56 tag alphabet as func_02069E88 in the
 * neighbouring list module) and returns the node's element count scaled by
 * two, plus the 0x1C header, rounded down to a word. 0x4D counts from the
 * byte at +0x18, 0x4A and 0x56 share the byte at +0x17.
 */
u32 GetTaggedPayloadSize(const u8 *tag, const TaggedNode *node)
{
    if (tag == 0 || node == 0) return 0;
    switch (*tag) {
    case 0x4d:
        return ((node->entryCountM * 2) + 0x1c) & ~3;
    case 0x4a:
    case 0x56:
        return ((node->entryCount * 2) + 0x1c) & ~3;
    }
    return 0;
}
