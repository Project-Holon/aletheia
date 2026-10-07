/*
 * file:     br_codein_p02.c
 * unit:     yes
 * function: func_021DBB3C, func_021DBBC4
 * address:  0x021DBB3C
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
 *   func_021DCE28 0x021DCE28 thumb ov183
 *   func_021DCE48 0x021DCE48 thumb ov183
 *   func_021DD054 0x021DD054 thumb ov183
 *   func_021DD0F4 0x021DD0F4 thumb ov183
 *   func_021DD1D4 0x021DD1D4 thumb ov183
 *   func_020409B4 0x020409B4 arm
 *   func_021FD15C 0x021FD15C thumb ov186
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_021FD714 0x021FD714 thumb ov186
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02025588 0x02025588 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_02012E40 0x02012E40 thumb
 *   func_021FF88C 0x021FF88C thumb ov186
 *   func_021F9C6C 0x021F9C6C thumb ov186
 *   func_021FD71C 0x021FD71C thumb ov186
 *   func_021FD72C 0x021FD72C thumb ov186
 *   func_021FD854 0x021FD854 thumb ov186
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021FC830 0x021FC830 thumb ov186
 *   func_021FD6B0 0x021FD6B0 thumb ov186
 *   func_021FD1BC 0x021FD1BC thumb ov186
 */
#include "../../matched/include/Obj00050.h"
#include "../../matched/include/Obj06598.h"
#include "../../matched/include/Obj24541.h"
#include "../../matched/include/Obj02892.h"
#include "../../matched/include/Obj24542.h"
#include "../../matched/include/Obj24543.h"
#include "../../matched/include/Obj24544.h"

struct PrintSys;
struct S020315D4;
typedef unsigned int   u32;

typedef unsigned char  u8;

extern void func_021DCE28(char *,char *);
extern void func_021DCE48(char *,char *);
extern void func_021DD054(char *,char *);
extern void func_021DD0F4(char *,char *);
extern void func_021DD1D4(char *,char *);
extern void func_020409B4(u32 index);
extern void func_021FD15C(void *,int);
extern void func_021FD820(char *);
extern void func_021FD714(void *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_02025588(void *p);
extern void func_020315D4(struct S020315D4 *p);
extern u8 func_02012E40(const u8 *o);
extern int func_021FF88C(char *p);
extern void func_021F9C6C(void *);
extern void func_021FD71C(u8 *p);
extern int func_021FD72C(int *p);
extern void func_021FD854(char *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern int func_021FC830(u8 *p);
extern int func_021FD6B0(u8 *p);
extern void func_021FD1BC(void *);
int func_021DBB3C(int task,int b,char *q,char *p);
int func_021DBBC4(int a,int b,int c,char *p);

int func_021DBB3C(int task,int b,char *q,char *p)
{
    int i;
    func_021DCE28(p,q);
    func_021DCE48(p,q);
    func_021DD054(p,q);
    func_021DD0F4(p,q);
    func_021DD1D4(p,q);
    ((struct Obj06598 *)q)->f4=((struct Obj00050 *)p)->fC8;
    func_020409B4(4);
    func_020409B4(1);
    if(((struct Obj00050 *)p)->f18) {
        func_021FD15C(((struct Obj00050 *)p)->f18,((struct Obj24541 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->f10);
        ((struct Obj00050 *)p)->f18=0;
    }
    for(i=0;i<2;i++) func_021FD820(*(char **)(p+i*4+0xc));
    func_021FD714((void *)(((struct Obj00050 *)p)->f8));
    func_0201C4C0(((struct Obj00050 *)p)->f4);
    func_02025588((void *)(((struct Obj00050 *)p)->f0));
    func_020315D4((struct S020315D4 *)task);
    return 1;
}

/*
 * extent: two bytes of zero alignment padding at 0x021DBC66
 */
int func_021DBBC4(int a,int b,int c,char *p)
{
    int i;
    if(func_02012E40(((struct Obj24542 *)(*(char * *)&((struct Obj02892 *)p)->fD0))->f28)==0 && func_021FF88C(((struct Obj24543 *)(*(char * *)&((struct Obj02892 *)p)->fD0))->f24)==2) {
        func_021F9C6C(((struct Obj24544 *)(*(char * *)&((struct Obj02892 *)p)->fD0))->f14);
        return 1;
    }
    func_021FD71C(((struct Obj02892 *)p)->f8);
    if(func_021FD72C(((struct Obj02892 *)p)->f8)) return 1;
    for(i=0;i<2;i++) func_021FD854(*(void **)(p+i*4+0xc));
    func_0201C4E4(((struct Obj02892 *)p)->f4);
    for(i=0;i<2;i++) if(*(void **)(p+i*4+0x28)) func_021FC830(*(void **)(p+i*4+0x28));
    for(i=0;i<5;i++) if(*(void **)(p+i*4+0x30)) func_021FC830(*(void **)(p+i*4+0x30));
    if(((struct Obj02892 *)p)->f44) func_021FD6B0(((struct Obj02892 *)p)->f44);
    if(((struct Obj02892 *)p)->f18) func_021FD1BC(((struct Obj02892 *)p)->f18);
    return 0;
}
