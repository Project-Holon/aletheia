/*
 * function: TOWNMAP_ExitSelection
 * address: 0x021BB204
 * packet: pkt_ov072_021BB204
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Delete 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02082BCC 0x02082BCC arm
 */
struct Descriptor;
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
typedef unsigned int   u32;
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02082BCC(void *p,int v,int n);
void TOWNMAP_ExitSelection(void **p) { STRBUF_Delete(p[1]); func_020452E8(p[0]); func_02082BCC(p,0,0x14); }
