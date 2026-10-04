/*
 * function: sub_02064B68
 * address:  0x02064B68
 * packet:   pkt_02064B68
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_020643C4  0x020643C4  arm
 *
 * PART 1 bank walker of docs/families/cluster_02064B68.h: publish `arg` at
 * +0x14, then step every record of the walk block at +0x34 (the same
 * struct Root func_02064934 takes) through sub_020643C4 -- kind 1 the flat
 * 0x5c-stride array for numCellAnims, else the 0x28-stride headers' first
 * word for numNodes.
 *
 * Two levers closed docs/notes/sub_02064B68.c.txt's last 11 bytes:
 *   - the index and base are PER-ARM locals (as in func_02064934);
 *   - the +0x14 store is written IN EACH ARM.  The front end hoists the
 *     common store above the branch but schedules it below the `cmp` and
 *     the index zero, which is the image; a single store before the `if`
 *     issues it above the `cmp` (11 out), and with it the volatile hdr
 *     the note needed is no longer necessary (the per-arm store is what
 *     keeps each arm's +0x34 load in its arm).
 * 1.1p1 gives 168 bytes / 24 out on the same C: pinned ../2.0/sp2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02064B68.c \
 *       --func sub_02064B68 --addr 0x02064B68 --arm --cc ../2.0/sp2
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct MultiCellAnim;
extern void sub_020643C4(struct MultiCellAnim *mca, u32 value);
struct MCD { u16 numNodes; u16 numCellAnims; void *nodes; };
struct Root { struct MCD *data; void *set; u32 kind; char *cells; };
struct Obj { u8 pad_00[0x14]; void *unk_14; u8 pad_18[0x1c]; struct Root root; };
void sub_02064B68(struct Obj *o, void *arg)
{
    if (o->root.kind == 1) {
        u16 i;
        char *cells = o->root.cells;
        o->unk_14 = arg;
        for (i = 0; i < o->root.data->numCellAnims; i++) sub_020643C4((struct MultiCellAnim *)(cells + i * 0x5c), (u32)arg);
    } else {
        u16 i;
        char *cells = o->root.cells;
        o->unk_14 = arg;
        for (i = 0; i < o->root.data->numNodes; i++) sub_020643C4(*(void **)(cells + i * 0x28), (u32)arg);
    }
}
