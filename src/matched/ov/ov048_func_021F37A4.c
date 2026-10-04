/*
 * function: func_021F37A4
 * address: 0x021F37A4
 * packet: pkt_ov048_021F37A4
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02188C80 0x02188C80 thumb ov021
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int     s32;
struct Big;
struct Ctx;
struct Rec94;
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 func_0200B3AC(struct Rec94 *p);
extern u8 *func_0200B3A4(u32,u32);
u8 *func_021F37A4(u32 a) { u32 p; p=(u32)func_02012EC4(func_020120F4(func_02188C80((void *)a))); return func_0200B3A4(p,func_0200B3AC((struct Rec94 *)p)); }
