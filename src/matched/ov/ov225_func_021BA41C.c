/*
 * function: func_021BA41C
 * address: 0x021BA41C
 * packet: pkt_ov225_021BA41C
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arity: B294 retains r0 read after call, although own forwarder declares void.
 * symbols:
 *   func_020275E4 0x020275E4 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02027614 0x02027614 thumb
 *   func_0204AC18 0x0204AC18 arm
 *   func_02027618 0x02027618 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_021B9A08 0x021B9A08 thumb ov225
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   d_021BBF14 0x021BBF14 data a4
 */
#include "../include/Obj02562.h"
#include "../include/Obj10983.h"
#include "../include/Obj14803.h"
#include "../include/Obj26168.h"
#include "../include/Obj26169.h"
#include "../include/Obj26170.h"
#include "../include/Obj26171.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern const u8 d_021BBF14[];
extern u32 func_020275E4(void);
extern void *func_020490F4(unsigned int id, u16 heap);
extern u32 func_02027614(void);
typedef signed int     s32;
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern u32 func_02027618(void);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern u32 func_021B9A08(const u8 *p);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *,u32);
extern void func_0204B92C(struct Obj *,u32);
void func_021BA41C(char *p)
{
    u8 i;
    void *loader;
    u32 first;
    loader=func_020490F4(func_020275E4(),((struct Obj26168 *)(*(char * *)&((struct Obj02562 *)p)->f0))->f4);
    *(int *)&((struct Obj02562 *)p)->f30=func_0204AC18((void *)((u32)loader),func_02027614(),1,128,0,3,((struct Obj26169 *)(*(char * *)&((struct Obj02562 *)p)->f0))->f4);
    *(int *)&((struct Obj02562 *)p)->f2C=func_0204A6C8((void *)((u32)loader),func_02027618(),0,1,((struct Obj26170 *)(*(char * *)&((struct Obj02562 *)p)->f0))->f4);
    first=func_0202761C(0);
    *(int *)&((struct Obj02562 *)p)->f34=func_0204AF28((void *)((u32)loader),first,func_02027620(0),((struct Obj26171 *)(*(char * *)&((struct Obj02562 *)p)->f0))->f4);
    func_02049238(loader);
    for(i=0;i<2;i++) {
        char *parent=*(char * *)&((struct Obj02562 *)p)->f0;
        char *dest=p+i*4;
        *(struct Obj * *)&((struct Obj10983 *)dest)->f38=func_0204B294((void *)func_021B9A08(((struct Obj14803 *)parent)->f8),((struct Obj02562 *)p)->f2C,((struct Obj02562 *)p)->f30,((struct Obj02562 *)p)->f34,&d_021BBF14[i*28],1,((struct Obj14803 *)parent)->f4);
        func_0204B3DC(*(struct Obj * *)&((struct Obj10983 *)dest)->f38,0);
        func_0204B92C(*(struct Obj * *)&((struct Obj10983 *)dest)->f38,1);
    }
}
