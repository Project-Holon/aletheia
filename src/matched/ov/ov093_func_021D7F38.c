/*
 * function: BTL_CALC_IsGymLeaderTrainer
 * address: 0x021D7F38
 * packet: pkt_ov093_021D7F38
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   TPOKE_DATA_GetTrainerKind 0x0202A3FC thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 TPOKE_DATA_GetTrainerKind(u32);
int BTL_CALC_IsGymLeaderTrainer(u32 n) { if(TPOKE_DATA_GetTrainerKind(n)==2) return 1; return 0; }
