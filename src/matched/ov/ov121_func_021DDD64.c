/*
 * function: MYSTERY_ALBUM_SetupIcons
 * address: 0x021DDD64
 * packet: pkt_ov121_021DDD64
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever (wave 82, lane R10, retry): the palette base is an inline that adds
 *   the byte offset inside each arm (`if (mode==0) return off+0x05000200;
 *   else return off+0x05000600;`); the shared add cross-jumps into the
 *   `adds r1,r0,r1` join. A base-only inline plus `+ offset` at the call site,
 *   or a ternary on the base, if-converts to a default load plus override and
 *   misschedules the q+0xb0/q+0x98 loads (431 B). The heap stays u16 as in
 *   matched ov121 MYSTERY_ALBUM_CreateEntryArc and matched caller MYSTERY_ALBUM_SetupTask: the earlier
 *   u32-heap owner gate does not apply.
 * symbols:
 *   MYSTERY_ALBUM_CreateEntryArc 0x021DBF10 thumb ov121
 *   MYSTERY_ALBUM_GetEntryPaletteResId 0x021DBF40 thumb ov121
 *   MYSTERY_ALBUM_GetEntryGraphicIndex 0x021DBF9C thumb ov121
 *   MYSTERY_ALBUM_GetEntryIconPalette 0x021DBF70 thumb ov121
 *   MYSTERY_ALBUM_GetEntryKind 0x021DC024 thumb ov121
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   ARC_UTIL_LoadScreenDataFromHandle 0x02049E74 arm
 *   CLACT_TransferCharacterPart 0x0204AA94 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_TransferPalette 0x0204ADEC arm
 *   MIi_CpuClear16 0x02082A48 arm
 *   CLACT_SetActorRotation 0x0204B5F4 arm
 *   CLACT_GetPaletteVramAddress 0x0204AEF4 arm
 *   func_0207D63C 0x0207D63C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {s16 x,y;} Point;
extern void *MYSTERY_ALBUM_CreateEntryArc(void *,u16);
extern u32 MYSTERY_ALBUM_GetEntryPaletteResId(void *);
extern int MYSTERY_ALBUM_GetEntryGraphicIndex(void *);
extern u32 MYSTERY_ALBUM_GetEntryIconPalette(void *);
extern int MYSTERY_ALBUM_GetEntryKind(void *);
struct Obj;
extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *a0, u32 a1, u32 a2, u32 a3);
extern void MI_CpuCopy8(const void *,void *,int);
extern u32 func_020307B0(void *p);
extern void *ARC_UTIL_LoadScreenDataFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void CLACT_TransferCharacterPart(int,void *,u32,int,int);
extern void ARC_TOOL_DeleteHandle(void *);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern void CLACT_AddActorSurfacePos(void *,const Point *,u16);
struct Actor;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_TransferPalette(u32,void *,u32);
extern void MIi_CpuClear16(u32,void *,u32);
extern void CLACT_SetActorRotation(struct Actor *actor, u16 value);
extern int CLACT_GetPaletteVramAddress(u32 idx, u32 alternate);
extern void func_0207D63C(void *,int,int,int,int);
static inline void *palette(u32 off, int mode)
{
    if (mode==0) return (void *)(off+0x05000200);
    else return (void *)(off+0x05000600);
}
void MYSTERY_ALBUM_SetupIcons(char *p,char *q,u16 heap)
{
    void *arc;
    void *allocation;
    void *allocation2;
    void *res;
    void *res2;
    Point pt;
    u16 *dest;
    u32 offset;
    int i;
    arc=MYSTERY_ALBUM_CreateEntryArc(p,heap);
    allocation=ARC_UTIL_LoadPaletteBlockFromHandle(arc,(int)MYSTERY_ALBUM_GetEntryPaletteResId(p),(u32)(&res),(u16)(*(u16 *)(p+0x118)));
    offset=*(u32 *)(q+0xb0)*32;
    MI_CpuCopy8(*(void **)((char *)res+12),palette(offset,*(u32 *)(q+0x98)),96);
    func_020307B0(allocation);
    allocation2=ARC_UTIL_LoadScreenDataFromHandle(arc,(int)MYSTERY_ALBUM_GetEntryGraphicIndex(p),(int)0,(u32)(&res2),*(u16 *)(p+0x118));
    CLACT_TransferCharacterPart(*(int *)(q+8),*(void **)((char *)res2+20),512,0,*(int *)(q+0x98));
    func_020307B0(allocation2);
    ARC_TOOL_DeleteHandle(arc);
    pt.x=216; pt.y=22;
    if (MYSTERY_ALBUM_GetEntryKind(p)==2) {pt.x+=4;pt.y+=8;}
    CLACT_SetActorPaletteOffset(*(void **)(q+28),(u8)MYSTERY_ALBUM_GetEntryIconPalette(p),0);
    CLACT_AddActorSurfacePos(*(void **)(q+28),&pt,*(u32 *)(q+0x98));
    CLACT_SetActorDrawEnable(*(void **)(q+28),1);
    if (MYSTERY_ALBUM_GetEntryKind(p)==1) {
        CLACT_TransferPalette(*(u32 *)(q+16),*(void **)(*(char **)(p+0x140)+12),1);
        MI_CpuCopy8(*(void **)(*(char **)(p+0x140)+12),q+0x64,32);
        MIi_CpuClear16(0,q+0x44,32);
        CLACT_TransferCharacterPart(*(int *)(q+20),*(void **)(*(char **)(p+0x138)+20),0x1200,0,*(int *)(q+0x98));
        CLACT_SetActorRotation(*(void **)(q+32),0);
        CLACT_SetActorDrawEnable(*(void **)(q+32),1);
        if (*(u32 *)(q+0xa0)<4) dest=(u16 *)((u32)CLACT_GetPaletteVramAddress(*(u32 *)(q+16),*(u32 *)(q+0x98))+0x05000200);
        else dest=(u16 *)((u32)CLACT_GetPaletteVramAddress(*(u32 *)(q+16),*(u32 *)(q+0x98))+0x05000600);
        for(i=0;i<16;i++) dest[i]=*(u16 *)(q+0x44+i*2);
        if (*(u32 *)(q+0xa0)<4)
            func_0207D63C((void *)0x04000050,0,(1<<(u8)*(u32 *)(q+0xa0))|(1<<(u8)*(u32 *)(q+0xa4)),2,12);
        else
            func_0207D63C((void *)0x04001050,0,(1<<(u8)(*(u32 *)(q+0xa0)-4))|(1<<(u8)(*(u32 *)(q+0xa4)-4)),2,12);
    } else CLACT_SetActorDrawEnable(*(void **)(q+32),0);
}
