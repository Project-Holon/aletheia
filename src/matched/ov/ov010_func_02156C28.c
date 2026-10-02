/*
 * function: func_02156C28
 * address: 0x02156C28
 * packet: pkt_ov010_02156C28
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov133_id 0x00000085 data
 */
typedef unsigned int u32;
extern void func_020307B0(void *);
extern void func_020315D4(void *);
extern void func_020306F0(int);
extern void func_02034A5C(u32);
extern char ov133_id[];
int func_02156C28(void *a, int b, int c, void **d) { func_020307B0(*d); func_020315D4(a); func_020306F0(0x2d); func_02034A5C((u32)ov133_id); return 1; }
