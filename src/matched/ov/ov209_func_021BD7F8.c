/*
 * function: func_021BD7F8
 * address: 0x021BD7F8
 * packet: pkt_ov209_021BD7F8
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BD984 0x021BD984 thumb ov209
 *   func_021BD9B4 0x021BD9B4 thumb ov209
 *   func_021BDC08 0x021BDC08 thumb ov209
 *   func_021BE010 0x021BE010 thumb ov209
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct R;
extern void func_021BD984(char *);
extern void func_021BD9B4(struct R *p);
extern void func_021BDC08(char *);
extern void func_021BE010(char *);extern void BG_SYS_SetMainPlaneVisible(u32,u32),BG_SYS_SetSubPlaneVisible(u32,u32);
void func_021BD7F8(char *p) {func_021BD984(p);func_021BD9B4((struct R *)p);func_021BDC08(p);func_021BE010(p);BG_SYS_SetMainPlaneVisible(16,1);BG_SYS_SetSubPlaneVisible(16,1);}
