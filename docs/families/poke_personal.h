/*
 * docs/families/poke_personal.h -- notes for the poke_personal.c family as
 * tools/session/families.py cuts it (0x0201ADE4..0x0201B28C; __FILE__ anchor
 * "poke_personal.c" at 0x020A7310, referenced from 0x0201AE10).  The span
 * borders pokeparty.c (anchor 0x020A7304, referenced from 0x0201A944 and
 * 0x0201AC28) and the party-record helpers below read like pokeparty.c code,
 * so the seam between the two files is soft.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and match.py never sees it.  Declarations are taken from
 * EXACT files in src/matched, named beside them.
 */

#ifndef POKE_PERSONAL_H
#define POKE_PERSONAL_H

typedef unsigned int u32;
typedef int          s32;

/* Party helpers (unit_0201B100.c, sub_0201B038.c). */
extern s32   sub_0201AA18(void *party);            /* member count */
extern void *sub_0201AB28(void *party, s32 i);     /* member i */

/* Party-record field get/set: func_02017E1C(mon, id, 0) reads, and
 * func_02017E40(mon, id, v) writes.  Ids used here: 5 species, 0x4C egg
 * flag, 0x97 the packed byte field (low nibble a countdown, high nibble a
 * strain; 0x0201B220's readers and 0x0201B100's writers). */
extern u32  func_02017E1C(void *mon, u32 id, u32 v);
extern void func_02017E40(void *mon, u32 id, u32 v);

/* The mask of party slots whose 0x97 field is set (unit_0201B220.c). */
extern u32  sub_0201B220(void *party);

/* The 3-in-65536 random event that seeds field 0x97 on one random member
 * (sub_0201B038.c).  Every random draw is a multiply-high; see
 * docs/idioms/random-below-n-is-a-64-bit-multiply-high.md.  The packed byte
 * is built as `w = v; w |= (u8)(v << 4);` then masked 0xF3 and incremented. */
extern void sub_0201B038(void *party);

#endif /* POKE_PERSONAL_H */
