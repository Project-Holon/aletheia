/*
 * function: func_021DF920
 * address: 0x021DF920
 * packet: pkt_ov183_021DF920
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0201C440 0x0201C440 thumb
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_021E02F8 0x021E02F8 thumb ov183
 */
#include "../include/Obj01765.h"
#include "../include/Obj02230.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Obj24810;
extern unsigned func_021F9B9C(struct Obj24810 *p);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern void func_02082BCC(void *, int, unsigned int);
typedef unsigned int   u32;
extern u32 func_0201C440(void *p);
extern void *BMP_OAM_CreateSys(unsigned int a0, void *a1);
extern void *func_021FD12C(int a, void *owner, u16 heap);
extern void func_021FD170(char *p, char *q, void *text);
extern char *func_021FD760(unsigned owner, char *resources, int index, int heap);
extern void func_021FBE54(char *base, u32 idx, u32 area);
extern void func_021E02F8(char *p, int *q);
int func_021DF920(void *obj, int unused, char *q)
{
    char *p;
    int i;
    p = PROCSYS_AllocProcWork(obj, 0x58, func_021F9B9C((struct Obj24810 *)(*(char * *)&((struct Obj02230 *)q)->fC)));
    func_02082BCC(p, 0, 0x58);
    ((struct Obj01765 *)p)->f54 = func_021F9B9C((struct Obj24810 *)(*(char * *)&((struct Obj02230 *)q)->fC));
    ((struct Obj01765 *)p)->f48 = (void *)func_0201C440((void *)(((struct Obj01765 *)p)->f54));
    ((struct Obj01765 *)p)->f44 = BMP_OAM_CreateSys(((struct Obj01765 *)p)->f54, ((struct Obj02230 *)q)->f4);
    ((struct Obj01765 *)p)->f38 = (int)func_021FD12C(((struct Obj02230 *)q)->f8, (void *)(*(int *)&((struct Obj01765 *)p)->f48), ((struct Obj01765 *)p)->f54);
    func_021FD170((char *)(((struct Obj01765 *)p)->f38), (char *)(((struct Obj02230 *)q)->f8), (void *)0x6B);
    for (i = 0; i < 2; i++) {
        *(int *)(p + i * 4 + 0x3C) = (int)func_021FD760(*(int *)&((struct Obj02230 *)q)->f4, (char *)(((struct Obj02230 *)q)->f8), i, ((struct Obj01765 *)p)->f54);
    }
    ((struct Obj02230 *)q)->f14 = 0xFFFF;
    ((struct Obj02230 *)q)->f16 = 0xFF;
    ((struct Obj02230 *)q)->f17 = 0xFF;
    ((struct Obj02230 *)q)->f18 = 0x13;
    func_021FBE54((char *)(((struct Obj02230 *)q)->f8), 6, ((struct Obj01765 *)p)->f54);
    func_021E02F8(p, (int *)q);
    return 1;
}
