/*
 * function: DENDOU_SAVEDATA_GetMemberCount
 * address:  0x0200EC14
 * packet:   pkt_0200EA3C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * An unlabelled leaf: it saves nothing, so disasm.py's lr-saving prologue
 * sweep never fired and the bytes print as a run of `.word` in the listing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  Nothing in
 * the image branches to it either, so no `function_starts.txt` seed exists.
 * First zero halfword of six 0x3c-byte records.
 *
 * It is not an anonymous hole, though: MISC_SAVEDATA_GetRingRecordIndex (src/matched/
 * unit_0200EC98.c) tail-calls it through a pool word, which is why that file
 * could not resolve its one relocation until this entry existed -- the
 * `matched` class is the only witness 0x0200EC14 can ever have, since no
 * branch anywhere in the image names it and its address appears in exactly
 * one pool.
 */

typedef unsigned short u16;
typedef unsigned int u32;

int DENDOU_SAVEDATA_GetMemberCount(char *p)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (*(u16 *)(p + i * 0x3c) == 0)
            break;
    }
    return i;
}
