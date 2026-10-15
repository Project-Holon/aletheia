/*
 * function: POKE_REGULATION_BuildLevelLine
 * address:  0x0201A3F4
 * packet:   pkt_0201A3F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WORDSET_SetSlotNumber   0x0201EFA4  thumb
 *   STRBUF_Create   0x020457B0  arm
 *   MSGDATA_ReadString   0x02045CAC  arm
 *   WORDSET_CopyTaggedText   0x0201F250  thumb
 *
 * poke_tool.c tail (wave 13), the twin of POKE_REGULATION_BuildPartySizeLine: pick the sprite
 * record's mode from the format byte at a0+5 (0 -> 6, 4 -> 0xb, 1 -> 0xd,
 * 2 -> 0xc, 3 -> 0xe, 5 -> 0xf, anything else 6; an if chain in that order,
 * the image tests it in source order), stamp the byte at a0+4 through
 * WORDSET_SetSlotNumber, allocate the 0x40-byte record against a4, fill it from *a2
 * and bind it with WORDSET_CopyTaggedText.
 *
 * WHAT CLOSED IT (docs/notes/pkt_0201A3F4.c.txt: 8 bytes out, the byte at
 * a0+4 loaded after the two outgoing stack stores instead of before): the
 * record parameter is `const u8 *`.  A load through a const pointer may move
 * above the stores to the outgoing-argument area; through a plain pointer it
 * may not.  Same lever as PARTICLE_CreateSystem and BUTTON_MAN_SetEmitterPos this wave.
 *
 * EXACT* because the follower at 0x0201A468 (a leaf that scans 0x52 bytes
 * from +0xa and tail-calls 0x02045EC0) carries no label.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct MsgBank;
struct WordSet;
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);

void *POKE_REGULATION_BuildLevelLine(const u8 *a0, u32 a1, u32 *a2, u32 a3, u16 a4)
{
    u32 mode;
    void *p;

    if (a0[5] == 0) {
        mode = 6;
    } else if (a0[5] == 4) {
        mode = 0xb;
    } else if (a0[5] == 1) {
        mode = 0xd;
    } else if (a0[5] == 2) {
        mode = 0xc;
    } else if (a0[5] == 3) {
        mode = 0xe;
    } else if (a0[5] == 5) {
        mode = 0xf;
    } else {
        mode = 6;
    }
    WORDSET_SetSlotNumber((struct WordSet *)a1, 0, a0[4], 3, 0, 1);
    p = STRBUF_Create(0x40, a4);
    MSGDATA_ReadString((struct MsgBank *)(*a2), mode, (void *)a3);
    WORDSET_CopyTaggedText((struct WordSet *)a1, p, (void *)a3);
    return p;
}
