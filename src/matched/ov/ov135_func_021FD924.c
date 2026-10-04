/*
 * function: func_021FD924
 * address:  0x021FD924
 * packet:   pkt_021FD924
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FE118  0x021FE118  thumb
 *   func_021FDBCC  0x021FDBCC  thumb
 *   func_021FDD00  0x021FDD00  thumb
 *   func_021FDF2C  0x021FDF2C  thumb
 *   func_021FDDA8  0x021FDDA8  thumb
 *   func_021FFFE8  0x021FFFE8  thumb
 *   func_02200B34  0x02200B34  thumb
 *   func_02200BAC  0x02200BAC  thumb
 *   func_021F9890  0x021F9890  thumb
 *   func_021FF384  0x021FF384  thumb
 *   func_021FF474  0x021FF474  thumb
 *   func_021F7F9C  0x021F7F9C  thumb
 *   func_021F8098  0x021F8098  thumb
 *   func_021F886C  0x021F886C  thumb
 *   func_021F8154  0x021F8154  thumb
 *   func_021F8010  0x021F8010  thumb
 *   func_021FF50C  0x021FF50C  thumb
 *   func_0202208C  0x0202208C  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    s16 name;
    s8 mode;
    s8 key;
    s8 val;
} Rec;

typedef struct {
    void *w00;
    void *w04;
    void *obj;
    void *w0c;
    void *w10;
    void *w14;
    void *bank;
    void *names;
    void *w20;
    u32 w24;
    u32 w28;
    u32 arg;
} Init;

typedef struct {
    u8 pad0[0x10];
    u32 f10;
} Ctx;

typedef struct {
    u8 pad0[0x14];
    u32 f14;
} Aux;

typedef struct {
    Ctx *ctx;
    u8 pad4[0x20 - 4];
    int kind;
    u8 pad24[4];
    u32 f28;
    u8 pad2C[0xB56 - 0x2C];
    Rec rec;
    u8 padB5C[0xB6C - 0xB5C];
    void *bank;
    void *names;
    u8 padB74[0xB7C - 0xB74];
    void *msg;
    u8 padB80[0xBF4 - 0xB80];
    void *cursor;
    void *mark;
    u8 padBFC[0xD2C - 0xBFC];
    void *btn[2];
    u8 padD34[0xD50 - 0xD34];
    u8 fD50[0xD90 - 0xD50];
    void *win[4];
    u8 padDA0[4];
    void *wDA4;
    u8 padDA8[0xDB0 - 0xDA8];
    void *wDB0;
    u8 padDB4[0xDD4 - 0xDB4];
    u8 fDD4[4];
    void *win2[2];
    u8 padDE0[4];
    void *menu;
    u8 padDE8[0xE00 - 0xDE8];
    Aux *aux;
    u8 padE04[0xE1A - 0xE04];
    u16 fE1A;
    u8 padE1C[0xEC0 - 0xE1C];
    void (*vblank)(void *);
    u8 padEC4[0xF84 - 0xEC4];
    u32 fF84;
    u8 padF88[0xFA0 - 0xF88];
    u8 fFA0[4];
    u8 padFA4[0x12E4 - 0xFA4];
    u32 f12E4;
} Work;

extern void func_021FE118(Work *p);
extern void func_021FDBCC(void);
extern void func_021FDD00(void *p);
extern void func_021FDF2C(Work *p);
extern void func_021FDDA8(Work *p);
extern void func_021FFFE8(Work *p, u32 a, u32 b);
extern void func_02200B34(Work *p);
extern void func_02200BAC(Work *p, u32 k);
extern void *func_021F9890(Init *init, u32 a, u32 b);
extern void func_021FF384(void **win, void **win2, void *bank, void *g);
extern void func_021FF474(void *win, void *bank, int flag, void *g);
extern void func_021F7F9C(void *win, void *bank, u32 index, u32 y, u32 x, u16 color, void *g);
extern void func_021F8098(void *win, void *bank, int mode, int force, u32 x, int y, u16 color, void *g);
extern int func_021F886C(int key, int val, int which);
extern void func_021F8154(void *win, void *bank, int idx, u32 e, u32 y, u16 color, int alt, void *g);
extern void func_021F8010(void *win, void *bank, void *bank2, u32 index, u32 y, u32 x, u16 color, void *g);
extern void func_021FF50C(void *p);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);

int func_021FD924(Work *p)
{
    Init init;

    func_021FE118(p);
    func_021FDBCC();
    func_021FDD00(p);
    func_021FDF2C(p);
    func_021FDDA8(p);
    func_021FFFE8(p, 0, 0);
    func_02200B34(p);
    func_02200BAC(p, 4);
    p->f12E4 = 0;
    init.w00 = p->fD50;
    init.w04 = p->fDD4;
    init.obj = p->mark;
    init.w0c = p->btn[0];
    init.w10 = p->btn[1];
    init.w14 = p->cursor;
    init.bank = p->bank;
    init.names = p->names;
    init.w20 = p->msg;
    init.w24 = p->ctx->f10;
    init.w28 = p->aux->f14;
    p->menu = func_021F9890(&init, 2, 1);
    func_021FF384(p->win, p->win2, p->bank, p->fFA0);
    func_021FF474(p->wDB0, p->bank, p->fE1A, p->fFA0);
    func_021F7F9C(p->win[1], p->names, p->rec.name, 0, 0, 0x3C40, p->fFA0);
    func_021F8098(p->win[3], p->bank, p->rec.mode, 1, 0, 0, 0x3C40, p->fFA0);
    func_021F8154(p->wDA4, p->bank, func_021F886C(p->rec.key, p->rec.val, 1), 0, 0, 0x3C40, 1, p->fFA0);
    func_021F8010(p->win2[1], p->msg, p->bank, p->fF84, 0, 0, 0x3C40, p->fFA0);
    p->vblank = func_021FF50C;
    if (p->kind == 0xd) {
        func_0202208C((void *)3, 1, 1, 0, 6, 1, 0x48);
    }
    p->f28 = 0;
    return 1;
}
