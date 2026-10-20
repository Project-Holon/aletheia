/*
 * file:     sceneseteditaddress.c
 * unit:     yes
 * function: DWCi_SceneSetEditAddress, initGraphics, procInit, procInit1, procInit2, DWCi_SceneSetEditAddress_procScene, input, isOver, DWCi_SceneSetEditAddress_draw, endScene, endScene1, endScene2, DWCi_SceneSetEditAddressEndScene3, DWCi_SceneSetEditAddressDrawAddress, DWCi_SceneSetEditAddressDispCaret, DWCi_SceneSetEditAddressProcWin, DWCi_SceneSetEditAddressProcWin1, arrangeAddress, isCorrect, procError, procError1
 * address:  0x021C7088
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
 *   DWCi_CEINlSetExObj                 0x021D5368  arm
 *   DWCi_CMNlStep                      0x021BD214  arm
 *   DWCi_COMMENTlDispEx                0x021BD060  arm
 *   DWCi_ChangeScene                   0x021C0E40  arm
 *   DWCi_FNTlFormBgEx                  0x021D5A58  arm
 *   DWCi_GetParam2_                    0x021C0EA0  arm
 *   DWCi_HEAPlAllocEx                  0x021D6414  arm
 *   DWCi_HLlLoad                       0x021BD674  arm
 *   MI_CpuFill8                        0x02082BCC  arm
 *   sSceneSetEditAddressMessageIds                         0x021DA5E0  data
 *   sSceneSetEditAddressCurrentGetters                         0x021DB4C8  data
 *   sSceneSetEditAddressBlankDigits                         0x021DB4F0  data
 *   gMemSsea                         0x021DE5E4  data
 *   memcmp                             0x020923F0  arm   ov016
 *   DWCi_CMNlLoadResource              0x021BD1D4  arm
 *   DWCi_EFFlFade                      0x021D55A4  arm
 *   DWCi_GXlVisible                    0x021D603C  arm
 *   GX_LoadBG2Char                     0x0207F0B8  arm
 *   GX_LoadBG2Scr                      0x0207EB78  arm
 *   GX_LoadBGPltt                      0x0207E3D0  arm
 *   GX_LoadOBJPltt                     0x0207E51C  arm
 *   sSceneSetEditAddressPathYbObjKbPltt                         0x021DB4F4  data
 *   sSceneSetEditAddressPathJbBgStep3Char                         0x021DB508  data
 *   sSceneSetEditAddressPathYbBgStep3Pltt                         0x021DB520  data
 *   sSceneSetEditAddressPathXb4EditAddrScr                         0x021DB538  data
 *   DWCi_EFFlCheck                     0x021D5580  arm
 *   DWCi_KB10lGet                      0x021BF6E0  arm
 *   DWCi_KB10lInit                     0x021BF390  arm
 *   DWCi_KB10lSetErase                 0x021BF6F4  arm
 *   DWCi_KB10lSetInput                 0x021BF708  arm
 *   DWCi_KB10lSetShift                 0x021BF71C  arm
 *   DWCi_SNDlPlay                      0x021CFFAC  arm
 *   MI_CpuCopy8                        0x02082D44  arm
 *   atoi                               0x020964E0  arm   ov016
 *   DWCi_EFFlWait                      0x021D5790  arm
 *   DWCi_KB10lEnd                      0x021BF6B0  arm
 *   DWC_BACKUPlCheckAddress            0x020588D0  arm
 *   DWCi_COMMENTlDelete                0x021BD138  arm
 *   DWCi_FNTlClear                     0x021D5F14  arm
 *   DWCi_FNTlDeleteBgLcd               0x021D5CA8  arm
 *   DWCi_FNTlDrawRect                  0x021D5E5C  arm
 *   DWCi_FNTlRenewBg                   0x021D5FC4  arm
 *   DWCi_GXlInvisible                  0x021D6090  arm
 *   DWCi_HEAPlFree_                    0x021D6438  arm
 *   DWCi_KB10lIsInit                   0x021BF730  arm
 *   DWCi_OBJlDelete                    0x021D6F38  arm
 *   DWCi_SETTINGlConvAddress           0x021CFE18  arm
 *   DWCi_SceneSetList                  0x021C82FC  arm
 *   DWCi_SetParam2_                    0x021C0E8C  arm
 *   DWCi_SetParam_                     0x021C0E50  arm
 *   DWCi_WINlEnd                       0x021D1524  arm
 *   DWCi_WINlGet                       0x021D1568  arm
 *   DWCi_WINlInitEx                    0x021D1208  arm
 *   DWCi_WINlIsInit                    0x021D157C  arm
 *   sSceneSetEditAddressMaxOctet                         0x021DA5CC  data
 *   sSceneSetEditAddressDigitX                         0x021DA5D4  data
 *   sSceneSetEditAddressOrigin                         0x021DA5E8  data
 *   sSceneSetEditAddressDefaultGetters                         0x021DB4DC  data
 *   sSceneSetEditAddressPathYbObjMainPltt                         0x021DB550  data
 *   sceneseteditaddress_bss            0x021DE5E4  data
 */
