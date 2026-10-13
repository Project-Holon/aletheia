/*
 * function: DWCi_FNTlInit
 * address:  0x021D5824
 * packet:   pkt_ov016_021D5824
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_FNTlInit (libdwcutil.TWL.HYB.a(font.o))
 *
 * symbols:
 *   DWCi_HEAPlAllocEx                0x021D6414  arm  ov016
 *   DWCi_QUElFormEx                  0x021D5410  arm  ov016
 *   DWCi_Language                    0x021C0EC8  arm  ov016
 *   DWCi_ARClReadEx                  0x021D4B68  arm  ov016
 *   NNS_G2dFontInitUTF16             0x02067F78  arm
 *   gFontWork                       0x021DE680  data
 *   sFontTable4                       0x021DBFE4  data
 *   sFontTable5                       0x021DBFEC  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct {
    u8 pad[7];
    u8 type;
} FGlyph;

typedef struct {
    u32 pad[2];
    FGlyph *glyph;
} FRes;

typedef struct {
    FRes *res;
    void *pad;
} Font;

typedef struct {
    void *pCanvas;
    Font *pFont;
    int hSpace;
    int vSpace;
} TextCanvas;

typedef struct {
    void *pad;
    void (*pfnClear)(void *cnv, int color);
} CharFmt;

typedef struct {
    u8 chr0[0x14];
    CharFmt *pFmt;
    TextCanvas text;
    void *buf;
    u16 name;
    u8 width;
    u8 height;
} Canvas;

typedef struct {
    Font font[2];
    Canvas canvas[32];
    Canvas bg[2];
    void *unused;
    void *file[2];
    u8 renew[2];
} MemFont;

extern MemFont *gFontWork;
extern void *DWCi_HEAPlAllocEx(u32 size, int alignment);
extern void *DWCi_QUElFormEx(long size, void *data, long dataSize);
extern int DWCi_Language(void);
extern void *DWCi_ARClReadEx(char *path, u32 *size, int alignment);
extern void NNS_G2dFontInitUTF16(void *font, void *res);
extern char *sFontTable4[2];
extern char *sFontTable5[2];

void DWCi_FNTlInit(void)
{
    int i;
    gFontWork = DWCi_HEAPlAllocEx(0x680, 4);
    gFontWork->unused = DWCi_QUElFormEx(32, gFontWork->canvas, 48);
    if (DWCi_Language() == 6) {
        for (i = 0; i < 2; i++) {
            gFontWork->file[i] = DWCi_ARClReadEx(sFontTable4[i], 0, 4);
            NNS_G2dFontInitUTF16(&gFontWork->font[i], gFontWork->file[i]);
        }
    } else {
        for (i = 0; i < 2; i++) {
            gFontWork->file[i] = DWCi_ARClReadEx(sFontTable5[i], 0, 4);
            NNS_G2dFontInitUTF16(&gFontWork->font[i], gFontWork->file[i]);
        }
    }
}
