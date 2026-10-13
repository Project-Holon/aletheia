/*
 * function: func_021C45E0
 * address: 0x021C45E0
 * packet: pkt_ov127_021C45E0
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void CLACT_ReleaseCellAnim(u32);
void func_021C45E0(u8 *p) { int i; for(i=0;i<16;i++){CLACT_ReleaseCellAnim(*(u32 *)(p+i*20+392));*(u32 *)(p+i*20+392)=-1;} }
