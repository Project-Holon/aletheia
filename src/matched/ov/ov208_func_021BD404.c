/*
 * function: ZKND_TBAR_FindButtonActor
 * address:  0x021BD404
 * packet:   pkt_ov208_021BD404
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Linear search of the 0x38-byte records at +0x28 for the record whose key
 * (via 0x021BD7F8) equals the second argument; returns the record or NULL.
 *
 * symbols:
 *   ZKND_TBAR_GetButtonActorBase  0x021BD7F8  thumb
 */

typedef unsigned int u32;

struct Ov208Rec {
    u32 w[14];
};

struct Ov208Mgr {
    u32 f0;
    u32 count;
    u32 pad8[8];
    struct Ov208Rec recs[1];
};

extern int ZKND_TBAR_GetButtonActorBase(char *p);

struct Ov208Rec *ZKND_TBAR_FindButtonActor(struct Ov208Mgr *p, int key)
{
    u32 i;

    for (i = 0; i < p->count; i++) {
        if (key == ZKND_TBAR_GetButtonActorBase((char *)((u32)p + 0x28 + i * 0x38)))
            return (struct Ov208Rec *)((u32)p + 0x28 + i * 0x38);
    }
    return 0;
}
