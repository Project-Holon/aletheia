/*
 * file:     unit_021E908C.c
 * unit:     yes
 * function: func_021E908C, func_021E90A0, func_021E90D0, func_021E9100, func_021E9104
 * address:  0x021E908C
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
 *   func_06899BE0  0x06899BE0  thumb
 *   func_0689B780  0x0689B780  thumb
 *   func_020310C4  0x020310C4  arm
 *   func_021F78E4  0x021F78E4  thumb  ov094
 *   d_021F3840  0x021F3840  data  a4
 *   d_021F3844  0x021F3844  data  a4
 *   func_021F745C  0x021F745C  thumb  ov094
 *   func_021F7544  0x021F7544  thumb  ov094
 *   func_020307B0  0x020307B0  arm
 *   func_021EB028  0x021EB028  thumb  ov093
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_021EB32C  0x021EB32C  thumb  ov093
 *   func_021EB52C  0x021EB52C  thumb  ov093
 *   func_021CD9C8  0x021CD9C8  thumb  ov093
 *   func_021CD9DC  0x021CD9DC  thumb  ov093
 */
#include "../../matched/include/Obj21551.h"
#include "../../matched/include/Obj01136.h"

struct Tcbl;
struct Param;
struct QD;
struct E {
    unsigned int k;
    unsigned int v;
};

typedef int (*Step)(void *self, void *a, void *b);

struct S {
    char pad[0x10];
    int state;
    Step fn;
    char a[0x14];
    char b[4];
};

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void func_020310C4(struct Tcbl *p);
extern void func_021F78E4(void);
extern void *func_021F745C(u8 *p, int a, u16 heap);
extern void func_021F7544(void *p, int arg, u16 heap);
extern u32 func_020307B0(void *p);
extern void func_021EB028(u8 *p);
extern void func_06899BE0(void *p);
extern u32 func_021CD9E0(u8 *p);
extern void func_021EB32C(u8 *p, u32 flag);
extern int func_021EB52C(u8 *p);
extern u32 func_021CD9C8(u8 *p);
extern u16 func_021CD9DC(struct QD *p);
extern void func_0689B780(void *a, void *b);
void func_021E908C(char *p);
void func_021E90A0(unsigned int *o, unsigned int key);
int func_021E90D0(struct S *s);
/* 021E9100 adds r0,#0x2c */ u8 *func_021E9100(u8 *p, int n);
int func_021E9104(u8 *p, int *st);
extern const struct E d_021F3840[];
extern const struct E d_021F3844[];


void func_021E908C(char *p)
{
    func_020310C4(((struct Obj21551 *)p)->f178);
    func_021F78E4();
}


void func_021E90A0(unsigned int *o, unsigned int key)
{
    unsigned int i;

    for (i = 0; i < 2; i++) {
        if (key == d_021F3840[i].k) {
            o[4] = key;
            o[5] = d_021F3844[i].k;
            o[6] = 0;
            return;
        }
    }
}


int func_021E90D0(struct S *s)
{
    if (s->state != 4) {
        if (s->fn(s, s->a, s->b) != 0) {
            s->state = 4;
            s->fn = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}


/* 021E9100  adds r0,#0x2c */
/*
 * Leaf with no calls and no pool; 2 instructions, 4 bytes: adds r0, #0x2c; bx lr.
 */
u8 *func_021E9100(u8 *p, int n) { return p + 0x2c; }


int func_021E9104(u8 *p, int *st)
{
    void *r;

    switch (*st) {
    case 0:
        r = func_021F745C(*(u8 * *)&((struct Obj01136 *)p)->f0, *(int *)&((struct Obj01136 *)p)->f17C, ((struct Obj01136 *)p)->f184);
        func_021F7544(r, ((struct Obj01136 *)p)->fB4, ((struct Obj01136 *)p)->f184);
        func_020307B0(r);
        func_021EB028(*(u8 * *)&((struct Obj01136 *)p)->f17C);
        func_06899BE0(((struct Obj01136 *)p)->f180);
        (*st)++;
        break;
    case 1:
        func_021EB32C(*(u8 * *)&((struct Obj01136 *)p)->f17C, func_021CD9E0(*(u8 * *)&((struct Obj01136 *)p)->f4));
        (*st)++;
        break;
    case 2:
        if (func_021EB52C(*(u8 * *)&((struct Obj01136 *)p)->f17C) != 0) {
            if (func_021CD9C8(*(u8 * *)&((struct Obj01136 *)p)->f4) != 0) {
                ((struct Obj01136 *)p)->f160 = 1;
                ((struct Obj01136 *)p)->f164 = 1;
                ((struct Obj01136 *)p)->f168 = func_021CD9DC((struct QD *)(*(u8 * *)&((struct Obj01136 *)p)->f4));
                ((struct Obj01136 *)p)->f16C = 0;
                if (func_021CD9E0(*(u8 * *)&((struct Obj01136 *)p)->f4) == 0) {
                    func_0689B780(((struct Obj01136 *)p)->f180, p + 0x160);
                }
            }
            return 1;
        }
        break;
    }
    return 0;
}
