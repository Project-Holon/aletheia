/*
 * file:     scenesetrakubutton1_1.c
 * unit:     yes
 * function: func_021CAC64, func_021CACA0
 * address:  0x021CAC64
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
 *   initGraphics      0x021CACA0 arm
 *   DWCi_HLlLoadSet   0x021BD6D4 arm
 *   DWCi_CMNlMsgDraw  0x021BD29C arm
 *   DWCi_ANIMElInitEx 0x021BC820 arm
 *   DWCi_ChangeScene  0x021C0E40 arm
 *   procInit          0x021CAD20 arm
 *   func_021BD1D4  0x021BD1D4  arm
 */
typedef unsigned short u16;

typedef struct {
    u16 priority : 2;
    u16 rest : 14;
} BgCnt;

void initGraphics(void);
void DWCi_HLlLoadSet(void);
void DWCi_CMNlMsgDraw(int msgId);
void DWCi_ANIMElInitEx(int color);
void DWCi_ChangeScene(void (*scene)(void));
void procInit(void);
void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
void DWCi_SceneSetRakuButton1(void);
void func_021CACA0(void);


void DWCi_SceneSetRakuButton1(void)
{
    *(unsigned char *)0x021DE5FC = 0;
    initGraphics();
    DWCi_HLlLoadSet();
    DWCi_CMNlMsgDraw(0x2a);
    DWCi_ANIMElInitEx(2);
    DWCi_ChangeScene(procInit);
}


void func_021CACA0(void)
{
    func_021BD1D4((void *)0x021DB658, (void *)0x0207EB78);
    ((BgCnt *)0x04001008)->priority = 3;
    ((BgCnt *)0x0400100A)->priority = 3;
    ((BgCnt *)0x04000008)->priority = 3;
    ((BgCnt *)0x0400000A)->priority = 3;
    ((BgCnt *)0x0400000C)->priority = 3;
}
