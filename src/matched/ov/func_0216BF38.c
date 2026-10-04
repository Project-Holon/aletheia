/*
 * function: func_0216BF38
 * address:  0x0216BF38
 * packet:   pkt_0216BF38
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 60 compiled 58
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200D418  0x0200D418  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0200D468  0x0200D468  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;

extern void *func_0215A5E4(void *a0);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200D418(void *sys);
extern unsigned int func_02159B10(void *, void *);
extern unsigned short *func_02159AE8(void *a0, void *a1);
struct Blk38;
extern u8 func_0200D468(struct Blk38 *p, u32 i);

int func_0216BF38(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    void *t7;
    void *p;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    p = func_0215A5E4((void *)a0);
loc_0216BF44:
    p = func_02012EBC((struct Big *)p);
loc_0216BF48:
    t7 = func_0200D418(p);
loc_0216BF4C:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0216BF56:
a0 = a0 << 0x18;
t4 = (unsigned)a0 >> 0x18;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = (int)func_02159AE8((void *)a0, (void *)a1); /* int-typed on purpose: pointer local changes codegen */
loc_0216BF62:
t5 = a0 + 0;
a1 = t4 + 0;
    a0 = func_0200D468(t7, a1);
loc_0216BF6C:
*(u16 *)((char *)t5) = a0;
a0 = 0;
    return a0;}
