/*
 * file:     unit_02166384_p03.c
 * unit:     yes
 * function: func_021665E4, func_02166600
 * address:  0x021665E4
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
 *   g_021AA80C  0x021AA80C  data
 *   MI_CpuCopy  0x02082EA4  arm
 */
extern void func_02082EA4(char *p, int a, int n);
extern void MI_CpuCopy(void *src, void *dst, unsigned long size);
void func_021665E4(int a);
unsigned long func_02166600(unsigned char deviceId, unsigned short *sendBuf, void *header, unsigned long headerLen, void *body, unsigned long bodyLen);
extern char g_021AA80C[];


/*
 * Copies six bytes to the object at 0x021AA80C.
 */
void func_021665E4(int a)
{
    func_02082EA4(g_021AA80C, a, 6);
}


/*
 * sdk:      WCMi_MergeToBuffer (libwcm.TWL.HYB.a cpsif.o)
 *
 * Merges a frame header and body into the send buffer; device 2 prefixes a byte-swapped length word.
 * Earlier waves parked this as a store-motion wall (shared case-1/default `copyDest = sendBuf`
 * hoisted above the compares). It was register coalescing: with no interference the copy merged
 * sendBuf and copyDest into r6 at entry. 2026-10-01 lane22 closed it: case 2 assigns copyDest
 * before the length store through sendBuf, so both are live together and stay apart; the swap is
 * high-byte-first with an unsigned 0xff00U mask (lsr, operand order).
 */
unsigned long func_02166600(unsigned char deviceId, unsigned short *sendBuf, void *header, unsigned long headerLen, void *body, unsigned long bodyLen)
{
    void *copyDest;
    unsigned long totalLen;
    totalLen = headerLen + bodyLen;
    switch (deviceId) {
    case 1:
    default:
        copyDest = sendBuf;
        break;
    case 2:
        copyDest = sendBuf + 7;
        sendBuf[6] = (unsigned short)((((unsigned short)totalLen & 0xff00U) >> 8) | (((unsigned short)totalLen & 0xff) << 8));
        totalLen += 0xE;
        break;
    }
    MI_CpuCopy(header, copyDest, headerLen);
    if (body != 0 && bodyLen != 0) {
        MI_CpuCopy(body, (unsigned char *)copyDest + headerLen, bodyLen);
    }
    return totalLen;
}
