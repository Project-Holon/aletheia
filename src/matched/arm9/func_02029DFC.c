/*
 * function: FIELD_SOUND_SYSTEM_GetFinalBgm
 * address:  0x02029DFC
 * packet:   pkt_02029DFC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  02028900 label
 *
 * symbols:
 *   FIELD_SOUND_SYSTEM_GetFinalValue  0x02028900  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


struct BigObj;
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern void *FIELD_SOUND_SYSTEM_GetFinalValue(void *p);

void *FIELD_SOUND_SYSTEM_GetFinalBgm(const void *p)
{
    return FIELD_SOUND_SYSTEM_GetFinalValue((void *)GAME_DATA_GetBgmInfo(p));
}
