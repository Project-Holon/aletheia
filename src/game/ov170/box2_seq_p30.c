/*
 * file:     box2_seq_p30.c
 * unit:     yes
 * function: func_021EA75C, func_021EA770, func_021EA784, func_021EA798, func_021EA808
 * address:  0x021EA75C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021EF32C  0x021EF32C  thumb  ov170
 *   func_021EC688  0x021EC688  thumb  ov170
 *   func_021EF33C  0x021EF33C  thumb  ov170
 *   func_021EC6F4  0x021EC6F4  thumb  ov170
 *   func_021DD210 0x021DD210 thumb
 *   func_021EC35C 0x021EC35C thumb
 *   func_021DEDCC 0x021DEDCC thumb
 *   func_021DEC98 0x021DEC98 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E0128 0x021E0128 thumb
 *   func_021E00C4 0x021E00C4 thumb
 *   func_02030734 0x02030734 arm
 *   d_021F140C 0x021F140C data a1
 */
#include "../../matched/include/Obj18491.h"
#include "../../matched/include/Obj18493.h"
#include "../../matched/include/Obj18495.h"
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj23958.h"

#define WORK(p) (*(char **)((p) + 0x2C))
struct WinMgr;
typedef unsigned short u16;

typedef unsigned int   u32;

extern void func_021EF32C(struct WinMgr *mgr);
extern void func_021EC688(char *p);
extern void func_021EF33C(struct WinMgr *mgr);
extern void func_021EC6F4(char *p);
extern int func_021DD210(unsigned char *p, unsigned a, unsigned b);
extern void func_021EC35C(char **p, int box);
extern int func_021DEDCC(char *p, int box);
extern void func_021DEC98(char *p, void *a, int dir);
extern void func_020061E4(unsigned se);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E0128(char *p);
extern int func_021E00C4(char *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
void func_021EA75C(int p);
void func_021EA770(int p);
void func_021EA784(int p);
int func_021EA798(unsigned char *p, int sel);
void func_021EA808(char *p);
extern const char d_021F140C[];

/*
 * Stop one 0x74 sub-object, then the plain stop.
 */
void func_021EA75C(int p)
{
    func_021EF32C(*(struct WinMgr **)(((struct Obj18491 *)p)->f2C + 0x74));
    func_021EC688((char *)p);
}

/*
 * Resume one 0x74 sub-object, then the plain resume.
 */
void func_021EA770(int p)
{
    func_021EF33C(*(struct WinMgr **)(((struct Obj18493 *)p)->f2C + 0x74));
    func_021EC6F4((char *)p);
}

/*
 * Plain stop, then stop the 0x74 sub-object.
 */
void func_021EA784(int p)
{
    func_021EC688((char *)p);
    func_021EF32C(*(struct WinMgr **)(((struct Obj18495 *)p)->f2C + 0x74));
}


int func_021EA798(unsigned char *p, int sel)
{
    int (*cb)(unsigned char *);
    int r = func_021DD210(p, p[0x14], *(unsigned char *)(WORK(p) + 0xA17F));
    p[0x14] = *(unsigned char *)(WORK(p) + 0xA17F);
    func_021EC35C((char **)p, p[0x14]);
    func_021DEC98((char *)p, (void *)func_021DEDCC((char *)p, p[0x14]), r);
    if (r == 1)
        cb = (int (*)(unsigned char *))func_021E0128;
    else
        cb = (int (*)(unsigned char *))func_021E00C4;
    switch (sel) {
    case 0:
        ((struct Obj00000 *)p)->f28 = 0x15;
        break;
    case 1:
        ((struct Obj00000 *)p)->f28 = 0x63;
        break;
    }
    func_020061E4(0x548);
    return func_021E8FC0((char *)p, (int)cb, ((struct Obj00000 *)p)->f28);
}


void func_021EA808(char *p)
{
    unsigned short *q = func_02030734(0x804C, 4, 0, d_021F140C, 0x2305);
    q[0] = 0;
    q[1] = 0;
    *(unsigned short * *)&((struct Obj23958 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA190 = q;
}
