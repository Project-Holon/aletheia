/*
 * file:     field_gimmick_gate_p04.c
 * unit:     yes
 * function: func_021F392C, func_021F39A8, func_021F39BC, func_021F39E4, func_021F3A50, func_021F3A70, func_021F3A98
 * address:  0x021F392C
 * region:   ov048
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_02049030  0x02049030  arm
 *   func_020111E8  0x020111E8  thumb
 *   func_021F4C10  0x021F4C10  thumb  ov048
 *   d_021F5224     0x021F5224  data  ov048  a1
 *   func_020307B0 0x020307B0 arm
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021BE700 0x021BE700 thumb ov021
 *   d_021F50D2 0x021F50D2 data a2
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_020520FC  0x020520FC  arm
 *   func_021F3AB4  0x021F3AB4  thumb
 *   func_0201296C 0x0201296C thumb
 *   func_020142E8 0x020142E8 thumb
 */
#include "../../matched/include/Obj20528.h"
#include "../../matched/include/Obj20529.h"
#include "../../matched/include/Obj20530.h"
#include "../../matched/include/Obj20531.h"

struct Mtx33;
struct BigObj;
typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Rec {
    u32 a;
    u32 b;
    u32 pad[29];
} Rec;

typedef struct Obj {
    u16 f00;
    u32 f04;
    u32 pad08[5];
    Rec *f1c;
} Obj;

typedef unsigned char  u8;

typedef struct Ent {
    int pad[2];
    int x;
    int y;
    int z;
    int mode;
} Ent;

typedef signed int     s32;

extern u16 func_02188C9C(u8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_02049030(u32 id);
extern u32 func_020111E8(void);
extern int func_021F4C10(int a, int b, int c);
extern u32 func_020307B0(void *p);
extern int func_02188D2C(int *p);
extern void func_021BE700(void *p, int i, int j, int k, int flag);
extern int func_021BE480(char *p, unsigned i, int j);
extern void func_020520FC(int a, int b, int c, struct Mtx33 *d);
extern int func_021F3AB4(void *p);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *bitmap, s32 id);
void func_021F392C(Obj *o);
void func_021F39A8(void **p);
void func_021F39BC(int *p);
void func_021F39E4(int *p);
void func_021F3A50(char *p,int a,int b);
int func_021F3A70(u8 *p);
int func_021F3A98(void *p);
extern const char d_021F5224[];
extern const u16 d_021F50D2[];


void func_021F392C(Obj *o)
{
    u32 i;
    u32 n;
    u32 r5;
    Rec buf;

    if (o->f1c == 0) {
        r5 = func_02188C9C((u8 *)o->f04);
        i = 0;
        o->f1c = func_02030734(o->f00, 0x7c, 0, d_021F5224, 0x387);
        n = func_02049030(0xae);
        for (; i < n; i++) {
            func_021F4C10((int)(&buf), 0xae, i);
            if (buf.a == r5) {
                if (buf.b == 0 || buf.b == func_020111E8()) {
                    *o->f1c = buf;
                    return;
                }
            }
        }
    }
}

void func_021F39A8(void **p) { if (p[7]) { func_020307B0(p[7]); p[7] = 0; } }

void func_021F39BC(int *p) { func_021BE700((void *)func_02188D2C((int *)p[1]),1,0,d_021F50D2[((int *)p[7])[0x1d]],1); }


void func_021F39E4(int *p)
{
    int *r3;
    Ent *e;
    int r4;

    r4 = 0;
    r3 = (int *)func_021BE480((char *)func_02188D2C((int *)p[1]), 1, 0);
    e = (Ent *)p[7];
    r3[0] = e->x << 12;
    r3[1] = e->y << 12;
    r3[2] = e->z << 12;
    switch (e->mode) {
    case 1:
        r4 = 0;
        break;
    case 3:
        r4 = 90;
        break;
    case 0:
        r4 = 180;
        break;
    case 2:
        r4 = 270;
        break;
    default:
        r4 = 0;
        break;
    }
    func_020520FC(0, (u16)(r4 * 0xb6), 0, (struct Mtx33 *)(r3 + 6));
}

void func_021F3A50(char *p,int a,int b) { char *q; int i; q=p+0x28; i=((struct Obj20528 *)p)->f28; if(i<7) { *(int *)(q+i*4+4)=a; *(int *)(q+i*4+0x20)=b; ((struct Obj20529 *)q)->f0=i+1; } }


int func_021F3A70(u8 *p)
{
    if (func_021F3A98(p) == 1 || func_021F3AB4(p) == 1) {
        if (((struct Obj20530 *)p)->f64 != 0) {
            return 1;
        }
    }
    return 0;
}

int func_021F3A98(void *p) {return func_020142E8((void *)func_0201296C((const struct BigObj *)(((struct Obj20531 *)p)->f8)),0x960)==1;}
