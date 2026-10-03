/*
 * function: func_021D61A4
 * address: 0x021D61A4
 * packet: pkt_ov175_021D61A4
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D9EA0 0x021D9EA0 thumb ov175
 *   func_0200FBB0 0x0200FBB0 thumb
 *   func_021E8AA8 0x021E8AA8 thumb ov177
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021D9EA0(void *),func_021E8AA8(void *);
extern int func_0200FBB0(void);
void func_021D61A4(void *obj,int unused,u8 *p) { *(u32 *)(*(u8 **)(p+64)+4)=3; if(*(void **)(p+48)) { func_021D9EA0(*(void **)(p+48)); *(u32 *)(p+48)=0; } func_0200FBB0(); func_021E8AA8(obj); }
