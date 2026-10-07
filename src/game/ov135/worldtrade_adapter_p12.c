/*
 * file:     worldtrade_adapter_p12.c
 * unit:     yes
 * function: func_021FD6F4, func_021FD760, func_021FD790, func_021FD7DC
 * address:  0x021FD6F4
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
 *   func_02202858  0x02202858  thumb  ov135
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_021F91A0  0x021F91A0  thumb
 *   func_021F91DC  0x021F91DC  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_021F7FD4  0x021F7FD4  thumb
 *   func_021F8104  0x021F8104  thumb
 *   func_021F886C  0x021F886C  thumb
 *   func_021F8178  0x021F8178  thumb
 */
#include "../../matched/include/Obj01063.h"

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

typedef struct {
    void *win;
} Pane;

typedef struct {
    s16 name;
    s8 mode;
    s8 key;
    s8 val;
} Rec;

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
extern void func_02045808(struct U16Vec *vec);
extern int func_021F91A0(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);
extern int func_021F91DC(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);
extern void func_021F7FD4(void *win, void *bank, u32 index, u32 y, u16 color, void *g);
extern void func_021F8104(void *win, void *bank, int mode, int force, u32 x, u32 y, u16 color, void *g);
extern int func_021F886C(int key, int val, int which);
extern void func_021F8178(void *win, void *bank, int idx, u32 e, u32 x, u32 y, u16 color, int alt, u32 g);
void func_021FD6F4(u8 *p, u32 k, u32 a2, u32 a3, u32 a4);
void func_021FD760(void *bank, Pane *pane, u32 index, void *g, u16 color);
void func_021FD790(void *bank, Pane *pane, u32 index, void *g);
void func_021FD7DC(Pane *pane, void *bank, void *names, Rec *rec, void *g);


/*
 * Tear the object down: unhook the two sub-objects, release the +0xd40 resource, wire the 0/1/2 quad, then drain the four engine hooks.
 */
void func_021FD6F4(u8 *p, u32 k, u32 a2, u32 a3, u32 a4)
{
    u32 v;

    func_02045CAC((struct MsgBank *)(((struct Obj01063 *)p)->fB6C), k, (void *)(*(u32 *)(p + 0xb6c + 0x1c)));
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj01063 *)p)->fD40)), 0xf);
    func_0201F73C((void *)(((struct Obj01063 *)p)->fD40), 0, 1, 0x2);
    func_02202858((void *)(((struct Obj01063 *)p)->fD40), 0, (void *)(*(u32 *)(p + 0xb6c + 0x1c)), 0, 0, p + 0xfa0);
    v = ((struct Obj01063 *)p)->fD40;
    func_02045334((struct Descriptor *)v);
    func_02045374((struct Cfg *)v);
    func_020409B4(func_02045730((struct Descriptor *)v));
}


void func_021FD760(void *bank, Pane *pane, u32 index, void *g, u16 color)
{
    void *str = func_02045EC0(bank, index);

    func_021F91A0(pane->win, (u32)str, 0, 2, 0, color, (u32)g);
    func_02045808(str);
}


void func_021FD790(void *bank, Pane *pane, u32 index, void *g)
{
    void *str = func_02045EC0(bank, index);
    void *win;

    func_021F91DC(pane->win, (u32)str, 0, 0, 1, 0x3C40, (u32)g);
    win = pane->win;
    func_02045334(win);
    func_02045374(win);
    func_020409B4(func_02045730(win));
    func_02045808(str);
}


void func_021FD7DC(Pane *pane, void *bank, void *names, Rec *rec, void *g)
{
    func_02043B5C(func_02045770(pane->win), 0);
    func_021F7FD4(pane->win, names, rec->name, 0, 0x440, g);
    func_021F8104(pane->win, bank, rec->mode, 0, 0x49, 0, 0x440, g);
    func_021F8178(pane->win, bank, func_021F886C(rec->key, rec->val, 0), 0, 0x68, 0, 0x440, 0, (u32)g);
}
