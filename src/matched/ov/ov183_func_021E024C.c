/*
 * function: func_021E024C
 * address: 0x021E024C
 * packet: pkt_ov183_021E024C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two zero alignment bytes at 0x021E02F6
 * symbols:
 *   func_021FCD0C 0x021FCD0C thumb ov186
 *   func_021FCDA8 0x021FCDA8 thumb ov186
 *   func_02035D20 0x02035D20 arm
 *   func_021FB4B4 0x021FB4B4 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021E03B0 0x021E03B0 thumb ov183
 *   func_02012944 0x02012944 thumb
 *   func_0200856C 0x0200856C thumb
 *   func_02008570 0x02008570 thumb
 */
#include "../include/Obj00277.h"
#include "../include/Obj00351.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Sub0200852CObj;
extern void func_021FCD0C(char *p);
extern int func_021FCDA8(char *p);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern int func_021FB4B4(int obj, int x, int y);
extern void func_021FD860(int, int, int *);
extern void func_021E03B0(char *, char *, int);
extern u8 *func_02012944(void *p);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
int func_021E024C(char *p, char *q)
{
    int selected, pressed;
    unsigned int x, y;
    func_021FCD0C(((struct Obj00277 *)p)->f18);
    selected = func_021FCDA8(((struct Obj00277 *)p)->f18);
    pressed = func_02035D20(&x, &y);
    pressed &= func_021FB4B4(((struct Obj00277 *)p)->fC, x, y);
    if (selected != -1) {
        unsigned int x1, y1;
        int args[2];
        void *v;
        int a;
        func_02035D20(&x1, &y1);
        args[0] = x1;
        args[1] = y1;
        func_021FD860(((struct Obj00277 *)p)->f40, 1, args);
        v = func_02012944(((struct Obj00351 *)q)->f10);
        a = func_0200856C(v);
        ((struct Obj00351 *)q)->f17 = func_02008570(v);
        ((struct Obj00351 *)q)->f16 = a;
        func_021E03B0(p, q, 2);
        ((struct Obj00277 *)p)->f50 = 0;
        return 1;
    } else if (pressed != 0) {
        unsigned int x2, y2;
        int args[2];
        func_02035D20(&x2, &y2);
        args[0] = x2;
        args[1] = y2;
        func_021FD860(((struct Obj00277 *)p)->f40, 1, args);
        ((struct Obj00277 *)p)->f50 = 0;
        return 1;
    }
    return 0;
}
