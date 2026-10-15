/*
 * function: GDS_SOCKET_OpenAndResolve
 * address: 0x021D7E80
 * packet: pkt_ov125_021D7E80
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * lever: final halfword swap ORs the right-shifted half before the left-shifted half; reversing them left two byte mismatches.
 * symbols:
 *   gGdsSocket 0x021D9E40 data a4
 *   gGdsHostName 0x021D9F80 data a4
 *   gGdsSslConnection 0x021DA258 data a4
 *   func_0215F428 0x0215F428 arm ov009
 *   GDS_SOCKET_ResolveHost 0x021D7E20 arm ov125
 *   CPS_Resolve 0x0215C910 arm ov009
 *   GDS_SOCKET_CopySslTemplate 0x021D8C14 arm ov125
 *   SOCL_EnableSsl 0x0215FC80 arm ov009
 */

#include "../include/G_Clear.h"

typedef unsigned int u32;
typedef unsigned char u8;
extern struct Clear gGdsSocket;
extern char gGdsHostName[];
extern u8 gGdsSslConnection[];
extern int func_0215F428(int, int, int);
extern int GDS_SOCKET_ResolveHost(const char *, char *);
extern unsigned long CPS_Resolve(char *name);
extern void GDS_SOCKET_CopySslTemplate(const char *, u8 *);
extern int SOCL_EnableSsl(int s, void *con);
int GDS_SOCKET_OpenAndResolve(void)
{
    char out[16];
    u32 value;
    ((u32 *)&gGdsSocket)[0x26c/4] = func_0215F428(2, 1, 0);
    if (((u32 *)&gGdsSocket)[0x26c/4] == -1u) {
        ((u32 *)&gGdsSocket)[0x250/4] = 3;
        return 0;
    }
    if (!GDS_SOCKET_ResolveHost(gGdsHostName, out)) {
        ((u32 *)&gGdsSocket)[0x250/4] = 5;
        return 0;
    }
    value = CPS_Resolve(out);
    value = ((value >> 8) & 0x00ff00ff) | ((value << 8) & 0xff00ff00);
    ((u32 *)&gGdsSocket)[0x264/4] = (value >> 16) | (value << 16);
    GDS_SOCKET_CopySslTemplate(gGdsHostName, gGdsSslConnection);
    if (SOCL_EnableSsl(((u32 *)&gGdsSocket)[0x26c/4], gGdsSslConnection) < 0) {
        ((u32 *)&gGdsSocket)[0x250/4] = 15;
        return 0;
    }
    return 1;
}
