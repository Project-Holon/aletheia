/*
 * function: GDS_SOCKET_ResolveHost
 * address: 0x021D7E20
 * packet: pkt_ov125_021D7E20
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   GDS_SOCKET_IsDottedQuad 0x021D7D88 arm ov125
 *   SOC_GetHostByName 0x0215F650 arm ov009
 *   func_0215FA9C 0x0215FA9C arm ov009
 *   strcpy  0x02094798  arm  arm9
 */
#include "../include/Obj23010.h"
extern int GDS_SOCKET_IsDottedQuad(const char *);
extern void *SOC_GetHostByName(const char *);
extern char *func_0215FA9C(unsigned);
extern char *strcpy(char *dst, const char *src);
int GDS_SOCKET_ResolveHost(const char *s, char *out) {
 void *p;
 if (!GDS_SOCKET_IsDottedQuad(s)) {
  p=SOC_GetHostByName(s);
  if (p) {
   strcpy(out, func_0215FA9C(***(unsigned ** *)&((struct Obj23010 *)p)->fC));
  } else return 0;
 } else {
  strcpy(out,s);
 }
 return 1;
}
