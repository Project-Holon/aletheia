/*
 * function: func_021DA958
 * address: 0x021DA958
 * packet: pkt_ov121_021DA958
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0202570C 0x0202570C thumb
 *   func_020437AC 0x020437AC arm
 *   func_02045808 0x02045808 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Grid;
struct Obj020437AC;
struct U16Vec;
extern void func_0202570C(struct Grid *g);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_020307B0(void *);
void func_021DA958(u8 *p) { func_0202570C(*(void **)(p+28)); func_020437AC(*(void **)p); func_02045808(*(void **)(p+24)); func_020307B0(p); }
