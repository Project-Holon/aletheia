/*
 * function: func_021F90C0
 * address: 0x021F90C0
 * packet: pkt_ov186_021F90C0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Lever: name the zero after allocation; initialise the second flag before FC3BC, not at entry (first spelling DIFF 46 bytes).
 * abi: caller consumes 0203159C's live r0 at 021F90E0, overriding its void matched signature.
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021FC3BC 0x021FC3BC thumb ov186
 *   GAME_DATA_GetMiscSave 0x02012F08 thumb
 *   func_0200C3E0 0x0200C3E0 thumb
 *   func_021FB884 0x021FB884 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021F99CC 0x021F99CC thumb ov186
 *   func_021FE6C0 0x021FE6C0 thumb ov186
 *   func_021FE7B4 0x021FE7B4 thumb ov186
 *   func_021FC224 0x021FC224 thumb ov186
 *   func_021FE7F4 0x021FE7F4 thumb ov186
 *   func_021FE7F8 0x021FE7F8 thumb ov186
 *   func_021FC4DC 0x021FC4DC thumb ov186
 *   func_021FED50 0x021FED50 thumb ov186
 *   func_021F98F8 0x021F98F8 thumb ov186
 *   func_021FF408 0x021FF408 thumb ov186
 *   func_02034AC4 0x02034AC4 arm
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   func_02012A30 0x02012A30 thumb
 *   func_02028A58 0x02028A58 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   func_021FEE9C 0x021FEE9C thumb ov186
 *   func_021FEE4C 0x021FEE4C thumb ov186
 *   func_021FE840 0x021FE840 thumb ov186
 *   d_02200254 0x02200254 data a4
 *   ov125_id 0x0000007D data
 */
