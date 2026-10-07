/*
 * file:     dowsing_p02.c
 * unit:     yes
 * function: func_021F000C, func_021F0124, func_021F0174, func_021F05A4, func_021F0674
 * address:  0x021F000C
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_021F06AC 0x021F06AC thumb ov033
 *   func_021F0760 0x021F0760 thumb ov033
 *   func_021F07F4 0x021F07F4 thumb ov033
 *   func_021F0924 0x021F0924 thumb ov033
 *   func_0204A298 0x0204A298 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021F0B74 0x021F0B74 thumb ov033
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_020120F4 0x020120F4 thumb
 *   func_0201296C 0x0201296C thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BE48 0x0200BE48 thumb
 *   func_021EFEC0 0x021EFEC0 thumb ov033
 *   func_0207D63C 0x0207D63C arm
 *   func_0203D34C 0x0203D34C arm
 *   d_021F0E60 0x021F0E60 data ov033 a1
 *   func_021EFEE4 0x021EFEE4 thumb ov033
 *   func_021F0C0C 0x021F0C0C thumb ov033
 *   func_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 *   func_021F0A90 0x021F0A90 thumb ov033
 *   func_021F08EC 0x021F08EC thumb ov033
 *   func_021F07DC 0x021F07DC thumb ov033
 *   func_021F0738 0x021F0738 thumb ov033
 *   func_02024ABC 0x02024ABC thumb
 *   func_02159C48 0x02159C48 thumb ov010
 *   func_02159BD4 0x02159BD4 thumb ov010
 *   func_020120F8 0x020120F8 thumb
 *   func_02012AA0 0x02012AA0 thumb
 *   func_02012974 0x02012974 thumb
 *   func_02013E7C 0x02013E7C thumb
 *   func_02013D74 0x02013D74 thumb
 *   func_02006148 0x02006148 thumb
 *   func_0200616C 0x0200616C thumb
 *   func_02006268 0x02006268 thumb
 *   func_02006224 0x02006224 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021EFF40 0x021EFF40 thumb ov033
 *   func_021EFEEC 0x021EFEEC thumb ov033
 *   func_021EFF48 0x021EFF48 thumb ov033
 *   func_021F0AC4 0x021F0AC4 thumb ov033
 *   d_021F0DC8 0x021F0DC8 data ov033 a4
 *   func_021F0C44 0x021F0C44 thumb ov033
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_02021D50 0x02021D50 thumb
 */
#include "../../matched/include/Obj00618.h"
#include "../../matched/include/Obj09801.h"
#include "../../matched/include/Obj00323.h"
#include "../../matched/include/Obj06142.h"

struct Big;
struct BigObj;
struct Ctx;
struct Node;
struct Rec44;
struct Vec12;
struct Obj;
struct Vec2;
struct S02021D50;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef struct {
    u32 a : 3;
    u32 b : 3;
    u32 c : 3;
    u32 x : 8;
    u32 y : 8;
    u32 pan : 7;
} Ent_021F0174;

typedef struct {
    u32 kind;
    u32 a;
    u32 b;
} Rec;

typedef struct {
    u8 pad0[2];
    u8 b2;
    u8 pad3;
    u16 h4;
    u16 h6;
    u16 h8;
} Ev;

typedef struct {
    int x, y, z;
} Vec;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u8 pad0C[0x60 - 0x0C];
    u8 *map;
    int f64;
    int f68;
    int f6C;
    Rec cur;
    Rec found;
    int f88;
    int f8C;
    int f90;
    int f94;
    int f98;
    int f9C;
    u16 hA0;
    u16 padA2;
    int fA4;
    u32 fA8;
    u32 fAC;
    int fB0;
    u32 fB4;
    u32 fB8;
    u32 fBC;
    int fC0;
    u32 fC4;
    int fC8;
    int fCC;
    void *fD0;
} W;

typedef struct {
    u32 a : 3;
    u32 b : 3;
    u32 c : 3;
    u32 x : 8;
    u32 y : 8;
    u32 pad : 7;
} Ent_021F05A4;

