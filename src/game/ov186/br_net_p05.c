/*
 * file:     br_net_p05.c
 * unit:     yes
 * function: func_021FFC6C, func_021FFC9C, func_021FFE34, func_021FFE5C, func_021FFE70, func_021FFE90, func_021FFEA8
 * address:  0x021FFC6C
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
 *   func_020307B0 0x020307B0 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_022000F0 0x022000F0 thumb ov186
 *   func_02035D20 0x02035D20 arm
 *   func_021FB4B4 0x021FB4B4 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021FCD0C 0x021FCD0C thumb ov186
 *   func_021FCDA8 0x021FCDA8 thumb ov186
 *   func_021FD938 0x021FD938 thumb ov186
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FFFCC 0x021FFFCC thumb ov186
 *   func_02034714 0x02034714 arm
 *   func_02200188 0x02200188 thumb ov186
 *   func_021FFFF8 0x021FFFF8 thumb ov186
 *   func_022000D0 0x022000D0 thumb ov186
 *   func_021FFF28 0x021FFF28 thumb ov186
 *   d_02200DAC 0x02200DAC data
 *   func_021FC830 0x021FC830 thumb ov186
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021FFF1C 0x021FFF1C thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
 *   func_02082BCC 0x02082BCC arm
 */
#include "../../matched/include/Obj06638.h"
#include "../../matched/include/Obj00221.h"
#include "../../matched/include/Obj24875.h"
#include "../../matched/include/Obj02237.h"
#include "../../matched/include/Obj14486.h"
#include "../../matched/include/Obj04590.h"

struct PrintSys;
struct Work;
typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { int x,y; } Pair;

typedef unsigned char  u8;

typedef struct Request { unsigned short x, y, id; unsigned char flag, pad; } Request;

extern void func_020307B0(void *);
extern void func_0201C4C0(struct PrintSys *);
extern int func_022000F0(char *);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern int func_021FB4B4(unsigned int *obj, int x, int y);
extern void func_021FD860(char *,u32,const Pair *);
extern void func_021FCD0C(char *);
extern int func_021FCDA8(char *),func_021FD938(char *),func_021FE7B0(int *);
extern void func_021FE784(int a, int b, int c, int d);
extern void func_021FFFCC(u8 *p);
extern void func_022000D0(u8 *p);
extern void func_021FFF28(struct Work *p);
extern void func_021FFFF8(char *);
extern u16 *func_02200188(void *p, u32 index, const u16 *table, u32 *out, u16 heap);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern int func_021FC830(void *);
extern unsigned func_0201C4E4(struct PrintSys *);
extern void func_021FFF1C(char *);
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern int func_021FC124(void *, unsigned, void *);
extern void *func_021FB378(void *, int, int, int, int, int, int, int, void *, unsigned short);
extern void *func_02082BCC(void *, int, unsigned);
void func_021FFC6C(char *p);
int func_021FFC9C(char *p);
unsigned func_021FFE34(char *p);
void func_021FFE5C(char *p);
void func_021FFE70(char *p);
int func_021FFE90(int *p, unsigned short *out);
void func_021FFEA8(char *p);
extern char d_02200DAC[];

void func_021FFC6C(char *p) {if(((struct Obj06638 *)p)->f88){func_020307B0(((struct Obj06638 *)p)->f88);((struct Obj06638 *)p)->f88=0;}func_020307B0(((struct Obj06638 *)p)->f80);func_0201C4C0(*(struct PrintSys * *)&((struct Obj06638 *)p)->f3C);func_020307B0(p);}

