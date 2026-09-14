/*
 * unit:     no
 * function: sub_0202DCC4
 * address:  0x0202DCC4
 * packet:   pkt_0202DBC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads one bit out of the i-th record of the 0x28-byte array the object
 * holds a pointer to at offset 0xC. No prologue, so no label.
 *
 * The record stride is what the two instructions `movs r0, #0x28` /
 * `muls` say and nothing else: a stride the compiler can reach with a
 * shift becomes `lsls`, so the struct has to be exactly 40 bytes wide and
 * declaring it 32 costs five instructions. The `lsls #0x1F` / `lsrs #0x1F`
 * pair is a one-bit unsigned bitfield at bit 0 of the word at 0x18
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202DCC4.c \
 *       --func sub_0202DCC4 --addr 0x0202DCC4 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Rec0202DCC4 {
    u8  pad[0x18];
    u32 unk18_0 : 1;
    u32 unk18_1 : 31;
    u8  tail[0xC];
};

struct Obj0202DCC4 {
    u8 pad[0xC];
    struct Rec0202DCC4 *unk0C;
};

u32 sub_0202DCC4(const struct Obj0202DCC4 *p, u32 i)
{
    return p->unk0C[i].unk18_0;
}
