/*
 * function: func_021D6BFC
 * address: 0x021D6BFC
 * packet: pkt_ov093_021D6BFC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D4EFC 0x021D4EFC thumb ov093
 *   func_021D4F84 0x021D4F84 thumb ov093
 *   func_021D50B4 0x021D50B4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S; struct Work;
extern void func_021D4EFC(struct S *,void *,u32,u32);
extern int func_021D4F84(u8 *,void *,int);
extern void func_021D50B4(struct Work *);
struct Flags { u8 pad[0x1b]; u8 low:5; u8 active:1; u8 high:2; };
void func_021D6BFC(u8 *p) { if(!((struct Flags *)p)->active) { func_021D4EFC((struct S *)p,*(void **)p,1,0); func_021D50B4((struct Work *)p); } else { func_021D4F84(p,*(void **)p,0); } }
