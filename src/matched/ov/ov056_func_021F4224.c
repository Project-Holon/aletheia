/*
 * function: FIELD_FK_SOUND_ANIME_PlaySe
 * address:  0x021F4224
 * packet:   pkt_ov056_021F4224
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void GFL_USE_PlaySeDefaultVolume(u32 a);

void FIELD_FK_SOUND_ANIME_PlaySe(u8 *p, u32 idx)
{
    u16 v = *(u16 *)(p + idx * 2 + 8);

    if (v != 0xffff) {
        GFL_USE_PlaySeDefaultVolume(v);
    }
}
