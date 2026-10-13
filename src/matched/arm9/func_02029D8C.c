/*
 * function: FIELD_SOUND_SYSTEM_PostZoneBgmChangeShortFade
 * address:  0x02029D8C
 * packet:   pkt_02029D8C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   FIELD_SOUND_SYSTEM_GetFieldBgmForZone  0x02029EB4  thumb
 *   FIELD_SOUND_SYSTEM_PostRequest  0x020289F8  thumb
 */

typedef unsigned int u32;

typedef unsigned short u16;
typedef unsigned char  u8;
struct BigObj;
struct Sys;
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern u32 FIELD_SOUND_SYSTEM_GetFieldBgmForZone(void *a, u32 id, u32 which);
extern void FIELD_SOUND_SYSTEM_PostRequest(struct Sys *s, u32 a, u32 b, u16 c, u16 d);

void FIELD_SOUND_SYSTEM_PostZoneBgmChangeShortFade(u32 a0, u32 a1, u32 a2)
{
    u32 temp = GAME_DATA_GetSeason((const struct BigObj *)a1);
    u32 res = FIELD_SOUND_SYSTEM_GetFieldBgmForZone((void *)a1, a2, temp);
    FIELD_SOUND_SYSTEM_PostRequest((struct Sys *)a0, 5, res, 0x1e, 0);
}
