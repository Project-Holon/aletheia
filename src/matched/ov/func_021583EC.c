/*
 * function: GAME_DATA_GetMyStatusByNetId
 * address:  0x021583EC
 * packet:   pkt_021583EC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Dispatch on the record's key: an equal key goes to the
 * single-argument arm9 read, anything else to the pair form.
 *
 * symbols:
 *   GAME_DATA_GetOwnNetId   0x02012B58  thumb
 *   GAME_DATA_GetMyStatus   0x02012944  thumb
 *   GAME_DATA_GetMyStatusPlayer   0x02012950  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct BigObj;
extern u8 GAME_DATA_GetOwnNetId(const struct BigObj *p);
struct Rec44;
struct Sub24;
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern struct Rec44 *GAME_DATA_GetMyStatusPlayer(struct Sub24 *p, u32 i);

int GAME_DATA_GetMyStatusByNetId(void *a0, int a1)
{
    if (GAME_DATA_GetOwnNetId(a0) == a1)
        return (int)GAME_DATA_GetMyStatus(a0);

    return (int)GAME_DATA_GetMyStatusPlayer(a0, a1);
}

