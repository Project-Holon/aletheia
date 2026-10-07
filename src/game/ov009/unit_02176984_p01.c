/*
 * file:     unit_02176984_p01.c
 * unit:     yes
 * function: func_02176984, func_021769E0, func_02176A8C
 * address:  0x02176984
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
 *   func_021684CC  0x021684CC  arm
 *   sub_02095EAC   0x02095EAC  arm
 *   g_021A21C8     0x021A21C8  data
 *   g_021A21E8     0x021A21E8  data
 *   g_021A2208     0x021A2208  data
 *   g_021A222C     0x021A222C  data
 *   g_021A224C     0x021A224C  data
 *   g_021A2280     0x021A2280  data
 *   g_021A22C4     0x021A22C4  data
 *   g_021A22F0     0x021A22F0  data
 *   g_021A2324     0x021A2324  data
 *   g_021A2340     0x021A2340  data
 *   g_021AAA20  0x021AAA20  data
 */
#include "../../matched/include/G_NNThinkGlobal.h"

typedef unsigned int   u32;

extern int func_021684CC(char *key, char *value, char *string, char separator);
extern u32 sub_02095EAC(u32 a0, u32 *a1, u32 mode);
extern unsigned long long func_020870D0(int a);
unsigned char func_02176984(char *a0);
char *func_021769E0(unsigned char denyReason);
void func_02176A8C(int a, int b);
extern char g_021A21C8[];
extern char g_021A21E8[];
extern char g_021A2208[];
extern char g_021A222C[];
extern char g_021A224C[];
extern char g_021A2280[];
extern char g_021A22C4[];
extern char g_021A22F0[];
extern char g_021A2324[];
extern char g_021A2340[];
extern struct NNThinkGlobal g_021AAA20;


unsigned char func_02176984(char *a0)
{
    char buf[4] = {0};
    unsigned char r = 0;

    if (func_021684CC((char *)0x021A208Cu, buf, a0 + 8, 0x2F) > 0)
        r = (unsigned char)sub_02095EAC((u32)buf, 0, 10);
    return r;
}


/*
 * sdk:      DWCi_GetResvDenyReasonString (dwc_match.o)
 */
char *func_021769E0(unsigned char denyReason)
{
    switch (denyReason) {
    case 0x10:
        return g_021A21C8;
    case 0x11:
        return g_021A21E8;
    case 0x12:
        return g_021A2208;
    case 0x13:
        return g_021A222C;
    case 0x14:
        return g_021A224C;
    case 0x15:
        return g_021A2280;
    case 0x16:
        return g_021A22C4;
    case 0x17:
        return g_021A22F0;
    case 0x18:
        return g_021A2324;
    default:
        return g_021A2340;
    }
}


/*
 * Stores both words the call returns into the module state block.
 */
void func_02176A8C(int a, int b)
{
    unsigned long long v = func_020870D0(a);

    *(int *)(((char *)&g_021AAA20) + 0x18) = (int)v;
    *(int *)(((char *)&g_021AAA20) + 0x1c) = (int)(v >> 32);
}
