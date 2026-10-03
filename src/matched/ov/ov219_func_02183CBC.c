/*
 * function: func_02183CBC
 * address: 0x02183CBC
 * packet: pkt_ov219_02183CBC
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02028218 0x02028218 thumb
 *   func_0202822C 0x0202822C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void func_02028218(struct Obj*,u32);
extern void func_0202822C(char*,int);
void func_02183CBC(u8 *p,u32 i){if(*(void**)(p+i*4+0xc05c)){if(i==0){func_02028218(*(struct Obj**)(p+0xc05c),1);return;}if(i==1)func_0202822C(*(char**)(p+0xc060),1);}}
