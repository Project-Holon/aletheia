/*
 * function: VCT_SESSION_SendCommand
 * address:  0x021B2564
 * packet:   pkt_ov013_021B2564
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   VCT_SESSION_BuildGroupCommand  0x021B2010  arm  ov013
 *   VCT_SESSION_SendPacket  0x021B275C  arm  ov013
 */

typedef unsigned char u8;

extern int VCT_SESSION_BuildGroupCommand(void *a, unsigned int b, unsigned char *buf, unsigned int c);
extern int VCT_SESSION_SendPacket(u8 *o, u8 *p);

int VCT_SESSION_SendCommand(int a, int b)
{
    u8 buf[16];
    int r;

    r = VCT_SESSION_BuildGroupCommand((void *)a, b, buf, 16);
    if (r != 0)
        return r;
    if (VCT_SESSION_SendPacket((u8 *)a, buf) != 0)
        return 0;
    return -4;
}
