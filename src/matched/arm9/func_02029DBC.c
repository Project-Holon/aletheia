/*
 * function: FIELD_SOUND_SYSTEM_LowerVolume
 * address:  0x02029DBC
 * packet:   pkt_02029D44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FIELD_SOUND_SYSTEM_LowerVolume.c \
 *       --func FIELD_SOUND_SYSTEM_LowerVolume --addr 0x02029DBC --thumb --cc 1.1p1
 *
 * symbols:
 *   ISS_3DS_SYS_SetVolume  0x0202B914  thumb
 *   FIELD_SOUND_SYSTEM_FadeVolume  0x02028A58  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef unsigned short u16;
struct Obj;
struct SoundSys;
extern u32 func_0202B57C(void *obj);
extern void ISS_3DS_SYS_SetVolume(struct Obj *o, u32 v);
extern void FIELD_SOUND_SYSTEM_FadeVolume(struct SoundSys *sys, u8 level, u16 frames);

void FIELD_SOUND_SYSTEM_LowerVolume(u8 *a, u32 b)
{
    u32 r = func_0202B57C((void *)b);

    ISS_3DS_SYS_SetVolume((struct Obj *)r, 0);
    FIELD_SOUND_SYSTEM_FadeVolume((struct SoundSys *)a, 0x40, 6);
}