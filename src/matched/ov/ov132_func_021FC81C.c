/*
 * function: func_021FC81C
 * address: 0x021FC81C
 * packet: pkt_ov132_021FC81C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203A574 0x0203A574 arm
 *   func_0203D378 0x0203D378 arm
 *   d_021FDC38 0x021FDC38 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor; struct Comm;
extern void func_0203A574(u32,u32,u32,u32);
extern u32 func_0203D378(void);
extern char d_021FDC38[];
void func_021FC81C(char *p) { func_0203A574(0x1100,(u32)d_021FDC38,9,(u32)p); if(func_0203D378()==1) *(int *)(p+0x48)=1; else *(int *)(p+0x48)=2; }
