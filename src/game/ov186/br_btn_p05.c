/*
 * file:     br_btn_p05.c
 * unit:     yes
 * function: func_021FAA74, func_021FAAD0, func_021FAB7C, func_021FAC20, func_021FACE0, func_021FAD04, func_021FAD18, func_021FAD74, func_021FADB8, func_021FAE70
 * address:  0x021FAA74
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021FAF24 0x021FAF24 thumb
 *   func_021FD12C 0x021FD12C thumb
 *   func_021FD170 0x021FD170 thumb
 *   func_021FD73C 0x021FD73C thumb
 *   func_021FA284 0x021FA284 thumb
 *   func_021FA274 0x021FA274 thumb
 *   func_021FAEE4 0x021FAEE4 thumb
 *   func_021FAA34 0x021FAA34 thumb
 *   func_02034714 0x02034714 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02045874 0x02045874 arm
 *   func_021FB7B0 0x021FB7B0 thumb ov186
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FB3BC 0x021FB3BC thumb ov186
 *   d_02200D18 0x02200D18 data a1
 *   func_02045808 0x02045808 arm
 *   func_021FB494 0x021FB494 thumb ov186
 *   memset 0x02082BCC arm
 *   func_021FB4CC  0x021FB4CC  thumb  ov186
 *   func_021FAFD0 0x021FAFD0 thumb ov186
 *   func_021FB058 0x021FB058 thumb ov186
 *   func_021FB0E8 0x021FB0E8 thumb ov186
 *   func_021FB1EC 0x021FB1EC thumb ov186
 *   func_021FB2F0 0x021FB2F0 thumb ov186
 *   func_021FB548 0x021FB548 thumb ov186
 *   func_021FB594 0x021FB594 thumb ov186
 *   func_021FB5B8 0x021FB5B8 thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 */
#include "../../matched/include/Obj03340.h"
#include "../../matched/include/Obj05499.h"
#include "../../matched/include/Obj06630.h"
#include "../../matched/include/Obj10784.h"
#include "../../matched/include/Obj03891.h"
#include "../../matched/include/Obj08331.h"
#include "../../matched/include/Obj00080.h"

struct U16Vec;
typedef unsigned short u16;

typedef struct { unsigned short x,y,z; unsigned char flag,pad; } Config_021FAC20;

typedef struct {
    unsigned active, enabled, result, object;
    unsigned words[6];
    unsigned index, unused, owner;
    unsigned short heap, pad;
    unsigned a,b,work;
} Fields;

typedef unsigned int   u32;

typedef struct Placement { short x, y; unsigned short animation; unsigned char priority, attr; } Placement;

typedef struct Config_021FADB8 { int words[3]; } Config_021FADB8;

typedef struct Record { int state; int mode; int words[15]; } Record;

extern int func_021FAF24(char *ctx, int kind);
extern void *func_021FD12C(int a, void *owner, u16 heap);
extern void func_021FD170(char *p, char *q, void *text);
extern int *func_021FD73C(int *p, int v);
extern void func_021FA284(void *p, int *state, unsigned char *ctx);
extern void func_021FA274(void *p);
extern void func_021FAEE4(char *p, int *out);
extern void func_021FAA34(void *p, int *state, int *ctx);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02082BCC(void *, int, unsigned);
extern struct U16Vec *func_02045874(struct U16Vec *src, u32 heapId);
extern int func_021FB7B0(void *p, int i);
extern void func_021FC124(void *, unsigned, void *);
extern unsigned func_021FC20C(char *p);
extern void *func_021FB3BC(void *, void *, int, int, int, int, int, void *, unsigned short);
extern void func_02045808(struct U16Vec *);
extern void func_021FB494(char *p);
extern void *memset(void *,int,unsigned);
extern int func_021FB4CC(u32 *p, int a1, int a2);
extern int func_021FAFD0(char *), func_021FB058(char *), func_021FB0E8(char *), func_021FB1EC(char *), func_021FB2F0(char *);
extern void func_021FB548(char *p, short *x, short *y);
extern int func_021FB594(char *p);
extern unsigned func_021FB5B8(char *p);
extern int func_021FC214(char *);
void func_021FAA74(void *p, int *state, unsigned *ctx);
void func_021FAAD0(void *p, int *state, unsigned char *ctx);
void func_021FAB7C(void *p, int *state, unsigned char *ctx);
void func_021FAC20(Fields *ctx, unsigned object, unsigned a, unsigned b, void *owner, const void *arg, unsigned index, unsigned short heap);
void func_021FACE0(char *p);
int func_021FAD04(int *p, int x, int y);
void func_021FAD18(char *ctx, int mode, const int *target);
int func_021FAD74(char *ctx);
void func_021FADB8(char *ctx, int mode);
void func_021FAE70(void *ctx, Record *dest, const Record *source, int mode);
extern char d_02200D18[];

