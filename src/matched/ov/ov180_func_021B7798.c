/*
 * function: func_021B7798
 * address: 0x021B7798
 * packet: pkt_ov180_021B7798
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Add the far offset before the index; see the far-offset-before-the-index idiom.
 * symbols:
 *   func_0202570C 0x0202570C thumb
 *   func_020437AC 0x020437AC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Grid;struct Obj020437AC;
extern void func_0202570C(struct Grid *);
extern void func_020437AC(struct Obj020437AC *);
void func_021B7798(u8 *p,int n) { if(*(void **)((u32)p+0x9120+(u32)n*8)) { func_0202570C(*(struct Grid **)((u32)p+0x9120+(u32)n*8)); func_020437AC(*(struct Obj020437AC **)((u32)p+0x9124+(u32)n*8)); *(u32 *)((u32)p+0x9120+(u32)n*8)=0; } }
