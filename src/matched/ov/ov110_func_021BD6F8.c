/*
 * function: func_021BD6F8
 * address: 0x021BD6F8
 * packet: pkt_ov110_021BD6F8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef signed char s8;
typedef short s16;
typedef struct { s16 a; s8 b,c; } State;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u8 func_02024584(u32 i);
extern void func_02024598(void *,int,int);
void func_021BD6F8(State *p,void *out) {
 p->b--;
 if(p->b<0) { p->a--; if(p->a<0) p->a=4; p->c=func_02024584(p->a); p->b=p->c-1; }
 func_02024598(out,p->a,p->b);
}
