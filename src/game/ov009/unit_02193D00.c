/*
 * file:     unit_02193D00.c
 * unit:     yes
 * function: func_02193D00, func_02193D64, func_02193D80, func_02193EB8, func_02193F00, func_02193FD0
 * address:  0x02193D00
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
 *   func_0217EB9C 0x0217EB9C  arm
 *   func_0217EB2C 0x0217EB2C  arm
 *   func_02194614 0x02194614  arm
 *   func_0217EAE0 0x0217EAE0  arm
 *   g_021A57C8   0x021A57C8  data
 *   g_021ADFE0   0x021ADFE0  data
 *   func_02193FE8  0x02193fe8  arm   ov009
 *   func_0217EAC8  0x0217eac8  arm   ov009
 *   func_0217EC4C  0x0217ec4c  arm   ov009
 *   func_02194494  0x02194494  arm   ov009
 *   func_02092364  0x02092364  arm
 *   func_020948B0 0x020948B0  arm
 *   func_02094B20 0x02094B20  arm
 *   func_0209477C 0x0209477C  arm
 *   g_021A5894   0x021A5894  data
 *   g_021AE21C   0x021AE21C  data
 *   g_021A5890  0x021A5890  data
 *   @13818       0x021A1A64  data
 */
#include "../../matched/include/G_StatsSocket.h"

typedef struct {
    int pad;
    int sock;
} StatsSocket;

struct StatsConn {
    int pad0[2];
    int inLen;
    int pad1[3];
    int inSize;
    int pad2;
    int bufIndex;
    int pad3;
    char *inBuff;
    int state;
};

typedef unsigned char  u8;

extern int func_0217EB9C(int sock, int how);
extern int func_0217EB2C(int sock);
extern void func_02194614(void);
extern void func_0217EAE0(void *ptr);
extern int func_02193FE8(int s);
extern void *func_0217EAC8(void *ptr, unsigned long size);
extern int func_0217EC4C(int sock, char *buf, int len, int flags);
extern int func_02194494(char *buff, int len);
extern void *func_02092364(void *dest, const void *src, unsigned int n);
extern u8 *func_020948B0(u8 *dest, const u8 *src);
extern char *func_02094B20(const char *s, const char *sub);
extern int func_0209477C(const u8 *s);
void func_02193D00(void);
int func_02193D64(void);
int func_02193D80(void);
void func_02193EB8(char *buf, int len);
char *func_02193F00(char *s, char *key);
char *func_02193FD0(char *s, char *key);
extern struct StatsSocket g_021A57C8;
extern struct StatsConn g_021ADFE0;
extern char g_021A1A64[];
extern char g_021A5894[];
extern char g_021AE21C[];
extern char g_021A5890[];



/*
 * sdk:      CloseStatsConnection (gstats.o)
 */
void func_02193D00(void)
{
    if (((int *)&g_021A57C8)[1] != -1) {
        func_0217EB9C(((int *)&g_021A57C8)[1], 2);
        func_0217EB2C(((int *)&g_021A57C8)[1]);
    }
    ((int *)&g_021A57C8)[1] = -1;
    func_02194614();
    if (g_021ADFE0.inBuff != 0) {
        func_0217EAE0((void *)g_021ADFE0.inBuff);
        g_021ADFE0.inBuff = 0;
        g_021ADFE0.inSize = 0;
        g_021ADFE0.inLen = 0;
    }
}



/*
 * Set while the word at +4 of the state object is not -1.
 */
int func_02193D64(void)
{
    return *(int *)(((char *)&g_021A57C8) + 4) != -1;
}



/*
 * sdk:      PersistThink (libdwcgsgstats.TWL.HYB.a gstats.o)
 */
int func_02193D80(void)
{
    int processed;
    int len;

    if (g_021A57C8.sock == -1)
        return 0;
    if (g_021ADFE0.state != 5)
        return 0;
    while (func_02193FE8(g_021A57C8.sock)) {
        if (g_021ADFE0.inSize - g_021ADFE0.inLen < 0x80) {
            len = g_021ADFE0.inSize;
            if (len < 0x100) {
                len = 0x100;
                g_021ADFE0.inSize = len;
            } else {
                len = len * 2;
                g_021ADFE0.inSize = len;
            }
            g_021ADFE0.inBuff = (char *)func_0217EAC8(g_021ADFE0.inBuff, len + 1);
            if (g_021ADFE0.inBuff == 0)
                return 0;
        }
        len = func_0217EC4C(g_021A57C8.sock, g_021ADFE0.inBuff + g_021ADFE0.inLen,
                            g_021ADFE0.inSize - g_021ADFE0.inLen, 0);
        if (len <= 0) {
            func_02193D00();
            return 0;
        }
        g_021ADFE0.inLen += len;
        g_021ADFE0.inBuff[g_021ADFE0.inLen] = 0;
        processed = func_02194494(g_021ADFE0.inBuff, g_021ADFE0.inLen);
        if (processed == g_021ADFE0.inLen) {
            g_021ADFE0.inLen = 0;
        } else {
            func_02092364(g_021ADFE0.inBuff, g_021ADFE0.inBuff + processed, g_021ADFE0.inLen - processed);
            g_021ADFE0.inLen -= processed;
        }
    }
    if (g_021A57C8.sock == -1)
        return 0;
    return 1;
}



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
    char *value;

    g_021ADFE0.bufIndex ^= 1;
    func_020948B0((u8 *)keyspec, (const u8 *)key);
    func_020948B0((u8 *)keyspec, (const u8 *)g_021A5894);
    pos = func_02094B20(s, keyspec);
    if (pos == 0)
        return 0;
    pos += func_0209477C((const u8 *)keyspec);
    value = g_021AE21C + g_021ADFE0.bufIndex * 256;
    pos2 = value;
    while (*pos != 0 && *pos != 0x5c)
        *pos2++ = *pos++;
    *pos2 = 0;
    return value;
}



/*
 * The module block when the test passes, else the fallback object.
 */
char *func_02193FD0(char *s, char *key)
{
    char *p = func_02193F00(s, key);

    return p ? p : g_021A5890;
}
