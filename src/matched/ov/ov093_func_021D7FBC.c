/*
 * function: BTL_CALC_CalcTrainerPrizeMoney
 * address: 0x021D7FBC
 * packet: pkt_ov093_021D7FBC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_0202A230 0x0202A230 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0201AA18(void *);
extern void *func_0201AB28(void *,u32);
extern u32 func_0202A230(void *,u32);
extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);
u32 BTL_CALC_CalcTrainerPrizeMoney(void **p,void *q) { u8 n; void *e; u32 v; if(q) { n=(u8)func_0201AA18(q); if(n) { e=func_0201AB28(q,n-1); v=func_0202A230(*p,10); return v*POKE_TOOL_GetPartyValue(e,158,0)*4; } } return 0; }
