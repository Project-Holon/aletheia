/*
 * function: BTL_CALC_IsBossTrainer
 * address: 0x021D7F60
 * packet: pkt_ov093_021D7F60
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_CALC_IsGymLeaderTrainer 0x021D7F38 thumb ov093
 *   BTL_CALC_IsEliteFourTrainer 0x021D7F4C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_CALC_IsGymLeaderTrainer(u32);
extern int BTL_CALC_IsEliteFourTrainer(u32);
int BTL_CALC_IsBossTrainer(u32 n) { if(BTL_CALC_IsGymLeaderTrainer(n)) return 1; if(BTL_CALC_IsEliteFourTrainer(n)) return 1; return n==89; }
