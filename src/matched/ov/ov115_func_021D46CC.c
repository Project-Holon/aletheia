/*
 * function: func_021D46CC
 * address: 0x021D46CC
 * packet: pkt_ov115_021D46CC
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 *   func_021D5C70 0x021D5C70 thumb ov115
 *   func_021D426C 0x021D426C thumb ov115
 *   func_021D5D5C 0x021D5D5C thumb ov115
 *   func_021D456C 0x021D456C thumb ov115
 *   func_021D5D3C 0x021D5D3C thumb ov115
 */
typedef unsigned char u8; typedef unsigned int u32;
extern int func_020221A4(void); extern int func_021D5C70(int); extern void func_021D426C(u8 *,u32); extern void *func_021D5D5C(u8 *,int,int,int);
extern void func_021D456C(u8 *); extern void func_021D5D3C(int);
void func_021D46CC(u8 *p) { if(func_020221A4() && func_021D5C70(*(int *)(p+0x38))) { *(void **)(p+0x30)=func_021D5D5C(*(u8 **)(p+0x38),0,!*(int *)(*(u8 **)(p+0x40)+4),0); func_021D426C(p,(u32)func_021D456C); } }
