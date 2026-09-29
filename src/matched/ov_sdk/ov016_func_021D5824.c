/*
 * function: func_021D5824
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
 *   g_021DE680                       0x021DE680  data
 *   g_021DBFE4                       0x021DBFE4  data
 *   g_021DBFEC                       0x021DBFEC  data
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

extern MemFont *g_021DE680;
extern void *DWCi_HEAPlAllocEx(u32 size, int alignment);
extern void *DWCi_QUElFormEx(long size, void *data, long dataSize);
extern int DWCi_Language(void);
extern void *DWCi_ARClReadEx(char *path, u32 *size, int alignment);
extern void NNS_G2dFontInitUTF16(void *font, void *res);
extern char *g_021DBFE4[2];
extern char *g_021DBFEC[2];

void func_021D5824(void)
{
    int i;
    g_021DE680 = DWCi_HEAPlAllocEx(0x680, 4);
    g_021DE680->unused = DWCi_QUElFormEx(32, g_021DE680->canvas, 48);
    if (DWCi_Language() == 6) {
        for (i = 0; i < 2; i++) {
            g_021DE680->file[i] = DWCi_ARClReadEx(g_021DBFE4[i], 0, 4);
            NNS_G2dFontInitUTF16(&g_021DE680->font[i], g_021DE680->file[i]);
        }
    } else {
        for (i = 0; i < 2; i++) {
            g_021DE680->file[i] = DWCi_ARClReadEx(g_021DBFEC[i], 0, 4);
            NNS_G2dFontInitUTF16(&g_021DE680->font[i], g_021DE680->file[i]);
        }
    }
}
