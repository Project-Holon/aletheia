/*
 * function: func_021CD458
 * address:  0x021CD458
 * packet:   pkt_ov016_021CD458
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a scenesettest.o)
 *
 * symbols:
 *   func_021CFBD4  0x021CFBD4  arm  ov016
 *   func_0205BE6C  0x0205BE6C  arm
 *   func_020589C4  0x020589C4  arm
 *   func_02082D44  0x02082D44  arm
 *   func_021BC8EC  0x021BC8EC  arm  ov016
 *   func_021D5CA8  0x021D5CA8  arm  ov016
 *   func_021D6090  0x021D6090  arm  ov016
 *   func_021C0E50  0x021C0E50  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   g_021DE61C     0x021DE61C  data
 *   func_021C7CE4  0x021C7CE4  arm  ov016
 *   func_021CD580  0x021CD580  arm  ov016
 */

extern void *func_021CFBD4(void);
extern int func_0205BE6C(void);
extern void *func_020589C4();
extern void func_02082D44(void *srcp, void *dstp, unsigned long size);
extern void func_021BC8EC(void);
extern void func_021D5CA8(int lcd);
extern void func_021D6090(int lcd, int plane);
extern void func_021C0E50(unsigned int a, unsigned int b);
extern void func_021C0E40(unsigned int v);
extern unsigned char g_021DE61C;
extern void func_021C7CE4(void);
extern void func_021CD580(void);

void func_021CD458(void)
{
    unsigned char *map = func_021CFBD4();
    if (func_0205BE6C() == 0)
        return;
    func_02082D44(func_020589C4(), map + 0xF0, 14);
    func_02082D44(func_020589C4(), map + 0x1F0, 14);
    func_021BC8EC();
    func_021D5CA8(0);
    func_021D6090(0, 21);
    if (g_021DE61C == 0) {
        func_021C0E50(0, (unsigned int)((void *)1));
        func_021C0E40((unsigned int)func_021C7CE4);
    } else {
        func_021C0E50(0, (unsigned int)((void *)1));
        func_021C0E40((unsigned int)func_021CD580);
    }
}
