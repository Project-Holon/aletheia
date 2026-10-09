/*
 * file:     unit_020643CC_p02.c
 * unit:     yes
 * function: func_02064648, func_0206469C, func_02064754
 * address:  0x02064648
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020629E8  0x020629E8  arm
 *   func_02062D40   0x02062D40  arm
 *   func_02062FF0   0x02062FF0  arm
 *   func_020640DC   0x020640DC  arm
 *   func_02064100   0x02064100  arm
 *   func_02064120   0x02064120  arm
 *   func_02064140   0x02064140  arm
 *   func_020643CC   0x020643CC  arm
 *   func_020648E0  0x020648E0  arm
 *   func_020627D8  0x020627D8  arm
 *   func_0206428C  0x0206428C  arm
 *   func_02064178  0x02064178  arm
 *   func_02062F38  0x02062F38  arm
 */
#include "../../matched/include/Obj16437.h"

struct CellAnim;
struct O02064140;
struct MultiCellBank;
struct MultiCellData;
struct Obj02064100;
struct MCInstance;
struct AnimBank;
struct AnimSequence;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

struct MultiCellData {
    u16 numNodes;
    u16 numCellAnims;
};

struct MultiCellBank {
    u16 numMultiCell;
};

typedef signed short   s16;

struct Srt0206469C {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    s16 unk_0c;
    s16 unk_0e;
    u16 unk_10;
    u16 unk_12;
};

struct FrameHdr0206469C {
    u8  pad_00[4];
    u32 kind;
};

struct Node0206469C {
    u16 unk_00;
    u16 unk_02;
    s16 unk_04;
    s16 unk_06;
    u32 unk_08;
    s16 unk_0c;
    s16 unk_0e;
};

struct Obj0206469C {
    u8  pad_00[4];
    u8 *unk_04;
    u8  pad_08[0x14];
    struct FrameHdr0206469C *unk_1c;
    u8  pad_20[0x10];
    u16 unk_30;
    u8  pad_32[2];
    u32 unk_34[4];
    void *unk_44;
    struct Srt0206469C unk_48;
};

extern struct MultiCellData *func_020629E8(struct MultiCellBank *bank, u32 idx);
extern void func_02062FF0(struct CellAnim *anim, void *bank);
extern void *func_02062D40(struct CellAnim *anim);
extern void func_02064140(struct O02064140 *o, u32 a);
extern void func_020640DC(struct Srt0206469C *srt, s16 x, s16 y);
extern void func_02064100(struct Obj02064100 *obj, u16 val);
extern void func_02064120(struct Srt0206469C *srt, u32 sx, u32 sy);
extern void func_020643CC(struct MCInstance *pMCInst, const struct MultiCellData *pMcData, u16 mcTotalFrame);
extern u16 func_020648E0(struct MultiCellBank *bank);
extern struct AnimSequence *func_020627D8(struct AnimBank *bank, u32 idx);
extern void func_0206428C(char *self, int a1, char *c);
extern void func_02064178(char *o, u32 a);
extern int func_02062F38(int a0);
u16 func_02064648(struct MultiCellBank *bank);
void func_0206469C(struct Obj0206469C *o, void *bank);
void func_02064754(char *o, char *buf, void *set, int a3, void *bank, int kind);


/*
 * Returns the largest per-multi-cell "cell animation slot count" (the u16 at
 * +0x02 of the 8-byte multi-cell descriptor) across a whole multi-cell bank.
 * The caller sizes its array of 0x5C-byte cell-animation states with this, and
 * each node's byte at +0x07 is the index into that array -- which is why that
 * byte runs 0, 1, 2, ... across a multi-cell's nodes rather than naming a cell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02064648.c  *       --func func_02064648 --addr 0x02064648 --cc 1.1p1
 */
u16 func_02064648(struct MultiCellBank *bank)
{
    u16 max = 0;
    u16 i = 0;

    for (i = 0; i < bank->numMultiCell; i++) {
        u16 n = func_020629E8(bank, i)->numCellAnims;

        if (n > max) {
            max = n;
        }
    }

    return max;
}



/*
 * Rebuilds one multi-cell node's SRT block from its current NANR frame record.
 * The node record comes through func_02062D40 and its descriptor through
 * func_020629E8; the frame's kind byte (a word masked with 0xff, not a ldrb)
 * selects the arm: 0 does nothing, 2 is translation-only, anything else is the
 * full SRT form (scale, rotation, translation).  The walk finishes by handing
 * the descriptor and the node's own u16 counter at +0x30 to func_020643CC.
 *
 * PIN ../2.0/sp2: the "kept branches" tell in its CROSS-JUMP form, the same
 * one src/matched/func_02064AB4.c and src/matched/func_0206419C.c carry.  The
 * image writes the kind==2 arm's `add r0, r4, #0x48` / `bl func_020640DC` tail
 * out in its own arm although the other arm's LAST call is a byte-identical
 * pair; 1.1p1 -O4,p cross-jumps the two and lands at 176 bytes against the
 * original's 184, 73 concrete bytes out (docs/notes/pkt_0206469C.c.txt, which
 * measured the goto/if-else/switch spellings and found them all folding).
 * Under the pin this SAME C is 184 bytes, 0 mismatches, all 9 sites by label.
 */
