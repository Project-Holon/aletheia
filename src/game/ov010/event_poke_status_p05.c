/*
 * file:     event_poke_status_p05.c
 * unit:     yes
 * function: func_021594E0, func_02159570, func_021595A0
 * address:  0x021594E0
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
 *   func_02011398  0x02011398  thumb
 *   func_02011330  0x02011330  thumb
 *   func_0201137C  0x0201137C  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159B38  0x02159B38  thumb  ov010
 *   func_021589A0  0x021589A0  thumb  ov010
 *   func_0215AA4C  0x0215AA4C  thumb  ov010
 *   func_021587E0  0x021587E0  thumb  ov010
 *   func_0215AA34  0x0215AA34  thumb  ov010
 */
struct Ring;
struct Stream;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

extern u32 func_02011398(struct Ring *r);
extern u16 func_02011330(struct Stream *s);
extern void func_0201137C(struct Ring *r, u32 v);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A5F4(void *p);
extern int func_02159B38(int a0);
extern int func_021589A0(int a, int b, int c);
extern u8 func_0215AA4C(void *p);
extern int func_021587E0(int a, int b);
extern int func_0215AA34(int a0);
int func_021594E0(int p);
int func_02159570(int a0, int a1, int a2);
int func_021595A0(int a0, int a1);


int func_021594E0(int p)
{
    u32 a = func_02011398((struct Ring *)p);
    u32 b = func_02011398((struct Ring *)p);
    int r;
    switch (func_02011330((struct Stream *)p)) {
    case 0: r = (b < a) ? 1 : 0; break;
    case 1: r = (b == a) ? 1 : 0; break;
    case 2: r = (b > a) ? 1 : 0; break;
    case 3: r = (b <= a) ? 1 : 0; break;
    case 4: r = (b >= a) ? 1 : 0; break;
    case 5: r = (b != a) ? 1 : 0; break;
    case 6: r = (b == 1 || a == 1) ? 1 : 0; break;
    case 7: r = (b == 1 && a == 1) ? 1 : 0; break;
    default: r = 0; break;
    }
    func_0201137C((struct Ring *)p, r);
    return 0;
}


int func_02159570(int a0, int a1, int a2)
{
    int t4;
    int t5;
    void *v0;
    void *v1;

t5 = a1 + 0;
t4 = a0 + 0;
a0 = t5 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0215957C:
a0 = t5 + 0;
    v1 = func_0215A5F4((void *)a0);
loc_02159582:
a0 = t4 + 0;
    a0 = func_02011330((struct Stream *)a0);
loc_0215958A:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_02159B38(a0);
loc_02159592:
a1 = a0 + 0;
a2 = t4 + 0;
    a0 = func_021589A0((int)v1, a1, a2);
loc_0215959C:
a0 = 1;
    return a0;}


int func_021595A0(int a0, int a1)
{    int t5;
    void *v0;

t5 = a1 + 0;
a0 = t5 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_021595AA:
a0 = t5 + 0;
    a0 = func_0215AA4C((void *)a0);
loc_021595B2:
a1 = a0 + 0;
    a0 = func_021587E0((int)v0, a1);
loc_021595BA:
    if (a0 != 0) goto loc_021595C8;
loc_021595BE:
a0 = t5 + 0;
    a0 = func_0215AA34(a0);
loc_021595C4:
a0 = 1;
    return a0;
loc_021595C8:
a0 = 0;
    return a0;}
