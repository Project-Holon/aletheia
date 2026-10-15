/*
 * file:     local_tvt_chara.c
 * unit:     yes
 * function: LOCAL_TVT_CHARA_Create, LOCAL_TVT_CHARA_Delete, LOCAL_TVT_CHARA_Update, LOCAL_TVT_CHARA_SetActive, LOCAL_TVT_CHARA_IsDone, LOCAL_TVT_CHARA_SetupPalette, LOCAL_TVT_CHARA_SetupActors, LOCAL_TVT_CHARA_LoadPalette, LOCAL_TVT_CHARA_CopyTiles, LOCAL_TVT_CHARA_DrawLabel, LOCAL_TVT_CHARA_ShowWindow, LOCAL_TVT_CHARA_GetState, LOCAL_TVT_CHARA_SetState, LOCAL_TVT_CHARA_ClearState
 * address:  0x021B6C70
 * region:   ov174
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from local_tvt_sys.c by tools/splitfile.py.
 *
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02005728 0x02005728 thumb
 *   BG_SYS_PushTile 0x020409B4 arm
 *   func_02012944 0x02012944 thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   func_02008550 0x02008550 thumb
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   d_021B7380 0x021B7380 data a1
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   func_02041B6C 0x02041B6C arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   func_02030734 0x02030734 arm
 *   d_021B74BC 0x021B74BC data
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   func_020056EC 0x020056EC thumb
 *   CLACT_StartActorAnim 0x0204B95C arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_GetActorAnimSeqCount 0x0204B918 arm
 *   CLACT_StopActorAnim 0x0204B974 arm
 *   d_021B7485 0x021B7485 data a1
 *   d_021B7481 0x021B7481 data a1
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   d_021B7484 0x021B7484 data a1
 *   d_021B7480 0x021B7480 data a1
 *   func_02049DF4 0x02049DF4 arm
 *   MIi_CpuCopy32  0x02082A90  arm
 *   func_0201D304 0x0201D304 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 */
#include "../../matched/include/Obj00152.h"
#include "../../matched/include/Obj01422.h"
#include "../../matched/include/Obj01759.h"
#include "../../matched/include/Obj24205.h"
#include "../../matched/include/Obj03860.h"
#include "../../matched/include/Obj00185.h"
#include "../../matched/include/Obj24206.h"
#include "../../matched/include/Obj24207.h"
#include "../../matched/include/Obj05453.h"
#include "../../matched/include/Obj00476.h"
#include "../../matched/include/Obj14322.h"
#include "../../matched/include/Obj24208.h"
#include "../../matched/include/Obj24209.h"
#include "../../matched/include/Obj24210.h"
#include "../../matched/include/Obj10674.h"
#include "local_tvt_sys_shared_types.h"

struct StrObj;

typedef struct { short x, y; u16 id; u8 a, b; } Request;

typedef short s16_021B71B8;

extern void CLACT_DeleteActor(struct Obj *p);

extern void CLACT_ReleasePalette(u32_021B61C4 i);

extern void CLACT_ReleaseCharacter(u32_021B61C4 i);

extern void CLACT_ReleaseCellAnim(u32_021B61C4 i);

extern u32_021B61C4 func_020307B0(void *p);

extern int func_02005728(int);

extern u8 *func_02012944(void *p);

extern int CLACT_RegisterPaletteCompressed(void *,u32_021B6594,u32_021B6594,u32_021B6594,u16);

extern int CLACT_RegisterCharacter(void *,u32_021B6594,u32_021B6594,u32_021B6594,u16);

extern s32 CLACT_RegisterCellAnim(void *owner, u32_021B6594 first, u32_021B6594 second, u32_021B6594 mode);

extern u8 func_02008550(const struct Sub0200852CObj *obj);

extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);

extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);

extern void CLACT_SetActorDrawEnable(struct Obj *p, u32_021B6594 v);

extern void CLACT_SetActorAutoAnim(struct Obj *p, u32_021B6594 v);

extern void CLACT_RestartActorAnim(struct Actor *a);

extern void STRBUF_Delete(struct U16Vec *vec);

extern unsigned int WORDSET_DeleteStrbufED04(struct WordSet *p);

extern unsigned int BMP_WIN_Delete(struct Descriptor *d);

extern void func_02041B6C(unsigned);

extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern void BMP_WIN_TransferChars(struct Descriptor *d);

