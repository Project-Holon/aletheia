/*
 * function: func_021BA67C
 * address:  0x021BA67C
 * packet:   pkt_ov016_021BA67C
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * sdk:      StoreNetParam (libdwcutil.TWL.HYB.a atermset.o)
 *
 * symbols:
 *   strcpy  0x02094798  arm
 *   memcpy  0x02092344  arm
 *   strlen  0x0209477C  arm
 *   func_021BA5C8  0x021BA5C8  thumb  ov016
 *   g_021DD13C  0x021DD13C  data
 *   g_021DD150  0x021DD150  data
 *   g_021DD164  0x021DD164  data
 *   g_021DD1E4  0x021DD1E4  data
 *   g_021DD324  0x021DD324  data
 *   g_021DD350  0x021DD350  data
 *   g_021DD388  0x021DD388  data
 *   g_021DD420  0x021DD420  data
 */

#include "../arm9_sdk/libc/string.h"
#include "../include/G__ATERMApConfigParam.h"
typedef struct {
    int type;
    int defkey;
} EncCommon;

extern int func_021BA5C8(unsigned char *byDest, char *szStr, int nLen);
extern struct _ATERMApConfigParam g_021DD13C;
extern struct {
    int pad[3];
    int auth_mode;
    int wepkeyid;
} g_021DD150;
extern char g_021DD164[4][32];
typedef struct { int w[16]; } Key64;
extern Key64 g_021DD1E4;
extern char g_021DD324[];
extern EncCommon g_021DD350;
extern char g_021DD388[4][0x28];
extern Key64 g_021DD420;

int func_021BA67C(void)
{
    char szwep[36];
    int i;
    int defkey;
    char *lpwep;
    int ret;

    ret = 1;
    strcpy(((char *)&g_021DD13C), g_021DD324);
    switch (g_021DD350.type) {
    case 0:
        g_021DD150.auth_mode = 0;
        break;
    case 1:
        defkey = g_021DD350.defkey;
        if (defkey == 0) {
            ret = -7;
            break;
        }
        g_021DD150.wepkeyid = defkey;
        for (i = 0; i < 4; i++) {
            lpwep = szwep;
            memcpy(szwep, g_021DD388[i], 32);
            szwep[32] = 0;
            switch (strlen(szwep)) {
            case 0:
                break;
            case 5:
                g_021DD150.auth_mode = 1;
                memcpy(g_021DD164[i], lpwep, 5);
                break;
            case 10:
                g_021DD150.auth_mode = 1;
                func_021BA5C8((unsigned char *)g_021DD164[i], lpwep, 10);
                break;
            case 13:
                g_021DD150.auth_mode = 2;
                memcpy(g_021DD164[i], lpwep, 13);
                break;
            case 26:
                g_021DD150.auth_mode = 2;
                func_021BA5C8((unsigned char *)g_021DD164[i], lpwep, 26);
                break;
            case 16:
                g_021DD150.auth_mode = 3;
                memcpy(g_021DD164[i], lpwep, 16);
                break;
            case 32:
                g_021DD150.auth_mode = 3;
                func_021BA5C8((unsigned char *)g_021DD164[i], lpwep, 32);
                break;
            default:
                ret = -7;
                break;
            }
        }
        break;
    case 2:
        g_021DD150.auth_mode = 4;
        memcpy(&g_021DD1E4, &g_021DD420, 64);
        break;
    case 3:
        g_021DD150.auth_mode = 5;
        memcpy(&g_021DD1E4, &g_021DD420, 64);
        break;
    default:
        ret = -7;
        break;
    }
    return ret;
}
