/*
 * function: func_021DBF28
 * address: 0x021DBF28
 * packet: pkt_ov093_021DBF28
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   func_021DBFD4 0x021DBFD4 thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern int func_021DBFD4(unsigned short);
extern void BTL_EVENT_MultiplyVar(int,int);
void func_021DBF28(int a,int b,int c) { if(c==BTL_EVENT_GetVar(3) && func_021DBFD4(BTL_EVENT_GetVar(0x12))) BTL_EVENT_MultiplyVar(0x31,0x14cd); }
