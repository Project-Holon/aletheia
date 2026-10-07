/*
 * file:     br_util_p03.c
 * unit:     yes
 * function: func_021FCC80, func_021FCD0C
 * address:  0x021FCC80
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
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_020437AC 0x020437AC arm
 *   func_020456F8 0x020456F8 arm
 *   func_020452E8 0x020452E8 arm
 *   func_021FC0C8 0x021FC0C8 thumb ov186
 *   func_020307B0 0x020307B0 arm
 *   func_021FCDA0 0x021FCDA0 thumb ov186
 *   func_021FCEDC 0x021FCEDC thumb ov186
 *   func_021FCE60 0x021FCE60 thumb ov186
 *   func_02006254 0x02006254 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B3DC 0x0204B3DC arm
 */
#include "../../matched/include/Obj01571.h"
#include "../../matched/include/Obj00048.h"

struct Descriptor;
struct Obj;
struct Obj020437AC;
typedef unsigned int   u32;

extern void func_021FD860(int,int,void *);
extern void func_0204B3B4(struct Obj *p);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_020456F8(struct Descriptor *d);
extern unsigned int func_020452E8(struct Descriptor *d);
extern void func_021FC0C8(char *p, unsigned i);
extern u32 func_020307B0(void *p);
extern int func_021FCDA0(char *);
extern int func_021FCEDC(char *);
extern int func_02006254(u32 a);
extern void func_021FCE60(char *,int);
extern void func_020061E4(u32 a);
extern void func_0204B3DC(struct Obj *,unsigned int);
void func_021FCC80(char *p);
void func_021FCD0C(char *p);

void func_021FCC80(char *p)
{
    int i;
    if(((struct Obj01571 *)p)->f1C) func_021FD860(((struct Obj01571 *)p)->f1C,0,0);
    for(i=0;i<4;i++) func_0204B3B4((struct Obj *)(*(int *)(p+0x28+i*4)));
    for(i=0;(unsigned)i<((struct Obj01571 *)p)->f4;i++) {
        if(*(int *)(p+0x8C+i*4) && *(int *)(((struct Obj01571 *)p)->f0+i*8)) func_020437AC((struct Obj020437AC *)(*(int *)(p+0x8C+i*4)));
    }
    func_020456F8((struct Descriptor *)(((struct Obj01571 *)p)->f38));func_020452E8((struct Descriptor *)(((struct Obj01571 *)p)->f38));
    if(((struct Obj01571 *)p)->fD<4) func_021FC0C8((char *)(((struct Obj01571 *)p)->f14),7);
    else func_021FC0C8((char *)(((struct Obj01571 *)p)->f14),8);
    if(((struct Obj01571 *)p)->f24) {
        *(unsigned short *)(((struct Obj01571 *)p)->f24)=((struct Obj01571 *)p)->f42;
        *(unsigned short *)(((struct Obj01571 *)p)->f24+2)=((struct Obj01571 *)p)->f40;
    }
    func_020307B0(p);
}

void func_021FCD0C(char *p)
{
    if(func_021FCDA0(p)) {
        ((struct Obj00048 *)p)->f4C=func_021FCEDC(p);
        if(((struct Obj00048 *)p)->f4C) {
            if(((int (*)(char *,int))*(int *)(p+0x50))(p,((struct Obj00048 *)p)->f4C)) {
                if(func_02006254(0x6FE)==0) func_020061E4(0x6FE);
                func_021FCE60(p,((struct Obj00048 *)p)->f42);
            }
            if(((struct Obj00048 *)p)->f4D) {
                if(((struct Obj00048 *)p)->f42==0) func_0204B3DC((struct Obj *)*(int *)&((struct Obj00048 *)p)->f28,0);
                else func_0204B3DC((struct Obj *)*(int *)&((struct Obj00048 *)p)->f28,1);
                if(((struct Obj00048 *)p)->f4==((struct Obj00048 *)p)->f42+((struct Obj00048 *)p)->f44) func_0204B3DC((struct Obj *)*(int *)&((struct Obj00048 *)p)->f2C,0);
                else func_0204B3DC((struct Obj *)*(int *)&((struct Obj00048 *)p)->f2C,1);
            }
        }
    }
    ((void (*)(char *))*(int *)(p+0x58))(p);
}
