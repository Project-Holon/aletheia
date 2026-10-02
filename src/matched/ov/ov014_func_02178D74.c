/*
 * function: func_02178D74
 * address: 0x02178D74
 * packet: pkt_ov014_02178D74
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 02178D9A precede labelled 02178D9C.
 * symbols:
 *   func_0217814C 0x0217814C thumb ov014
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef void (*Cb)(int);
extern void func_0217814C(int);
void func_02178D74(u8 *p) {
 int v = *(u16 *)(p + 2);
 if (v != 0 && v != 15) { func_0217814C(v); }
 else { Cb cb = *(Cb *)(p + 0x20); if (cb != 0) cb(v == 0); }
}
