/*
 * function: GURU2_RECEIPT_StateIdleStart
 * address: 0x021DD7E4
 * packet: pkt_ov137_021DD7E4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: nested explicit empty then/else-call plus outer else-call preserves the b-to-next at +0x1c; goto spelling DIFF12/38B.
 * abi: 021DD802 visibly reloads p into r0 for 021DE350; retain that argument despite its empty matched body.
 * symbols:
 *   GURU2_RECEIPT_HandleKeys 0x021DD80C thumb ov137
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   GURU2_RECEIPT_CountMembers 0x021DE220 thumb ov137
 *   GURU2_RECEIPT_Noop2 0x021DE350 thumb ov137
 */
extern void GURU2_RECEIPT_HandleKeys(char *);
typedef unsigned short u16;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern int GURU2_RECEIPT_CountMembers(void *);
extern void GURU2_RECEIPT_Noop2(char *);
int GURU2_RECEIPT_StateIdleStart(char *p,int a) {GURU2_RECEIPT_HandleKeys(p);if(GFL_NET_SYSTEM_GetCurrentAid()==0) {if(GURU2_RECEIPT_CountMembers(p)==1) {} else GURU2_RECEIPT_Noop2(p);}else GURU2_RECEIPT_Noop2(p);return a;}
