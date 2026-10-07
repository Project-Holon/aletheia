/*
 * file:     event_poke_status_p03.c
 * unit:     yes
 * function: func_021593DC, func_021593F0, func_02159404, func_02159420, func_0215942C, func_0215944C
 * address:  0x021593DC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02011330  0x02011330  thumb
 *   func_0201137C  0x0201137C  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02011398  0x02011398  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 */
struct Stream;
struct Ring;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern u16 func_02011330(struct Stream *s);
extern int func_0201137C();
extern unsigned int func_02159B10(void *, void *);
extern u32 func_02011398(struct Ring *r);
extern u16 *func_02159AE8(void *a0, void *a1);
int func_021593DC(int a0, int a1);
int func_021593F0(int a0, int a1);
int func_02159404(int a0, int a1);
int func_02159420(int a0);
int func_0215942C(void *a0);
int func_0215944C(void *a0);


int func_021593DC(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
    a0 = func_02011330((struct Stream *)a0);
loc_021593E4:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0201137C(a0, a1);
loc_021593EC:
a0 = 0;
    return a0;}


int func_021593F0(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_021593F8:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0201137C(a0, a1);
loc_02159400:
a0 = 0;
    return a0;}


int func_02159404(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    u16 *q;

t5 = a0 + 0;
t6 = a1 + 0;
    a0 = func_02011398((struct Ring *)a0);
loc_0215940E:
t4 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_02159418:
*q = t4;
a0 = 0;
    return a0;}


int func_02159420(int a0)
{

    a0 = func_02011398((struct Ring *)a0);
loc_02159426:
a0 = 0;
    return a0;}


/*
 * One arm9 getter read twice, folded with '+', written back
 * through the arm9 setter.
 */
int func_0215942C(void *a0)
{
    int v = func_02011398(a0);
    int w = func_02011398(a0);

    func_0201137C(a0, w + v);

    return 0;
}


/*
 * One arm9 getter read twice, folded with '-', written back
 * through the arm9 setter.
 */
int func_0215944C(void *a0)
{
    int v = func_02011398(a0);

    func_0201137C(a0, func_02011398(a0) - v);

    return 0;
}
