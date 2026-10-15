/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0200E918
 * packet:   pkt_0200E684
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: MISC_SAVEDATA_GetKeyByte, MISC_SAVEDATA_AddKeyByte
 *
 * alias: a byte array at offset 6 of some base object, indexed by the second
 * parameter.  MISC_SAVEDATA_GetKeyByte is the plain getter; MISC_SAVEDATA_AddKeyByte adds a signed
 * delta to one element and clamps the result to 0..255 before storing it
 * back.  MISC_SAVEDATA_GetKeyByte has no register-saving prologue (two instructions, no
 * push), so disasm.py's sweep never labelled it; it sits in the listing as a
 * .word between two functions.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200E918.c \
 *       --addr 0x0200E918 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

u8 MISC_SAVEDATA_GetKeyByte(const u8 *base, u32 idx)
{
    return (base + idx)[6];
}

void MISC_SAVEDATA_AddKeyByte(u8 *base, u32 idx, int delta)
{
    u8 *p = base + 6;
    int v = p[idx] + delta;

    if (v > 0xff) {
        v = 0xff;
    } else if (v < 0) {
        v = 0;
    }
    p[idx] = (u8)v;
}
