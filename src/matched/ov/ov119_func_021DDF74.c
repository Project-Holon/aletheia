/*
 * function: func_021DDF74
 * address:  0x021DDF74
 * packet:   pkt_ov119_021DDF74
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   func_021E12AC  0x021E12AC  thumb  ov119
 *   func_021DD140  0x021DD140  thumb  ov119
 *   func_021D8A24  0x021D8A24  thumb  ov119
 *   func_02039CB4  0x02039CB4  arm
 *   func_02039C68  0x02039C68  arm
 *   func_021DD24C  0x021DD24C  thumb  ov119
 *   func_021DD294  0x021DD294  thumb  ov119
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_021D8FA4  0x021D8FA4  thumb  ov119
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_021E1024  0x021E1024  thumb  ov119
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021D89CC  0x021D89CC  thumb  ov119
 *   func_021D9434  0x021D9434  thumb  ov119
 *   func_021DDF28  0x021DDF28  thumb  ov119
 *   func_021DE8C0  0x021DE8C0  thumb  ov119
 */
#include "../include/Obj01251.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
struct MsgBank;
struct WordSet;
extern int func_021E12AC(char *p);
extern int func_021DD140(char *p);
extern int func_021D8A24(void *p);
struct Link;
extern u32 func_02039CB4(struct Link *h, u32 a, u32 b);
extern void func_02039C68(struct Link *h, u32 a, u32 b);
extern int func_021DD24C(char *p);
extern void func_021DD294(char *p, int a, int b);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void *func_021D8FA4(void *p, int idx);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021E1024(void *p);
extern void func_021D8E84(void *p, int next);
extern void func_021D89CC(char *p);
extern void func_021D9434(void *p);
extern void func_021DDF28(char *p);
extern void func_021DE8C0(char *p);

void func_021DDF74(char *p)
{
    int a, b, c, i, m;
    a = GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle()));
    b = 1 - a;
    if (func_021E12AC(p) == 0) return;
    if (func_021DD140(p) == 0) return;
    if (func_021D8A24(p) != 0 && func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1C, 8) == 0) {
        func_021DD24C(p);
        return;
    }
    i = 0;
    func_021DD294(p, 0, 0);
    c = (unsigned char)(p + a)[0x11E0];
    if (c == 11 && (unsigned char)(p + b)[0x11E0] == 11) {
        MSGDATA_ReadString(((struct Obj01251 *)p)->f720, 0x92, ((struct Obj01251 *)p)->f73C);
        do {
            func_0201EEF4(((struct Obj01251 *)p)->f724, i, func_021D8FA4(p, i));
            i++;
        } while (i < 2);
        func_0201F250(((struct Obj01251 *)p)->f724, ((struct Obj01251 *)p)->f738, ((struct Obj01251 *)p)->f73C);
        func_021E1024(p);
        func_021D8E84(p, (int)func_021DDF28);
        return;
    }
    if ((unsigned char)(p + b)[0x11E0] == 12) {
        (p + 0x11E0)[0x11] = 0x78;
        m = 0x93;
        if (((struct Obj01251 *)p)->f118C == 3 && (u8)p[0x11FA] >= 3) {
            func_021D89CC(p);
            func_021D8E84(p, (int)func_021D9434);
            return;
        }
    } else if (c == 12) {
        (p + 0x11E0)[0x11] = 0x78;
        m = 0x95;
        if (((struct Obj01251 *)p)->f118C == 3 && (u8)p[0x11FA] >= 3) {
            func_021D89CC(p);
            func_021D8E84(p, (int)func_021D9434);
            return;
        }
    }
    MSGDATA_ReadString(((struct Obj01251 *)p)->f720, m, ((struct Obj01251 *)p)->f738);
    func_021E1024(p);
    p[0x11E0] = 0;
    p[0x11E1] = 0;
    if (func_021D8A24(p) != 0) {
        func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x19, 8);
    }
    ((struct Obj01251 *)p)->fF2C = 0;
    func_021D8E84(p, (int)func_021DE8C0);
}
