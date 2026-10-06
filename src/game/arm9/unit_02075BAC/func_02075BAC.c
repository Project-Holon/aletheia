/*
 * function: func_02075BAC
 * address:  0x02075BAC
 * packet:   pkt_02075BAC
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02075BD4  0x02075BD4  arm
 *
 * Wave 17 lane untried_small. The pkt_02073098 cluster's front end: under
 * dsi/1.1p1 the zero for +0x08 is hoisted above the +0x0C store (9 out);
 * ../2.0/sp2 keeps it after, as the image does, the same pin that closes
 * func_02072EA8. func_02075BD4 reads only r0 (its body loads +0x08/+0x0C of
 * the record before touching r1/r2), so it is declared with one parameter.
 */

typedef unsigned int u32;

typedef struct Obj02075BAC {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0c;
} Obj02075BAC;

typedef signed int     s32;
struct Obj;
extern s32 func_02075BD4(struct Obj *o);

void func_02075BAC(Obj02075BAC *o, u32 a, u32 b)
{
    o->unk00 = func_02075BD4((struct Obj *)o);
    o->unk04 = a;
    o->unk0c = b;
    o->unk08 = 0;
}
