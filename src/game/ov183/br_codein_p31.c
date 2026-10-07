/*
 * file:     br_codein_p31.c
 * unit:     yes
 * function: func_021E2578, func_021E25E4, func_021E2640
 * address:  0x021E2578
 * region:   ov183
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02025538 0x02025538 thumb
 *   func_021FD6D8 0x021FD6D8 thumb ov186
 *   func_021E26B8 0x021E26B8 thumb ov183
 *   func_0201C440 0x0201C440 thumb
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021E2E48 0x021E2E48 thumb ov183
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_021FD714 0x021FD714 thumb ov186
 *   func_02025588 0x02025588 thumb
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 *   func_020315D4 0x020315D4 arm
 *   func_02012E40 0x02012E40 thumb
 *   func_021FF88C 0x021FF88C thumb ov186
 *   func_021F9C6C 0x021F9C6C thumb ov186
 *   func_021FD71C 0x021FD71C thumb ov186
 *   func_021FD72C 0x021FD72C thumb ov186
 *   func_021FD854 0x021FD854 thumb ov186
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021FD1BC 0x021FD1BC thumb ov186
 *   func_021FC830 0x021FC830 thumb ov186
 */
#include "../../matched/include/Obj03332.h"
#include "../../matched/include/Obj06614.h"
#include "../../matched/include/Obj03333.h"
#include "../../matched/include/Obj24671.h"
#include "../../matched/include/Obj24672.h"
#include "../../matched/include/Obj03883.h"
#include "../../matched/include/Obj24673.h"
#include "../../matched/include/Obj24674.h"
#include "../../matched/include/Obj24675.h"

struct Obj24810;
struct Obj0203159C;
struct PrintSys;
struct S020315D4;
typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned char  u8;

extern unsigned func_021F9B9C(struct Obj24810 *p);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,unsigned);
extern void *func_02025538(unsigned int a0, void *a1);
extern int *func_021FD6D8(int payload, int callback, u32 heap);
extern void func_021E26B8(int *task, int *state, char *p);
extern u32 func_0201C440(void *);
extern char *func_021FD760(unsigned owner, char *resources, int index, int heap);
extern void func_021E2E48(char *p, int a, int b);
extern void func_021FD820(char *);
extern void func_021FD15C(void *,int);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_021FD714(void *p);
extern void func_02025588(void *p);
extern void func_021F9BA0(unsigned *ctx);
extern void func_020315D4(struct S020315D4 *);
extern u8 func_02012E40(const u8 *o);
extern int func_021FF88C(char *p);
extern void func_021F9C6C(int);
extern void func_021FD71C(u8 *p);
extern int func_021FD72C(int *p);
extern void func_021FD854(char *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021FD1BC(void *p);
extern int func_021FC830(u8 *p);
int func_021E2578(void *obj,int b,char *q);
int func_021E25E4(int obj,int b,int c,char *p);
int func_021E2640(int a,int b,int c,char *p);

int func_021E2578(void *obj,int b,char *q)
{
    char *p;
    int i;
    p=func_0203159C(obj,0x54,func_021F9B9C(((struct Obj06614 *)q)->f10));
    func_02082BCC(p,0,0x54);
    *(char * *)&((struct Obj03332 *)p)->f3C=q;
    ((struct Obj03332 *)p)->f38=func_021F9B9C(((struct Obj06614 *)q)->f10);
    ((struct Obj03332 *)p)->f0=func_02025538(((struct Obj03332 *)p)->f38,((struct Obj06614 *)q)->f4);
    ((struct Obj03332 *)p)->fC=func_021FD6D8((int)p,(int)func_021E26B8,((struct Obj03332 *)p)->f38);
    ((struct Obj03332 *)p)->f4=func_0201C440((void *)(unsigned int)((struct Obj03332 *)p)->f38);
    for (i=0;i<2;i++) *(void **)(p+i*4+0x30)=func_021FD760((unsigned int)(((struct Obj06614 *)q)->f4),(char *)(((struct Obj06614 *)q)->f8),i,((struct Obj03332 *)p)->f38);
    return 1;
}

/*
 * Extent remainder: zero alignment halfword at 021E263E.
 */
int func_021E25E4(int obj,int b,int c,char *p)
{
    int i;
    func_021E2E48(p+0x4c,(int)p,(int)(*(char * *)&((struct Obj03333 *)p)->f3C));
    for (i=0;i<2;i++) func_021FD820(*(char **)(p+i*4+0x30));
    if (((struct Obj03333 *)p)->f8) {
        func_021FD15C(((struct Obj03333 *)p)->f8,((struct Obj24671 *)(*(char * *)&((struct Obj03333 *)p)->f3C))->f8);
        *(int *)&((struct Obj03333 *)p)->f8=0;
    }
    func_0201C4C0((struct PrintSys *)(((struct Obj03333 *)p)->f4));
    func_021FD714((void *)(((struct Obj03333 *)p)->fC));
    func_02025588((void *)(((struct Obj03333 *)p)->f0));
    func_021F9BA0((unsigned int *)(((struct Obj24672 *)(*(char * *)&((struct Obj03333 *)p)->f3C))->f10));
    func_020315D4((struct S020315D4 *)obj);
    return 1;
}

int func_021E2640(int a,int b,int c,char *p)
{
    int i;
    if (!func_02012E40((const u8 *)(((struct Obj24673 *)(*(char * *)&((struct Obj03883 *)p)->f3C))->f14)) && func_021FF88C((char *)(((struct Obj24674 *)(*(char * *)&((struct Obj03883 *)p)->f3C))->fC))==2) {
        func_021F9C6C(((struct Obj24675 *)(*(char * *)&((struct Obj03883 *)p)->f3C))->f10);
        return 1;
    }
    func_021FD71C((u8 *)(((struct Obj03883 *)p)->fC));
    if (func_021FD72C((int *)(((struct Obj03883 *)p)->fC))) return 1;
    for (i=0;i<2;i++) func_021FD854((char *)(*(int *)(p+i*4+0x30)));
    func_0201C4E4((struct PrintSys *)(((struct Obj03883 *)p)->f4));
    if (((struct Obj03883 *)p)->f8) func_021FD1BC((void *)(((struct Obj03883 *)p)->f8));
    for (i=0;i<2;i++) if (*(int *)(p+i*4+0x28)) func_021FC830((u8 *)(*(int *)(p+i*4+0x28)));
    return 0;
}
