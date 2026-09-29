/*
 * function: func_021C1048
 * address:  0x021C1048
 * packet:   pkt_ov016_021C1048
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_MSGlGetEx (libdwcutil.TWL.HYB.a message.o)
 *
 * symbols:
 */

typedef struct MsgPrm {
    unsigned int *index;
    unsigned char *data;
} MsgPrm;

unsigned short *func_021C1048(void *msg, int id, int n, int num)
{
    MsgPrm *ms = msg;
    unsigned short *str = (unsigned short *)(ms->data + ms->index[(unsigned short)id]);
    if (n >= 0)
        str[n] = num + 0x30;
    return str;
}
