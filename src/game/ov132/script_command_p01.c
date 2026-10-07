/*
 * file:     script_command_p01.c
 * unit:     yes
 * function: func_021F9E40, func_021F9E44, func_021F9E4C, func_021F9E50, func_021F9E94, func_021F9ECC, func_021F9ED4, func_021F9EDC, func_021F9F58, func_021F9F74, func_021F9FB4, func_021F9FD0, func_021F9FEC, func_021FA04C, func_021FA064, func_021FA0D0
 * address:  0x021F9E40
 * region:   ov132
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
 *   func_02050B80 0x02050B80 arm
 *   d_021FDCB0 0x021FDCB0 data a4
 *   func_02050ED4 0x02050ED4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02051574 0x02051574 arm
 *   func_02051534 0x02051534 arm
 *   func_02050C04 0x02050C04 arm
 *   func_0205121C 0x0205121C arm
 *   func_020056BC 0x020056BC thumb
 *   func_02051230 0x02051230 arm
 *   func_02051620 0x02051620 arm
 *   func_02050DB8 0x02050DB8 arm
 *   func_020515B4 0x020515B4 arm
 *   func_02051630  0x02051630  arm
 *   func_02051838  0x02051838  arm
 *   func_021FA0D8 0x021FA0D8 thumb ov132
 *   d_021FDCC4 0x021FDCC4 data a4
 *   func_021FA278  0x021FA278  thumb
 *   func_021FA0D4  0x021FA0D4  thumb
 *   func_021F9DFC 0x021F9DFC thumb ov132
 *   func_02005728 0x02005728 thumb
 *   func_021FA3A8 0x021FA3A8 thumb ov132
 *   func_021FA4AC 0x021FA4AC thumb ov132
 *   func_021FA27C 0x021FA27C thumb ov132
 */
#include "../../matched/include/Obj23222.h"
#include "../../matched/include/Obj23223.h"
#include "../../matched/include/Obj23224.h"
#include "../../matched/include/Obj10535.h"
#include "../../matched/include/Obj14089.h"
#include "../../matched/include/Obj10536.h"
#include "../../matched/include/Obj14090.h"
#include "../../matched/include/Obj23225.h"
#include "../../matched/include/Obj08156.h"
#include "../../matched/include/Obj10539.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { int x, y, z; } Vec;

typedef struct { int a; Vec v; } Part;

typedef struct { char pad[0x4808]; Part part[4]; } Obj;

typedef signed int     s32;

extern void *func_02030734(unsigned, unsigned, int, const char *, u16);
extern void func_02050B80(unsigned);
extern void func_02050ED4(void);
extern u32 func_020307B0(void *p);
extern int func_02051574(void);
extern int func_02051534(void);
extern int func_02050C04(int a, int b, int c, int d);
extern int func_0205121C(u32 a, u32 b, u32 c);
extern unsigned func_020056BC(void);
extern void func_02051230(void *, void *, unsigned, unsigned);
extern void func_02051620(u32);
extern void func_02050DB8(u8 *p);
extern int func_020515B4(void *p, int b, int c);
extern void func_02051630(void **p, void *q);
extern void func_02051838(void *, int);
extern void func_021FA0D8(char *p, char *q);
extern void func_021FA278(void *);
extern void func_021FA0D4(void *);
extern u16 func_021F9DFC(void *p);
extern unsigned func_02005728(unsigned);
extern void func_021FA3A8(char *p, u8 *rec, unsigned type);
extern void func_021FA4AC(char *);
extern void func_021FA27C(char *);
void func_021F9E40(u8 *p,u32 v);
u32 func_021F9E44(u8 *p);
void func_021F9E4C(u8 *a0);
char *func_021F9E50(unsigned heap);
void func_021F9E94(u8 *p);
int func_021F9ECC(u8 *a0);
int func_021F9ED4(u8 *a0);
char *func_021F9EDC(char *p, u32 a);
void func_021F9F58(u8 *unused,u8 *p);
void func_021F9F74(char *p, unsigned i, Vec *v);
void func_021F9FB4(char *p, int i);
void func_021F9FD0(char *p, int i, int a);
char *func_021F9FEC(unsigned heap, void *a, unsigned b);
void func_021FA04C(u8 *p);
void func_021FA064(char *p);
void func_021FA0D0(char *a0);
extern const char d_021FDCB0[];
extern const char d_021FDCC4[];

void func_021F9E40(u8 *p,u32 v) { ((struct Obj23222 *)p)->f14=v; }

u32 func_021F9E44(u8 *p) { return ((struct Obj23223 *)p)->f1E8; }

void func_021F9E4C(u8 *a0) { }

char *func_021F9E50(unsigned heap)
{
    u8 i = 0;
    char *p = func_02030734(heap, 0x24244, 0, d_021FDCB0, 76);
    ((struct Obj23224 *)p)->f0 = heap;
    func_02050B80(heap);
    for (; i < 8; i++)
        *(int *)(p + i * 0x4848 + 4) = 0;
    return p;
}

