/*
 * function: SCRIPT_WORK_CmdAddWork
 * address: 0x021597AC
 * packet: pkt_ov010_021597AC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding at 0x021597CA.
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer 0x02159AE8 thumb ov010
 *   SCRIPT_WORK_ReadWorkValue 0x02159B10 thumb ov010
 */
typedef unsigned short u16;
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
int SCRIPT_WORK_CmdAddWork(void *a, void *b)
{
    u16 *p = SCRIPT_WORK_ReadWorkPointer(a, b);
    *p = *p + SCRIPT_WORK_ReadWorkValue(a, b);
    return 0;
}
