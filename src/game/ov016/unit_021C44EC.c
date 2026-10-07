/*
 * file:     unit_021C44EC.c
 * unit:     yes
 * function: func_021C44EC, func_021C450C, func_021C4558, func_021C45D8, func_021C4614
 * address:  0x021C44EC
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
 *   DWCi_MOVlInit                    0x021C1074  arm
 *   initGraphics                     0x021C4558  arm
 *   DWCi_CMNlMsgDraw                 0x021BD29C  arm
 *   DWCi_ANIMElInitEx                0x021BC820  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   cbMov                            0x021C4890  arm
 *   Choose                           0x021DE5C8  data
 *   func_021BD1D4  0x021BD1D4  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   procInit2                        0x021C4640  arm
 */
typedef unsigned short u16;

typedef struct {
    u16 priority : 2;
    u16 rest : 14;
} BgCnt;

typedef _Bool bool;

extern void DWCi_MOVlInit(void (*callback)(int));
extern void DWCi_CMNlMsgDraw(int msgId);
extern void DWCi_ANIMElInitEx(int color);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_ChangeScene(void (*scene)());
void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern bool DWCi_EFFlCheck(int lcd);
extern void DWCi_CMNlButton(int kind);
int func_021C44EC(void);
void DWCi_SceneOptMovWait(void);
void func_021C4558(void);
extern unsigned char Choose;

/*
 * Bit 15 of the halfword at 0x02FFFFA8, as 0/1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C44EC.c \
 *       --func func_021C44EC --addr 0x021C44EC --region ov016 --cc dsi/1.1p1 --arm
 */
int func_021C44EC(void)
{
    return ((*(unsigned short *)0x02FFFFA8 & 0x8000) >> 15) != 0;
}


static void cbMov(int state);

static void initGraphics(void);

static void procInit(void);


void DWCi_SceneOptMovWait(void)
{
    DWCi_MOVlInit(cbMov);
    Choose = 0;
    initGraphics();
    DWCi_CMNlMsgDraw(0x1c);
    DWCi_ANIMElInitEx(0);
    DWCi_SNDlPlay(0xb);
    DWCi_ChangeScene(procInit);
}


void func_021C4558(void)
{
    func_021BD1D4((void *)0x021DB3CC, (void *)0x0207EB78);
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
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_CMNlButton(1);
    DWCi_ChangeScene(procInit2);
}
