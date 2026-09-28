/*
 * function: func_0215A900
 * address:  0x0215A900
 * packet:   pkt_ov009_0215A900
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      tcpip (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   func_02157C7C  0x02157C7C  arm  ov009
 *   func_0215A71C  0x0215A71C  arm  ov009
 *   func_02158C68  0x02158C68  arm  ov009
 *   func_02157D48  0x02157D48  arm  ov009
 */

extern unsigned char *func_02157C7C(unsigned long *len);
extern void func_0215A71C(unsigned char *buf, unsigned long len);
extern void func_02158C68(unsigned char *buf, unsigned long len);
extern void func_02157D48(void);

void func_0215A900(void)
{
    unsigned long len;
    unsigned char *buf;

    for (;;) {
        buf = func_02157C7C(&len);
        if (len > 0x22) {
            unsigned short t = *(unsigned short *)(buf + 0xc);
            unsigned short type = (unsigned short)((t >> 8) | (t << 8));

            switch (type) {
            case 0x800:
                func_0215A71C(buf + 0xe, len - 0xe);
                break;
            case 0x806:
                func_02158C68(buf + 0xe, len - 0xe);
                break;
            }
        }
        func_02157D48();
    }
}
