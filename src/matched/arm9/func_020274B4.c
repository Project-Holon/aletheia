/*
 * function: GAME_BEACON_SetMyPms
 * address:  0x020274B4
 * packet:   pkt_020274B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  02027460 label
 *
 * symbols:
 *   GAME_BEACON_Work     0x02146940  data
 *   GAME_BEACON_WritePms  0x02027460  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern char *GAME_BEACON_Work;
struct Src;
extern void GAME_BEACON_WritePms(void *p, const struct Src *s);

void GAME_BEACON_SetMyPms(u32 a0)
{
    GAME_BEACON_WritePms(GAME_BEACON_Work + 4, (const struct Src *)a0);
}
