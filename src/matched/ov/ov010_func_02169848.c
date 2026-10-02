/*
 * function: func_02169848
 * address: 0x02169848
 * packet: pkt_ov010_02169848
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte alignment padding.
 * output proof: func_0207CA00 stores buf[0:2] at 0207CA20/0207CA28;
 * callback receives that initialized three-word vector, with original arity.
 * address arithmetic: unsigned 32-bit index scaling and base addition
 * preserve the original lsls/adds wraparound without an invented index bound.
 * symbols:
 *   func_0207CA00 0x0207CA00 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef void (*Cb)(void *,u32,u32 *,u32,u32);
extern void func_0207CA00(u32,void *,u32 *);
void func_02169848(void *a,u8 *b,u32 c,u32 d) { u32 buf[3]; Cb cb; func_0207CA00(c,b+4,buf); cb=*(Cb *)(*(u32 *)(b+0x28)+*(u32 *)(b+0x18)*16u+12u); cb(a,*(u32 *)(b+0xd4),buf,d,*(u32 *)(b+8)); }
