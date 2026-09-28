/*
 * function: button
 * address:  0x021C4C18
 * packet:   pkt_ov016_021C4C18
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      button (libdwcutil.TWL.HYB.a scenesetaossbutt)
 * symbols:
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_TSKlDelete                  0x021D7724  arm
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   Choose                           0x021DE5CC  data
 *   procCancel                       0x021C4E98  arm
 */
typedef struct {
    unsigned char  Choose;            /* 0x00 */
    unsigned short Count;             /* 0x02 */
    void          *Task;              /* 0x04 */
} SCENESETAOSSBUTT_BSS;
extern SCENESETAOSSBUTT_BSS Choose;

extern int  DWCi_BTNlGet(void);
extern void DWCi_TSKlDelete(int kind, void *task);
extern void DWCi_BTNlDisable(void);
extern void DWCi_ChangeScene(void (*scene)());

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