typedef struct {
    u16 x;
    u16 y;
} Pt;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021F06AC(char *p);
extern void func_021F0760(char *p);
extern void func_021F07F4(void *);
extern void func_021F0924(void *);
extern int func_0204A298(int a0, int a1, int a2, int a3, u32 *out);
extern void *func_020056A0(void *fn, void *ctx, u32 a);
extern void func_021F0B74(char *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201296C(const struct BigObj *p);
extern void *func_02012EBC(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern void *func_021EFEC0(u32, u32, u32);
extern void func_0207D63C(u32 reg, int plane1, int plane2, int ev1, int ev2);
extern void func_0203D34C(u32, u32);
extern void func_021EFEE4(void *p);
extern void func_021F0C0C(char *p);
extern void func_02030EAC(struct Node *n);
extern u32 func_020307B0(void *p);
extern void func_021F0A90(char *p);
extern void func_021F08EC(char *p);
extern void func_021F07DC(char *p);
extern void func_021F0738(char *p);
extern void func_02024ABC(void);
extern u8 *func_020120F8(const struct Ctx *p);
extern struct Vec12 *func_02012AA0(struct Rec44 *p);
extern u32 func_02012974(const struct BigObj *p);
extern int func_02159C48(int a0, int a1, int a2);
extern int func_02159BD4(int a0, int a1, int a2);
extern u32 func_02013E7C(u32 id);
extern int func_02013D74(u32 key);
extern void func_021EFF40(char *p);
extern int func_021EFEEC(char *p, int *q);
extern int func_021EFF48(void *p, Rec *out, int mode);
extern int func_02006148(u32 a0);
extern void func_0200616C(void *arg, int i);
extern void func_02006268(int i, u32 a, u32 b, u32 c);
extern int func_02006224(u32 a0);
extern void func_020061E4(u32 se);
extern void func_021F0AC4(W *p);
extern void func_021F0C44(char *p);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B8C4(struct Obj *p, u32 value);
extern void func_02021D50(struct S02021D50 *);
void *func_021F000C(u32 heap, u32 heap2, u32 a, u32 b);
void func_021F0124(char *p);
void func_021F0174(W *p, int on);
void func_021F05A4(char *p, int flag);
void func_021F0674(int a, unsigned char *p);
extern const char d_021F0E60[];
extern const Ent_021F0174 d_021F0DC8[];


void *func_021F000C(u32 heap, u32 heap2, u32 a, u32 b)
{
    char *p;
    u32 size;
    u32 s;
    u32 v;

    p = func_02030734(heap, 0xD4, 1, d_021F0E60, 0x272);
    ((struct Obj00618 *)p)->f0 = heap;
    ((struct Obj00618 *)p)->f2 = heap2;
    ((struct Obj00618 *)p)->f4 = a;
    ((struct Obj00618 *)p)->f8 = b;
    func_021F06AC(p);
    func_021F0760(p);
    func_021F07F4(p);
    func_021F0924(p);
    ((struct Obj00618 *)p)->f60 = (void *)func_0204A298(0xC3, 0xD, 0, ((struct Obj00618 *)p)->f0, &size);
    ((struct Obj00618 *)p)->fA8 = func_020056A0(func_021F0674, p, 1);
    ((struct Obj00618 *)p)->fAC = 0;
    ((struct Obj00618 *)p)->fB0 = 1;
    func_021F0B74(p);
    ((struct Obj00618 *)p)->f64 = 10;
    ((struct Obj00618 *)p)->f68 = 9;
    ((struct Obj00618 *)p)->f6C = 10;
    ((struct Obj00618 *)p)->f70 = 0;
    ((struct Obj00618 *)p)->f7C = 0;
    ((struct Obj00618 *)p)->f88 = 0;
    ((struct Obj00618 *)p)->f8C = 0;
    ((struct Obj00618 *)p)->f90 = 0;
    ((struct Obj00618 *)p)->f94 = 0;
    ((struct Obj00618 *)p)->f9C = 0;
    ((struct Obj00618 *)p)->fA4 = 0;
    func_021F05A4(p, 1);
    ((struct Obj00618 *)p)->fC8 = 1;
    ((struct Obj00618 *)p)->fCC = 1;
    s = (u32)func_020120F4(func_02188C80((void *)(((struct Obj00618 *)p)->f8)));
    v = func_0201296C((const struct BigObj *)s);
    ((struct Obj00618 *)p)->fD0 = func_021EFEC0(((struct Obj00618 *)p)->f0, v, (u32)func_0200BE48(func_02012EBC((struct Big *)s)));
    func_0207D63C(0x04001050, 0x10, 0x18, 1, 7);
    func_0203D34C(0, ((struct Obj00618 *)p)->f0);
    return p;
}


void func_021F0124(char *p)
{
    *(volatile unsigned short *)0x04001050 = 0;
    func_021EFEE4((void *)(((struct Obj09801 *)p)->fD0));
    func_021F0C0C(p);
    func_02030EAC((struct Node *)(((struct Obj09801 *)p)->fA8));
    func_020307B0(((struct Obj09801 *)p)->f60);
    func_021F0A90(p);
    func_021F08EC(p);
    func_021F07DC(p);
    func_021F0738(p);
    func_020307B0(p);
}


void func_021F0174(W *p, int on)
{
    Rec r[2];
    int snd;
    int changed;
    int x0;
    u32 map;
    void *obj;
    int gx, gy, gz;
    int zone;
    int flag;
    u32 n;
    int xmin, xmax, zmin, zmax;
    int best;
    u16 bestIdx;
    Ev *e;
    s16 *s;
    int x1, z1;
    Vec *pos;
    int go;
    int start;
    u16 i;
    int x, z;
    int dx, dz;
    u16 idx;
    u32 d;
    int h;
    int pan;
    int c68;
    u32 k;

    p->fB0 = on;
    if (on)
        p->fC0 = 1;
    else
        p->fC0 = 2;
    func_02024ABC();
    if (on == 0)
        return;
    p->f64 = p->f68;
    p->cur.kind = p->found.kind;
    if (p->cur.kind == 1)
        p->cur.a = p->found.a;
    else if (p->cur.kind == 2)
        p->cur.b = p->found.b;
    obj = func_02188C80((void *)p->f08);
    pos = (Vec *)func_02012AA0((struct Rec44 *)func_020120F8(obj));
    gx = (pos->x >> 4) / 4096;
    gy = (pos->y >> 4) / 4096;
    gz = (pos->z >> 4) / 4096;
    map = func_02012974(func_020120F4(obj));
    zone = 0xFFFF;
    flag = 0;
    if (func_02159C48((int)map, pos->x, pos->z) == 1) {
        zone = func_02159BD4((int)map, pos->x, pos->z);
        flag = (int)func_02013E7C((u16)zone);
    }
    if (p->f94 == 0) {
        p->f94 = 1;
        go = 1;
    } else {
        go = 1;
    }
    if (go) {
        xmin = gx - 15;
        xmax = gx + 17;
        zmin = gz - 11;
        zmax = gz + 13;
        best = -1;
        r[0].kind = 0;
        if (p->fC8 != 0) {
            func_021EFF40(p->fD0);
            p->fC8 = 0;
        }
        if (p->fCC != 0) {
            n = 0xFFFF;
            p->fCC = 0;
        } else {
            n = 11;
        }
        for (i = 0; i < n; i++) {
            if (i == 0) {
                if (p->cur.kind != 0) {
                    if (func_021EFEEC(p->fD0, (int *)(&p->cur))) {
                        r[1].kind = p->cur.kind;
                        if (r[1].kind == 1)
                            r[1].a = p->cur.a;
                        else if (r[1].kind == 2)
                            r[1].b = p->cur.b;
                    } else {
                        p->fC8 = 1;
                        p->fCC = 1;
                        break;
                    }
                }
            } else {
                if ((p->fC8 = func_021EFF48(p->fD0, &r[1], 0) ? 0 : 1) != 0)
                    break;
            }
            if (zone == 0xFFFF)
                continue;
            if (r[1].kind == 1) {
                e = (Ev *)r[1].a;
                if (zone != e->h4) {
                    if (e->b2 == 0)
                        continue;
                    if (flag == 0)
                        continue;
                    if (func_02013D74(e->h4) != 0)
                        continue;
                }
                x = e->h6;
                z = e->h8;
            } else if (r[1].kind == 2) {
                s = (s16 *)r[1].b;
                if ((int)func_02013E7C((u16)s[3]) == 0)
                    continue;
                if (flag == 0)
                    continue;
                x = s[0];
                z = s[2];
            }
            if (xmin <= x && x < xmax && zmin <= z && z < zmax) {
                dz = z - gz;
                dx = x - gx;
                idx = (u16)(dx + 15 + (dz + 11) * 32);
                if (p->map[idx] == 9)
                    continue;
                d = dx * dx + dz * dz;
                if (d < (u32)best) {
                    bestIdx = idx;
                    best = d;
                    r[0].kind = r[1].kind;
                    if (r[1].kind == 1)
                        r[0].a = r[1].a;
                    else if (r[1].kind == 2)
                        r[0].b = r[1].b;
                }
            }
        }
        k = r[0].kind;
        p->found.kind = k;
        if (k != 0) {
            p->f68 = p->map[bestIdx];
            if (k == 1)
                p->found.a = r[0].a;
            else if (k == 2)
                p->found.b = r[0].b;
        } else {
            p->f68 = 9;
        }
    }
    snd = 1;
    if (p->f68 == 8) {
        start = 0;
        if (p->f9C == 0) {
            start = 1;
            p->f9C = 1;
        } else if (p->hA0 == 6) {
            if (func_02006224(p->f98) == 0)
                p->hA0--;
        } else if (p->hA0 == 0) {
            start = 1;
        } else {
            p->hA0--;
        }
        if (start) {
            p->f98 = func_02006148(0x760);
            func_0200616C((void *)0x760, p->f98);
            func_02006268(p->f98, -1, 0x180, -1);
            p->hA0 = 6;
            p->fA4 = 1;
        }
        snd = 0;
    } else {
        p->f9C = 0;
    }
    if (snd && (c68 = p->f68) != 8 && p->found.kind != 0) {
        changed = 0;
        if (p->cur.kind == 1) {
            e = (Ev *)p->cur.a;
            x0 = e->h6;
            z = e->h8;
        } else if (p->cur.kind == 2) {
            s = (s16 *)p->cur.b;
            x0 = s[0];
            z = s[2];
        } else {
            changed = 1;
            goto done;
        }
        if (p->found.kind == 1) {
            e = (Ev *)p->found.a;
            x1 = e->h6;
            z1 = e->h8;
        } else if (p->found.kind == 2) {
            s = (s16 *)p->found.b;
            x1 = s[0];
            z1 = s[2];
        }
        if ((x0 != x1 || z != z1) && p->f64 != c68)
            changed = 1;
    done:
        if (changed) {
            h = func_02006148(0x760);
            pan = ((int)d_021F0DC8[p->f68].pan - 8) * 16;
            if (pan < -127)
                pan = -127;
            else if (pan > 127)
                pan = 127;
            func_0200616C((void *)0x760, h);
            func_02006268(h, -1, -1, pan);
            snd = 0;
        }
    }
    if (snd && p->f64 != p->f68)
        func_020061E4(0x762);
    p->f88 = gx;
    p->f8C = gy;
    p->f90 = gz;
    func_021F0AC4(p);
}


void func_021F05A4(char *p, int flag)
{
    Pt pt;

    func_021F0C44(p);
    if (flag == 0)
        return;
    if (((struct Obj00323 *)p)->f6C != ((struct Obj00323 *)p)->f68) {
        func_0204B3DC(((struct Obj00323 *)p)->f50,
                      (((struct Obj00323 *)p)->f68 == 8 || ((struct Obj00323 *)p)->f68 == 9) ? 0 : 1);
        func_0204B3DC(((struct Obj00323 *)p)->f5C, ((struct Obj00323 *)p)->f68 == 8);
        pt.x = d_021F0DC8[*(int *)(p + 0x68)].x;
        pt.y = d_021F0DC8[*(int *)(p + 0x68)].y;
        func_0204B404(((struct Obj00323 *)p)->f50, (const struct Vec2 *)(&pt), 1);
        func_0204B878(((struct Obj00323 *)p)->f38, d_021F0DC8[*(int *)(p + 0x68)].a);
        func_0204B878(((struct Obj00323 *)p)->f44, d_021F0DC8[*(int *)(p + 0x68)].b);
        func_0204B878(((struct Obj00323 *)p)->f50, d_021F0DC8[*(int *)(p + 0x68)].c);
        ((struct Obj00323 *)p)->f6C = ((struct Obj00323 *)p)->f68;
    }
    if (((struct Obj00323 *)p)->f68 == 8 && ((struct Obj00323 *)p)->fA4 != 0) {
        func_0204B878(((struct Obj00323 *)p)->f5C, 0);
        func_0204B92C(((struct Obj00323 *)p)->f5C, 1);
        func_0204B8C4(((struct Obj00323 *)p)->f5C, 0);
        ((struct Obj00323 *)p)->fA4 = 0;
    }
}

void func_021F0674(int a, unsigned char *p)
{
    func_02021D50(*(struct S02021D50 * *)&((struct Obj06142 *)p)->fBC);
    if (((struct Obj06142 *)p)->fB0 != 0) {
        if (p[0xac] >= 4)
            p[0xac] = 0;
        p[0xac]++;
    }
}
