/*
 * function: func_021AA900
 * address:  0x021AA900
 * packet:   pkt_ov021_021AA900
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * True when the entry behind self->+8 is live (low nibble of +0x1D) and its
 * s16 triple at +0x12/+0x14/+0x16 equals pos[0]/pos[1]/pos[2].
 *
 * symbols:
 *   func_02012A38  0x02012A38  thumb
 */

typedef struct Entry {
    char pad00[0x12];
    short x;
    short y;
    short z;
    char pad18[5];
    unsigned char flags : 4;
} Entry;

typedef struct Self {
    char pad00[8];
    void *obj;
} Self;

extern Entry *func_02012A38(void *p);

int func_021AA900(Self *self, short *pos)
{
    Entry *e = func_02012A38(self->obj);

    if (e->flags == 0)
        return 0;
    if (e->x != pos[0] || e->z != pos[2] || e->y != pos[1])
        return 0;
    return 1;
}
