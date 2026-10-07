/*
 * function: endScene2
 * address:  0x021C8F20
 * packet:   pkt_ov016_021C8F20
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_ARClRelease                 0x021D4C68  arm
 *   DWCi_BACKUPlConvMaskCidr         0x020587F8  arm
 *   DWCi_CMNlLoadResource            0x021BD1D4  arm
 *   DWCi_COMMENTlDelete              0x021BD138  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_FNTlDeleteBgLcd             0x021D5CA8  arm
 *   DWCi_FOCUSlDelete                0x021BD5A8  arm
 *   DWCi_GXlInvisible                0x021D6090  arm
 *   DWCi_HEAPlFree_                  0x021D6438  arm
 *   DWCi_OBJlDelete                  0x021D6F38  arm
 *   DWCi_SBlEnd                      0x021CE94C  arm
 *   DWCi_SCREENlEnd                  0x021CE6C4  arm
 *   DWCi_SETTIGNlGet                 0x021CF404  arm
 *   DWCi_SETTINGlSetSetting          0x021CF80C  arm
 *   DWCi_SceneSetEdit32              0x021C6588  arm
 *   DWCi_SceneSetEditAddress         0x021C7088  arm
 *   DWCi_SceneSetListSave            0x021CA5D0  arm
 *   DWCi_SceneSetSelectAp            0x021CBC90  arm
 *   DWCi_SceneSetSelectWay           0x021CC998  arm
 *   DWCi_SceneSetTest                0x021CD160  arm
 *   DWCi_SetParam2_                  0x021C0E8C  arm
 *   DWCi_SetParam_                   0x021C0E50  arm
 *   DWCi_TSKlDeleteEx                0x021D7744  arm
 *   GX_LoadOBJPltt                   0x0207E51C  arm
 *   MI_CpuFill8                      0x02082BCC  arm
 *   scenesetlist_bss                 0x021DE5EC  data
 *   scenesetlist_str_21900           0x021DB5D8  data
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetlist.o), symbol endScene2 (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021C8F20.c \
 *       --func endScene2 --addr 0x021C8F20 --region ov016 --cc 1.1p1 --arm
 */

#include "../include/G_SCENESETLIST_BSS.h"

typedef _Bool bool;

typedef struct tagRECT { unsigned short l, t, r, b; } RECT;
typedef struct tagAREA { unsigned short l, t, w, h; } AREA;
typedef struct { unsigned long attr01; unsigned short attr2; unsigned short _3; } GXOamAttr;

typedef struct NCFGApInfo {
    unsigned char  ispId[32];         /* 0x00 */
    unsigned char  ispPass[32];       /* 0x20 */
    unsigned char  ssid[2][32];       /* 0x40 */
    unsigned char  wep[4][16];        /* 0x80 */
    unsigned char  ip[4];             /* 0xC0 */
    unsigned char  gateway[4];        /* 0xC4 */
    unsigned char  dns[2][4];         /* 0xC8 */
    unsigned char  netmask;           /* 0xD0 */
    unsigned char  wep2[4][5];        /* 0xD1 */
    unsigned char  authType;          /* 0xE5 */
    unsigned char  wepMode : 2;       /* 0xE6 */
    unsigned char  wepNotation : 6;   /* 0xE6 */
    unsigned char  setType;           /* 0xE7 */
    unsigned char  ssidLength[2];     /* 0xE8 */
    unsigned short mtu;               /* 0xEA */
    unsigned char  rsv[2];            /* 0xEC */
    unsigned char  flags;             /* 0xEE */
    unsigned char  state;             /* 0xEF */
} NCFGApInfo;

typedef struct tagSETTINGINFO {
    NCFGApInfo     ap;                /* 0x00 */
    unsigned char  netmask[4];        /* 0xF0 */
    unsigned char  idx;               /* 0xF4 */
    bool           ipAuto;            /* 0xF5 */
    bool           dnsAuto;           /* 0xF6 */
} SETTINGINFO;

typedef struct tagPUSH { void *task; unsigned char count[4]; } PUSH;

typedef struct tagMEMSSL {
    PUSH           push;              /* 0x00 */
    void          *back;              /* 0x08 */
    void          *pltt[2];           /* 0x0C */
    void          *canv;              /* 0x14 */
    GXOamAttr     *obj[7];            /* 0x18 */
    GXOamAttr     *icon;              /* 0x34 */
    void          *task;              /* 0x38 */
    void          *taskV;             /* 0x3C */
    unsigned char  choose;            /* 0x40 */
    unsigned char  disp;              /* 0x41 */
    unsigned char  focusLast;         /* 0x42 */
    unsigned char  lastDns;           /* 0x43 */
    bool           renew;             /* 0x44 */
    bool           scroll;            /* 0x45 */
    bool           sound[2];          /* 0x46 */
} MEMSSL;

/* scenesetlist.o .bss at 0x021DE5EC, members at their vendor offsets */
typedef struct {
    unsigned char  Focus;             /* 0x00 */
    unsigned char  RetScene;          /* 0x01 */
    unsigned char  FocusClm;          /* 0x02 */
    unsigned short Pos;               /* 0x04 */
    MEMSSL        *MemSsl;            /* 0x08 */
} SCENESETLIST_BSS;
extern struct SCENESETLIST_BSS scenesetlist_bss;

