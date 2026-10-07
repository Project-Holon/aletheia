/*
 * file:     pokemontrade_proc_p02.c
 * unit:     yes
 * function: func_021D8C6C, func_021D8C84, func_021D8CCC, func_021D8D4C, func_021D8DD0, func_021D8E24, func_021D8E80
 * address:  0x021D8C6C
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E66E8  0x021E66E8  thumb  ov119
 *   func_0204B800 0x0204B800 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B454  0x0204B454  arm
 *   func_02035CB8  0x02035CB8  arm
 *   func_021E4AB8  0x021E4AB8  thumb  ov119
 *   func_021E64DC  0x021E64DC  thumb  ov119
 *   func_02007A18  0x02007A18  thumb
 *   func_0201747C  0x0201747C  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_020173F0  0x020173F0  thumb
 *   func_020173EC  0x020173EC  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_020185F4 0x020185F4 thumb
 */
#include "../../matched/include/Obj04474.h"
#include "../../matched/include/Obj00001.h"
#include "../../matched/include/Obj08050.h"
#include "../../matched/include/Obj22705.h"

struct Node;
struct Obj;
struct Vec2;
struct Actor;
struct PtS;
struct Sub020079BCEntry;
struct Mon;
typedef unsigned int   u32;

typedef signed short s16;

typedef unsigned short u16;

extern void func_021E66E8(void *p);
extern void func_0204B800(struct Node *node, u32 val);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_02082BCC(void *,int,int);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern void func_021E4AB8(int a0, int a1, int a2);
extern void func_021E64DC(int p, int i, int j, int x, int y, void *q);
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
extern void *func_0201747C(struct Mon *p, u32 heap);
extern u32 func_0201AA18(void *m);
extern void *func_0201AB28(void *m, u32 c);
extern void *func_020173F0(u16 species, u16 level, unsigned long long id, u16 heap);
extern u32 func_020173EC(void);
extern void func_02082D44(void *dst, const void *src, int n);
extern void *func_020185F4(void *a);
void func_021D8C6C(void *p);
void func_021D8C84(void *p);
void func_021D8CCC(void *p, int x, int y, int z, int a4);
void *func_021D8D4C(void **a, int b, int c, char *p);
void *func_021D8DD0(void *a, int b, int c, char *p);
char *func_021D8E24(int a, int b, char *p);
void func_021D8E80(void *a0);


/*
 * Clear the pending pointer and hand the object to the updater.
 */
void func_021D8C6C(void *p)
{
    if (((struct Obj04474 *)p)->fF60 != 0)
        ((struct Obj04474 *)p)->fF60 = 0;
    func_021E66E8(p);
}

void func_021D8C84(void *p) {
 if(((struct Obj00001 *)p)->fF60!=0) {
 func_0204B800((struct Node *)(((struct Obj00001 *)p)->fF60),16);
 func_0204B404((struct Obj *)(((struct Obj00001 *)p)->fF60),(const struct Vec2 *)((char *)p+0xf64),1);
 func_0204B3DC((struct Obj *)((struct Obj00001 *)p)->fF60,1);
 ((struct Obj00001 *)p)->fF7C=-1;
 ((struct Obj00001 *)p)->fF80=-1;
 func_021D8C6C(p); func_02082BCC((char *)p+4,0,2);
 }
}


void func_021D8CCC(void *p, int x, int y, int z, int a4)
{
    int o1, o2;

    ((struct Obj00001 *)p)->fF60 = x;
    func_0204B454((struct Actor *)x, (struct PtS *)((char *)p + 0xf64), 1);
    func_021E4AB8((int)p, ((struct Obj00001 *)p)->fF60, 1);
    if (func_02035CB8((u32 *)(&o1), (u32 *)(&o2)) == 0)
        return;
    ((struct Obj00001 *)p)->fF68 = (s16)((struct Obj00001 *)p)->fF64 - o1;
    ((struct Obj00001 *)p)->fF6A = (s16)((struct Obj00001 *)p)->fF66 - o2;
    func_021E64DC((int)p, y, z,
                  o1 + (s16)((struct Obj00001 *)p)->fF68,
                  o2 + (s16)((struct Obj00001 *)p)->fF6A,
                  (void *)a4);
    ((struct Obj00001 *)p)->fF60 = ((struct Obj00001 *)p)->fF20;
}


void *func_021D8D4C(void **a, int b, int c, char *p)
{
    int n;
    void *res = 0;

    if (b == -1)
        goto out;
    n = ((struct Obj08050 *)p)->f630;
    if (b > n)
        return 0;
    if (b != n && c != -1) {
        res = func_0201747C((struct Mon *)func_02007A18(a, b, c), ((struct Obj08050 *)p)->f5F4);
    } else {
        void *m = ((struct Obj08050 *)p)->f838;
        if (c >= (int)func_0201AA18(m))
            goto out;
        if (c == -1)
            goto out;
        {
            void *mon = func_020173F0(1, 1, 1, ((struct Obj08050 *)p)->f5F4);
            int sz = func_020173EC();
            func_02082D44(func_0201AB28(m, c), mon, sz);
            res = mon;
        }
    }
out:
    return res;
}


void *func_021D8DD0(void *a, int b, int c, char *p)
{
    void *m;
    int n;

    if (b != -1) {
        n = ((struct Obj00001 *)p)->f630;
        if (b > n)
            return 0;
        if (b != n && c != -1)
            return func_02007A18(a, b, c);
        m = ((struct Obj00001 *)p)->f838;
        if (c < (int)func_0201AA18(m) && c != -1)
            return func_020185F4(func_0201AB28(m, c));
    }
    return 0;
}


char *func_021D8E24(int a, int b, char *p)
{
    int n;

    if (a != -1) {
        n = ((struct Obj22705 *)p)->f630;
        if (a > n)
            return 0;
        if (a != n && b != -1)
            return p + 0x11fc + (a * 0x1e + 6 + b) * 4;
        if (b >= 0 && b < 6)
            return p + 0x11fc + b * 4;
        return 0;
    }
    return 0;
}

/*
 * Empty stub.
 */
void func_021D8E80(void *a0)
{
}
