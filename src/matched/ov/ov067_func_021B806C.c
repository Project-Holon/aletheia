/*
 * function: FRAME_LIST_HandleInput
 * address:  0x021B806C
 * packet:   pkt_ov067_021B806C
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201C6B4  0x0201C6B4  thumb
 *   FRAME_LIST_ReadTouch  0x021B7CF8  thumb  ov067
 *   FRAME_LIST_ReadKeys  0x021B7E70  thumb  ov067
 *   func_020061E4  0x020061E4  thumb
 *   FRAME_LIST_SetCursorHighlight  0x021B92F0  thumb  ov067
 *   FRAME_LIST_StartScroll  0x021B8434  thumb  ov067
 *   FRAME_LIST_Redraw  0x021B7BE0  thumb  ov067
 *   FRAME_LIST_BeginScrollBarDrag  0x021B8990  thumb  ov067
 *   FRAME_LIST_BeginRowDrag  0x021B8C14  thumb  ov067
 *   func_020355C4  0x020355C4  arm
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

struct Ops {
    void *f0;
    void (*f4)(void *obj, int pos, int flag);
};

struct S {
    u8 _0[0xb];
    u8 fb[6];
    u8 _11[0x20 - 0x11];
    struct Ops *f20;
    void *f24;
    u8 _28[0x34 - 0x28];
    int f34;
    u8 _38[0x4e - 0x38];
    u16 f4e;
    u8 _50[0x5c - 0x50];
    s16 f5c;
    u16 f5e;
    s16 f60;
    s16 f62;
    u16 f64;
    u8 _66[0x7c - 0x66];
    u8 f7c;
    u8 _7d[0x95 - 0x7d];
    u8 f95;
};

struct PrintSys;
extern u32 func_0201C6B4(const struct PrintSys *p);
extern int FRAME_LIST_ReadTouch(struct S *s);
extern int FRAME_LIST_ReadKeys(struct S *s);
extern void func_020061E4(u32 id);
extern void FRAME_LIST_SetCursorHighlight(struct S *p, u32 a1, u32 a2);
extern void FRAME_LIST_StartScroll(u8 *p, int a, u8 b, u16 c, u32 d);
extern void FRAME_LIST_Redraw(struct S *s, int a1);
extern void FRAME_LIST_BeginScrollBarDrag(struct S *s, int idx);
extern void FRAME_LIST_BeginRowDrag(struct S *s, int a);
extern u8 func_020355C4(void);

int FRAME_LIST_HandleInput(struct S *s)
{
    int r;
    s16 v;

    if (func_0201C6B4((const struct PrintSys *)s->f34) == 0)
        return -1;
    r = FRAME_LIST_ReadTouch(s);
    if (r == 14)
        r = FRAME_LIST_ReadKeys(s);
    switch (r) {
    case 0:
        func_020061E4(0x548);
        FRAME_LIST_SetCursorHighlight(s, (u16)s->f5c, (u16)s->f60);
        s->f20->f4(s->f24, s->f5c + s->f62, 1);
        s->f4e = 4;
        return -12;
    case 1:
        func_020061E4(0x548);
        FRAME_LIST_SetCursorHighlight(s, (u16)s->f5c, (u16)s->f60);
        s->f20->f4(s->f24, s->f5c + s->f62, 1);
        s->f4e = 4;
        return -11;
    case 2:
        FRAME_LIST_StartScroll((u8 *)s, (s8)(-s->fb[s->f95]), 1, 4, 1);
        return -10;
    case 3:
        FRAME_LIST_StartScroll((u8 *)s, (s8)s->fb[s->f95], 1, 4, 1);
        return -10;
    case 4:
        v = s->f5e;
        s->f60 = s->f5c;
        if (s->f62 - v < 0) {
            s->f5c = 0;
            v = s->f62;
        }
        FRAME_LIST_SetCursorHighlight(s, (u16)0xff, (u16)s->f60);
        FRAME_LIST_StartScroll((u8 *)s, (s8)(-s->fb[0]), v, 4, 0);
        func_020061E4(0x548);
        return -7;
    case 5:
        v = s->f5e;
        s->f60 = s->f5c;
        if (s->f62 + v > s->f64) {
            s->f5c = s->f5e - 1;
            v = s->f64 - s->f62;
        }
        FRAME_LIST_SetCursorHighlight(s, (u16)0xff, (u16)s->f60);
        FRAME_LIST_StartScroll((u8 *)s, (s8)s->fb[0], v, 4, 0);
        func_020061E4(0x548);
        return -6;
    case 6:
        func_020061E4(0x548);
        FRAME_LIST_SetCursorHighlight(s, (u16)s->f5c, (u16)s->f60);
        s->f20->f4(s->f24, s->f5c + s->f62, 1);
        s->f4e = 4;
        return -5;
    case 7:
        func_020061E4(0x548);
        FRAME_LIST_SetCursorHighlight(s, (u16)s->f5c, (u16)s->f60);
        s->f20->f4(s->f24, s->f5c + s->f62, 1);
        s->f4e = 4;
        return -4;
    case 8:
        s->f5c = 0;
        s->f62 = 0;
        FRAME_LIST_Redraw(s, 1);
        func_020061E4(0x548);
        return -3;
    case 9:
        s->f5c = s->f5e - 1;
        s->f62 = s->f64;
        FRAME_LIST_Redraw(s, 1);
        func_020061E4(0x548);
        return -2;
    case 10:
        FRAME_LIST_SetCursorHighlight(s, (u16)0xff, (u16)s->f60);
        FRAME_LIST_BeginScrollBarDrag(s, s->f7c);
        func_020061E4(0x645);
        return -9;
    case 11:
        FRAME_LIST_SetCursorHighlight(s, (u16)0xff, (u16)s->f60);
        s->f20->f4(s->f24, s->f5c + s->f62, 1);
        FRAME_LIST_BeginRowDrag(s, s->f5c);
        func_020061E4(0x645);
        return -8;
    case 12:
        if (func_020355C4() == 1) {
            FRAME_LIST_SetCursorHighlight(s, (u16)s->f5c, (u16)s->f60);
            s->f20->f4(s->f24, s->f5c + s->f62, 1);
        }
        return s->f5c;
    case 13:
    case 14:
        break;
    }
    return -1;
}
