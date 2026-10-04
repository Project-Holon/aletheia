/*
 * function: func_021BD310
 * address:  0x021BD310
 * packet:   pkt_ov016_021BD310
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CMNlMsgNameDraw (libdwcutil.TWL.HYB.a(common.o))
 *
 * symbols:
 *   func_021D5A58  0x021d5a58  arm  ov016
 *   func_021C1030  0x021c1030  arm  ov016
 *   func_021BD3CC  0x021bd3cc  arm  ov016
 *   func_021D5E5C  0x021d5e5c  arm  ov016
 *   func_021C0EC8  0x021c0ec8  arm  ov016
 *   func_021D5CCC  0x021d5ccc  arm  ov016
 *   func_021D5FC4  0x021d5fc4  arm  ov016
 *   g_021DE598  0x021de598  data
 *   g_021DA06A  0x021da06a  data
 *   g_021DA068  0x021da068  data
 */

typedef struct tagCOORD { unsigned short x, y; } COORD;

extern int g_021DE598;
extern const COORD g_021DA068[7];
extern void *func_021D5A58(int lcd, int font);
extern unsigned int func_021C1030(unsigned int *p, unsigned int idx);
extern int func_021BD3CC(void);
extern void func_021D5E5C(void *canvas, int x, int y, int w, int h, int color, unsigned long flag, unsigned short *txt);
extern unsigned char func_021C0EC8(void);
extern void func_021D5CCC(void *canvas, int x, int y, int color, unsigned long flag, unsigned short *txt);
extern void func_021D5FC4(int x);

void func_021BD310(unsigned short *name, int msgId)
{
    unsigned short *msg;
    void *canvas;

    canvas = func_021D5A58(0, 0);
    msg = (short unsigned int *)func_021C1030((void *)g_021DE598, msgId);
    func_021D5E5C(canvas, 13, 60, 230, 94, 2, func_021BD3CC(), msg);
    func_021D5CCC(canvas, g_021DA068[func_021C0EC8()].x, g_021DA068[func_021C0EC8()].y, 2, 13 + 508, name);
    func_021D5FC4((int)canvas);
}
