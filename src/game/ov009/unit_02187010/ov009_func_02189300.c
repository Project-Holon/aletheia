/*
 * function: func_02189300
 * address:  0x02189300
 * packet:   pkt_ov009_02189300
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiBuddyDeletedLocally (gpibuddy.o)
 *
 * symbols:
 *   func_02193734  0x02193734  arm   ov009
 *   func_0218FD9C  0x0218FD9C  arm   ov009
 *   g_021A446C     0x021A446C  data  ov009
 */

typedef struct GPIProfile {
    unsigned char pad[0x2C];
    int f2C;
} GPIProfile;

extern void func_02193734(int *p, int b);
extern int func_0218FD9C(void **connection, int profileid, GPIProfile **pProfile);
extern char g_021A446C[];

int func_02189300(void **connection, int id, int isDeleted)
{
    GPIProfile *pProfile;

    if (id <= 0) {
        func_02193734((int *)connection, (int)g_021A446C);
        return 2;
    }
    if (func_0218FD9C(connection, id, &pProfile))
        pProfile->f2C = isDeleted;
    return 0;
}
