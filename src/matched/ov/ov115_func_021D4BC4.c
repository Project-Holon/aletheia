/*
 * function: func_021D4BC4
 * address: 0x021D4BC4
 * packet: pkt_ov115_021D4BC4
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   func_021D5C70 0x021D5C70 thumb ov115
 *   func_021D426C 0x021D426C thumb ov115
 *   func_021D5D5C 0x021D5D5C thumb ov115
 *   func_021D4644 0x021D4644 thumb ov115
 *   func_02168040 0x02168040 arm ov009
 *   func_021D4AB0 0x021D4AB0 thumb ov115
 */
typedef unsigned char u8; typedef unsigned int u32;
extern u32 WIPE_SYS_EndCheck(void); extern int func_021D5C70(int); extern void func_021D426C(u8 *,u32); extern void *func_021D5D5C(u8 *,int,int,int);
extern int func_021D4644(u8 *); extern int func_02168040(void); extern void func_021D4AB0(u8 *);
void func_021D4BC4(u8 *p) { int x; if(!func_021D4644(p)) { x=func_02168040(); if(x==3) func_021D426C(p,(u32)func_021D4AB0); else if(x==4 || x==0 || x==5) func_021D4644(p); } }
