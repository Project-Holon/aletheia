/*
 * function: func_021BD6B4
 * address: 0x021BD6B4
 * packet: pkt_ov110_021BD6B4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef struct { s16 a; s8 b; s8 c; } State;
typedef unsigned int   u32;
extern u8 func_02024584(u32 i);
extern void func_02024598(void *, int, int);
void func_021BD6B4(State *p, void *out) {
    p->b++;
    if (p->b >= p->c) {
        p->b = 0;
        p->a++;
        if (p->a >= 5) p->a = 0;
        p->c = func_02024584(p->a);
    }
    func_02024598(out, p->a, p->b);
}
