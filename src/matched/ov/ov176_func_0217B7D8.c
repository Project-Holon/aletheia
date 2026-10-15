/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_DrawMenu
 * address: 0x0217B7D8
 * packet: pkt_ov176_0217B7D8
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: following 0217B924 and 0217B930 tail-call stubs already have separate matched shards; lead only.
 * lever: descriptor assignments in member order fix constant scheduling; coordinates are u8, height u32 with logical shift and no outgoing truncation.
 * abi: E88B0 height widened from its narrow body spelling because original stores the full computed register into the outgoing slot.
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_COMPETITION_GetFromSave 0x0200B358 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   REGULATION_GetCard 0x0200B1D4 thumb
 *   func_021E88B0 0x021E88B0 thumb ov177
 */
#include "../include/Obj01762.h"
#include "../include/Obj24405.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    u32 f00,f04,f08,option0,option1,f14,f18,count;
    u16 f20,f22,f24,f26;
    u32 f28;
    u16 f2c,f2e;
} Menu;
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *BATTLE_COMPETITION_GetFromSave(void *);
struct Rec160;
extern struct Rec160 *REGULATION_GetCard(struct Rec160 *arr, u32 index);
extern void MI_CpuFill8(void *,int,u32);
extern void *func_021E88B0(Menu *,u8,u8,u8,u32,int);
static inline void selected(Menu *rec,void *base,int index)
{
    char *mon;
    mon=(char *)REGULATION_GetCard(base,index);
    rec->option0=7;
    rec->option1=5;
    if((u8)(s8)(((struct Obj24405 *)mon)->f15B-1)<=1) rec->f14=13;
    else rec->f14=4;
    rec->f18=6;
    rec->count=4;
    rec->f28=1;
    rec->f2c=3;
}
void BATTLE_CHAMPIONSHIP_FLOW_DrawMenu(int *p, int index)
{
    Menu rec;
    void *base;
    int layout;
    u8 x,y,width;
    u32 height;
    base=BATTLE_COMPETITION_GetFromSave((void *)GAME_DATA_GetSaveControl(((struct Obj01762 *)p)->f30));
    MI_CpuFill8(&rec,0,48);
    rec.f00=((struct Obj01762 *)p)->f20;
    rec.f04=((struct Obj01762 *)p)->f1C;
    rec.f08=((struct Obj01762 *)p)->f24;
    switch(index) {
    case 0:
        rec.option0=2;rec.option1=3;rec.f14=5;rec.f18=6;rec.count=4;rec.f28=1;rec.f2c=3;layout=0;break;
    case 1: selected(&rec,base,0);layout=0;break;
    case 2: selected(&rec,base,1);layout=0;break;
    case 3:
        rec.option0=11;rec.option1=12;rec.count=2;layout=1;rec.f28=1;rec.f2c=1;break;
    }
    rec.f20=0;rec.f22=15;rec.f24=13;rec.f26=1;
    switch(layout) {
    case 0: width=28;height=(rec.count&127)*2;x=2;y=9-(height>>1);break;
    case 1: width=12;height=(rec.count&127)*2;x=19;y=17-height;break;
    }
    ((struct Obj01762 *)p)->f4=func_021E88B0(&rec,x,y,width,height,((struct Obj01762 *)p)->f34);
    ((struct Obj01762 *)p)->f8=index;
}
