/*
 * function: func_021E111C
 * address: 0x021E111C
 * packet: pkt_ov183_021E111C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: form slot=&out[index] before the constructor call and store/reload through slot. The direct out[index] spelling sank the output base and left 15 bytes different.
 * symbols:
 *   func_021FC214 0x021FC214 thumb ov186
 *   d_021E3850 0x021E3850 data a4
 *   func_02045EC0 0x02045EC0 arm
 *   func_02043678 0x02043678 arm
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_020255A0 0x020255A0 thumb
 *   func_020257D0 0x020257D0 thumb
 *   func_0202597C 0x0202597C thumb
 *   func_020437AC 0x020437AC arm
 *   func_02045808 0x02045808 arm
 */
#include "../include/Obj03882.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {void *handle; short x,y; unsigned data,zero; u8 a,b; u16 c; unsigned d;} Descriptor;
struct Grid;
struct Sys;
typedef struct {char f000[0x300]; struct Sys *f300; struct Grid *f304[1];} Object;
typedef enum {INDEX_0,INDEX_1} Index;
extern const int d_021E3850[];
extern int func_021FC214(char *);
typedef signed short   s16;
typedef unsigned int   u32;
struct Bmp;
struct MsgBank;
struct Obj;
struct Obj020437AC;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
struct Param;
extern struct Grid *func_020255A0(struct Sys *sys, const struct Param *param);
extern void func_020257D0(struct Obj *o);
extern void func_0202597C(u8 *g, u32 a);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_02045808(struct U16Vec *vec);
void func_021E111C(const Object *object,Index index,int x,int y)
{
    char *p=(char *)object;
    int source,handle,obj;
    u8 xx,yy;
    struct Grid **slots;
    Descriptor desc;
    source=func_021FC214(*(char * *)&((struct Obj03882 *)p)->f344);
    source=(int)func_02045EC0((struct MsgBank *)source,d_021E3850[index]);
    handle=(int)func_02043678(10,2,32,((struct Obj03882 *)p)->f34C);
    func_0201C7A4((void *)handle,1,0,(void *)source,(void *)(((struct Obj03882 *)p)->f310));
    xx=((u8 *)(p+0x29a))[(index+22)*4];
    yy=((u8 *)(p+0x298))[(index+22)*4];
    desc.handle=(void *)handle;
    desc.x=xx+x;
    desc.y=yy+y;
    desc.data=((struct Obj03882 *)p)->f264;
    desc.zero=0;
    desc.a=0;
    desc.b=0;
    desc.c=1;
    desc.d=1;
    {
        struct Grid **out=(struct Grid **)(char *)object->f304;
        struct Grid **slot;
        struct Grid *grid;
        slot=&out[index];
        grid=func_020255A0(object->f300,(const struct Param *)(&desc));
        *slot=grid;
        func_020257D0((struct Obj *)((int)grid));
        func_0202597C((u8 *)((int)*slot),1);
    }
    func_020437AC((struct Obj020437AC *)handle);
    func_02045808((struct U16Vec *)source);
}
