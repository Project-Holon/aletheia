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
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021CFFD0  0x021CFFD0  arm  ov016
 *   func_021D6B64  0x021D6B64  arm  ov016
 *   func_021CEC9C  0x021CEC9C  arm  ov016
 *   func_021CECC8  0x021CECC8  arm  ov016
 *   func_021CEB54  0x021CEB54  arm  ov016
 *   func_021CEDC4  0x021CEDC4  arm  ov016
 *   g_021DE63C  0x021DE63C  data
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
extern void func_021CFFAC(unsigned int v);
extern void func_021CFFD0(unsigned int v);
struct tagCOORD;
extern int func_021D6B64(struct tagCOORD *c);
extern void func_021CEC9C(int idx);
extern void func_021CECC8(void);
extern void func_021CEB54(void);
extern int func_021CEDC4(int a);
extern MemSbT *g_021DE63C;

void func_021CE9E8(void)
{
    g_021DE63C->state = 0;
    switch (g_021DE63C->last) {
    case 0:
        if (g_021DE63C->disable)
            return;
        switch (func_021CED30()) {
        case 1:
            if (g_021DE63C->kind == 0)
                return;
            func_021CFFAC(0x16);
            func_021CFFD0(0);
            g_021DE63C->state = 1;
            func_021D6B64((struct tagCOORD *)(&g_021DE63C->cTouch));
            g_021DE63C->tochPos = g_021DE63C->pos;
            g_021DE63C->last = 1;
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
            g_021DE63C->state = 5;
            g_021DE63C->last = 0;
        } else if (func_021CED30() == 2) {
            func_021CEC9C(2);
        }
        break;
    case 3:
        if (func_021CEDC4(3) != 3) {
            g_021DE63C->state = 7;
            g_021DE63C->last = 0;
        } else if (func_021CED30() == 3) {
            func_021CEC9C(3);
        }
        break;
    }
}
