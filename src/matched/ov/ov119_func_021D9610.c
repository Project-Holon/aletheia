/*
 * function: func_021D9610
 * address: 0x021D9610
 * packet: pkt_ov119_021D9610
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_IsHostSide 0x021D8AA8 thumb ov119
 *   POKETRADE_PROC_GetSideMon 0x021D8FA4 thumb ov119
 *   POKETRADE_PROC_GetSideValue 0x021D8F20 thumb ov119
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   func_0202136C 0x0202136C thumb
 */
typedef unsigned short u16;
extern int POKETRADE_PROC_IsHostSide(void *);
extern void *POKETRADE_PROC_GetSideMon(void *,int);
extern int POKETRADE_PROC_GetSideValue(void *,int);
typedef unsigned int   u32;
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern u32 func_0202136C(u16 v);
int func_021D9610(unsigned char *p) { void *v; int w; if(POKETRADE_PROC_IsHostSide(p)==0) {v=POKETRADE_PROC_GetSideMon(p,0); w=POKETRADE_PROC_GetSideValue(p,1);} else {v=POKETRADE_PROC_GetSideMon(p,1); w=POKETRADE_PROC_GetSideValue(p,0);} if(func_0202136C(POKE_TOOL_GetPartyValue(v,6,0)) && p[0x11f4]!=0 && w==0) return 1; return 0; }
