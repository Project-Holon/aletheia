/*
 * function: func_02183E18
 * address:  0x02183E18
 * packet:   pkt_02183E18
 * region:   ov168
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02183D3C   0x02183D3C  thumb
 *   func_02183D34   0x02183D34  thumb
 *   func_02183E60   0x02183E60  thumb
 *   func_0204B878   0x0204B878  arm
 *   func_0204B98C   0x0204B98C  arm
 *
 * Three-state step over the object at *(x+0xC): start on 0, poll on 1,
 *   install 0x2183E60 on 2.
 */


typedef unsigned short u16;
typedef unsigned int   u32;
struct Actor;
struct Obj;
extern unsigned int func_02183D3C(unsigned int *p);
extern void func_02183D34(unsigned int *p, unsigned int v);
extern void func_02183E60(int a, int *state);
extern void func_0204B878(struct Obj *p, u16 value);
extern u32 func_0204B98C(struct Actor *a);

void func_02183E18(int a, int *state)
{
    int x = func_02183D3C((unsigned int *)a);
    switch (*state) {
    case 0:
        func_0204B878((struct Obj *)(*(int *)(x + 0xC)), 1);
        *state = 1;
        break;
    case 1:
        if (func_0204B98C((struct Actor *)(*(int *)(x + 0xC))) == 0)
            *state = 2;
        break;
    case 2:
        func_02183D34((unsigned int *)a, (unsigned int)func_02183E60);
        break;
    }
}
