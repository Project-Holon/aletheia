/*
 * function: func_021FADF0
 * address: 0x021FADF0
 * packet: pkt_ov135_021FADF0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FA9C8 0x021FA9C8 thumb ov135
 *   func_0204B878 0x0204B878 arm
 *   func_021F4FF4 0x021F4FF4 thumb ov135
 *   func_0202CD64 0x0202CD64 thumb
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_021FA9C8(u8 *,int,int);
extern void func_0204B878(void *,u16);
extern void func_021F4FF4(u32,u32,u32);
extern void func_0202CD64(void *,u32,s8,s8,u8);
void func_021FADF0(u8 *p) {func_021FA9C8(p,4,32);func_0204B878(*(void **)(p+8),18);func_021F4FF4(*(u32 *)(p+8),144,40);func_0202CD64(*(void **)(p+24),0,-4,0,4);*(u32 *)(p+72)=1;*(u32 *)(p+76)=7;*(s16 *)(p+56)=-1;}
