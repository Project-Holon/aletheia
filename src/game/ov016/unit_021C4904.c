/*
 * file:     unit_021C4904.c
 * unit:     yes
 * function: func_021C4904, func_021C4964, func_021C4A0C, procInit1, procInit2, func_021C4AF8
 * address:  0x021C4904
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
 *   Choose                           0x021DE5CC  data
 *   initGraphics                     0x021C4964  arm
 *   DWCi_HLlLoadSet                  0x021BD6D4  arm
 *   DWCi_COMMENTlDispEx              0x021BD060  arm
 *   DWCi_CMNlStep                    0x021BD214  arm
 *   DWCi_CMNlMsgDraw                 0x021BD29C  arm
 *   DWCi_ANIMElInitEx                0x021BC820  arm
 *   DWCi_AOSSlInit                   0x021C07A8  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   func_021BD1D4   0x021BD1D4  arm  ov016
 *   dat_021DB3E0    0x021DB3E0  data
 *   dat_021DB3F8    0x021DB3F8  data
 *   dat_021DB410    0x021DB410  data
 *   dat_0207F0B8    0x0207F0B8  data
 *   dat_0207E3D0    0x0207E3D0  data
 *   dat_0207EB78    0x0207EB78  data
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_TSKlForm                    0x021D7680  arm
 *   taskVBlank                       0x021C4DE4  arm
 *   procScene                        0x021C4AF8  arm
 *   func_021C4BDC  0x021C4BDC  arm  ov016
 *   func_021C4C14  0x021C4C14  arm  ov016
 *   func_021C4C18  0x021C4C18  arm  ov016
 *   func_021C0900  0x021C0900  arm  ov016
 *   func_021D7744  0x021D7744  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021D0014  0x021D0014  arm  ov016
 *   func_021D1208  0x021D1208  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021BCB9C  0x021BCB9C  arm  ov016
 *   g_021DE5CC     0x021DE5CC  data
 *   func_021C4E4C  0x021C4E4C  arm  ov016
 *   func_021C4E00  0x021C4E00  arm  ov016
 */
typedef _Bool bool;

/* scenesetaossbutt.o .bss at 0x021DE5CC, members at their vendor offsets */
typedef struct {
    unsigned char  Choose;            /* 0x00 */
    unsigned short Count;             /* 0x02 */
    void          *Task;              /* 0x04 */
} SCENESETAOSSBUTT_BSS;

typedef unsigned short u16;

extern void DWCi_HLlLoadSet(void);
extern bool DWCi_COMMENTlDispEx(int messageId, int n, int num);
extern void DWCi_CMNlStep(int step);
extern void DWCi_CMNlMsgDraw(int msgId);
extern void DWCi_ANIMElInitEx(int color);
extern void DWCi_AOSSlInit(void);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_ChangeScene(void (*scene)());
extern void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern bool DWCi_EFFlCheck(int lcd);
extern void DWCi_CMNlButton(int kind);
extern int   DWCi_BTNlGet(void);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void func_021C4BDC();
extern void func_021C4C14();
extern void func_021C4C18();
extern int func_021C0900();
extern void func_021D7744(unsigned int idx, void *r4);
extern void func_021C0E40(unsigned int v);
extern void func_021D0014();
extern void func_021D1208(int msg, int type, unsigned char dark, int n, int num);
extern void func_021CFFAC(unsigned int v);
extern void func_021BCB9C();
extern void func_021C4E4C();
extern void func_021C4E00();
void DWCi_SceneSetAossButton(void);
void func_021C4964(void);
void func_021C4AF8(void);
extern SCENESETAOSSBUTT_BSS Choose;
extern unsigned short dat_021DB3E0[];
extern unsigned short dat_021DB3F8[];
extern unsigned short dat_021DB410[];
extern unsigned short dat_0207F0B8[];
extern unsigned short dat_0207E3D0[];
extern unsigned short dat_0207EB78[];





static void initGraphics(void);




static void procInit(void);





void DWCi_SceneSetAossButton(void)
{
    Choose.Count = 0;
    initGraphics();
    DWCi_HLlLoadSet();
    DWCi_COMMENTlDispEx(0x36, -1, 0);
    DWCi_CMNlStep(2);
    DWCi_CMNlMsgDraw(0x22);
    DWCi_ANIMElInitEx(0);
    DWCi_AOSSlInit();
    DWCi_SNDlPlay(0xb);
    DWCi_ChangeScene(procInit);
}





/*
 * Load three tilemaps through func_021BD1D4, then set the low two bits of five
 * halfword registers (the 0x04001008/0x04000008 pair and their +2 neighbours).
 * Addresses are Black-image addresses.
 */
void func_021C4964(void)
{
    u16 *p;

    func_021BD1D4((char *)((int)dat_021DB3E0), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207F0B8));
    func_021BD1D4((char *)((int)dat_021DB3F8), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207E3D0));
    func_021BD1D4((char *)((int)dat_021DB410), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207EB78));

    p = (u16 *)0x04001008;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)0x04000008;
    p[0] = (p[0] & ~3) | 3;
    p = (u16 *)0x0400000A;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
}





static void procInit1(void);





static void procInit(void)
{
    DWCi_EFFlFade(2, 1, 1, 8);
    DWCi_EFFlFade(2, 0, 0x15, 8);
    DWCi_GXlVisible(1, 1);
    DWCi_GXlVisible(0, 0x15);
    DWCi_ChangeScene(procInit1);
}




static void procInit2(void);




static void procInit1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_CMNlButton(1);
    DWCi_ChangeScene(procInit2);
}



static void taskVBlank(void);


static void procScene(void);



static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2)
        return;
    Choose.Task = DWCi_TSKlForm(1, (void (*)(void *, void *))taskVBlank, 0, 0x78);
    DWCi_ChangeScene(procScene);
}


void func_021C4AF8(void)
{
    func_021C4BDC();
    func_021C4C14();
    func_021C4C18();
    switch (func_021C0900()) {
    case 0:
        return;
    case 1:
        if (Choose.Task == 0)
            return;
        Choose.Choose = 1;
        func_021D7744(1, Choose.Task);
        Choose.Task = 0;
        func_021C0E40((unsigned int)func_021C4E4C);
        return;
    case 2:
        if (Choose.Task == 0)
            return;
        func_021D0014();
        func_021D1208(0xC, 1, 1, -1, 0);
        func_021CFFAC(9);
        func_021BCB9C();
        func_021D7744(1, Choose.Task);
        Choose.Task = 0;
        func_021C0E40((unsigned int)func_021C4E00);
        return;
    }
}
