/*
 * function: GAME_BEACON_SetPms
 * address:  0x0202715C
 * packet:   pkt_0202715C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * EXACT*: the listing extent runs 60 bytes to the next label; only the
 * first 24 bytes belong to this function (the follower at 0x02027174 is
 * an unlabelled leaf).
 *
 * The original splits the address arithmetic into `adds r0, r4, #4` then
 * `adds r0, #0x5e`, which a flat `*(u8 *)(p + 0x62)` folds into one
 * `adds r4, #0x62`.  Taking a pointer to a NESTED struct member (the
 * inner object starts at +4) before the call is what pins the two-step
 * form: `&g->in` is its own value, materialised at +0x0A, and the field
 * offset is added separately at +0x0E.
 *
 * symbols:
 *   GAME_BEACON_Work     0x02146940  data
 *   GAME_BEACON_SetMyPms  0x020274B4  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Inner {
    u8  pad[0x5e];
    u8  f5e;
};

struct Outer {
    u32 f00;
    struct Inner in;
};

extern struct Outer *GAME_BEACON_Work;
extern void  GAME_BEACON_SetMyPms(u32 a0);

void GAME_BEACON_SetPms(u32 a0)
{
    struct Inner *in = &GAME_BEACON_Work->in;

    GAME_BEACON_SetMyPms(a0);
    in->f5e = 1;
}