/* scenesetlist.o .rodata at 0x021DA61C, members at their vendor offsets */
typedef struct {
    unsigned char  PALETTE_NUM[3];    /* 0x00 */
    signed char    MSG_IDX[7];        /* 0x03 */
    AREA           A_EDIT;            /* 0x0A */
    AREA           A_NO;              /* 0x12 */
    AREA           A_YES;             /* 0x1A */
    unsigned char  CLM2FCS_TBL[9];    /* 0x22 */
    unsigned char  OFS_BACK[9];       /* 0x2B */
    unsigned char  FCS2CLM_TBL[11];   /* 0x34 */
    unsigned char  CELL_IDX[5][3];    /* 0x3F */
    unsigned short BACK_POS[9];       /* 0x4E */
    RECT           R_BUTTON[3];       /* 0x60 */
    RECT           R_FOCUS[6];        /* 0x78 */
} SCENESETLIST_RODATA;
extern const SCENESETLIST_RODATA scenesetlist_rodata;

extern bool DWCi_EFFlCheck(int lcd);
extern void DWCi_TSKlDeleteEx(int kind, void *task);
extern void DWCi_OBJlDelete(GXOamAttr *obj);
extern void DWCi_SBlEnd(void);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
extern void DWCi_FOCUSlDelete(void);
extern bool DWCi_COMMENTlDelete(void);
extern void DWCi_SCREENlEnd(void);
extern void DWCi_ARClRelease(void *file);
extern void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_SetParam2_(void *param2, void *param3);
extern void DWCi_SetParam_(void *param0, void *param1);
extern SETTINGINFO *DWCi_SETTIGNlGet(void);
extern unsigned char DWCi_BACKUPlConvMaskCidr(unsigned char *mask);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void DWCi_SETTINGlSetSetting(int idx);
extern void DWCi_ChangeScene(void (*scene)());
extern void DWCi_HEAPlFree_(void **mem);
extern void GX_LoadOBJPltt(void *src, unsigned long offset, unsigned long size);
extern void DWCi_SceneSetEdit32(void);
extern void DWCi_SceneSetEditAddress(void);
extern void DWCi_SceneSetTest(void);
extern void DWCi_SceneSetListSave(void);
extern void DWCi_SceneSetSelectAp(void);
extern void DWCi_SceneSetSelectWay(void);
extern char scenesetlist_str_21900[];

void endScene2(void)
{
    SETTINGINFO *info;
    int ix;
    int i;

    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_TSKlDeleteEx(0, ((MEMSSL *)scenesetlist_bss.MemSsl)->push.task);
    DWCi_TSKlDeleteEx(1, ((MEMSSL *)scenesetlist_bss.MemSsl)->taskV);
    for (i = 0; i < 7; i++)
        DWCi_OBJlDelete(((MEMSSL *)scenesetlist_bss.MemSsl)->obj[i]);
    if (((MEMSSL *)scenesetlist_bss.MemSsl)->icon)
        DWCi_OBJlDelete(((MEMSSL *)scenesetlist_bss.MemSsl)->icon);
    DWCi_SBlEnd();
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_FOCUSlDelete();
    if (((MEMSSL *)scenesetlist_bss.MemSsl)->choose != 12)
        DWCi_COMMENTlDelete();
    DWCi_SCREENlEnd();
    DWCi_ARClRelease(((MEMSSL *)scenesetlist_bss.MemSsl)->back);
    for (i = 0; i < 2; i++)
        DWCi_ARClRelease(((MEMSSL *)scenesetlist_bss.MemSsl)->pltt[i]);
    DWCi_CMNlLoadResource(scenesetlist_str_21900, GX_LoadOBJPltt);
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x1D);
    *(volatile unsigned long *)0x04000010 = 0;
    *(volatile unsigned long *)0x04000018 = 0;
    *(volatile unsigned short *)0x0400000C = (unsigned short)((*(volatile unsigned short *)0x0400000C & 0x43) | 0xE10);
    switch (((MEMSSL *)scenesetlist_bss.MemSsl)->choose) {
    case 0:
    case 1:
        DWCi_SetParam2_((void *)((MEMSSL *)scenesetlist_bss.MemSsl)->choose, 0);
        DWCi_SetParam_((void *)2, 0);
        DWCi_ChangeScene(DWCi_SceneSetEdit32);
        break;
    case 4:
    case 5:
    case 6:
    case 9:
    case 10:
        ix = ((MEMSSL *)scenesetlist_bss.MemSsl)->choose - 4;
        if (((MEMSSL *)scenesetlist_bss.MemSsl)->choose >= 9)
            ix -= 2;
        DWCi_SetParam_((void *)2, 0);
        DWCi_SetParam2_((void *)ix, 0);
        DWCi_ChangeScene(DWCi_SceneSetEditAddress);
        break;
    case 11:
        info = DWCi_SETTIGNlGet();
        info->ap.netmask = DWCi_BACKUPlConvMaskCidr(info->netmask);
        if (info->ipAuto) {
            MI_CpuFill8(info->ap.ip, 0, 4);
            MI_CpuFill8(info->ap.gateway, 0, 4);
            MI_CpuFill8(info->netmask, 0, 4);
            info->ap.netmask = 0;
        }
        if (info->dnsAuto)
            MI_CpuFill8(info->ap.dns, 0, 8);
        DWCi_SetParam_((void *)2, 0);
        DWCi_SetParam2_(0, 0);
        DWCi_ChangeScene(DWCi_SceneSetTest);
        break;
    case 12:
        DWCi_SetParam_(0, 0);
        DWCi_ChangeScene(DWCi_SceneSetListSave);
        break;
    case 13:
        if (scenesetlist_bss.RetScene == 0) {
            DWCi_SetParam_((void *)2, (void *)1);
            DWCi_ChangeScene(DWCi_SceneSetSelectAp);
        } else {
            DWCi_SETTINGlSetSetting(DWCi_SETTIGNlGet()->idx);
            DWCi_SetParam_(0, (void *)1);
            DWCi_ChangeScene(DWCi_SceneSetSelectWay);
        }
        break;
    }
    DWCi_HEAPlFree_((void **)&scenesetlist_bss.MemSsl);
}
