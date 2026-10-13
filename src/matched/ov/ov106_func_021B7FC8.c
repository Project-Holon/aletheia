/*
 * function: func_021B7FC8
 * address: 0x021B7FC8
 * packet: pkt_ov106_021B7FC8
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte alignment padding, no follower.
 * symbols:
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bank;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void func_02082BCC(void *,int,int);
void func_021B7FC8(void **p) { CLACT_DeleteUnit(*p); CLACT_ExitSystem(); func_02082BCC(p,0,20); }
