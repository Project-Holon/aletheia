/*
 * function: BTL_CLIENT_PollTimeLimitAndSetSub
 * address: 0x021CE0BC
 * packet: pkt_ov093_021CE0BC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_CLIENT_PollTimeLimitReady 0x021CE08C thumb ov093
 *   BTL_CLIENT_SetSubFn 0x021CE150 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_CLIENT_PollTimeLimitReady(u8 *);
extern void BTL_CLIENT_SetSubFn(u8 *,void *);
int BTL_CLIENT_PollTimeLimitAndSetSub(u8 *p,void *q) { if(BTL_CLIENT_PollTimeLimitReady(p)) { if(q) BTL_CLIENT_SetSubFn(p,q); return 1; } return 0; }
