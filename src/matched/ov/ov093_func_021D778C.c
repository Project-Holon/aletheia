/*
 * function: func_021D778C
 * address: 0x021D778C
 * packet: pkt_ov093_021D778C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_021F3ECC 0x021F3ECC data a4
 */
typedef struct { unsigned int count; unsigned short keys[0x60]; int vals[0x60]; int a[0x60]; int b[0x60]; unsigned char c[0x60]; } Tbl;
extern Tbl g_021F3ECC;
int func_021D778C(int key, int *out) { Tbl *p=&g_021F3ECC; unsigned int i; for(i=p->count; i<0x60; i++) { if(key==p->keys[i]) { *out=p->vals[i]; return 1; } if(p->keys[i]==0) break; } return 0; }
