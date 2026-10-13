/*
 * file:     sceneoptmovuser.c
 * unit:     yes
 * function: func_021C4110, func_021C41E0, func_021C4260, func_021C429C, func_021C42C0, func_021C42E0, DWCi_SceneOptMovUser_input, DWCi_SceneOptMovUser_draw, func_021C4350, func_021C43AC, func_021C4408, func_021C44D8
 * address:  0x021C4110
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
 *   func_021C11F8  0x021C11F8  arm  ov016
 *   func_021D5A58  0x021D5A58  arm  ov016
 *   func_02082A48  0x02082A48  arm
 *   func_02082A60  0x02082A60  arm
 *   func_021D5E5C  0x021D5E5C  arm  ov016
 *   func_021D5FC4  0x021D5FC4  arm  ov016
 *   func_021C11D4  0x021C11D4  arm  ov016
 *   func_021D1208  0x021D1208  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   g_021DE5C4     0x021DE5C4  data
 *   func_021C44D8  0x021C44D8  arm  ov016
 *   func_021C4260  0x021C4260  arm  ov016
 *   func_021BD1D4  0x021BD1D4  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_WINlGet                     0x021D1568  arm
 *   DWCi_MOVlChangeCallback          0x021C11D4  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_WINlEnd                     0x021D1524  arm
 *   Error                            0x021DE5C4  data
 *   draw                             0x021C434C  arm
 *   input                            0x021C4348  arm
 *   DWCi_WINlIsInit                  0x021D157C  arm
 *   DWCi_MOVlAdmitChild              0x021C11EC  arm
 *   DWCi_MOVlEnd                     0x021C115C  arm
 *   DWCi_COMMENTlDelete              0x021BD138  arm
 *   DWCi_FNTlDeleteBgLcd             0x021D5CA8  arm
 *   DWCi_GXlInvisible                0x021D6090  arm
 *   DWCi_MOVlIsEnd                   0x021C11B8  arm
 *   DWCi_SceneOptMenu                0x021C2A3C  arm
 *   DWCi_SceneOptMovComm             0x021C315C  arm
 *   DWCi_SceneOptMovFailure          0x021C3D8C  arm
 *   DWCi_SetParam_                   0x021C0E50  arm
 *   isUnloaded  0x021de5c4  data
 */
typedef struct MBUserInfo {
    unsigned char color;
    unsigned char nameLength;
    unsigned short name[10];
} MBUserInfo;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u16 priority : 2;
    u16 rest : 14;
} BgCnt;

typedef _Bool bool;

extern char *func_021C11F8(void);
extern void *func_021D5A58(int lcd, int font);
extern void func_02082A48();
extern void func_02082A60();
extern void func_021D5E5C(void *canvas, int x, int y, int w, int h, int color, u32 flag, u16 *txt);
extern void func_021D5FC4(int x);
extern void func_021C11D4(unsigned int v);
extern void func_021D1208(int msg, int type, unsigned char dark, int n, int num);
extern void func_021C0E40(unsigned int v);
extern void func_021C44D8();
extern void func_021C4260();
void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_ChangeScene(void (*scene)());
extern bool DWCi_EFFlCheck(int lcd);
extern int DWCi_WINlGet(void);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_MOVlChangeCallback(void (*callback)(int));
extern void DWCi_WINlEnd(void);
extern bool DWCi_WINlIsInit(void);
extern void DWCi_MOVlAdmitChild();
extern void DWCi_MOVlEnd(void);
extern bool DWCi_MOVlIsEnd(void);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern bool DWCi_COMMENTlDelete(void);
extern void DWCi_SetParam_(void *param0, void *param1);
extern void DWCi_SceneOptMenu(void);
extern void DWCi_SceneOptMovComm(void);
extern void DWCi_SceneOptMovFailure(void);
void func_021C4110(void);
void func_021C41E0(void);
void DWCi_SceneOptMovUser_input(void);
void DWCi_SceneOptMovUser_draw(void);
extern unsigned char g_021DE5C4[];
extern unsigned char Error[];
extern unsigned char isUnloaded;



