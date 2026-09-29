/*
 * function: func_02166600
 * address:  0x02166600
 * packet:   pkt_ov009_02166600
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF (near miss: copyDest assignment hoisted above the compares, registers shifted)
 *
 * sdk:      WCMi_MergeToBuffer (libwcm.TWL.HYB.a cpsif.o)
 *
 * symbols:
 *   MI_CpuCopy  0x02082EA4  arm
 *
 * Merges a frame header and body into the send buffer; device 2 prefixes a byte-swapped length word.
 */

extern void MI_CpuCopy(void *src, void *dst, unsigned long size);

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
    case 2: {
        unsigned short len = (unsigned short)totalLen;
        sendBuf[6] = (unsigned short)(((unsigned char)len << 8) | (len >> 8));
        copyDest = sendBuf + 7;
        totalLen += 0xE;
        break;
    }
    }
    MI_CpuCopy(header, copyDest, headerLen);
    if (body != 0 && bodyLen != 0) {
        MI_CpuCopy(body, (unsigned char *)copyDest + headerLen, bodyLen);
    }
    return totalLen;
}
