/*
 * function: func_021CC974
 * address: 0x021CC974
 * packet: pkt_ov093_021CC974
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef struct { unsigned low:28, a:1, b:1, c:1, d:1; } Word;
void func_021CC974(Word *p,int flag) { if(flag) {p->a=1;p->b=1;} else p->a=0; p->c=1; }
