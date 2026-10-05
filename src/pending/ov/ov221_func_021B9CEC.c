/*
 * function: func_021B9CEC
 * address: 0x021B9CEC
 * packet: pkt_ov221_021B9CEC
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note: 2026-10-05 recoup P21L1: DIFF 4/76 B. Residue: pool base of d_021BA140 sits in r2 and the first
 *   coordinate in r1 in the original; build has base r1, coordinate r2. Same size, same branches, 4 relocations resolved.
 *   Tried (all unchanged 4 B): extern struct Vec2 with field copies; short[2] table with short[2] local; const extern
 *   (17 B worse); table through a (short *) local (47 B worse); struct copy v = d (66 B worse); int temps; y read first;
 *   v at function scope; q = &v pointer local; extra v.y -= 64 as a second statement (32 B worse); all six per-function
 *   pragmas (opt_lifetimes, opt_propagation, opt_common_subs, opt_dead_assignments, scheduling, peephole) off.
 *   Callees checked: func_02040618(int,int,int) and func_0204B404(Obj *, Vec2 *, u32) as in matched ov119/ov133/ov121; both void in all callers.
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
        func_02040618(1,3,0x40);
        func_02040618(2,3,0x40);
        v.x=d_021BA140.x;
        v.y=d_021BA140.y-64;
        func_0204B404(*(struct Obj **)(p+0x54),&v,0);
        p[0x44]=0;
    }
}
