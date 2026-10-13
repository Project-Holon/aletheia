/*
 * function: WEATHER_TASK_StopSound
 * address:  0x021A2C6C
 * packet:   pkt_ov021_021A2C6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_SOUND_SYSTEM_ReleaseSlot  0x02028B50  thumb
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   GFL_USE_StopSeSlot  0x020061F8  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 state;
    u16 id;
    u32 pad4;
    u32 flag;
} Snd021A2C6C;

typedef unsigned char  u8;
void FIELD_SOUND_SYSTEM_ReleaseSlot(u8 *p, int a0);
int GFL_USE_GetSeSlot(u32 a0);
void GFL_USE_StopSeSlot(int h);

void WEATHER_TASK_StopSound(Snd021A2C6C *p, int a)
{
    if (p->state == 1) {
        p->state = 0;
        if (p->flag != 0)
            FIELD_SOUND_SYSTEM_ReleaseSlot((u8 *)a, p->id);
        else
            GFL_USE_StopSeSlot(GFL_USE_GetSeSlot(p->id));
    }
}
