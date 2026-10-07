/*
 * file:     townmap_p14.c
 * unit:     yes
 * function: func_021BB220, func_021BB3D0, func_021BB3E8, func_021BB42C, func_021BB448, func_021BB49C
 * address:  0x021BB220
 * region:   ov072
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
 *   func_020456F8 0x020456F8 arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_020450F0  0x020450F0  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 */
struct Descriptor;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct StrObj;
struct U16Vec;
typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef struct W_021BB220 W_021BB220;

typedef unsigned char  u8;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
} W_021BB3E8;

extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern int func_021BA774(char *p, int i);
extern u32 func_02013E4C(u32 id);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u8 func_02045738(struct Descriptor *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern int func_021BA834(char *p);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern void func_020456F8(struct Descriptor *d);
extern void func_02082BCC(void *p, int v, int n);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020452E8(struct Descriptor *d);
void func_021BB220(u32 *p, W_021BB220 *w);
void func_021BB3D0(void **p);
void func_021BB3E8(W_021BB3E8 *p, int a, int b, int c, u8 s0, u8 s1, u8 s2, u8 s3, u16 s4);
void func_021BB42C(void **p);
void func_021BB448(u32 *p, u32 a, int x, int y);
void func_021BB49C(void **p);


void func_021BB220(u32 *p, W_021BB220 *w)
{
    u32 win;
    s16 cx;
    s16 hw;
    u16 id;
    u32 h;

    win = (u32)func_02045770((struct Descriptor *)p[0]);
    func_02043B5C((struct CharBuf *)win, 0);
    if (w != 0) {
        func_02045CAC((struct MsgBank *)p[3], func_02013E4C((u16)func_021BA774((char *)w, 0)), (void *)p[1]);
        cx = ((u32)func_02045738((struct Descriptor *)p[0]) << 3) / 2;
        hw = func_0201D304((struct StrObj *)p[1], p[2], 0) >> 1;
        cx = cx - hw;
        func_0201C7A4((void *)win, cx, 0x30, (void *)p[1], (void *)p[2]);
        id = func_021BA774((char *)w, 0x11);
        if (id != 0xFFFF) {
            func_02045CAC((struct MsgBank *)p[4], id, (void *)p[1]);
            func_0201C7A4((void *)win, 0x1c, 0x50, (void *)p[1], (void *)p[2]);
        }
        if (func_021BA834((char *)w)) {
            id = func_021BA774((char *)w, 0x12);
            if (id != 0xFFFF) {
                func_02045CAC((struct MsgBank *)p[4], id, (void *)p[1]);
                func_0201C7A4((void *)win, 0x10, 0x80, (void *)p[1], (void *)p[2]);
            }
            id = func_021BA774((char *)w, 0x13);
            if (id != 0xFFFF) {
                func_02045CAC((struct MsgBank *)p[4], id, (void *)p[1]);
                func_0201C7A4((void *)win, 0x10, 0x90, (void *)p[1], (void *)p[2]);
            }
            id = func_021BA774((char *)w, 0x14);
            if (id != 0xFFFF) {
                func_02045CAC((struct MsgBank *)p[4], id, (void *)p[1]);
                func_0201C7A4((void *)win, 0x10, 0xa0, (void *)p[1], (void *)p[2]);
            }
            id = func_021BA774((char *)w, 0x15);
            if (id != 0xFFFF) {
                func_02045CAC((struct MsgBank *)p[4], id, (void *)p[1]);
                func_0201C7A4((void *)win, 0x88, 0x80, (void *)p[1], (void *)p[2]);
            }
            id = func_021BA774((char *)w, 0x16);
            if (id != 0xFFFF) {
                func_02045CAC((struct MsgBank *)p[4], id, (void *)p[1]);
                func_0201C7A4((void *)win, 0x88, 0x90, (void *)p[1], (void *)p[2]);
            }
            id = func_021BA774((char *)w, 0x17);
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

void func_021BB3D0(void **p) { void *q = *p; func_020456F8(q); func_02041B6C(func_02045730(q)); }


void func_021BB3E8(W_021BB3E8 *p, int a, int b, int c, u8 s0, u8 s1, u8 s2, u8 s3, u16 s4)
{
    func_02082BCC(p, 0, 0x10);
    p->f8 = b;
    p->fc = c;
    p->f0 = func_020450F0(a, s0, s1, s2, s3, 0xe, 0);
    p->f4 = (int)func_020457B0(0xff, s4);
}

void func_021BB42C(void **p) { func_02045808(p[1]); func_020452E8(p[0]); func_02082BCC(p,0,0x10); }


void func_021BB448(u32 *p, u32 a, int x, int y)
{
    u32 w;

    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p[0])), 0);
    func_02045CAC((struct MsgBank *)p[3], a, (void *)p[1]);
    func_0201C7A4((void *)((u32)func_02045770((struct Descriptor *)p[0])), x, y, (void *)p[1], (void *)p[2]);
    w = p[0];
    func_02045334((struct Descriptor *)w);
    func_02045374((struct Cfg *)w);
    func_02041B6C(func_02045730((struct Descriptor *)w));
}

void func_021BB49C(void **p) { void *q = *p; func_020456F8(q); func_02041B6C(func_02045730(q)); }
