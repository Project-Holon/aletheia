/*
 * function: EVENT_MAPCHANGE_TamperLeakA
 * address: 0x0218604C
 * packet: pkt_ov020_0218604C
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_02187EA0 0x02187EA0 data ov020 a1
 */
extern char d_02187EA0[];
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
void *EVENT_MAPCHANGE_TamperLeakA(void) { return func_02030734(0x8004,0x1000,0,d_02187EA0,0xe35); }
