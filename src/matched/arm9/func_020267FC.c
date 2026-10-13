/*
 * function: GAME_BEACON_SendIfRequested
 * address:  0x020267FC
 * packet:   pkt_020266E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   func_0217778C  0x0217778C  thumb
 *   GAME_BEACON_Work     0x02146940  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern char *GAME_BEACON_Work;

extern int GFL_NET_GetRunState(void);
extern void func_0217778C(void);

void GAME_BEACON_SendIfRequested(void)
{
    if (*(u8 *)(GAME_BEACON_Work + 0x62) == 1) {
        if (GFL_NET_GetRunState() == 1) {
            func_0217778C();
            *(u8 *)(GAME_BEACON_Work + 0x62) = 0;
        }
    }
}
