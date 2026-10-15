/*
 * function: MANUAL_CATEGORY_CreateList
 * address: 0x021BB6E0
 * packet: pkt_ov225_021BB6E0
 * status: EXACT
 * region: ov225
 * isa: thumb
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * lever: u16 groups/items counts preserve target word spills/reloads; full callee bodies return ldrh values. Widened count locals compiled272B/191 concrete bytes; narrow counts compiled EXACT276B.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020056A0 0x020056A0 thumb
 *   MANUAL_COMMON_GetGroupCount 0x021B9C50 thumb ov225
 *   MANUAL_COMMON_GetGroupValue1 0x021B9C34 thumb ov225
 *   MANUAL_COMMON_GetGroupValue2 0x021B9C40 thumb ov225
 *   MANUAL_COMMON_GetEntryValue1 0x021B9BD4 thumb ov225
 *   MANUAL_COMMON_CheckUnlocked 0x021B9C58 thumb ov225
 *   MANUAL_COMMON_GetGroupValue0 0x021B9C28 thumb ov225
 *   MANUAL_COMMON_CreateListWork 0x021BA65C thumb ov225
 *   MANUAL_CATEGORY_TaskNoop 0x021BB850 thumb ov225
 *   gManualCategoryListAllocFile 0x021BC048 data a4
 */
#include "../include/Obj00637.h"
#include "../include/Obj14810.h"
#include "../include/Obj26278.h"
#include "../include/Obj26279.h"
#include "../include/Obj26280.h"
#include "../include/Obj26281.h"
#include "../include/Obj26282.h"
#include "../include/Obj26283.h"
#include "../include/Obj26284.h"
#include "../include/Obj26286.h"
#include "../include/Obj26288.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void *func_020056A0(unsigned,unsigned,unsigned);
extern u16 MANUAL_COMMON_GetGroupCount(const char *p);
extern u16 MANUAL_COMMON_GetGroupValue1(char *,int);
extern u16 MANUAL_COMMON_GetGroupValue2(char *,int,int);
extern u16 MANUAL_COMMON_GetEntryValue1(char *,int);
extern int MANUAL_COMMON_CheckUnlocked(void *,int,void *);
extern u16 MANUAL_COMMON_GetGroupValue0(char *,int);
struct Data;
extern void *MANUAL_COMMON_CreateListWork(char *owner, struct Data *data);
extern void MANUAL_CATEGORY_TaskNoop(void);
extern const char gManualCategoryListAllocFile[];
char *MANUAL_CATEGORY_CreateList(char *p,char *data)
{
    char *q;
    u16 groups,items;
    u16 i,j,valid;
    q=func_02030734(((struct Obj14810 *)data)->f4,0x24,1,gManualCategoryListAllocFile,0x5c);
    *(char * *)&((struct Obj00637 *)q)->f0=p;
    ((struct Obj26278 *)p)->f4=0;
    ((struct Obj26279 *)(*(char * *)&((struct Obj00637 *)q)->f0))->f8=0;
    *(char * *)&((struct Obj00637 *)q)->f4=data;
    ((struct Obj00637 *)q)->f8=0;
    groups=MANUAL_COMMON_GetGroupCount(*(char * *)&((struct Obj14810 *)data)->f2C);
    ((struct Obj00637 *)q)->fC=0;
    *(char * *)&((struct Obj00637 *)q)->f10=func_02030734(((struct Obj26280 *)(*(char * *)&((struct Obj00637 *)q)->f4))->f4,groups*8,1,gManualCategoryListAllocFile,0x71);
    for(i=0;i<groups;i++) {
        valid=0;
        items=MANUAL_COMMON_GetGroupValue1(*(char * *)&((struct Obj26281 *)(*(char * *)&((struct Obj00637 *)q)->f4))->f2C,i);
        for(j=0;j<items;j++) {
            int id;
            id=MANUAL_COMMON_GetGroupValue2(*(char * *)&((struct Obj26282 *)(*(char * *)&((struct Obj00637 *)q)->f4))->f2C,i,j);
            id=MANUAL_COMMON_GetEntryValue1(*(char * *)&((struct Obj26283 *)(*(char * *)&((struct Obj00637 *)q)->f4))->f2C,id);
            if(MANUAL_COMMON_CheckUnlocked(((struct Obj26284 *)(*(char * *)&((struct Obj00637 *)q)->f4))->f2C,id,*(void **)*(char * *)&((struct Obj00637 *)q)->f4)) valid++;
        }
        if(valid) {
            *(u16 *)(*(char * *)&((struct Obj00637 *)q)->f10+((struct Obj00637 *)q)->fC*8)=i;
            *(u16 *)(*(char * *)&((struct Obj00637 *)q)->f10+((struct Obj00637 *)q)->fC*8+2)=MANUAL_COMMON_GetGroupValue0(*(char * *)&((struct Obj26286 *)(*(char * *)&((struct Obj00637 *)q)->f4))->f2C,i);
            *(u32 *)(*(char * *)&((struct Obj00637 *)q)->f10+((struct Obj00637 *)q)->fC*8+4)=0;
            ((struct Obj00637 *)q)->fC+=1;
        }
    }
    ((struct Obj00637 *)q)->f14=*(u16 *)*(char * *)&((struct Obj00637 *)q)->f0;
    ((struct Obj00637 *)q)->f16=((struct Obj26288 *)(*(char * *)&((struct Obj00637 *)q)->f0))->f2;
    *(char * *)&((struct Obj00637 *)q)->f1C=MANUAL_COMMON_CreateListWork(q+8,(struct Data *)data);
    ((struct Obj00637 *)q)->f20=func_020056A0((unsigned)MANUAL_CATEGORY_TaskNoop,(unsigned)q,1);
    return q;
}
