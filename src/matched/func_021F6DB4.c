/*
 * function: func_021F6DB4
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
 *   func_021F6C80  0x021F6C80  thumb
 *
 * For each of the 30 four-byte records with a nonzero s16 head that
 * func_021F6C80 does not accept against `key`, add 3 to the +4 word of
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

extern int func_021F6C80(void *pa, void *pb);

void func_021F6DB4(Rec *recs, u32 unused, void *key, Entry *ent)
{
    int i;

    for (i = 0; i < 30; i++) {
        if (recs[i].a != 0 && func_021F6C80(&recs[i], key) == 0) {
            ent[i].f4 += 3;
        }
    }
}