/*
 * lever: the load uses p+index*0x4848+4, while the outgoing pointer uses p+4+index*0x4848; the latter keeps p+4 hoisted in r6. Using the load's grouping for both gave 49 concrete byte differences.
 */
void func_021F9E94(u8 *p) { u8 i; for(i=0;i<8;i++) { if(*(u32 *)(p+i*0x4848+4)==1) func_021F9F58(p,p+4+i*0x4848); } func_02050ED4(); func_020307B0(p); }

int func_021F9ECC(u8 *a0) { return func_02051574(); }

int func_021F9ED4(u8 *a0) { return func_02051534(); }

char *func_021F9EDC(char *p, u32 a)
{
    char *q = 0;
    void *v;
    u8 i;
    u8 j;
    for (i = 0; i < 8; i++) if (*(int *)(p + i * 0x4848 + 4) == 0) q = (p + 4) + i * 0x4848;
    j = 0;
    ((struct Obj10535 *)q)->f4804 = (void *)func_02050C04((int)(q + 4), 0x4800, 0, ((struct Obj14089 *)p)->f0);
    v = (void *)func_0205121C(47, a, ((struct Obj14089 *)p)->f0);
    func_02051230(((struct Obj10535 *)q)->f4804, v, 0, func_020056BC());
    for (; j < 4; j++) *(int *)(q + j * 16 + 0x4808) = 0;
    ((struct Obj10535 *)q)->f0 = 1;
    return q;
}

void func_021F9F58(u8 *unused,u8 *p) { ((struct Obj10536 *)p)->f0=0; func_02051620(((struct Obj10536 *)p)->f4804); func_02050DB8((u8 *)(((struct Obj10536 *)p)->f4804)); }

static inline void set(Vec *p, int x, int y, int z)
{
    p->x = x;
    p->y = y;
    p->z = z;
}

/*
 * lever: Non-const Vec source preserves alias dependence: inline setter
 * arguments load z, y, x after the handle store and before vector stores.
 * const int * and const Vec * sources both gave DIFF, 19 concrete bytes.
 */
void func_021F9F74(char *p, unsigned i, Vec *v)
{
    int a = func_020515B4(((struct Obj14090 *)p)->f4804, i, (int)v);
    if (a == 0 || i < 4) {
        ((Obj *)p)->part[i].a = a;
        set(&((Obj *)p)->part[i].v, v->x, v->y, v->z);
    }
}


/*
 * Promoted from MATCH by the recursive-unblocker lane: 0x02051630 now has an
 * EXACT arm9 shard entry (pkt_02051630), so the blx at +0012 resolves via
 * `matched`.  Verified EXACT.
 *
 * Addresses are Black-image addresses.
 */
void func_021F9FB4(char *p, int i)
{
    int v = *(int *)(p + i * 16 + 0x4808);

    if (v != 0)
        func_02051630(((struct Obj23225 *)p)->f4804, (void *)v);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021F9FD0(char *p, int i, int a)
{
    void *v = *(void **)(p + i * 16 + 0x4808);

    if (v != 0)
        func_02051838(v, a);
}

char *func_021F9FEC(unsigned heap, void *a, unsigned b)
{
    u8 i = 0;
    char *p = func_02030734(heap, 0x3e4, 0, d_021FDCC4, 115);
    ((struct Obj08156 *)p)->f0 = heap;
    func_021FA0D0(p);
    func_021FA0D8(p, (char *)b);
    ((struct Obj08156 *)p)->f1E8 = a;
    ((struct Obj08156 *)p)->f200 = 0;
    for (; i < 4; i++) *(int *)(p + i * 4 + 0x1ec) = 0;
    ((struct Obj08156 *)p)->f1FC = 255;
    return p;
}


void func_021FA04C(u8 *p)
{
    func_021FA278(p);
    func_021FA0D4(p);
    func_020307B0(p);
}

/*
 * extent: compiled ends 021FA0CE; two zero padding bytes before labelled 021FA0D0.
 */
void func_021FA064(char *p)
{
    u8 i;
    if (func_021F9DFC(((struct Obj10539 *)p)->f1E8) == 0) {
        if (func_02005728(10) == 0) {
            for (i = 0; i < 3; i++) {
                u8 a = func_02005728(4);
                u8 b = func_02005728(60);
                func_021FA3A8(p, (u8 *)(p + 0x204 + b * 8), a);
            }
        }
    } else {
        if (((struct Obj10539 *)p)->f200 == 1) {
            func_021FA4AC(p);
            ((struct Obj10539 *)p)->f200 = 0;
        }
        func_021FA27C(p);
    }
}

void func_021FA0D0(char *a0) { }
