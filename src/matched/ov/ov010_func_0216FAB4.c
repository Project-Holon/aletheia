/*
 * function: TEXT_TEXTURE_LoadTexPlttByName
 * address:  0x0216FAB4
 * packet:   pkt_ov010_0216FAB4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Look up a texture and a palette by name in a G3D texture resource,
 * derive their formats from the 7-entry d_021726A0 table, and load them
 * through TEXT_TEXTURE_UploadTextTexture (optionally TEXT_TEXTURE_UploadPalette). One lever: the four
 * stack aggregates declared in reverse of their frame order.
 *
 * symbols:
 *   G3D_SYSTEM_GetResourceTex        0x02047250  arm
 *   STD_GetStringLength  0x0208CC78  arm
 *   NNS_G3dGetResDataByName        0x0206E62C  arm
 *   GF_FONT_Create        0x0201D7EC  thumb
 *   GF_FONT_Delete        0x0201D83C  thumb
 *   TEXT_TEXTURE_UploadTextTexture        0x0216FD54  thumb  ov010
 *   TEXT_TEXTURE_UploadPalette        0x0216FE04  thumb  ov010
 *   d_021726A0           0x021726A0  data
 */
#include "../include/Obj09341.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Res {
    u8 pad00[8];
    u32 f08;            /* 0x08 */
    u8 pad0C[2];
    u16 texDict;        /* 0x0E */
    u8 pad10[0x2C - 0x10];
    u32 f2c;            /* 0x2C */
    u8 pad30[4];
    u16 plttDict;       /* 0x34 */
} Res;

typedef struct Fmt {
    u32 f00;
    u32 tex;            /* 0x04 */
    u32 pltt;           /* 0x08 */
} Fmt;

typedef struct TexKey {
    u16 texFmt;         /* 0x00 */
    u16 plttFmt;        /* 0x02 */
    u32 f04;            /* 0x04 */
    u32 f08;            /* 0x08 */
    u32 texOfs;         /* 0x0C */
    u32 plttOfs;        /* 0x10 */
} TexKey;

typedef struct TexReq {
    u16 texFmt;         /* 0x00 */
    u16 plttFmt;        /* 0x02 */
    u32 f04;            /* 0x04 */
    u32 f08;            /* 0x08 */
    u32 texOfs;         /* 0x0C */
    u32 plttOfs;        /* 0x10 */
    void *font;         /* 0x14 */
} TexReq;

extern Res *G3D_SYSTEM_GetResourceTex(void *p);
extern int STD_GetStringLength(const char *s);
extern void *NNS_G3dGetResDataByName(const void *dict, const char *name);
struct GfFont;
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 GF_FONT_Delete(void *ptr);
extern void TEXT_TEXTURE_UploadTextTexture(char *a, u32 b, u16 c, u16 d, u16 e, u16 f);
extern void TEXT_TEXTURE_UploadPalette(char *p, void *q);
extern const Fmt d_021726A0[];

int TEXT_TEXTURE_LoadTexPlttByName(void *file, const char *texName, void *extra, const char *plttName, u32 a4, u16 a5, u16 a6, u16 a7, u16 heap, TexKey *out)
{
    TexKey key;
    char tn[16];
    char pn[16];
    TexReq req;
    u16 ofs;
    Res *res;
    u16 *e;
    u32 v;
    u32 fmtT;
    u32 fmtP;
    u32 j;
    int i;
    void *font;

    key.texFmt = 6;
    key.plttFmt = 6;
    key.texOfs = 0;
    key.plttOfs = 0;
    res = G3D_SYSTEM_GetResourceTex(file);
    key.f04 = res->f08;
    key.f08 = res->f2c;
    ofs = res->texDict;
    for (i = 0; i < STD_GetStringLength(texName); i++)
        tn[i] = texName[i];
    for (; i < 16; i++)
        tn[i] = 0;
    e = NNS_G3dGetResDataByName((u8 *)res + ofs, tn);
    if (e == 0)
        return 0;
    v = ((struct Obj09341 *)e)->f0;
    key.texOfs = (v & 0xFFFF) << 3;
    fmtT = (v & 0x700000) >> 20;
    fmtP = (v & 0x3800000) >> 23;
    for (j = 0; j < 7; j++) {
        if (fmtT == d_021726A0[j].tex) {
            key.texFmt = j;
            break;
        }
    }
    for (j = 0; j < 7; j++) {
        if (fmtP == d_021726A0[j].pltt) {
            key.plttFmt = j;
            break;
        }
    }
    ofs = res->plttDict;
    for (i = 0; i < STD_GetStringLength(plttName); i++)
        pn[i] = plttName[i];
    for (; i < 16; i++)
        pn[i] = 0;
    e = NNS_G3dGetResDataByName((u8 *)res + ofs, pn);
    if (e == 0)
        return 0;
    if (e[1] == 1)
        return 0;
    key.plttOfs = (e[0] & 0xFFFF) << 3;
    font = GF_FONT_Create(0x17, 0, 0, 0, heap);
    req.texFmt = key.texFmt;
    req.plttFmt = key.plttFmt;
    req.f04 = key.f04;
    req.font = font;
    req.texOfs = key.texOfs;
    req.f08 = key.f08;
    req.plttOfs = key.plttOfs;
    TEXT_TEXTURE_UploadTextTexture((char *)(&req), a4, a5, a6, a7, heap);
    if (extra != 0)
        TEXT_TEXTURE_UploadPalette((char *)(&req), extra);
    GF_FONT_Delete(font);
    if (out != 0)
        *out = key;
    return 1;
}
