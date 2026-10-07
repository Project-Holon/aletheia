/*
 * file:     scrcmd_proc_p01.c
 * unit:     yes
 * function: func_0215B488, func_0215B4AC, func_0215B4DC, func_0215B500, func_0215B558, func_0215B5A8, func_0215B5BC, func_0215B660, func_0215B6C0, func_0215B704, func_0215B74C, func_0215B7E8, func_0215B824, func_0215B848, func_0215B888, func_0215B904, func_0215B994, func_0215BA18, func_0215BAB0, func_0215BAF4, func_0215BB50
 * address:  0x0215B488
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
 *   func_02159B10 0x02159B10 thumb ov010
 *   func_02159AE8 0x02159AE8 thumb ov010
 *   d_02171170 0x02171170 data a2
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C   0x02017E1C  thumb
 *   func_0201BA34  0x0201BA34  thumb
 *   func_02011330  0x02011330  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_0201AB08  0x0201AB08  thumb
 *   func_0201AB18  0x0201AB18  thumb
 *   func_0201AA14  0x0201AA14  thumb
 *   func_0201AA1C  0x0201AA1C  thumb
 *   func_0201AA50  0x0201AA50  thumb
 *   func_0201AA88  0x0201AA88  thumb
 *   func_0201AAD4  0x0201AAD4  thumb
 *   func_0201293C  0x0201293C  thumb
 *   func_02007984  0x02007984  thumb
 *   func_020079A0  0x020079A0  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_02012944  0x02012944  thumb
 *   func_0215C510  0x0215C510  thumb  ov010
 */
#include "../../matched/include/Obj04130.h"
#include "../../matched/include/Obj17690.h"

struct BigObj;
struct Stream;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

typedef short s16;

typedef struct {
    u16 h;
    void *p0;
    void *p1;
    void *p2;
    int z;
    int c0;
    int c1;
    int c2;
    int c3;
} Req;

extern unsigned int func_02159B10(void *,void *);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5E4(void *a0);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_0201BA34(void *a0);
extern u16 func_02011330(struct Stream *s);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_0201AB08(void *p);
extern u32 func_0201AB18(void *p);
extern u32 func_0201AA14(void *p);
extern u32 func_0201AA1C(void *p);
extern u32 func_0201AA50(void *p);
extern u32 func_0201AA88(void *p);
extern u32 func_0201AAD4(void *p);
extern u32 func_0201293C(const struct BigObj *p);
extern int func_02007984(void *);
extern int func_020079A0(void *);
extern void *func_0215A5DC(void *a0);
extern u16 func_0215A5CC(void *);
extern u8 *func_02012944(void *p);
extern int func_0215C510(void *a, void *b);
int func_0215B488(int a,int b);
int func_0215B4AC(void *a0, u32 a1, void **a2);
int func_0215B4DC(void *a0, void *a1, void *a2);
int func_0215B500(int a0, int a1);
int func_0215B558(int a0, int a1);
int func_0215B5A8(int a0, int a1);
int func_0215B5BC(void *a0, void *a1);
int func_0215B660(int a0, int a1, int a2);
int func_0215B6C0(int a0, int a1, int a2);
int func_0215B704(int a0, int a1, int a2);
int func_0215B74C(int a0, int a1);
int func_0215B7E8(int a,int b);
int func_0215B824(int a0, int a1, int a2);
int func_0215B848(int a0, int a1);
int func_0215B888(void *a0, void *a1);
int func_0215B904(void *a0, void *a1);
int func_0215B994(void *a0, void *a1);
int func_0215BA18(void *a0, void *a1);
int func_0215BAB0(int a0, int a1, int a2);
int func_0215BAF4(void *a0, void *a1);
int func_0215BB50(void *a0, void *a1);
extern const u16 d_02171170[];

/*
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 */
int func_0215B488(int a,int b)
{
    int k = func_02159B10((void *)a,(void *)b);
    u16 *out = func_02159AE8((void *)a,(void *)b);
    *out = d_02171170[k];
    return 0;
}


