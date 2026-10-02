/*
 * function: func_02173248
 * address: 0x02173248
 * packet: pkt_ov012_02173248
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0217325C 0x0217325C thumb ov012
 */
typedef unsigned char u8;
typedef struct Rec { u8 b[0x64]; } Rec;
extern void func_0217325C(u8 *self, Rec *out);
Rec *func_02173248(u8 *p) { func_0217325C(p, (Rec *)(p + 0x28ac)); return (Rec *)(p + 0x28ac); }
