/*
 * function: SCRIPT_WORK_CmdCompareWorks
 * address: 0x021593B8
 * packet: pkt_ov010_021593B8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer 0x02159AE8 thumb ov010
 *   SCRIPT_WORK_CompareValues 0x0215932C thumb ov010
 */
typedef unsigned short u16;
typedef unsigned char u8;
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern int SCRIPT_WORK_CompareValues(unsigned int, unsigned int);
int SCRIPT_WORK_CmdCompareWorks(u8 *a, void *b)
{
    u16 *p = SCRIPT_WORK_ReadWorkPointer(a, b);
    u16 *q = SCRIPT_WORK_ReadWorkPointer(a, b);
    a[14] = SCRIPT_WORK_CompareValues(*p, *q);
    return 0;
}
