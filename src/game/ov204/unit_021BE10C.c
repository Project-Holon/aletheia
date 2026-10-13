/*
 * file:     unit_021BE10C.c
 * unit:     yes
 * function: func_021BE10C, func_021BE11C, func_021BE138, func_021BE17C, func_021BE1F0, func_021BE23C
 * address:  0x021BE10C
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
 *   func_021BF094 0x021BF094 thumb ov204
 *   func_021BF4E8 0x021BF4E8 thumb ov204
 *   func_021BF00C 0x021BF00C thumb ov204
 *   func_021BF384 0x021BF384 thumb ov204
 *   func_021BF528 0x021BF528 thumb ov204
 *   func_021BF538 0x021BF538 thumb ov204
 *   d_021C09D0 0x021C09D0 data a4
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_UTIL_LoadPaletteDataFromHandle 0x02049EF4 arm
 *   func_02082A60 0x02082A60 arm
 *   func_020307B0 0x020307B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../../matched/include/Obj10870.h"
#include "../../matched/include/Obj04608.h"
#include "../../matched/include/Obj10872.h"
#include "../../matched/include/Obj25339.h"
#include "../../matched/include/Obj25341.h"
#include "../../matched/include/Obj25343.h"

struct S021BF00C;
struct Q021BF00C;
typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed int s32;

typedef struct { int a, b; } Pair;

typedef struct { Pair first, second; } Request;

typedef struct Row { unsigned tag; char data[20]; } Row;

extern char *func_021BF094(int);
extern void func_021BF4E8(char *);
extern int func_021BF00C(struct S021BF00C *, struct Q021BF00C *);
extern void func_021BF384(char *p, u32 *entries, u32 count, int flag);
extern void func_021BF528(u8 *p);
extern int func_021BF538(u8 *p, int *out);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void *ARC_UTIL_LoadPaletteDataFromHandle(void *,u32,u32,void **,u16);
extern void func_02082A60(const void *,void *,u32);
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *);
int func_021BE10C(char *p, u32 b, int *c);
u32 func_021BE11C(u8 *p);
void func_021BE138(char *p, int which);
int func_021BE17C(char *p, int *state, int *values);
int func_021BE1F0(char *p, int unused, unsigned *q);
int func_021BE23C(char *p,void *unused,int *state);
int func_021BE308(char *p,void *unused,u32 *r);
int func_021BE314(void *unused,int *q,int *r);



int func_021BE10C(char *p, u32 b, int *c)
{
    ((struct Obj10870 *)p)->f1C = *c;
    ((struct Obj10870 *)p)->fA0 = 0;
    return 1;
}



u32 func_021BE11C(u8 *p)
{
    u32 t = *(u32 *)(((struct Obj10870 *)p)->f4 + 8);

    if (t == 0) {
        t = t + 1;
    }
    func_021BE10C((char *)p, 0, (int *)(&t));
    return 1;
}


/*
 * extent: 021BE17A..021BE17C is two zero alignment bytes.
 */
void func_021BE138(char *p, int which)
{
    char *q = func_021BF094(((struct Obj04608 *)p)->f1C) + 24 * ((struct Obj04608 *)p)->fA0;
    func_021BF4E8(*(char * *)&((struct Obj04608 *)p)->f18);
    if (which == 0) {
        if (q) func_021BF00C((struct S021BF00C *)p, (struct Q021BF00C *)q);
    } else {
        q += 24;
        if (q) func_021BF00C((struct S021BF00C *)p, (struct Q021BF00C *)q);
    }
    ((struct Obj04608 *)p)->fA0 += 2;
}


int func_021BE17C(char *p, int *state, int *values)
{
    Request request;
    int result, choice;
    switch (*state) {
    case 0:
        request.first.a = values[0];
        request.first.b = 0;
        request.second.a = values[1];
        request.second.b = 1;
        func_021BF384(*(char * *)&((struct Obj04608 *)p)->f18, (u32 *)(&request), 2, values[2]);
        ++*state;
        break;
    case 1:
        func_021BF528((u8 *)(*(char * *)&((struct Obj04608 *)p)->f18));
        result = func_021BF538((u8 *)(*(char * *)&((struct Obj04608 *)p)->f18), &choice);
        if (result == 1) { func_021BE138(p, choice); return 1; }
        if (result == 2) { func_021BE138(p, 1); return 1; }
        break;
    }
    return 0;
}


extern int (*const d_021C09D0[])(void *);


int func_021BE1F0(char *p, int unused, unsigned *q)
{
    Row *row = (Row *)func_021BF094(((struct Obj10872 *)p)->f1C) + ((struct Obj10872 *)p)->fA0;
    if (!d_021C09D0[*q](p)) row++;
    if (row) func_021BF00C((struct S021BF00C *)p, (struct Q021BF00C *)row);
    ((struct Obj10872 *)p)->fA0 += 2;
    return 1;
}


/*
 * extent: lead and two store/return followers; function_starts 021BE308,021BE314.
 */
int func_021BE23C(char *p,void *unused,int *state)
{
    u16 heap;
    void *arc,*out,*buf;
    heap=((struct Obj25339 *)p)->f0;
    arc=func_020490F4(0xAA,heap);
    func_02049B68(arc,1,0,0,64,heap);
    func_02049B68(arc,1,4,0,32,heap);
    func_02049658(arc,0,6,0,0,0,heap);
    func_020498F4(arc,2,6,0,0,0,heap);
    func_02049658(arc,0,3,0,0,0,heap);
    func_020498F4(arc,3,3,0,0,0,heap);
    if (*state==1) {
        func_02049658(arc,12,2,0,0,0,heap);
        buf=ARC_UTIL_LoadPaletteDataFromHandle(arc,14,0,(void **)&out,heap);
        func_02082A60((char *)out+12,p+0xA8,4096);
        func_020307B0(buf);
    }
    ARC_TOOL_DeleteHandle(arc);
    return 1;
}


int func_021BE308(char *p,void *unused,u32 *r)
{
    ((struct Obj25343 *)(*(char * *)&((struct Obj25341 *)p)->f4))->f14=*r;
    return 1;
}


int func_021BE314(void *unused,int *q,int *r)
{
    if (q[1]>*r) return 1;
    q[1]++;
    return 0;
}
