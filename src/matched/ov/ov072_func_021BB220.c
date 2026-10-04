/*
 * function: func_021BB220
 * address:  0x021BB220
 * packet:   pkt_ov072_021BB220
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: the centred x assigned back to the s16 local before the call
 * (`cx = cx - hw;`), which truncates it ahead of the argument loads;
 * passing `cx - hw` inline schedules the p[1]/p[2] loads first.
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_021BA774  0x021BA774  thumb  ov072
 *   func_02013E4C  0x02013E4C  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045738  0x02045738  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_021BA834  0x021BA834  thumb  ov072
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

typedef struct W W;

struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct StrObj;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern int func_021BA774(W *p, int i);
extern u32 func_02013E4C(u16 a);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_02045738(u32 win);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern int func_021BA834(W *p);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);

void func_021BB220(u32 *p, W *w)
{
    u32 win;
    s16 cx;
    s16 hw;
    u16 id;
    u32 h;

    win = (u32)func_02045770((struct Descriptor *)p[0]);
    func_02043B5C((struct CharBuf *)win, 0);
    if (w != 0) {
        func_02045CAC((struct MsgBank *)p[3], func_02013E4C(func_021BA774(w, 0)), (void *)p[1]);
        cx = (func_02045738(p[0]) << 3) / 2;
        hw = func_0201D304((struct StrObj *)p[1], p[2], 0) >> 1;
        cx = cx - hw;
        func_0201C7A4((void *)win, cx, 0x30, (void *)p[1], (void *)p[2]);
        id = func_021BA774(w, 0x11);
        if (id != 0xFFFF) {
            func_02045CAC((struct MsgBank *)p[4], id, (void *)p[1]);
            func_0201C7A4((void *)win, 0x1c, 0x50, (void *)p[1], (void *)p[2]);
        }
        if (func_021BA834(w)) {
            id = func_021BA774(w, 0x12);
            if (id != 0xFFFF) {
                func_02045CAC((struct MsgBank *)p[4], id, (void *)p[1]);
                func_0201C7A4((void *)win, 0x10, 0x80, (void *)p[1], (void *)p[2]);
            }
            id = func_021BA774(w, 0x13);
            if (id != 0xFFFF) {
                func_02045CAC((struct MsgBank *)p[4], id, (void *)p[1]);
                func_0201C7A4((void *)win, 0x10, 0x90, (void *)p[1], (void *)p[2]);
            }
            id = func_021BA774(w, 0x14);
            if (id != 0xFFFF) {
                func_02045CAC((struct MsgBank *)p[4], id, (void *)p[1]);
                func_0201C7A4((void *)win, 0x10, 0xa0, (void *)p[1], (void *)p[2]);
            }
            id = func_021BA774(w, 0x15);
            if (id != 0xFFFF) {
                func_02045CAC((struct MsgBank *)p[4], id, (void *)p[1]);
                func_0201C7A4((void *)win, 0x88, 0x80, (void *)p[1], (void *)p[2]);
            }
            id = func_021BA774(w, 0x16);
            if (id != 0xFFFF) {
                func_02045CAC((struct MsgBank *)p[4], id, (void *)p[1]);
                func_0201C7A4((void *)win, 0x88, 0x90, (void *)p[1], (void *)p[2]);
            }
            id = func_021BA774(w, 0x17);
            if (id != 0xFFFF) {
                func_02045CAC((struct MsgBank *)p[4], id, (void *)p[1]);
                func_0201C7A4((void *)win, 0x88, 0xa0, (void *)p[1], (void *)p[2]);
            }
        }
    }
    h = p[0];
    func_02045334((struct Descriptor *)h);
    func_02045374((struct Cfg *)h);
    func_02041B6C(func_02045730((struct Descriptor *)h));
}
