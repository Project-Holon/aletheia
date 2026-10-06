/*
 * function: func_021DCF5C
 * address: 0x021DCF5C
 * packet: pkt_ov093_021DCF5C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: 021D5B40's u16 field result is kept as a full register value
 * until the explicit halfword truncation at 021DCF68/021DCF6C; the caller
 * therefore uses a wide result and a u16 021DCEC4 argument, as the listing shows.
 * symbols:
 *   func_021D5B40 0x021D5B40 thumb ov093
 *   func_021DCEC4 0x021DCEC4 thumb ov093
 */
typedef unsigned short u16;
struct QI;
extern u16 func_021D5B40(struct QI *p);
typedef unsigned int   u32;
extern void *func_021DCEC4(void *a, u32 k);
void *func_021DCF5C(void *p) { int k; k=func_021D5B40(p); if(k) return func_021DCEC4(p,(unsigned short)k); return 0; }
