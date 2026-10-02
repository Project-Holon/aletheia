/*
 * function: func_021C23B8
 * address:  0x021C23B8
 * packet:   pkt_ov099_021C23B8
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unblocked (was MATCH on one witness).
 * +0004 ABS32 func_02156860          -> resolved as `matched` by
 * src/matched/ov009_func_02156860.c after fixing the ISA/region hint: the
 * target is Thumb code in ov009 (ov010 opens with adds r3,r7,#0 and an
 * immediate branch), declared as `func_02156860 0x02156860 thumb ov009` below.
 *
 * symbols:
 *   func_02156860  0x02156860  thumb  ov009
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int func_02156860(int i);
int func_021C23B8(int i) { return func_02156860(i); }
