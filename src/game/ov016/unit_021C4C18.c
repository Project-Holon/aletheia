/*
 * file:     unit_021C4C18.c
 * unit:     yes
 * function: func_021C4C18, func_021C4C60
 * address:  0x021C4C18
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
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_TSKlDelete                  0x021D7724  arm
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   Choose                           0x021DE5CC  data
 *   procCancel                       0x021C4E98  arm
 *   DWCi_TSKlDeleteEx                0x021D7744  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   endScene1                        0x021C4C9C  arm
 */
typedef struct {
    unsigned char  Choose;            /* 0x00 */
    unsigned short Count;             /* 0x02 */
    void          *Task;              /* 0x04 */
} SCENESETAOSSBUTT_BSS;

typedef _Bool bool;

extern int  DWCi_BTNlGet(void);
extern void DWCi_TSKlDelete(int kind, void *task);
extern void DWCi_BTNlDisable(void);
extern void DWCi_ChangeScene(void (*scene)());
extern void DWCi_TSKlDeleteEx(int kind, void *task);
extern bool DWCi_EFFlWait(int frame);
extern SCENESETAOSSBUTT_BSS Choose;


static void procCancel(void);


static void button(void)
{
    if (DWCi_BTNlGet())
        return;
    if (Choose.Task == 0)
        return;
    DWCi_TSKlDelete(1, Choose.Task);
    Choose.Task = 0;
    DWCi_BTNlDisable();
    DWCi_ChangeScene(procCancel);
}


static void endScene1(void);


static void endScene(void)
{
    DWCi_BTNlDisable();
    if (Choose.Task != 0)
        DWCi_TSKlDeleteEx(1, Choose.Task);
    DWCi_EFFlWait(8);
    DWCi_ChangeScene(endScene1);
}
