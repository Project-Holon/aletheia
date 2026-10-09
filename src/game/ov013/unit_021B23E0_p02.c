/*
 * file:     unit_021B23E0_p02.c
 * unit:     yes
 * function: func_021B2620, func_021B26DC, func_021B2724, func_021B275C, func_021B279C, func_021B2848, func_021B2894, func_021B2958, func_021B29A4
 * address:  0x021B2620
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021B60D8  0x021B60D8  data  ov013  a4
 *   d_021B4BD0  0x021B4BD0  data  ov013  a4
 *   func_021B25FC  0x021B25FC  arm  ov013
 *   func_02176E90  0x02176E90  arm  ov009
 *   d_021B4C0C  0x021B4C0C  data  ov013  a4
 *   func_020923B0 0x020923B0 arm
 *   d_021B3AF0  0x021B3AF0  data  ov013  a1
 *   d_021B3AF5  0x021B3AF5  data  ov013  a1
 *   d_021B3BC8  0x021B3BC8  data  ov013  a1
 *   d_021B3AFC  0x021B3AFC  data  ov013  a1
 *   func_021B25B0  0x021B25B0  arm  ov013
 *   d_021B4BE0  0x021B4BE0  data  a4
 *   d_021B3B40 0x021B3B40 data ov013 a1
 *   d_021B3B84 0x021B3B84 data ov013 a1
 */
#include "../../matched/include/G_Stat.h"
#include "../../matched/include/Obj09377.h"
#include "../../matched/include/G_Sess.h"

struct Msg_021B2620;
typedef unsigned char u8;

typedef struct Stat Stat;

typedef struct St {
    u8 b0;
    u8 pad[3];
    int (*cb)(int, int, int, int);
    int arg;
    int fC;
    int state;
} St;

typedef struct Q {
    int f0;
    u8 b4;
    u8 b5;
    u8 pad[2];
    int f8;
    int fC;
} Q;

typedef struct Msg_021B2620 {
    unsigned int magic;
    u8 b4, b5, b6, b7, b8, b9, b10, b11;
    int fC;
} Msg_021B2620;

typedef signed char s8;

typedef struct Ctx {
    int f0;
    int f4;
    int f8;
    int fC;
} Ctx;

typedef struct Msg_021B2894 {
    int f0;
    u8 b4;
    u8 b5;
    u8 b6;
} Msg_021B2894;

typedef struct N {
    int a;
    int b;
    int c;
    int kind;
    int e;
    struct N *next;
} N;

typedef struct {
    int x;
    N *head;
} G;

typedef unsigned int u32;

extern void func_021B25FC(u8 *a, u8 *b);
extern int func_02176E90(int i, u8 *p, int n);
extern void *func_020923B0(void *,int,unsigned int);
extern int func_021B25B0(int a, int b);
int func_021B2620(int *o, u8 *p);
void func_021B26DC(int x);
void func_021B2724(u8 *p,u8 v);
int func_021B275C(u8 *o, u8 *p);
int func_021B279C(u8 *o, Q *q);
int func_021B2848(u8 *o, Msg_021B2620 *p, int n);
int func_021B2894(Ctx *c, Msg_021B2894 *m);
int func_021B2958(N *p);
int func_021B29A4(int *obj,const u8 *q);
extern St d_021B60D8;
extern struct Stat d_021B4BD0;
extern char d_021B4C0C;
extern u8 d_021B3AF0[];
extern u8 d_021B3AF5[];
extern s8 d_021B3BC8[][11];
extern s8 d_021B3AFC[][11];
extern G d_021B4BE0;
extern s8 d_021B3B40[],d_021B3B84[];





int func_021B2620(int *o, u8 *p)
{
    int cnt;
    u8 i;

    cnt = 0;
    func_021B25FC((u8 *)o, p);
    for (i = 0; i < 0x20; i++) {
        unsigned int m = (i != 0) ? (1 << i) : 1;
        if ((d_021B4BD0.mask & m) != 0 && i != d_021B60D8.b0) {
            p[9] = i;
            if (func_02176E90(i, p, 0x10) != 0)
                cnt++;
        }
    }
    if (p[10] == 1)
        o[2] = d_021B4BD0.mask;
    else if (p[10] == 0)
        o[2] = 0;
    return cnt == 0 ? -4 : 0;
}