#include "../types.h"

typedef _Bool bool;

#include "gx_oam_types.h"

/* gMemSsea: the edit-address scene work area (HEAP block of 0x18 bytes). */
typedef struct MemSsea {
    void *bg;                         /* 0x00 */
    GXOamAttr *caret;                 /* 0x04 */
    u8 digits[12];                    /* 0x08, four groups of three characters */
    u8 cursor;                        /* 0x14 */
    u8 result;                        /* 0x15 */
} MemSsea;

typedef struct AddressGetterTable {
    void (*f[5])(u8 *);
} AddressGetterTable;

typedef struct AddressMessageTable {
    u8 m[5];
} AddressMessageTable;

typedef struct {
    MemSsea *MemSsea;
} SCENESETEDITADDRESS_BSS;

typedef struct tagCOORD {
    u16 x, y;
} COORD;

typedef struct AREA {
    u16 x, y, w, h;
} AREA;

typedef struct AddressLimit {
    u8 c[4];
} AddressLimit;

extern void *DWCi_HEAPlAllocEx(u32 size, int alignment);
extern void DWCi_GetParam2_(u32 *a, u32 *b);
extern int memcmp(unsigned char *s1, unsigned char *s2, unsigned int n);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern void DWCi_HLlLoad(int idx);
extern int DWCi_COMMENTlDispEx(int messageId, int n, int num);
extern void DWCi_CMNlStep(int step);
extern void *DWCi_FNTlFormBgEx(int lcd, int font);
extern GXOamAttr *DWCi_CEINlSetExObj(int lcd, int idx);
extern void DWCi_ChangeScene(u32 v);
extern void DWCi_CMNlLoadResource(char *file, void (*func)(void *, u32, u32));
extern void GX_LoadOBJPltt(void *src, u32 offset, u32 size);
extern void GX_LoadBG2Char(void *src, u32 offset, u32 size);
extern void GX_LoadBGPltt(void *src, u32 offset, u32 size);
extern void GX_LoadBG2Scr(void *src, u32 offset, u32 size);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_KB10lInit(void);
extern u8 DWCi_KB10lGet(void);
extern void DWCi_KB10lSetErase(unsigned char v);
extern void DWCi_KB10lSetInput(unsigned char v);
extern void DWCi_KB10lSetShift(u8 v);
extern void DWCi_SNDlPlay(u32 v);
extern bool DWCi_EFFlCheck(int lcd);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern int atoi(u32 s);
extern void DWCi_KB10lEnd(void);
extern bool DWCi_EFFlWait(int frame);
extern void DWCi_HEAPlFree_(void **mem);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_SetParam2_(unsigned int a, unsigned int b);
extern int DWCi_COMMENTlDelete(void);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
struct Canvas;
extern void DWCi_FNTlClear(struct Canvas *cnv, s32 color);
extern void DWCi_FNTlDrawRect(void *canvas, int x, int y, int w, int h, int color, u32 flag, u16 *txt);
extern void DWCi_FNTlRenewBg(int x);
extern void DWCi_OBJlDelete(unsigned int *obj);
extern int DWCi_KB10lIsInit(void);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
extern s8 DWCi_WINlGet(void);
extern void DWCi_WINlEnd(void);
extern int DWCi_WINlIsInit(void);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_SceneSetList(void);
extern void DWCi_SETTINGlConvAddress(char *adr, unsigned char *buf);
extern int DWC_BACKUPlCheckAddress(u8 *address);
void DWCi_SceneSetEditAddress(void);
void DWCi_SceneSetEditAddress_procScene(void);
void DWCi_SceneSetEditAddress_draw(void);
extern MemSsea *gMemSsea;
extern const AddressGetterTable sSceneSetEditAddressCurrentGetters;
extern const AddressMessageTable sSceneSetEditAddressMessageIds;
extern char sSceneSetEditAddressBlankDigits[];
extern char sSceneSetEditAddressPathYbObjKbPltt[];
extern char sSceneSetEditAddressPathJbBgStep3Char[];
extern char sSceneSetEditAddressPathYbBgStep3Pltt[];
extern char sSceneSetEditAddressPathXb4EditAddrScr[];
/* second symbol of the scene work pointer: DWCi_SceneSetEditAddressEndScene3 frees it through its own pool word */
extern SCENESETEDITADDRESS_BSS sceneseteditaddress_bss;
extern const AddressGetterTable sSceneSetEditAddressDefaultGetters;
extern char sSceneSetEditAddressPathYbObjMainPltt[];
extern const COORD sSceneSetEditAddressOrigin;
extern const u8 sSceneSetEditAddressDigitX[];
extern const AddressLimit sSceneSetEditAddressMaxOctet;

