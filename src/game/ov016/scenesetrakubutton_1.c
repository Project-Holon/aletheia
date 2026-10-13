/*
 * file:     scenesetrakubutton_1.c
 * unit:     yes
 * function: func_021CA838, func_021CA874
 * address:  0x021CA838
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
 *   initGraphics      0x021CA874 arm
 *   DWCi_HLlLoadSet   0x021BD6D4 arm
 *   DWCi_CMNlMsgDraw  0x021BD29C arm
 *   DWCi_ANIMElInitEx 0x021BC820 arm
 *   DWCi_ChangeScene  0x021C0E40 arm
 *   Choose            0x021DE5F8 data
 *   procInit          0x021CA8F4 arm
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
void DWCi_SceneSetRakuButton(void);
void func_021CA874(void);
extern unsigned char Choose;


void DWCi_SceneSetRakuButton(void)
{
    Choose = 0;
    initGraphics();
    DWCi_HLlLoadSet();
    DWCi_CMNlMsgDraw(0x25);
    DWCi_ANIMElInitEx(1);
    DWCi_ChangeScene(procInit);
}


void func_021CA874(void)
{
    func_021BD1D4((void *)0x021DB644, (void *)0x0207EB78);
    ((BgCnt *)0x04001008)->priority = 3;
    ((BgCnt *)0x0400100A)->priority = 3;
    ((BgCnt *)0x04000008)->priority = 3;
    ((BgCnt *)0x0400000A)->priority = 3;
    ((BgCnt *)0x0400000C)->priority = 3;
}
