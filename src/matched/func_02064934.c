/*
 * function: func_02064934
 * address:  0x02064934
 * packet:   pkt_020640DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02064364  0x02064364  arm
 *
 * Step every node of the multi-cell walk block (struct Root of
 * docs/families/cluster_020640DC.h) by `arg` ticks: kind == 1 walks the
 * flat 0x5c-stride array for data->numCellAnims, anything else the
 * 0x28-stride group headers' first word for data->numNodes.
 *
 * The lever that closed the note's last 4 bytes (two head loads swapped,
 * docs/notes/func_02064934.c.txt): declare the index and the array base
 * INSIDE EACH ARM.  A function-scope `u16 i = 0; char *base = p->f0c;`
 * issues the base load before the data-pointer load; per-arm locals let
 * the front end hoist the arms' common data-pointer load first, which is
 * the image.  No dead local needed.  Identical bytes under dsi/1.1p1 and
 * ../2.0/sp2 (not a pin).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02064934.c \
 *       --func func_02064934 --addr 0x02064934 --arm --cc 1.1p1
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02064364(void *anim, int arg);
struct MCD { u16 numNodes; u16 numCellAnims; void *nodes; };
struct Root { struct MCD *data; void *set; u32 kind; char *cells; };
void func_02064934(struct Root *p, int arg)
{
    if (p->kind == 1) {
        u16 i;
        char *cells = p->cells;
        for (i = 0; i < p->data->numCellAnims; i++) func_02064364(cells + i * 0x5c, arg);
    } else {
        u16 i;
        char *cells = p->cells;
        for (i = 0; i < p->data->numNodes; i++) func_02064364(*(void **)(cells + i * 0x28), arg);
    }
}
