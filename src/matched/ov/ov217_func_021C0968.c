/*
 * function: func_021C0968
 * address:  0x021C0968
 * packet:   pkt_ov217_021C0968
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * This address is also matched as func_021C0968 in ov208; the ov217 copy is a
 * distinct function and gets its own shard.
 *
 * symbols:
 *   func_021BF734  0x021BF734  thumb  ov217
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_COMM_SetNotifyFlag  0x02026498  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_021BF734(u8 *a0);
struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *);
extern void GAME_COMM_SetNotifyFlag(void *obj, u32 flag);

void func_021C0968(unsigned char *a0)
{
    GAME_COMM_SetNotifyFlag((void *)GAMESYSTEM_GetGameComm((const struct Ctx *)func_021BF734(a0)), 0);
}
