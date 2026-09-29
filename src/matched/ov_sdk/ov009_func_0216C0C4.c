/*
 * function: func_0216C0C4
 * address:  0x0216C0C4
 * packet:   pkt_ov009_0216C0C4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GPRecvBuddyMessageCallback (libdwcmatch.TWL.HYB.a(dwc_main.o))
 *
 * symbols:
 *   strlen         0x0209477C  arm
 *   memcmp         0x020923F0  arm
 *   strchr         0x02094A28  arm
 *   strncpy        0x02094860  arm
 *   strtoul        0x02095EAC  arm
 *   func_0216EAB8  0x0216EAB8  arm  ov009
 *   g_021A2030     0x021A2030  data
 *   g_021A2038     0x021A2038  data
 *   g_021AA878     0x021AA878  data
 */

#include "../arm9_sdk/libc/string.h"

typedef unsigned char u8;

typedef struct {
    int profile;
    int pad4;
    char *message;
} GPRecvBuddyMessageArg;

typedef struct {
    char pad0[0x24];
    int state;
    char pad28[0x33c];
    volatile u8 mode;   /* volatile: the image reloads it for each compare */
} Ctl;

typedef struct {
    int pad;
    Ctl *ctl;
} Root;

extern char g_021A2030[];
extern char g_021A2038[];
extern Root g_021AA878;
extern int memcmp(const void *a, const void *b, unsigned long n);
extern char *strchr(const char *s, int c);
extern char *strncpy(char *d, const char *s, unsigned long n);
extern unsigned long strtoul(const char *s, char **end, int base);
extern void func_0216EAB8(void **pconnection, int profileID, char *message);

void func_0216C0C4(void **pconnection, GPRecvBuddyMessageArg *arg)
{
    unsigned long len;
    char *message;
    char version[12] = {0};

    message = arg->message;
    if (memcmp(message, g_021A2030, strlen(g_021A2030)) != 0)
        return;
    message += strlen(g_021A2030);
    len = strchr(message, 'v') - message;
    strncpy(version, message, len);
    if (len > 10)
        return;
    if (strtoul(version, 0, 10) != 90)
        return;
    message += len + 1;
    if (memcmp(message, g_021A2038, strlen(g_021A2038)) != 0)
        return;
    if (g_021AA878.ctl->state != 4) {
        if (g_021AA878.ctl->state != 5)
            return;
        if (g_021AA878.ctl->mode != 2 && g_021AA878.ctl->mode != 3)
            return;
    }
    func_0216EAB8(pconnection, arg->profile, message + strlen(g_021A2038));
}
