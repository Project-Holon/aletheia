/*
 * file:     unit_0689CB3C.c
 * unit:     yes
 * function: func_0689CB3C, func_0689CB48, func_0689CBB8, func_0689CC14, func_0689CC70, func_0689CC84, func_0689CC8C, func_0689CCB4, func_0689CCF8, func_0689CD38, func_0689CD40, func_0689CD48, func_0689CD50, func_0689CD78, func_0689CDCC, func_0689CE58
 * address:  0x0689CB3C
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9A24  0x021B9A24  thumb
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    void *id[6];
    u16 a[6];
    u16 b[6];
    u8 c[6];
    u16 d[6];
    u8 n;
    u8 max;
    u8 f44;
    u8 f45;
} S;

struct S {
    void *arr[16];
    u8 _40[0x42 - 0x40];
    u8 f42;
    u8 _43;
    u8 f44;
};

void MI_CpuFill8(void *p, int v, int n);
int BTL_POKEPARAM_IsFainted(void *x);
int BTL_POKEPARAM_GetPokeId();
int func_021B9A24(int a, int b);
void func_0689CB3C(void *p);
void func_0689CB48(S *p, void *id);
void func_0689CBB8(S *p, void *id, u16 amt, int flag);
void func_0689CC14(S *p, void *id);
void *func_0689CC70(S *p, u32 i);
void func_0689CC84(char *p);
void *func_0689CC8C(struct S *s);
int func_0689CCB4(S *p, void *id, u32 *out);
int func_0689CCF8(S *p, void *id, u32 *out);
u32 func_0689CD38(S *p);
int func_0689CD40(S *p);
void func_0689CD48(S *p, u8 v);
int func_0689CD50(S *p);
int func_0689CD78(S *p, S *q);
int func_0689CDCC(S *p, void *a, S *q);
int func_0689CE58(S *p, void *a, S *q);


void func_0689CB3C(void *p)
{
    MI_CpuFill8(p, 0, 0x48);
}


void func_0689CB48(S *p, void *id)
{
    u32 i;
    u8 n = p->n;

    if (n < 6) {
        for (i = 0; i < n; i++) {
            void *t = p->id[i];
            if (t == id)
                return;
        }
        p->id[n] = id;
        p->c[p->n] = 0;
        p->a[p->n] = 0;
        p->b[p->n] = 0;
        p->n = p->n + 1;
        if (p->n > p->max)
            p->max = p->n;
    }
}


void func_0689CBB8(S *p, void *id, u16 amt, int flag)
{
    u32 i;
    void *t;

    func_0689CB48(p, id);
    for (i = 0; i < p->n; i++) {
        t = p->id[i];
        if (t == id) {
            if (flag) {
                p->b[i] += amt;
                p->c[i] = 2;
            } else {
                p->a[i] += amt;
                p->c[i] = 1;
            }
        }
    }
}


void func_0689CC14(S *p, void *id)
{
    u32 i;
    u32 j;
    u8 n = p->n;
    void *t;

    for (i = 0; i < n; i++) {
        t = p->id[i];
        if (t == id) {
            for (j = i + 1; j < p->n; j++)
                p->id[j - 1] = p->id[j];
            p->n--;
            p->f44--;
            return;
        }
    }
}


void *func_0689CC70(S *p, u32 i)
{
    if (i < p->n)
        return p->id[i];
    return 0;
}


void func_0689CC84(char *p)
{
    p[0x44] = 0;
}


void *func_0689CC8C(struct S *s)
{
    u8 a = s->f44;

    if (a < s->f42) {
        s->f44++;
        return s->arr[a];
    }
    return 0;
}


/*
 * Both lookups reload the count byte on every pass (no common-subexpression
 * reuse of p->n across the loop).
 */
#pragma opt_common_subs off

int func_0689CCB4(S *p, void *id, u32 *out)
{
    u32 i;
    void *t;
    for (i = 0; i < p->n; i++) {
        t = p->id[i];
        if (t == id && p->c[i] != 0) {
            *out = p->a[i] + p->b[i];
            return 1;
        }
    }
    return 0;
}


int func_0689CCF8(S *p, void *id, u32 *out)
{
    u32 i;
    void *t;
    for (i = 0; i < p->n; i++) {
        t = p->id[i];
        if (t == id && p->c[i] == 1) {
            *out = p->a[i];
            return 1;
        }
    }
    return 0;
}

#pragma opt_common_subs reset


u32 func_0689CD38(S *p)
{
    return p->n;
}


int func_0689CD40(S *p)
{
    return p->max;
}


void func_0689CD48(S *p, u8 v)
{
    p->f45 = v;
}


int func_0689CD50(S *p)
{
    if (p->max != 0 || p->f45 != 0) {
        if (p->n == 0)
            return 1;
        return 0;
    }
    return 0;
}


int func_0689CD78(S *p, S *q)
{
    u32 i;
    u32 n;
    void *x;

    func_0689CB3C(q);
    n = func_0689CD38(p);
    for (i = 0; i < n; i++) {
        x = func_0689CC70(p, i);
        if (!BTL_POKEPARAM_IsFainted(x))
            func_0689CB48(q, x);
    }
    return func_0689CD38(q);
}


int func_0689CDCC(S *p, void *a, S *q)
{
    u32 i;
    u32 n;
    void *x;
    int s;

    func_0689CB3C(q);
    s = BTL_POKEPARAM_GetPokeId(a);
    n = func_0689CD38(p);
    for (i = 0; i < n; i++) {
        x = func_0689CC70(p, i);
        if (func_021B9A24(s, BTL_POKEPARAM_GetPokeId(x)))
            func_0689CB48(q, x);
    }
    return func_0689CD38(q);
}


int func_0689CE58(S *p, void *a, S *q)
{
    u32 i;
    u32 n;
    void *x;
    int s;

    func_0689CB3C(q);
    s = BTL_POKEPARAM_GetPokeId(a);
    n = func_0689CD38(p);
    for (i = 0; i < n; i++) {
        x = func_0689CC70(p, i);
        if (!func_021B9A24(s, BTL_POKEPARAM_GetPokeId(x)))
            func_0689CB48(q, x);
    }
    return func_0689CD38(q);
}
