/*
 * file:     unit_02193D00_p01.c
 * unit:     yes
 * function: func_02193D00, func_02193D64, func_02193D80
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
 */
#include "../../matched/include/G_StatsSocket.h"
#include "../../matched/include/G_StatsConn.h"

typedef struct {
    int pad;
    int sock;
} StatsSocket;

typedef struct {
    char pad0[8];
    int inLen;
    char pad1[0xc];
    int inSize;
    char pad2[0xc];
    char *inBuff;
    int state;
} StatsConn;

extern int func_0217EB9C(int sock, int how);
extern int func_0217EB2C(int sock);
extern void func_02194614(void);
extern void func_0217EAE0(void *ptr);
extern int func_02193FE8(int s);
extern void *func_0217EAC8(void *ptr, unsigned long size);
extern int func_0217EC4C(int sock, char *buf, int len, int flags);
extern int func_02194494(char *buff, int len);
extern void *func_02092364(void *dest, const void *src, unsigned int n);
void func_02193D00(void);
int func_02193D64(void);
int func_02193D80(void);
extern struct StatsSocket g_021A57C8;
extern struct StatsConn g_021ADFE0;


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
    if (((int *)&g_021ADFE0)[10] != 0) {
        func_0217EAE0((void *)((int *)&g_021ADFE0)[10]);
        ((int *)&g_021ADFE0)[10] = 0;
        ((int *)&g_021ADFE0)[6] = 0;
        ((int *)&g_021ADFE0)[2] = 0;
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
