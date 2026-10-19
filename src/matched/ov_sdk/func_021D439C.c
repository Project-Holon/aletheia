/*
 * function: _DWCi_MOV_ReadyMovUserID
 * address:  0x021D439C
 * packet:   pkt_021D439C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _DWCi_MOV_ReadyMovUserID 0x021D439C arm
 *   DWCi_MOV_WH_SetJudgeAcceptFunc  0x021D38C8  arm
 *
 * Reset the sequence and set the state byte at +0xa90 to 8.
 * Addresses are Black-image addresses.
 */

extern void func_021D45E0(void);
extern void DWCi_MOV_WH_SetJudgeAcceptFunc(unsigned int v);

void _DWCi_MOV_ReadyMovUserID(void)
{
    func_021D45E0();
    DWCi_MOV_WH_SetJudgeAcceptFunc((unsigned int)((void *)0x021D45A4));
    *(unsigned char *)(*(char **)0x021DE668 + 0xa90) = 8;
}
