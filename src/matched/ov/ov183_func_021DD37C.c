/*
 * function: func_021DD37C
 * address: 0x021DD37C
 * packet: pkt_ov183_021DD37C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 2 zero alignment bytes at 0x021DD3F6
 * symbols:
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_021DDE2C 0x021DDE2C thumb ov183
 *   func_021DD5C8 0x021DD5C8 thumb ov183
 */
#include "../include/Obj00631.h"
#include "../include/Obj00632.h"
typedef unsigned short u16;
struct Obj24810;
extern unsigned func_021F9B9C(struct Obj24810 *p);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern void func_02082BCC(void *, int, unsigned int);
extern void *BMP_OAM_CreateSys(unsigned int a0, void *a1);
typedef unsigned int   u32;
extern u32 func_0201C440(void *p);
extern char *func_021FD760(unsigned owner, char *resources, int index, int heap);
extern void func_021FBE54(char *, unsigned int, unsigned int);
extern void func_021DDE2C(char *, char *);
extern void func_021DD5C8(char *, char *);
int func_021DD37C(void *a, int unused, char *q)
{
    char *p = PROCSYS_AllocProcWork(a, 0x80, func_021F9B9C((struct Obj24810 *)(*(char * *)&((struct Obj00632 *)q)->fC)));
    func_02082BCC(p, 0, 0x80);
    ((struct Obj00631 *)p)->f7C = func_021F9B9C((struct Obj24810 *)(*(char * *)&((struct Obj00632 *)q)->fC));
    ((struct Obj00631 *)p)->f0 = BMP_OAM_CreateSys(((struct Obj00631 *)p)->f7C, ((struct Obj00632 *)q)->f4);
    ((struct Obj00631 *)p)->f4 = (void *)func_0201C440((void *)(((struct Obj00631 *)p)->f7C));
    ((struct Obj00631 *)p)->f74 = func_021FD760((unsigned int)(((struct Obj00632 *)q)->f4), (char *)(*(int *)&((struct Obj00632 *)q)->f8), 1, ((struct Obj00631 *)p)->f7C);
    func_021FBE54(*(char * *)&((struct Obj00632 *)q)->f8, 13, ((struct Obj00631 *)p)->f7C);
    func_021DDE2C(p, q);
    func_021DD5C8(p, q);
    return 1;
}
