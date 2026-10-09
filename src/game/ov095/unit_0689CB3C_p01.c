/*
 * file:     unit_0689CB3C_p01.c
 * unit:     yes
 * function: func_0689CB3C, func_0689CB48, func_0689CBB8, func_0689CC14, func_0689CC70, func_0689CC84, func_0689CC8C
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
 *   func_02082BCC  0x02082BCC  arm
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 id[6];
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
    u32 arr[16];
    u8 _40[0x42 - 0x40];
    u8 f42;
    u8 _43;
    u8 f44;
};

void func_02082BCC(void *p, int v, int n);
void func_0689CB3C(void *p);
void func_0689CB48(S *p, u32 id);
void func_0689CBB8(S *p, u32 id, u16 amt, int flag);
void func_0689CC14(S *p, u32 id);
u32 func_0689CC70(S *p, u32 i);
void func_0689CC84(char *p);
int func_0689CC8C(struct S *s);




void func_0689CB3C(void *p)
{
    func_02082BCC(p, 0, 0x48);
}




void func_0689CB48(S *p, u32 id)
{
    u32 i;
    u8 n = p->n;

    if (n < 6) {
        for (i = 0; i < n; i++) {
            u32 t = p->id[i];
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




void func_0689CBB8(S *p, u32 id, u16 amt, int flag)
{
    u32 i;
    u32 t;

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




void func_0689CC14(S *p, u32 id)
{
    u32 i;
    u32 j;
    u8 n = p->n;
    u32 t;

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




u32 func_0689CC70(S *p, u32 i)
{
    if (i < p->n)
        return p->id[i];
    return 0;
}


void func_0689CC84(char *p)
{
    p[0x44] = 0;
}


int func_0689CC8C(struct S *s)
{
    u8 a = s->f44;

    if (a < s->f42) {
        s->f44++;
        return s->arr[a];
    }
    return 0;
}
