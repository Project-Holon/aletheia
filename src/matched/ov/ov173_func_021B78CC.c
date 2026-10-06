/*
 * function: func_021B78CC
 * address: 0x021B78CC
 * packet: pkt_ov173_021B78CC
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201BD28 0x0201BD28 thumb
 *   func_020275EC 0x020275EC thumb
 *   func_0204B6F4 0x0204B6F4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
/* The original forwards the full entry r1 without halfword truncation. */
extern u32 func_0201BD28(u16 id, u32 field);
extern u8 func_020275EC(int i);
extern void func_0204B6F4(struct Obj *,u32,u32);
void func_021B78CC(u8 *p, u16 id, u16 i) {u32 n;n=func_0201BD28(id,0);*(u32 *)(p+i*8+320)=n;*(u32 *)(p+i*8+324)=1;func_0204B6F4(*(struct Obj **)(p+(i+8)*4+260),func_020275EC((u8)n),1);}
