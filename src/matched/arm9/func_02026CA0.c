/*
 * function: GAME_BEACON_GetNextNewLogIndex
 * address:  0x02026CA0
 * packet:   pkt_0202685C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_BEACON_Work     0x02146940  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern u32 *GAME_BEACON_Work;

int GAME_BEACON_GetNextNewLogIndex(int *p)
{
    int i = *p;

    while (i < 0x1e) {
        if (*(u32 *)((char *)GAME_BEACON_Work + 0xba4) & (1 << i)) {
            *p = *p + 1;
            return *p - 1;
        }
        i = *p + 1;
        *p = i;
    }
    return 0x1e;
}
