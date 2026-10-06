/*
 * function: func_021EF588
 * address: 0x021EF588
 * packet: pkt_ov107_021EF588
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 2026-10-05 (integrator): the fullwidth-to-ASCII constants are plain literals (0xFF29, 0xFF24, 0xFF10..0xFF19, c - 0xFEE0); mwcc derives them from one held value itself, so the earlier `u32 k = 0xFF24` local was not needed. EXACT in c99 and c.
 * symbols:
 *   func_02012944 0x02012944 thumb
 *   func_02030734 0x02030734 arm
 *   func_021F1628 0x021F1628 thumb ov107
 *   func_021F18D8 0x021F18D8 thumb ov107
 *   func_02008534 0x02008534 thumb
 *   func_021F1918 0x021F1918 thumb ov107
 *   func_021F1AFC 0x021F1AFC thumb ov107
 *   func_021F1B00 0x021F1B00 thumb ov107
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 *   func_020458F8 0x020458F8 arm
 *   func_02045A90 0x02045A90 arm
 *   func_02082A60 0x02082A60 arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_02040588 0x02040588 arm
 *   func_020774A0 0x020774A0 arm
 *   func_021F05DC 0x021F05DC thumb ov107
 *   d_021F6E0C 0x021F6E0C data a4
 *   ov014_id 0x0000000E data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Sub0200852CObj;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Work {
    u16 f0;
    u8 pad_2[6];
    u8 **f8;
    u8 pad_c[0x18];
    u8 f24;
    u8 pad_25;
    u8 f26;
    u8 pad_27;
    u8 f28;
    u8 pad_29[7];
    int f30;
    u8 pad_34[0x1c];
    u16 *f50;
    u16 *f54;
    u8 pad_58[0x10];
    u8 *f68;
};
extern const char d_021F6E0C[];
extern u8 ov014_id[];
extern u8 *func_02012944(void *p);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_021F1628(void *, int), func_021F18D8(void *);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern void func_021F1918(unsigned char *a, int b, int c, int d);
extern u32 func_021F1AFC(u8 *p);
extern u32 func_021F1B00(u8 *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
typedef signed int     s32;
extern u16 func_020458F8(struct U16Vec *vec);
extern u16 *func_02045A90(struct U16Vec *vec);
extern void func_02082A60(const void *, void *, int);
extern int func_02034AC4(s32 handle);
extern void func_02040588(u32, u32);
extern void func_020774A0(int (*callback)(void));
extern int func_021F05DC(void);

void func_021EF588(u8 *p)
{
    struct Work *w = (struct Work *)p;
    u8 *q;
    struct U16Vec *a;
    struct U16Vec *b;
    void *m;
    u16 la;
    u16 lb;
    int i;
    u16 *dst;
    u16 *src;


    q = func_02012944(w->f8[1]);
    w->f24 = 0;
    w->f26 = 0;
    w->f50 = func_02030734(w->f0, 0x60, 1, d_021F6E0C, 0x553);
    w->f54 = func_02030734(w->f0, 0xC0, 1, d_021F6E0C, 0x554);
    func_021F1628(w->f68, 1);
    func_021F18D8(w->f68);
    func_021F1918(w->f68, 0, func_02008534((const struct Sub0200852CObj *)q), 5);
    if (w->f28 == 0)
        m = func_02045EC0((struct MsgBank *)func_021F1AFC(w->f68), 0xC);
    else
        m = func_02045EC0((struct MsgBank *)func_021F1AFC(w->f68), 0xF);
    a = func_020457B0(0x100, w->f0);
    func_0201F250((struct WordSet *)func_021F1B00(w->f68), a, m);
    func_02045808((struct U16Vec *)m);
    if (w->f28 == 0)
        m = func_02045EC0((struct MsgBank *)func_021F1AFC(w->f68), 0xD);
    else
        m = func_02045EC0((struct MsgBank *)func_021F1AFC(w->f68), 0x10);
    b = (struct U16Vec *)m;
    la = (u32)func_020458F8(a);
    lb = (u32)func_020458F8(b);
    dst = w->f50;
    src = func_02045A90(a);
    func_02082A60(src, dst, la * 2);
    dst = w->f54;
    src = func_02045A90(b);
    func_02082A60(src, dst, lb * 2);
    func_02045808(a);
    func_02045808(b);
    w->f50[la] = 0;
    w->f54[lb] = 0;
    for (i = 0; i < 0x60; i++) {
        if (w->f54[i] == 0xFFFE)
            w->f54[i] = 0xA;
    }
    for (i = 0; i < 0x30; i++) {
        u16 c = w->f50[i];
        if (c == 0xFF29)
            w->f50[i] = 0x49;
        else if (c == 0xFF24)
            w->f50[i] = 0x44;
        else if (c >= 0xFF10 && c <= 0xFF19)
            w->f50[i] = c - 0xFEE0;
    }
    w->f30 = 0;
    func_02034AC4((int)ov014_id);
    if (w->f28 == 0) {
        func_02040588(2, 1);
        func_02040588(0, 1);
    } else {
        func_02040588(5, 1);
        func_02040588(4, 1);
    }
    func_020774A0(func_021F05DC);
}