void func_021B26DC(int x)
{
    u8 buf[16];

    buf[4] = 0xff;
    func_021B2848((u8 *)(&d_021B4C0C), (struct Msg_021B2620 *)buf, 4);
    buf[10] = x;
    func_021B2620((int *)(&d_021B4C0C), buf);
}





void func_021B2724(u8 *p,u8 v)
{
    func_020923B0(p,0,24);
    ((struct Obj09377 *)p)->f0=d_021B60D8.state;
    ((struct Obj09377 *)p)->fC=0;
    p[4]=v;
}






int func_021B275C(u8 *o, u8 *p)
{
    if (p[4] == 0xff && p[6] == 4) {
        func_021B2620((int *)o, p);
    } else if (func_02176E90(o[4], p, 0x10) == 0) {
        return 0;
    }
    return 1;
}





int func_021B279C(u8 *o, Q *q)
{
    q->b5 = o[0xb];
    if (o[4] == 0xff) {
        if (o[6] == 0) {
            q->f8 = (q->b4 != 0) ? (1 << q->b4) : 1;
        }
        return d_021B3AF0[o[6]];
    }
    if (o[4] == 0) {
        if (o[6] == 0) {
            if (q->fC == 1) {
                q->f8 = (q->b4 != 0) ? (1 << q->b4) : 1;
                return 7;
            }
            if (q->fC == 5)
                return 9;
            return 12;
        }
        return d_021B3AF5[o[6]];
    }
    return 12;
}




/*
 * lever: Returning zero keeps the clearing value in r0 and frees r2 for byte loads.
 */
int func_021B2848(u8 *o, Msg_021B2620 *p, int n)
{
    p->magic = 0x5f564354;
    p->b5 = 0x10;
    p->b6 = n;
    p->b8 = d_021B60D8.b0;
    p->b9 = o[4];
    p->b10 = 0;
    p->b11 = d_021B60D8.b0;
    p->fC = 0;
    return 0;
}



int func_021B2894(Ctx *c, Msg_021B2894 *m)
{
    int i;
    int r;

    i = m->b6;
    if (m->b4 == 0)
        i += 5;
    if ((unsigned int)i >= 0xb)
        i = -1;
    if (i < 0)
        return -1;
    if (d_021B60D8.state == 1)
        r = d_021B3BC8[c->fC][i];
    else
        r = d_021B3AFC[c->fC][i];
    switch (r) {
    case -1:
        return r;
    case -2:
        func_021B25B0((int)c, 1);
        c->fC = 0;
        c->f0 = 0;
        return r;
    case -3:
        func_021B25B0((int)c, 3);
        c->fC = 0;
        c->f0 = 0;
        return r;
    default:
        return r;
    }
}



int func_021B2958(N *p)
{
    N *n;

    n = d_021B4BE0.head;
    while (n) {
        if (n->a != 0 && n->kind == 2) {
            if (p != n)
                return 0;
        }
        n = n->next;
    }
    return 1;
}


static inline s8 lookup(u32 t,int row,u32 col) { return *(s8 *)(row*11+t+col); }


/*
 * lever: Calling the indexed inline in each table-selection arm restores the MLA register and independent -1/-2 constants.
 * checks: Per-arm inline lookup is EXACT; one data table in each arm preserves the original dispatch.
 */
int func_021B29A4(int *obj,const u8 *q) {
 u32 i; int v; u32 t;
 i=q[6]; if(q[4]==0)i+=5; if(i>=11)i=-1; if((int)i<0)return -1;
 if(d_021B60D8.state==1) v=lookup((u32)d_021B3B40,obj[3],i);
 else v=lookup((u32)d_021B3B84,obj[3],i);
 if(v==-1)return 1; if(v==-2)return 0; obj[3]=v; return 1;
}