int func_0215B4AC(void *a0, u32 a1, void **a2)
{
    int t4;
    u32 t5;
    void **t6;
    int n;
    void *p;
    void *v0;
    void *v1;

t5 = a1 + 0;
t6 = a2;
    v0 = func_0215A5E4(a0);
loc_0215B4B6:
    v1 = func_02012934(v0);
loc_0215B4BA:
    n = func_0201AA18(v1);
loc_0215B4C0:
    if (t5 >= (unsigned)n) goto loc_0215B4C8;
loc_0215B4C4:
t4 = 1;
    goto loc_0215B4CC;
loc_0215B4C8:
t4 = 0;
t5 = 0;
loc_0215B4CC:
    p = func_0201AB28(v1, t5);
loc_0215B4D4:
*t6 = p;
    return t4;}


/*
 * Unpacks a record into a local and, when the overlay call says it took,
 * forwards the record and the third argument to the arm9 side.
 */
int func_0215B4DC(void *a0, void *a1, void *a2)
{
    int v;

    if (func_0215B4AC(a0, (u32)a1, (void **)(&v)) == 1)
        return func_02017E1C((void *)v, (u32)a2, 0);

    return 0;
}


int func_0215B500(int a0, int a1)
{
    int a2;
    int t4;
    int t5;
    int t6;

t4 = a1 + 0;
a1 = 0x4c;
a2 = 0;
t5 = a0 + 0;
t6 = 0;
    a0 = func_02017E1C((void *)a0, a1, a2);
loc_0215B510:
    if (a0 == 0) goto loc_0215B518;
loc_0215B514:
a0 = t6 + 0;
    return a0;
loc_0215B518:
a0 = t5 + 0;
a1 = 0x36;
a2 = t6 + 0;
    a0 = func_02017E1C((void *)a0, a1, a2);
loc_0215B522:
    if (t4 == a0) goto loc_0215B550;
loc_0215B526:
a0 = t5 + 0;
a1 = 0x37;
a2 = t6 + 0;
    a0 = func_02017E1C((void *)a0, a1, a2);
loc_0215B530:
    if (t4 == a0) goto loc_0215B550;
loc_0215B534:
a0 = t5 + 0;
a1 = 0x38;
a2 = t6 + 0;
    a0 = func_02017E1C((void *)a0, a1, a2);
loc_0215B53E:
    if (t4 == a0) goto loc_0215B550;
loc_0215B542:
a0 = t5 + 0;
a1 = 0x39;
a2 = t6 + 0;
    a0 = func_02017E1C((void *)a0, a1, a2);
loc_0215B54C:
    if (t4 != a0) goto loc_0215B554;
loc_0215B550:
a0 = 1;
    return a0;
loc_0215B554:
a0 = t6 + 0;
    return a0;}

int func_0215B558(int a0, int a1)
{
    u16 *p = func_02159AE8((void *)a0, (void *)a1);
    u16 *q = func_02159AE8((void *)a0, (void *)a1);
    int obj;
    if (func_0215B4AC((void *)a1, func_02159B10((void *)a0, (void *)a1), (void **)(&obj)) == 1) {
        *p = func_02017E1C((void *)obj, 0xAE, 0);
        *q = func_02017E1C((void *)obj, 0xAF, 0);
    } else {
        *p = 0;
        *q = 0;
    }
    return 0;
}


int func_0215B5A8(int a0, int a1)
{
    void *v0;
    void *v1;

a0 = a1 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215B5B0:
    v1 = func_02012934(v0);
loc_0215B5B4:
    func_0201BA34(v1);
loc_0215B5B8:
a0 = 0;
    return a0;}

#pragma opt_lifetimes off

#pragma opt_propagation off

/*
 * 2026-10-05 (wave P14 C6): closed with per-function opt_lifetimes off plus
 * opt_propagation off. Without them the two zeros (the named argument zero z
 * and the initial sum) merge into one register and the first add folds to
 * adds r0,r0,#0 (35 B off, 166 B). opt_lifetimes off alone: 2 B off.
 */
int func_0215B5BC(void *a0, void *a1)
{
    u16 *out = (u16 *)func_02159AE8(a0, a1);
    int idx = func_02159B10(a0, a1);
    int z = 0;
    u16 sum = 0;
    void *obj;
    if (func_0215B4AC(a1, idx, &obj) == 1) {
        sum = z + (u16)func_02017E1C(obj, 0xD, z);
        sum = sum + (u16)func_02017E1C(obj, 0xE, z);
        sum = sum + (u16)func_02017E1C(obj, 0xF, z);
        sum = sum + (u16)func_02017E1C(obj, 0x10, z);
        sum = sum + (u16)func_02017E1C(obj, 0x11, z);
        sum = sum + (u16)func_02017E1C(obj, 0x12, z);
    }
    *out = sum;
    return 0;
}

