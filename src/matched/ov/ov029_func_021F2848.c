/*
 * function: func_021F2848
 * address:  0x021F2848
 * packet:   pkt_ov029_021F2848
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The listing extent (316 B) runs over an unlabelled 4-byte follower at
 * 0x021F2980 (`bx lr`); the function is 312 B.  func_021F3144's second
 * argument is this function's r1, forwarded untouched.
 *
 * symbols:
 *   func_021F3144  0x021F3144  thumb  ov029
 *   func_021F2DA8  0x021F2DA8  thumb  ov029
 *   func_02012138  0x02012138  thumb
 *   func_02158630  0x02158630  thumb  ov010
 *   func_021F06B8  0x021F06B8  thumb  ov029
 *   func_020120F4  0x020120F4  thumb
 *   func_0201283C  0x0201283C  thumb
 *   func_0201058C  0x0201058C  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02028A64  0x02028A64  thumb
 *   func_02028A70  0x02028A70  thumb
 *   func_021F1BBC  0x021F1BBC  thumb  ov029
 *   func_021F1A64  0x021F1A64  thumb  ov029
 *   func_021F13FC  0x021F13FC  thumb  ov029
 *   func_021F0EB0  0x021F0EB0  thumb  ov029
 *   func_021F0298  0x021F0298  thumb  ov029
 *   func_021EFEF8  0x021EFEF8  thumb  ov029
 *   func_021F2370  0x021F2370  thumb  ov029
 *   func_021F2180  0x021F2180  thumb  ov029
 *   func_02030D28  0x02030D28  arm
 */
#include "../include/Obj00761.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021F3144(u8 *p, int v);
extern int func_021F2DA8(u8 *p);
struct Ctx;
extern u32 func_02012138(const struct Ctx *p);
extern int func_02158630(int a);
extern void func_021F06B8(u8 *p, int a, int b);
struct BigObj;
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201283C(const struct BigObj *p);
extern u32 func_0201058C(void *key);
struct BigObj;
extern u32 func_02012A30(const struct BigObj *p);
struct SoundSys;
extern void func_02028A64(struct SoundSys *sys);
extern void func_02028A70(struct SoundSys *sys);
extern void func_021F1BBC(char *p);
extern void func_021F1A64(char *p, int flag);
extern void func_021F13FC(void *p);
extern void func_021F0EB0(char *p, int flag);
extern void func_021F0298(u8 *p);
extern void func_021EFEF8(char *p, void (*f)(void), int line);
extern void func_021F2370(char *p);
extern void func_021F2180(char *p);
extern void func_02030D28(struct Ctx *c);

void func_021F2848(u8 *p, u8 v)
{
    int st;
    u32 keys;
    void *snd;

    if (p[0x451] == 1)
        return;

    func_021F3144(p, v);
    if (func_021F2DA8(p) == 0) {
        st = func_02158630(func_02012138((const struct Ctx *)((struct Obj00761 *)p)->f1C));
        if (st == 3) {
            if (p[0x463] == 0) {
                func_021F06B8(p, 1, 0);
                p[0x463] = 1;
            }
        } else {
            if (p[0x463] == 1) {
                func_021F06B8(p, 0, 0);
                p[0x463] = 0;
            }
        }
        if (st == 0) {
            keys = func_0201058C((void *)func_0201283C(func_020120F4((const struct Ctx *)(((struct Obj00761 *)p)->f1C))));
            snd = (void *)func_02012A30((const struct BigObj *)func_020120F4((const struct Ctx *)(((struct Obj00761 *)p)->f1C)));
            if (keys & 8) {
                if (p[0x462] == 0) {
                    p[0x462] = 1;
                    func_021F06B8(p, 1, 1);
                }
                func_02028A64(snd);
            } else if ((keys & 8) == 0 && p[0x462] != 0) {
                func_02028A70(snd);
                p[0x462] = 0;
                func_021F06B8(p, 0, 0);
            }
        }
    }

    if (p[0x451] == 2) {
        p[0x451] = 0;
        if (func_021F2DA8(p) == 0) {
            func_021EFEF8((char *)p, (void (*)(void))func_021F2370, 0x11C5);
        } else {
            func_021F1BBC((char *)p);
            func_021F1A64((char *)p, 1);
            func_021F13FC(p);
            func_021F0EB0((char *)p, func_021F2DA8(p));
            func_021F0298(p);
            func_021EFEF8((char *)p, (void (*)(void))func_021F2180, 0x11D4);
        }
    }

    if (*(void (**)(u8 *))p != 0)
        (*(void (**)(u8 *))p)(p);
    if (((struct Obj00761 *)p)->f204 != 0)
        func_02030D28((struct Ctx *)(((struct Obj00761 *)p)->f204));
}
