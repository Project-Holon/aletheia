/*
 * function: VIEWER_MAIN_HitRow
 * address:  0x021C5264
 * packet:   pkt_ov111_021C5264
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

typedef struct {
    u8 pad0[4];
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 f4_3 : 1;
    u8 f4_4 : 1;
    u8 f4_5 : 1;
} Info;

typedef struct {
    u8 pad0[0x28];
    Info *info;
} Work;

int VIEWER_MAIN_HitRow(Work *p, int hit)
{
    if (p->info->f4_5 && hit >= 3 && hit <= 9) {
        return 1;
    }
    return 0;
}
