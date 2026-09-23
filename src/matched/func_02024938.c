/*
 * function: func_02024938
 * address:  0x02024938
 * packet:   pkt_02024938
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   tbl_0209F784   0x0209F784  data  a1
 *   func_020249A0  0x020249A0  thumb
 *
 * pms_word.c: clear the flag words, seed all forty word slots to 0xFFFF,
 * then set the flag bit named by the first row of the 7 x 2 byte table at
 * 0x0209F784 whose kind is 2.  The table is a 2D array: `tbl[k][1]` is what
 * gives the image's second pool word 0x0209F785 (symbol + 1, indexed by
 * the same 2k), where a struct {kind, val} folds the +1 into the load
 * (docs/notes/pkt_02024938.c.txt).  k is unsigned (`blo`); the first two
 * loops count in int.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct PmsWordEntry {
    u32 f00;
    u16 word[2];
};

struct PmsWord {
    u32 flags;
    u32 f04;
    struct PmsWordEntry e[20];
};

extern const u8 tbl_0209F784[][2];
extern void func_020249A0(void *p, int bit);

void func_02024938(struct PmsWord *p)
{
    int i, j;
    u32 k;

    p->flags = 0;
    p->f04 = 0;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 2; j++)
            p->e[i].word[j] = 0xffff;
    }
    for (k = 0; k < 7; k++) {
        if (tbl_0209F784[k][0] == 2) {
            func_020249A0(p, tbl_0209F784[k][1]);
            return;
        }
    }
}