static inline void G2_SetOBJPriority(GXOamAttr *oam, int priority)
{
    oam->attr2 = (u16)((oam->attr2 & ~0xC00) | (priority << 10));
}

static void initGraphics(void);
static void procInit(void);
static void procInit1(void);
static void procInit2(void);
static void input(void);
static int isOver(int limit);
static void endScene(void);
static void endScene1(void);
static void endScene2(void);
static void DWCi_SceneSetEditAddressEndScene3(void);
static void DWCi_SceneSetEditAddressDrawAddress(void);
static void DWCi_SceneSetEditAddressDispCaret(void);
static void DWCi_SceneSetEditAddressProcWin(void);
static void DWCi_SceneSetEditAddressProcWin1(void);
static void arrangeAddress(void);
static int isCorrect(void);
static void procError(void);
static void procError1(void);

void DWCi_SceneSetEditAddress(void)
{
    AddressGetterTable getters = sSceneSetEditAddressCurrentGetters;
    AddressMessageTable messages = sSceneSetEditAddressMessageIds;
    int kind;
    MemSsea *p;

    gMemSsea = DWCi_HEAPlAllocEx(0x18, 4);
    DWCi_GetParam2_((u32 *)&kind, 0);
    getters.f[kind](gMemSsea->digits);
    p = gMemSsea;
    if (memcmp((unsigned char *)p->digits, (unsigned char *)sSceneSetEditAddressBlankDigits, 3) != 0) {
        p->cursor = 3;
    } else {
        MI_CpuFill8(p->digits, 0, 12);
        gMemSsea->cursor = 0;
    }
    initGraphics();
    DWCi_HLlLoad(kind + 0xb);
    DWCi_COMMENTlDispEx(messages.m[kind], -1, 0);
    DWCi_CMNlStep(2);
    gMemSsea->bg = DWCi_FNTlFormBgEx(0, 0);
    gMemSsea->caret = DWCi_CEINlSetExObj(0, 0x3f);
    G2_SetOBJPriority(gMemSsea->caret, 3);
    DWCi_SceneSetEditAddressDispCaret();
    DWCi_SceneSetEditAddressDrawAddress();
    DWCi_ChangeScene((u32)procInit);
}

