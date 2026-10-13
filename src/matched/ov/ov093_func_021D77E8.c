/*
 * function: BTL_EVENT_FindVar
 * address: 0x021D77E8
 * packet: pkt_ov093_021D77E8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
typedef struct { unsigned int count; unsigned short keys[0x60]; int vals[0x60]; int a[0x60]; int b[0x60]; unsigned char c[0x60]; } Tbl;
int BTL_EVENT_FindVar(Tbl *p, int key) { unsigned int i; for (i=p->count; i<0x60 && p->keys[i]!=0; i++) { if(key==p->keys[i]) return i; } return -1; }
