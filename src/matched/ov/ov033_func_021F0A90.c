/*
 * function: func_021F0A90
 * address: 0x021F0A90
 * packet: pkt_ov033_021F0A90
 * region: ov033
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_02024DCC 0x02024DCC thumb
 */
extern void func_0204B3B4(int);
typedef unsigned int   u32;
extern void func_0204AFD8(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_02024DCC(void);
void func_021F0A90(char *p) { unsigned v; func_0204B3B4(*(int *)(p+0x24)); func_0204AFD8(*(int *)(p+0x20)); func_0204A8D4(*(int *)(p+0x1c)); func_0204ADA4(*(int *)(p+0x18)); v=*(unsigned *)(p+0x14); func_0203FB44(4,(unsigned short)v,(unsigned short)(v>>16)); func_02024DCC(); }
