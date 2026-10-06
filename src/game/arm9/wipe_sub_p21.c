/*
 * file:     wipe_sub_p21.c
 * unit:     yes
 * function: func_02025154, func_020251D8, func_020251FC, func_020252A8
 * address:  0x02025154
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020410D0       0x020410D0  arm
 *   gInfoWin            0x0214693C  data
 *   func_020490F4       0x020490F4  arm
 *   func_0203FA08       0x0203FA08  arm
 *   func_02049B68       0x02049B68  arm
 *   func_02049658       0x02049658  arm
 *   ENV_SetResourceSet  0x02049238  arm
 *   func_02041300       0x02041300  arm
 *   func_020409B4       0x020409B4  arm
 *   gSysState           0x0214693C  data
 *   func_0203F4CC  0x0203F4CC  arm
 */
struct RtcTime;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct InfoWin {
    u32 f00;
    u16 f04;
    u8  f06;
    u8  f07;
};

struct Sys {
    u32 field_0;
    u16 field_4;
    u16 field_6;
    u32 field_8;
    u32 field_C;
    u32 field_10;
    u32 field_14;
    u32 field_18;
    u8  field_1C;
    u8  field_1D;
    u8  field_1E;
    u8  field_1F;
};

struct Cfg {
    u32 a;
    u32 b;
    u32 c;
};

extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32   func_0203FA08(u32 a, u32 b, u32 c);
extern void  func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void  func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void  ENV_SetResourceSet(void *a);
extern void  func_02041300(u32 a, u16 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void  func_020409B4(u32 a);
extern void func_0203F4CC(struct RtcTime *time);
void func_02025154(u32 base, u32 blk, u8 x, u8 y, u8 w, u8 h);
int func_020251D8(int a0, const void *a1, int a2);
void func_020251FC(u32 a, u32 b, u32 c);
void func_020252A8(void);
extern struct InfoWin *gInfoWin;
extern struct Sys *gSysState;


/*
 * note:     infowin tile-rect writer: fills a w*h u16 screen buffer with
 *           charbase + base + (pal << 12) + i + j*16 and hands it to
 *           func_020410D0.  x/y/w/h are u8 (the callee takes u8 w/h);
 *           `j * 16`, not `j << 4`, fixes the adds operand order.
 */
void func_02025154(u32 base, u32 blk, u8 x, u8 y, u8 w, u8 h)
{
    u16 buf[14];
    u8 i;
    u8 j;
    u32 p;
    struct InfoWin *q;

    i = 0;
    if (i < w) {
        p = base + (blk << 12);
        q = gInfoWin;
        do {
            for (j = 0; j < h; j++) {
                buf[j * w + i] = (u16)(q->f00 + (i + p + j * 16));
            }
            i++;
        } while (i < w);
    }
    func_020410D0(gInfoWin->f06, x, y, w, h, (u32)buf, 0, 0, w, h);
}


int func_020251D8(int a0, const void *a1, int a2){ int t0 = func_02040E78((int)*(unsigned char *)(((char *)(*(int *)((char *)(0x214693C))) + 6)), (int)a1, (int)((unsigned int)((a2 << 0x11)) >> 0x10), (int)((unsigned int)((((a0 + 0) + (*(unsigned char *)(((char *)(*(int *)((char *)(0x214693C))) + 7)) << 4)) << 0x11)) >> 0x10)); return t0; }



void func_020251FC(u32 a, u32 b, u32 c)
{
    void *env;
    u32 sel = 0;

    if (a > 3) {
        sel = 4;
    }

    env = func_020490F4(0x32, c);
    gSysState->field_0 = func_0203FA08(a, 1 << 12, 1);
    func_02049B68(env, 0, sel, b << 5, 0x20, c);
    func_02049658(env, 1, a, gSysState->field_0, 0, 0, c);
    ENV_SetResourceSet(env);
    func_02041300(a, (u16)(gSysState->field_0 + 0xf), 0, 0, 0x20, 1, b);
    func_02041300(a, (u16)(gSysState->field_0 + 0x1f), 0, 1, 0x20, 1, b);
    func_020409B4(a);
}



void func_020252A8(void)
{
    struct Cfg cfg;
    u32 v;

    func_0203F4CC((struct RtcTime *)(&cfg));
    v = cfg.c & 1;

    if (cfg.a != gSysState->field_1D) {
        gSysState->field_1D = cfg.a;
        if (gSysState->field_1D >= 0xc) {
            gSysState->field_18 = 1;
        } else {
            gSysState->field_18 = 0;
        }
        gSysState->field_4 |= 1;
    }

    if (cfg.b != gSysState->field_1C) {
        gSysState->field_1C = cfg.b;
        gSysState->field_4 |= 1;
    }

    if (v != gSysState->field_14) {
        gSysState->field_14 = v;
        gSysState->field_4 |= 1;
    }
}
