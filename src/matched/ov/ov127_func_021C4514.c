/*
 * function: func_021C4514
 * address: 0x021C4514
 * packet: pkt_ov127_021C4514
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing 2-byte alignment padding only.
 * symbols:
 *   func_021C4550 0x021C4550 thumb ov127
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int func_021C4550(int *);
extern void func_0204A8D4(u32);
extern void func_0204ADA4(u32);
extern void func_0204AFD8(u32);
void func_021C4514(char *p) { if(func_021C4550((int *)(p+0x2e0))==1) { func_0204A8D4(*(u32 *)(p+0x2e0)); *(u32 *)(p+0x2e0)=-1; func_0204ADA4(*(u32 *)(p+0x2e4)); *(u32 *)(p+0x2e4)=-1; func_0204AFD8(*(u32 *)(p+0x2e8)); *(u32 *)(p+0x2e8)=-1; } }
