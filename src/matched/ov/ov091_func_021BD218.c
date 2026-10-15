/*
 * function: PLIST_BATTLE_CreateMiniCell
 * address: 0x021BD218
 * packet: pkt_ov091_021BD218
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: u16 y pins x's front spill; declare the u8 offset before gx to restore r7/r6 allocation.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   func_020490F4 0x020490F4 arm
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   POKE_TOOL_GetGraphicIndex 0x0201BA68 thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   POKE_TOOL_GetIconPalette 0x0201BBE8 thumb
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   FILE_UTIL_Check136C 0x0202136C thumb
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   POKELIST_PrintTextMain 0x021B9C1C thumb ov091
 *   POKE_TOOL_CalcLevel 0x02018430 thumb
 *   GF_FONT_Create_EC64 0x0201EC64 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   POKELIST_PrintExpandedTextSub 0x021B9D58 thumb ov091
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   d_021BED48 0x021BED48 data ov091 a1
 */
#include "../include/Obj02771.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef struct {u16 a,b,c;u8 d,e;} R;
typedef signed int     s32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void *POKE_TOOL_GetBoxParam(void *p);
struct Obj;
struct WordSet;
extern u32 POKE_TOOL_GetGraphicIndex(void *mon);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void ARC_TOOL_DeleteHandle(void *);
extern int POKE_TOOL_GetIconPalette(void *a0);
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p,u32 v);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern u32 FILE_UTIL_Check136C(u16);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u32 BMP_WIN_Create(int,u8,u8,int,u8,u8,u8);
extern void POKELIST_PrintTextMain(u8 *p, u32 win, u32 id, int x, s16 y, u16 color);
extern u32 POKE_TOOL_CalcLevel(void *p);
extern struct WordSet *GF_FONT_Create_EC64(u32 heap);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void POKELIST_PrintExpandedTextSub(u8 *p, u32 win, void *set, u32 idx, s16 x, s16 y, u16 color);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern const char d_021BED48[];
#define P(k) (*(u32 *)(p+(k)))
u32 *PLIST_BATTLE_CreateMiniCell(u8 *p,void *mon,s16 x,u16 y)
{
    R a;
    R b;
    u32 *s;
    void *h;
    int species;
    int frame;
    u32 gender;
    u32 special;
    int level;
    int egg;
    int rem;
    u8 z;
    int gx;
    u32 gy;
    u32 text;
    s=func_02030734(((struct Obj02771 *)p)->f0,24,0,d_021BED48,0x199);
    egg=POKE_TOOL_GetPartyValue(mon,0x4c,0);
    h=func_020490F4(7,((struct Obj02771 *)p)->f0);
    species=(int)POKE_TOOL_GetBoxParam(mon);
    s[3]=CLACT_RegisterCharacter(h,POKE_TOOL_GetGraphicIndex((void *)species),0,1,((struct Obj02771 *)p)->f0);
    ARC_TOOL_DeleteHandle(h);
    frame=POKE_TOOL_GetIconPalette((void *)species);
    a.a=x+16;a.b=y+8;a.c=1;a.d=16;a.e=2;
    {
        int obj=(int)CLACT_CreateActor((void *)P(0x1ec),s[3],P(0x194),P(0x1d0),&a,1,((struct Obj02771 *)p)->f0);
        s[4]=obj;
        CLACT_SetActorPaletteOffset((struct Obj *)obj,frame,1);
    }
    CLACT_SetActorAutoAnim((struct Obj *)s[4],1);
    gender=POKE_TOOL_GetPartyValue(mon,6,0);
    b.a=x+32;b.b=y+16;b.c=0;b.d=8;b.e=2;
    s[5]=(u32)CLACT_CreateActor((void *)P(0x1ec),P(0x1a8),P(0x184),P(0x1c4),&b,1,((struct Obj02771 *)p)->f0);
    if(gender!=0) {
        CLACT_SetActorDrawEnable((struct Obj *)s[5],1);
        if(FILE_UTIL_Check136C(gender)==1) CLACT_SetActorAnimSeq((struct Obj *)s[5],1);
        else CLACT_SetActorAnimSeq((struct Obj *)s[5],0);
    } else CLACT_SetActorDrawEnable((struct Obj *)s[5],0);
    special=POKE_TOOL_GetPartyValue(mon,0x6e,0);
    rem=x%8;
    z=rem;
    gy=(u32)y>>3;
    gx=(u32)x>>3;
    s[1]=BMP_WIN_Create(4,(u8)gx+3,gy,3,2,13,1);
    if(egg==0) {
        if(special==0) POKELIST_PrintTextMain(p,s[1],7,(u16)(z+4),0,0x14c0);
        else if(special==1) POKELIST_PrintTextMain(p,s[1],8,(u16)(z+4),0,0xc80);
    }
    level=POKE_TOOL_CalcLevel((void *)((int)mon));
    z=rem;
    s[2]=BMP_WIN_Create(4,(u8)gx,(u8)gy+3,6,1,14,1);
    if(egg==0) {
        text=(u32)GF_FONT_Create_EC64(((struct Obj02771 *)p)->f0);
        func_0201EFA4((struct WordSet *)text,0,level,3,0,1);
        POKELIST_PrintExpandedTextSub(p,s[2],(void *)text,2,z,0,0x3c40);
        WORDSET_DeleteStrbufED04((struct WordSet *)text);
    }
    s[0]=1;
    return s;
}
