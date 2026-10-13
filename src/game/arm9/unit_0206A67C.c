/*
 * file:     unit_0206A67C.c
 * function: func_0206A67C
 * address:  0x0206A67C
 * packet:   pkt_0206A67C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The unlabelled follower of src/matched/func_0206A5B4.c, and the bulk form
 * of that function's per-entry work: resolve the same cell table out of the
 * header chain and walk every entry, clearing the done bit (flags bit 0 at
 * +3) on each.  It shares 0x0206A5B4's Ent layout and its
 * base/entry resolution exactly.
 *
 * NOT pinned, despite the parent carrying ../2.0/sp2.  One probe under
 * `--cc ../2.0/sp2` was run and measured 128 bytes / 63 concrete out, the
 * same shortfall as 1.1p1's 128 / 64: the front end is not the difference
 * here and the whole 4-byte gap is in the C.  Three levers close it, all
 * under the default 1.1p1:
 *
 *   1. The entry test is written against the counter (`e1->count <= i`,
 *      both unsigned), not against zero.  `count == 0` and `count <= 0`
 *      both give `bxeq lr`; only the comparison with the unsigned counter
 *      gives the image's `bxls lr` at +0028.
 *   2. The in-loop bound must be re-read.  Written plainly, the compiler
 *      forwards the r0 it already loaded for the entry test and drops the
 *      `ldrb r0, [r3, #1]` at +0038, which is the whole 4-byte shortfall;
 *      reading it through `volatile` restores the fresh load.
 *   3. The clear is masked at full width: `(u8)(flags & ~1u)` gives the
 *      image's `bicne r0, r0, #1` at +006C, where the narrow `flags &= ~1`
 *      folds to `andne r0, r0, #0xfe`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206A67C.c \
 *       --func func_0206A67C --addr 0x0206A67C --cc 1.1p1 --arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

/* Resource dictionary header (NNSG3dResDict shape). */
typedef struct {
    u8  revision;
    u8  numEntry;
    u16 sizeDictBlk;
    u16 dummy;
    u16 ofsEntry;
} ResDictHeader;

/* Prefix of one dictionary data record: the done bit is bit 0 of byte 3. */
typedef struct {
    u8 unused00[3];
    u8 flags;
} ResDictData;

/* Prefix of a resource file header: the offset of the first block at +8. */
typedef struct {
    u8  unused00[8];
    u32 ofsBlock;
} ResFilePrefix;

/* Prefix of the data block: the offset of the dictionary at +2. */
typedef struct {
    u8  unused00[2];
    u16 ofsDict;
} ResBlockPrefix;

void func_0206A67C(char *pRes)
{
    char          *pBlock;
    ResDictHeader *pDict;
    u32            entryIdx;

    pBlock = (pRes != 0 && ((ResFilePrefix *)pRes)->ofsBlock != 0) ? pRes + ((ResFilePrefix *)pRes)->ofsBlock : 0;
    pDict = (ResDictHeader *)(pBlock + ((ResBlockPrefix *)pBlock)->ofsDict);

    entryIdx = 0;
    if (pDict->numEntry <= entryIdx)
        return;

    do {
        ResDictData *pData;
        if (pDict != 0 && entryIdx < *(volatile u8 *)&pDict->numEntry) {
            u16 ofsEntry = pDict->ofsEntry;
            u16 sizeUnit = *(u16 *)((char *)pDict + ofsEntry);
            pData = (ResDictData *)((char *)pDict + ofsEntry + 4 + sizeUnit * entryIdx);
        } else {
            pData = 0;
        }
        entryIdx++;
        if (pData->flags & 1) {
            pData->flags = (u8)(pData->flags & ~1u);
        }
    } while (entryIdx < pDict->numEntry);
}
