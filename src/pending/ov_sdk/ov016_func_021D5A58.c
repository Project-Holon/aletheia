typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef volatile u16 vu16;

typedef struct {
    char pad0[0x18];
    void *self;
    void *font;
    int f20;
    int f24;
    void *chr;
    void *task;
} Canvas;

typedef struct {
    char pad0[0x610];
    Canvas canvas[2];
} MemFont;

typedef struct { u16 x, y; } Coord;

extern MemFont *g_021DE680;
extern Coord g_021DAA74[2];
extern u16 g_021DAA70[2];

extern void *func_021D6414(u32 size, int alignment);
extern void func_02068FC4(Canvas *cv, void *chr, int w, int h, int fmt);
extern void *func_0207DF94(void);
extern void *func_0207DF60(void);
extern void func_02069078(void *scr, int w, int h, int a, int b, int c, int d, int e);
extern void func_021D5F14(void *canvas, int color);
extern void *func_021D7680(int kind, void (*func)(void *), void *work, u8 prio);
extern void func_021D5BC0(void *task);

void *func_021D5A58(int lcd, int font)
{
    Canvas *cv = &g_021DE680->canvas[lcd];
    u16 x = g_021DAA74[lcd].x;
    u16 y = g_021DAA74[lcd].y;

    cv->chr = func_021D6414(x * y * 32, 32);
    if (lcd == 1) {
        *(vu16 *)0x04001008 &= 0xffbf;
        *(vu16 *)0x04001008 = (*(vu16 *)0x04001008 & 0x43) | 0xc00;
    } else {
        *(vu16 *)0x04000008 &= 0xffbf;
        *(vu16 *)0x04000008 = (*(vu16 *)0x04000008 & 0x43) | 0xc00;
    }
    func_02068FC4(cv, cv->chr, x, y, 4);
    cv->self = cv;
    cv->font = (char *)g_021DE680 + font * 8;
    cv->f20 = 1;
    cv->f24 = 1;
    {
        void *scr;
        if (lcd == 1)
            scr = func_0207DF94();
        else
            scr = func_0207DF60();
        func_02069078(scr, x, y, 0, 0, 32, g_021DAA70[lcd], 15);
    }
    func_021D5F14(cv, 0);
    cv->task = func_021D7680(1, func_021D5BC0, (char *)g_021DE680 + 0x27c + 0x400 + lcd, 200);
    return cv;
}
