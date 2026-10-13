/*
 * function: FIELD_FK_DEMO_DeleteSoundAnime
 * address:  0x021F3D9C
 * packet:   pkt_ov056_021F3D9C
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   FIELD_FK_SOUND_ANIME_Delete  0x021F408C  thumb  ov056
 *   MI_CpuFill8  0x02082BCC  arm
 */
typedef unsigned int u32;

struct IcaAnime;
extern void FIELD_FK_SOUND_ANIME_Delete(struct IcaAnime **pp);
extern void MI_CpuFill8(void *p, int c, u32 n);

void FIELD_FK_DEMO_DeleteSoundAnime(void *o)
{
    if (*(void **)o != 0) {
        FIELD_FK_SOUND_ANIME_Delete(*(void **)o);
    }
    MI_CpuFill8(o, 0, 4);
}
