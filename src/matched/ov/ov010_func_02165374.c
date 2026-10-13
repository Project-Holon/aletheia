/*
 * function: func_02165374
 * address:  0x02165374
 * packet:   pkt_ov010_02165374
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Looks the id up in a five-entry byte table; on a hit re-submits the
 * record at the shared globals pointer.
 *
 * symbols:
 *   GAME_BEACON_CheckActionPriority   0x02027060  thumb
 *   GAME_BEACON_RequestSend   0x02026FB8  thumb
 *   GAME_BEACON_Work      0x02146940  data
 *   d_02171CA0      0x02171CA0  data  ov010  a1
 *   func_021653B4   0x021653B4  thumb  ov010
 */

typedef unsigned char u8;

typedef unsigned int   u32;
extern u32 GAME_BEACON_CheckActionPriority(u32 a);
extern void GAME_BEACON_RequestSend(void *);
extern char *GAME_BEACON_Work;
extern u8 d_02171CA0[5];
extern void func_021653B4(void *, unsigned);

void func_02165374(unsigned a0)
{
    unsigned i;

    if (GAME_BEACON_CheckActionPriority(0x16)) {
        for (i = 0; i < 5; i++) {
            if (a0 == d_02171CA0[i]) {
                func_021653B4(GAME_BEACON_Work + 4, a0);
                GAME_BEACON_RequestSend(GAME_BEACON_Work + 4);
                return;
            }
        }
    }
}
