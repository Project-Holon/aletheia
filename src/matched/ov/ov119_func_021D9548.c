/*
 * function: POKETRADE_PROC_IsSelectedOfferSlot
 * address: 0x021D9548
 * packet: pkt_ov119_021D9548
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_LoadSlotMonAlt 0x021D8DD0 thumb ov119
 *   func_02017E88 0x02017E88 thumb
 *   func_0202F738 0x0202F738 thumb
 */
#include "../include/Obj04475.h"
typedef unsigned int   u32;
extern void *POKETRADE_PROC_LoadSlotMonAlt(void *a, int b, int c, char *p);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern int func_0202F738(void *p, int a1);
int POKETRADE_PROC_IsSelectedOfferSlot(char *p,int a,int b) { int v=(int)POKETRADE_PROC_LoadSlotMonAlt((void *)(((struct Obj04475 *)p)->f828),a,b,p); int r; if(((struct Obj04475 *)p)->f118C) return 0; if(a!=((struct Obj04475 *)p)->f630) return 0; r=0; if(func_02017E88((void *)v,76,0)) return r; if(func_0202F738((void *)v,r)==0) r=1; return r; }
