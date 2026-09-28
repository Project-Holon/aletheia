/*
 * function: gt2Send
 * address:  0x02195CC0
 * packet:   pkt_ov009_02195CC0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gt2Send (libdwcgsgt2.TWL.HYB.a gt2main.o)
 * symbols:
 *   gti2MessageCheck        0x02198808 arm
 *   ArrayLength             0x02184200 arm
 *   gti2SendFilterCallback  0x02195278 arm
 *   gti2Send                0x02197CE0 arm
 */

extern void gti2MessageCheck(unsigned char **message, int *len);
extern int ArrayLength(void *array);
extern int gti2SendFilterCallback(void *connection, int filterID,
    unsigned char *message, int len, int reliable);
extern int gti2Send(void *connection, unsigned char *message, int len, int reliable);

int gt2Send(void *connection, unsigned char *message, int len, int reliable)
{
    unsigned short vdpDataLength;

    if (*(int *)((char *)connection + 0xc) != 5)
        return 8;
    gti2MessageCheck(&message, &len);
    if (reliable) {
        char *p = *(char **)((char *)connection + 8);

        if (*(int *)(p + 0x40) == 2) {
            unsigned char *b = (unsigned char *)&vdpDataLength;

            b[0] = message[0];
            b[1] = message[1];
            if (len != vdpDataLength + *(int *)(p + 0x44))
                return 9;
        }
    }
    if (ArrayLength(*(void **)((char *)connection + 0x98)) != 0) {
        gti2SendFilterCallback(connection, 0, message, len, reliable);
        return 0;
    }
    return gti2Send(connection, message, len, reliable) ? 0 : 0xa;
}
