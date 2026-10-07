/*
 * file:     eventdata_system_p22.c
 * unit:     yes
 * function: func_02163418, func_02163464, func_021634D8
 * address:  0x02163418
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
 *   func_0216DC00 0x0216DC00 thumb ov010
 *   func_021AB41C 0x021AB41C thumb ov021
 *   func_0216D900 0x0216D900 thumb ov010
 *   d_021714D0 0x021714D0 data ov010 a4
 *   func_021AB4EC  0x021AB4EC  thumb
 *   func_021AB4F8  0x021AB4F8  thumb
 *   func_021AB434  0x021AB434  thumb
 *   func_021AB428  0x021AB428  thumb
 *   func_021AB250  0x021AB250  thumb
 *   func_021AB264  0x021AB264  thumb
 *   func_021AB270  0x021AB270  thumb
 *   func_021AC760  0x021AC760  thumb
 */
#include "../../matched/include/Obj00110.h"

typedef struct { int x, y, z; } V;

typedef struct { char pad[10]; unsigned short f; } S;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_0216DC00(void *a0);
extern int func_021AB41C(unsigned short);
extern void func_0216D900(int, const V *);
extern int func_021AB4EC();
extern int func_021AB4F8();
extern int func_021AB434();
extern int func_021AB428();
extern int func_021AB250();
extern int func_021AB264();
extern int func_021AB270();
extern int func_021AC760();
void func_02163418(int a, S *s);
int func_02163464(int a0, int a1);
void func_021634D8(int a0, int a1, int a2, int a3);
extern V d_021714D0;

static inline void vzero(V *p)
{
    p->x = 0;
    p->y = 0;
    p->z = 0;
}

/*
 * lever: block-local cast byte buffer keeps the zeroing pointer on the zero path.
 */
void func_02163418(int a, S *s)
{
    V v;
    V *pz;
    if (func_0216DC00((void *)a) == 0 && func_021AB41C(s->f) != 0) {
        v = d_021714D0;
        func_0216D900(a, &v);
        return;
    }
    {
        unsigned char buf[12];
        V *z = (V *)buf;
        vzero(z);
        func_0216D900(a, z);
    }
}


int func_02163464(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
t6 = a1 + 0;
t4 = 0;
    a0 = func_021AB4EC(a0);
loc_02163470:
    if (a0 == 0) goto loc_02163478;
loc_02163474:
t4 = 6;
    goto loc_021634D4;
loc_02163478:
a0 = t5 + 0;
    a0 = func_021AB4F8(a0);
loc_0216347E:
    if (a0 == 0) goto loc_02163486;
loc_02163482:
t4 = 7;
    goto loc_021634D4;
loc_02163486:
a0 = t5 + 0;
    a0 = func_021AB434(a0);
loc_0216348C:
    if (a0 == 0) goto loc_0216349A;
loc_02163490:
t4 = 1;
    if (t6 != 3) goto loc_021634D4;
loc_02163496:
t4 = 5;
    goto loc_021634D4;
loc_0216349A:
a0 = t5 + 0;
    a0 = func_021AB428(a0);
loc_021634A0:
    if (a0 == 0) goto loc_021634AC;
loc_021634A4:
    if (t6 != 3) goto loc_021634D4;
loc_021634A8:
t4 = 4;
    goto loc_021634D4;
loc_021634AC:
a0 = t5 + 0;
    a0 = func_021AB250(a0);
loc_021634B2:
    if (a0 == 0) goto loc_021634BA;
loc_021634B6:
t4 = 1;
    goto loc_021634D4;
loc_021634BA:
a0 = t5 + 0;
    a0 = func_021AB264(a0);
loc_021634C0:
    if (a0 == 0) goto loc_021634C8;
loc_021634C4:
t4 = 2;
    goto loc_021634D4;
loc_021634C8:
a0 = t5 + 0;
    a0 = func_021AB270(a0);
loc_021634CE:
    if (a0 == 0) goto loc_021634D4;
loc_021634D2:
t4 = 3;
loc_021634D4:
a0 = t4 + 0;
    return a0;}


void func_021634D8(int a0, int a1, int a2, int a3)
{
    int t4;
    int t5;

t4 = a1 + 0;
a1 = ((struct Obj00110 *)t4)->fE;
t5 = a0 + 0;
a0 = 0x20;
    if ((a0 & a1) == 0) goto loc_021634FA;
loc_021634E6:
a0 = ((struct Obj00110 *)t4)->fA;
a1 = ((struct Obj00110 *)t4)->f18;
    a0 = func_02163464(a0, a1);
loc_021634EE:
a3 = a0 + 0;
a0 = ((struct Obj00110 *)t4)->f14;
a1 = t5 + 0;
a2 = 0;
    a0 = func_021AC760(a0, a1, a2, a3);
loc_021634FA:
    return;}
