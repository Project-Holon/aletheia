/*
 * function: func_021F6D68
 * address: 0x021F6D68
 * packet: pkt_ov112_021F6D68
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * ABI: B294 leaves live r0 which the original stores and passes to B3DC despite its legacy void declaration.
 * symbols:
 *   func_021F9E18 0x021F9E18 thumb ov132
 *   func_021F9DA0 0x021F9DA0 thumb ov132
 *   func_021F9DA4 0x021F9DA4 thumb ov132
 *   func_021F9E04 0x021F9E04 thumb ov132
 *   func_021F8044 0x021F8044 thumb ov112
 *   CLACT_CreateActor 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   func_0204B404 0x0204B404 arm
 *   _fflt 0x0209BDBC arm
 *   _ffltu 0x0209BE04 arm
 *   _fdiv 0x0209CE10 arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
#include "../include/Obj00771.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { short x,y; } Point;
typedef struct { Point pos; u16 x,y,z; u8 a,b; } Desc;
typedef struct { int x,y,z; } Vec;
extern int func_021F9E18(char *);
struct Obj;
extern void *func_021F9DA0(char *p);
extern void *func_021F9DA4(char *p, u32 i);
extern u16 func_021F9E04(u8 *p);
struct Vec2;
extern void func_021F8044(void *unused, u32 *p, u32 *q);
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void CLACT_DeleteActor(struct Obj *p);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
void func_021F6D68(char *p)
{
    Vec v;
    Desc d;
    void *a;
    char *ctx;
    char *model;
    u16 n;
    if(((struct Obj00771 *)p)->f88==0 && func_021F9E18(*(char * *)&((struct Obj00771 *)p)->f4)!=4) {
        ((struct Obj00771 *)p)->f88=1;
        d.x=128;
        d.y=96;
        d.z=0;
        d.a=0;
        d.b=2;
        a=CLACT_CreateActor((void *)((struct Obj00771 *)p)->fA8,((struct Obj00771 *)p)->fB0,((struct Obj00771 *)p)->fAC,((struct Obj00771 *)p)->fB4,&d.x,0,((struct Obj00771 *)p)->f0);
        ((struct Obj00771 *)p)->fA4=a;
        func_0204B3DC(a,1);
    }
    if(((struct Obj00771 *)p)->f88==1) {
        if(func_021F9E18(*(char * *)&((struct Obj00771 *)p)->f4)==4) {
            CLACT_DeleteActor(((struct Obj00771 *)p)->fA4);
            ((struct Obj00771 *)p)->f88=0;
            return;
        }
        ctx=func_021F9DA0(((struct Obj00771 *)p)->f4);
        model=func_021F9DA4(((struct Obj00771 *)p)->f4,func_021F9E18(*(char * *)&((struct Obj00771 *)p)->f4));
        n=func_021F9E04(((struct Obj00771 *)p)->f4);
        func_021F8044(ctx,(u32 *)model,(u32 *)(&v));
        d.pos.x=(short)((float)v.x/4096.0f-(float)(unsigned)n);
        d.pos.y=(short)((float)v.y/4096.0f-32.0f);
        func_0204B404(((struct Obj00771 *)p)->fA4,(const struct Vec2 *)(&d.pos),0);
    }
}
