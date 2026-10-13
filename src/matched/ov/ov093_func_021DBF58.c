/*
 * function: func_021DBF58
 * address: 0x021DBF58
 * packet: pkt_ov093_021DBF58
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   func_021DBFD4 0x021DBFD4 thumb ov093
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern int func_021DBFD4(unsigned short);
extern int BTL_EVENT_OverwriteVar(int,unsigned int);
void func_021DBF58(int a,int b,int c) { if(c==BTL_EVENT_GetVar(3) && func_021DBFD4(BTL_EVENT_GetVar(0x12))) BTL_EVENT_OverwriteVar(0x41,1); }