void func_0206469C(struct Obj0206469C *o, void *bank)
{
    struct Node0206469C *p;
    u32 k;
    u32 r;

    func_02062FF0((struct CellAnim *)o, bank);
    o->unk_30 = 0;

    if (((struct Obj16437 *)(o->unk_04))->f4 == 0) {
        return;
    }

    p = func_02062D40((struct CellAnim *)o);
    r = (u32)func_020629E8(o->unk_44, p->unk_00);
    k = o->unk_1c->kind & 0xff;

    func_02064140((struct O02064140 *)(&o->unk_48), 1);

    if (k == 0) {
        goto done;
    }

    if (k == 2) {
        func_020640DC(&o->unk_48, p->unk_04, p->unk_06);
    } else {
        func_02064120(&o->unk_48, *(u32 *)&p->unk_04, p->unk_08);
        func_02064100((struct Obj02064100 *)(&o->unk_48), p->unk_02);
        func_020640DC(&o->unk_48, p->unk_0c, p->unk_0e);
    }

done:
    func_020643CC((struct MCInstance *)o->unk_34, (const struct MultiCellData *)r, o->unk_30);
}


/*
 * Build a multi-cell animation's cell array (docs/families/cluster_020640DC.h,
 * section 3): kind == 1 is the flat 0x5c-stride array sized by
 * func_02064648(bank), anything else the two-level shape of
 * func_020648E0(bank) 0x28-byte group headers followed by 0x58-stride cells.
 *
 * Three things closed it after docs/notes/pkt_02064754.c.txt stalled at 70
 * out:
 *   - DATA FLOW.  The NMCR bank handed to both sizing calls is the FIFTH
 *     argument (loaded from [sp,#0x28] into r0 before the kind test and
 *     respilled to its own slot), and the second argument is the cell
 *     buffer stored at +0x40 and used as the group-header base.  The note's
 *     body passed the second argument to func_020648E0; with the flow
 *     corrected no `volatile` is needed for the respill.
 *   - Arm 2 runs the four-call tail TWICE (it falls into the shared copy),
 *     so the tail is written in the arm and again after the if.
 *   - The count and index are declared PER ARM (u16 n, i inside each
 *     block); function-scope n / i are 18 out (a register swap in both
 *     loops), a separate j for arm 2 is 4 bytes short.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02064754.c \
 *       --func func_02064754 --addr 0x02064754 --arm --cc ../2.0/sp2
 */
void func_02064754(char *o, char *buf, void *set, int a3, void *bank, int kind)
{
  if (kind == 1)
  {
    char *cells;
    u16 n;
    u16 i;
    *((int *) (o + 0x3c)) = 1;
    *((void **) (o + 0x38)) = set;
    *((char **) (o + 0x40)) = buf;
    n = func_02064648(bank);
    cells = *((char **) (o + 0x40));
    for (i = 0; i < n; i++)
    {
      char *cell = cells + i * 0x5c;
      func_0206428C(cell, (int)func_020627D8(set, 0), (char *)a3);
      *((int *) (cell + 0x58)) = 1;
    }
  }
  else
  {
    char *base;
    u16 n;
    u16 i;
    n = func_020648E0(bank);
    base = buf + n * 0x28;
    *((int *) (o + 0x3c)) = 0;
    *((int *) (o + 0x34)) = 0;
    *((void **) (o + 0x38)) = set;
    *((char **) (o + 0x40)) = buf;
    for (i = 0; i < n; i++)
    {
      char *hdr = buf + i * 0x28;
      char *cell;
      func_02064178(hdr, 1);
      cell = base + i * 0x58;
      *((char **) hdr) = cell;
      func_0206428C(cell, (int)func_020627D8(set, 0), (char *)a3);
    }
    func_02062F38((int)o);
    *((void **) (o + 0x44)) = bank;
    func_02064140((struct O02064140 *)(o + 0x48), 1);
    *((u16 *) (o + 0x30)) = 0;
  }
  func_02062F38((int)o);
  *((void **) (o + 0x44)) = bank;
  func_02064140((struct O02064140 *)(o + 0x48), 1);
  *((u16 *) (o + 0x30)) = 0;
}
