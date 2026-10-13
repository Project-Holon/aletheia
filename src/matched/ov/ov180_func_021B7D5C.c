/*
 * function: func_021B7D5C
 * address: 0x021B7D5C
 * packet: pkt_ov180_021B7D5C
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * EXACT* tail: two zero alignment bytes after the function.
 * symbols:
 *   func_0204EA38 0x0204EA38 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   func_021B73B0 0x021B73B0 thumb ov180
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u32 func_0204EA38(void);
extern void BG_SYS_SetMainPlaneVisible(u32,u32);
extern void func_021B73B0(char *p);
void func_021B7D5C(void *p) { if(func_0204EA38()==1) BG_SYS_SetMainPlaneVisible(16,0); else BG_SYS_SetMainPlaneVisible(16,1); func_021B73B0(p); }
