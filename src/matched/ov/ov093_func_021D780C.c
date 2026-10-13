/*
 * function: BTL_EVENT_ClampVar
 * address: 0x021D780C
 * packet: pkt_ov093_021D780C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef struct { unsigned int count; unsigned short keys[0x60]; int vals[0x60]; int a[0x60]; int b[0x60]; unsigned char c[0x60]; } Tbl;
int BTL_EVENT_ClampVar(Tbl *p, int i, int v) { int hi = p->a[i]; if (hi || p->b[i]) { if (p->b[i] > v) v=p->b[i]; if (hi < v) v=hi; } return v; }
