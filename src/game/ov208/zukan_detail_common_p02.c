/*
 * file:     zukan_detail_common_p02.c
 * unit:     yes
 * function: func_021BC3B4, func_021BC3B8, func_021BC3BC, func_021BC3C0, func_021BC3CC, func_021BC40C, func_021BC448, func_021BC464, func_021BC46C, func_021BC4C8, func_021BC4D8, func_021BC4E4, func_021BC4F4
 * address:  0x021BC3B4
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200D064 0x0200D064 thumb
 *   func_02030734 0x02030734 arm
 *   d_021C8D98 0x021C8D98 data a1
 *   func_020307B0 0x020307B0  arm
 *   func_021BC520  0x021BC520  thumb
 */
#include "../../matched/include/Obj18183.h"
#include "../../matched/include/Obj25414.h"
#include "../../matched/include/Obj01178.h"

struct Blk37;
typedef unsigned short u16;

typedef struct {
    char pad[0x18];
    unsigned short *tbl;
    char pad2[4];
    unsigned short *idx;
} S;

typedef unsigned int   u32;

struct Ov208Cur { void *blk; int f4; int f8; int fc; int f10; int f14; u16 *ids; u16 wrap; u16 pad; u16 *cur; };

typedef unsigned char u8;

struct Ov208Blend {
    int plane1;
    int plane2;
    int ev;
    int step;
    int wait;
};

extern void *func_0200CA1C(void *a);
extern u32 func_0200D064(struct Blk37 *p, u16 id);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_021BC520(int flag, int *p);
int func_021BC3B4(int *p);
int func_021BC3B8(char *p);
u16 ov208_func_021BC3BC(char *p);
unsigned short func_021BC3C0(S *p);
void func_021BC3CC(char *p);
void func_021BC40C(struct Ov208Cur *p);
void *func_021BC448(u32 heap);
void func_021BC464(void *a0);
void ov208_func_021BC46C(struct Ov208Blend *main, struct Ov208Blend *sub);
int ov208_func_021BC4C8(struct Ov208Blend *p);
void ov208_func_021BC4D8(struct Ov208Blend *p);
void ov208_func_021BC4E4(struct Ov208Blend *p);
void func_021BC4F4(int flag, int *p);
extern const char d_021C8D98[];

/*
 * Returns the word at +0x10.
 */
int func_021BC3B4(int *p)
{
    return p[4];
}


int func_021BC3B8(char *p)
{
    return ((struct Obj18183 *)p)->f14;
}


u16 ov208_func_021BC3BC(char *p)
{
    return ((struct Obj25414 *)p)->f1C;
}


/*
 * Returns the halfword of the table at +0x18 indexed by the halfword read through the pointer at +0x20.
 */
unsigned short func_021BC3C0(S *p)
{
    return p->tbl[*p->idx];
}

void func_021BC3CC(char *p)
{
    unsigned short old=**(unsigned short * *)&((struct Obj01178 *)p)->f20;
    void *owner=func_0200CA1C((void *)(*(int *)&((struct Obj01178 *)p)->f0));
    do {
        ++**(unsigned short * *)&((struct Obj01178 *)p)->f20;
        if(**(unsigned short * *)&((struct Obj01178 *)p)->f20>=((struct Obj01178 *)p)->f1C)
            **(unsigned short * *)&((struct Obj01178 *)p)->f20=0;
        if(**(unsigned short * *)&((struct Obj01178 *)p)->f20==old)break;
    }while(func_0200D064(owner,(*(unsigned short **)(p+0x18))[**(unsigned short * *)&((struct Obj01178 *)p)->f20])==0);
}

void func_021BC40C(struct Ov208Cur *p)
{
    u16 start = *p->cur;
    u32 h = (u32)func_0200CA1C(p->blk);
    do {
        if (*p->cur == 0)
            *p->cur = p->wrap - 1;
        else
            *p->cur = *p->cur - 1;
        if (*p->cur == start)
            break;
    } while (func_0200D064((struct Blk37 *)h, p->ids[*p->cur]) == 0);
}

void *func_021BC448(u32 heap)
{
    return func_02030734(heap, 20, 1, d_021C8D98, 0x113);
}


/*
 * Tail call to the ARM9 function at 0x020307B0: loads the pointer from the pool and branches through it.
 */
void func_021BC464(void *a0)
{
    func_020307B0(a0);
}


void ov208_func_021BC46C(struct Ov208Blend *main, struct Ov208Blend *sub)
{
    struct Ov208Blend *b[2];
    struct Ov208Blend *p;
    u8 i;

    b[0] = main;
    b[1] = sub;
    for (i = 0; i < 2; i++) {
        p = b[i];
        if (p->step != 0) {
            if (p->wait == 0) {
                p->wait = 0;
                p->ev += p->step;
                if (p->step > 0) {
                    if (p->ev >= 16) {
                        p->ev = 16;
                        p->step = 0;
                    }
                } else if (p->ev <= 0) {
                    p->ev = 0;
                    p->step = 0;
                }
                func_021BC520(i, (int *)p);
            } else {
                p->wait--;
            }
        }
    }
}


int ov208_func_021BC4C8(struct Ov208Blend *p)
{
    if (p->step != 0)
        return 1;
    return 0;
}


void ov208_func_021BC4D8(struct Ov208Blend *p)
{
    p->ev = 0;
    p->step = 2;
    p->wait = 0;
}


void ov208_func_021BC4E4(struct Ov208Blend *p)
{
    p->ev = 16;
    p->step = -2;
    p->wait = 0;
}


void func_021BC4F4(int flag, int *p)
{
    p[2] = 0x10;
    p[3] = 0;
    p[4] = 0;
    func_021BC520(flag, p);
}
