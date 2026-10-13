/*
 * function: KEY_MainSys
 * address:  0x02035F38
 * packet:   pkt_02035F38
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203521C  0x0203521C  arm
 *   KEY_ApplyControlMode  0x020360B8  arm
 *
 * key.c.  The per-frame pad update: with the lid closed (PAD_DetectFold) the
 * six edge words are cleared; otherwise the pad is read (PAD_Read, the SDK
 * inline: KEYINPUT | the ARM7 XY buffer, ^ and & 0x2FFF, so the 0x2FFF mask
 * is the 0x02FFFFA8 pool word shifted right by 12, not a pool word of its
 * own), UP cancels DOWN and LEFT cancels RIGHT, trigger and repeat are
 * derived from the previous hold word at +0x0C, the repeat counter at +0x3C
 * reloads from +0x40 (speed) or +0x44 (delay), and KEY_ApplyControlMode then remaps
 * the three published words before they are accumulated into +0x30..+0x38
 * and latched into +0x24..+0x2C on every other frame (ctx->f3e, a SIGNED
 * modulo-2 test on a u8 byte).  Both hardware addresses are cast constants, not
 * relocations.  Written from the SDK inline shapes (NitroSDK pad.h, library
 * function shapes only); EXACT on the first transcription.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
typedef volatile u16   vu16;

#define HW_BUTTON_XY_BUF    0x02FFFFA8
#define REG_KEYINPUT        0x04000130
#define PAD_ALL_MASK        0x2FFF

struct Key {
    u8  pad00[0x0c];
    u32 cont;           /* 0x0c */
    u32 trg;            /* 0x10 */
    u32 rpt;            /* 0x14 */
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
    u32 f38;
    s32 wait;           /* 0x3c */
    s32 speed;          /* 0x40 */
    s32 delay;          /* 0x44 */
};

struct Ctx {
    u8 pad00[0x3e];
    u8 f3e;
};

extern u32 func_0203521C(u32 *p);
struct Obj;
extern void KEY_ApplyControlMode(struct Obj *o);

static inline s32 PAD_DetectFold(void)
{
    return (s32)((*(vu16 *)HW_BUTTON_XY_BUF & 0x8000) >> 15);
}

static inline u16 PAD_Read(void)
{
    return (u16)(((*(vu16 *)REG_KEYINPUT | *(vu16 *)HW_BUTTON_XY_BUF) ^ PAD_ALL_MASK) & PAD_ALL_MASK);
}

void KEY_MainSys(struct Ctx *ctx)
{
    struct Key *k = (struct Key *)func_0203521C((u32 *)ctx);
    u16 key;

    if (PAD_DetectFold()) {
        k->f1c = 0;
        k->f18 = 0;
        k->f20 = 0;
        k->f28 = 0;
        k->f24 = 0;
        k->f2c = 0;
        return;
    }

    key = PAD_Read();
    key = key & ~((key & 0x40) << 1) & ~((key & 0x20) >> 1);

    k->trg = key & (key ^ k->cont);
    k->rpt = key & (key ^ k->cont);
    if (key != 0 && k->cont == key) {
        if (--k->wait == 0) {
            k->rpt = key;
            k->wait = k->speed;
        }
    } else {
        k->wait = k->delay;
    }
    k->cont = key;
    k->f1c = k->trg;
    k->f18 = key;
    k->f20 = k->rpt;
    KEY_ApplyControlMode((struct Obj *)k);
    k->f34 |= k->f1c;
    k->f30 |= k->f18;
    k->f38 |= k->f20;
    if (ctx->f3e % 2 != 0) {
        return;
    }
    k->f28 = k->f34;
    k->f24 = k->f30;
    k->f2c = k->f38;
    k->f34 = 0;
    k->f30 = 0;
    k->f38 = 0;
}
