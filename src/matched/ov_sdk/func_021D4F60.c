/*
 * function: DWCi_CELLlDelete
 * address:  0x021D4F60
 * packet:   pkt_021D4F60
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D6D8C  0x021D6D8C  arm
 *   DWCi_QUElPushBack  0x021D546C  arm
 *   gCellWork     0x021DE670  data
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_021D6D8C(void *p);
extern void DWCi_QUElPushBack(void *queue, void *data);
extern u8  *gCellWork;

void DWCi_CELLlDelete(u8 *p)
{
    u32 *q;
    int i;
    int sel = 0;
    u8 *base;

    q = *(u32 **)(p + 8);
    for (i = 0; i < p[0xc]; i++) {
        *q = (*q & 0xC1FFFCFF) | 0x200;
        q += 2;
    }
    func_021D6D8C(p);
    base = gCellWork;
    if (p >= base + 0x228)
        sel = 1;
    DWCi_QUElPushBack((void *)(*(u32 *)(base + sel * 0x228 + 0x224)), p);
}
