/*
 * file:     unit_02176DEC_p01.c
 * unit:     yes
 * function: func_02176DEC, func_02176DFC
 * address:  0x02176DEC
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02059F38          0x02059F38  arm
 *   DWC_IsValidAID         0x0216B94C  arm  ov009
 *   DWCi_IsValidAID        0x0216BC3C  arm  ov009
 *   func_02177788          0x02177788  arm  ov009
 *   DWCs_GetOutgoingBufferFreeSize  0x02177E64  arm  ov009
 *   DWCs_GetRequiredHeaderSize      0x0217721C  arm  ov009
 *   func_02176BE4          0x02176BE4  arm  ov009
 */
extern int func_02059F38(void);
extern int DWC_IsValidAID(int aid);
extern int DWCi_IsValidAID(int aid);
extern unsigned char func_02177788(int i);
extern int DWCs_GetOutgoingBufferFreeSize(int aid);
extern int DWCs_GetRequiredHeaderSize(int type);
extern int func_02176BE4(void);
int func_02176DEC(int a);
int func_02176DFC(int aid, int type);


/*
 * Tail call that supplies the second argument 1.
 */
int func_02176DEC(int a)
{
    return func_02176DFC(a, 1);
}


/*
 * sdk:      DWCi_IsSendableReliable (libdwcmatch.TWL.HYB.a dwc_transport.o)
 */
int func_02176DFC(int aid, int type)
{
    long freeSpace;

    if (func_02059F38() != 0 || (type == 1 && DWC_IsValidAID(aid) == 0))
        return 0;
    if (DWCi_IsValidAID(aid) == 0)
        return 0;
    if (func_02177788(aid) == 1)
        return 0;
    freeSpace = DWCs_GetOutgoingBufferFreeSize(aid);
    if (freeSpace < DWCs_GetRequiredHeaderSize(type))
        return 0;
    return func_02176BE4() != 0;
}
