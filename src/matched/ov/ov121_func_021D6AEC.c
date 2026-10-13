/*
 * function: func_021D6AEC
 * address: 0x021D6AEC
 * packet: pkt_ov121_021D6AEC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero padding bytes at 0x021D6C26.
 * lever: spell the object slot as p+i*4+16; data precedes allocation in local declarations.
 * interfaces: ABF0 and B294 leave r0 live and this caller consumes it despite legacy void definitions.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   func_02049F78 0x02049F78 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02082BCC 0x02082BCC arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02005728 0x02005728 thumb
 */
#include "../include/Obj01403.h"
#include "../include/Obj22851.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef struct { s16 x,y,z; u8 a,b; } Record;
struct Obj;
extern void *func_020490F4(u32 id, u32 heap);
extern int CLACT_RegisterPalette(void *,u32,u32,u32,u16);
extern int CLACT_RegisterCellAnim(void *,u32,u32,u32);
extern int CLACT_RegisterCharacter(void *,u32,u32,u32,u16);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(const void *,void *,int);
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_02082BCC(void *,int,int);
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern u32 func_02005728(u32 range);
void func_021D6AEC(char *p, void *owner, u16 heap)
{
    void *res;
    Record point;
    int bound;
    char *data;
    void *allocation;
    void *arc;
    int i;
    arc=func_020490F4(34,heap);
    *(int *)&((struct Obj01403 *)p)->f0=CLACT_RegisterPalette(arc,8,2,0,heap);
    *(int *)&((struct Obj01403 *)p)->f8=CLACT_RegisterCellAnim(arc,34,37,heap);
    *(int *)&((struct Obj01403 *)p)->f4=CLACT_RegisterCharacter(arc,16,0,2,heap);
    allocation=func_02049F78(arc,8,(u32)(&res),heap);
    data=*(char * *)&((struct Obj22851 *)res)->fC;
    func_02082D44(data,p+0xda,32);
    data+=32;
    func_02082D44(data,p+0xba,32);
    func_020307B0(allocation);
    ARC_TOOL_DeleteHandle(arc);
    func_02082BCC(&point,0,8);
    ((struct Obj01403 *)p)->fC=CLACT_CreateActor((void *)owner,((struct Obj01403 *)p)->f4,((struct Obj01403 *)p)->f0,((struct Obj01403 *)p)->f8,&point,0,heap);
    func_0204B3DC(((struct Obj01403 *)p)->fC,0);
    bound=256;
    bound+=16;
    for (i=0;i<32;i++) {
        point.x=func_02005728(256);
        point.y=func_02005728(256)-bound;
        point.b=3;
        point.z=func_02005728(6)+3;
        *(void **)(p+i*4+16)=CLACT_CreateActor((void *)owner,((struct Obj01403 *)p)->f4,((struct Obj01403 *)p)->f0,((struct Obj01403 *)p)->f8,&point,0,heap);
        func_0204B3DC(*(void **)(p+i*4+16),0);
    }
    point.x=128;
    point.y=177;
    point.b=0;
    point.a=1;
    point.z=9;
    ((struct Obj01403 *)p)->f94=CLACT_CreateActor((void *)owner,((struct Obj01403 *)p)->f4,((struct Obj01403 *)p)->f0,((struct Obj01403 *)p)->f8,&point,0,heap);
    func_0204B3DC(((struct Obj01403 *)p)->f94,0);
}
