/*
 * unit: no
 * function: func_021DFF44
 * address: 0x021DFF44
 * packet: pkt_ov137_021DFF44
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocking: ABS32 data gClActorInitParam at +0x20 has no witness outside 021DFF44..021DFF70; ROM pool at021DFF64 is020A1448. Alignment-only data a4 hint already used; one recheck and tu --suggest-split remain MATCH with zero witnesses. Both ARM9 callees resolve matched.
 * symbols:
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   gClActorInitParam 0x020A1448 data a4
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct Descriptor;struct Cfg;struct CharBuf;struct Bank;struct Util;struct Setup;struct Ctx;
extern void CLACT_InitSystem(const struct Cfg *,u32,u32);
extern struct Bank *CLACT_CreateUnit(int,u8,u32);
extern const struct Cfg gClActorInitParam;
void func_021DFF44(u8 *p){CLACT_InitSystem(&gClActorInitParam,0x021E1EA4,114);*(struct Bank **)(p+0xd68)=CLACT_CreateUnit(30,1,114);}
