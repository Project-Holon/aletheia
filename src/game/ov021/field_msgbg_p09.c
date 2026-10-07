/*
 * file:     field_msgbg_p09.c
 * unit:     yes
 * function: func_0218B924, func_0218B930, func_0218B974, func_0218B9FC
 * address:  0x0218B924
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0218BBF4  0x0218BBF4  thumb
 *   func_0218B910  0x0218B910  thumb  ov021
 *   func_0218BBD0  0x0218BBD0  thumb  ov021
 *   func_0218BA04  0x0218BA04  thumb  ov021
 *   func_0218C4A0  0x0218C4A0  thumb  ov021
 *   func_0218C4EC  0x0218C4EC  thumb
 */
#include "../../matched/include/Obj17893.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    int f0;
    unsigned short id;
    short x;
    short y;
    short z;
} Ent;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

typedef struct {
    int x;
    int y;
    int z;
    unsigned short w;
    unsigned char hi;
    unsigned char lo;
} Src;

typedef struct {
    int k;
    Vec pos;
    unsigned short w;
} Args;

extern int func_0218BBF4(u32 a, u32 b);
int func_0218B910(u32 a, u32 b);
int func_0218BBD0(void *p, unsigned int i);
void func_0218BA04(void *p, int a, const Src *s, int d);
void func_0218C4A0(void *p, int a, Args *args, int d);
extern void func_0218C4EC(unsigned char *p, void *key);
int func_0218B924(u8 *p, u32 a1);
int func_0218B930(void *p, int a, Vec *pos, int *k);
int func_0218B974(void *p, int a, const Src *s, int n);
void func_0218B9FC(int a, int obj);


/*
 * Tail-call thunk: the object's word at +0x18.
 *
 * Addresses are Black-image addresses.
 */
int func_0218B924(u8 *p, u32 a1)
{
    return func_0218BBF4(((struct Obj17893 *)p)->f18, a1);
}


static inline void Vec_Set(Vec *v, int x, int y, int z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}


int func_0218B930(void *p, int a, Vec *pos, int *k)
{
    Ent *e = (Ent *)func_0218B910((u32)p, a);
    if (e->id == 0xFFFF)
        return 0;
    *k = func_0218BBD0(p, e->id);
    Vec_Set(pos, e->x << 12, e->y << 12, e->z << 12);
    return 1;
}


/*
 * The const on s is load-bearing: with a plain Src * the compiler keeps
 * &s[i] in a register and spills s; const keeps s and i*16 in registers.
 */
int func_0218B974(void *p, int a, const Src *s, int n)
{
    Args args;
    int i;
    int cnt = 0;
    for (i = 0; i < n; i++) {
        func_0218BA04(p, a, s + i, cnt);
        if (func_0218B930(p, (unsigned short)(s[i].lo + (s[i].hi << 8)), &args.pos, &args.k) == 1) {
            cnt++;
            args.w = s[i].w;
            args.pos.x += s[i].x;
            args.pos.y += s[i].y;
            args.pos.z -= s[i].z;
            func_0218C4A0(p, a, &args, cnt);
        }
        cnt++;
    }
    return cnt;
}


/*
 * Tail-call thunk: forwards to func_0218C4EC with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_0218B9FC(int a, int obj)
{
    func_0218C4EC((unsigned char *)a, (void *)obj);
}
