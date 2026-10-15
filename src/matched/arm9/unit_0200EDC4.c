/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0200EDC4
 * packet:   pkt_0200ED54
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: MISC_SAVEDATA_ContainsRecentValue, MISC_SAVEDATA_TestBitmapBit, MISC_SAVEDATA_SetBitmapBit
 *
 * The three functions that follow MISC_SAVEDATA_InsertRecentValue (src/matched/
 * MISC_SAVEDATA_InsertRecentValue.c) inside this packet, none of which carries a label in
 * the generated listing: 0x0200EDC4 saves registers but not lr, and the
 * other two save nothing, so disasm.py's lr-saving prologue sweep never
 * fired on any of them and they print as runs of `.word` (docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md).  Nothing branches to
 * them either: the only references are the calls from the two functions
 * just past the end of the range.
 *
 * 0x0200EDC4, 40 bytes, is `contains` on the same 32-entry list
 * MISC_SAVEDATA_InsertRecentValue inserts into, and 0x0200EDEC / 0x0200EE14 are the
 * get-bit and set-bit pair of a 256-bit bitmap at +0x84 of the same
 * object, both written with a signed index (`/ 32` and `% 32`, which is
 * what the `asrs`/`rors` pair is).
 */

typedef unsigned int u32;

struct L0200EDC4 {
    u32 arr[32];
    u32 count;
};

int MISC_SAVEDATA_ContainsRecentValue(struct L0200EDC4 *l, u32 val)
{
    u32 i;

    for (i = 0; i < l->count; i++) {
        if (l->arr[i] == val)
            return 1;
    }
    return 0;
}

int MISC_SAVEDATA_TestBitmapBit(char *obj, int i)
{
    u32 *bits = (u32 *)(obj + 0x84);

    return (bits[i / 32] >> (i % 32)) & 1;
}

void MISC_SAVEDATA_SetBitmapBit(char *obj, int i)
{
    if (i >= 256)
        return;
    ((u32 *)(obj + 0x84))[i / 32] |= (u32)(1 << (i % 32));
}
