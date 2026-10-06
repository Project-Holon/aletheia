/*
 * function: func_021D7484
 * address:  0x021D7484
 * packet:   pkt_ov016_021D7484
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_TSKlInit (libdwcutil.TWL.HYB.a task.o)
 *
 * symbols:
 *   func_021D6414  0x021D6414  arm  ov016
 *   func_021D5410  0x021D5410  arm  ov016
 *   func_021D53DC  0x021D53DC  arm  ov016
 *   func_021D6D44  0x021D6D44  arm  ov016
 *   func_021D6E04  0x021D6E04  arm  ov016
 *   func_021D6DF4  0x021D6DF4  arm  ov016
 *   g_021DE6E4  0x021DE6E4  data
 *   g_021DAA84  0x021DAA84  data
 */

typedef struct {
    void *que;
    void *que2;
    void *list;
    unsigned char node0[16];
    unsigned char b1c;
    unsigned char pad1d[3];
    unsigned char node1[16];
    unsigned char b30;
    unsigned char pad31[3];
    int num;
    unsigned char b38;
    unsigned char pad39[3];
    void *mem;
} MemTaskT;

extern void *func_021D6414(unsigned long size, int alignment);
extern void *func_021D5410(long size, void *data, long dataSize);
extern void *func_021D53DC(long size);
struct ListCB;
extern struct ListCB *func_021D6D44(void);
extern void func_021D6E04(void *list, void *ob);
extern void func_021D6DF4(char *p, void *ob);
extern MemTaskT *g_021DE6E4;
extern unsigned char g_021DAA84[2];

void func_021D7484(void)
{
    int i;

    g_021DE6E4 = func_021D6414(0x80, 4);
    for (i = 0; i < 2; i++) {
        int num = g_021DAA84[i];
        g_021DE6E4[i].num = num;
        g_021DE6E4[i].mem = func_021D6414(num * 0x14, 4);
        g_021DE6E4[i].que = func_021D5410(num, g_021DE6E4[i].mem, 0x14);
        g_021DE6E4[i].que2 = func_021D53DC(num);
        g_021DE6E4[i].list = func_021D6D44();
        g_021DE6E4[i].b1c = 0;
        g_021DE6E4[i].b30 = 0xff;
        func_021D6E04(g_021DE6E4[i].list, g_021DE6E4[i].node0);
        func_021D6DF4(g_021DE6E4[i].list, g_021DE6E4[i].node1);
        g_021DE6E4[i].b38 = 1;
    }
}
