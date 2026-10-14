/*
 * function: GURU2_RECEIPT_StateEndSession
 * address: 0x021DE060
 * packet: pkt_ov137_021DE060
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_Start 0x0202208C thumb
 *   GURU2_RECEIPT_Noop 0x021DD924 thumb ov137
 */
#include "../include/Obj23727.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern void GURU2_RECEIPT_Noop(char *);
int GURU2_RECEIPT_StateEndSession(char *p) {WIPE_SYS_Start(0,0,0,0,16,1,114);((struct Obj23727 *)p)->f8=1;GURU2_RECEIPT_Noop(p);return 3;}
