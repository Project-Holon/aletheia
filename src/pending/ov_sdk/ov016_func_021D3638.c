/*
 * function: func_021D3638
 * address:  0x021D3638
 * packet:   pkt_ov016_021D3638
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * w9_nm: still 5 B. Also tried: the ternary with no local, one/zero locals selected by a ternary, result from a local then a ternary, early return of r or 1.
 *
 * sdk:      DWCi_MOV_WH_Initialize (libdwcutil.TWL.HYB.a(dwc_mov_wh.o))
 *
 * w6_nm tried: goto-spelled exits with a shared return label (both senses),
 * a result local via goto, unsigned char return/callee types: register roles unchanged.
 *
 * w8_nm: `int r = 0; ... if (call) r = 1; return r;` puts 0 in r5 and 1 in r4 as
 * in the object (15 B -> 5 B). Left: the object returns with `moveq r0,r5;
 * movne r0,r4`, this compile with `movne r5,r4; mov r0,r5`. The result local is
 * not in the DWARF. Tried: `? 1 : 0`, `!!`, `!= 0`, if/else returns in both
 * senses, r = 1 then clear, if/else assignment, the call result in a local,
 * cc 1.1, 1.2, 1.2p1, 1.3.
 *
 * T6: still 5 B - the select's destination register. Object `moveq r0,r5 /
 * movne r0,r4`; this build `movne r5,r4 / mov r0,r5` (the result coalesces
 * into the r5 zero constant). 14 spellings re-run: if/return without else in
 * both senses, if/else returns, `r = c ? 1 : 0;` at declaration and after the
 * stores, `(c != 0)`, one/zero locals, `if (c) r = 1; else r = 0;` - every one
 * either flips the constant assignment to r4=0/r5=1 or keeps the result in
 * r5. Only `int r = 0; if (c) r = 1; return r;` keeps the object's r5=0/r4=1
 * ordering, and that is the shape whose result coalesces. A sweep over all
 * nine pins x seven flag sets x inline/ipa variants is D5 in every cell.
 * U26: 8 further tail spellings (bare ternary, assignment-ternary, `!= 0`, `!!`, if/else in both
 * senses, braced single-arm if, do/while(0), temp local, `return c ? 1 : r` with r == 0) - every
 * one either flips the constants (0 to r4, 1 to r5, 15 B out) or keeps the result coalesced into
 * r5 with the copy to r0 (5 B out).  The 2-instruction residue is the if-converted select's
 * destination register, not a statement shape.
 *
 * symbols:
 *   DWCi_MOV_WH_StateInInitialize    0x021D36D0  arm  ov016
 *   g_021DE660                       0x021DE660  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct {
    u32 f0;
    u16 f4;
    u8 pad0[0x48 - 6];
    u32 f48;
    u32 f4c;
    u16 f50;
    u16 f52;
    u32 f54;
    u8 pad1[0x12a0 - 0x58];
    u32 f12a0;
    u32 f12a4;
} Wh;

typedef struct {
    void *trace;
    Wh *wh;
} WhGlobals;

extern WhGlobals g_021DE660;
extern int DWCi_MOV_WH_StateInInitialize(void);

int func_021D3638(void)
{
    int r = 0;

    g_021DE660.wh->f12a4 = 0;
    g_021DE660.wh->f12a0 = 0;
    g_021DE660.wh->f48 = 0;
    g_021DE660.wh->f50 = 0;
    g_021DE660.wh->f52 = 1;
    g_021DE660.wh->f54 = 0;
    g_021DE660.wh->f0 = 0;
    g_021DE660.wh->f4 = 0;
    g_021DE660.wh->f4c = 0;
    if (DWCi_MOV_WH_StateInInitialize())
        r = 1;
    return r;
}