void func_021FAA74(void *p, int *state, unsigned *ctx)
{
    int value;
    switch (*state) {
    case 0:
        value = func_021FAF24((char *)ctx[16] + ctx[11] * 0x44, 6);
        if (ctx[20] == 0)
            ctx[20] = (unsigned)func_021FD12C((int)((void *)ctx[1]), (void *)ctx[19], ((struct Obj03340 *)ctx)->f0);
        func_021FD170((void *)ctx[20], (void *)ctx[1], (void *)value);
        *state = 1;
        break;
    case 1: *state = 2; break;
    case 2: func_021FD73C(p, (int)func_021FA284); break;
    }
}

void func_021FAAD0(void *p, int *state, unsigned char *ctx)
{
    int i, ready;
    int values[2];
    switch (*state) {
    case 0:
        for (i = 0; i < ctx[0x39]; i++) {
            values[0] = func_021FAF24(*(char * *)&((struct Obj05499 *)ctx)->f40 + i * 0x44, 8);
            values[1] = func_021FAF24(*(char * *)&((struct Obj05499 *)ctx)->f40 + i * 0x44, 9);
            func_021FAD18(*(char * *)&((struct Obj05499 *)ctx)->f40 + i * 0x44, 4, values);
        }
        *state = 1;
        break;
    case 1:
        ready = 1;
        for (i = 0; i < ctx[0x39]; i++)
            ready &= func_021FAD74(*(char * *)&((struct Obj05499 *)ctx)->f40 + i * 0x44);
        if (ready) *state = 2;
        break;
    case 2: func_021FD73C(p, (int)func_021FA274); break;
    }
}

void func_021FAB7C(void *p, int *state, unsigned char *ctx)
{
    int i, ready;
    int values[2];
    switch (*state) {
    case 0:
        for (i = 0; i < ctx[0x39]; i++) {
            func_021FAEE4(*(char * *)&((struct Obj06630 *)ctx)->f40 + i * 0x44, values);
            values[1] = 0xe0;
            func_021FAD18(*(char * *)&((struct Obj06630 *)ctx)->f40 + i * 0x44, 4, values);
        }
        *state = 1;
        break;
    case 1:
        ready = 1;
        for (i = 0; i < ctx[0x39]; i++)
            ready &= func_021FAD74(*(char * *)&((struct Obj06630 *)ctx)->f40 + i * 0x44);
        if (ready) *state = 2;
        break;
    case 2: func_021FD73C(p, (int)func_021FAA34); break;
    }
}

/*
 * lever: 02045874 takes the source and heap, forwarding r1 unchanged to its allocator.
 * evidence: matched arm9/sub_02045874.c; original 021FAC58 loads heap into r1,
 * then loads source into r0 at021FAC5A before storing heap and calling021FAC62.
 */
void func_021FAC20(Fields *ctx, unsigned object, unsigned a, unsigned b, void *owner, const void *arg, unsigned index, unsigned short heap)
{
    unsigned info[3];
    Config_021FAC20 config;
    const void *work;
    unsigned short heap_value;
    if (ctx->active) func_02034714(d_02200D18, 0, d_02200D18);
    func_02082BCC(ctx, 0, 0x44);
    ctx->active = 1;
    ctx->enabled = 1;
    ctx->object = object;
    ctx->index = index;
    ctx->owner = (unsigned)owner;
    heap_value = heap;
    work = arg;
    ctx->heap = heap_value;
    ctx->a = a;
    ctx->b = b;
    ctx->work = (unsigned)func_02045874((struct U16Vec *)work, heap_value);
    func_02082BCC(&config, 0, 8);
    config.x = func_021FB7B0((void *)ctx->object, 0);
    config.y = func_021FB7B0((void *)ctx->object, 1);
    config.z = func_021FB7B0((void *)ctx->object, 4);
    config.flag = 1;
    func_021FC124(owner, ctx->index + 1, info);
    ctx->result = (unsigned)func_021FB3BC(&config, (void *)ctx->work, 0xa0, ctx->enabled, a, b, func_021FC20C(owner), info, (unsigned short)((heap & 0x7fff) | 0x8000));
}

