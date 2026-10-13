/*
 * function: WEATHER_TASK_ResumeSound
 * address:  0x021A2C98
 * packet:   pkt_ov021_021A2C98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_IsLoaderBusy  0x02005C64  thumb
 *   FIELD_SOUND_SYSTEM_ClaimSlot  0x02028A7C  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 state;
    u16 id;
    u32 pad4;
    u32 flag;
} Snd021A2C98;

int GFL_USE_IsLoaderBusy(void);
struct SoundSys2;
void FIELD_SOUND_SYSTEM_ClaimSlot(struct SoundSys2 *s, u32 id);
void GFL_USE_PlaySeDefaultVolume(u32 a);

void WEATHER_TASK_ResumeSound(Snd021A2C98 *p, int a)
{
    if (p->state == 2 && GFL_USE_IsLoaderBusy() == 0) {
        p->state = 1;
        if (p->flag != 0)
            FIELD_SOUND_SYSTEM_ClaimSlot((struct SoundSys2 *)a, p->id);
        else
            GFL_USE_PlaySeDefaultVolume(p->id);
    }
}
