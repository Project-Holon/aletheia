/*
 * function: func_021DEADC
 * address: 0x021DEADC
 * packet: pkt_ov183_021DEADC
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero bytes are alignment padding before the next labelled function.
 * symbols:
 *   func_021FF88C 0x021FF88C thumb ov186
 *   func_021F9C6C 0x021F9C6C thumb ov186
 *   func_021FD71C 0x021FD71C thumb ov186
 *   func_021FD72C 0x021FD72C thumb ov186
 *   func_021FD854 0x021FD854 thumb ov186
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_021FC830 0x021FC830 thumb ov186
 *   func_021FD1BC 0x021FD1BC thumb ov186
 */
#include "../include/Obj02521.h"
#include "../include/Obj24585.h"
#include "../include/Obj24586.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct PrintSys;
extern int func_021FF88C(char *p);
extern void func_021F9C6C(void *);
extern void func_021FD71C(u8 *p);
extern int func_021FD72C(int *p);
extern void func_021FD854(char *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern int func_021FC830(u8 *p);
extern void func_021FD1BC(void *);
int func_021DEADC(int a, int b, int c, char *p)
{
    int i;
    if (func_021FF88C(((struct Obj24585 *)(*(char * *)&((struct Obj02521 *)p)->f108))->f18) == 2) {
        func_021F9C6C(((struct Obj24586 *)(*(char * *)&((struct Obj02521 *)p)->f108))->f14);
        return 1;
    }
    func_021FD71C(((struct Obj02521 *)p)->f10);
    if (func_021FD72C(((struct Obj02521 *)p)->f10) != 0) return 1;
    for (i = 0; i < 2; i++) func_021FD854(*(void **)(p + 0x1C + i * 4));
    PRINTSYS_QUE_Main(((struct Obj02521 *)p)->f14);
    if (((struct Obj02521 *)p)->f8 != 0) func_021FC830(((struct Obj02521 *)p)->f8);
    if (((struct Obj02521 *)p)->fC != 0) func_021FC830(((struct Obj02521 *)p)->fC);
    if (((struct Obj02521 *)p)->f24 != 0) func_021FD1BC(((struct Obj02521 *)p)->f24);
    return 0;
}
