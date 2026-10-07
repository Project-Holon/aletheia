/*
 * file:     dowsing_p01.c
 * unit:     yes
 * function: func_021EFEC0, func_021EFEE4, func_021EFEEC, func_021EFF40, func_021EFF48
 * address:  0x021EFEC0
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
 *   d_021F0E60 0x021F0E60 data ov033 a1
 *   func_020307B0 0x020307B0 arm
 *   func_020142E8 0x020142E8 thumb
 *   func_021CFAC0 0x021CFAC0 thumb ov021
 *   func_0216476C 0x0216476C thumb ov010
 *   func_021CFB68 0x021CFB68 thumb ov021
 */
#include "../../matched/include/Obj07642.h"
#include "../../matched/include/Obj13070.h"
#include "../../matched/include/Obj13071.h"

typedef unsigned int u32;

typedef unsigned short u16;

typedef struct { void *f00; u16 f04; void *f08; u16 f0c; } Work;

typedef signed int     s32;

typedef unsigned char  u8;

typedef struct {
    unsigned kind;
    unsigned a;
    unsigned b;
} Rec;

typedef struct {
    unsigned short h0;
    unsigned short h2;
    unsigned short h4;
    unsigned short h6;
    unsigned f8;
    unsigned short hc;
} T;

extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_020307B0(void *p);
extern u32 func_020142E8(void *bitmap, s32 id);
extern int func_021CFAC0(u8 *base, int a, int b, int c, int d);
extern char *func_0216476C(unsigned short *);
extern unsigned func_021CFB68(unsigned, unsigned *);
Work *func_021EFEC0(u32 heap, void *a, void *b);
void func_021EFEE4(void *p);
int func_021EFEEC(char *p, int *q);
void func_021EFF40(char *p);
int func_021EFF48(T *p, unsigned *out, int mode);
extern const char d_021F0E60[];

Work *func_021EFEC0(u32 heap, void *a, void *b)
{
    Work *p;
    p = func_02030734(heap, 0x10, 1, d_021F0E60, 0x8d);
    p->f00 = a;
    p->f04 = 0;
    p->f08 = b;
    p->f0c = 0;
    return p;
}


void func_021EFEE4(void *p)
{
    func_020307B0(p);
}


int func_021EFEEC(char *p, int *q)
{
    int r;
    if (q[0] == 1) {
        unsigned short *s = *(unsigned short * *)&((struct Obj07642 *)q)->f4;
        return func_020142E8((void *)(((struct Obj13070 *)p)->f0), (unsigned short)(*s + 0x384)) == 0;
    }
    if (q[0] == 2) {
        short *s = *(short * *)&((struct Obj07642 *)q)->f8;
        r = 0;
        if (func_021CFAC0((u8 *)(((struct Obj13070 *)p)->f8), (unsigned short)s[3], s[0], s[1], s[2]) != 0xFF)
            r = 1;
        return r;
    }
    return 0;
}


void func_021EFF40(char *p)
{
    ((struct Obj13071 *)p)->f4 = 0;
    ((struct Obj13071 *)p)->fC = 0;
}


int func_021EFF48(T *p, unsigned *out, int mode)
{
    unsigned short cnt;
    unsigned idx;
    Rec rec;
    char *tbl;
    unsigned v;
    int found;

    found = 0;
    tbl = func_0216476C(&cnt);
    idx = p->hc;
    if (mode == 0 || mode == 1) {
        while (p->h4 < cnt) {
            rec.kind = 1;
            rec.a = (unsigned)(tbl + p->h4 * 10);
            if (func_021EFEEC((char *)p, (int *)(&rec))) {
                out[0] = rec.kind;
                out[1] = rec.a;
                found = 1;
            }
            p->h4++;
            if (found)
                return 1;
        }
    }
    if (mode == 0 || mode == 2) {
        v = func_021CFB68(p->f8, &idx);
        p->hc = idx;
        while (v != 0) {
            rec.b = v;
            rec.kind = 2;
            if (func_021EFEEC((char *)p, (int *)(&rec))) {
                out[0] = rec.kind;
                out[2] = rec.b;
                found = 1;
            }
            if (found)
                return 1;
            v = func_021CFB68(p->f8, &idx);
            p->hc = idx;
        }
    }
    out[0] = 0;
    return 0;
}
