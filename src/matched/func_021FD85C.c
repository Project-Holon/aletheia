/*
 * function: func_021FD85C
 * address:  0x021FD85C
 * packet:   pkt_021FD85C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_021F91A0  0x021F91A0  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *win0;
    void *win1;
} Pane2;

extern void *func_02045770(void *win);
extern void func_02043B5C(void *bmp, u32 color);
extern int func_021F91A0(void *p, void *b, u32 c, u32 d, u32 e, u16 f, void *g);

void func_021FD85C(Pane2 *pane, void *s1, void *s2, void *g)
{
    func_02043B5C(func_02045770(pane->win0), 0);
    func_02043B5C(func_02045770(pane->win1), 0);
    if (s1 != 0) {
        func_021F91A0(pane->win0, s1, 0, 0, 0, 0x440, g);
    }
    if (s2 != 0) {
        func_021F91A0(pane->win1, s2, 0, 0, 0, 0x440, g);
    }
}
