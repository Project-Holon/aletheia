/*
 * file:     worldtrade_enter_p07.c
 * unit:     yes
 * function: func_021F91DC, func_021F9218, func_021F9254, func_021F9260, func_021F9660
 * address:  0x021F91DC
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
 *   func_021F914C  0x021F914C  thumb  ov135
 *   func_022028C8  0x022028C8  thumb  ov135
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_021F91A0  0x021F91A0  thumb
 *   tbl_022031EC   0x022031EC  data
 *   func_02040C14  0x02040C14  arm
 *   sub_020450F0   0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   sub_02043B5C   0x02043B5C  arm
 *   data_02203200  0x02203200  data
 *   data_02203206  0x02203206  data
 *   data_0220322A  0x0220322A  data
 *   data_02203242  0x02203242  data
 *   data_022032AE  0x022032AE  data
 *   func_0202CF98  0x0202CF98  thumb
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_020452E8  0x020452E8  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02040DA8  0x02040DA8  arm
 */
struct MsgBank;
struct U16Vec;
struct Descriptor;
struct CharBuf;
struct WinMgr;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

struct Ov135Menu {
    u32 *win;
    u8 pad4[0x4c];
    u32 layer;
};

typedef struct {
    void **win;
    u8 pad4[0x18 - 4];
    struct WinMgr *f18;
    u8 pad1C[0x50 - 0x1C];
    u32 f50;
} Obj;

extern int func_021F914C(void *win, void *str, int x, int align, int unused, int font, void *ctx);
extern u32 func_022028C8(u8 *p, u32 z, u32 b, u32 r, u32 d, u32 z2, u16 f, u32 g);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern int func_021F91A0(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);
extern void func_0203D34C(u32 a, u32 b);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern u32  sub_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void sub_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0202CF98(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_020409B4(u32 layer);
extern void func_02040DA8(u32, u32, u32);
int func_021F91DC(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);
void func_021F9218(void *win, void *bank, int idx, void *g);
void func_021F9254(u8 *a0);
void ov135_func_021F9260(struct Ov135Menu *p, u32 mode);
void func_021F9660(Obj *p, int mode);
extern const u32 tbl_022031EC[];
extern const u8 data_02203200[3][2];
extern const u8 data_02203206[4][2];
extern const u8 data_0220322A[4][3];
extern const u8 data_02203242[5][2];
extern const u8 data_022032AE[9][2];


/*
 * Seven-argument wrapper: forwards the object, three words, the 0 and the u16/g pair to the two helpers.
 */
int func_021F91DC(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g)
{
    u32 r = func_021F914C(p, (void *)b, c, e, f, 0, (void *)g);

    return func_022028C8(p, 0, b, r, d, 0, f, g);
}


void func_021F9218(void *win, void *bank, int idx, void *g)
{
    void *str;

    str = func_02045EC0(bank, tbl_022031EC[idx]);
    func_021F91A0(win, (u32)str, 0, 0, 0, 0x440, (u32)g);
    func_02045808(str);
}


/*
 * Tail call into func_0203D34C with the fixed 0/0x48 pair.
 */
void func_021F9254(u8 *a0)
{
    func_0203D34C(0, 0x48);
}


void ov135_func_021F9260(struct Ov135Menu *p, u32 mode)
{
    int i;

    func_02040C14(p->layer, 0, 1, 0);
    switch (mode) {
    case 4:
        p->win[14] = sub_020450F0((u8)p->layer, 9, 17, 6, 2, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[14])), 10);
        for (i = 0; i < 9; i++) {
            p->win[i] = sub_020450F0((u8)p->layer, data_022032AE[i][0], data_022032AE[i][1], 3, 2, 1, 1);
            sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[i])), 10);
        }
        break;
    case 5:
        p->win[14] = sub_020450F0((u8)p->layer, 9, 17, 6, 2, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[14])), 10);
        p->win[0] = sub_020450F0((u8)p->layer, 2, 2, 3, 2, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[0])), 7);
        for (i = 1; i < 4; i++) {
            p->win[i] = sub_020450F0((u8)p->layer, data_022032AE[i - 1][0], data_022032AE[i - 1][1], 2, 2, 1, 1);
            sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[i])), 10);
        }
        break;
    case 0:
        p->win[14] = sub_020450F0((u8)p->layer, 9, 17, 6, 2, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[14])), 10);
        for (i = 0; i < 4; i++) {
            p->win[i] = sub_020450F0((u8)p->layer, data_0220322A[i][0], data_0220322A[i][1], 8, 2, 1, 1);
            sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[i])), 10);
        }
        p->win[4] = sub_020450F0((u8)p->layer, 5, 14, 5, 1, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[4])), 8);
        break;
    case 6:
        p->win[14] = sub_020450F0((u8)p->layer, 9, 17, 6, 2, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[14])), 10);
        for (i = 0; i < 9; i++) {
            p->win[i] = sub_020450F0((u8)p->layer, data_022032AE[i][0], data_022032AE[i][1], 3, 2, 1, 1);
            sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[i])), 10);
        }
        p->win[15] = sub_020450F0((u8)p->layer, 1, 2, 9, 2, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[15])), 10);
        break;
    case 3:
        p->win[14] = sub_020450F0((u8)p->layer, 24, 17, 6, 2, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[14])), 10);
        for (i = 0; i < 5; i++) {
            p->win[i] = sub_020450F0((u8)p->layer, data_02203242[i][0], data_02203242[i][1], 23, 2, 1, 1);
            sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[i])), 10);
        }
        p->win[5] = sub_020450F0((u8)p->layer, 14, 16, 5, 1, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[5])), 10);
        break;
    case 1:
        p->win[14] = sub_020450F0((u8)p->layer, 9, 17, 6, 2, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[14])), 10);
        for (i = 0; i < 3; i++) {
            p->win[i] = sub_020450F0((u8)p->layer, data_02203200[i][0], data_02203200[i][1], 9, 2, 1, 1);
            sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[i])), 10);
        }
        break;
    case 2:
        p->win[14] = sub_020450F0((u8)p->layer, 9, 17, 6, 2, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[14])), 10);
        for (i = 0; i < 4; i++) {
            p->win[i] = sub_020450F0((u8)p->layer, data_02203206[i][0], data_02203206[i][1], 11, 2, 1, 1);
            sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[i])), 10);
        }
        p->win[4] = sub_020450F0((u8)p->layer, 5, 14, 5, 1, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[4])), 8);
        break;
    }
}


