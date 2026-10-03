/*
 * function: func_021BC458
 * address: 0x021BC458
 * packet: pkt_ov110_021BC458
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after return.
 * symbols:
 *   func_021BF708 0x021BF708 thumb ov110
 *   func_02045A90 0x02045A90 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void *func_021BF708(u8 *,u32);
struct U16Vec;
extern u16 *func_02045A90(struct U16Vec *vec);
void func_021BC458(u8 *p,u8 *a) { *(void **)p=func_021BF708(*(u8 **)(a+4),42); *(u16 **)(p+4)=func_02045A90(*(void **)p); if(**(u16 **)(p+4)==0xF000) *(int *)(p+8)=1; else *(int *)(p+8)=0; }
