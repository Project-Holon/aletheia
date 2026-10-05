/*
 * function: func_021B9CEC
 * address: 0x021B9CEC
 * packet: pkt_ov221_021B9CEC
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: final push 2026-10-05 G1L9: EXACT. The table is read through a block-local short pointer, the same form as the twin ov222 021B9D84 (an integer address local also matched)
 *   and both halfwords are read through it; the plain extern field reads gave base r1 / x r2 (4 B off). Earlier DIFF tries
 *   (struct copy, short[2], const, pragmas, byte-offset casts, etc.) are superseded. Also unchanged 4 B this pass: brace
 *   initialiser, inline setter, int y temp, short x/y locals, d[0] array extern, struct pointer local, u16 local struct.
 *   Idiom: a pool word reloaded before every field access (u32 gb = (u32)&d_X, read through a cast) from the wave brief.
 * symbols:
 *   func_02040618 0x02040618 arm
 *   func_0204B404 0x0204B404 arm
 *   d_021BA140 0x021BA140 data a2
 */
struct Obj;
struct Vec2 { short x,y; };
extern struct Vec2 d_021BA140;
extern void func_02040618(int,int,int);
extern void func_0204B404(struct Obj *,struct Vec2 *,unsigned);
void func_021B9CEC(char *p)
{
    if(*(unsigned *)(*(unsigned char **)(p+4)+4)==0) {
        struct Vec2 v;
        short *t;
        func_02040618(1,3,0x40);
        func_02040618(2,3,0x40);
        t=(short *)&d_021BA140;
        v.x=t[0];
        v.y=t[1]-64;
        func_0204B404(*(struct Obj **)(p+0x54),&v,0);
        p[0x44]=0;
    }
}
