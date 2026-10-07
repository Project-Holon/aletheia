/*
 * file:     irc_ranking_p07.c
 * unit:     yes
 * function: func_021B8E50, func_021B8E90, func_021B8FA8, func_021B8FB8
 * address:  0x021B8E50
 * region:   ov106
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02035C38 0x02035C38 arm
 *   func_0203630C 0x0203630C arm
 *   func_0207CA00 0x0207CA00 arm
 *   _fflt 0x0209BDBC arm
 *   _ffix 0x0209C494 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 */
#include "../../matched/include/Obj22267.h"

typedef struct { int x,y; } Pair_021B8E50;

typedef unsigned int u32;

typedef struct { int x, y; } Pair_021B8E90;

typedef struct { long x, y, z; } Vec;

typedef struct {
    Pair_021B8E90 start, end;
    int x, y, dx, dy, count;
    u32 consumed;
    int flags;
} State;

typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef int s32;

extern int func_02035C38(void);
extern unsigned int func_0203630C(void);
extern void func_0207CA00(const Vec *, const Vec *, Vec *);
extern float _fflt(int);
extern int _ffix(float);
extern float _fadd(float, float), _fsub(float, float);
extern void func_02082BCC(void *, int, int);
int func_021B8E50(char *p, Pair_021B8E50 *a, Pair_021B8E50 *b, Pair_021B8E50 *c);
int func_021B8E90(State *p, Pair_021B8E90 *start, Pair_021B8E90 *end, Vec *delta, int *count);
void *func_021B8FA8(u8 *p,int *out);
void func_021B8FB8(void *p);

/*
 * extent: two bytes of alignment padding after the return.
 */
int func_021B8E50(char *p, Pair_021B8E50 *a, Pair_021B8E50 *b, Pair_021B8E50 *c) {
 if (func_02035C38()) {
 if(a) *a=*(Pair_021B8E50 *)p;
 if(b) *b=*(Pair_021B8E50 *)(p+8);
 if(c) *c=*(Pair_021B8E50 *)(p+24);
 return 1;
 }
 return 0;
}

static inline int convert(int v)
{
    float f;
    if (v > 0)
        f = _fadd(0.5f, _fflt((int)((u32)v << 12)));
    else
        f = _fsub(_fflt((int)((u32)v << 12)), 0.5f);
    return _ffix(f);
}

int func_021B8E90(State *p, Pair_021B8E90 *start, Pair_021B8E90 *end, Vec *delta, int *count)
{
    Vec a, b;
    int y;
    if (!func_0203630C()) {
        if (p->consumed < 1) {
            p->consumed = 1;
            if (start)
                *start = p->start;
            if (end)
                *end = p->end;
            if (delta) {
                y = convert(p->start.y);
                a.x = convert(p->start.x);
                a.y = y;
                a.z = 0;
                y = convert(p->end.y);
                b.x = convert(p->end.x);
                b.z = 0;
                b.y = y;
                func_0207CA00(&a, &b, delta);
            }
            if (count)
                *count = p->count;
            return 1;
        }
    }
    return 0;
}

void *func_021B8FA8(u8 *p,int *out) { if(out) *out=((struct Obj22267 *)p)->f28; return (void *)func_0203630C(); }

void func_021B8FB8(void *p) { func_02082BCC(p, 0, 0x14); }
