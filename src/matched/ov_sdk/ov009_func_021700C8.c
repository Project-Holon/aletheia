/*
 * function: DWCi_EncodeBinaryMsgCommand
 * address:  0x021700C8
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_EncodeBinaryMsgCommand (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * The 5-byte identifier copy is an inlined `strcpy` of the 4-character
 * keyword literal (vendor template @24369 at 0x021A2188) into the 4-byte
 * identifier; the version word at +4 then overwrites the NUL. Spelling it as a
 * struct copy from an extern gave the same instructions with the pool base in
 * r0 instead of ip (20 B); through strcpy the registers match.
 *
 * symbols:
 *   @24369         0x021A2188  data
 *   MIi_CpuCopy32  0x02082A90  arm
 *   func_02175F3C  0x02175F3C  arm  ov009
 */

#include "../../matched/arm9_sdk/libc/string.h"

typedef struct DWCstBinaryMessageHeader {
    char identifier[4];
    unsigned long version;
    unsigned char command;
    unsigned char size;
    unsigned short qr2Port;
    unsigned long qr2IP;
    int profileID;
} DWCstBinaryMessageHeader;

typedef struct DWCstBinaryMessage {
    DWCstBinaryMessageHeader header;
    unsigned long data[32];
} DWCstBinaryMessage;

extern void MIi_CpuCopy32(void *srcp, void *destp, unsigned long size);
extern char *func_02175F3C(void);

void DWCi_EncodeBinaryMsgCommand(DWCstBinaryMessage *message, unsigned char command, unsigned long *data, int len)
{
    if (data == 0 || len == 0) {
        len = 0;
    } else {
        MIi_CpuCopy32(data, message->data, len * 4);
    }
    strcpy(message->header.identifier, "\xbbI\xccM");
    message->header.version = 0x5a;
    message->header.command = command;
    message->header.size = len * 4;
    message->header.qr2Port = *(unsigned short *)(func_02175F3C() + 0x5d4);
    message->header.qr2IP = *(unsigned long *)(func_02175F3C() + 0x5d8);
    message->header.profileID = *(int *)(func_02175F3C() + 0x678);
}