#pragma opt_lifetimes reset

#pragma opt_propagation reset


int func_0215B660(int a0, int a1, int a2)
{
    unsigned char fr[4];
    int t5;
    int t6;
    u16 *q;
t6 = a0 + 0;
t5 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215B66C:
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0215B676:
a1 = a0 + 0;
t6 = 0;
a0 = t5 + 0;
a2 = (int)(fr + 0);
*q = t6;
    a0 = func_0215B4AC((void *)a0, a1, (void **)a2);
loc_0215B684:
    if (a0 != 1) goto loc_0215B6BA;
loc_0215B688:
    a0 = *(int *)&((struct Obj04130 *)fr)->f0;
a1 = 0xa0;
a2 = t6 + 0;
    a0 = (int)func_02017E1C((void *)a0, a1, a2);
loc_0215B692:
a0 = a0 << 0x10;
t5 = (unsigned)a0 >> 0x10;
    a0 = *(int *)&((struct Obj04130 *)fr)->f0;
a1 = 0xa1;
a2 = t6 + 0;
    a0 = (int)func_02017E1C((void *)a0, a1, a2);
loc_0215B6A0:
a0 = a0 << 0x10;
a0 = (unsigned)a0 >> 0x10;
    if (t5 == a0) goto loc_0215B6B6;
loc_0215B6A8:
    a0 = *(int *)&((struct Obj04130 *)fr)->f0;
a1 = 0x4c;
a2 = t6 + 0;
    a0 = (int)func_02017E1C((void *)a0, a1, a2);
loc_0215B6B2:
    if (a0 != 1) goto loc_0215B6BA;
loc_0215B6B6:
a0 = 1;
*q = a0;
loc_0215B6BA:
a0 = 0;
    return a0;
}


int func_0215B6C0(int a0, int a1, int a2)
{
    unsigned char fr[4];
    int t5;
    int t6;
    u16 *q;
t6 = a0 + 0;
t5 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215B6CC:
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = (int)func_02159B10((void *)a0, (void *)a1);
loc_0215B6D6:
a1 = a0 + 0;
t6 = 0;
a0 = t5 + 0;
a2 = (int)(fr + 0);
*q = t6;
    a0 = func_0215B4AC((void *)a0, a1, (void **)a2);
loc_0215B6E4:
    if (a0 != 1) goto loc_0215B6FE;
loc_0215B6E8:
    a0 = *(int *)&((struct Obj04130 *)fr)->f0;
a1 = 0x4c;
a2 = t6 + 0;
    a0 = func_02017E1C((void *)a0, a1, a2);
loc_0215B6F2:
    if (a0 != 0) goto loc_0215B6FA;
loc_0215B6F6:
*q = t6;
    goto loc_0215B6FE;
loc_0215B6FA:
a0 = 1;
*q = a0;
loc_0215B6FE:
a0 = 0;
    return a0;
}


int func_0215B704(int a0, int a1, int a2)
{
    unsigned char fr[4];
    int t5;
    int t6;
    u16 *q;
t6 = a0 + 0;
t5 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215B710:
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = (int)func_02159B10((void *)a0, (void *)a1);
loc_0215B71A:
a1 = a0 + 0;
t6 = 0;
a0 = t5 + 0;
a2 = (int)(fr + 0);
*q = t6;
    a0 = func_0215B4AC((void *)a0, a1, (void **)a2);
loc_0215B728:
    if (a0 != 1) goto loc_0215B746;
loc_0215B72C:
    a0 = *(int *)&((struct Obj04130 *)fr)->f0;
a1 = 0x4c;
a2 = t6 + 0;
    a0 = (int)func_02017E1C((void *)a0, (u32)a1, (u32)a2);
loc_0215B736:
    if (a0 != 0) goto loc_0215B746;
loc_0215B73A:
    a0 = *(int *)&((struct Obj04130 *)fr)->f0;
a1 = 9;
a2 = t6 + 0;
    a0 = (int)func_02017E1C((void *)a0, (u32)a1, (u32)a2);
loc_0215B744:
*q = a0;
loc_0215B746:
a0 = 0;
    return a0;
}

