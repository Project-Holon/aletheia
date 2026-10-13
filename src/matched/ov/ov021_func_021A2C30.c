/*
 * function: WEATHER_TASK_PlaySound
 * address:  0x021A2C30
 * packet:   pkt_ov021_021A2C30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WEATHER_TASK_StopSound  0x021A2C6C  thumb  ov021
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
} Snd021A2C30;

void WEATHER_TASK_StopSound(Snd021A2C30 *p, int a);
int GFL_USE_IsLoaderBusy(void);
struct SoundSys2;
void FIELD_SOUND_SYSTEM_ClaimSlot(struct SoundSys2 *s, u32 id);
void GFL_USE_PlaySeDefaultVolume(u32 a);

void WEATHER_TASK_PlaySound(Snd021A2C30 *p, int a, u16 id)
{
    WEATHER_TASK_StopSound(p, a);
    if (GFL_USE_IsLoaderBusy() == 0) {
        p->state = 1;
        p->id = id;
        if (p->flag != 0)
            FIELD_SOUND_SYSTEM_ClaimSlot((struct SoundSys2 *)a, p->id);
        else
            GFL_USE_PlaySeDefaultVolume(p->id);
    } else {
        p->state = 2;
        p->id = id;
    }
}
