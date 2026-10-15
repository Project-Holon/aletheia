/*
 * function: BR_UTIL_CreateHandles
 * address: 0x021FD760
 * packet: pkt_ov186_021FD760
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: signed FC124 index avoids caching unsigned FBE54 index+9; zero counter before res spill.
 * prototype: B294 returns live r0 and receives full-width heap without truncation.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_UTIL_CreateTask 0x021FD6D8 thumb ov186
 *   BR_UTIL_EffectIdle 0x021FD964 thumb ov186
 *   BR_RES_LoadSprite 0x021FBE54 thumb ov186
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   func_02034714 0x02034714 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   d_02200D5C 0x02200D5C data a4
 *   d_02200D68 0x02200D68 data a4
 */
typedef struct { int x,y; } Pair;
typedef struct { int x,y,z; } Triple;
typedef struct { char pad[0xC];int index;int task;char *resources;char pad18[0x1E0];int handles[12]; } Handles;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *,int,unsigned);
extern void func_02034714(const char *expr, u32 line, const char *file);
typedef unsigned char  u8;
struct Actor;
extern int *BR_UTIL_CreateTask(int payload, int callback, u32 heap);
extern int BR_RES_GetSprite(char *,int,Triple *);
extern void BR_UTIL_EffectIdle(void *unused, int *state, u8 *p);
extern void BR_RES_LoadSprite(char *,unsigned,unsigned);
extern int CLACT_CreateActor(unsigned,unsigned,unsigned,unsigned,Pair *,unsigned short,int);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned int);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern const char d_02200D5C[],d_02200D68[];
char *BR_UTIL_CreateHandles(unsigned owner,char *resources,int index,int heap)
{
    Triple triple;
    Pair pair;
    unsigned short res;
    char *p;
    int i;
    p=func_02030734(heap,0x264,0,d_02200D5C,0x7CA);
    MI_CpuFill8(p,0,0x264);
    ((Handles *)p)->resources=resources;((Handles *)p)->index=index;
    ((Handles *)p)->task=(int)BR_UTIL_CreateTask((int)p,(int)BR_UTIL_EffectIdle,heap);
    BR_RES_LoadSprite(((Handles *)p)->resources,index+9,heap);
    MI_CpuFill8(&pair,0,8);
    if(!BR_RES_GetSprite(((Handles *)p)->resources,index+9,&triple)) func_02034714(d_02200D68,0,d_02200D68);
    i=0;
    res=index;
    for(;i<12;i++) {
        ((Handles *)p)->handles[i]=CLACT_CreateActor(owner,triple.y,triple.z,triple.x,&pair,res,heap);
        CLACT_SetActorDrawEnable((struct Obj *)((Handles *)p)->handles[i],0);
        CLACT_SetActorObjMode((struct Actor *)(((Handles *)p)->handles[i]),1);
    }
    return p;
}
