/*
 * function: func_021DE1C8
 * address: 0x021DE1C8
 * packet: pkt_ov183_021DE1C8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021DE3E4 0x021DE3E4 thumb ov183
 *   func_021DE7C0 0x021DE7C0 thumb ov183
 */
#include "../include/Obj02519.h"
#include "../include/Obj06604.h"
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
extern void func_021DE3E4(char *, char *);
extern void func_021DE7C0(char *, char *);
int func_021DE1C8(void *a, int b, char *q)
{
    char *p = PROCSYS_AllocProcWork(a, 0x70, func_021F9B9C(((struct Obj06604 *)q)->fC));
    func_02082BCC(p, 0, 0x70);
    ((struct Obj02519 *)p)->f6C = func_021F9B9C(((struct Obj06604 *)q)->fC);
    ((struct Obj02519 *)p)->f0 = BMP_OAM_CreateSys(((struct Obj02519 *)p)->f6C, ((struct Obj06604 *)q)->f0);
    ((struct Obj02519 *)p)->f4 = (void *)func_0201C440((void *)(((struct Obj02519 *)p)->f6C));
    ((struct Obj02519 *)p)->f64 = func_021FD760((unsigned int)(((struct Obj06604 *)q)->f0), (char *)(((struct Obj06604 *)q)->f8), 1, ((struct Obj02519 *)p)->f6C);
    func_021DE3E4(p, q);
    func_021DE7C0(p, q);
    return 1;
}
