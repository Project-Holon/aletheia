/*
 * function: func_021C5370
 * address: 0x021C5370
 * packet: pkt_ov127_021C5370
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C4994 0x021C4994 thumb ov127
 *   d_021C607C 0x021C607C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int (*Callback)(void *,void *,void *,const u8 *,void *);
extern const Callback d_021C607C[];
extern char *func_021C4994(unsigned *p, unsigned id);
int func_021C5370(void *a,void *b,const u8 *desc,void *out) { return d_021C607C[*(u16 *)desc](func_021C4994(b,desc[3]),a,b,desc,out); }
