/*
 * file:     worldtrade_adapter_p24.c
 * unit:     yes
 * function: func_021FF2D0, func_021FF318, func_021FF384
 * address:  0x021FF2D0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B98C 0x0204B98C arm
 *   func_021FE9B0 0x021FE9B0 thumb ov135
 *   func_0204B878 0x0204B878 arm
 *   func_020355C4 0x020355C4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   d_02203D4A 0x02203D4A data a2
 *   func_02202858  0x02202858  thumb  ov135
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_021F91A0  0x021F91A0  thumb
 *   func_021F91DC  0x021F91DC  thumb
 */
#include "../../matched/include/Obj00018.h"

struct Actor;
struct Obj;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef signed char s8;

typedef signed short s16;

extern u32 func_0204B98C(struct Actor *a);
extern int func_021FE9B0(u8 *);
extern void func_0204B878(struct Obj *p, u16 value);
extern u8 func_020355C4(void);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern u32 func_02202858(void *p, u8 b, void *s, u32 x, u32 y, void *out);
extern void func_02045334(struct Descriptor *v);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 v);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *p);
extern void func_021F91A0(void *p, void *b, u32 c, u32 d, u32 e, u16 f, void *g);
extern void func_021F91DC(void *p, void *b, u32 c, u32 d, u32 e, u16 f, void *g);
int func_021FF2D0(u8 *p);
void func_021FF318(u8 *p, u32 k, int b, int c, int d);
void func_021FF384(void **win, void **win2, void *bank, void *g);
extern const u16 d_02203D4A[][4];

int func_021FF2D0(u8 *p)
{
    if (func_0204B98C((struct Actor *)(((struct Obj00018 *)p)->fBF4)) == 0) {
        func_0204B878((struct Obj *)(((struct Obj00018 *)p)->fBF4), d_02203D4A[func_021FE9B0(p)][0]);
        if (func_020355C4() == 1) {
            func_0204B3DC((struct Obj *)((struct Obj00018 *)p)->fBF4, 0);
        } else {
            func_0204B3DC((struct Obj *)((struct Obj00018 *)p)->fBF4, 1);
        }
        ((struct Obj00018 *)p)->f28 = 1;
    }
    return 2;
}


/*
 * Tear the object down: unhook the two sub-objects, release the +0xd40 resource, wire the 0/1/e quad, then drain the four engine hooks.
 */
void func_021FF318(u8 *p, u32 k, int b, int c, int d)
{
    u32 v;

    func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00018 *)p)->fB6C), k, (void *)(*(u32 *)(p + 0xb6c + 0x1c)));
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj00018 *)p)->fD40)), 0xf);
    func_0201F73C((void *)(((struct Obj00018 *)p)->fD40), 0, 1, 0xe);
    func_02202858((void *)(((struct Obj00018 *)p)->fD40), 0, (void *)(*(u32 *)(p + 0xb6c + 0x1c)), 0, 0, p + 0xfa0);
    v = ((struct Obj00018 *)p)->fD40;
    func_02045334((struct Descriptor *)v);
    func_02045374((struct Cfg *)v);
    func_020409B4(func_02045730((struct Descriptor *)v));
}


/*
 * note: pass 2 2026-10-06 P2L19: closed from 8 B off (238 B). The print callees func_021F91A0 and
 *   func_021F91DC are declared void here. Their bodies end in a call and never set r0 themselves, so the
 *   image does not decide between int and void, and no caller reads the result. With int, the six stack
 *   zeros and the six 0x440 stores tie and the zero takes r7; with void the colour 0x440 takes r7 and
 *   the zero is rematerialised per call, as in the image. Plain literals, no pragma.
 */
void func_021FF384(void **win, void **win2, void *bank, void *g)
{
    void *s1, *s2, *s3, *s4, *s5, *s6;

    s1 = func_02045EC0(bank, 0x43);
    func_021F91A0(win[0], s1, 0, 0, 0, 0x440, g);
    func_02045808(s1);

    s2 = func_02045EC0(bank, 0x45);
    func_021F91A0(win[2], s2, 0, 0, 0, 0x440, g);
    func_02045808(s2);

    s3 = func_02045EC0(bank, 0x47);
    func_021F91A0(win[4], s3, 0, 0, 0, 0x440, g);
    func_02045808(s3);

    s4 = func_02045EC0(bank, 0xB9);
    func_021F91A0(win2[0], s4, 0, 0, 0, 0x440, g);
    func_02045808(s4);

    s5 = func_02045EC0(bank, 0x49);
    func_021F91DC(win[6], s5, 0, 0, 0, 0x440, g);
    func_02045808(s5);

    s6 = func_02045EC0(bank, 0xFC);
    func_021F91DC(win[7], s6, 0, 0, 0, 0x440, g);
    func_02045808(s6);
}