extern u32_021B68F8 BMP_WIN_Create(u32_021B68F8 layer, u32_021B68F8 a, u32_021B68F8 b, u32_021B68F8 tiles, u8 c, u8 d, u8 slot);

extern void *BMP_WIN_GetBmp(struct Descriptor *);

extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);

extern void *func_02045EC0(struct MsgBank *bank, u32_021B6A04 index);

extern struct U16Vec *STRBUF_Create(u32_021B6A04 capacity, u32_021B6A04 heapId);

extern struct WordSet *WORDSET_CreateDefault(u32 heap);

extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);

extern unsigned func_020056EC(unsigned);

extern void CLACT_StartActorAnim(struct Actor *a);

extern void CLACT_StopActorAnim(struct Actor *a);

extern u32 CLACT_IsActorAnimActive(struct Actor *a);

extern u16 CLACT_GetActorAnimSeqCount(struct Obj *p);

extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);

extern void *func_02049DF4(void *,unsigned,unsigned,unsigned,unsigned short);

extern void MIi_CpuCopy32(int, int, int);

extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);

extern void PRINTSYS_PrintQueColor(void *,u32,u32,u32,u32,u32,u16);

char *LOCAL_TVT_CHARA_Create(char *p,int index);

void LOCAL_TVT_CHARA_Delete(unsigned char *unused,char *p);

void LOCAL_TVT_CHARA_Update(u8 *p,u8 *q);

void LOCAL_TVT_CHARA_SetActive(u8 *unused,u8 *q,int unused2);

int LOCAL_TVT_CHARA_IsDone(int unused, char *p);

void LOCAL_TVT_CHARA_SetupPalette(char *p,u8 *q);

void LOCAL_TVT_CHARA_SetupActors(u8 *p, u8 *q);

void LOCAL_TVT_CHARA_LoadPalette(char *p, char *q, int id);

void LOCAL_TVT_CHARA_CopyTiles(int a, int *b, int c, int d, int e);

void LOCAL_TVT_CHARA_DrawLabel(u8 *p,u8 *q);

void LOCAL_TVT_CHARA_ShowWindow(int a, int *p);

unsigned LOCAL_TVT_CHARA_GetState(unsigned char *p);

void LOCAL_TVT_CHARA_SetState(char *p, int v);

void LOCAL_TVT_CHARA_ClearState(char *p);

extern const Pair_021B6100 d_021B7380[];

extern char d_021B74BC[];

extern const u8 d_021B7485[],d_021B7481[];

extern const u8 d_021B7484[],d_021B7480[];

char *LOCAL_TVT_CHARA_Create(char *p,int index)
{
    char *q;
    if((*(u8 **)(p+0x3c))[index]==0xff) return 0;
    q=func_02030734(((struct Obj01422 *)p)->f0,0x3c,0,d_021B74BC,0x7a);
    ((struct Obj01759 *)q)->f0=index;
    ((struct Obj01759 *)q)->f2=(*(u8 **)(p+0x3c))[index];
    ((struct Obj01759 *)q)->f3=(*(u8 * *)&((struct Obj01422 *)p)->f3C+index)[4];
    ((struct Obj01759 *)q)->f4=0;
    ((struct Obj01759 *)q)->f5=0;
    ((struct Obj01759 *)q)->f14=0;
    ((struct Obj01759 *)q)->f34=0;
    ((struct Obj01759 *)q)->f30=func_02005728(0x4b);
    if(((struct Obj01759 *)q)->f2==0 && func_02008550((const struct Sub0200852CObj *)func_02012944(((struct Obj24205 *)(*(char * *)&((struct Obj01422 *)p)->f30))->f4))==1) ((struct Obj01759 *)q)->f2=5;
    LOCAL_TVT_CHARA_SetupActors((u8 *)p,(u8 *)q);
    LOCAL_TVT_CHARA_SetupPalette(p,(u8 *)q);
    LOCAL_TVT_CHARA_DrawLabel((u8 *)p,(u8 *)q);
    ((struct Obj01759 *)q)->f8=0;
    ((struct Obj01759 *)q)->f10=0;
    ((struct Obj01759 *)q)->f6=func_02005728(40);
    ((struct Obj01759 *)q)->f38=0;
    return q;
}

