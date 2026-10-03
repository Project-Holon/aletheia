/*
 * function: func_0216AF3C
 * address:  0x0216AF3C
 * packet:   pkt_0216AF3C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Unblocked by matching func_0217688C (ov011, EXACT): the +0032 call site now
 * attests as `matched`.
 * 
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200E0B0  0x0200E0B0  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02012FB0  0x02012FB0  thumb
 *   func_0217688C  0x0217688C  thumb  ov011
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;

extern void *func_0215A5DC(void *a0);
extern void *func_0215A5E4(void *a0);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200E0B0(void *p);
struct Ctx;
extern u32 func_02012138(const struct Ctx *p);
extern int func_02158344(int a0);
extern int func_02012FB0(unsigned char *base);
extern int func_0217688C();

void func_0216AF3C(int a0)
{
    int a1;
    int t4;
    int t5;
    void *c;
    void *e;
    void *w;

t5 = a0 + 0;
    c = func_0215A5DC((void *)a0);
loc_0216AF44:
a0 = t5 + 0;
    e = func_0215A5E4((void *)a0);
loc_0216AF4C:
    w = func_02012EBC(e);
loc_0216AF52:
    func_0200E0B0(w);
loc_0216AF56:
    a0 = func_02012138(c);
loc_0216AF5C:
    a0 = func_02158344(a0);
loc_0216AF60:
t4 = a0 + 0;
    if (t4 == 0) goto loc_0216AF72;
loc_0216AF64:
    a0 = func_02012FB0(e);
loc_0216AF6A:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0217688C(a0, a1);
loc_0216AF72:
    return;}
