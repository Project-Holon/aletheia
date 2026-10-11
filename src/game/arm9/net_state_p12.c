/*
 * function: func_0203DAC4
 * address:  0x0203DAC4
 * packet:   pkt_0203DAC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * net_irc_wireless.c.  Registers a peer MAC address: returns if it is
 * already in one of the four 8-byte slots at +0x94, otherwise copies it
 * into the first all-zero slot and records the slot index at +0x90; with
 * no free slot it reports error 1 (func_0203C938).  func_0203EFC8 is the
 * memcmp-style compare, func_02082D44 MI_CpuCopy8.
 *
 * The lever (docs/notes/pkt_0203DAC4.c.txt had 24 bytes out): the zero MAC
 * is a SIX-byte block-scope array with an initialiser, `u8 buf[6] = {0};`
 * spelled out.  The initialiser takes the array's address first (`add r8,
 * sp, #0`) and stores through it; six separate assignments to an 8-byte
 * array store off sp and sink the address.  Flat under 2000 permuter
 * compiles before the declaration change.
 * symbols:
 *   g_021469F0     0x021469F0  data
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0203C938  0x0203C938  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef unsigned short u16;

struct NetCtx;

struct Entry {
    void *obj;
    u8    pad_04[4];
    void *slot[8];
    u8    pad_28[0x16];
    u16   key3e;
    u16   key40;
    u8    pad_42[2];
    u16   key44;
    u16   key46;
    u8    pad_48;
    u8    f49;
    u8    f4a;
    u8    pad_4b[5];
};

struct NetVtbl {
    void (*f00)(u32 a, u32 b);
    void (*f04)(u16 key, struct NetCtx *ctx, u32 zero, u32 arg);
    void (*f08)(u32 a);
    int  (*f0C)(u32 a);
    u32  (*f10)(u32 a, u32 b);
    u32  (*f14)(u32 a);
    u8   pad18[0x28 - 0x18];
    u32  (*f28)(u32 a);
    void *(*f2C)(u32 a);
    u8   pad30[0x38 - 0x30];
    u32  (*f38)(u32 a);
    void (*f3C)(void *cb);
    u32  (*f40)(u32 a, u32 b);
    u32  (*f44)(u32 a, u32 b);
    u32  (*f48)(u32 a, u32 b, u32 c, u32 d, u32 e);
    u8   pad4C[4];
    u32  (*f50)(int a, u32 b, u32 c);
    u32  (*f54)(u32 a, u32 b);
    u32  (*f58)(void);
    u32  (*f5C)(u32 a);
    u32  (*f60)(u32 a);
    u32  (*f64)(u32 a, u32 b, u32 c, void *d);
    void (*f68)(void *cb);
    u32  (*f6C)(void);
    int  (*f70)(void);
    u32  (*f74)(void);
    u32  (*f78)(void);
    u32  (*f7C)(void);
    int  (*f80)(void);
    u32  (*f84)(void);
    int  (*f88)(void);
    void (*f8C)(u32 a);
    u32  (*f90)(u32 a);
    u8   pad94[0x9C - 0x94];
    void (*f9C)(void);
    u32  (*fA0)(void);
    u32  (*fA4)(void);
    u32  (*fA8)(void);
    u32  (*fAC)(void);
    int  (*fB0)(void);
    void (*fB4)(void);
    void (*fB8)(void *arg);
    int  (*fBC)(void);
    void (*fC0)(int a);
    void (*fC4)(u32 a);
    void (*fC8)(u32 a);
};

struct NetCtx {
    u8   pad00[0x08];
    void (*f08)(u32 a, u32 b);
    void (*f0C)(int a, u32 b);
    u32  (*f10)(u32 a);
    u32  (*f14)(u32 a);
    u8   pad18[0x1C - 0x18];
    void (*f1C)(void);
    u8   pad20[0x24 - 0x20];
    void (*f24)(u32 a, u32 b, u32 c);
    void (*f28)(u32 a, u32 b, u32 c);
    void (*f2C)(u32 a);
    void (*f30)(u32 a);
    u8   pad34[0x40 - 0x34];
    u32  (*f40)(u32 a);
    u32  (*f44)(u32 a);
    u8   pad48[0x56 - 0x48];
    u16  f56;
    u16  f58;
    u16  f5A;
    u16  f5C;
    u16  f5E;
    u8   f60;
    u8   f61;
    u8   pad62[2];
    u8   f64;
    u8   f65;
    u8   f66;
    u8   f67;
    u8   pad68[4];
    u16  f6C;
    u16  f6E;
    struct Entry table[9];
    struct NetVtbl *vt;
    u32  f344;
    void (*f348)(u32 a);
    u32  f34C;
    u8   pad350[2];
    u8   f352;
};

struct NetCtx;

struct NetCtx;

struct NetCtx;

struct NetCtx;

struct NetCtx;

extern u8 *g_021469F0;
typedef signed int     s32;
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void func_02082D44(const void *src, void *dst, u32 size);
extern u32 func_0203C938(u8 mode);

void func_0203DAC4(const u8 *mac)
{
    int i;

    if (g_021469F0 == 0)
        return;
    for (i = 0; i < 4; i++) {
        if (func_0203EFC8(mac, g_021469F0 + 0x94 + i * 8, 6) == 0)
            return;
    }
    {
        u8 buf[6] = {0, 0, 0, 0, 0, 0};
        for (i = 0; i < 4; i++) {
            if (func_0203EFC8(buf, g_021469F0 + 0x94 + i * 8, 6) == 0) {
                func_02082D44(mac, g_021469F0 + 0x94 + i * 8, 6);
                *(u32 *)(g_021469F0 + 0x90) = i;
                return;
            }
        }
    }
    func_0203C938(1);
}
