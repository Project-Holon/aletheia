/*
 * function: ZUKAN_DETAIL_AREA_DrawTownName
 * address:  0x021C1D30
 * packet:   pkt_ov208_021C1D30
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   TOWNMAP_GRH_GetTownInfoValue  0x021BBB3C  thumb  ov072
 *   ZONEDATA_GetPlaceNameId  0x02013E4C  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   func_021C0740  0x021C0740  thumb  ov208
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct {
    u16 x;
    u16 y;
} Pt;

struct MsgBank;
struct Obj;
struct PrintSys;
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
struct CharBuf;
struct U16Vec;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern unsigned short TOWNMAP_GRH_GetTownInfoValue(char *p, int a, int b);
extern u32 ZONEDATA_GetPlaceNameId(u32 id);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_021C0740(u16 *heap, u8 *p, int key, u8 i);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *obj, unsigned int on);
extern void BMP_WIN_TransferChars(struct Descriptor *p);

#define W(o) (*(u32 *)(p + (o)))

void ZUKAN_DETAIL_AREA_DrawTownName(u16 *heap, u8 *p, int key)
{
    void *str;
    Pt pt;

    W(0x28) = 0;
    PRINTSYS_QUE_Clear((struct PrintSys *)W(0x38));
    BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)W(0x18)), 0);
    if (p[0x79] != 0xff) {
        str = func_02045EC0((struct MsgBank *)W(0x10), ZONEDATA_GetPlaceNameId(TOWNMAP_GRH_GetTownInfoValue((char *)W(0x3c8), p[0x79], 0)));
        PRINTSYS_PrintQueColor((void *)W(0x38), (u32)BMP_WIN_GetBmp((struct Descriptor *)W(0x18)), 0, 1, (u32)str, W(4), 0x3c40);
        STRBUF_Delete(str);
        W(0x28) = 1;
        func_021C0740(heap, p, key, 1);
        pt.x = TOWNMAP_GRH_GetTownInfoValue((char *)W(0x3c8), p[0x79], 2);
        pt.y = TOWNMAP_GRH_GetTownInfoValue((char *)W(0x3c8), p[0x79], 3);
        CLACT_SetActorAnimSeq((struct Obj *)W(0xd0), 5);
        CLACT_AddActorSurfacePos((struct Obj *)W(0xd0), (const struct Vec2 *)(&pt), 0);
        CLACT_SetActorDrawEnable((struct Obj *)W(0xd0), 1);
    } else {
        BMP_WIN_TransferChars((struct Descriptor *)W(0x18));
        CLACT_SetActorDrawEnable((struct Obj *)W(0xd0), 0);
    }
}
