/*
 * function: func_021BA328
 * address: 0x021BA328
 * packet: pkt_ov218_021BA328
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA960 0x021BA960 thumb ov218
 *   func_021BA4D4 0x021BA4D4 thumb ov218
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B688 0x0204B688 arm
 *   d_021BABC8 0x021BABC8 data ov218 a4
 *   d_021BAB68 0x021BAB68 data a4
 *   d_021BAB98 0x021BAB98 data ov218 a4
 *   d_021BABB0 0x021BABB0 data ov218 a4
 *   d_021BAB80 0x021BAB80 data ov218 a4
 */
#include "../include/Obj00243.h"
#include "../include/G_Config.h"
typedef unsigned int u32;
typedef struct Config Config;
extern struct Config d_021BAB68;
extern const Config d_021BABC8, d_021BAB98, d_021BABB0, d_021BAB80;
struct Obj;
extern u32 func_021BA960(char *p);
extern struct Obj *func_021BA4D4(u32 owner, char *p);
struct Actor;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B688(struct Actor *actor, u32 value);
void func_021BA328(char *p)
{
    Config a,b,c,d,e;
    void *manager,*item;
    int i,j;
    manager=(void *)func_021BA960(((struct Obj00243 *)p)->f4);
    for(j=0;j<36;j++)*(u32 *)(p+0x240+j*4)=0;
    a=d_021BABC8;
    a.c=((struct Obj00243 *)p)->f2D0;a.d=((struct Obj00243 *)p)->f2D4;a.e=((struct Obj00243 *)p)->f2D8;
    ((struct Obj00243 *)p)->f240=func_021BA4D4((u32)manager,(char *)(&a));
    b=d_021BAB68;
    b.c=((struct Obj00243 *)p)->f2D0;b.d=((struct Obj00243 *)p)->f2D4;b.e=((struct Obj00243 *)p)->f2D8;
    for(i=0;i<20;i++)*(void **)(p+0x244+i*4)=func_021BA4D4((u32)manager,(char *)(&b));
    c=d_021BAB98;
    c.c=((struct Obj00243 *)p)->f2D0;c.d=((struct Obj00243 *)p)->f2D4;c.e=((struct Obj00243 *)p)->f2D8;
    for(j=0;j<7;j++) {
        item=func_021BA4D4((u32)manager,(char *)(&c));
        func_0204B3DC(item,0);
        *(void **)(p+0x294+j*4)=item;
    }
    d=d_021BABB0;
    d.c=((struct Obj00243 *)p)->f2D0;d.d=((struct Obj00243 *)p)->f2D4;d.e=((struct Obj00243 *)p)->f2D8;
    for(i=0;i<7;i++) {
        item=func_021BA4D4((u32)manager,(char *)(&d));
        func_0204B688(item,1);
        func_0204B3DC(item,0);
        *(void **)(p+0x2b0+i*4)=item;
    }
    e=d_021BAB80;
    e.c=((struct Obj00243 *)p)->f2D0;e.d=((struct Obj00243 *)p)->f2D4;e.e=((struct Obj00243 *)p)->f2D8;
    ((struct Obj00243 *)p)->f2CC=func_021BA4D4((u32)manager,(char *)(&e));
}