int func_0215B74C(int a0, int a1)
{
    int a = func_02159B10((void *)a0, (void *)a1);
    int b = func_02159B10((void *)a0, (void *)a1);
    int mode = func_02011330((struct Stream *)a0);
    int obj = 0;
    u8 v;
    if (func_0215B4AC((void *)a1, a, (void **)(&obj)) == 0) {
        return 0;
    }
    if (func_02017E1C((void *)obj, 0x4C, 0) == 1) {
        return 0;
    }
    v = func_02017E1C((void *)obj, 9, 0);
    switch (mode) {
    case 0:
        if ((u32)b > 0xFF) {
            v = 0xFF;
        } else {
            v = b;
        }
        break;
    case 1:
        if (v + b > 0xFF) {
            v = 0xFF;
        } else {
            v = v + (u8)b;
        }
        break;
    case 2:
        if (v < b) {
            v = 0;
        } else {
            v = v - (u8)b;
        }
        break;
    }
    func_02017E40((void *)obj, 9, v);
    return 0;
}

int func_0215B7E8(int a,int b)
{
    u16 *out = func_02159AE8((void *)a,(void *)b);
    int k = func_02159B10((void *)a,(void *)b);
    if (func_0215B4DC((void *)b,(void *)k,(void *)0x4C) != 0) *out = 0x28A; else *out = func_0215B4DC((void *)b,(void *)k,(void *)5);
    return 0;
}


int func_0215B824(int a0, int a1, int a2)
{
    int t5;
    int t6;
    u16 *q;

t6 = a0 + 0;
t5 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215B82E:
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = (int)func_02159B10((void *)a0, (void *)a1);
loc_0215B838:
a1 = a0 + 0;
a0 = t5 + 0;
a2 = 0x6f;
    a0 = func_0215B4DC((void *)a0, (void *)a1, (void *)a2);
loc_0215B842:
*q = a0;
a0 = 0;
    return a0;}


int func_0215B848(int a0, int a1)
{
    int t4;
    int t5;
    unsigned short *v0;
    void *p;

t4 = a0 + 0;
t5 = a1 + 0;
    v0 = func_02159AE8((void *)a0, (void *)a1);
loc_0215B852:
a0 = t4 + 0;
a1 = t5 + 0;
    a0 = (int)func_02159B10((void *)a0, (void *)a1);
loc_0215B85C:
t4 = a0 + 0;
a0 = t5 + 0;
    p = func_0215A5E4((void *)a0);
loc_0215B864:
    p = func_02012934(p);
loc_0215B868:
    if (t4 == 1) goto loc_0215B87A;
loc_0215B86C:
    if (t4 != 2) goto loc_0215B880;
loc_0215B870:
    a0 = func_0201AB08(p);
loc_0215B874:
a0 = a0 << 0x10;
a0 = (unsigned)a0 >> 0x10;
    goto loc_0215B882;
loc_0215B87A:
    a0 = func_0201AB18(p);
loc_0215B87E:
    goto loc_0215B874;
loc_0215B880:
a0 = 0;
loc_0215B882:
((struct Obj17690 *)((char *)v0))->f0 = a0;
a0 = 0;
    return a0;}


int func_0215B888(void *a0, void *a1)
{
    u16 *out = func_02159AE8(a0, a1);
    int sel = func_02159B10(a0, a1);
    void *h = func_02012934(func_0215A5E4(a1));
    int r;

    switch (sel) {
    case 0:
        r = func_0201AA18(h);
        break;
    case 1:
        r = func_0201AA1C(h);
        break;
    case 2:
        r = func_0201AA50(h);
        break;
    case 3:
        r = func_0201AA88(h);
        break;
    case 4:
        r = func_0201AAD4(h);
        break;
    case 5: {
        int a = func_0201AA14(h);
        int b = func_0201AA18(h);
        if (a < b) {
            r = 0;
        } else {
            r = a - b;
        }
        break;
    }
    default:
        r = 0;
        break;
    }
    *out = r;
    return 0;
}


int func_0215B904(void *a0, void *a1)
{
    u32 key = func_02159B10(a0, a1);
    u16 *out = func_02159AE8(a0, a1);
    void *list = func_02012934(func_0215A5E4(a1));
    u16 n = func_0201AA18(list);
    u16 cnt = 0;
    int i;

    if (key != 0 && key <= 0x289) {
        for (i = 0; i < n; i++) {
            void *e = func_0201AB28(list, i);
            u16 t;

            if (e != 0 && func_02017E1C(e, 0x4C, 0) == 0) {
                t = func_02017E1C(e, 5, 0);
                if (t == key) {
                    cnt++;
                }
            }
        }
        *out = cnt;
    } else {
        *out = 0;
    }
    return 0;
}


