/*
 * function: func_0217A034
 * address:  0x0217A034
 * packet:   pkt_ov015_0217A034
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * notes:    w9_nm2: DIFF 10 B (was 16). A dedicated local buf = g_0217ABD8 assigned after the copy loop (declared before pHeader) puts i in ip and the pointers in r6/r5; the final call keeps the pool word. Left: object stores sumLo before sumHi (scheduler swaps; tried order, masks, byte pointer, locals) and loop 2 counter is r1 not ip (tried i=0 hoists).
 * sdk:      IRCi_Send (libirc.a irc.o)
 *
 * symbols:
 *   func_02179EE0  0x02179EE0  arm  ov015
 *   func_0217A8EC  0x0217A8EC  arm  ov015
 *   g_0217ABD8     0x0217ABD8  data
 *   g_0217ABDC     0x0217ABDC  data
 */

typedef struct {
    unsigned char command;
    unsigned char id;
    unsigned char sumLo;
    unsigned char sumHi;
} IRCHeader;

extern unsigned short func_02179EE0(void *input, unsigned long length);
extern void func_0217A8EC(unsigned char *data, unsigned char size);
extern unsigned char g_0217ABD8[184];
extern unsigned char g_0217ABDC[184];

void func_0217A034(unsigned char *data, unsigned char size, unsigned char command, unsigned char id)
{
    unsigned char *p;
    unsigned short sum;
    int i;
    unsigned char *buf;
    IRCHeader *pHeader;

    pHeader = (IRCHeader *)g_0217ABD8;
    pHeader->command = command;
    pHeader->id = id;
    pHeader->sumLo = 0;
    pHeader->sumHi = 0;
    p = g_0217ABDC;
    for (i = 0; (i < size) ? 1 : 0; i++)
        *p++ = *data++;
    size += 4;
    buf = g_0217ABD8;
    sum = func_02179EE0(buf, size);
    pHeader->sumLo = sum;
    pHeader->sumHi = sum >> 8;
    for (i = 0; (i < size) ? 1 : 0; i++)
        buf[i] ^= 0xAA;
    func_0217A8EC(g_0217ABD8, size);
}
