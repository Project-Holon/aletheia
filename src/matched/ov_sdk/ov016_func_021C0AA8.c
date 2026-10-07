/*
 * function: func_021C0AA8
 * address:  0x021C0AA8
 * packet:   pkt_ov016_021C0AA8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      initGame (libdwcutil.TWL.HYB.a main.o)
 *
 * symbols:
 *   func_0207D42C  0x0207D42C  arm
 *   func_02087058  0x02087058  arm
 *   OS_Terminate   0x02088234  arm
 *   func_02087244  0x02087244  arm
 *   func_0207D3E4  0x0207D3E4  arm
 *   func_0207D148  0x0207D148  arm
 *   func_0207AD04  0x0207AD04  arm
 *   func_0208A924  0x0208A924  arm
 *   func_02088788  0x02088788  arm
 *   func_021D7274  0x021D7274  arm  ov016
 *   func_021D6360  0x021D6360  arm  ov016
 *   func_021D6C78  0x021D6C78  arm  ov016
 *   func_021D7484  0x021D7484  arm  ov016
 *   func_021D486C  0x021D486C  arm  ov016
 *   func_021D64B8  0x021D64B8  arm  ov016
 *   func_021D551C  0x021D551C  arm  ov016
 *   func_021D6414  0x021D6414  arm  ov016
 *   func_020589D0  0x020589D0  arm
 *   func_021D6438  0x021D6438  arm  ov016
 *   g_021DE56C     0x021DE56C  data
 */

#include "../include/G_UtilState.h"

typedef struct UtilState UtilState;

extern void func_0207D42C(void);
extern int func_02087058(void);
extern void OS_Terminate(void);
extern int func_02087244(void);
extern long func_0207D3E4(int enable);
extern void func_0207D148(void);
extern void func_0207AD04(unsigned long default_dma_no);
extern void func_0208A924(void);
extern void func_02088788(void);
extern void func_021D7274(void);
extern void func_021D6360(void *address);
extern void func_021D6C78(void);
extern void func_021D7484(void);
extern void func_021D486C(void);
extern void func_021D64B8(void);
extern void func_021D551C(void);
extern void *func_021D6414(unsigned long size, int alignment);
extern int func_020589D0(void *work);
extern void func_021D6438(void **mem);
extern struct UtilState g_021DE56C;

void func_021C0AA8(void)
{
    void *work;
    int zero;
    volatile unsigned short *ime = (volatile unsigned short *)0x04000208;
    unsigned short old = *ime;
    *ime = 0;
    func_0207D42C();
    *(volatile unsigned int *)0x04001000 &= ~0x10000;
    if (!func_02087058())
        OS_Terminate();
    if (!func_02087244())
        OS_Terminate();
    zero = 0;
    func_0207D3E4(zero);
    func_0207D148();
    func_0207AD04(zero - 1);
    func_0208A924();
    func_02088788();
    func_0207D42C();
    *(volatile unsigned int *)0x04001000 &= ~0x10000;
    func_021D7274();
    func_021D6360(g_021DE56C.work);
    func_021D6C78();
    func_021D7484();
    func_021D486C();
    func_021D64B8();
    func_021D551C();
    work = func_021D6414(0x1000, 0x20);
    func_020589D0(work);
    func_021D6438(&work);
}
