/*
 * function: procInit2
 * address:  0x021C4AB4
 * packet:   pkt_ov016_021C4AB4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procInit2 (libdwcutil.TWL.HYB.a scenesetaossbutt)
 * symbols:
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_TSKlForm                    0x021D7680  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   taskVBlank                       0x021C4DE4  arm
 *   Choose                           0x021DE5CC  data
 *   procScene                        0x021C4AF8  arm
 */
typedef _Bool bool;

typedef struct {
    unsigned char  Choose;            /* 0x00 */
    unsigned short Count;             /* 0x02 */
    void          *Task;              /* 0x04 */
} SCENESETAOSSBUTT_BSS;
extern SCENESETAOSSBUTT_BSS Choose;

extern int   DWCi_BTNlGet(void);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void  DWCi_ChangeScene(void (*scene)());

static void taskVBlank(void);
static void procScene(void);

static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2)
        return;
    Choose.Task = DWCi_TSKlForm(1, (void (*)(void *, void *))taskVBlank, 0, 0x78);
    DWCi_ChangeScene(procScene);
}
