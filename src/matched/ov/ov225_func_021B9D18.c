/*
 * function: MANUAL_COMMON_CreateData
 * address: 0x021B9D18
 * packet: pkt_ov225_021B9D18
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MANUAL_GRAPHIC_CreateScreen 0x021B9900 thumb ov225
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_020490F4 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromArchive 0x02049B90 arm
 *   MANUAL_COMMON_CreateMenuTable 0x021B9B3C thumb ov225
 *   MANUAL_COMMON_InitDisplay 0x021B9EE8 thumb ov225
 *   MANUAL_COMMON_GetDefaultId 0x021B9CDC thumb ov225
 *   MANUAL_COMMON_SetScreenId 0x021B9E80 thumb ov225
 *   MANUAL_COMMON_CreateTouchbar 0x021B9F24 thumb ov225
 *   gManualCommonDataAllocFile 0x021BC004 data ov225 a1
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct GfFont;
struct MsgBank;
struct State {
    void *owner; u16 heap,pad6; void *screen;
    struct GfFont *font; u32 str10,str14,str18;
    struct MsgBank *bank1,*bank2;
    void *arc1,*arc2,*assets; u16 id,pad32; void *group;
};
extern const char gManualCommonDataAllocFile[];
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void *MANUAL_GRAPHIC_CreateScreen(u32,u32);
extern struct GfFont *GF_FONT_Create(int,int,int,int,u32);
extern u32 PRINTSYS_QUE_Create(void *);
extern struct MsgBank *func_02045B38(u32,u32,u32,u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void ARC_UTIL_UploadPaletteFromArchive(u32,u32,u32,u32,u32,u32,u16);
extern void *MANUAL_COMMON_CreateMenuTable(void *,u32);
extern void MANUAL_COMMON_InitDisplay(void *);
extern int MANUAL_COMMON_GetDefaultId(void *);
extern void MANUAL_COMMON_SetScreenId(char *,unsigned);
extern void *MANUAL_COMMON_CreateTouchbar(char *);
void *MANUAL_COMMON_CreateData(void *owner,u16 heap)
{
    struct State *p=func_02030734(heap,0x38,1,gManualCommonDataAllocFile,0x4b);
    p->owner=owner; p->heap=heap;
    p->screen=MANUAL_GRAPHIC_CreateScreen(1,p->heap);
    p->font=GF_FONT_Create(23,0,0,0,p->heap);
    p->str10=PRINTSYS_QUE_Create((void *)(u32)p->heap);
    p->str14=PRINTSYS_QUE_Create((void *)(u32)p->heap);
    p->str18=PRINTSYS_QUE_Create((void *)(u32)p->heap);
    p->bank1=func_02045B38(0,2,61,p->heap);
    p->bank2=func_02045B38(0,2,62,p->heap);
    p->arc1=func_020490F4(223,p->heap);
    p->arc2=func_020490F4(231,p->heap);
    ARC_UTIL_UploadPaletteFromArchive(23,5,4,0,64,32,p->heap);
    p->assets=MANUAL_COMMON_CreateMenuTable(p->arc1,p->heap);
    MANUAL_COMMON_InitDisplay(p);
    p->id=65535;
    MANUAL_COMMON_SetScreenId((char *)p,MANUAL_COMMON_GetDefaultId(p->assets));
    p->group=MANUAL_COMMON_CreateTouchbar((char *)p);
    return p;
}
