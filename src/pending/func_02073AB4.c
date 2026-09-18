/*
 * function: func_02073AB4
 * address:  0x2073AB4
 * packet:   pkt_02073624
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  0x02073B3C has no witness outside this range: its only caller is this function
 *
 * The guard is a live `lsls #31`/`asrs #31` pair, i.e. a bit-0 read that is
 *  * *signed*: an `& 1` mask would be a single `and`, and an unsigned 1-bit
 *  * bitfield would end in `lsrs`. Writing the field as a 1-bit signed bitfield
 *  * reproduces the pair exactly. The call site at 0x020738EC passes r1
 *  * sign-extended the same way, which is the same accessor in the caller.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct X { u8 pad00[0x2c]; signed f2c : 1; };
extern void func_02073B3C(struct X *);

void func_02073AB4(struct X *x)
{
    if (!x->f2c) return;
    func_02073B3C(x);
}
