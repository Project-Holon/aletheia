/*
 * function: func_0220B52C
 * address: 0x0220B52C
 * packet: pkt_ov207_0220B52C
 * region: ov207
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
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
extern void func_02082BCC(void*,int,u32);
void func_0220B52C(struct Bank**p){CLACT_DeleteUnit(*p);CLACT_ExitSystem();func_02082BCC(p,0,4);}
