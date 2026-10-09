/*
 * file:     unit_021CCAC0.c
 * unit:     yes
 * function: func_021CCAC0, func_021CCBA4, procInit1, procInit2
 * address:  0x021CCAC0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BD1D4   0x021BD1D4  arm  ov016
 *   func_021BD170   0x021BD170  arm  ov016
 *   func_021D4B68   0x021D4B68  arm  ov016
 *   dat_021DA800   0x021DA800  data
 *   dat_021DB778   0x021DB778  data
 *   dat_0207F0B8   0x0207F0B8  data
 *   dat_021DB790   0x021DB790  data
 *   dat_0207E3D0   0x0207E3D0  data
 *   dat_021DB7A8   0x021DB7A8  data
 *   dat_0207EB78   0x0207EB78  data
 *   dat_021DE614   0x021DE614  data
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_BTNlEnable                  0x021BCB84  arm
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_BTNlSet                     0x021BCB28  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_FOCUSlDisp4                 0x021BD4C8  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_IPTlCheckRepeat             0x021D6864  arm
 *   DWCi_IPTlCheckTrigger            0x021D6824  arm
 *   DWCi_SCREENlCopyPalette          0x021CE7B0  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_SceneEnd                    0x021C1630  arm
 *   DWCi_TPlCheckTrigger             0x021D696C  arm
 *   dispPushButton                   0x021C1EDC  arm
 *   endScene                         0x021C1D4C  arm
 *   endScene1                        0x021C1D6C  arm
 *   endScene2                        0x021C1DC4  arm
 *   moveFocus                        0x021C1E70  arm
 *   scenemenu_bss                    0x021DE59C  data
 *   scenemenu_init_20658             0x021DA474  data
 *   scenemenu_rodata                 0x021DA478  data
 *   procScene                        0x021CCC70  arm
 */
#include "../../matched/include/G_SCENEMENU_BSS.h"
#include "../../matched/include/G_SCENEMENU_BSS.h"

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct {
    char name[0x14];
    u8 f14;
    u8 f15;
} T22;

typedef _Bool bool;

typedef struct tagRECT { unsigned short l, t, r, b; } RECT;

/* scenemenu.o .bss at 0x021DE59C, members at their vendor offsets */
typedef struct {
    unsigned char  FocusPos;          /* 0x00 */
    void          *Palette;           /* 0x04 */
} SCENEMENU_BSS;

/* scenemenu.o .rodata at 0x021DA478, members at their vendor offsets */
typedef struct {
    RECT           R_TOUCH[2];        /* 0x00 */
    RECT           R_FOCUS[2];        /* 0x10 */
} SCENEMENU_RODATA;

/* PALETTE's initialiser is the compiler's @20658 in its own .rodata section */
typedef struct { unsigned char v[2]; } PALETTE_INIT;

extern void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
extern unsigned char *func_021BD170(unsigned char *name);
extern void *func_021D4B68(char *path, unsigned long *size, int alignment);
extern void func_021D603C(int lcd, int plane);
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern bool DWCi_EFFlWait(int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_ChangeScene(void (*scene)());
extern void DWCi_CMNlButton(int kind);
extern int DWCi_BTNlGet(void);
extern void DWCi_BTNlEnable(void);
extern void DWCi_BTNlDisable(void);
extern void DWCi_BTNlSet(int idx);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_FOCUSlDisp4(int x0, int x1, int y0, int y1);
extern bool DWCi_TPlCheckTrigger(RECT *r);
extern bool DWCi_IPTlCheckTrigger(unsigned short input);
extern bool DWCi_IPTlCheckRepeat(unsigned short input);
extern void DWCi_SCREENlCopyPalette(void *src, int sColor, int dColor);
extern void DWCi_SceneEnd(void);
void func_021CCAC0(void);
extern T22 dat_021DA800;
extern unsigned char dat_021DB778[];
extern unsigned char dat_0207F0B8[];
extern unsigned char dat_021DB790[];
extern unsigned char dat_0207E3D0[];
extern unsigned char dat_021DB7A8[];
extern unsigned char dat_0207EB78[];
extern unsigned char dat_021DE614[];
extern struct SCENEMENU_BSS scenemenu_bss;
extern const SCENEMENU_RODATA scenemenu_rodata;
extern const PALETTE_INIT scenemenu_init_20658;




/*
 * Copy a 0x16-byte NCL resource path from the static table into a stack
 * buffer, load three tilemaps through func_021BD1D4, publish the buffer
 * through func_021BD170/func_021D4B68 into the 0x021DE614 record, then set
 * the low two bits of the 0x04001008 and 0x0400000A halfword pairs.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CCAC0.c \
 *       --func func_021CCAC0 --addr 0x021CCAC0 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021CCAC0(void)
{
    T22 buf;
    u16 *p;

    buf = dat_021DA800;
    func_021BD1D4((char *)((int)dat_021DB778), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207F0B8));
    func_021BD1D4((char *)((int)dat_021DB790), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207E3D0));
    func_021BD1D4((char *)((int)dat_021DB7A8), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207EB78));
    ((int *)dat_021DE614)[1] = (int)func_021D4B68((char *)((int)func_021BD170((unsigned char *)(&buf))), 0, 4);

    p = (u16 *)0x04001008;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)0x0400000A;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
}




static void procInit1(void);



static void procInit2(void);



static void procScene(void);



static void endScene(void);



static void endScene1(void);



static void endScene2(void);



static void moveFocus(int dir);



static void dispPushButton(void);




static void procInit(void)
{
    DWCi_EFFlFade(2, 1, 1, 8);
    DWCi_EFFlFade(2, 0, 0x14, 8);
    DWCi_GXlVisible(1, 1);
    DWCi_GXlVisible(0, 0x14);
    DWCi_ChangeScene(procInit1);
}



static void procInit1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_CMNlButton(0);
    DWCi_ChangeScene(procInit2);
}


static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2)
        return;
    DWCi_BTNlEnable();
    DWCi_ChangeScene(procScene);
}
