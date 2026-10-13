/*
 * function: func_021C3F54
 * address:  0x021C3F54
 * packet:   pkt_ov111_021C3F54
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020221A4  0x020221A4  thumb
 *   func_021C56E8  0x021C56E8  thumb
 *   func_021C5718  0x021C5718  thumb
 *   func_021C5AEC  0x021C5AEC  thumb
 *   func_021C5F64  0x021C5F64  thumb
 *   func_021C3F18  0x021C3F18  thumb
 *   func_0204B98C  0x0204B98C  arm
 *   func_0202208C  0x0202208C  thumb
 *   func_021C4B9C  0x021C4B9C  thumb
 *   func_021C4E0C  0x021C4E0C  thumb
 *   func_0204A600  0x0204A600  arm
 *   PMS_DRAW_Main  0x0202DBC4  thumb
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_020310C4  0x020310C4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[4];
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 f4_3 : 1;
    u8 f4_4 : 1;
    u8 f4_5 : 1;
    u8 f4_6 : 1;
} Cfg;

typedef struct {
    Cfg *cfg;
    void *f4;
    u8 pad8[4];
    u32 fC;
    u32 f10;
} Args;

typedef struct {
    u8 x;
    u8 y;
    u8 size;
    u8 active;
} TouchPos;

typedef struct {
    u16 heap;
    u8 pad2[0x24 - 2];
    Args *args;
    void *info;
    u8 pix[0x305C - 0x2C];
    u16 f305C;
    u16 f305E;
    u8 pad3060[0x3108 - 0x3060];
    void *f3108;
    void *f310C;
    void *f3110;
    u8 pad3114[0x31F8 - 0x3114];
    void *f31F8;
    u8 pad31FC[0x32B0 - 0x31FC];
    void *f32B0;
    u8 pad32B4[0x32CC - 0x32B4];
    void *f32CC;
    u8 pad32D0[0x32D6 - 0x32D0];
    u8 b32D6;
    u8 pad32D7[0x32EE - 0x32D7];
    TouchPos cur;
    TouchPos prev;
} Work;

struct Actor;
struct PrintSys;
struct Tcbl;
extern u32 func_020221A4(void);
extern int func_021C56E8(Work *p);
extern void func_021C5718(Work *p, int sel, int *seq);
extern void func_021C5AEC(Work *p);
extern int func_021C5F64(u8 *pix, TouchPos *cur, TouchPos *prev, int flush, const void *src, u8 clip, u8 side);
extern void func_021C3F18(Work *p, int speed);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern int func_021C4B9C(Work *p);
extern int func_021C4E0C(char *p);
extern void func_0204A600(void);
extern void PMS_DRAW_Main(u8 *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_020310C4(struct Tcbl *p);

int func_021C3F54(void *proc, int *seq, int c, Work *p)
{
    switch (*seq) {
    case 0:
        if (func_020221A4()) {
            *seq = 1;
        }
        break;
    case 1:
        func_021C5718(p, func_021C56E8(p), seq);
        func_021C5AEC(p);
        if (p->args->cfg->f4_6) {
            func_021C3F18(p, func_021C5F64(p->pix, &p->cur, &p->prev, 1, p->pix, p->f305E, p->f305C));
        }
        break;
    case 2:
        if (func_0204B98C(p->f3108) == 0) {
            func_0202208C((void *)2, 4, 4, 0, 6, 1, p->heap);
            *seq = 4;
        }
        break;
    case 3:
        if (func_0204B98C(p->f310C) == 0) {
            func_0202208C((void *)2, 4, 4, 0, 6, 1, p->heap);
            *seq = 4;
        }
        break;
    case 4:
        if (func_020221A4()) {
            return 1;
        }
        break;
    case 5:
        if (func_021C4B9C(p)) {
            *seq = 1;
        }
        break;
    case 9:
        if (func_021C4E0C((char *)p)) {
            *seq = 1;
        }
        break;
    case 6:
        func_0202208C((void *)2, 4, 4, 0, 6, 1, p->heap);
        p->args->fC = 1;
        *seq = 4;
        break;
    case 7:
        if (func_0204B98C(p->f3110) == 0) {
            func_0202208C((void *)2, 4, 4, 0, 6, 1, p->heap);
            p->args->fC = 2;
            *seq = 4;
        }
        break;
    case 8:
        break;
    }
    p->b32D6++;
    if (p->b32D6 >= 0x100) {
        p->b32D6 = 0;
    }
    func_0204A600();
    PMS_DRAW_Main(p->f32B0);
    func_0201C4E4(p->f32CC);
    if (p->f31F8) {
        func_020310C4(p->f31F8);
    }
    return 0;
}
