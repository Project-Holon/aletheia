/*
 * function: WORLDTRADE_BOX_ScoreMatchingRecords
 * address:  0x021F6DB4
 * packet:   pkt_021F6DB4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_BOX_TagMatchesRequest  0x021F6C80  thumb
 *
 * For each of the 30 four-byte records with a nonzero s16 head that
 * WORLDTRADE_BOX_TagMatchesRequest does not accept against `key`, add 3 to the +4 word of
 * the matching 0x20C-byte entry. The second argument is unused.
 */

typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

typedef struct {
    s16 a;
    s16 b;
} Rec;

typedef struct {
    u32 f0;
    int f4;
    u8 pad8[0x20C - 8];
} Entry;

extern int WORLDTRADE_BOX_TagMatchesRequest(void *pa, void *pb);

void WORLDTRADE_BOX_ScoreMatchingRecords(Rec *recs, u32 unused, void *key, Entry *ent)
{
    int i;

    for (i = 0; i < 30; i++) {
        if (recs[i].a != 0 && WORLDTRADE_BOX_TagMatchesRequest(&recs[i], key) == 0) {
            ent[i].f4 += 3;
        }
    }
}
