/*
 * function: GAME_BEACON_CheckActionPriority
 * address:  0x02027060
 * packet:   pkt_02027060
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The priority gate: answers 1 when id `a`'s priority is at least that of
 * the current mode at +0x34 of the block.  The table at 0x0209FC20 is a
 * word of BITFIELDS, { prio : 8; frames : 24; } -- GAME_BEACON_UpdateActionTime reads the
 * same word `>> 8`.  Spelled as `(u8)tbl[i]` on a u32 array the compiler
 * ties the lsrs order to the cmp order and stays 4 bytes out (see
 * docs/notes/pkt_02027060.GAME_BEACON_CheckActionPriority.c.txt); the bitfield read frees
 * the schedule.  Also EXACT under ../2.0/sp2.
 *
 * symbols:
 *   GAME_BEACON_Work  0x02146940  data
 *   GAME_BEACON_ActionTable    0x0209FC20  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct S { u8 pad[0x34]; u16 f34; };
struct Prio { u32 prio : 8; u32 frames : 24; };

extern struct S *GAME_BEACON_Work;
extern const struct Prio GAME_BEACON_ActionTable[];

u32 GAME_BEACON_CheckActionPriority(u32 a)
{
    if (GAME_BEACON_ActionTable[a].prio >= GAME_BEACON_ActionTable[GAME_BEACON_Work->f34].prio)
        return 1;
    return 0;
}
