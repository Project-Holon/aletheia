/*
 * function: MUSICAL_PROGRAM_GetBestCategory
 * address:  0x021572C0
 * packet:   pkt_ov010_021572C0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Declaration order i, max, idx is what colours them r2, r3, r4.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Deal {
    u8 f00[4];          /* 0x00 */
} Deal;

u8 MUSICAL_PROGRAM_GetBestCategory(Deal *d)
{
    u8 i;
    u8 max;
    u8 idx;

    max = 0;
    idx = 0;
    for (i = 0; i < 4; i++) {
        if (max < d->f00[i]) {
            max = d->f00[i];
            idx = i;
        }
    }
    return idx;
}
