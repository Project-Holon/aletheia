/*
 * function: func_021B732C
 * address: 0x021B732C
 * packet: pkt_ov101_021B732C
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_020490F4 0x020490F4 arm
 * CLACT_RegisterPaletteEx 0x0204AC18 arm
 * CLACT_RegisterCharacter 0x0204A6C8 arm
 * CLACT_RegisterCellAnim 0x0204AF28 arm
 * ARC_TOOL_DeleteHandle 0x02049238 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int CLACT_RegisterPaletteEx(void *,unsigned,unsigned,u16,u16,u16,unsigned);
extern int CLACT_RegisterCharacter(void *,unsigned,unsigned,unsigned,unsigned);
extern int CLACT_RegisterCellAnim(void *,unsigned,unsigned,unsigned);
extern void ARC_TOOL_DeleteHandle(void *);
void func_021B732C(int *p,unsigned b,int c,int unused,int unused2,u8 d,unsigned e) {
 void *q;
 q=func_020490F4(0x5e,e);
 p[12]=CLACT_RegisterPaletteEx(q,0x29,b,d<<5,0,1,e);
 p[13]=CLACT_RegisterCharacter(q,0x28,0,b,e);
 p[14]=CLACT_RegisterCellAnim(q,0x27,0x26,e);
 ARC_TOOL_DeleteHandle(q);
}