void LOCAL_TVT_CHARA_Delete(unsigned char *unused,char *p) {CLACT_DeleteActor(*(struct Obj * *)&((struct Obj03860 *)p)->f28);CLACT_DeleteActor(*(struct Obj * *)&((struct Obj03860 *)p)->f2C);CLACT_ReleasePalette(((struct Obj03860 *)p)->f1C);CLACT_ReleaseCharacter(((struct Obj03860 *)p)->f20);CLACT_ReleaseCellAnim(((struct Obj03860 *)p)->f24);BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj03860 *)p)->f18);if(((struct Obj03860 *)p)->f10)func_020307B0(((struct Obj03860 *)p)->f10);func_020307B0(p);}

void LOCAL_TVT_CHARA_Update(u8 *p,u8 *q)
{
    unsigned size;
    unsigned pal;
    unsigned base;
    unsigned step;
    if(((struct Obj00152 *)p)->f8==2) size=0x6000; else size=0x3000;
    if(p[13]==0) pal=0;else pal=0xC000;
    if(((struct Obj00152 *)p)->f8==2) base=0;else base=0x1C00;
    switch(((struct Obj00185 *)q)->f8) {
    case 1:
        q[1]=0;
        LOCAL_TVT_CHARA_LoadPalette((char *)p,(char *)q,q[4]+d_021B7485[q[2]*3]);
        ((struct Obj00185 *)q)->f8=2;
        break;
    case 2:
        step=q[1]*0x3000u;
        LOCAL_TVT_CHARA_CopyTiles((int)p,(int *)q,base+step,pal+(step+(size*q[0]+0x10000)),0x3000);
        q[1]++;
        if(q[1]*0x3000u>=size) {
            ((struct Obj00185 *)q)->f8=3;
            func_020307B0(((struct Obj00185 *)q)->f10);
            ((struct Obj00185 *)q)->f10=0;
        }
        break;
    case 3:
        q[1]=0;
        LOCAL_TVT_CHARA_LoadPalette((char *)p,(char *)q,(q[5]+d_021B7481[q[3]*2])+(((struct Obj00152 *)p)->f10*2));
        ((struct Obj00185 *)q)->f8=4;
        break;
    case 4:
        step=q[1]*0x3000u;
        LOCAL_TVT_CHARA_CopyTiles((int)p,(int *)q,base+step,pal+(step+(size*q[0]+0x28000)),0x3000);
        q[1]++;
        if(q[1]*0x3000u>=size) {
            ((struct Obj00185 *)q)->f8=5;
            func_020307B0(((struct Obj00185 *)q)->f10);
            ((struct Obj00185 *)q)->f10=0;
        }
        break;
    case 0:
        break;
    }
    if(q[6]<40) q[6]++;
    else if(((struct Obj00185 *)q)->f8==5 || ((struct Obj00185 *)q)->f8==0) {
        q[6]=0;
        q[4]=q[4]==0?1:0;
        q[5]=q[5]==0?1:0;
    }
    if(((struct Obj00185 *)q)->f14==1 && PRINTSYS_QUE_IsFinished(((struct Obj00152 *)p)->f78)==1) {
        BMP_WIN_TransferChars(((struct Obj00185 *)q)->f18);
        ((struct Obj00185 *)q)->f14=0;
    }
    ((struct Obj00185 *)q)->f30+=(u16)(func_020056EC(2)+1);
    if(((struct Obj00185 *)q)->f30>=150) {
        CLACT_StartActorAnim(((struct Obj00185 *)q)->f28);
        CLACT_RestartActorAnim(((struct Obj00185 *)q)->f28);
        ((struct Obj00185 *)q)->f30=0;
    }
    if(((struct Obj00185 *)q)->f34==1 || ((struct Obj00185 *)q)->f38!=0) {
        if(CLACT_IsActorAnimActive(((struct Obj00185 *)q)->f2C)==0) CLACT_StartActorAnim(((struct Obj00185 *)q)->f2C);
    } else {
        if(CLACT_IsActorAnimActive(((struct Obj00185 *)q)->f2C)==1 && CLACT_GetActorAnimSeqCount(((struct Obj00185 *)q)->f2C)==0)
            CLACT_StopActorAnim(((struct Obj00185 *)q)->f2C);
    }
    if(((struct Obj00185 *)q)->f38!=0) (((struct Obj00185 *)q)->f38)--;
}

/*
 * extent: trailing store-and-return follower 021B6F24 included in this unit; 021B6F2A..021B6F2C is alignment padding.
 */
void LOCAL_TVT_CHARA_SetActive(u8 *unused,u8 *q,int unused2)
{
    ((struct Obj24206 *)q)->f8=1;
}

