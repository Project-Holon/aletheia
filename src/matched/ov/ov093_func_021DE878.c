/*
 * function: BTL_HANDLER_ITEM_SoulDew_BoostSpAttack
 * address: 0x021DE878
 * packet: pkt_ov093_021DE878
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: func_021C7CF4 returns its live r0 here (the matched
 * tail forwarder is declared void); r1 is visibly loaded with c before
 * the call and is retained as an argument, per canonical exceptions.
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_GetSpecies 0x021D5444 thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern void BTL_EVENT_MultiplyVar(int,int);
extern void *func_021C7CF4(int *,int);
typedef unsigned short u16;
struct QF;
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
void BTL_HANDLER_ITEM_SoulDew_BoostSpAttack(int a,int *b,int c) { if(c==BTL_EVENT_GetVar(3)) { if((unsigned int)BTL_POKEPARAM_GetSpecies(func_021C7CF4(b,c))-380<=1) { if(BTL_EVENT_GetVar(26)==2) BTL_EVENT_MultiplyVar(53,6144); } } }
