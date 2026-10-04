/*
 * function: func_021BADE8
 * address: 0x021BADE8
 * packet: pkt_ov110_021BADE8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201C6C4 0x0201C6C4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct Descriptor;
struct Cfg;
extern void *func_02045770(struct Descriptor *);
typedef unsigned int   u32;
struct PrintSys;
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern u8 func_02045730(struct Descriptor *);
extern void func_02041B6C(unsigned);
void func_021BADE8(u8 *p) { struct Descriptor *q; if(*(int *)(p+0x70)!=0 && func_0201C6C4((struct PrintSys *)(*(unsigned *)(p+0x7c)),(void *)((unsigned)func_02045770(*(struct Descriptor **)(p+0x6c))))==0) { q=*(struct Descriptor **)(p+0x6c); func_02045334(q);func_02045374((struct Cfg *)q);func_02041B6C(func_02045730(q));*(int *)(p+0x70)=0; } }