int LOCAL_TVT_CHARA_IsDone(int unused, char *p)
{
    return ((struct Obj24207 *)p)->f8 == 5;
}

void LOCAL_TVT_CHARA_SetupPalette(char *p,u8 *q)
{
    u8 height=24;
    if(((struct Obj05453 *)p)->f8!=2) height=12;
    ARC_UTIL_UploadPaletteFromHandle(((struct Obj05453 *)p)->f18,d_021B7484[q[2]*3],2,0,0x4000+q[0]*0x200,0x200,((struct Obj05453 *)p)->f0);
    ARC_UTIL_UploadPaletteFromHandle(((struct Obj05453 *)p)->f18,((struct Obj05453 *)p)->f10+d_021B7480[q[3]*2],2,0,0x6000+q[0]*0x200,0x200,((struct Obj05453 *)p)->f0);
    BG_SYS_FillTileMap(2,(q[0]%2)*16,(q[0]/2)*height,16,height,q[0]);
    BG_SYS_FillTileMap(3,(q[0]%2)*16,(q[0]/2)*height,16,height,q[0]);
    func_02041B6C(3);
    func_02041B6C(2);
}

/*
 * prototype: 0204B294 leaves its forwarder's result in r0, captured at
 *   021B712A and 021B715A; the returned object pointer is stored as a word.
 */
void LOCAL_TVT_CHARA_SetupActors(u8 *p, u8 *q)
{
    int step;
    int base;
    Request req;
    if (((struct Obj01422 *)p)->f8 == 2) { step = 0x6000; base = 0; }
    else { step = 0x3000; base = 0x1c00; }
    LOCAL_TVT_CHARA_LoadPalette((char *)p, (char *)q, (d_021B7481 + 4)[q[2] * 3]);
    LOCAL_TVT_CHARA_CopyTiles((int)p, (int *)q, base, step * q[0] + 0x10000, step);
    func_020307B0(((struct Obj00476 *)q)->f10);
    LOCAL_TVT_CHARA_LoadPalette((char *)p, (char *)q, d_021B7481[q[3] * 2] + ((struct Obj01422 *)p)->f10 * 2);
    LOCAL_TVT_CHARA_CopyTiles((int)p, (int *)q, base, step * q[0] + 0x28000, step);
    func_020307B0(((struct Obj00476 *)q)->f10);
    *(int *)&((struct Obj00476 *)q)->f1C = CLACT_RegisterPaletteCompressed(((struct Obj01422 *)p)->f18, (d_021B7481 + 5)[q[2] * 3], 0, (u16)((q[0] * 2 + 4) << 5), ((struct Obj01422 *)p)->f0);
    *(int *)&((struct Obj00476 *)q)->f20 = CLACT_RegisterCharacter(((struct Obj01422 *)p)->f18, (d_021B7481 + 5)[q[2] * 3] + 1, 0, 0, ((struct Obj01422 *)p)->f0);
    *(int *)&((struct Obj00476 *)q)->f24 = CLACT_RegisterCellAnim(((struct Obj01422 *)p)->f18, (d_021B7481 + 5)[q[2] * 3] + 2, (d_021B7481 + 5)[q[2] * 3] + 3, ((struct Obj01422 *)p)->f0);
    req.a = 10; req.b = 1;
    req.x = (q[0] % 2) * 128 + 64;
    req.y = (q[0] / 2) * 96 + 48;
    if (((struct Obj01422 *)p)->f8 == 2) req.y += 56;
    req.id = 0;
    *(u32 *)&((struct Obj00476 *)q)->f28 = (u32)CLACT_CreateActor((void *)((struct Obj01422 *)p)->f50, ((struct Obj00476 *)q)->f20, ((struct Obj00476 *)q)->f1C, ((struct Obj00476 *)q)->f24, &req, 0, ((struct Obj01422 *)p)->f0);
    CLACT_SetActorDrawEnable(((struct Obj00476 *)q)->f28, 1);
    CLACT_SetActorAutoAnim(((struct Obj00476 *)q)->f28, 1);
    CLACT_StopActorAnim(((struct Obj00476 *)q)->f28);
    req.id = 1;
    *(u32 *)&((struct Obj00476 *)q)->f2C = (u32)CLACT_CreateActor((void *)((struct Obj01422 *)p)->f50, ((struct Obj00476 *)q)->f20, ((struct Obj00476 *)q)->f1C, ((struct Obj00476 *)q)->f24, &req, 0, ((struct Obj01422 *)p)->f0);
    CLACT_SetActorDrawEnable(((struct Obj00476 *)q)->f2C, 1);
    CLACT_SetActorAutoAnim(((struct Obj00476 *)q)->f2C, 1);
    CLACT_StopActorAnim(((struct Obj00476 *)q)->f2C);
}