/*
 * Load the four resources of the scene (object palette, background tiles,
 * background palette, background screen), then set the low two bits of five
 * halfword registers (the 0x04001008/0x04000008 pair and their +2 neighbours).
 */
static void initGraphics(void)
{
    u16 *p;

    DWCi_CMNlLoadResource(sSceneSetEditAddressPathYbObjKbPltt, GX_LoadOBJPltt);
    DWCi_CMNlLoadResource(sSceneSetEditAddressPathJbBgStep3Char, GX_LoadBG2Char);
    DWCi_CMNlLoadResource(sSceneSetEditAddressPathYbBgStep3Pltt, GX_LoadBGPltt);
    DWCi_CMNlLoadResource(sSceneSetEditAddressPathXb4EditAddrScr, GX_LoadBG2Scr);
    p = (u16 *)0x04001008;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)0x04000008;
    p[0] = (p[0] & ~3) | 2;
    p = (u16 *)0x0400000A;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
}

static void procInit(void)
{
    DWCi_EFFlFade(2, 1, 1, 8);
    DWCi_EFFlFade(2, 0, 0x15, 8);
    DWCi_GXlVisible(1, 1);
    DWCi_GXlVisible(0, 0x15);
    DWCi_ChangeScene((u32)procInit1);
}

static void procInit1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_KB10lInit();
    DWCi_SNDlPlay(0x14);
    if (gMemSsea->cursor == 0) {
        DWCi_KB10lSetErase(0);
        DWCi_KB10lSetShift(0);
    } else {
        if (isOver(0x1A))
            DWCi_KB10lSetInput(0);
        DWCi_KB10lSetShift(0);
    }
    DWCi_ChangeScene((u32)procInit2);
}

static void procInit2(void)
{
    if (DWCi_KB10lGet() == 0x1F)
        return;
    DWCi_ChangeScene((u32)DWCi_SceneSetEditAddress_procScene);
}

void DWCi_SceneSetEditAddress_procScene(void)
{
    input();
    DWCi_SceneSetEditAddress_draw();
}

static void input(void)
{
    int key;
    u8 *digits;
    int k;

    key = DWCi_KB10lGet();
    switch (key) {
    case 0:
        return;
    case 0x10:
        if (gMemSsea->cursor == 0 && gMemSsea->digits[2] == 0)
            break;
        DWCi_SNDlPlay(3);
        if (gMemSsea->digits[gMemSsea->cursor * 3 + 2] == 0)
            gMemSsea->cursor--;
        MI_CpuFill8(&gMemSsea->digits[gMemSsea->cursor * 3], 0, 3);
        if (gMemSsea->cursor == 0 && gMemSsea->digits[2] == 0)
            DWCi_KB10lSetErase(0);
        DWCi_KB10lSetInput(1);
        DWCi_KB10lSetShift(0);
        break;
    case 0x11:
        if (gMemSsea->cursor >= 3)
            break;
        if (gMemSsea->digits[gMemSsea->cursor * 3 + 2] == 0)
            break;
        DWCi_SNDlPlay(1);
        gMemSsea->cursor++;
        DWCi_KB10lSetShift(0);
        break;
    case 0x12:
        gMemSsea->result = 0;
        DWCi_SNDlPlay(7);
        DWCi_ChangeScene((u32)endScene);
        return;
    case 0x13:
        if (isCorrect()) {
            DWCi_SNDlPlay(6);
            gMemSsea->result = 1;
        } else {
            gMemSsea->result = 2;
            DWCi_SNDlPlay(9);
        }
        gMemSsea->cursor = 3;
        gMemSsea->caret->attr01 = (gMemSsea->caret->attr01 & 0xC1FFFCFF) | 0x200;
        DWCi_SceneSetEditAddressDispCaret();
        arrangeAddress();
        DWCi_ChangeScene((u32)endScene);
        return;
    default:
        if (gMemSsea->cursor == 3 && isOver(0x1a))
            break;
        DWCi_SNDlPlay(1);
        digits = gMemSsea->digits;
        k = gMemSsea->cursor * 3;
        if (digits[k + 2] == 0) {
            digits[k + 2] = key;
        } else {
            if (digits[k + 1] == 0) {
                digits[k + 1] = digits[k + 2];
                digits[k + 2] = key;
                if (!isOver(0x1a))
                    goto updateKeyboard;
            } else {
                digits[k] = digits[k + 1];
                digits[k + 1] = digits[k + 2];
                digits[k + 2] = key;
            }
            if (gMemSsea->cursor < 3)
                gMemSsea->cursor++;
        }
updateKeyboard:
        DWCi_KB10lSetErase(1);
        if (gMemSsea->cursor < 3)
            DWCi_KB10lSetShift(1);
        else
            DWCi_KB10lSetShift(0);
        if (gMemSsea->cursor == 3 && isOver(0x1a))
            DWCi_KB10lSetInput(0);
        break;
    }
    DWCi_SceneSetEditAddressDrawAddress();
    DWCi_SceneSetEditAddressDispCaret();
}

