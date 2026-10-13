/*
 * function: func_021D4820
 * address:  0x021D4820
 * packet:   pkt_ov117_021D4820
 * region:   ov117
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_021D8AA8  0x021D8AA8  thumb  ov119
 *   func_021D8FA4  0x021D8FA4  thumb  ov119
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02041300  0x02041300  arm
 *   func_021E0FF4  0x021E0FF4  thumb  ov119
 *   func_021E7208  0x021E7208  thumb  ov119
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00982.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct WordSet;
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern int func_021D8AA8(void *);
extern void *func_021D8FA4(void *, int);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02041300(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_021E0FF4(void *p, int a, int b);
extern void func_021E7208(void *p, int a);

void func_021D4820(u8 *p)
{
    GFL_NET_RestartWithDefaultTimeout(0, ((struct Obj00982 *)p)->f5F4);
    if (((struct Obj00982 *)p)->f118C == 6) {
        MSGDATA_ReadString((struct MsgBank *)(((struct Obj00982 *)p)->f720), 0x98, (void *)(((struct Obj00982 *)p)->f73C));
    } else if (((struct Obj00982 *)p)->f118C == 8) {
        MSGDATA_ReadString((struct MsgBank *)(((struct Obj00982 *)p)->f720), 0x9B, (void *)(((struct Obj00982 *)p)->f73C));
    } else if (((struct Obj00982 *)p)->f11ED != 0) {
        MSGDATA_ReadString((struct MsgBank *)(((struct Obj00982 *)p)->f720), 0x82, (void *)(((struct Obj00982 *)p)->f73C));
    } else {
        MSGDATA_ReadString((struct MsgBank *)(((struct Obj00982 *)p)->f720), 0x81, (void *)(((struct Obj00982 *)p)->f73C));
    }
    func_0201EEF4(((struct Obj00982 *)p)->f724, 0, func_021D8FA4(p, func_021D8AA8(p)));
    func_0201F02C((struct WordSet *)(*(u32 *)&((struct Obj00982 *)p)->f724), 1, (void *)(((struct Obj00982 *)p)->f834));
    func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00982 *)p)->f724), (void *)(((struct Obj00982 *)p)->f738), (void *)(((struct Obj00982 *)p)->f73C));
    func_02041300(4, 0, 0, 0, 0x20, 0x18, 0x11);
    func_021E0FF4(p, 1, 0);
    func_021E7208(p, 0x14);
    *(volatile u16 *)0x04001050 = 0;
}
