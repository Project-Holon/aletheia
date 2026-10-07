/*
 * file:     worldtrade_adapter_p13.c
 * unit:     yes
 * function: func_021FD85C, func_021FD8BC
 * address:  0x021FD85C
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
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_021F91A0  0x021F91A0  thumb
 *   func_02040618  0x02040618  arm
 */
struct CharBuf;
struct Descriptor;
typedef signed char s8;

typedef signed short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    void *win0;
    void *win1;
} Pane2;

typedef struct {
    u8 pad0[0xD3C];
    int scroll;
} Work;

extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern int func_021F91A0(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);
extern void func_02040618(u32 layer, u32 a, u32 b);
void func_021FD85C(Pane2 *pane, void *s1, void *s2, void *g);
void func_021FD8BC(Work *p);


void func_021FD85C(Pane2 *pane, void *s1, void *s2, void *g)
{
    func_02043B5C(func_02045770(pane->win0), 0);
    func_02043B5C(func_02045770(pane->win1), 0);
    if (s1 != 0) {
        func_021F91A0(pane->win0, (u32)s1, 0, 0, 0, 0x440, (u32)g);
    }
    if (s2 != 0) {
        func_021F91A0(pane->win1, (u32)s2, 0, 0, 0, 0x440, (u32)g);
    }
}


void func_021FD8BC(Work *p)
{
    func_02040618(0, 3, p->scroll);
    func_02040618(1, 3, p->scroll);
    func_02040618(2, 3, p->scroll);
    func_02040618(3, 3, p->scroll);
    func_02040618(4, 3, -p->scroll);
    func_02040618(5, 3, -32 - p->scroll);
    func_02040618(6, 3, -p->scroll);
    func_02040618(7, 3, -p->scroll);
}
