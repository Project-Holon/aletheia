/*
 * function: func_021B9D18
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
 *   func_021B9900 0x021B9900 thumb ov225
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_020490F4 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromArchive 0x02049B90 arm
 *   func_021B9B3C 0x021B9B3C thumb ov225
 *   func_021B9EE8 0x021B9EE8 thumb ov225
 *   func_021B9CDC 0x021B9CDC thumb ov225
 *   func_021B9E80 0x021B9E80 thumb ov225
 *   func_021B9F24 0x021B9F24 thumb ov225
 *   d_021BC004 0x021BC004 data ov225 a1
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
extern const char d_021BC004[];
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void *func_021B9900(u32,u32);
extern struct GfFont *GF_FONT_Create(int,int,int,int,u32);
extern u32 PRINTSYS_QUE_Create(void *);
extern struct MsgBank *func_02045B38(u32,u32,u32,u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void ARC_UTIL_UploadPaletteFromArchive(u32,u32,u32,u32,u32,u32,u16);
extern void *func_021B9B3C(void *,u32);
extern void func_021B9EE8(void *);
extern int func_021B9CDC(void *);
extern void func_021B9E80(char *,unsigned);
extern void *func_021B9F24(char *);
void *func_021B9D18(void *owner,u16 heap)
{
    struct State *p=func_02030734(heap,0x38,1,d_021BC004,0x4b);
    p->owner=owner; p->heap=heap;
    p->screen=func_021B9900(1,p->heap);
    p->font=GF_FONT_Create(23,0,0,0,p->heap);
    p->str10=PRINTSYS_QUE_Create((void *)(u32)p->heap);
    p->str14=PRINTSYS_QUE_Create((void *)(u32)p->heap);
    p->str18=PRINTSYS_QUE_Create((void *)(u32)p->heap);
    p->bank1=func_02045B38(0,2,61,p->heap);
    p->bank2=func_02045B38(0,2,62,p->heap);
    p->arc1=func_020490F4(223,p->heap);
    p->arc2=func_020490F4(231,p->heap);
    ARC_UTIL_UploadPaletteFromArchive(23,5,4,0,64,32,p->heap);
    p->assets=func_021B9B3C(p->arc1,p->heap);
    func_021B9EE8(p);
    p->id=65535;
    func_021B9E80((char *)p,func_021B9CDC(p->assets));
    p->group=func_021B9F24((char *)p);
    return p;
}
