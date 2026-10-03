/*
 * function: func_021C4564
 * address: 0x021C4564
 * packet: pkt_ov127_021C4564
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204AC18 0x0204AC18 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int func_0204AC18(void *,u32,u32,u16,u16,u16,u16);
void func_021C4564(u8 *p,u32 a,u32 b,u32 heap) { *(u32 *)(p+756)=func_0204AC18(*(void **)(p+764),0,a,b,0,8,heap); }
