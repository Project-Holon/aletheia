/*
 * function: NNSi_G2dUnpackMultiCellBank
 * address:  0x0206296C
 * packet:   pkt_02062688
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_G2dFixupMultiCellAnimBankTbl  0x0206295C  arm
 *
 * NNS G2D multi-cell bank (NMCR 'KBCM' block) offset-to-pointer fixup, run
 * once when the bank is unpacked.  It names the on-disk layout exactly:
 *
 *   +0x00  u16 numMultiCell
 *   +0x02  u16 (padding)
 *   +0x04  offset -> the multi-cell descriptor array, 8 bytes per entry
 *   +0x08  offset -> the base the per-descriptor node arrays are relative to
 *   +0x10  offset -> the embedded cell-animation bank ('KNBA'/NANR body), or 0
 *
 * and each 8-byte multi-cell descriptor as
 *
 *   +0x00  u16 numNodes
 *   +0x02  u16
 *   +0x04  offset -> that multi-cell's node array, relative to the +0x08 base
 *
 * The 8-byte descriptor stride is what the loop's `lsl #3` proves; a 10- or
 * 12-byte descriptor is not what this game reads.
 *
 * HOW THE 2026-09-21 WALL WAS CLOSED.  docs/notes/NNSi_G2dUnpackMultiCellBank.c.txt records
 * this function as a 120-of-124-byte near miss: the image re-loads the +0x04
 * field it has just stored (`ldr r4,[r0,#4]` at +0x24), and every plain
 * spelling lets -O4,p forward the stored value instead, four bytes short.
 * Three things together reproduce it, and all three are load-order evidence,
 * not decoration:
 *   1. the bank pointer is `volatile`, which is what stops the two +0x04/+0x08
 *      fixups being scheduled in parallel into two scratch registers;
 *   2. the re-load is written as an explicit `*(volatile u32 *)(bank + 4)`
 *      read into a local, which is the only spelling the optimiser does not
 *      forward through -- a plain `array = bank->array` still folds;
 *   3. the loop bound is re-read at the BOTTOM of the body (`n =
 *      bank->numMultiCell;` after the store), which is what puts the count's
 *      `ldrh r1,[r0]` ahead of the array re-load instead of behind it.
 * The last two steps (statement order inside the body, and binding the sum to
 * a named temporary so the `add` lands before the `str`) were found by
 * tools/permuter.py --mode hill: `reorder(+1) ; temp(tmp=array[i].nodes +
 * bank->nodeBase)`, EXACT at compile 429 of 800.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNSi_G2dUnpackMultiCellBank.c \
 *       --func NNSi_G2dUnpackMultiCellBank --addr 0x0206296C --cc 1.1p1 --arm
 */
#include "../include/Obj02615.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;


struct MultiCellData {
    u16 numNodes;
    u16 unk02;
    u32 nodes;
};

struct MultiCellBank {
    u16 numMultiCell;
    u16 unk02;
    struct MultiCellData *array;
    u32 nodeBase;
    u32 unk0C;
    u8 *animBank;
};

extern void NNSi_G2dFixupMultiCellAnimBankTbl(void *animBank);

void NNSi_G2dUnpackMultiCellBank(volatile struct MultiCellBank *bank)
{
    u16 i;
    u16 n;
    struct MultiCellData *array;
    u8 *anim;
    u32 tmp;

    bank->array = (struct MultiCellData *)((u32)bank->array + (u32)bank);
    bank->nodeBase = bank->nodeBase + (u32)bank;

    i = 0;
    n = bank->numMultiCell;
    array = (struct MultiCellData *)*(volatile u32 *)&((struct Obj02615 *)bank)->f4;

    while (i < n) {
        tmp = array[i].nodes + bank->nodeBase;
        array[i].nodes = tmp;
        n = bank->numMultiCell;
        i++;
    }

    anim = bank->animBank;
    if (anim != 0) {
        anim = anim + (u32)bank;
        bank->animBank = anim;
        NNSi_G2dFixupMultiCellAnimBankTbl(anim);
    }
}
