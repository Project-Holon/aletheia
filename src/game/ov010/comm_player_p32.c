/*
 * file:     comm_player_p32.c
 * unit:     yes
 * function: func_0216ACCC, func_0216AD1C, func_0216AD70
 * address:  0x0216ACCC
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
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200E0B0  0x0200E0B0  thumb
 *   func_0216AED0  0x0216AED0  thumb  ov010
 *   func_0217C294  0x0217C294  thumb  ov018
 *   func_0216628C  0x0216628C  thumb  ov010
 *   func_0216AF3C  0x0216AF3C  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_0216AF1C  0x0216AF1C  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_0201EE84  0x0201EE84  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02012138  0x02012138  thumb
 *   func_021767A0  0x021767A0  thumb  ov011
 *   func_02012FB0  0x02012FB0  thumb
 *   func_02166618  0x02166618  thumb  ov010
 *   func_0216662C  0x0216662C  thumb  ov010
 *   func_0216AEE8  0x0216AEE8  thumb  ov010
 */
struct Big;
struct WordSet;
struct Ctx;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 lo : 11;
    u32 pad : 12;
    u32 f : 6;
    u32 rest : 3;
} Bits;

extern unsigned int func_02159B10(void *a0, void *a1);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5E4(void *a0);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200E0B0(void *p);
extern void *func_0216AED0(void *p, u32 id);
extern int func_0217C294(char *a0);
extern int func_0216628C(u32 *obj, u32 slot);
extern void func_0216AF3C(int a0);
extern u16 func_0215A5CC(void *a0);
extern int func_0216AF1C();
extern void *func_0215A5F4(void *p);
extern void *func_02158F74(void *p);
extern void func_0201EE84(struct WordSet *p, u32 i, void *mon);
extern int func_020307B0();
extern void *func_0215A5DC(void *a0);
extern u32 func_02012138(const struct Ctx *p);
extern u8 func_021767A0(void *a, void *b);
extern int func_02012FB0(unsigned char *base);
extern int func_02166618(int a0);
extern int func_0216662C(int a0);
extern void func_0216AEE8(int vm, int *out);
int func_0216ACCC(int a0, int a1);
int func_0216AD1C(int a0, int a1, int a2, int a3);
int func_0216AD70(int a0, int a1);


/*
 * Unblocked by matching func_0217C294 (ov018, EXACT; itself unblocked by
 * func_0216D63C): the +0032 call site now attests as `matched`.
 */
int func_0216ACCC(int a0, int a1)
{
    int t4;
    int t5;
    void *t6;
    int t7;
    void *w;
    void *r;
    u16 *q;

t4 = a0 + 0;
t5 = a1 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0216ACD6:
t7 = a0 + 0;
a0 = t4 + 0;
a1 = t5 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0216ACE0:
a0 = t5 + 0;
    w = func_0215A5E4((void *)a0);
loc_0216ACE8:
    w = func_02012EBC(w);
loc_0216ACEC:
    t6 = func_0200E0B0(w);
loc_0216ACF0:
a0 = t5 + 0;
a1 = t7 + 0;
    r = func_0216AED0((void *)a0, a1);
loc_0216ACFA:
    if (r == 0) goto loc_0216AD14;
loc_0216ACFE:
    a0 = func_0217C294(r);
loc_0216AD02:
a1 = a0 + 0;
    a0 = func_0216628C(t6, a1);
loc_0216AD0A:
*q = a0;
a0 = t5 + 0;
    func_0216AF3C(a0);
loc_0216AD12:
    goto loc_0216AD18;
loc_0216AD14:
a0 = 0;
*q = a0;
loc_0216AD18:
a0 = 0;
    return a0;}


int func_0216AD1C(int a0, int a1, int a2, int a3)
{
    int v0;
    int t4;
    int t5;
    int t6;
    int t7;
    void *obj;
    void *v1;
t5 = a0 + 0;
t4 = a1 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0216AD26:
t6 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0216AD30:
t7 = a0 + 0;
a0 = t4 + 0;
a1 = t6 + 0;
    obj = func_0216AED0((void *)a0, a1);
loc_0216AD3A:
    if (obj == 0) goto loc_0216AD6C;
loc_0216AD3E:
a0 = t4 + 0;
    a0 = func_0215A5CC((void *)a0);
loc_0216AD44:
a2 = a0 + 0;
a0 = t4 + 0;
a3 = (int)&v0;
    a0 = func_0216AF1C(a0, obj, a2, a3);
loc_0216AD50:
t5 = a0 + 0;
    if (t5 == 0) goto loc_0216AD6C;
loc_0216AD54:
a0 = t4 + 0;
    v1 = func_0215A5F4((void *)a0);
loc_0216AD5A:
    a0 = (int)func_02158F74(v1);
loc_0216AD5E:
a1 = t7 + 0;
a2 = t5 + 0;
    func_0201EE84((void *)a0, a1, (void *)a2);
loc_0216AD66:
a0 = t5 + 0;
    a0 = func_020307B0(a0);
loc_0216AD6C:
a0 = 0;
    return a0;
}


int func_0216AD70(int a0, int a1)
{
    int kind;
    u16 *out;
    void *x;
    void *y;
    int t;
    Bits v;
    Bits w;

    kind = func_02159B10((void *)a0, (void *)a1);
    out = func_02159AE8((void *)a0, (void *)a1);
    x = func_0215A5DC((void *)a1);
    y = func_0215A5E4((void *)a1);
    func_0200E0B0(func_02012EBC((struct Big *)y));
    t = func_02012138(x);
    switch (kind) {
    case 0:
        if (func_021767A0((void *)t, y) == 4)
            *out = 1;
        else
            *out = 0;
        break;
    case 1:
        *out = func_02166618(func_02012FB0(y));
        break;
    case 2:
        *out = func_0216662C(func_02012FB0(y));
        break;
    case 3:
        func_0216AEE8(a1, (int *)(&v));
        *out = v.lo;
        break;
    case 4:
        func_0216AEE8(a1, (int *)(&w));
        *out = w.f;
        break;
    }
    return 0;
}
