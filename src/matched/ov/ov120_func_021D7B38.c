/*
 * function: func_021D7B38
 * address: 0x021D7B38
 * packet: pkt_ov120_021D7B38
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020456F8 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020452E8 0x020452E8 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_0201F7A8(void *,u32);
extern void func_020456F8(void *);
extern void func_02041B6C(u32);
extern void func_020452E8(void *);
void func_021D7B38(char *p) { if(*(void **)(p+0x30)) { func_0201F7A8(*(void **)(p+0x30),2); func_020456F8(*(void **)(p+0x30)); func_02041B6C(1); func_020452E8(*(void **)(p+0x30)); *(void **)(p+0x30)=0; } }
