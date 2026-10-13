/*
 * function: HAND_ITEM_WhiteHerbCheckOnStatChange
 * address: 0x021DE270
 * packet: pkt_ov093_021DE270
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two-byte alignment padding at 021DE29E.
 * interface: BTL_SERVER_FLOW_GetPokeParam leaves r0 live for the following call; r1 carries c.
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_HasLoweredStatStage 0x021D5D68 thumb ov093
 *   HAND_ITEM_PushUseItem 0x021DD044 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
typedef signed char    s8;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_HasLoweredStatStage(s8 *p);
extern void HAND_ITEM_PushUseItem(void *, void *, int);
void HAND_ITEM_WhiteHerbCheckOnStatChange(int a, void *b, int c) { if(c == BTL_EVENT_GetVar(2)) { if(BTL_POKEPARAM_HasLoweredStatStage(BTL_SERVER_FLOW_GetPokeParam(b,c))) HAND_ITEM_PushUseItem((void *)a,b,c); } }
