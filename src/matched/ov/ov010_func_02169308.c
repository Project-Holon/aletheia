/*
 * function: func_02169308
 * address: 0x02169308
 * packet: pkt_ov010_02169308
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * address arithmetic: unsigned 32-bit index scaling and base addition
 * preserve the original lsls/adds wraparound without an invented index bound.
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef void (*Cb)(u8 *, u32);
void func_02169308(u8 *p) { Cb cb; if (*(u16 *)(p+0xb0)) { cb = *(Cb *)(*(u32 *)(p+0x28)+*(u32 *)(p+0x18)*16u+4u); if(cb) cb(p,*(u32 *)(p+0xd8)); } }
