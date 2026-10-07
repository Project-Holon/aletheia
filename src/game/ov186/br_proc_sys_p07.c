/*
 * file:     br_proc_sys_p07.c
 * unit:     yes
 * function: func_021F9C84, func_021F9CA4
 * address:  0x021F9C84
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 */
#include "../../matched/include/Obj08325.h"
#include "../../matched/include/Obj24813.h"

struct Pair;
struct PrintSys;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_02082BCC(void *,int,unsigned);
void func_021F9C84(char *p,int a,int b);
void func_021F9CA4(void *p);

void func_021F9C84(char *p,int a,int b) { int zero=0;func_02082BCC(p,0,16);((struct Obj08325 *)p)->f0=1;((struct Obj08325 *)p)->f4=zero;((struct Obj08325 *)p)->fC=a;((struct Obj08325 *)p)->f8=b; }


void func_021F9CA4(void *p)
{
    func_02082BCC(p, 0, 0x10);
    ((struct Obj24813 *)p)->fC = -1;
}
