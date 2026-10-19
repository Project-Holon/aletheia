/*
 * function: MYSTERY_ALBUM_Create
 * address: 0x021DAC18
 * packet: pkt_ov121_021DAC18
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   MIi_CpuClear32 0x02082A7C arm
 *   func_0203084C 0x0203084C arm
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   MYSTERY_ALBUM_SetupEntry 0x021DBDF4 thumb ov121
 *   MYSTERY_UTIL_CreateTask 0x021DA854 thumb ov121
 *   MYSTERY_ALBUM_Setup 0x021DB018 thumb ov121
 *   MYSTERY_ALBUM_SetCursor 0x021DB478 thumb ov121
 *   MYSTERY_UTIL_CreateWindowList 0x021DA1BC thumb ov121
 *   MYSTERY_ALBUM_CreateSlotWork 0x021DCFC8 thumb ov121
 *   MYSTERY_ALBUM_CountValidCards 0x021DBDBC thumb ov121
 *   MYSTERY_ALBUM_IsEntryValid 0x021DBF04 thumb ov121
 *   MYSTERY_ALBUM_GetEntryCard 0x021DC02C thumb ov121
 *   MYSTERY_ALBUM_CreateAlbumView 0x021DD24C thumb ov121
 *   MYSTERY_ALBUM_RequestSetup 0x021DE0AC thumb ov121
 *   MYSTERY_ALBUM_SelectHandler 0x021DC08C thumb ov121
 *   MYSTERY_ALBUM_SingleHandler 0x021DCEC4 thumb ov121
 *   d_021DFBB0 0x021DFBB0 data a4
 *   d_021DF8FC 0x021DF8FC data a4
 *   d_021DF890 0x021DF890 data a4
 *   MYSTERY_DATA_GetCardSlotNum  0x0200A348  thumb  arm9
 *   MYSTERY_DATA_GetCard  0x0200A000  thumb  arm9
 *   MYSTERY_DATA_IsCardExist  0x0200A0E4  thumb  arm9
 */
#include "../include/Obj00910.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 w[9];} Input;
typedef struct {u32 w[51];} Record;
typedef struct {u32 w[12];} Desc;
extern char d_021DFBB0[],d_021DF8FC[],d_021DF890[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *,int,int);
extern void MIi_CpuClear32(int,void *,int);
extern void *func_0203084C(u32 heapId);
extern void BG_SYS_ChangeScrollImmediate(u32,u32,u32);
struct Obj;
extern u32 MYSTERY_DATA_GetCardSlotNum(struct Obj *);
extern u32 MYSTERY_DATA_IsCardExist(u8 *p, u32 a);
extern int MYSTERY_DATA_GetCard(char *p, int idx, void *buf);
extern void MYSTERY_ALBUM_SetupEntry(char *,const Record *,char *,u16);
extern void *MYSTERY_UTIL_CreateTask(void *,void *,u16);
extern void MYSTERY_ALBUM_Setup(u8 *p, u16 heap);
extern void MYSTERY_ALBUM_SetCursor(char *,int,int,int,u16);
extern void *MYSTERY_UTIL_CreateWindowList(void *,const char *,u32,u16,u16,u32,u32,int,u16);
extern void *MYSTERY_ALBUM_CreateSlotWork(const Desc *,u16);
extern u32 MYSTERY_ALBUM_CountValidCards(u32 p);
extern int MYSTERY_ALBUM_IsEntryValid(int *p);
extern char *MYSTERY_ALBUM_GetEntryCard(void *);
extern void *MYSTERY_ALBUM_CreateAlbumView(void *,void *,void *,u16);
extern void MYSTERY_ALBUM_RequestSetup(u8 *p, u32 b);
extern void MYSTERY_ALBUM_SelectHandler(void *task, u32 *state, char *p);
extern void MYSTERY_ALBUM_SingleHandler(void *arg, int *state, char *p);
char *MYSTERY_ALBUM_Create(const Input *src,u16 heap)
{
    char *out;
    int count=0;
    u32 i;
    int j;
    Desc d;
    Record record;
    const char *table;
    int n;
    void *callback;
    out=func_02030734(heap,0xc70,0,d_021DFBB0,0x19f);
    MI_CpuFill8(out,0,0xc70);
    ((struct Obj00910 *)out)->fAD0=1;
    *(Input *)out=*src;
    ((struct Obj00910 *)out)->f24=heap;
    MIi_CpuClear32(-1,out+0xb48,32);
    MIi_CpuClear32(-1,out+0xb88,32);
    MIi_CpuClear32(-1,out+0xb68,32);
    for(i=0;i<MYSTERY_DATA_GetCardSlotNum(((struct Obj00910 *)out)->fC);i++) {
        if(MYSTERY_DATA_IsCardExist(((struct Obj00910 *)out)->fC,i)) {
            count++;
            MYSTERY_DATA_GetCard(((struct Obj00910 *)out)->fC,i,&record);
            MYSTERY_ALBUM_SetupEntry(out+40+i*0xdc,&record,out,heap);
        }
    }
    callback=(void *)MYSTERY_ALBUM_SelectHandler;
    if(((struct Obj00910 *)out)->f0) callback=(void *)MYSTERY_ALBUM_SingleHandler;
    ((struct Obj00910 *)out)->fAC4=MYSTERY_UTIL_CreateTask(out,callback,heap);
    MYSTERY_ALBUM_Setup((u8 *)out,heap);
    MYSTERY_ALBUM_SetCursor(out,1,0,((struct Obj00910 *)out)->fAC8,heap);
    if(count) {table=d_021DF8FC;n=3;}
    else {table=d_021DF890;n=2;}
    ((struct Obj00910 *)out)->fAB8=MYSTERY_UTIL_CreateWindowList(0,table,n,1,3,((struct Obj00910 *)out)->f14,((struct Obj00910 *)out)->f1C,*(int *)&((struct Obj00910 *)out)->f10,heap);
    MI_CpuFill8(&d,0,48);
    d.w[0]=6;d.w[1]=4;d.w[2]=14;d.w[3]=15;d.w[4]=11;d.w[5]=14;
    d.w[6]=((struct Obj00910 *)out)->f8;d.w[7]=*(u32 *)&((struct Obj00910 *)out)->fC;d.w[8]=((struct Obj00910 *)out)->f1C;
    d.w[9]=((struct Obj00910 *)out)->f10;d.w[10]=((struct Obj00910 *)out)->f14;d.w[11]=((struct Obj00910 *)out)->f18;
    ((struct Obj00910 *)out)->fAB0=MYSTERY_ALBUM_CreateSlotWork(&d,heap);
    if(MYSTERY_ALBUM_CountValidCards((u32)out)) {
        for(j=0;j<12;j++) {
            if(MYSTERY_ALBUM_IsEntryValid((int *)(out+40+j*0xdc)))
                *(void **)(out+0xa7c+j*4)=MYSTERY_ALBUM_CreateAlbumView(MYSTERY_ALBUM_GetEntryCard(out+40+j*0xdc),((struct Obj00910 *)out)->fAB0,(void *)src->w[8],heap);
        }
        MYSTERY_ALBUM_RequestSetup(((struct Obj00910 *)out)->fA7C,0);
        func_0203084C(29);
    }
    BG_SYS_ChangeScrollImmediate(3,3,0);
    BG_SYS_ChangeScrollImmediate(7,3,0);
    return out;
}


