/*
 * function: func_021D9E0C
 * address: 0x021D9E0C
 * packet: pkt_ov119_021D9E0C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D9DC4 0x021D9DC4 thumb ov119
 */
#include "../include/Obj13890.h"

typedef unsigned short u16;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern void func_021D8E84(void *,int);
extern void func_021D9DC4(void *);
void func_021D9E0C(char *p)
{
    int v = 0;
    if (((struct Obj13890 *)p)->fF88 == ((struct Obj13890 *)p)->f630) v=1;
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xC16,1,(u32)(&v)))
        func_021D8E84(p,(int)func_021D9DC4);
}
