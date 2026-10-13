/*
 * function: BTL_HANDLER_ITEM_MentalHerbCheckCondition
 * address: 0x021DE31C
 * packet: pkt_ov093_021DE31C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two-byte alignment padding at 021DE34A.
 * interface: func_021C7CF4 leaves r0 live for the following call; r1 carries c.
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   BTL_CALC_FindMajorSick 0x021D7E10 thumb ov093
 *   BTL_HANDLER_ITEM_PushUseItem 0x021DD044 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
extern void *func_021C7CF4(int *p, int i);
struct Unk021D62A8;
extern int BTL_CALC_FindMajorSick(struct Unk021D62A8 *);
extern void BTL_HANDLER_ITEM_PushUseItem(void *, void *, int);
void BTL_HANDLER_ITEM_MentalHerbCheckCondition(int a, void *b, int c) { if(c == BTL_EVENT_GetVar(2)) { if(BTL_CALC_FindMajorSick(func_021C7CF4(b,c))) BTL_HANDLER_ITEM_PushUseItem((void *)a,b,c); } }