#include "../include/Obj00387.h"
#include "../include/Obj24764.h"
#include "../include/Obj24765.h"
#include "../include/Obj24766.h"
#include "../include/Obj24768.h"
#include "../include/Obj24769.h"
#include "../include/Obj24770.h"
#include "../include/Obj24772.h"
#include "../include/Obj24773.h"
#include "../include/Obj24774.h"
#include "../include/Obj24775.h"
#include "../include/Obj24776.h"
#include "../include/Obj24777.h"
#include "../include/Obj24779.h"
#include "../include/Obj24780.h"
#include "../include/Obj24781.h"
#include "../include/Obj24782.h"
#include "../include/Obj24783.h"
#include "../include/Obj24785.h"
#include "../include/Obj24786.h"
#include "../include/Obj24787.h"
#include "../include/Obj24788.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern char ov125_id[];
extern const char d_02200254[];
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32),func_02082BCC(void *,int,unsigned);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
struct SoundSys;
extern void *func_021FC3BC(unsigned mode, int setting, unsigned heap);
extern void *GAME_DATA_GetMiscSave(int *);
extern void *func_021FB884(unsigned,unsigned,unsigned);
struct BigObj;
struct Blk34;
extern u8 func_0200C3E0(struct Blk34 *p);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern void *func_021F99CC(unsigned,void *,unsigned,unsigned,unsigned *,u16);
extern int *func_021FE6C0(unsigned);
extern void func_021FE7B4(char *),func_021FE7F4(int *,int),func_021FE7F8(char *,int);
extern int func_021FC224(char *);
extern u32 func_021FC4DC(u8 *p);
extern char *func_021FED50(int,int,char *,unsigned);
extern void func_021F98F8(char *p, int skip, void *sys, int heap);
extern char *func_021FF408(void *owner, void *arg, u32 heap);
extern int func_02034AC4(int),GFL_NET_GetRunState(void);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);
extern u32 func_02012A30(const struct BigObj *p);
extern void func_02028A58(struct SoundSys *sys, u8 level, u16 frames);
extern void GFL_USE_CancelChangeAndPlayBgm(u32,u16);
extern void func_021FEE9C(char *p);
extern void func_021FEE4C(char *p);
extern void func_021FE840(int,int,int);
int func_021F90C0(void *obj,int unused,char *q)
{
    char *p;
    int flag=1;
    unsigned mode;
    int enabled;
    int zero;
    GFL_HEAP_CreateChildHeap(1,0x5a,0x90000);
    p=PROCSYS_AllocProcWork(obj,0x1c,0x5a);
    zero=0;
    func_02082BCC(p,0,0x1c);
    *(char * *)&((struct Obj00387 *)p)->f18=q;
    ((struct Obj24765 *)(*(char * *)&((struct Obj24764 *)q)->fC))->fC=zero;
    if(**(int * *)&((struct Obj24766 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC!=2) flag=zero;
    enabled=1;
    ((struct Obj00387 *)p)->f0=func_021FC3BC(flag,1,0x5a);
    mode=func_0200C3E0(GAME_DATA_GetMiscSave(*(int * *)&((struct Obj24769 *)(*(char * *)&((struct Obj24768 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC))->f4));
    if(**(int * *)&((struct Obj24770 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC) enabled=0;
    ((struct Obj00387 *)p)->f4=func_021FB884(mode,enabled,0x5a);
    func_021FB964((void *)(*(int *)&((struct Obj00387 *)p)->f4),0,0x5a);
    func_021FB964((void *)(*(int *)&((struct Obj00387 *)p)->f4),1,0x5a);
    ((struct Obj00387 *)p)->f8=func_021F99CC(0,(void *)d_02200254,0xd,(unsigned)p,(unsigned *)(((struct Obj24772 *)(*(char * *)&((struct Obj00387 *)p)->f18))->f8+0x1728),0x5a);
    *(int * *)&((struct Obj00387 *)p)->fC=func_021FE6C0(0x5a);
    func_021FE7B4(*(char * *)&((struct Obj00387 *)p)->fC);
    func_021FE7F4(*(int * *)&((struct Obj00387 *)p)->fC,func_021FC224(*(char * *)&((struct Obj00387 *)p)->f4));
    if(!((struct Obj24773 *)(*(char * *)&((struct Obj00387 *)p)->f18))->f4) func_021FE7F8(*(char * *)&((struct Obj00387 *)p)->fC,3);
    *(char * *)&((struct Obj00387 *)p)->f10=func_021FED50(func_021FC4DC((u8 *)(*(int *)&((struct Obj00387 *)p)->f0)),*(int *)&((struct Obj00387 *)p)->fC,*(char * *)&((struct Obj00387 *)p)->f4,0x5a);
    func_021F98F8((char *)(((struct Obj24774 *)(*(char * *)&((struct Obj00387 *)p)->f18))->f8+0x1748),1,(void *)(((struct Obj24776 *)(*(char * *)&((struct Obj24775 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC))->f4),0x5a);
    if(**(int * *)&((struct Obj24777 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC) {
        ((struct Obj00387 *)p)->f14=func_021FF408(((struct Obj24780 *)(*(char * *)&((struct Obj24779 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC))->f4,(void *)(((struct Obj24782 *)(*(char * *)&((struct Obj24781 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC))->f8),0x5a);
    } else func_02034AC4((int)ov125_id);
    if(GFL_NET_GetRunState()) GFL_NET_RestartWithDefaultTimeout(0,0x5a);
    if(!**(int * *)&((struct Obj24783 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC) {
        if(((struct Obj24785 *)(*(char * *)&((struct Obj00387 *)p)->f18))->f4!=1) func_02028A58((void *)func_02012A30(((struct Obj24787 *)(*(char * *)&((struct Obj24786 *)(*(char * *)&((struct Obj00387 *)p)->f18))->fC))->f4),0x40,0);
    } else GFL_USE_CancelChangeAndPlayBgm(0x484,0xffff);
    if(((struct Obj24788 *)(*(char * *)&((struct Obj00387 *)p)->f18))->f4==1) {
        func_021FEE9C((char *)(*(int *)&((struct Obj00387 *)p)->f10));func_021FEE4C((char *)(*(int *)&((struct Obj00387 *)p)->f10));
        func_021FE840(*(int *)&((struct Obj00387 *)p)->fC,3,0);
    }
    return 1;
}
