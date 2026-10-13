/*
 * function: FIELD_FK_DEMO_StepSoundAnime
 * address:  0x021F3DB8
 * packet:   pkt_ov056_021F3DB8
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_FK_SOUND_ANIME_Step  0x021F40A0  thumb  ov056
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_FK_SOUND_ANIME_Step(int *p);

int FIELD_FK_DEMO_StepSoundAnime(int **pp)
{
    int r = 1;

    if (*pp != 0) {
        r = FIELD_FK_SOUND_ANIME_Step(*pp);
    }
    return r;
}
