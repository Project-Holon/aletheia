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
 * u21: the defining object cpsif.o is .comment 4.0.0.1024 -> dsi/1.1p1. The image lowers
 *      `case 1:` + `default:` as cmp r0,#1 / beq <default body> / cmp r0,#2 / beq <case 2>, with the
 *      default body as the fall-through and a single `mov r6,r1`; 1.1p1 hoists that store above both
 *      compares, which is the whole 8-byte shortfall (120 vs 128). First divergence +000C
 *      image `cmp r0, #1` | ours `mov r6, r1`. Every switch spelling (case order, default alone,
 *      default first) hoists the store.
 * u1: re-measured, unchanged at 120 B vs 128 B.
 *
 * w9_nm: the object tests deviceId == 1 first, then == 2, then falls into the default mov r6,r1 without hoisting it; every switch spelling hoists mov r6,r1 above the compares (case 1 split from default, default alone, assignment before the switch, default last). The byte swap also differs: use ((len & 0xff) << 8) | ((len & 0xff00) >> 8) for the object's lsl 24 / lsr 16 form. Best 84 B with default listed first.
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
