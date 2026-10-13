/*
 * function: FIELD_PLAYER_NOGRID_StartSpin
 * address:  0x021A6B08
 * packet:   pkt_ov021_021A6B08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 b0;
    u8 b1;
    short h2;
} P;

typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

void FIELD_PLAYER_NOGRID_StartSpin(P *p, u8 v)
{
    if (p->b0 != 1 || v != p->b1) {
        GFL_USE_PlaySeDefaultVolume(0x6d1);
        p->b0 = 1;
        p->b1 = v;
        p->h2 = 0;
    }
}
