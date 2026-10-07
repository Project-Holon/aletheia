/*
 * function: func_021C2B00
 * address:  0x021C2B00
 * packet:   pkt_ov016_021C2B00
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      initGraphics (libdwcutil.TWL.HYB.a(sceneoptmenu.o))
 *
 * symbols:
 *   func_021BD1D4  0x021BD1D4  arm  ov016
 *   func_021BD170  0x021BD170  arm  ov016
 *   func_021D4B68  0x021D4B68  arm  ov016
 *   func_02058518  0x02058518  arm
 *   func_02082D44  0x02082D44  arm
 *   func_020862F0  0x020862F0  arm
 *   GX_LoadBGPltt  0x0207E3D0  arm
 *   func_021D4C68  0x021D4C68  arm  ov016
 *   GX_LoadBG2Char 0x0207F0B8  arm
 *   GX_LoadBG2Scr  0x0207EB78  arm
 *   g_021DE5A8     0x021DE5A8  data
 *   @20575         0x021DA4E8  data
 *   @20577         0x021DA500  data
 *   @20751         0x021DB338  data
 *   @20752         0x021DB350  data
 */

#include "../../../matched/include/G_FocusPosT.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef unsigned long long u64;
typedef volatile u16 vu16;

typedef struct tagDWCWiFiInfo {
    u64 attestedUserId;
    u64 notAttestedId;
    u16 pass;
    u16 randomHistory;
} DWCWiFiInfo;

typedef struct {
    u8 idx;
    u8 flag;
    u8 pad[2];
    void *ptr;
} FocusPosT;

extern void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
extern unsigned char *func_021BD170(unsigned char *name);
extern void *func_021D4B68(char *path, u32 *size, int alignment);
extern void func_02058518(DWCWiFiInfo *buf);
extern void func_02082D44(const void *srcp, void *dstp, u32 size);
extern void func_020862F0(const void *startAddr, u32 nBytes);
extern void GX_LoadBGPltt(const void *pSrc, u32 offset, u32 szByte);
extern void func_021D4C68(void *file);
extern void GX_LoadBG2Char(const void *pSrc, u32 offset, u32 szByte);
extern void GX_LoadBG2Scr(const void *pSrc, u32 offset, u32 szByte);
extern struct FocusPosT g_021DE5A8;

#define BG_PRIORITY_3(reg) (*(vu16 *)(reg) = (u16)((*(vu16 *)(reg) & ~3) | 3))

void func_021C2B00(void)
{
    char PLLT0[] = "char/ybBgOption.ncl.l";
    char PLLT1[] = "char/ybBgOption1.ncl.l";
    u8 *src;
    u8 *dst;
    char *n;
    DWCWiFiInfo info;
    int i;
    u8 *pltt;

    func_021BD1D4("char/jbBgOption.ncg.l", (void (*)(void *, long unsigned int,  long unsigned int))GX_LoadBG2Char);
    func_021BD1D4("char/jb5OptMenu.nsc.l", (void (*)(void *, long unsigned int,  long unsigned int))GX_LoadBG2Scr);
    n = (char *)func_021BD170((unsigned char *)PLLT1);
    g_021DE5A8.ptr = func_021D4B68(n, 0, 4);
    n = (char *)func_021BD170((unsigned char *)PLLT0);
    pltt = func_021D4B68(n, 0, 4);
    func_02058518(&info);
    if (info.attestedUserId == 0) {
        src = pltt + 0xc0;
        dst = pltt + 0x40;
        for (i = 0; i < 2; i++) {
            func_02082D44(src, dst, 0x20);
            src += 0x20;
            dst += 0x20;
        }
    }
    func_020862F0(pltt, 0x200);
    GX_LoadBGPltt(pltt, 0, 0x200);
    func_021D4C68(pltt);
    BG_PRIORITY_3(0x04001008);
    BG_PRIORITY_3(0x0400100a);
    BG_PRIORITY_3(0x0400000a);
    BG_PRIORITY_3(0x0400000c);
}
