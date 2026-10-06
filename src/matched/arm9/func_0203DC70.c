/*
 * function: func_0203DC70
 * address:  0x0203DC70
 * packet:   pkt_0203DC70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * net_irc_wireless.c.  The wireless link state machine: a 19-state switch on
 * +0x109 of the context at 0x021469F0 (func_0203DC68 is the setter), run
 * once per frame.  Every concrete byte reproduces (1968/1968, 78 of 80
 * relocation sites resolved).  The only lever beyond the straight reading
 * was state 11's loop counter: `i = 0;` is assigned BEFORE the
 * func_02087C6C(mac) call (the image's `mov sb, r8` precedes the `bl`).
 *
 * blocker:  the two remaining sites, func_0203CFF0 (+0x484) and
 *           func_0203D000 (+0x4F0), are ARM tail-call wrappers (both now
 *           EXACT in pkt_0203DC70) that layout/symbols_sdk.txt/.json list as
 *           DWC_IsSendableReliable and FATFS_FormatDrive with a THUMB flag, a
 *           false libmatch signature hit.  With `arm` on those two lines
 *           match.py refuses the file (ISA conflict); with `thumb` (below)
 *           the matched class cannot attest them.  Integrator: drop the two
 *           rows, switch both symbols lines to `arm`, re-verify: EXACT.
 * symbols:
 *   g_021469F0     0x021469F0  data
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_02039338  0x02039338  arm
 *   func_020399EC  0x020399EC  arm
 *   func_02039ACC  0x02039ACC  arm
 *   func_0203CBAC  0x0203CBAC  arm
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_0203CF10  0x0203CF10  arm
 *   func_0203CF3C  0x0203CF3C  arm
 *   func_0203CFF0  0x0203CFF0  arm
 *   func_0203D000  0x0203D000  arm
 *   func_0203D010  0x0203D010  arm
 *   func_0203D01C  0x0203D01C  arm
 *   func_0203D0DC  0x0203D0DC  arm
 *   func_0203D17C  0x0203D17C  arm
 *   func_0203D210  0x0203D210  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_0203D788  0x0203D788  arm
 *   func_0203DA20  0x0203DA20  arm
 *   func_0203DC04  0x0203DC04  arm
 *   func_0203DC4C  0x0203DC4C  arm
 *   func_0203DC68  0x0203DC68  arm
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_02087C6C  0x02087C6C  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx {
    u8    pad_00[0x2C];
    void *f2c;
    u8    pad_30[0x60 - 0x30];
    u8    f60;
    u8    pad_61[3];
    u8    f64;
    u8    f65;
    u8    pad_66;
    u8    f67;
    u8    pad_68[0x6E - 0x68];
    u16   f6e;
    u32   f70;
    u32   f74;
    u8    pad_78[0x80 - 0x78];
    void *f80;
    void (*f84)(u32 arg);
    void (*f88)(u32 arg, int flag);
    void (*f8c)(u32 arg);
    u8    f90[4];
    u8    f94[0x100 - 0x94];
    u8    f100;
    u8    f101;
    u8    f102;
    u8    f103;
    u8    f104;
    u8    f105;
    u8    pad_106;
    u8    f107;
    u8    f108;
    u8    f109;
    u8    f10a;
    u8    f10b;
};

struct VTbl {
    u8    pad_00[0xC8];
    void (*fc8)(u32 arg);
};

struct Sys {
    u8           pad_00[0x340];
    struct VTbl *f340;
};

extern struct Ctx *g_021469F0;
typedef signed int     s32;
struct Entry;
struct Link;
extern struct Entry *func_020399A8(void);
extern void func_02039C68(struct Link *h, u32 a, u32 b);
extern u32 func_02039CB4(struct Link *h, u32 a, u32 b);
extern u16 func_02039338(void);
extern int  func_020399EC(void);
extern int  func_02039ACC(void);
struct Req;
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern int  func_0203CD98(void);
extern int func_0203CEAC(int a0);
extern u32 func_0203CF10(u32 a);
extern void *func_0203CF3C(u32 a);
extern void func_0203CFF0(void *p);
extern void func_0203D000(void *p);
extern void func_0203D010(void);
extern void func_0203D01C(void);
extern int func_0203D0DC(int a0);
extern void func_0203D17C(u32 a);
extern u32 func_0203D210(void);
extern int func_0203D3A8(struct Entry *a, u16 b, u16 c, u32 d);
extern struct Sys *func_0203D788(void);
extern void func_0203DA20(void);
extern void func_0203DC04(void);
extern void func_0203DC4C(void);
extern void func_0203DC68(struct Ctx *p, int state);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void func_02087C6C(u8 *mac);

void func_0203DC70(void)
{
    struct Ctx *p = g_021469F0;

    if (p == 0)
        return;

    switch (p->f109) {
    case 0:
        if (p->f102 != 1)
            return;
        p->f101 = 1;
        func_02039C68((struct Link *)func_020399A8(), 3, 0);
        func_0203DC68(p, 1);
        break;
    case 1:
        if (func_02039CB4((struct Link *)func_020399A8(), 3, 0) == 0)
            return;
        func_0203DC68(p, 2);
        break;
    case 2:
        if (func_02039338() == 0) {
            if (func_0203D3A8(func_020399A8(), 1, 0, 0) == 0)
                return;
            func_0203DC68(p, 3);
            p->f100 = 0xC8;
        } else {
            if (func_0203D3A8(func_020399A8(), 0x10, 0, 0) == 0)
                return;
            func_0203DC68(p, 3);
        }
        break;
    case 3:
        p->f100--;
        if (func_0203D210()) {
            if (g_021469F0->f8c != 0)
                g_021469F0->f8c(g_021469F0->f70);
            if (p->f10a != 0 && p->f60 == 4 && p->f105 == 0) {
                func_0203DC68(p, 0xE);
                p->f108++;
            } else if (p->f105 == 0 && p->f60 == 4) {
                p->f108++;
                func_0203CEAC(0);
                p->f88(p->f70, 1);
                func_0203DC68(p, 4);
            } else {
                p->f88(p->f70, 0);
                func_0203DC68(p, 9);
            }
        }
        if (p->f100 == 0)
            func_0203CEAC(0);
        break;
    case 4:
        if (func_0203CD98() != 0)
            return;
        p->f65 = 3;
        p->f2c = (void *)func_0203DC4C;
        if (p->f10b != 0)
            p->f67 = p->f10b;
        p->f102 = 0;
        p->f103 = 0;
        func_0203CBAC((struct Req *)p, 0, p->f70);
        func_0203DC68(p, 5);
        break;
    case 5:
        if (func_0203CD98() != 1)
            return;
        func_0203D788()->f340->fc8(g_021469F0->f74);
        func_0203D0DC((int)((void *)func_0203DC04));
        func_0203DC68(p, 6);
        break;
    case 6:
        if (p->f102 != 1)
            return;
        p->f101 = 1;
        if (func_0203D3A8(func_020399A8(), 9, 0x24, (u32)((void *)g_021469F0->f90)) == 0)
            return;
        func_0203DC68(p, 7);
        break;
    case 7:
        if (p->f102 != 1)
            return;
        if (func_0203D3A8(func_020399A8(), 1, 0, 0) == 0)
            return;
        func_0203D17C(0xC8);
        func_0203DC68(p, 8);
        break;
    case 8:
        if (func_0203D210() == 0)
            return;
        if (g_021469F0->f8c != 0)
            g_021469F0->f8c(g_021469F0->f70);
        func_0203DC68(p, 9);
        break;
    case 9:
        if (func_0203D210() == 0)
            return;
        if (p->f10b != 0) {
            p->f6e = 0;
            p->f67 = p->f10b;
        }
        p->f65 = 0;
        p->f2c = p->f80;
        p->f64 = p->f104;
        func_0203CBAC((struct Req *)p, 0, p->f70);
        g_021469F0->f101 = 0;
        func_0203DC68(p, 0xA);
        break;
    case 10:
        if (func_0203CD98() != 1)
            return;
        if (p->f105 == 0) {
            func_0203D01C();
            func_0203DC68(p, 0xC);
        } else if (p->f60 == 4) {
            func_0203D010();
            func_0203DC68(p, 0xB);
        } else {
            func_0203CFF0(p->f94);
            func_0203DC68(p, 0xC);
        }
        break;
    case 11: {
        u8 mac[6];
        int i;
        int j;
        u8 *q;

        i = 0;
        func_02087C6C(mac);
        for (;; i++) {
            q = (u8 *)func_0203CF10((int)i);
            if (q == 0)
                return;
            for (j = 0; j < 4; j++) {
                if (func_0203EFC8(mac, q + 4 + j * 8, 6) == 0) {
                    func_0203D000(func_0203CF3C((u32)i));
                    func_0203DC68(p, 0xC);
                    break;
                }
            }
        }
    }
    case 12:
        if (p->f105 == 0) {
            if (func_020399EC() == 0)
                return;
            if (func_02039ACC() != 1)
                return;
            func_0203DC68(p, 0xD);
        } else {
            if (func_02039ACC() != 1)
                return;
            func_0203DC68(p, 0xD);
        }
        break;
    case 13:
        if (p->f105 != 0) {
            if (p->f84 != 0)
                p->f84(p->f70);
            func_0203DA20();
        } else {
            if (func_020399EC() < p->f107)
                return;
            if (p->f84 != 0)
                p->f84(p->f70);
            func_0203DA20();
        }
        break;
    case 14:
        if (func_0203CD98() != 0)
            return;
        p->f65 = 3;
        p->f2c = (void *)func_0203DC4C;
        p->f102 = 0;
        p->f103 = 0;
        func_0203CBAC((struct Req *)p, 0, p->f70);
        func_0203DC68(p, 0xF);
        break;
    case 15:
        if (func_0203CD98() != 1)
            return;
        func_0203D788()->f340->fc8(g_021469F0->f74);
        func_0203D0DC((int)((void *)func_0203DC04));
        func_0203DC68(p, 0x10);
        break;
    case 16:
        if (p->f102 != 1)
            return;
        func_02039C68((struct Link *)func_020399A8(), 3, 0);
        g_021469F0->f101 = 1;
        func_0203DC68(p, 0x11);
        break;
    case 17:
        if (func_02039CB4((struct Link *)func_020399A8(), 3, 0) == 0)
            return;
        if (func_0203D3A8(func_020399A8(), 1, 0, 0) == 0)
            return;
        func_0203DC68(p, 0x12);
        p->f100 = 0xC8;
        break;
    case 18:
        p->f100--;
        if (func_0203D210() == 0 && p->f100 != 0)
            return;
        if (g_021469F0->f8c != 0)
            g_021469F0->f8c(g_021469F0->f70);
        if (p->f10a != 0 && p->f108 < 3) {
            p->f108++;
            if (p->f108 >= 3)
                func_0203DC68(p, 9);
            else
                func_0203DC68(p, 0xE);
        } else {
            func_0203DC68(p, 9);
        }
        break;
    }
}
