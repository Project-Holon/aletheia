/*
 * function: func_02072F5C
 * address:  0x02072F5C
 * packet:   pkt_02072F5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02075BAC  0x02075BAC  arm
 *
 * Wave 17 lane untried_small. Callee arity read from func_02075BAC's body
 * (three parameters, r2 stored to +0x0C): the wrapper forwards its own third
 * parameter untouched, so r0..r2 are all live and the null test's load lands
 * in r3, the register the earlier two-parameter spellings could not reach.
 * The re-load after the null test is the volatile slot.
 */

typedef unsigned int  u32;
typedef unsigned char u8;

typedef struct Obj02072F5C {
    u8  unk00[0x1c];
    u32 env[4];
    u8  state;
} Obj02072F5C;

struct Obj02075BAC;
extern void func_02075BAC(struct Obj02075BAC *o, u32 a, u32 b);

void func_02072F5C(Obj02072F5C *volatile *pp, u32 a, u32 b)
{
    Obj02072F5C *o;

    if (*pp == 0) {
        return;
    }
    o = *pp;
    if (o->state == 2) {
        return;
    }
    func_02075BAC((struct Obj02075BAC *)o->env, a << 8, b);
}
