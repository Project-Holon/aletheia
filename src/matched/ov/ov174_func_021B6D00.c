/*
 * function: func_021B6D00
 * address: 0x021B6D00
 * packet: pkt_ov174_021B6D00
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 */
struct Obj;struct Descriptor;extern void func_0204B3B4(struct Obj *);extern void func_0204ADA4(unsigned),func_0204A8D4(unsigned),func_0204AFD8(unsigned);extern void func_020452E8(struct Descriptor *);extern void func_020307B0(void *);
void func_021B6D00(unsigned char *unused,char *p) {func_0204B3B4(*(struct Obj **)(p+40));func_0204B3B4(*(struct Obj **)(p+44));func_0204ADA4(*(unsigned *)(p+28));func_0204A8D4(*(unsigned *)(p+32));func_0204AFD8(*(unsigned *)(p+36));func_020452E8(*(struct Descriptor **)(p+24));if(*(void **)(p+16))func_020307B0(*(void **)(p+16));func_020307B0(p);}
