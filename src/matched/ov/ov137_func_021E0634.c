/*
 * unit: no
 * function: GURU2_MAIN_AddAngle
 * address: 0x021E0634
 * packet: pkt_ov137_021E0634
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_MAIN_AddAngleWrapped 0x021E15DC thumb ov137
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct Descriptor;struct Cfg;struct CharBuf;struct Bank;struct Util;struct Setup;struct Ctx;
extern void GURU2_MAIN_AddAngleWrapped(int *,int);
void GURU2_MAIN_AddAngle(u8 *p,int a){GURU2_MAIN_AddAngleWrapped((int *)(p+0x3c),a);}
