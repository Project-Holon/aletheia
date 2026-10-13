/*
 * function: EVENT_ENTRANCE_IN_ReplaceBgm
 * address:  0x021BD94C
 * packet:   pkt_ov021_021BD94C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb  arm9
 *   FIELD_SOUND_SYSTEM_PostZoneBgmReplace  0x02029D44  thumb  arm9
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    char pad[8];
    void *f8;
    char pad2[0x14];
    u16 h20;
    char pad3[0x23];
    u8 b45;
    char pad4[2];
    int f48;
} Inner;

typedef struct {
    char pad[8];
    Inner *f8;
} Obj;

typedef unsigned int   u32;
struct BigObj;
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern void FIELD_SOUND_SYSTEM_PostZoneBgmReplace(u32 a, u32 b, u16 c, u8 d);

void EVENT_ENTRANCE_IN_ReplaceBgm(Obj *p)
{
    Inner *q = p->f8;
    void *r = q->f8;

    FIELD_SOUND_SYSTEM_PostZoneBgmReplace(GAME_DATA_GetBgmInfo(r), (u32)r, q->h20, q->b45);
    q->f48 = 1;
}
