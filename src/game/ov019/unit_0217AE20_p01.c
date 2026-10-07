/*
 * file:     unit_0217AE20_p01.c
 * unit:     yes
 * function: func_0217AE20, func_0217AE38, func_0217AE40, func_0217AED4, func_0217AEE8, func_0217AEFC, func_0217AF04, func_0217AF38, func_0217AF4C, func_0217AFB0, func_0217AFE4
 * address:  0x0217AE20
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
 *   func_02082BCC  0x02082BCC  arm
 *   func_02012964  0x02012964  thumb
 *   func_02025C74  0x02025C74  thumb
 *   func_0216E618  0x0216E618  thumb  ov010
 *   func_0216CE60  0x0216CE60  thumb  ov010
 *   d_0217FFF8     0x0217FFF8  data  ov019  a4
 *   d_0218001C     0x0218001C  data  ov019  a2
 *   d_0217FFE4     0x0217FFE4  data  ov019  a2
 *   func_0216DE94 0x0216DE94 thumb ov010
 *   func_02034714 0x02034714 arm
 *   d_021807E0 0x021807E0 data a1
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 */
#include "../../matched/include/Obj19389.h"
#include "../../matched/include/Obj19390.h"

struct BigObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef unsigned int u32;

typedef union { u32 w[9]; u16 h[18]; } Tmpl;

typedef struct { s16 x, y; } Pt;

typedef enum { FALSE, TRUE } BOOL;

typedef struct { u8 *p; u8 f4,f5,f6,f7; u8 pad[4]; } Ent_0217AF04;

typedef struct {
    u8 pad[0x6b];
    u8 f6b;
    u16 f6c;
} Obj;

typedef struct {
    Obj *f0;
    u8 pad4[2];
    u8 f6, f7, f8, f9;
    u8 pad[2];
} Ent_0217AF4C;

typedef struct {
    int f0;
    u8 f4, f5, f6, f7, f8, f9;
    u8 pad[2];
} Ent_0217AFE4;

typedef struct {
    u8 pad[6];
    u8 f6;
    u8 f7 : 1;
} Src;

void func_02082BCC(void *p, int v, int n);
extern u32 func_02012964(const struct BigObj *p);
extern u32 func_02025C74(u32 x);
extern void func_0216E618(void *, u32, u32, int);
extern int func_0216CE60(int, void *, int);
extern void *func_0216DE94(void *,unsigned int);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_0216DAC8(unsigned int *p, unsigned int v);
void func_0217AE20(u8 *w);
int func_0217AE38(char *p, char v);
int func_0217AE40(void *a, int b, u16 c, int d);
u16 func_0217AED4(u8 *a, u8 *b);
BOOL func_0217AEE8(u16 a);
u16 func_0217AEFC(unsigned int x);
int func_0217AF04(u8 *a, u16 key);
int func_0217AF38(u16 a);
int func_0217AF4C(char *a, u16 key);
void *func_0217AFB0(void **a,u8 *b,u8 *c);
Ent_0217AFE4 *func_0217AFE4(char *a, int b, Src *c, int d, int e, int *f);
extern const Tmpl d_0217FFF8;
extern const Pt d_0218001C[];
extern const Pt d_0217FFE4[];
extern const char d_021807E0[];


void func_0217AE20(u8 *w)
{
    func_02082BCC(w + 0x2e88, 0, 0x258);
}

int func_0217AE38(char *p, char v)
{
    p[9] = v;
    return 1;
}


/*
 * What closed it: the spilled third parameter is u16, not u32. As u32 the
 * scheduler hoists its reload (`ldr r0,[sp]`) above the `strh` of d into
 * the local; as u16 the reload stays after it (see
 * docs/notes/pkt_ov019_0217AE40.c.txt for the earlier near miss).
 */
int func_0217AE40(void *a, int b, u16 c, int d)
{
    int t;
    u16 hi, lo;
    Tmpl l;

    t = func_02012964((const struct BigObj *)b);
    hi = (u16)(d >> 8);
    lo = (u16)((d & 0xff) - 0x20);
    l = d_0217FFF8;
    l.h[0] = d;
    l.h[1] = func_02025C74(c);
    if (lo != 0)
        l.h[2] = 15;
    func_0216E618(&l, (u16)(d_0218001C[hi].x + d_0217FFE4[lo].x),
                  (u16)(d_0218001C[hi].y + d_0217FFE4[lo].y), 0);
    return func_0216CE60(t, &l, 422);
}

u16 func_0217AED4(u8 *a, u8 *b) { return (a[0x6b] << 8) | (b[6] + 0x20); }

BOOL func_0217AEE8(u16 a) { if ((u16)((unsigned char)a - 0x20) == 0) return FALSE; else return TRUE; }


u16 func_0217AEFC(unsigned int x)
{
    return (u16)(x >> 8);
}

int func_0217AF04(u8 *a, u16 key) { int i; Ent_0217AF04 *p; p = (Ent_0217AF04 *)(a+0x2e88); for(i=0;i<50;i++,p++) { if(p->f7 == 1 && p->p != 0 && key == func_0217AED4(p->p,(u8 *)p)) return p->f5; } return 0; }

int func_0217AF38(u16 a) { unsigned int v; v = (unsigned char)a; if ((u16)v >= 0x20) return 1; else return 0; }


int func_0217AF4C(char *a, u16 key)
{
    Ent_0217AF4C *p;
    int i;

    p = (Ent_0217AF4C *)(a + 0x2E88);
    for (i = 0; i < 50; i++, p++) {
        if (p->f7 == 1 && p->f0 != 0 && p->f0->f6c != 0
            && key == ((p->f0->f6b << 8) | (p->f6 + 0x20))) {
            if (p->f8 == 2 || p->f8 == 1 || (u8)(p->f9 + 0xff) <= 1)
                return 0;
            return 1;
        }
    }
    return 0;
}

void *func_0217AFB0(void **a,u8 *b,u8 *c) { u16 key; void *p; key = func_0217AED4(b,c); p = func_0216DE94((void *)func_02012964(((struct Obj19389 *)((u8 *)*a))->f8),key); if(p == 0) func_02034714(d_021807E0,0,d_021807E0); return p; }


Ent_0217AFE4 *func_0217AFE4(char *a, int b, Src *c, int d, int e, int *f)
{
    Ent_0217AFE4 *p;
    int i;
    int r;

    p = (Ent_0217AFE4 *)(a + 0x2E88);
    for (i = 0; i < 50; i++, p++) {
        if (p->f7 == 0) {
            p->f0 = b;
            p->f4 = c->f6;
            p->f5 = c->f7;
            p->f6 = d;
            p->f7 = 1;
            r = func_0217AED4((u8 *)b, (u8 *)p);
            r = func_0217AE40(a, ((int *)((struct Obj19390 *)a)->f0)[2], c->f6, r);
            if (e == 0)
                func_0216DAC8((unsigned int *)r, 1);
            *f = r;
            return p;
        }
    }
    func_02034714(d_021807E0, 0, d_021807E0);
    return 0;
}
