/*
 * function: FLD3D_CI_DrawMessageTexture
 * address:  0x021C2F84
 * packet:   pkt_ov021_021C2F84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02048A0C  0x02048A0C  arm
 *   func_02045B38  0x02045B38  arm
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   WORDSET_Delete  0x0201ED04  thumb
 *   WORDSET_AppendUnpackedString  0x0201F4A0  thumb
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   func_0201D304  0x0201D304  thumb
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   ARC_UTIL_LoadPaletteBlockFromArchive  0x02049F34  arm
 *   TEXT_TEXTURE_LoadTexPlttByName  0x0216FAB4  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   MSGDATA_Delete  0x02045C04  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct PlttData {
    u8 pad00[0xc];
    u16 *raw;
} PlttData;

typedef struct Obj {
    u8 pad00[0x10];
    u16 heap;
    u16 pad12;
    void *f14;
    u8 pad18[0x8c - 0x18];
    PlttData *pltt;
    void *canvas;
    void *chrRes;
    void *plttRes;
} Obj;

struct StrObj;
struct TexKey;
struct WordSet;
extern u32 func_02048A0C(u8 *a0, int i);
struct GfFont;
struct MsgBank;
struct Rec;
struct U16Vec;
struct WordSet;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern void *STRBUF_Create(u32 size, u16 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 WORDSET_Delete(struct WordSet *p);
extern void WORDSET_AppendUnpackedString(void *dst, void *src);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 GF_FONT_Delete(void *ptr);
extern void *ARC_UTIL_LoadPaletteBlockFromArchive(u32 a0, u32 a1, u32 a2, u32 a3);
extern int TEXT_TEXTURE_LoadTexPlttByName(void *file, const char *texName, void *extra, const char *plttName, u32 a4, u16 a5, u16 a6, u16 a7, u16 heap, struct TexKey *out);
extern u32 func_020307B0(void *p);
extern u32 MSGDATA_Delete(struct Rec *rec);

void FLD3D_CI_DrawMessageTexture(int s, Obj *p, char *a1, char *a2, u32 c, u32 d)
{
    u8 buf[0x14];
    void *x;
    void *z;
    void *y;
    void *m;
    void *h;
    u16 heap;
    void *str;
    int w;
    u16 *pl;

    h = (void *)func_02048A0C(p->f14, 0);
    heap = p->heap;
    m = func_02045B38(0, 2, 0xb0, heap);
    if (c == 0) {
        x = WORDSET_CreateDefault((u16)((heap & 0x7FFF) | 0x8000));
        str = STRBUF_Create(8, (heap & 0x7FFF) | 0x8000);
        y = func_02045EC0(m, c);
        WORDSET_SetSlotMyStatus(x, 0, (void *)s);
        WORDSET_CopyTaggedText(x, str, y);
        STRBUF_Delete(y);
        WORDSET_Delete(x);
    } else {
        y = func_02045EC0(m, c);
        str = STRBUF_Create(0x10, (heap & 0x7FFF) | 0x8000);
        WORDSET_AppendUnpackedString(str, y);
        STRBUF_Delete(y);
    }
    w = 0;
    if (d != 0) {
        z = GF_FONT_Create(0x17, 0, 0, 0, heap);
        w = func_0201D304(str, (u32)z, 0);
        GF_FONT_Delete(z);
        w = 0x3c - w;
        if (w < 0)
            w = 0;
    }
    p->plttRes = ARC_UTIL_LoadPaletteBlockFromArchive(0x17, 5, (u32)(&p->pltt), heap);
    pl = p->pltt->raw;
    pl[1] = 0x7FFF;
    pl[2] = 0;
    TEXT_TEXTURE_LoadTexPlttByName(h, a1, pl, a2, (u32)str, w, 0, 0x440, heap, (struct TexKey *)buf);
    func_020307B0(p->plttRes);
    func_020307B0(str);
    MSGDATA_Delete(m);
}
