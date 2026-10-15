/*
 * function: DIGITALCARDCHECK_WaitRecord
 * address:  0x0217D160
 * packet:   pkt_0217D160
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DIGITALCARDCHECK_CreateRecord  0x0217D028  thumb  ov176
 *   DIGITALCARDCHECK_IsRecordDone  0x0217D188  thumb  ov176
 */

typedef unsigned char  u8;
extern void DIGITALCARDCHECK_CreateRecord(u8 *p);
extern int DIGITALCARDCHECK_IsRecordDone(u8 *p);

void DIGITALCARDCHECK_WaitRecord(int *p)
{
    DIGITALCARDCHECK_CreateRecord((u8 *)p);
    while (DIGITALCARDCHECK_IsRecordDone((u8 *)p) == 0)
        ;
}
