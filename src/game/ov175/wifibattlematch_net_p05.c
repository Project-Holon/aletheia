/*
 * file:     wifibattlematch_net_p05.c
 * unit:     yes
 * function: func_021D5E24, func_021D6000, func_021D6048
 * address:  0x021D5E24
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021D61A4 0x021D61A4 thumb ov175
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   func_021DC2C0 0x021DC2C0 thumb ov175
 *   func_021DC2D8 0x021DC2D8 thumb ov175
 *   func_021D9F04 0x021D9F04 thumb ov175
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200ED48 0x0200ED48 thumb
 *   func_02008530 0x02008530 thumb
 *   func_0200ED54 0x0200ED54 thumb
 *   func_021E8AC0 0x021E8AC0 thumb ov177
 *   func_021DA384 0x021DA384 thumb ov175
 *   func_021DA390 0x021DA390 thumb ov175
 *   func_02012DAC 0x02012DAC thumb
 *   func_02012DD0 0x02012DD0 thumb
 *   func_021E8AA8 0x021E8AA8 thumb ov177
 *   func_021D6550 0x021D6550 thumb ov175
 *   func_021D65DC 0x021D65DC thumb ov175
 *   func_021D65C8 0x021D65C8 thumb ov175
 *   func_021D5908 0x021D5908 thumb ov175
 *   func_021D60E0 0x021D60E0 thumb ov175
 */
#include "../../matched/include/Obj02885.h"

#define P(k) (*(int *)(p + (k)))
#define TIMER (*(u32 *)(p + 0xe0))
struct Big;
struct L0200ED54;
struct Sub0200852CObj;
typedef unsigned int u32;

typedef unsigned long ul;

typedef unsigned char u8;

extern void func_021E8AA0(int *, int);
extern void func_021D61A4(void *obj, int unused, u8 *p);
extern void func_021E8738(int *, int, int, int);
extern void func_021E8AB4(unsigned, unsigned);
extern int func_021E8844(const int *);
extern void func_021E8AB8(unsigned);
extern int func_021DC2C0(ul, void *);
extern ul func_021DC2D8(char *, ul *);
extern int func_021D9F04(char *, void *, void *);
extern void *func_02012EBC(struct Big *);
extern void *func_0200ED48(void *);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void func_0200ED54(struct L0200ED54 *, u32);
extern void func_021E8AC0(int, int);
extern void func_021DA384(char *);
extern int func_021DA390(char *);
extern int func_02012DAC(int);
extern int func_02012DD0(u8 *);
extern void func_021E8AA8(int);
extern void func_021D6550(unsigned int *p, int mode);
extern int func_021D65DC(char *);
extern void func_021D65C8(char *);
extern void func_021D5908(unsigned sys, int *state, char *p);
extern void func_021D60E0(u32 sys, int *state, u32 *p);
void func_021D5E24(unsigned sys, int *state, char *p);
void func_021D6000(unsigned sys,int *state,int *p);
void func_021D6048(unsigned sys,int *state,int *p);

/*
 * Lever: source arm order is 0,3,1,2,4..11; numeric ordering differs
 * by 119 concrete bytes although the compiled size remains 476.
 * DC2C0's return r0 is tested here despite its legacy void declaration.
 */
void func_021D5E24(unsigned sys, int *state, char *p)
{
    char *q = (char *)P(0x40);
    void *list;
    switch (*state) {
    case 0:
        if (((struct Obj02885 *)q)->fC == 2) func_021E8AA0((int *)sys, (int)func_021D6000);
        else *state = 3;
        break;
    case 3:
        func_021E8738((int *)P(0x24), P(0x10), 43, 2);
        *state = 11;
        func_021E8AB4(sys, 1);
        TIMER = 0;
        break;
    case 1:
        if (func_021DC2C0(P(0x30), *(char * *)&((struct Obj02885 *)q)->f2C + 0x10)) *state = 2;
        break;
    case 2:
        if (func_021DC2D8((char *)P(0x30), (ul *)(*(char * *)&((struct Obj02885 *)q)->f2C + 0x14))) *state = 4;
        switch (func_021D9F04((char *)P(0x30), 0, (void *)1)) {
        case 1: case 4: TIMER = 0; *state = 7; break;
        case 2: TIMER = 0; func_021E8AA0((int *)sys, (int)func_021D61A4); break;
        }
        break;
    case 4:
        list = func_0200ED48(func_02012EBC((struct Big *)**(int * *)&((struct Obj02885 *)q)->f8));
        func_0200ED54(list, func_02008530(((struct Obj02885 *)q)->f18));
        func_021E8AC0(**(int * *)&((struct Obj02885 *)q)->f8, **(int * *)&((struct Obj02885 *)q)->f2C);
        func_021DA384((char *)P(0x30));
        *state = 5;
        break;
    case 5:
        TIMER++;
        if (func_021DA390((char *)P(0x30))) *state = 6;
        switch (func_021D9F04((char *)P(0x30), 0, (void *)1)) {
        case 1: case 4: TIMER = 0; *state = 7; break;
        case 2: TIMER = 0; func_021E8AA0((int *)sys, (int)func_021D61A4); break;
        }
        break;
    case 6:
        if (TIMER++ > 30) { TIMER = 0; *state = 7; }
        break;
    case 7:
        *state = 8;
        break;
    case 8:
        func_021E8738((int *)P(0x24), P(0x10), 40, 2);
        *state = 11;
        func_021E8AB4(sys, 9);
        break;
    case 9:
        func_02012DAC(**(int * *)&((struct Obj02885 *)q)->f8);
        *state = 10;
        break;
    case 10:
        switch (func_02012DD0((u8 *)**(int * *)&((struct Obj02885 *)q)->f8)) {
        case 0: case 1: break;
        case 2: case 3: ((struct Obj02885 *)q)->f4 = 2; func_021E8AA8(sys); break;
        }
        break;
    case 11:
        if (func_021E8844((int *)P(0x24))) func_021E8AB8(sys);
        break;
    }
}

void func_021D6000(unsigned sys,int *state,int *p)
{
    switch(state[0]) {
    case 0: state[0]=1; break;
    case 1: state[0]=2; break;
    case 2: func_021E8AA0((int *)sys,(int)func_021D6048); break;
    case 3: if(func_021E8844((const int *)p[9])) func_021E8AB8(sys); break;
    }
}

void func_021D6048(unsigned sys,int *state,int *p)
{
    int result;
    switch(state[0]) {
    case 0:
        func_021E8738((int *)p[9],p[4],0x26,1);
        state[0]=3;
        func_021E8AB4(sys,1);
        break;
    case 1: func_021D6550((unsigned int *)p,0); state[0]=2; break;
    case 2:
        result=func_021D65DC((char *)p);
        if(result!=-1) {
            func_021D65C8((char *)p);
            switch(result) {
            case 0: func_021E8AA0((int *)sys,(int)func_021D5908); break;
            case 1: func_021E8AA0((int *)sys,(int)func_021D60E0); break;
            }
        }
        break;
    case 3: if(func_021E8844((const int *)p[9])) func_021E8AB8(sys); break;
    }
}
