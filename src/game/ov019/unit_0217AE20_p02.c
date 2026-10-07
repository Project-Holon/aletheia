/*
 * file:     unit_0217AE20_p02.c
 * unit:     yes
 * function: func_0217B054, func_0217B098
 * address:  0x0217B054
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_0217AFB0  0x0217AFB0  thumb  ov019
 *   func_02188CE0  0x02188CE0  thumb  ov021
 *   func_0217F958  0x0217F958  thumb  ov019
 *   func_0216CF2C  0x0216CF2C  thumb  ov010
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02087C6C  0x02087C6C  arm
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_0217B158  0x0217B158  thumb  ov019
 *   func_0217AFE4  0x0217AFE4  thumb  ov019
 *   func_0217AE38  0x0217AE38  thumb  ov019
 *   func_0217F894  0x0217F894  thumb  ov019
 *   func_0200EDC4  0x0200EDC4  thumb
 *   func_0217F948  0x0217F948  thumb  ov019
 */
struct Ctx;
struct ent;
struct L0200EDC4;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct {
    u8 mac[6];
    u8 pad;
    u8 f0 : 1;
    u8 f1 : 1;
} Ent8;

typedef struct {
    u8 pad[0x28];
    Ent8 tab[5];
    u8 pad2[0x5c - 0x50];
    int f5c;
    u8 pad3[0x6c - 0x60];
    u16 f6c;
    u8 pad4[2];
    u8 *slot[5];
} Obj;

typedef signed int     s32;

extern void *func_0201210C(const struct Ctx *p);
extern void *func_0217AFB0(void **a, u8 *b, u8 *c);
extern u32 func_02188CE0(u8 *p);
extern void func_0217F958(char *p, u32 key);
extern void func_0216CF2C(void *);
extern void MI_CpuFill8(void *p, int v, int n);
extern void func_02087C6C(void *);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, unsigned int n);
extern int func_0217B158(char *base, struct ent *excl, u8 *mac);
extern u8 *func_0217AFE4(int, Obj *, Ent8 *, int, int, int *);
extern int func_0217AE38(char *p, char v);
extern int func_0217F894(void *p, char *q);
extern int func_0200EDC4(struct L0200EDC4 *l, u32 val);
extern void func_0217F948(char *p, u32 a, u32 b);
void func_0217B054(void **a, int b, void *c);
void func_0217B098(int a, int b, int c, int d, Obj *e);


void func_0217B054(void **a, int b, void *c)
{
    void *h;
    void *r;

    h = func_0201210C(((void **)a[0])[3]);
    r = func_0217AFB0(a, (u8 *)b, c);
    if (h != 0 && r != 0)
        func_0217F958((char *)func_02188CE0(h), (u32)r);
    func_0216CF2C(r);
    MI_CpuFill8(c, 0, 12);
}


void func_0217B098(int a, int b, int c, int d, Obj *e)
{
    int out;
    u8 buf[8];
    int i;

    if (e->f6c == 0)
        return;
    func_02087C6C(buf);
    for (i = 0; i < 5; i++) {
        if (e->slot[i] == 0 && e->tab[i].f1 == 1
            && func_0203EFC8(buf, (const u8 *)(&e->tab[i]), 6) != 0
            && func_0217B158((char *)a, (struct ent *)e, (u8 *)(&e->tab[i])) != 0) {
            e->slot[i] = func_0217AFE4(a, e, &e->tab[i], i, 0, &out);
            e->slot[i][8] = 1;
            func_0217AE38((char *)e->slot[i], 0);
            if (i == 0) {
                if (func_0217F894((void *)c, (char *)e) == 1)
                    func_0217F948((char *)d, out, 0);
                else if (func_0200EDC4((struct L0200EDC4 *)b, e->f5c) == 1)
                    func_0217F948((char *)d, out, 1);
            }
        }
    }
}
