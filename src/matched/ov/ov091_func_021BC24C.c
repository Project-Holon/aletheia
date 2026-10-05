/*
 * function: func_021BC24C
 * address: 0x021BC24C
 * packet: pkt_ov091_021BC24C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 2026-10-05 (D8 lane 15): the leaf func_02019CF8 is now filed EXACT in src/matched/arm9, so every
 * relocation resolves and this file is EXACT.
 * symbols:
 *   func_02017E1C 0x02017E1C thumb
 *   func_02019CF8 0x02019CF8 thumb
 *   func_02017988 0x02017988 thumb
 */
typedef unsigned int u32;
extern u32 func_02017E1C(void *,u32,u32);
extern int func_02019CF8(int);
extern u32 func_02017988(void *,u32);
void func_021BC24C(void *unused,void *a,int b) { u32 t=0; int r; if(func_02017E1C(a,5,0)==0x1ED) { t=func_02017E1C(a,0x6F,t); r=func_02019CF8(b); if(t!=r)func_02017988(a,r); } }
