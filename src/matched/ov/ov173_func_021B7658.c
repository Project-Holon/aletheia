/*
 * function: func_021B7658
 * address: 0x021B7658
 * packet: pkt_ov173_021B7658
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   d_021B820C 0x021B820C data a4
 *   d_021B8250 0x021B8250 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cfg;struct Bank;
extern const struct Cfg d_021B820C;
extern u8 d_021B8250[];
extern void CLACT_InitSystem(const struct Cfg *,u32,u32);
extern struct Bank *CLACT_CreateUnit(int,u8,u32);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *);
extern void BG_SYS_SetMainPlaneVisible(u32,u32);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
typedef enum { OFFSET=14 } Offset;
void func_021B7658(u8 *p, void *a1) {Offset off;struct Bank *b;CLACT_InitSystem(&d_021B820C,(u32)d_021B8250,79);off=OFFSET;b=CLACT_CreateUnit(14,0,79);off+=242;*(struct Bank **)(p+off)=b;CLACT_SetUnitDefaultRenderer(b);BG_SYS_SetMainPlaneVisible(16,1);BG_SYS_SetSubPlaneVisible(16,1);}