int func_0215B994(void *a0, void *a1)
{
    u16 *out = func_02159AE8(a0, a1);
    int sel = func_02159B10(a0, a1);
    void *h = func_0215A5E4(a1);
    void *d = (void *)func_0201293C(h);
    int r;

    func_02012934(h);
    switch (sel) {
    case 0:
        r = func_02007984(d);
        break;
    case 1:
    case 2:
        r = func_020079A0(d);
        break;
    case 3:
        r = func_02007984(d) - func_020079A0(d);
        break;
    case 5: {
        int v = func_02007984(d);
        if (v > 720) {
            r = 0;
        } else {
            r = 720 - v;
        }
        break;
    }
    default:
        r = 0;
        break;
    }
    *out = r;
    return 0;
}


int func_0215BA18(void *a0, void *a1)
{
    u32 key = func_02159B10(a0, a1);
    u16 *out = func_02159AE8(a0, a1);
    u16 *idx = func_02159AE8(a0, a1);
    void *list = func_02012934(func_0215A5E4(a1));
    u16 n = func_0201AA18(list);
    int i;

    if (key != 0 && key <= 0x289) {
        for (i = 0; i < n; i++) {
            void *e = func_0201AB28(list, i);
            u16 t;

            if (e != 0 && func_02017E1C(e, 0x4C, 0) == 0) {
                t = func_02017E1C(e, 5, 0);
                if (t == key) {
                    break;
                }
            }
        }
        if (i < n) {
            *out = 1;
            *idx = i;
        } else {
            *out = 0;
        }
    } else {
        *out = 0;
    }
    return 0;
}


int func_0215BAB0(int a0, int a1, int a2)
{
    int v0;
    int t5;
    int t6;
    int t7;
    u16 *q;
t6 = a0 + 0;
t5 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215BABA:
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = (int)func_02159B10((void *)a0, (void *)a1);
loc_0215BAC4:
t7 = a0 + 0;
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = (int)func_02159B10((void *)a0, (void *)a1);
loc_0215BACE:
a1 = a0 + 0;
a0 = 0;
*q = a0;
a0 = t5 + 0;
a2 = (int)&v0;
    a0 = func_0215B4AC((void *)a0, a1, (void **)a2);
loc_0215BADC:
    if (a0 != 1) goto loc_0215BAF0;
loc_0215BAE0:
    a0 = v0;
a1 = t7 + 0;
    a0 = func_0215B500(a0, a1);
loc_0215BAE8:
    if (a0 != 1) goto loc_0215BAF0;
loc_0215BAEC:
a0 = 1;
*q = a0;
loc_0215BAF0:
a0 = 0;
    return a0;
}


int func_0215BAF4(void *a0, void *a1)
{
    void *list = func_02012934(func_0215A5E4(a1));
    u16 *out = func_02159AE8(a0, a1);
    void *key = (void *)func_02159B10(a0, a1);
    int i;
    int n = func_0201AA18(list);

    *out = 6;
    for (i = 0; i < n; i++) {
        if (func_0215B500((int)func_0201AB28(list, i), (int)key) == 1) {
            *out = i;
            break;
        }
    }
    return 0;
}


int func_0215BB50(void *a0, void *a1)
{
    void *h;
    u16 n;
    u16 *out;
    void *t1;
    void *t2;
    void *t3;
    Req r;

    func_0215A5DC(a1);
    h = func_0215A5E4(a1);
    n = func_0215A5CC(a1);
    func_02012934(h);
    func_02012944(h);
    out = func_02159AE8(a0, a1);
    t1 = (void *)func_02159B10(a0, a1);
    t2 = (void *)func_02159B10(a0, a1);
    t3 = (void *)func_02159B10(a0, a1);
    r.h = n;
    r.p0 = t1;
    r.p1 = t2;
    r.p2 = t3;
    r.z = 0;
    r.c0 = 2;
    r.c1 = 2;
    r.c2 = 2;
    r.c3 = 4;
    *out = func_0215C510(h, &r);
    return 0;
}
