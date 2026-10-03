/*
 * function: func_021BF8BC
 * address: 0x021BF8BC
 * packet: pkt_ov110_021BF8BC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: two trailing zero alignment bytes.
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
struct Obj;
struct U16Vec;
struct Descriptor;
extern void func_0204B3B4(struct Obj *),func_02045808(struct U16Vec *),func_020452E8(struct Descriptor *),func_020307B0(void *);
void func_021BF8BC(u8 *p) {
    if(*(struct Obj **)(p+0x14)) func_0204B3B4(*(struct Obj **)(p+0x14));
    if(*(struct Obj **)(p+0x1c)) func_0204B3B4(*(struct Obj **)(p+0x1c));
    if(*(struct U16Vec **)(p+0x48)) func_02045808(*(struct U16Vec **)(p+0x48));
    func_020452E8(*(struct Descriptor **)(p+0x10));
    func_020452E8(*(struct Descriptor **)(p+0xc));
    func_020307B0(p);
}
