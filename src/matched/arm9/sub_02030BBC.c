/*
 * function: GFL_HEAP_AllocSystemChecked
 * address:  0x02030BBC
 * packet:   pkt_02030BBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_HEAP_AllocSystem  0x020305C4  arm
 *
 * A four-instruction tail call: `ldr ip, [pc]; bx ip; .word target`. The
 * target, 0x020305C4, is not itself a labelled function: it is the second
 * half of the 176-byte function at 0x02030534 (pkt_02030534, outside this
 * packet), reached only through this pool word and never by a branch, so
 * `disasm.py`'s prologue sweep never fires on it. See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md for the shape;
 * this is the same phenomenon one level up, a whole secondary entry point
 * rather than one accessor.
 *
 * Promoted from MATCH with no change to the C. The one relocation had no
 * witness under the honesty rule: the only reference to 0x020305C4
 * anywhere is this call, inside the range under test, and the address
 * carried no func_ label. It closed when 0x020305C4 was seeded into
 * layout/function_starts.txt and written as src/matched/GFL_HEAP_AllocSystem.c,
 * which makes the site `matched`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_HEAP_AllocSystemChecked.c \
 *       --func GFL_HEAP_AllocSystemChecked --addr 0x02030BBC --cc 1.1p1 --arm
 */

typedef unsigned int   u32;
extern void *GFL_HEAP_AllocSystem(u32 size);

void *GFL_HEAP_AllocSystemChecked(u32 a0)
{
    return GFL_HEAP_AllocSystem(a0);
}