void LOCAL_TVT_CHARA_LoadPalette(char *p, char *q, int id) {((struct Obj24208 *)q)->f10=func_02049DF4(((struct Obj14322 *)p)->f18,id,0,(unsigned)(q+12),((struct Obj14322 *)p)->f0);}

void LOCAL_TVT_CHARA_CopyTiles(int a, int *b, int c, int d, int e)
{
    MIi_CpuCopy32(*(int *)((char *)(((struct Obj24209 *)b)->fC) + 0x14) + c,
                  d + 0x06000000, e);
}

void LOCAL_TVT_CHARA_DrawLabel(u8 *p,u8 *q)
{
    void *s;
    void *dst;
    void *ws;
    u8 *save;
    *(u32 *)(q+0x18)=BMP_WIN_Create(0,(u8)(d_021B7380[q[0]].x+2),(u8)(d_021B7380[q[0]].y+1),12,2,12,1);
    BMP_Clear(BMP_WIN_GetBmp(*(void **)(q+0x18)),0);
    BMP_WIN_TransferChars(*(void **)(q+0x18));
    BMP_WIN_MakeScreen(*(void **)(q+0x18));
    BG_SYS_PushTile(0);
    s=func_02045EC0(*(void **)(p+0x68),q[2]);
    if(q[2]==0 || q[2]==5){
        dst=STRBUF_Create(128,*(u16 *)p);
        save=func_02012944(*(void **)(*(u8 **)(p+0x30)+4));
        ws=WORDSET_CreateDefault(*(u16 *)p);
        WORDSET_SetSlotMyStatus(ws,0,save);
        WORDSET_CopyTaggedText(ws,dst,s);
        STRBUF_Delete(s);
        WORDSET_DeleteStrbufED04(ws);
        s=dst;
    }
    q[7]=func_0201D304(s,*(u32 *)(p+0x60),0);
    PRINTSYS_PrintQueColor(*(void **)(p+0x78),(u32)BMP_WIN_GetBmp(*(void **)(q+0x18)),(s16_021B71B8)((96-q[7])/2+1),1,(u32)s,*(u32 *)(p+0x60),0x3c00);
    PRINTSYS_PrintQueColor(*(void **)(p+0x78),(u32)BMP_WIN_GetBmp(*(void **)(q+0x18)),(s16_021B71B8)((96-q[7])/2-1),1,(u32)s,*(u32 *)(p+0x60),0x3c00);
    PRINTSYS_PrintQueColor(*(void **)(p+0x78),(u32)BMP_WIN_GetBmp(*(void **)(q+0x18)),(s16_021B71B8)((96-q[7])/2),2,(u32)s,*(u32 *)(p+0x60),0x3c00);
    PRINTSYS_PrintQueColor(*(void **)(p+0x78),(u32)BMP_WIN_GetBmp(*(void **)(q+0x18)),(s16_021B71B8)((96-q[7])/2),0,(u32)s,*(u32 *)(p+0x60),0x3c00);
    PRINTSYS_PrintQueColor(*(void **)(p+0x78),(u32)BMP_WIN_GetBmp(*(void **)(q+0x18)),(s16_021B71B8)((96-q[7])/2),1,(u32)s,*(u32 *)(p+0x60),0x400);
    STRBUF_Delete(s);
    *(u32 *)(q+0x14)=1;
}

void LOCAL_TVT_CHARA_ShowWindow(int a, int *p)
{
    BMP_WIN_MakeScreen((struct Cfg *)(((struct Obj24210 *)p)->f18));
    func_02041B6C(0);
}

unsigned LOCAL_TVT_CHARA_GetState(unsigned char *p) {return p[7];}

void LOCAL_TVT_CHARA_SetState(char *p, int v)
{
    if (((struct Obj10674 *)p)->f34 == 1 && v == 0)
        ((struct Obj10674 *)p)->f38 = 0x46;
    ((struct Obj10674 *)p)->f34 = v;
}

void LOCAL_TVT_CHARA_ClearState(char *p)
{
    ((struct Obj10674 *)p)->f38 = 0;
    ((struct Obj10674 *)p)->f34 = 0;
}
