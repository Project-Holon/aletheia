/*
 * function: func_021CE9E8
 * address:  0x021CE9E8
 * packet:   pkt_ov016_021CE9E8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskMain (libdwcutil.TWL.HYB.a scrollbar.o)
 *
 * symbols:
 *   func_021CED30  0x021CED30  arm  ov016
 *   DWCi_SNDlPlay  0x021CFFAC  arm  ov016
 *   DWCi_SNDlSetVolume  0x021CFFD0  arm  ov016
 *   DWCi_TPlGet  0x021D6B64  arm  ov016
 *   func_021CEC9C  0x021CEC9C  arm  ov016
 *   func_021CECC8  0x021CECC8  arm  ov016
 *   func_021CEB54  0x021CEB54  arm  ov016
 *   func_021CEDC4  0x021CEDC4  arm  ov016
 *   gScrollBar  0x021DE63C  data
 */

typedef struct {
    void *cell;
    void *obj[2];
    void *task;
    unsigned char coord[4];
    unsigned char cTouch[4];
    unsigned char tochPos;
    unsigned char max;
    unsigned char pos;
    unsigned char kind;
    unsigned char last;
    unsigned char state;
    unsigned char disable;
    unsigned char pad;
} MemSbT;

extern int func_021CED30(void);
extern void DWCi_SNDlPlay(unsigned int v);
extern void DWCi_SNDlSetVolume(unsigned int v);
struct tagCOORD;
extern int DWCi_TPlGet(struct tagCOORD *c);
extern void func_021CEC9C(int idx);
extern void func_021CECC8(void);
extern void func_021CEB54(void);
extern int func_021CEDC4(int a);
extern MemSbT *gScrollBar;

void func_021CE9E8(void)
{
    gScrollBar->state = 0;
    switch (gScrollBar->last) {
    case 0:
        if (gScrollBar->disable)
            return;
        switch (func_021CED30()) {
        case 1:
            if (gScrollBar->kind == 0)
                return;
            DWCi_SNDlPlay(0x16);
            DWCi_SNDlSetVolume(0);
            gScrollBar->state = 1;
            DWCi_TPlGet((struct tagCOORD *)(&gScrollBar->cTouch));
            gScrollBar->tochPos = gScrollBar->pos;
            gScrollBar->last = 1;
            break;
        case 2:
            func_021CEC9C(2);
            break;
        case 3:
            func_021CEC9C(3);
            break;
        case 4:
            func_021CECC8();
            break;
        }
        break;
    case 1:
        func_021CEB54();
        break;
    case 2:
        if (func_021CEDC4(2) != 2) {
            gScrollBar->state = 5;
            gScrollBar->last = 0;
        } else if (func_021CED30() == 2) {
            func_021CEC9C(2);
        }
        break;
    case 3:
        if (func_021CEDC4(3) != 3) {
            gScrollBar->state = 7;
            gScrollBar->last = 0;
        } else if (func_021CED30() == 3) {
            func_021CEC9C(3);
        }
        break;
    }
}
