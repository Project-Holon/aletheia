/*
 * function: dispPush
 * address:  0x021CC8C4
 * packet:   pkt_ov016_021CC8C4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SCREENlCopyPalette          0x021ce7b0 arm
 *   DWCi_SETTINGlGetSetType          0x021cf7f4 arm
 *   DWCi_CELLlSetPalette             0x021d5098 arm
 *   g_021DA7B4                      0x021da7b4 data
 *   g_021DA7B8                      0x021da7b8 data
 *   scenesetselectap_bss             0x021de60c data
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetselectap), symbol dispPush (name and prototype from the vendor object DWARF).
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CC8C4.c \
 *       --func dispPush --addr 0x021CC8C4 --region ov016 --cc 1.1p1 --arm --lang c99
 */

/* the compiler's g_021DA7B4and g_021DA7B8initialisers, each in its own .rodata section */
typedef struct { unsigned char v[4]; } PLT4;
extern const PLT4 g_021DA7B4;
extern const PLT4 g_021DA7B8;

/* scenesetselectap.o .bss at 0x021DE60C, members at their vendor offsets */
typedef struct {
    void          *palette;           /* 0x00 */
    void          *cellA[3];          /* 0x04 */
    void          *cellB[3];          /* 0x10 */
    unsigned char  pad0;              /* 0x1C */
    unsigned char  state;             /* 0x1D */
    unsigned char  pad1[2];
} SSSA;                               /* 0x20 */

typedef struct {
    unsigned char  FocusPos;          /* 0x00 */
    SSSA          *MemSssa;           /* 0x04 */
} SCENESETSELECTAP_BSS;
extern SCENESETSELECTAP_BSS scenesetselectap_bss;

extern void DWCi_SCREENlCopyPalette(void *src, int sColor, int dColor);
extern int DWCi_SETTINGlGetSetType(int idx);
extern void DWCi_CELLlSetPalette(void *cell, int idx, int mode, int plt);

static void dispPush(void)
{
    PLT4 PALETTE = g_021DA7B4;
    PLT4 OBJ_PLTT = g_021DA7B8;
    int type = scenesetselectap_bss.FocusPos;

    if ((unsigned int)type > 3) {
        return;
    }
    DWCi_SCREENlCopyPalette(scenesetselectap_bss.MemSssa->palette, PALETTE.v[type], PALETTE.v[type]);
    if (scenesetselectap_bss.FocusPos == 3) {
        return;
    }
    type = DWCi_SETTINGlGetSetType(scenesetselectap_bss.FocusPos);
    if (type > 2) {
        type = 3;
    }
    DWCi_CELLlSetPalette(scenesetselectap_bss.MemSssa->cellA[scenesetselectap_bss.FocusPos], -1, 0, OBJ_PLTT.v[type]);
}
