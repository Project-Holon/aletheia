/*
 * function: procWait
 * address:  0x021C4E4C
 * packet:   pkt_ov016_021C4E4C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procWait (libdwcutil.TWL.HYB.a scenesetaossbutt)
 * symbols:
 *   input                            0x021C4BDC  arm
 *   draw                             0x021C4C14  arm
 *   button                           0x021C4C18  arm
 *   DWCi_SNDlStop                    0x021D0014  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   Choose                           0x021DE5CC  data
 *   endScene                         0x021C4C60  arm
 */
typedef struct {
    unsigned char  Choose;            /* 0x00 */
    unsigned short Count;             /* 0x02 */
    void          *Task;              /* 0x04 */
} SCENESETAOSSBUTT_BSS;
extern SCENESETAOSSBUTT_BSS Choose;

extern void DWCi_SNDlStop(void);
extern void DWCi_ChangeScene(void (*scene)());

static void input(void);
static void draw(void);
static void button(void);
static void endScene(void);

static void procWait(void)
{
    input();
    draw();
    button();
    Choose.Count = Choose.Count + 1;
    if (Choose.Count < 1080)
        return;
    DWCi_SNDlStop();
    DWCi_ChangeScene(endScene);
}
