/*
 * function: func_021BFD94
 * address: 0x021BFD94
 * packet: pkt_ov110_021BFD94
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B454 0x0204B454 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct Vec2 { s16 x,y; } Vec2;
extern u32 func_0204B3F4(void *);
extern void func_0204B454(void *,Vec2 *,u32);
u32 func_021BFD94(u8 *p,Vec2 *out) { u32 result; result=func_0204B3F4(*(void **)(p+0x1c)); func_0204B454(*(void **)(p+0x1c),out,0); return result; }
