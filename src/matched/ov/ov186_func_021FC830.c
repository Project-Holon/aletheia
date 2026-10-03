/*
 * function: func_021FC830
 * address: 0x021FC830
 * packet: pkt_ov186_021FC830
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void*func_02045770(void*);
extern int func_0201C6C4(void*,void*);
extern void func_02045334(void*);
int func_021FC830(u8*p){void*owner=*(void**)(p+8);if(p[4]){if(!func_0201C6C4(owner,func_02045770(*(void**)p))){func_02045334(*(void**)p);p[4]=0;}}if(!p[4])return 1;return 0;}
