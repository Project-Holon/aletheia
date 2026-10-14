/*
 * function: DWCi_FNTlEnd
 * address:  0x021D5904
 * packet:   pkt_ov016_021D5904
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_FNTlEnd (libdwcutil.TWL.HYB.a(font.o))
 *
 * symbols:
 *   DWCi_ARClRelease                 0x021D4C68  arm  ov016
 *   DWCi_QUElDelete                  0x021D5450  arm  ov016
 *   DWCi_HEAPlFree_                  0x021D6438  arm  ov016
 *   gFontWork                       0x021DE680  data
 *   gMemFont                  0x021DE680  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct {
    u8 chr[0x18];
    u8 text[0x10];
    void *buf;
    u16 name;
    u8 width;
    u8 height;
} Canvas;

typedef struct {
    u8 font[0x10];
    Canvas canvas[32];
    Canvas bg[2];
    void *unused;
    void *file[2];
    int renew[2];
} MemFont;

extern MemFont *gFontWork;
extern MemFont *gMemFont;
extern void DWCi_ARClRelease(void *file);
extern void DWCi_QUElDelete(void *queue);
extern void DWCi_HEAPlFree_(void **mem);

void DWCi_FNTlEnd(void)
{
    int i;
    for (i = 0; i < 2; i++)
        DWCi_ARClRelease(gFontWork->file[i]);
    DWCi_QUElDelete(gFontWork->unused);
    DWCi_HEAPlFree_((void **)&gMemFont);
}
