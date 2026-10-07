/*
 * file:     comm_player_p14.c
 * unit:     yes
 * function: func_02168AC8, func_02168AEC, func_02168B18, func_02168B20, func_02168BBC, func_02168BF0
 * address:  0x02168AC8
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
 *   g_0217208C  0x0217208C  data  ov010  a2
 *   g_0217208E  0x0217208E  data  ov010  a2
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CCC  0x02188CCC  thumb ov021
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02012158  0x02012158  thumb
 *   func_020121CC  0x020121CC  thumb
 *   func_021A0F7C  0x021A0F7C  thumb ov021
 *   func_020120F4 0x020120F4 thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_02012934  0x02012934  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BAF4  0x0200BAF4  thumb
 *   func_02168C74  0x02168C74  thumb ov010
 */
#include "../../matched/include/Obj12052.h"

struct Ctx;
struct Comm;
struct IcaAnime;
struct Desc;
struct Obj;
struct Big;
struct BigObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef enum { ST_0, ST_1, ST_2, ST_3, ST_4, ST_5 } State;

typedef struct {
    void *f0;
    void *f4;
    int f8;
    u16 *fc;
    int f10;
    int f14;
    void *f18;
    void *f1c;
    u32 pad[4];
    int f30;
} R;

extern void *func_0201210C(const struct Ctx *);
extern u32 func_02188CCC(u8 *p);
extern unsigned int func_02012138(const struct Ctx *);
extern u32 func_02026454(void *obj);
extern void func_02026400(struct Comm *p);
extern void func_02012158(char *p, unsigned int v);
extern u32 func_020121CC(struct IcaAnime *p);
extern int func_021A0F7C(u32 a, u32 b, u32 c, u32 d);
extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_02082BCC(void *, int, unsigned int);
extern void *func_02012934(const struct BigObj *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200BAC8(void *p);
extern void *func_0200BAF4(int a0, int a1);
extern void func_02168C74(void);
int func_02168AC8(int a0);
u16 func_02168AEC(u16 a0);
void func_02168B18(int *p);
int func_02168B20(int a, int *b, int *c);
void *func_02168BBC(void *a, void *b);
struct Desc *func_02168BF0(int a, int b, int c, int d, u16 *e);
extern u16 g_0217208C[];
extern u16 g_0217208E[];




int func_02168AC8(int a0)
{
    int a1;
    int a2;
    int a3;

a3 = 0;
loc_02168ACA:
a1 = a3 << 1;
a2 = a0 + a1;
a1 = ((struct Obj12052 *)a2)->f20;
    if (a1 == 0) goto loc_02168AD8;
loc_02168AD4:
a0 = 1;
    return a0;
loc_02168AD8:
a1 = ((struct Obj12052 *)a2)->f28;
    if (a1 == 0) goto loc_02168AE2;
loc_02168ADE:
a0 = 1;
    return a0;
loc_02168AE2:
a3 = a3 + 1;
    if (a3 < 4) goto loc_02168ACA;
loc_02168AE8:
a0 = 0;
    return a0;}


/*
 * Recursive MATCH unblocker: ABS32 target of func_021D0BCC (ov021) +0008.
 * Coherent Thumb code in ov010 (ARM data in ov009), so the ov010 shard makes
 * that site attest as `matched`.
 */
u16 func_02168AEC(u16 a0)
{
    u32 i;

    for (i = 0; i < 0x35; i++) {
        if (g_0217208C[i * 2] == a0)
            return g_0217208E[i * 2];
    }
    return 0xA;
}

/*
 * Unlabelled leaf callback (movs r1,#1; str r1,[r0]; bx lr); filed as the
 * sole blocker of func_02168B20 (its pool word).
 */
void func_02168B18(int *p)
{
    *p = 1;
}


/*
 * lever: 02026454 reads the live 02012138 result in r0 in cases 0 and 1.
 */
int func_02168B20(int a, int *b, int *c)
{
    int s = c[2];
    int x = func_02188CCC((u8 *)((int)func_0201210C((const struct Ctx *)s)));
    int y = func_02012138((const struct Ctx *)s);
    State t = (State)*b;
    switch (t) {
    case 0:
        if (func_02026454((void *)y) != 0)
            func_02026400((struct Comm *)y);
        (*b)++;
        break;
    case 1:
        if (func_02026454((void *)y) != 0)
            break;
        func_02012158((char *)s, 0);
        (*b)++;
        break;
    case 2:
        if (c[1] != 0) {
            func_02012158((char *)s, 1);
            func_020121CC((struct IcaAnime *)s);
        }
        (*b)++;
        break;
    case 3:
        func_021A0F7C(x, 8, (u32)func_02168B18, (u32)c);
        (*b)++;
        break;
    case 4:
        if (c[0] != 0)
            *b = t + 1;
        break;
    case 5:
        return 1;
    }
    return 0;
}

void *func_02168BBC(void *a, void *b)
{
    void *h;
    void **p;
    func_020120F4(a);
    h = func_020122C0(a, 0, func_02168B20, 0xc);
    p = func_020124E8(h);
    func_02082BCC(p, 0, 0xc);
    p[2] = a;
    p[1] = b;
    return h;
}


struct Desc *func_02168BF0(int a, int b, int c, int d, u16 *e)
{
    struct Desc *hd;
    void *h;
    R *p;
    int k;
    void *v;
    h = func_020120F4((void *)a);
    hd = func_020122C0((void *)a, 0, (void *)func_02168C74, 0x34);
    p = func_020124E8((struct Obj *)hd);
    p->f0 = (void *)a;
    p->f4 = func_0201210C((void *)a);
    p->fc = e;
    p->f30 = b;
    if (c == 0x14 || c == 0x15) {
        if (c == 0x14) {
            p->f10 = 0;
            k = 0x14;
        } else {
            p->f10 = 1;
            k = 0x15;
        }
    } else {
        p->f10 = 0;
        k = 0x14;
    }
    p->f14 = k;
    if (d == 0) {
        p->f1c = 0;
        v = func_02012934(h);
    } else {
        v = func_0200BAF4((int)func_0200BAC8(func_02012EBC(h)), 5);
        p->f1c = v;
    }
    p->f18 = v;
    return hd;
}
