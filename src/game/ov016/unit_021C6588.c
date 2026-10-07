/*
 * file:     unit_021C6588.c
 * unit:     yes
 * function: func_021C6588, func_021C66A8, func_021C6764, func_021C67CC, func_021C684C
 * address:  0x021C6588
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
 *   DWCi_CEINlSetExObj               0x021D5368  arm
 *   DWCi_CMNlLoadResource            0x021BD1D4  arm
 *   DWCi_CMNlStep                    0x021BD214  arm
 *   DWCi_COMMENTlDelete              0x021BD138  arm
 *   DWCi_COMMENTlDispEx              0x021BD060  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_FNTlClear                   0x021D5F14  arm
 *   DWCi_FNTlDeleteBgLcd             0x021D5CA8  arm
 *   DWCi_FNTlDrawRect                0x021D5E5C  arm
 *   DWCi_FNTlFormBgEx                0x021D5A58  arm
 *   DWCi_FNTlRenewBg                 0x021D5FC4  arm
 *   DWCi_GXlInvisible                0x021D6090  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_GetParam2_                  0x021C0EA0  arm
 *   DWCi_HEAPlAllocEx                0x021D6414  arm
 *   DWCi_HEAPlFree_                  0x021D6438  arm
 *   DWCi_HLlLoad                     0x021BD674  arm
 *   DWCi_KB10lEnd                    0x021BF6B0  arm
 *   DWCi_KBlEnd                      0x021BDC24  arm
 *   DWCi_KBlGet                      0x021BDC54  arm
 *   DWCi_KBlIsInit                   0x021BDC90  arm
 *   DWCi_KBlSetErase                 0x021BDC68  arm
 *   DWCi_KBlSetInput                 0x021BDC7C  arm
 *   DWCi_OBJlDelete                  0x021D6F38  arm
 *   DWCi_SETTINGlGetSsid             0x021CF684  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_STRlNLen                    0x021D7200  arm
 *   DWCi_SceneSetApList              0x021C50D4  arm
 *   DWCi_SceneSetList                0x021C82FC  arm
 *   DWCi_SceneSetTestConfirm         0x021CD80C  arm
 *   DWCi_SetParam2_                  0x021C0E8C  arm
 *   DWCi_SetParam_                   0x021C0E50  arm
 *   DWCi_WINlEnd                     0x021D1524  arm
 *   DWCi_WINlGet                     0x021D1568  arm
 *   DWCi_WINlInitEx                  0x021D1208  arm
 *   DWCi_WINlIsInit                  0x021D157C  arm
 *   GX_LoadOBJPltt                   0x0207E51C  arm
 *   MemSse                           0x021DE5E0  data
 *   X_IPT                            0x021DA5B2  data
 *   Y_IPT                            0x021DA5AC  data
 *   dispCaret                        0x021C6D24  arm
 *   drawSsid                         0x021C6C30  arm
 *   endScene                         0x021C6A10  arm
 *   endScene1                        0x021C6A2C  arm
 *   endScene2                        0x021C6A5C  arm
 *   endScene3                        0x021C6B30  arm
 *   initGraphics                     0x021C66A8  arm
 *   input                            0x021C687C  arm
 *   isCorrect                        0x021C6E90  arm
 *   procError                        0x021C7018  arm
 *   procError1                       0x021C7044  arm
 *   procInit1                        0x021C67CC  arm
 *   procScene                        0x021C686C  arm
 *   procWin                          0x021C6D8C  arm
 *   procWin1                         0x021C6DE4  arm
 *   scenesetedit32_bss               0x021DE5E0  data
 *   scenesetedit32_init_20570        0x021DA5A8  data
 *   scenesetedit32_init_20639        0x021DA5C4  data
 *   scenesetedit32_init_20694        0x021DB450  data
 *   scenesetedit32_str_20937         0x021DB4B0  data
 *   func_021BD1D4   0x021BD1D4  arm  ov016
 *   dat_021DB458    0x021DB458  data
 *   dat_0207E51C    0x0207E51C  data
 *   dat_021DB46C    0x021DB46C  data
 *   dat_0207F0B8    0x0207F0B8  data
 *   dat_021DB484    0x021DB484  data
 *   dat_0207E3D0    0x0207E3D0  data
 *   dat_021DB49C    0x021DB49C  data
 *   dat_0207EB78    0x0207EB78  data
 *   func_021D5580  0x021D5580  arm
 *   func_021BD8D8  0x021BD8D8  arm
 *   func_021CFFAC  0x021CFFAC  arm
 *   func_021BDC68  0x021BDC68  arm
 *   func_021BDC7C  0x021BDC7C  arm
 *   func_021C0E40  0x021C0E40  arm
 *   g_021DE5E0     0x021DE5E0  data
 *   func_021C684C  0x021C684C  arm
 */
