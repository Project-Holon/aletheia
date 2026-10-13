/*
 * function: DWCi_TSKlInit
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
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   DWCi_QUElFormEx  0x021D5410  arm  ov016
 *   DWCi_QUElForm  0x021D53DC  arm  ov016
 *   DWCi_LSTlForm  0x021D6D44  arm  ov016
 *   DWCi_LSTlPushFront  0x021D6E04  arm  ov016
 *   DWCi_LSTlPushBack  0x021D6DF4  arm  ov016
 *   gMemTask  0x021DE6E4  data
 *   sTaskTable  0x021DAA84  data
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

extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void *DWCi_QUElFormEx(long size, void *data, long dataSize);
extern void *DWCi_QUElForm(long size);
struct ListCB;
extern struct ListCB *DWCi_LSTlForm(void);
extern void DWCi_LSTlPushFront(char *p, void *ob);
extern void DWCi_LSTlPushBack(char *p, void *ob);
extern MemTaskT *gMemTask;
extern unsigned char sTaskTable[2];

void DWCi_TSKlInit(void)
{
    int i;

    gMemTask = DWCi_HEAPlAllocEx(0x80, 4);
    for (i = 0; i < 2; i++) {
        int num = sTaskTable[i];
        gMemTask[i].num = num;
        gMemTask[i].mem = DWCi_HEAPlAllocEx(num * 0x14, 4);
        gMemTask[i].que = DWCi_QUElFormEx(num, gMemTask[i].mem, 0x14);
        gMemTask[i].que2 = DWCi_QUElForm(num);
        gMemTask[i].list = DWCi_LSTlForm();
        gMemTask[i].b1c = 0;
        gMemTask[i].b30 = 0xff;
        DWCi_LSTlPushFront(gMemTask[i].list, gMemTask[i].node0);
        DWCi_LSTlPushBack(gMemTask[i].list, gMemTask[i].node1);
        gMemTask[i].b38 = 1;
    }
}
