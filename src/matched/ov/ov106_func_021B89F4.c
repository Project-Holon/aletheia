/*
 * function: func_021B89F4
 * address: 0x021B89F4
 * packet: pkt_ov106_021B89F4
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_020437AC 0x020437AC arm
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj020437AC;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32);
extern void func_0204AFD8(u32);
extern void func_020437AC(struct Obj020437AC *);
extern void func_02082BCC(void *,int,int);
void func_021B89F4(u8 *p) { int i; for(i=0;i<2;i++) func_0204B3B4(*(void **)(p+8+i*4)); func_0204A8D4(*(u32 *)(p+20)); func_0204AFD8(*(u32 *)(p+24)); func_020437AC(*(struct Obj020437AC **)(p+4)); func_02082BCC(p,0,32); }
