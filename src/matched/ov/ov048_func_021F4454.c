/*
 * function: func_021F4454
 * address: 0x021F4454
 * packet: pkt_ov048_021F4454
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Post-increment in the table subscript schedules the counter update before the call.
 * symbols:
 *   func_021F3CB0 0x021F3CB0 thumb ov048
 *   func_021F440C 0x021F440C thumb ov048
 *   d_021F4E84 0x021F4E84 data a4
 */
extern int *func_021F3CB0(int *p);
extern void func_021F440C(int *p,int *q,int i);
extern const int d_021F4E84[];
void func_021F4454(int *p) { int i; int *q; i=0; q=func_021F3CB0(p); while(q && i<4) {func_021F440C(p,q,d_021F4E84[i++]);q=func_021F3CB0(p);} }
