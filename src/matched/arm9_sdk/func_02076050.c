/*
 * function: func_02076050
 * address:  0x02076050
 * packet:   pkt_02075FCC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02150200    0x02150200  data
 *   func_02076230 0x02076230  arm
 */
typedef unsigned int u32;
extern u32 g_02150200;
struct CARDiCommon;
extern int func_02076230(struct CARDiCommon *p, int restart, void (*callback)(void *), void *callback_arg);
void func_02076050(void) { func_02076230((struct CARDiCommon *)((u32)&g_02150200), 0, 0, 0); }