void func_021FACE0(char *p) { if(((struct Obj10784 *)p)->f0!=0){func_02045808(*(struct U16Vec * *)&((struct Obj10784 *)p)->f40);func_021FB494(((struct Obj10784 *)p)->f8);memset(p,0,0x44);} }


/*
 * func_021FB4CC reads r0, r1, r2 (obj, x, y); this function forwards its
 * incoming r1 and r2 untouched.  Naming them keeps r1 and r2 live, which is
 * why the original tests p[0] in r3 (the old one-parameter spelling put it
 * in r1 and missed by 2 bytes).
 */
int func_021FAD04(int *p, int x, int y)
{
    if (p[0] != 0)
        return func_021FB4CC((u32 *)p[2], x, y);
    return 0;
}

void func_021FAD18(char *ctx, int mode, const int *target)
{
    ((struct Obj03891 *)ctx)->f1C = 0;
    if (target) {
        ((struct Obj03891 *)ctx)->f14 = target[0];
        ((struct Obj03891 *)ctx)->f18 = target[1];
    }
    switch (mode) {
    case 0: *(int (**)(char *))(ctx + 0x10) = func_021FAFD0; break;
    case 1: *(int (**)(char *))(ctx + 0x10) = func_021FB058; break;
    case 2: *(int (**)(char *))(ctx + 0x10) = func_021FB0E8; break;
    case 3: *(int (**)(char *))(ctx + 0x10) = func_021FB1EC; break;
    case 4: *(int (**)(char *))(ctx + 0x10) = func_021FB2F0; break;
    }
}

/*
 * tail: 021FADB6..021FADB8 is two zero alignment bytes.
 */
int func_021FAD74(char *ctx)
{
    short x, y;
    int result;
    if (*(int (**)(char *))(ctx + 0x10) != 0) {
        result = (*(int (**)(char *))(ctx + 0x10))(ctx);
        if (result != 0) *(int (**)(char *))(ctx + 0x10) = 0;
        if (*(int * *)&((struct Obj08331 *)ctx)->f2C != 0) {
            func_021FB548(((struct Obj08331 *)ctx)->f8, &x, &y);
            (*(int **)(ctx + 0x2c))[0] = x + 80;
            (*(int **)(ctx + 0x2c))[1] = y;
        }
        return result;
    }
    return 1;
}

void func_021FADB8(char *ctx, int mode)
{
    Config_021FADB8 config;
    Placement placement;
    short x, y;
    int priority;
    int attr;
    int shift;
    unsigned resource;
    if (((struct Obj00080 *)ctx)->f4 == mode) return;
    ((struct Obj00080 *)ctx)->f4 = mode;
    func_021FB548(((struct Obj00080 *)ctx)->f8, &x, &y);
    priority = func_021FB594(((struct Obj00080 *)ctx)->f8);
    attr = func_021FB5B8(((struct Obj00080 *)ctx)->f8);
    func_021FB494(((struct Obj00080 *)ctx)->f8);
    ((struct Obj00080 *)ctx)->f2C = 0;
    shift = mode == 0 ? 512 : -512;
    memset(&placement, 0, sizeof(placement));
    placement.x = x;
    placement.y = y + shift;
    placement.animation = func_021FB7B0(((struct Obj00080 *)ctx)->fC, 4);
    placement.priority = priority;
    placement.attr = attr;
    func_021FC124(((struct Obj00080 *)ctx)->f30, ((struct Obj00080 *)ctx)->f28 + mode, &config);
    resource = func_021FC20C(((struct Obj00080 *)ctx)->f30);
    func_021FC214(*(char * *)&((struct Obj00080 *)ctx)->f30);
    func_021FB7B0(((struct Obj00080 *)ctx)->fC, 3);
    ((struct Obj00080 *)ctx)->f8 = func_021FB3BC(&placement, ((struct Obj00080 *)ctx)->f40, 160, mode, ((struct Obj00080 *)ctx)->f38, ((struct Obj00080 *)ctx)->f3C, resource, &config, ((struct Obj00080 *)ctx)->f34);
}

void func_021FAE70(void *ctx, Record *dest, const Record *source, int mode)
{
    if (dest->state != 0) func_02034714(d_02200D18, 0, d_02200D18);
    if (source->state != 1) func_02034714(d_02200D18, 0, d_02200D18);
    *dest = *source;
    if (source->mode != mode) func_021FADB8((char *)dest, mode);
}
