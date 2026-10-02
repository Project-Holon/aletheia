/*
 * function: func_021BA450
 * address: 0x021BA450
 * packet: pkt_ov072_021BA450
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA774 0x021BA774 thumb ov072
 *   func_0204B404 0x0204B404 arm
 */
typedef short s16;
typedef struct { s16 x; s16 y; } Pos;
extern int func_021BA774(void *p, int i);
extern int func_0204B404(int obj, Pos *pos, int c);
void func_021BA450(int *p, int *b) { Pos pos; if(p[5]) { pos.x=b[0]+func_021BA774((void *)p[5],4); pos.y=b[1]+func_021BA774((void *)p[5],5); func_0204B404(p[1],&pos,0); } }
