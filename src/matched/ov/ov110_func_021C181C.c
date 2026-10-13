/*
 * function: func_021C181C
 * address: 0x021C181C
 * packet: pkt_ov110_021C181C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   MI_CpuFill8 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bank;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void MI_CpuFill8(void *,int,u32);
void func_021C181C(void **p) { CLACT_DeleteUnit(*p); CLACT_ExitSystem(); MI_CpuFill8(p,0,4); }
