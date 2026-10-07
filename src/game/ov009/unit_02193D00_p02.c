/*
 * file:     unit_02193D00_p02.c
 * unit:     yes
 * function: func_02193EB8, func_02193F00, func_02193FD0
 * address:  0x02193EB8
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021A57C8   0x021A57C8  data
 *   func_020948B0 0x020948B0  arm
 *   func_02094B20 0x02094B20  arm
 *   func_0209477C 0x0209477C  arm
 *   @13818       0x021A1A64  data
 *   g_021ADFE0   0x021ADFE0  data
 *   g_021A5894   0x021A5894  data
 *   g_021AE21C   0x021AE21C  data
 *   g_021A5890  0x021A5890  data
 */
#include "../../matched/include/G_StatsSocket.h"

typedef unsigned char  u8;

extern u8 *func_020948B0(u8 *dest, const u8 *src);
extern char *func_02094B20(const char *s, const char *sub);
extern int func_0209477C(const u8 *s);
void func_02193EB8(char *buf, int len);
char *func_02193F00(char *s, char *key);
char *func_02193FD0(char *s, char *key);
extern struct StatsSocket g_021A57C8;
extern char g_021A1A64[];
extern int g_021ADFE0[];
extern char g_021A5894[];
extern char g_021AE21C[];
extern char g_021A5890[];


/*
 * sdk:      xcode_buf (gstats.o)
 */
void func_02193EB8(char *buf, int len)
{
    int i;
    char *pos;

    pos = (*(char * *)&g_021A57C8);
    for (i = 0; i < len; i++) {
        buf[i] ^= *pos;
        pos++;
        if (*pos == 0)
            pos = (*(char * *)&g_021A57C8);
    }
}


/*
 * sdk:      value_for_key (gstats.o)
 *
 * value_for_key. The keyspec initializer is the vendor template @13818 at 0x021A1A64
 * (template class, overlay scope). strcat 0x020948B0 attests as matched through
 * unit_02094860, whose functions list names func_020948B0 since 2026-09-29 (w4_nm).
 */
char *func_02193F00(char *s, char *key)
{
    char keyspec[256] = "\\";
    char *pos;
    char *pos2;

    g_021ADFE0[8] ^= 1;
    func_020948B0((u8 *)keyspec, (const u8 *)key);
    func_020948B0((u8 *)keyspec, (const u8 *)g_021A5894);
    pos = func_02094B20(s, keyspec);
    if (pos == 0)
        return 0;
    pos += func_0209477C((const u8 *)keyspec);
    pos2 = g_021AE21C + g_021ADFE0[8] * 256;
    while (*pos != 0 && *pos != 0x5c)
        *pos2++ = *pos++;
    *pos2 = 0;
    return g_021AE21C + g_021ADFE0[8] * 256;
}


/*
 * The module block when the test passes, else the fallback object.
 */
char *func_02193FD0(char *s, char *key)
{
    char *p = func_02193F00(s, key);

    return p ? p : g_021A5890;
}
