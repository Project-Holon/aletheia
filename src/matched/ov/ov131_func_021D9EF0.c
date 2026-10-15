/*
 * function: P_STA_SKILL_ApplyMovesScreen
 * address: 0x021D9EF0
 * packet: pkt_ov131_021D9EF0
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 021DA0AE follow the 446-byte body.
 * proof: i is a byte, i*24 <=6120. first/second remain full-word u32
 * results; unsigned address multiply/add preserve original modulo-2^32
 * lsl/add without invented selector bounds. 0204AB84 writes all nine words
 * before 0204B784 reads them; both Point halfwords are stored before use.
 * symbols:
 *   func_02041570 0x02041570 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   BG_SYS_PushTileSource 0x020409E0 arm
 *   func_02040AE0 0x02040AE0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020410D0 0x020410D0 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   P_STA_SKILL_ShowSlot 0x021DB964 thumb ov131
 *   P_STATUS_GetPokePara 0x021D6064 thumb ov131
 *   func_02017E88 0x02017E88 thumb
 *   CLACT_GetCharacterProxy 0x0204AB84 arm
 *   CLACT_SetActorImageProxy 0x0204B784 arm
 *   func_020275EC 0x020275EC thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 */
#include "../include/Obj00136.h"
#include "../include/Obj00536.h"
#include "../include/Obj23161.h"
#include "../include/Obj23162.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {u32 w[9];} Rec;
typedef struct {s16 x,y;} Point;
extern void func_02041570(int,u16);
struct Cfg;
struct Descriptor;
struct Obj;
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void BG_SYS_PushTileSource(u32,const void *,u32,u32);
extern void func_02040AE0(u32 index, const void *src, u32 mode);
extern void func_02041B6C(u32 bit);
extern void func_020410D0(u32,u32,u32,u32,u8,u32,u8,u8,u8,u8);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void P_STA_SKILL_ShowSlot(u8 *,void *,u8 *);
extern void *P_STATUS_GetPokePara(u8 *);
extern u32 func_02017E88(void *,u32,u32);
struct Rec;
struct Struct36;
struct Vec2;
extern void CLACT_GetCharacterProxy(u32 idx, struct Rec *dst);
extern void CLACT_SetActorImageProxy(char *dst, const struct Struct36 *src);
extern u8 func_020275EC(int i);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_SetActorBgPriority(void *,u32);
void P_STA_SKILL_ApplyMovesScreen(u8 *a,u8 *p)
{
    Rec r1,r2;
    Point point;
    u8 i;
    void *cell;
    void *object;
    u32 first,second;
    func_02041570(4,0);
    for(i=8;i<=11;i++) {
        cell=*(void **)((p+i*4)+0x5c);
        BMP_WIN_TransferChars(cell);
        BMP_WIN_MakeScreen(cell);
        func_020409B4(BMP_WIN_GetBgLayer(cell));
    }
    i=0;
    BG_SYS_PushTileSource(6,*(u8 * *)&((struct Obj00536 *)p)->f44+12,((struct Obj23161 *)(*(u8 * *)&((struct Obj00536 *)p)->f44))->f8,0);
    func_02040AE0(6,*(u8 * *)&((struct Obj00536 *)p)->f44+12,((struct Obj23162 *)(*(u8 * *)&((struct Obj00536 *)p)->f44))->f8);
    func_02041B6C(6);
    func_020410D0(5,0,0,32,3,(u32)(*(u8 * *)&((struct Obj00536 *)p)->f54+12),0,0,32,32);
    func_02041B6C(5);
    CLACT_SetActorDrawEnable(((struct Obj00536 *)p)->f90,0);
    CLACT_SetActorDrawEnable(((struct Obj00536 *)p)->f94,1);
    for(;i<p[0x2b];i++) P_STA_SKILL_ShowSlot(a,p,(p+0xb0)+i*24);
    object=P_STATUS_GetPokePara(a);
    first=func_02017E88(object,174,0);
    second=func_02017E88(object,175,0);
    CLACT_GetCharacterProxy(*(u32 *)(((u32)a+first*4u)+0x130u),(struct Rec *)(&r1));
    CLACT_SetActorImageProxy(((struct Obj00136 *)a)->f198,(const struct Struct36 *)(&r1));
    CLACT_SetActorPaletteOffset(((struct Obj00136 *)a)->f198,func_020275EC((u8)first),1);
    point.x=208;
    point.y=120;
    CLACT_AddActorSurfacePos(((struct Obj00136 *)a)->f198,(const struct Vec2 *)(&point),0);
    CLACT_SetActorDrawEnable(((struct Obj00136 *)a)->f198,1);
    CLACT_SetActorBgPriority(((struct Obj00136 *)a)->f198,0);
    if(first!=second) {
        CLACT_GetCharacterProxy(*(u32 *)(((u32)a+second*4u)+0x130u),(struct Rec *)(&r2));
        CLACT_SetActorImageProxy(((struct Obj00136 *)a)->f19C,(const struct Struct36 *)(&r2));
        CLACT_SetActorPaletteOffset(((struct Obj00136 *)a)->f19C,func_020275EC((u8)second),1);
        point.x=240;
        point.y=120;
        CLACT_AddActorSurfacePos(((struct Obj00136 *)a)->f19C,(const struct Vec2 *)(&point),0);
        CLACT_SetActorDrawEnable(((struct Obj00136 *)a)->f19C,1);
        CLACT_SetActorBgPriority(((struct Obj00136 *)a)->f19C,0);
    } else CLACT_SetActorDrawEnable(((struct Obj00136 *)a)->f19C,0);
}