static int isOver(int limit)
{
    u8 *c;
    u8 buf[4];
    int v;
    int i;

    c = &gMemSsea->digits[gMemSsea->cursor * 3];
    if (*c != 0 && *c != ' ')
        return 1;
    MI_CpuCopy8(c, buf, 3);
    buf[3] = 0;
    for (i = 0; i < 3; i++) {
        if (buf[i] != 0)
            break;
        buf[i] = ' ';
    }
    v = atoi((u32)buf);
    return v >= limit;
}

/* Empty stub: the routine carries no behaviour (see the call sites for why it exists). */
void DWCi_SceneSetEditAddress_draw(void)
{
}

static void endScene(void)
{
    DWCi_EFFlWait(8);
    DWCi_ChangeScene((u32)endScene1);
}

static void endScene1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    DWCi_KB10lEnd();
    DWCi_SNDlPlay(0x15);
    DWCi_ChangeScene((u32)endScene2);
}

static inline void G2_SetOBJPosition(GXOamAttr *oam, int x, int y)
{
    oam->attr01 = (oam->attr01 & 0xFE00FF00) | (y & 0xFF) | ((x & 0x1FF) << 16);
}

static void endScene2(void)
{
    int r;

    if (DWCi_KB10lIsInit())
        return;
    r = gMemSsea->result;
    if (r == 0) {
        DWCi_ChangeScene((u32)DWCi_SceneSetEditAddressEndScene3);
    } else if (r == 2) {
        DWCi_WINlInitEx(6, 3, 1, -1, 0);
        DWCi_ChangeScene((u32)procError);
    } else {
        DWCi_WINlInitEx(0x47, 2, 1, -1, 0);
        DWCi_ChangeScene((u32)DWCi_SceneSetEditAddressProcWin);
    }
}

static void DWCi_SceneSetEditAddressEndScene3(void)
{
    int kind;

    DWCi_COMMENTlDelete();
    DWCi_OBJlDelete((unsigned int *)gMemSsea->caret);
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_CMNlLoadResource(sSceneSetEditAddressPathYbObjMainPltt, GX_LoadOBJPltt);
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x15);
    DWCi_GetParam2_((u32 *)&kind, 0);
    if (kind >= 3)
        kind++;
    DWCi_SetParam_(2, 1);
    DWCi_SetParam2_(0, kind + 3);
    DWCi_ChangeScene((u32)DWCi_SceneSetList);
    DWCi_HEAPlFree_((void **)&sceneseteditaddress_bss);
}

/*
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
 */
