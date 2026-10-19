/*
 * function: BTLV_INPUT_CreateBackActor
 * address:  0x02205F88
 * packet:   pkt_ov094_02205F88
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0220A392  0x0220A392  data  ov094  a2
 *   BTLV_INPUT_GetTextBlockSize  0x02204C98  thumb  ov094
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   GF_FONT_GetTextColor  0x0201DE00  thumb
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   WORDSET_SetSlotFromMsgCB  0x0201EF34  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   WORDSET_Delete  0x0201ED04  thumb
 *   CLACT_GetActorImageProxy  0x0204B7C8  arm  arm9
 *   BMP_Create  0x02043678  arm  arm9
 *   BMP_Delete  0x020437AC  arm  arm9
 *   BMP_GetPixels  0x020437D4  arm  arm9
 *   BMP_Clear  0x02043B5C  arm  arm9
 *   STRBUF_Create  0x020457B0  arm  arm9
 *   STRBUF_Delete  0x02045808  arm  arm9
 *   CLACT_CreateActor  0x0204B294  arm  arm9
 *   CLACT_SetActorAnimSeq  0x0204B878  arm  arm9
 *   CLACT_AddActorSurfacePos  0x0204B404  arm  arm9
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm  arm9
 *   MIi_CpuCopy16  0x02082A60  arm  arm9
 */
#include "../include/Obj01384.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef struct Point { s16 x, y; } Point;
typedef struct { int w[9]; } Struct36;
extern const u16 d_0220A392[];
struct Obj;
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
struct Struct36;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Bmp;
struct CharBuf;
struct MsgBank;
struct Obj;
struct Obj020437AC;
struct U16Vec;
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct WordSet;
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void GF_FONT_GetTextColor(u8 *, u8 *, u8 *);
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern void WORDSET_SetSlotFromMsgCB(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
struct StrObj;
extern void BTLV_INPUT_GetTextBlockSize(struct StrObj *a, int b, int *outn, int *outq);
extern void PRINTSYS_Print(void *, s16, s16, void *, void *);
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern void CLACT_GetActorImageProxy(const char *src, struct Struct36 *dst);
extern void MIi_CpuCopy16(const void *, void *, int);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 WORDSET_Delete(struct WordSet *p);
extern void BMP_Delete(struct Obj020437AC *p);

void BTLV_INPUT_CreateBackActor(char *p)
{
    void *str;
    void *msg;
    int font;
    void *bmp;
    Point pos;
    int w;
    int h;
    u8 c[3];
    Struct36 buf;
    char *pixels;
    int i;
    enum { VRAM_BASE = 0x06600000 } vram;

    ((struct Obj01384 *)p)->f21C = CLACT_CreateActor((void *)((struct Obj01384 *)p)->f218, ((struct Obj01384 *)p)->f104, ((struct Obj01384 *)p)->f108, ((struct Obj01384 *)p)->f10C, d_0220A392, 1, ((struct Obj01384 *)p)->f240);
    pos.x = 0x80;
    pos.y = 0x50;
    CLACT_AddActorSurfacePos(((struct Obj01384 *)p)->f21C, (const struct Vec2 *)(&pos), 1);
    CLACT_SetActorAutoAnim(((struct Obj01384 *)p)->f21C, 1);
    CLACT_SetActorAnimSeq(((struct Obj01384 *)p)->f21C, 0x14);
    str = STRBUF_Create(0x10, ((struct Obj01384 *)p)->f240);
    msg = func_02045EC0(((struct Obj01384 *)p)->f5C, 0);
    font = (int)WORDSET_CreateDefault(((struct Obj01384 *)p)->f240);
    bmp = BMP_Create(0xe, 4, 0x20, ((struct Obj01384 *)p)->f240);
    BMP_Clear(bmp, 0);
    GF_FONT_GetTextColor(&c[2], &c[1], &c[0]);
    GF_FONT_SetTextColor(0xe, 0xa, 0);
    WORDSET_SetSlotFromMsgCB((struct WordSet *)font, 0, 0xa5);
    WORDSET_CopyTaggedText((struct WordSet *)font, str, msg);
    BTLV_INPUT_GetTextBlockSize((struct StrObj *)str, (int)(((struct Obj01384 *)p)->f224), &w, &h);
    PRINTSYS_Print(bmp, 0x38 - w / 2, 8, str, ((struct Obj01384 *)p)->f224);
    GF_FONT_SetTextColor(c[2], c[1], c[0]);
    pixels = BMP_GetPixels(bmp);
    CLACT_GetActorImageProxy(((struct Obj01384 *)p)->f21C, (struct Struct36 *)(&buf));
    vram = VRAM_BASE;
    for (i = 0; i < 4; i++) {
        MIi_CpuCopy16(pixels + i * 0x1c0, (void *)(vram + (i * 8 + 0xcd) * 32 + buf.w[2]), 0x100);
        MIi_CpuCopy16(pixels + (i * 0x1c0 + 0x100), (void *)(vram + (i * 4 + 0xed) * 32 + buf.w[2]), 0x80);
        MIi_CpuCopy16(pixels + (i * 0x1c0 + 0x180), (void *)(vram + (i * 2 + 0xfd) * 32 + buf.w[2]), 0x40);
    }
    STRBUF_Delete(str);
    STRBUF_Delete(msg);
    WORDSET_Delete((struct WordSet *)font);
    BMP_Delete(bmp);
}
