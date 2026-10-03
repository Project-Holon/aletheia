/*
 * function: func_021BF228
 * address: 0x021BF228
 * packet: pkt_ov204_021BF228
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020310C4 0x020310C4 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Tcbl;struct PrintSys;
extern void func_020310C4(struct Tcbl*);
extern u32 func_0201C4E4(struct PrintSys*);
void func_021BF228(u8*p){func_020310C4(*(struct Tcbl**)(p+24));func_0201C4E4(*(struct PrintSys**)(p+4));}
