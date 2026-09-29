/*
 * function: func_021C4AF8
 * address:  0x021C4AF8
 * packet:   pkt_ov016_021C4AF8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procScene (libdwcutil.TWL.HYB.a scenesetaossbutton.o)
 *
 * symbols:
 *   func_021C4BDC  0x021C4BDC  arm  ov016
 *   func_021C4C14  0x021C4C14  arm  ov016
 *   func_021C4C18  0x021C4C18  arm  ov016
 *   func_021C0900  0x021C0900  arm  ov016
 *   func_021D7744  0x021D7744  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021D0014  0x021D0014  arm  ov016
 *   func_021D1208  0x021D1208  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021BCB9C  0x021BCB9C  arm  ov016
 *   g_021DE5CC     0x021DE5CC  data
 *   func_021C4E4C  0x021C4E4C  arm  ov016
 *   func_021C4E00  0x021C4E00  arm  ov016
 */

typedef struct Choose {
    unsigned char way;
    void *task;
} Choose;

extern void func_021C4BDC();
extern void func_021C4C14();
extern void func_021C4C18();
extern int func_021C0900();
extern void func_021D7744();
extern void func_021C0E40();
extern void func_021D0014();
extern void func_021D1208();
extern void func_021CFFAC();
extern void func_021BCB9C();
extern void func_021C4E4C();
extern void func_021C4E00();
extern Choose g_021DE5CC;

void func_021C4AF8(void)
{
    func_021C4BDC();
    func_021C4C14();
    func_021C4C18();
    switch (func_021C0900()) {
    case 0:
        return;
    case 1:
        if (g_021DE5CC.task == 0)
            return;
        g_021DE5CC.way = 1;
        func_021D7744(1, g_021DE5CC.task);
        g_021DE5CC.task = 0;
        func_021C0E40(func_021C4E4C);
        return;
    case 2:
        if (g_021DE5CC.task == 0)
            return;
        func_021D0014();
        func_021D1208(0xC, 1, 1, -1, 0);
        func_021CFFAC(9);
        func_021BCB9C();
        func_021D7744(1, g_021DE5CC.task);
        g_021DE5CC.task = 0;
        func_021C0E40(func_021C4E00);
        return;
    }
}
