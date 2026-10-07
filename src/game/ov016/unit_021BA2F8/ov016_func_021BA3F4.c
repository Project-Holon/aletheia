/*
 * function: func_021BA3F4
 * address:  0x021BA3F4
 * packet:   pkt_ov016_021BA3F4
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * sdk:      GetWLanSetElement (libdwcutil.TWL.HYB.a(atermset.o))
 *
 * symbols:
 *   memcpy  0x02092344  arm
 *   memset  0x020923B0  arm
 *   func_021B9F5C  0x021B9F5C  thumb  ov016
 *   func_021BC5D4  0x021BC5D4  thumb  ov016
 *   g_021DD224  0x021DD224  data
 *   g_021DD324  0x021DD324  data
 *   g_021DD350  0x021DD350  data
 *   g_021DD388  0x021DD388  data
 *   g_021DD420  0x021DD420  data
 */

#include "../../../matched/arm9_sdk/libc/string.h"

typedef unsigned char u8;
typedef unsigned short u16;

#define SWAP16(x) ((u16)((((x) >> 8) & 0xff) | (((x) << 8) & 0xff00)))

extern u8 *func_021B9F5C(u8 **lplpb, u8 *lplimit, int *pid, int *psize);
extern int func_021BC5D4(char *lpwrite, char ch);

typedef struct {
    int keyType;
    int keyLen;
    char key[32];
} WepEntry;

extern struct {
    char pad[0x15c];
    WepEntry wep[4];
} g_021DD224;
extern struct { int w[8]; } g_021DD324;
extern struct {
    int type;
    int defkey;
    char pad[0x28];
    int f30;
} g_021DD350;
extern char g_021DD388[4][0x28];
extern struct { int w[18]; } g_021DD420;

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