typedef _Bool bool;

/* scenesetedit32.o was built with plain char unsigned (ldrb and unsigned compares on
   the DWARF `char` data): every DWARF `char` below is written `unsigned char`. */

typedef struct tagAREA { unsigned short l, t, w, h; } AREA;

typedef struct { unsigned long attr01; unsigned short attr2; unsigned short _3; } GXOamAttr;

typedef struct tagMEMSSE {
    void          *canv;              /* 0x00 */
    GXOamAttr     *caret;             /* 0x04 */
    unsigned char  ssid[33];          /* 0x08 */
    unsigned char  pos;               /* 0x29 */
    unsigned char  choose;            /* 0x2A */
} MEMSSE;

typedef struct { MEMSSE *MemSse; } SCENESETEDIT32_BSS;

/* the local initialisers, the compiler's @NNNNN objects, copied by struct assignment */
typedef struct { unsigned char v[2]; } SSE_MSG2;

typedef struct { int v[2]; } SSE_MSG;

typedef struct { void (*v[2])(unsigned char *); } SSE_FUNC;

typedef unsigned short u16;

typedef unsigned char u8;

extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void DWCi_HEAPlFree_(void **mem);
extern void DWCi_GetParam2_(void **param2, void **param3);
extern void DWCi_SetParam_(void *param0, void *param1);
extern void DWCi_SetParam2_(void *param2, void *param3);
extern void DWCi_SETTINGlGetSsid(unsigned char *buf);
extern int DWCi_STRlNLen(unsigned char *s, int maxlen);
extern void DWCi_HLlLoad(int idx);
extern bool DWCi_COMMENTlDispEx(int messageId, int n, int num);
extern bool DWCi_COMMENTlDelete(void);
extern void DWCi_CMNlStep(int step);
extern void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern void GX_LoadOBJPltt(void *src, unsigned long offset, unsigned long size);
extern void *DWCi_FNTlFormBgEx(int lcd, int font);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
extern void DWCi_FNTlClear(void *canvas, int color);
extern void DWCi_FNTlDrawRect(void *canvas, int x, int y, int w, int h, int color, unsigned long flag, unsigned short *txt);
extern void DWCi_FNTlRenewBg(void *canvas);
extern GXOamAttr *DWCi_CEINlSetExObj(int lcd, int idx);
extern void DWCi_OBJlDelete(GXOamAttr *obj);
extern int DWCi_KBlGet(void);
extern void DWCi_KBlSetErase(bool enable);
extern void DWCi_KBlSetInput(bool enable);
extern void DWCi_KBlEnd(void);
extern void DWCi_KB10lEnd(void);
extern bool DWCi_KBlIsInit(void);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
extern int DWCi_WINlGet(void);
extern void DWCi_WINlEnd(void);
extern bool DWCi_WINlIsInit(void);
extern void DWCi_SNDlPlay(int no);
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_ChangeScene(void (*scene)());
extern void DWCi_SceneSetList(void);
extern void DWCi_SceneSetApList(void);
extern void DWCi_SceneSetTestConfirm(void);
extern void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
extern int  func_021D5580(int x);
extern void func_021BD8D8(void);
extern void func_021CFFAC(unsigned int v);
extern void func_021BDC68(unsigned char v);
extern void func_021BDC7C(unsigned char v);
extern void func_021C0E40(unsigned int v);
extern void func_021C684C(void);
void DWCi_SceneSetEdit32(void);
void func_021C66A8(void);
void func_021C67CC(void);
/* scenesetedit32.o .bss at 0x021DE5E0, its only member the file static MemSse. The object
   reaches a static through the section symbol, and takes &MemSse through the variable's own
   symbol (a second pool word): endScene3 reads through the section and frees &MemSse. */
