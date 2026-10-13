/*
 * function: UNION_SUBDISP_CancelOtherHighlights
 * address: 0x021F0F40
 * packet: pkt_ov031_021F0F40
 * region: ov031
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { u16 cnt; u8 idx; u8 pad; } Slot;
typedef struct { char pad[0x34]; Slot s[3]; } A;
void UNION_SUBDISP_CancelOtherHighlights(A *p, int unused, int idx) { int i; for(i=0;i<3;i++) if(p->s[i].cnt!=0 && idx!=p->s[i].idx) p->s[i].cnt=1; }
