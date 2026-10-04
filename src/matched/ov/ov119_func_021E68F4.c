/*
 * function: func_021E68F4
 * address: 0x021E68F4
 * packet: pkt_ov119_021E68F4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   d_021E7DEC 0x021E7DEC data a2
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { short x,y,z; u8 a,b; } Create;
typedef struct { short x,y; } Pt;
typedef struct { Pt pos[6]; } Table;
extern const Table d_021E7DEC;
struct Obj;
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
extern void func_0204B92C(struct Obj *p,unsigned int v);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B404(int,const Pt *,unsigned int);
void func_021E68F4(int p, int i) {
    Table t=d_021E7DEC;
    Create c;
    if(i==-1) {
        if(((struct Obj00001 *)p)->fFD4) func_0204B3DC((struct Obj *)((struct Obj00001 *)p)->fFD4,0);
    } else {
        if(!((struct Obj00001 *)p)->fFD4) {
            c.x=64;c.y=48;c.z=23;c.a=0;c.b=1;
            ((struct Obj00001 *)p)->fFD4=(int)func_0204B294((void *)((struct Obj00001 *)p)->f9C4,((struct Obj00001 *)p)->f894,((struct Obj00001 *)p)->f880,((struct Obj00001 *)p)->f8B0,&c,1,((struct Obj00001 *)p)->f5F4);
        }
        func_0204B92C((struct Obj *)((struct Obj00001 *)p)->fFD4,1);
        func_0204B3DC((struct Obj *)((struct Obj00001 *)p)->fFD4,1);
        func_0204B404(((struct Obj00001 *)p)->fFD4,&t.pos[i],1);
    }
}
