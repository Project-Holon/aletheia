/*
 * function: func_021D75F4
 * address: 0x021D75F4
 * packet: pkt_ov120_021D75F4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing 2-byte alignment padding only.
 * symbols:
 *   func_02040618 0x02040618 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_02040618(u32,u32,u32);
void func_021D75F4(char *p) { if(*(u32 *)(p+0x114)) { func_02040618(2,3,*(u32 *)(p+0x110)); *(u32 *)(p+0x110)+=1; } }