int func_021FFC9C(char *p)
{
    if (((struct Obj00221 *)p)->f6C) {
        switch (((struct Obj00221 *)p)->f0) {
        case 0: (((struct Obj00221 *)p)->f0)++; break;
        case 1: ((struct Obj00221 *)p)->f0=2; break;
        case 2: {
            int x,y,held;
            Pair pair;
            ((struct Obj00221 *)p)->fC=func_022000F0(p);
            held=func_02035D20((u32 *)(&x),(u32 *)(&y));
            if (func_021FB4B4((unsigned int *)(((struct Obj00221 *)p)->f2C),x,y)&held) {
                pair.x=x; pair.y=y;
                func_021FD860(*(char * *)&((struct Obj00221 *)p)->f78,1,&pair);
                *(int *)&((struct Obj00221 *)p)->f0=8; ((struct Obj00221 *)p)->f8=1;
            } else if (((struct Obj00221 *)p)->fC!=9) {
                *(int *)&((struct Obj00221 *)p)->f0=4; ((struct Obj00221 *)p)->f4=3;
            }
            break;
        }
        case 3: {
            int x,y,held;
            Pair pair;
            func_021FCD0C(*(char * *)&((struct Obj00221 *)p)->f68);
            ((struct Obj00221 *)p)->f10=func_021FCDA8(*(char * *)&((struct Obj00221 *)p)->f68);
            held=func_02035D20((u32 *)(&x),(u32 *)(&y));
            if (func_021FB4B4((unsigned int *)(((struct Obj00221 *)p)->f2C),x,y)&held) {
                pair.x=x; pair.y=y;
                func_021FD860(*(char * *)&((struct Obj00221 *)p)->f78,1,&pair);
                *(int *)&((struct Obj00221 *)p)->f0=4; ((struct Obj00221 *)p)->f4=2;
            } else if (((struct Obj00221 *)p)->f10!=-1) {
                *(int *)&((struct Obj00221 *)p)->f0=8; ((struct Obj00221 *)p)->f8=2;
            }
            break;
        }
        case 4:
            if (func_021FD938(*(char * *)&((struct Obj00221 *)p)->f78)) {
                func_021FE784((int)(((struct Obj00221 *)p)->f30),2,2,1);
                (((struct Obj00221 *)p)->f0)++;
            }
            break;
        case 5:
            if (func_021FE7B0(*(int * *)&((struct Obj00221 *)p)->f30)) (((struct Obj00221 *)p)->f0)++;
            break;
        case 6:
            if (((struct Obj00221 *)p)->f4==3) {
                func_021FFFCC((u8 *)p);
                if (((struct Obj00221 *)p)->f88) func_02034714(d_02200DAC,0,d_02200DAC);
                *(u16 * *)&((struct Obj00221 *)p)->f88=func_02200188(((struct Obj00221 *)p)->f7C,*(u32 *)&((struct Obj00221 *)p)->fC,*(u16 * *)&((struct Obj00221 *)p)->f80,(u32 *)(p+0x8c),((struct Obj00221 *)p)->f24);
                func_021FFFF8(p);
            } else {
                func_022000D0((u8 *)p);
                if (((struct Obj00221 *)p)->f88) {
                    func_020307B0(((struct Obj00221 *)p)->f88);
                    ((struct Obj00221 *)p)->f88=0;
                }
                func_021FFF28((struct Work *)p);
            }
            func_021FE784((int)(((struct Obj00221 *)p)->f30),2,2,0);
            (((struct Obj00221 *)p)->f0)++;
            break;
        case 7:
            if (func_021FE7B0(*(int * *)&((struct Obj00221 *)p)->f30)) ((struct Obj00221 *)p)->f0=*(u32 *)&((struct Obj00221 *)p)->f4;
            break;
        case 8: (((struct Obj00221 *)p)->f0)++; break;
        case 9: (((struct Obj00221 *)p)->f0)++; break;
        case 10: ((struct Obj00221 *)p)->f20=1; break;
        }
    }
    return func_021FFE34(p);
}

unsigned func_021FFE34(char *p) {unsigned r=1;int i;for(i=0;i<9;i++){void *v=*(void **)((unsigned)p+i*4+64);if(v)r &= func_021FC830(v);}return r & func_0201C4E4(*(struct PrintSys * *)&((struct Obj24875 *)p)->f3C);}


void func_021FFE5C(char *p)
{
    func_021FFEA8(p);
    func_021FFF28((struct Work *)p);
    ((struct Obj02237 *)p)->f6C = 1;
}

void func_021FFE70(char *p) {((struct Obj14486 *)p)->f6C=0;if(((struct Obj14486 *)p)->f70==1)func_022000D0((u8 *)p);else func_021FFFCC((u8 *)p);func_021FFF1C(p);}

/*
 * Unlabelled ov186 leaf: if the +0x20 field is zero return 0; otherwise, when
 * the +0x08 field is 2, publish the +0x10 halfword through the out pointer and
 * return the +0x08 field.  Matched to supply the `matched` witness for the
 * pending ov185 caller func_021F86A4.
 */
int func_021FFE90(int *p, unsigned short *out)
{
    if (p[8] != 0) {
        if (p[2] == 2)
            *out = (unsigned short)p[4];
        return p[2];
    }
    return 0;
}

void func_021FFEA8(char *p)
{
    Request req;
    int info[3];
    int a = func_021FC20C(*(char * *)&((struct Obj04590 *)p)->f28);
    int b = func_021FC214(*(char * *)&((struct Obj04590 *)p)->f28);
    func_02082BCC(&req, 0, 8);
    req.x = 0x50; req.y = 0xa8; req.id = 0; req.flag = 1;
    if (!func_021FC124(((struct Obj04590 *)p)->f28, 6, info))
        func_02034714(d_02200DAC, 0, d_02200DAC);
    ((struct Obj04590 *)p)->f2C = func_021FB378(&req, 4, 0x60, 1, ((struct Obj04590 *)p)->f34, ((struct Obj04590 *)p)->f38, a, b, info, ((struct Obj04590 *)p)->f24);
}