/*
 * sdk:      DWCi_SceneOptMovUser (libdwcutil.TWL.HYB.a sceneoptmovuser.o)
 */
void func_021C4110(void)
{
    unsigned short buf[11];
    MBUserInfo *info;
    void *bg;

    info = (MBUserInfo *)func_021C11F8();
    bg = func_021D5A58(0, 0);
    g_021DE5C4[1] = 0;
    g_021DE5C4[0] = 0;
    func_021C41E0();
    func_02082A48(0, buf, sizeof(buf));
    func_02082A60(info->name, buf, info->nameLength * 2);
    func_021D5E5C(bg, 8, 0x35, 0xF0, 0x1C, 2, 0x480, buf);
    func_021D5FC4((int)bg);
    func_021C11D4((unsigned int)func_021C44D8);
    func_021D1208(0x1D, 4, 0, -1, 0);
    func_021C0E40((unsigned int)func_021C4260);
}



void func_021C41E0(void)
{
    func_021BD1D4((void *)0x021DB3B8, (void *)0x0207EB78);
    ((BgCnt *)0x04001008)->priority = 3;
    ((BgCnt *)0x0400100A)->priority = 3;
    ((BgCnt *)0x04000008)->priority = 3;
    ((BgCnt *)0x0400000A)->priority = 3;
    ((BgCnt *)0x0400000C)->priority = 3;
}



static void procInit1(void);



static void procInit(void)
{
    DWCi_EFFlFade(2, 0, 0x15, 8);
    DWCi_GXlVisible(0, 0x15);
    DWCi_ChangeScene(procInit1);
}



static void procInit2(void);



static void procInit1(void)
{
    if (!DWCi_EFFlCheck(0))
        DWCi_ChangeScene(procInit2);
}



static void procScene(void);



static void procInit2(void)
{
    if (DWCi_WINlGet() == -2)
        return;
    DWCi_ChangeScene(procScene);
}


static void input(void);


static void draw(void);


static void endScene(void);



static void procScene(void)
{
    input();
    draw();
    switch (DWCi_WINlGet()) {
    case 0:
        Error[1] = 0;
        DWCi_SNDlPlay(7);
        break;
    case 1:
        Error[1] = 1;
        DWCi_SNDlPlay(0xe);
        break;
    default:
        return;
    }
    DWCi_MOVlChangeCallback(0);
    DWCi_WINlEnd();
    DWCi_ChangeScene(endScene);
}


/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovUser_input.c \
 *       --func DWCi_SceneOptMovUser_input --addr 0x021C4348 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneOptMovUser_input(void)
{
}


/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovUser_draw.c \
 *       --func DWCi_SceneOptMovUser_draw --addr 0x021C434C --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneOptMovUser_draw(void)
{
}



static void endScene1(void);



static void endScene(void)
{
    if (DWCi_WINlIsInit())
        return;
    if (Error[1] == 0)
        DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene(endScene1);
}



static void endScene2(void);



static void endScene1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    if (Error[0] == 0 && Error[1] == 1)
        DWCi_MOVlAdmitChild();
    else
        DWCi_MOVlEnd();
    DWCi_ChangeScene(endScene2);
}



static void endScene2(void)
{
    if (Error[0] || !Error[1]) {
        if (!DWCi_MOVlIsEnd())
            return;
    }
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_GXlInvisible(0, 0x15);
    if (!Error[1]) {
        DWCi_COMMENTlDelete();
        DWCi_GXlInvisible(1, 1);
    }
    DWCi_SetParam_(0, (void *)1);
    if (Error[0]) {
        DWCi_ChangeScene(DWCi_SceneOptMovFailure);
        return;
    }
    if (Error[1] == 0) {
        DWCi_GXlInvisible(1, 1);
        DWCi_ChangeScene(DWCi_SceneOptMenu);
        return;
    }
    DWCi_ChangeScene(DWCi_SceneOptMovComm);
}



static void cbMov(void)
{
    isUnloaded = 1;
}
