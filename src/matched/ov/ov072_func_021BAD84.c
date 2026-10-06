/*
 * function: func_021BAD84
 * address: 0x021BAD84
 * packet: pkt_ov072_021BAD84
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BA774 0x021BA774 thumb ov072
 *   func_0204B404 0x0204B404 arm
 */
typedef short s16;
typedef struct { s16 x; s16 y; } Pos;
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern int func_021BA774(char *p, int i);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
void func_021BAD84(int *p, int *b) { Pos pos; pos.x=b[0]+func_021BA774((char *)p,2); pos.y=b[1]+func_021BA774((char *)p,3); if(p[0]) func_0204B404((struct Obj *)p[0],(const struct Vec2 *)(&pos),0); }
