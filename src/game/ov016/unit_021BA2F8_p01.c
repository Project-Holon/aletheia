/*
 * file:     unit_021BA2F8_p01.c
 * unit:     yes
 * function: func_021BA2F8, func_021BA3F4, AsciiToHex, func_021BA67C
 * address:  0x021BA2F8
 * region:   ov016
 * compiler: dsi/../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BA2EC  0x021ba2ec  thumb  ov016
 *   func_020923F0  0x020923f0  arm
 *   func_021BC608  0x021bc608  thumb  ov016
 *   g_021DAC18  0x021dac18  data
 *   g_021DD480  0x021dd480  data
 *   g_021DD478  0x021dd478  data
 *   g_021DAB58  0x021dab58  data
 *   memcmp  0x020923F0  arm
 *   memcpy  0x02092344  arm
 *   memset  0x020923B0  arm
 *   func_021B9F5C  0x021B9F5C  thumb  ov016
 *   func_021BC5D4  0x021BC5D4  thumb  ov016
 *   g_021DD224  0x021DD224  data
 *   g_021DD324  0x021DD324  data
 *   g_021DD350  0x021DD350  data
 *   g_021DD388  0x021DD388  data
 *   g_021DD420  0x021DD420  data
 *   strcpy  0x02094798  arm
 *   strlen  0x0209477C  arm
 *   func_021BA5C8  0x021BA5C8  thumb  ov016
 *   g_021DD13C  0x021DD13C  data
 *   g_021DD150  0x021DD150  data
 *   g_021DD164  0x021DD164  data
 *   g_021DD1E4  0x021DD1E4  data
 */
#include "../../matched/arm9_sdk/libc/string.h"
#include "../../matched/include/G__ATERMApConfigParam.h"

#define SWAP16(x) ((u16)((((x) >> 8) & 0xff) | (((x) << 8) & 0xff00)))
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    int keyType;
    int keyLen;
    char key[32];
} WepEntry;

typedef struct {
    int type;
    int defkey;
    char pad[0x28];
    int f30;
} EncCommon;

typedef struct { int w[18]; } Key72;

typedef struct { int w[16]; } Key64;

extern int func_021BA2EC(unsigned char *lpmac);
extern int memcmp(const void *a, const void *b, unsigned long n);
extern int func_021BC608(char *lpwrite, char *lps);
extern u8 *func_021B9F5C(u8 **lplpb, u8 *lplimit, int *pid, int *psize);
extern int func_021BC5D4(char *lpwrite, char ch);
extern int func_021BA5C8(unsigned char *byDest, char *szStr, int nLen);
int func_021BA2F8(unsigned char *lpkey);
int func_021BA3F4(u8 *lpelement);
int AsciiToHex(unsigned char *byDest, char *szStr, int nLen);
int func_021BA67C(void);
extern const unsigned char g_021DAC18[];
extern unsigned char g_021DD480[6];
extern unsigned char g_021DD478[6];
extern unsigned char *g_021DAB58[];
extern struct {
    char pad[0x15c];
    WepEntry wep[4];
} g_021DD224;
extern struct { int w[8]; } g_021DD324;
extern EncCommon g_021DD350;
extern char g_021DD388[4][0x28];
extern Key72 g_021DD420;
extern struct _ATERMApConfigParam g_021DD13C;
extern struct {
    int pad[3];
    int auth_mode;
    int wepkeyid;
} g_021DD150;
extern char g_021DD164[4][32];
extern Key64 g_021DD1E4;




/*
 * sdk:      GetMacEncKey (libdwcutil.TWL.HYB.a(atermset.o))
 */
int func_021BA2F8(unsigned char *lpkey)
{
    char strmac[32];
    char strap[32];
    unsigned char ap_mac[6];
    unsigned char sta_mac[6];
    int ret;

    memcpy(lpkey + 12, g_021DAC18, 4);
    memcpy(ap_mac, g_021DD480, 6);
    ap_mac[0] &= 0xfd;
    func_021BA2EC(sta_mac);
    memcpy(g_021DD478, sta_mac, 6);
    ret = memcmp(ap_mac, sta_mac, 6);
    if (ret <= 0) {
        memcpy(lpkey, sta_mac, 6);
        memcpy(lpkey + 6, ap_mac, 6);
    } else {
        memcpy(lpkey, ap_mac, 6);
        memcpy(lpkey + 6, sta_mac, 6);
    }
    if (g_021DAB58[1]) {
        func_021BC608(strmac, (char *)sta_mac);
        func_021BC608(strap, (char *)ap_mac);
    }
    return 1;
}




int func_021BA3F4(u8 *lpelement)
{
    int retv;
    u8 *lpb;
    u8 *lpw;
    int eid;
    int esize;
    int i;
    u16 len;
    u8 *lpe;
    char *wp;

    lpe = lpelement;
    lpe += 8;
    lpb = lpe;
    retv = 0;
    len = SWAP16(*(u16 *)lpelement);
    while ((lpw = func_021B9F5C(&lpb, lpe + len, &eid, &esize)) != 0) {
        switch (eid) {
        case 0x201:
            __builtin__clear(&g_021DD324, 32);
            memcpy(&g_021DD324, lpw, esize);
            retv = 1;
            break;
        case 0x202:
            g_021DD350.type = SWAP16(*(u16 *)lpw);
            break;
        case 0x203:
            {
                u16 v = SWAP16(*(u16 *)lpw);
                for (i = 0; i < 4; i++)
                    g_021DD224.wep[i].keyType = v;
            }
            break;
        case 0x204:
            {
                u16 v = SWAP16(*(u16 *)lpw);
                for (i = 0; i < 4; i++)
                    g_021DD224.wep[i].keyLen = v;
            }
            break;
        case 0x205:
            g_021DD350.defkey = SWAP16(*(u16 *)lpw);
            break;
        case 0x206:
        case 0x207:
        case 0x208:
        case 0x209:
            memset(g_021DD388[eid - 0x206], 0, 32);
            if (g_021DD350.f30 == 1) {
                wp = g_021DD388[eid - 0x206];
                for (i = 0; i < esize; i++)
                    wp += func_021BC5D4(wp, *(char *)lpw++);
            } else {
                memcpy(g_021DD388[eid - 0x206], lpw, esize);
            }
            break;
        case 0x20a:
            __builtin__clear(&g_021DD420, 72);
            memcpy(&g_021DD420, lpw, esize);
            break;
        }
    }
    return retv;
}


int AsciiToHex(unsigned char *byDest, char *szStr, int nLen)
{
    int ch;
    int b;
    int i;

    b = 0;
    for (i = 0; i < nLen; i++) {
        ch = szStr[i];
        switch (ch) {
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            b += ch - '0';
            break;
        case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
            b += ch - 'a' + 10;
            break;
        case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
            b += ch - 'A' + 10;
            break;
        default:
            return 0;
        }
        if (i % 2 == 0) {
            b <<= 4;
        } else {
            byDest[i / 2] = b;
            b = 0;
        }
    }
    return 1;
}


int func_021BA67C(void)
{
    char szwep[36];
    int i;
    int defkey;
    char *lpwep;
    int ret;

    ret = 1;
    strcpy(((char *)&g_021DD13C), (char *)&g_021DD324);
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
