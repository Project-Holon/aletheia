/*
 * function: func_021DF708
 * address:  0x021DF708
 * packet:   pkt_021D8B54
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D8A24  0x021D8A24  thumb  ov119
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021DD34C  0x021DD34C  thumb  ov119
 *   func_021DD4F4  0x021DD4F4  thumb  ov119
 *   func_021E62D4  0x021E62D4  thumb  ov119
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 */
#include "../include/Obj00001.h"

typedef unsigned short u16;

extern int func_021D8A24(void *p);
extern void func_021D8E84(void *p, int v);
struct Entry;
struct S119DD4F4;
extern int func_021DD34C(char *p, int a, int b);
extern void func_021DD4F4(struct S119DD4F4 *p, int i, int j);
extern void func_021E62D4(void *p, int a, int b);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);

void func_021DF708(void *p)
{
    int v = func_021DD34C(p, ((struct Obj00001 *)p)->fF98,
                          ((struct Obj00001 *)p)->fF94);

    if (func_021D8A24(p) == 0 ||
        GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xc0b, 4, (u32)(&v)) != 0) {
        ((struct Obj00001 *)p)->fF84 = -1;
        ((struct Obj00001 *)p)->fF88 = -1;
        ((struct Obj00001 *)p)->fF7C = -1;
        ((struct Obj00001 *)p)->fF80 = -1;
        ((struct Obj00001 *)p)->fF94 = -1;
        ((struct Obj00001 *)p)->fF98 = -1;
        if (v != -1) {
            func_021DD4F4(p, 0, v);
            func_021E62D4(p, 0, v);
        }
        func_021D8E84(p, 0x021DF6ED);
    }
}
