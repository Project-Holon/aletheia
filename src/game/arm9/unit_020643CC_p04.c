/*
 * file:     unit_020643CC_p04.c
 * unit:     yes
 * function: func_020648B4, func_020648E0, func_02064934
 * address:  0x020648B4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02064648    0x02064648  arm
 *   func_020648E0    0x020648E0  arm
 *   func_020629E8   0x020629E8  arm
 *   func_02064364  0x02064364  arm
 */
struct MultiCellBank;
struct CellAnim;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct MultiCellData {
    u16 numNodes;
    u16 unk_02;
    u32 nodes;
};

struct MultiCellBank {
    u16 numMultiCell;
    u16 unk_02;
    struct MultiCellData *array;
};

typedef signed int     s32;

struct MCD { u16 numNodes; u16 numCellAnims; void *nodes; };

struct Root { struct MCD *data; void *set; u32 kind; char *cells; };

extern u16 func_02064648(struct MultiCellBank *bank);
extern u16 func_020648E0(struct MultiCellBank *bank);
extern struct MultiCellData *func_020629E8(struct MultiCellBank *bank, u32 idx);
extern void func_02064364(struct CellAnim *anim, s32 frames);
int func_020648B4(u32 a, u32 b);


int func_020648B4(u32 a, u32 b)
{
    u32 v;

    if (b == 1) {
        v = func_02064648((struct MultiCellBank *)a) * 0x5c;
    } else {
        v = func_020648E0((struct MultiCellBank *)a) << 7;
    }
    return v;
}



/*
 * Returns the largest node count among the multi-cell descriptors of the bank,
 * 0 for an empty bank.  The counter is a u16 (the `lsl #16` / `lsr #16` pair
 * per iteration) and the count is re-read from the bank every iteration, which
 * is why the guard at the top is a rotated `cmp count, #0`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020648E0.c \
 *       --func func_020648E0 --addr 0x020648E0 --arm --cc 1.1p1
 */
u16 func_020648E0(struct MultiCellBank *bank)
{
    u16 max = 0;
    u16 i;

    for (i = 0; i < bank->numMultiCell; i++) {
        u16 n = func_020629E8(bank, i)->numNodes;

        if (n > max) {
            max = n;
        }
    }

    return max;
}

/*
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
void func_02064934(struct Root *p, int arg)
{
    if (p->kind == 1) {
        u16 i;
        char *cells = p->cells;
        for (i = 0; i < p->data->numCellAnims; i++) func_02064364((struct CellAnim *)(cells + i * 0x5c), arg);
    } else {
        u16 i;
        char *cells = p->cells;
        for (i = 0; i < p->data->numNodes; i++) func_02064364(*(void **)(cells + i * 0x28), arg);
    }
}
