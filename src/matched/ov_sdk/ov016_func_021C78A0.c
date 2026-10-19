/*
 * function: DWCi_SceneSetEditAddressDrawAddress
 * address:  0x021C78A0
 * packet:   pkt_ov016_021C78A0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      drawAddress (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 *
 * Draws the 12-character edit-address field: one 12x16 area whose y/w/h come
 * from an AREA built before the first call, then a per-character blit.
 *
 * The AREA must be aggregate-initialised: `AREA a = { sSceneSetEditAddressOrigin.x,
 * sSceneSetEditAddressOrigin.y, 11, 16 };`.  That is what keeps `a` memory-resident (fields
 * reloaded from the stack frame per iteration, exactly like the object); the
 * same four field assignments written as statements get the struct promoted
 * to registers and the function compiles 28 bytes short.  The two redundant
 * stores that follow the initialiser are dead (1.1p1 removes them) but they
 * change the schedule of the initialiser stores into the object's x,y,w,h
 * order and are required for EXACT; drop either one and the row goes back to
 * 142+ concrete bytes.
 *
 * symbols:
 *   DWCi_FNTlClear  0x021D5F14  arm  ov016
 *   DWCi_FNTlDrawRect  0x021D5E5C  arm  ov016
 *   DWCi_FNTlRenewBg  0x021D5FC4  arm  ov016
 *   gMemSsea     0x021DE5E4  data
 *   sSceneSetEditAddressOrigin     0x021DA5E8  data
 *   sSceneSetEditAddressDigitX     0x021DA5D4  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021C78A0.c \
 *       --func DWCi_SceneSetEditAddressDrawAddress --addr 0x021C78A0 --region ov016 --cc 1.1p1 --arm --lang c99
 */

typedef struct COORD {
    unsigned short x, y;
} COORD;

typedef struct AREA {
    unsigned short x, y, w, h;
} AREA;

typedef struct MemSsea {
    int bg;
    unsigned char pad0[4];
    unsigned char text[12];
} MemSsea;

extern void DWCi_FNTlClear();
typedef unsigned short u16;
typedef unsigned int   u32;
extern void DWCi_FNTlDrawRect(void *canvas, int x, int y, int w, int h, int color, u32 flag, u16 *txt);
extern void DWCi_FNTlRenewBg(int x);
extern MemSsea *gMemSsea;
extern COORD sSceneSetEditAddressOrigin;
extern unsigned char sSceneSetEditAddressDigitX[];

void DWCi_SceneSetEditAddressDrawAddress(void)
{
    AREA a = { sSceneSetEditAddressOrigin.x, sSceneSetEditAddressOrigin.y, 11, 16 };
    int i;
    unsigned short buf[2];

    a.w = 11;
    a.h = 16;
    DWCi_FNTlClear(gMemSsea->bg, 0);
    buf[1] = 0;
    for (i = 0; i < 12; i++) {
        buf[0] = gMemSsea->text[i];
        a.x = sSceneSetEditAddressDigitX[i];
        DWCi_FNTlDrawRect((void *)gMemSsea->bg, a.x, a.y, a.w, a.h, 2, 0x480, buf);
    }
    DWCi_FNTlRenewBg(gMemSsea->bg);

}
