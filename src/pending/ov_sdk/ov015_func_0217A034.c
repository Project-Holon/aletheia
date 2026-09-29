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
    sum = func_02179EE0(g_0217ABD8, size);
    pHeader->sumLo = sum;
    pHeader->sumHi = sum >> 8;
    for (i = 0; (i < size) ? 1 : 0; i++)
        g_0217ABD8[i] ^= 0xAA;
    func_0217A8EC(g_0217ABD8, size);
}
