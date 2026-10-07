/*
 * file:     intro_cmd_p03.c
 * unit:     yes
 * function: func_021BEF20, func_021BEF74, func_021BEF88, func_021BF00C
 * address:  0x021BEF20
 * region:   ov204
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
 *   func_021BF0A0 0x021BF0A0 thumb ov204
 *   d_021C0AAC 0x021C0AAC data a1
 *   func_021BF1A4 0x021BF1A4 thumb ov204
 *   func_020307B0 0x020307B0 arm
 *   func_021BF228 0x021BF228 thumb ov204
 *   func_021BF030 0x021BF030 thumb ov204
 *   func_021BF094 0x021BF094 thumb ov204
 *   d_021C09D8 0x021C09D8 data a4
 */
#include "../../matched/include/Obj03921.h"
#include "../../matched/include/Obj25381.h"
#include "../../matched/include/Obj25382.h"
#include "../../matched/include/Obj06673.h"

struct Q021BF00C;
struct S021BF00C;
struct State;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef struct Row { unsigned tag; unsigned data[5]; } Row;

struct S021BF00C
{
    char pad[0x20];
    void *slots[8];
};

struct Q021BF00C
{
    char pad[0x14];
    unsigned char b : 1;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char *func_021BF0A0(u16 heap);
extern void func_021BF1A4(char*);
extern u32 func_020307B0(void *p);
extern void func_021BF228(u8 *p);
extern int func_021BF030(struct State *p);
extern Row *func_021BF094(unsigned);
char *func_021BEF20(void *a, unsigned b, unsigned c, char *d, unsigned e, unsigned short heap);
void func_021BEF74(u8*p);
int func_021BEF88(char *p);
int func_021BF00C(struct S021BF00C *p, struct Q021BF00C *q);
extern const char d_021C0AAC[];

char *func_021BEF20(void *a, unsigned b, unsigned c, char *d, unsigned e, unsigned short heap)
{
    char *p = func_02030734(heap, 0x10d8, 1, d_021C0AAC, 0x6f2);
    ((struct Obj03921 *)p)->f0 = heap;
    *(char * *)&((struct Obj03921 *)p)->f4 = d;
    ((struct Obj03921 *)p)->f8 = c;
    ((struct Obj03921 *)p)->fC = a;
    ((struct Obj03921 *)p)->f10 = b;
    ((struct Obj03921 *)p)->f14 = e;
    ((struct Obj03921 *)p)->fA4 = ((struct Obj25381 *)d)->fC;
    ((struct Obj03921 *)p)->f18 = func_021BF0A0(heap);
    return p;
}

void func_021BEF74(u8*p){func_021BF1A4(*(char* *)&((struct Obj25382 *)p)->f18);func_020307B0(p);}

extern int (*const d_021C09D8[])(void *, void *, void *);

int func_021BEF88(char *p)
{
    func_021BF228(((struct Obj06673 *)p)->f18);
    if (func_021BF030((struct State *)p) == 0) {
        char *base = p;
        int i;
        base += 0x40;
        for (i = 0; i < 9; i++) {
            Row *row = func_021BF094(((struct Obj06673 *)p)->f1C) + ((struct Obj06673 *)p)->fA0;
            if (row->tag == 1) {
                d_021C09D8[row->tag](p, base + i * 12, row->data);
                row = func_021BF094(((struct Obj06673 *)p)->f1C);
            }
            if (row->tag == 0x34)
                return 0;
            ++((struct Obj06673 *)p)->fA0;
            if (!func_021BF00C((struct S021BF00C *)p, (struct Q021BF00C *)row))
                break;
        }
    }
    return 1;
}


int func_021BF00C(struct S021BF00C *p, struct Q021BF00C *q)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        if (p->slots[i] == 0)
        {
            p->slots[i] = q;
            break;
        }
    }
    return q->b;
}
