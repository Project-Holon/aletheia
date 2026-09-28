/*
 * function: endScene
 * address:  0x021C4C60
 * packet:   pkt_ov016_021C4C60
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene (libdwcutil.TWL.HYB.a scenesetaossbutt)
 * symbols:
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_TSKlDeleteEx                0x021D7744  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   Choose                           0x021DE5CC  data
 *   endScene1                        0x021C4C9C  arm
 */
typedef _Bool bool;

typedef struct {
    unsigned char  Choose;            /* 0x00 */
    unsigned short Count;             /* 0x02 */
    void          *Task;              /* 0x04 */
} SCENESETAOSSBUTT_BSS;
extern SCENESETAOSSBUTT_BSS Choose;

extern void DWCi_BTNlDisable(void);
extern void DWCi_TSKlDeleteEx(int kind, void *task);
extern bool DWCi_EFFlWait(int frame);
extern void DWCi_ChangeScene(void (*scene)());

static void endScene1(void);

static void endScene(void)
{
    DWCi_BTNlDisable();
    if (Choose.Task != 0)
        DWCi_TSKlDeleteEx(1, Choose.Task);
    DWCi_EFFlWait(8);
    DWCi_ChangeScene(endScene1);
}