extern MEMSSE *MemSse;
extern SCENESETEDIT32_BSS scenesetedit32_bss;
/* scenesetedit32.o .rodata */
extern const unsigned char Y_IPT[2];
extern const unsigned char X_IPT[16];
extern const SSE_MSG2 scenesetedit32_init_20570;
extern const SSE_MSG scenesetedit32_init_20639;
extern const SSE_FUNC scenesetedit32_init_20694;
extern char scenesetedit32_str_20937[];
extern unsigned short dat_021DB458[];
extern unsigned short dat_0207E51C[];
extern unsigned short dat_021DB46C[];
extern unsigned short dat_0207F0B8[];
extern unsigned short dat_021DB484[];
extern unsigned short dat_0207E3D0[];
extern unsigned short dat_021DB49C[];
extern unsigned short dat_0207EB78[];
extern u8  *g_021DE5E0;


static void initGraphics(void);

static void procInit(void);

static void procInit1(void);

static void procInit2(void);

static void procScene(void);

static void input(void);

static void endScene(void);

static void endScene1(void);

static void endScene2(void);

static void endScene3(void);

static void drawSsid(void);

static void dispCaret(void);

static void procWin(void);

static void procWin1(void);

static bool isCorrect(void);

static void procError(void);

static void procError1(void);


static inline void G2_SetOBJEffect(GXOamAttr *oam, int effect, int affine)
{
    oam->attr01 = (oam->attr01 & ~(0x0300 | 0x3E000000)) | effect | (affine << 25);
}


static inline void G2_SetOBJPosition(GXOamAttr *oam, int x, int y)
{
    oam->attr01 = (oam->attr01 & 0xFE00FF00) | (y & 0xFF) | ((x & 0x1FF) << 16);
}


static inline void G2_SetOBJPriority(GXOamAttr *oam, int priority)
{
    oam->attr2 = (unsigned short)((oam->attr2 & ~0xC00) | (priority << 10));
}


void DWCi_SceneSetEdit32(void)
{
    int prm;
    int sce;
    SSE_MSG2 MSG = scenesetedit32_init_20570;

    MemSse = DWCi_HEAPlAllocEx(sizeof(MEMSSE), 4);
    DWCi_GetParam2_((void **)&prm, (void **)&sce);
    if (prm == 0) {
        DWCi_SETTINGlGetSsid(MemSse->ssid);
        MemSse->pos = DWCi_STRlNLen(MemSse->ssid, 32);
    }
    initGraphics();
    DWCi_HLlLoad(prm + 9);
    if (sce == 1)
        DWCi_COMMENTlDispEx(0x35, -1, 0);
    else
        DWCi_COMMENTlDispEx(MSG.v[prm], -1, 0);
    DWCi_CMNlStep(2);
    MemSse->canv = DWCi_FNTlFormBgEx(0, 0);
    MemSse->caret = DWCi_CEINlSetExObj(0, 0x3E);
    G2_SetOBJPriority(MemSse->caret, 3);
    dispCaret();
    drawSsid();
    DWCi_ChangeScene(procInit);
}


void func_021C66A8(void)
{
    u16 *p;

    func_021BD1D4((char *)((int)dat_021DB458), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207E51C));
    func_021BD1D4((char *)((int)dat_021DB46C), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207F0B8));
    func_021BD1D4((char *)((int)dat_021DB484), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207E3D0));
    func_021BD1D4((char *)((int)dat_021DB49C), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207EB78));
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
    DWCi_ChangeScene(procInit1);
}


void func_021C67CC(void)
{
    u8 *p;

    if (func_021D5580(1) != 0)
        return;
    if (func_021D5580(0) != 0)
        return;
    func_021BD8D8();
    func_021CFFAC(0x14);
    p = g_021DE5E0;
    if (p[0x29] == 0)
        func_021BDC68(0);
    p = g_021DE5E0;
    if (p[0x29] == 0x20)
        func_021BDC7C(0);
    func_021C0E40((unsigned int)func_021C684C);
}


static void procInit2(void)
{
    if (DWCi_KBlGet() == 0xFF)
        return;
    DWCi_ChangeScene(procScene);
}
