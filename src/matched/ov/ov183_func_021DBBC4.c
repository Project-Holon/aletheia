/*
 * function: func_021DBBC4
 * address: 0x021DBBC4
 * packet: pkt_ov183_021DBBC4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding at 0x021DBC66
 * symbols:
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
#include "../include/Obj02892.h"
#include "../include/Obj24542.h"
#include "../include/Obj24543.h"
#include "../include/Obj24544.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct PrintSys;
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
