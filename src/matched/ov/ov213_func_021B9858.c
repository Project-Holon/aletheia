/*
 * function: COMM_BTL_DEMO_MAIN_Step
 * address: 0x021B9858
 * packet: pkt_ov213_021B9858
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   COMM_BTL_DEMO_MAIN_InitRows 0x021BA38C thumb ov213
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Context Context;
extern void COMM_BTL_DEMO_MAIN_InitRows(Context *);
int COMM_BTL_DEMO_MAIN_Step(void *unused, Context *p) { COMM_BTL_DEMO_MAIN_InitRows(p); return 1; }
