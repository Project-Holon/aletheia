/*
 * function: TOWNMAP_GRH_ExitTextBox
 * address: 0x021BB42C
 * packet: pkt_ov072_021BB42C
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   MI_CpuFill8 0x02082BCC arm
 */
struct Descriptor;
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void MI_CpuFill8(void *p,int v,int n);
void TOWNMAP_GRH_ExitTextBox(void **p) { STRBUF_Delete(p[1]); BMP_WIN_Delete(p[0]); MI_CpuFill8(p,0,0x10); }
