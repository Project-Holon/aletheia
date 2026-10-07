/*
 * file:     comm_player_p29.c
 * unit:     yes
 * function: func_0216A560, func_0216A594, func_0216A5C4
 * address:  0x0216A560
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
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F50  0x02012F50  thumb
 *   func_02168CF4  0x02168CF4  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021D0AB8  0x021D0AB8  thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_02008C58 0x02008C58 thumb
 *   func_02008E68 0x02008E68 thumb
 */
#include "../../matched/include/Obj17757.h"
#include "../../matched/include/Obj17758.h"

struct Ctx;
struct Big;
struct Sub02008C20Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012F50(void *base);
extern void *func_02168CF4();
extern int func_0215897C();
extern unsigned int func_02159B10(void *, void *);
extern int func_021D0AB8();
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008C20Obj *func_02008C58(void *sys);
extern void func_02008E68(struct Sub02008C20Obj *obj, u32 value);
int func_0216A560(int a0, int a1);
int func_0216A594(int a0, int a1);
int func_0216A5C4(void *a,void *b);


/*
 * blocked:  listing 52 compiled 50
 */
int func_0216A560(int a0, int a1)
{
    int t4;
    void *p;
    void *task;
    void *v0;
    void *v1;
    void *v2;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216A56A:
a0 = t4 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0216A572:
    p = func_020120F4((const struct Ctx *)v1);
loc_0216A578:
    v2 = func_02012F50(p);
loc_0216A57C:
a1 = ((struct Obj17757 *)((char *)v2))->f0;
    task = func_02168CF4(v1, a1);
loc_0216A586:
    a0 = func_0215897C(v0, task);
loc_0216A58E:
a0 = 1;
    return a0;}


/*
 * blocked:
 */
int func_0216A594(int a0, int a1)
{    int t5;
    int t6;
    void *p;
    void *v0;
    void *v1;
    void *v2;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216A5A0:
a0 = t6 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0216A5A6:
    p = func_020120F4((const struct Ctx *)v1);
loc_0216A5AA:
    v2 = func_02012F50(p);
loc_0216A5AE:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0216A5B8:
a1 = a0 + 0;
a0 = ((struct Obj17758 *)((char *)v2))->f0;
    a0 = func_021D0AB8(a0, a1);
loc_0216A5C0:
a0 = 0;
    return a0;}

int func_0216A5C4(void *a,void *b) { void *sys; u32 n; func_0215A5F4(b); sys=func_020120F4(func_0215A5DC(b)); n=func_02159B10(a,b); func_02008E68(func_02008C58(func_02012EBC(sys)),(u8)n); return 0; }
