/*
 * function: FIELD_FK_DEMO_CreateSoundAnime
 * address:  0x021F3D60
 * packet:   pkt_ov056_021F3D60
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     heap is u16: the original passes r2 straight to the stack slot
 *           of FIELD_FK_SOUND_ANIME_Create's u16 parameter (an int heap adds lsls/lsrs).
 * symbols:
 *   FIELD_FK_SOUND_ANIME_Create  0x021F4040  thumb  ov056
 *   MI_CpuFill8    0x02082BCC  arm
 *   gFkDemoHasSoundAnime     0x021F42A0  data  a4
 *   gFkSoundAnimeSoundIds     0x021F43A4  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 *FIELD_FK_SOUND_ANIME_Create(void *a, u32 b, u32 c, u32 d, u16 e);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern u32 gFkDemoHasSoundAnime[];
extern u8 gFkSoundAnimeSoundIds[];

void FIELD_FK_DEMO_CreateSoundAnime(void *o, int idx, u16 heap)
{
    if (gFkDemoHasSoundAnime[idx] != 0) {
        *(u32 **)o = FIELD_FK_SOUND_ANIME_Create(gFkSoundAnimeSoundIds + idx * 0x12, 0x96, idx + 0x1c, 10, heap);
        return;
    }
    MI_CpuFill8(o, 0, 4);
}
