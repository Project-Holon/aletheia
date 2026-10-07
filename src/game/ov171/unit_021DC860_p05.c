/*
 * file:     unit_021DC860_p05.c
 * unit:     yes
 * function: func_021DE76C, func_021DE80C, func_021DE884, func_021DE8A8, func_021DE914
 * address:  0x021DE76C
 * region:   ov171
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021DEC94 0x021DEC94 data
 *   func_02025538 0x02025538 thumb
 *   func_02043678 0x02043678 arm
 *   func_020255A0 0x020255A0 thumb
 *   func_02025774 0x02025774 thumb
 *   func_0202570C 0x0202570C thumb
 *   func_020437AC 0x020437AC arm
 *   func_02025588 0x02025588 thumb
 *   func_02035C08 0x02035C08 arm
 *   func_021DE960 0x021DE960 thumb ov171
 *   func_0203633C 0x0203633C arm
 *   func_020362DC 0x020362DC arm
 *   d_021DED24 0x021DED24 data a4
 */
#include "../../matched/include/Obj01756.h"
#include "../../matched/include/Obj08252.h"

struct Bmp;
struct Grid;
struct Param;
struct Sys;
struct Obj020437AC;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed char s8;

typedef unsigned int u32;

typedef struct Descriptor {
    void *image;
    u16 x, y;
    void *source;
    u32 mode;
    u8 a, b;
    u16 id;
    u32 extra;
} Descriptor;

extern void *func_02025538(unsigned int a0, void *a1);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern struct Grid *func_020255A0(struct Sys *sys, const struct Param *param);
extern void func_02025774(u8 *g, u32 a);
extern void func_0202570C(struct Grid *g);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_02025588(void *);
extern int func_02035C08(const void *);
extern int func_021DE960(char *);
extern unsigned int func_0203633C(void);
extern u32 func_020362DC(void);
void func_021DE76C(u8 *p, int mode);
void func_021DE80C(char *p);
void func_021DE884(int *p);
int func_021DE8A8(char *p);
int func_021DE914(char *p);
extern u8 d_021DEC94[];
extern const char d_021DED24[];


/*
 * note: 2026-10-05 (wD7 lane16): EXACT. cur and i are both set before n (`u16 i = 0;` at the
 *   declaration, loop with an empty init), so r0/r1 are live while n is computed; the scheduler then sinks them.
 */
void func_021DE76C(u8 *p, int mode)
{
    u16 cur = *(s8 *)(p + 0xC5C);
    u16 i = 0;
    u16 n = *(u16 *)(p + *(s8 *)(p + 0xC5E) * 0xBC + 0xC4);
    for (; i < n; ) {
        if (mode == 1) {
            u8 *q = p + cur;
            q[0xB34] = *(u16 *)(d_021DEC94 + n * 0x18 + i * 4 - 0x16);
            q[0xB3A] = q[0xB34];
            cur++;
            if (cur >= *(u16 *)(p + *(s8 *)(p + 0xC5E) * 0xBC + 0xC4))
                cur = 0;
        } else {
            u8 *q = p + i;
            q[0xB34] = 0;
            q[0xB3A] = 0;
        }
        i++;
        n = *(u16 *)(p + *(s8 *)(p + 0xC5E) * 0xBC + 0xC4);
    }
}

void func_021DE80C(char *p)
{
    Descriptor descriptor;
    ((struct Obj01756 *)p)->fC50 = func_02025538(0x8C, ((struct Obj01756 *)p)->fB70);
    ((struct Obj01756 *)p)->fC58 = func_02043678(5, 3, 0x20, 0x8C);
    descriptor.image = ((struct Obj01756 *)p)->fC58;
    descriptor.x = 0x28;
    descriptor.y = 0xA8;
    descriptor.source = ((struct Obj01756 *)p)->fC18;
    descriptor.mode = 1;
    descriptor.a = 0;
    descriptor.b = 0;
    descriptor.id = 0xFFFF;
    descriptor.extra = 0;
    ((struct Obj01756 *)p)->fC54 = func_020255A0(((struct Obj01756 *)p)->fC50, (const struct Param *)(&descriptor));
    if (((struct Obj01756 *)p)->fC5F == 1) func_02025774(((struct Obj01756 *)p)->fC54, 0);
}

void func_021DE884(int *p) { func_0202570C(((struct Obj08252 *)p)->fC54); func_020437AC(((struct Obj08252 *)p)->fC58); func_02025588(((struct Obj08252 *)p)->fC50); }

int func_021DE8A8(char *p)
{
    int result = func_02035C08(d_021DED24);
    if (result == -1) {
        result = func_021DE960(p);
        if (result == 0xFF) {
            if (func_0203633C() & 0x220) return 0;
            if (func_0203633C() & 0x110) return 1;
            if (func_020362DC() & 1) return 4;
            if (func_020362DC() & 2) return 3;
            return (func_020362DC() & 0x400) ? 2 : 0xFF;
        }
    }
    return result;
}

int func_021DE914(char *p)
{
    int result = func_02035C08(d_021DED24);
    if (result != 3) {
        result = func_021DE960(p);
        if (result == 0xFF) {
            if (func_0203633C() & 0x220) return 0;
            if (func_0203633C() & 0x110) return 1;
            if (func_020362DC() & 2) return 3;
            return 0xFF;
        }
    }
    return result;
}