static void DWCi_SceneSetEditAddressDrawAddress(void)
{
    AREA a = { sSceneSetEditAddressOrigin.x, sSceneSetEditAddressOrigin.y, 11, 16 };
    int i;
    u16 buf[2];

    a.w = 11;
    a.h = 16;
    DWCi_FNTlClear(gMemSsea->bg, 0);
    buf[1] = 0;
    for (i = 0; i < 12; i++) {
        buf[0] = gMemSsea->digits[i];
        a.x = sSceneSetEditAddressDigitX[i];
        DWCi_FNTlDrawRect(gMemSsea->bg, a.x, a.y, a.w, a.h, 2, 0x480, buf);
    }
    DWCi_FNTlRenewBg((int)gMemSsea->bg);
}

static void DWCi_SceneSetEditAddressDispCaret(void)
{
    int x = gMemSsea->cursor;

    if (x > 3)
        x = 3;
    G2_SetOBJPosition(gMemSsea->caret, sSceneSetEditAddressDigitX[x * 3 + 2], 0x28);
}

static void DWCi_SceneSetEditAddressProcWin(void)
{
    gMemSsea->result = DWCi_WINlGet();
    switch (gMemSsea->result) {
    case 0:
        DWCi_SNDlPlay(7);
        break;
    case 1:
        DWCi_SNDlPlay(0xE);
        break;
    default:
        return;
    }
    DWCi_WINlEnd();
    DWCi_ChangeScene((u32)DWCi_SceneSetEditAddressProcWin1);
}

static void DWCi_SceneSetEditAddressProcWin1(void)
{
    AddressGetterTable getters = sSceneSetEditAddressDefaultGetters;
    int kind;

    if (DWCi_WINlIsInit())
        return;
    if (gMemSsea->result == 0) {
        gMemSsea->caret->attr01 &= 0xC1FFFCFF;
        DWCi_ChangeScene((u32)procInit1);
        return;
    }
    DWCi_GetParam2_((u32 *)&kind, 0);
    getters.f[kind](gMemSsea->digits);
    DWCi_ChangeScene((u32)DWCi_SceneSetEditAddressEndScene3);
}

/*
 * Sanitises four three-byte rows of the address buffer: every leading byte that
 * is NUL, space or '0' becomes a space, except the third column which becomes
 * '0'; the run stops at the first other byte.
 */
static void arrangeAddress(void)
{
    int i;

    for (i = 0; i < 4; i++) {
        u8 *row = gMemSsea->digits + i * 3;
        int j;
        for (j = 0; j < 3; j++) {
            u8 c = row[j];
            if (c != 0x30 && c != 0x20 && c != 0)
                break;
            row[j] = (j == 2) ? 0x30 : 0x20;
        }
    }
    DWCi_SceneSetEditAddressDrawAddress();
}

static int isCorrect(void)
{
    AddressLimit limit = sSceneSetEditAddressMaxOctet;
    u8 *c;
    int kind;
    int i;
    int j;
    u8 buf[4];
    int b;

    for (i = 0; i < 4; i++) {
        c = &gMemSsea->digits[i * 3];
        if (c[0] == ' ')
            continue;
        for (j = 0; j < 3; j++) {
            if (c[j] > limit.c[j])
                return 0;
            if (c[j] < limit.c[j])
                break;
        }
    }
    DWCi_SETTINGlConvAddress((char *)gMemSsea->digits, buf);
    b = 0;
    DWCi_GetParam2_((u32 *)&kind, 0);
    if (kind == 1) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 8; j++) {
                if (b != 0) {
                    if (buf[i] & (1 << (7 - j)))
                        return 0;
                } else {
                    if ((buf[i] & (1 << (7 - j))) == 0)
                        b = 1;
                }
            }
        }
        return 1;
    }
    if (DWC_BACKUPlCheckAddress(buf))
        b = 1;
    return b;
}

static void procError(void)
{
    if (DWCi_WINlGet())
        return;
    DWCi_SNDlPlay(6);
    DWCi_WINlEnd();
    DWCi_ChangeScene((u32)procError1);
}

static void procError1(void)
{
    if (DWCi_WINlIsInit() != 0)
        return;
    gMemSsea->caret->attr01 &= 0xC1FFFCFF;
    DWCi_ChangeScene((u32)procInit1);
}