/*
 * Redraw the text windows of layout `mode` (0..6): clear and refresh the
 * first n windows of the window table, and when the second brightness
 * byte read by func_0202CF98 is 0x10 reset the two BG2 screen blocks
 * (func_02041300) and commit them; then refresh window 14 (and 15 for
 * layout 6) and schedule the +0x50 screen.
 */
void func_021F9660(Obj *p, int mode)
{
    s8 bright[2];
    int i = 0;

    func_0202CF98(p->f18, 0, &bright[1], &bright[0]);
    switch (mode) {
    case 4:
        for (i = 0; i < 9; i++) {
            func_02043B5C(func_02045770(p->win[i]), 10);
            func_02045334(p->win[i]);
            func_020452E8(p->win[i]);
        }
        if (bright[1] == 0x10) {
            func_02041300(2, 5, 0x10, 1, 1, 0xF, 0x10);
            func_02041300(2, 6, 0x11, 1, 0xF, 0xF, 0x10);
            func_020409B4(2);
        }
        func_020452E8(p->win[14]);
        break;
    case 5:
        for (i = 0; i < 4; i++) {
            func_02043B5C(func_02045770(p->win[i]), 10);
            func_02045334(p->win[i]);
            func_020452E8(p->win[i]);
        }
        if (bright[1] == 0x10) {
            func_02041300(2, 5, 0x10, 1, 1, 0xF, 0x10);
            func_02041300(2, 6, 0x11, 1, 0xF, 0xF, 0x10);
            func_020409B4(2);
        }
        func_020452E8(p->win[14]);
        break;
    case 0:
        for (i = 0; i < 5; i++) {
            func_02043B5C(func_02045770(p->win[i]), 10);
            func_02045334(p->win[i]);
            func_020452E8(p->win[i]);
        }
        if (bright[1] == 0x10) {
            func_02041300(2, 5, 0x10, 1, 1, 0xF, 0x10);
            func_02041300(2, 6, 0x11, 1, 0xF, 0xF, 0x10);
            func_020409B4(2);
        }
        func_020452E8(p->win[14]);
        break;
    case 6:
        for (i = 0; i < 9; i++) {
            func_02043B5C(func_02045770(p->win[i]), 10);
            func_02045334(p->win[i]);
            func_020452E8(p->win[i]);
        }
        if (bright[1] == 0x10) {
            func_02041300(2, 5, 0x10, 1, 1, 0xF, 0x10);
            func_02041300(2, 6, 0x11, 1, 0xF, 0xF, 0x10);
            func_020409B4(2);
        }
        func_020452E8(p->win[14]);
        func_020452E8(p->win[15]);
        break;
    case 3:
        for (i = 0; i < 6; i++) {
            func_02043B5C(func_02045770(p->win[i]), 10);
            func_02045334(p->win[i]);
            func_020452E8(p->win[i]);
        }
        func_020452E8(p->win[14]);
        break;
    case 1:
        for (i = 0; i < 3; i++) {
            func_020452E8(p->win[i]);
        }
        func_020452E8(p->win[14]);
        break;
    case 2:
        for (i = 0; i < 5; i++) {
            func_020452E8(p->win[i]);
        }
        func_020452E8(p->win[14]);
        break;
    }
    func_02040DA8(p->f50, 1, 0);
}
