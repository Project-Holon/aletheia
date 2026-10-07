/*
 * file:     btl_server_p05.c
 * unit:     yes
 * function: func_021B9C50, func_021B9C98, func_021B9CBC, func_021B9CE8, func_021B9D10, func_021B9DB8, func_021B9DE8
 * address:  0x021B9C50
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9AB0  0x021B9AB0  thumb  ov093
 *   func_021B9AC8  0x021B9AC8  thumb  ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D5B7C 0x021D5B7C thumb ov093
 *   func_021B8588  0x021B8588  thumb  ov093
 *   func_021B8B78  0x021B8B78  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D5844  0x021D5844  thumb  ov093
 *   func_021D5848  0x021D5848  thumb  ov093
 *   func_021D5864  0x021D5864  thumb  ov093
 *   func_021D5854  0x021D5854  thumb  ov093
 *   func_021D6C24  0x021D6C24  thumb  ov093
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj20992.h"
#include "../../matched/include/Obj20995.h"
#include "../../matched/include/Obj09942.h"
#include "../../matched/include/Obj03187.h"

struct QH;
struct R4;
struct Work;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Arr { void *e[6]; u8 n; };

extern int func_021B9AB0(int k);
extern int func_021B9AC8(int k);
extern u8 func_021D5440(u8 *p);
extern int func_021D5B7C(void *);
extern u32 func_021B8588(void **p);
extern unsigned int func_021B8B78(unsigned char *p, int k);
extern int func_021D59B4(u8 *p, int k);
extern void *func_021D5844(void *m);
extern void func_021D5848(struct QH *p, void *v);
extern void *func_021D5864(struct Work *p);
extern void func_021D5854(struct Work *p);
extern int func_021D6C24(struct R4 *p);
extern u32 func_020307B0(void *p);
void func_021B9C50(u8 **p, int k, u8 **o1, u8 **o2);
int func_021B9C98(u8 *p,u32 v);
int func_021B9CBC(u8 *p, int v);
void *func_021B9CE8(u8 *p);
void func_021B9D10(char *a, struct Arr *arr, int k);
void func_021B9DB8(char *p);
void func_021B9DE8(char *p);


void func_021B9C50(u8 **p, int k, u8 **o1, u8 **o2)
{
    u8 *t;
    int a;
    int b;

    if (k != 0) {
        if (k != 1) {
            t = p[0];
            a = func_021B9AB0(k);
            b = func_021B9AC8(k);
            p[0] = p[a];
            p[a] = p[b];
            p[b] = t;
            if (o1)
                *o1 = t;
            if (o2)
                *o2 = p[0];
        }
    }
}

int func_021B9C98(u8 *p,u32 v) {
    int i;
    for(i=0;i<*(volatile u8 *)&((struct Obj20992 *)p)->f18;i++) {
        u32 t=*(u32 *)((u32)p+(u32)i*4);
        if(t==v) return i;
    }
    return -1;
}

int func_021B9CBC(u8 *p, int v) {
    int i;
    for(i=0;i<p[24];i++) if(v==func_021D5440(*(void **)((u32)p+(u32)i*4))) return i;
    return -1;
}

void *func_021B9CE8(u8 *p) {
    int i;
    for(i=0;i<p[24];i++) if(func_021D5B7C(*(void **)((u32)p+(u32)i*4))) return *(void **)((u32)p+(u32)i*4);
    return 0;
}


void func_021B9D10(char *a, struct Arr *arr, int k)
{
    int j;
    void *m;
    void *h;

    for (j = arr->n - 1; j > 0; j--) {
        if (func_021D5B7C(arr->e[j]) != 0)
            break;
    }
    if (func_021B8588((void **)a) != 3)
        k = func_021B8B78((unsigned char *)a, k);
    else
        k = 3;
    for (; k < arr->n; k++) {
        m = arr->e[k];
        if (func_021D59B4(m, 0x11) == 0x95) {
            if (k < j) {
                func_021D5848(m, func_021D5844(arr->e[j]));
            } else {
                h = func_021D5864(m);
                if (h != ((struct Obj20995 *)a)->f2C0)
                    func_021D5854(m);
            }
        }
    }
    for (k = 0; k < arr->n; k++)
        func_021D6C24(arr->e[k]);
}

void func_021B9DB8(char *p) {
    u32 i;
    char *q;
    for(i=0;i<4;i++) {
        q=p+i*40;
        ((struct Obj09942 *)q)->f20=0;
        ((struct Obj09942 *)q)->f2A=0;
        ((struct Obj09942 *)q)->f2C=0;
    }
    for(i=0;i<4;i++) *(u32 *)(p+i*4+0x3e0)=0;
}


void func_021B9DE8(char *p)
{
    u32 i;
    char *q;

    for (i = 0; i < 4; i++) {
        q = p + i * 0x28;
        if (((struct Obj03187 *)q)->f20) {
            func_020307B0(((struct Obj03187 *)q)->f20);
            ((struct Obj03187 *)q)->f20 = 0;
        }
        if (((struct Obj03187 *)q)->f24) {
            func_020307B0(((struct Obj03187 *)q)->f24);
            ((struct Obj03187 *)q)->f24 = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        q = p + i * 4;
        if (((struct Obj03187 *)q)->f3E0) {
            func_020307B0(((struct Obj03187 *)q)->f3E0);
            ((struct Obj03187 *)q)->f3E0 = 0;
        }
    }
}
