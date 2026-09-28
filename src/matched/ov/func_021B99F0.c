/*
 * function: func_021B99F0
 * address:  0x021B99F0
 * packet:   pkt_021EA478
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B99F0   0x021B99F0  thumb  ov093

 * Two-value membership test with the `||` left unfolded: cmp #2, beq, cmp #3, bne.  The adjacent constants are normally folded into a range test (`subs r0,#2; cmp r0,#1; bhi`), and every if-statement spelling of it still folds; materialising the disjunction as a VALUE instead of a branch condition -- the ternary `? 1 : 0` -- is what keeps the two separate `cmp`s.  Closes lane O28's residue.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

u32 func_021B99F0(u32 x) { return (x == 2 || x == 3) ? 1 : 0; }

