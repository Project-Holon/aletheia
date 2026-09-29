/*
 * function: func_021D5C48
 * address:  0x021D5C48
 * packet:   pkt_ov016_021D5C48
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_FNTlDeleteBg (libdwcutil.TWL.HYB.a(font.o))
 *
 * symbols:
 *   DWCi_TSKlDeleteEx                0x021D7744  arm  ov016
 *   G2_GetBG0CharPtr                 0x0207E1F8  arm
 *   MIi_CpuClear16                   0x02082A48  arm
 *   DWCi_HEAPlFree_                  0x021D6438  arm  ov016
 *   g_021DE680                       0x021DE680  data
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

extern MemFont *g_021DE680;
extern void DWCi_TSKlDeleteEx(int a, void *task);
extern void *G2_GetBG0CharPtr(void);
extern void MIi_CpuClear16(u16 data, void *destp, u32 size);
extern void DWCi_HEAPlFree_(void **mem);

void func_021D5C48(void *canvas)
{
    Canvas *cnv = canvas;
    DWCi_TSKlDeleteEx(1, ((void **)cnv)[0x2c / 4]);
    if (cnv == g_021DE680->bg)
        MIi_CpuClear16(0, G2_GetBG0CharPtr(), 0x6000);
    else
        MIi_CpuClear16(0, G2_GetBG0CharPtr(), 0x3000);
    DWCi_HEAPlFree_(&cnv->buf);
}
