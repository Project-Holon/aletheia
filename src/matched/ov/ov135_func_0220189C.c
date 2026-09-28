/*
 * function: func_0220189C
 * address:  0x0220189C
 * packet:   pkt_0220189C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C866C  0x021C866C  arm  ov114
 *   func_021C86A8  0x021C86A8  arm  ov114
 *   func_022024DC  0x022024DC  thumb
 *   func_021F4FC4  0x021F4FC4  thumb
 *   func_021F90A0  0x021F90A0  thumb
 *   func_021F4E98  0x021F4E98  thumb
 *   func_0200AD8C  0x0200AD8C  thumb
 *   func_02202608  0x02202608  thumb
 *   func_0200AD9C  0x0200AD9C  thumb
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0200ADE0  0x0200ADE0  thumb
 *   func_022022B8  0x022022B8  thumb
 *   func_0200AD94  0x0200AD94  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02201B18  0x02201B18  thumb
 *   func_0200FBB0  0x0200FBB0  thumb
 *   func_0203CA04  0x0203CA04  arm
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_0203C968  0x0203C968  arm
 *   func_021F513C  0x021F513C  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *sys;
} Ctx;

typedef struct {
    Ctx *ctx;
    u8 pad4[0x24 - 4];
    int mode;
    int state;
    u8 pad2C[0x32 - 0x2C];
    u16 busy;
    u8 pad34[0x38 - 0x34];
    int err;
    u8 pad3C[0xE4 - 0x3C];
    u8 mon[0xB68 - 0xE4];
    void *words;
    void *bank;
    u8 padB70[0xEB4 - 0xB70];
    u32 fEB4;
    u8 padEB8[0xF8C - 0xEB8];
    u32 timer;
    u8 padF90[0x12F8 - 0xF90];
    u32 f12F8;
} Work;

extern int func_021C866C(void);
extern int func_021C86A8(void);
extern int func_022024DC(Work *p, void *mon);
extern void func_021F4FC4(Work *p);
extern void func_021F90A0(Work *p, void *bank, u32 id, u32 d, u16 e);
extern void func_021F4E98(Work *p, u32 a, u32 b);
extern u32 func_0200AD8C(void *sys);
extern void *func_02202608(u32 heap);
extern void func_0200AD9C(void *sys, void *mon);
extern void func_0201EEF4(void *words, u32 i, void *mon);
extern u32 func_0200ADE0(void *sys);
extern void func_022022B8(Work *p, void *mon, u32 box, int hatch);
extern void func_0200AD94(void *sys, u16 v);
extern void func_020307B0(void *p);
extern void func_02201B18(Work *p);
extern void func_0200FBB0(void);
extern void func_0203CA04(void);
extern void func_0200FBA0(void);
extern void func_0203C968(void);
extern void func_021F513C(Work *p);

int func_0220189C(Work *p)
{
    int r;
    void *mon;

    if (func_021C866C() != 0) {
        r = func_021C86A8();
        p->timer = 0;
        switch (r) {
        case 0:
            p->state = 0x1E;
            break;
        case 1:
            p->busy = 1;
            switch (func_022024DC(p, p->mon)) {
            case 1:
                func_021F4FC4(p);
                func_021F90A0(p, p->bank, 0x23, 1, 0xF0F);
                func_021F4E98(p, 0x2A, 0x20);
                break;
            case 2:
                func_021F4FC4(p);
                func_021F90A0(p, p->bank, 0x29, 1, 0xF0F);
                func_021F4E98(p, 0x2A, 0x20);
                break;
            case 0:
                p->state = 0x16;
                p->fEB4 = 1;
                p->f12F8 = 1;
                break;
            }
            break;
        case -3:
            p->busy = 0;
            if (func_0200AD8C(p->ctx->sys) != 0) {
                mon = func_02202608(0x48);
                func_0200AD9C(p->ctx->sys, mon);
                func_0201EEF4(p->words, 0, mon);
                p->mode = 2;
                p->state = 0x26;
                func_022022B8(p, mon, func_0200ADE0(p->ctx->sys), 0);
                func_0200AD94(p->ctx->sys, 0);
                func_020307B0(mon);
            } else {
                func_02201B18(p);
            }
            break;
        case -4:
            p->busy = 0;
            if (func_0200AD8C(p->ctx->sys) != 0) {
                mon = func_02202608(0x48);
                func_0200AD9C(p->ctx->sys, mon);
                func_0201EEF4(p->words, 0, mon);
                p->mode = 3;
                p->state = 0x26;
                func_0200AD94(p->ctx->sys, 0);
                func_020307B0(mon);
            }
            break;
        case -15:
        case -14:
        case -12:
        case -2:
            p->err = r;
            p->state = 0x2B;
            func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            break;
        case -13:
            func_021F513C(p);
            break;
        }
    } else {
        if (++p->timer == 0xE10) {
            func_021F513C(p);
        }
    }
    return 2;
}
