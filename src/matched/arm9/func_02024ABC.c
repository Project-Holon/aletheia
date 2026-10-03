/*
 * function: func_02024ABC
 * address:  0x02024ABC
 * packet:   pkt_02024ABC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     infowin per-frame state poll (the TCB-less update): clock tick,
 *           link/wireless state, then the dirty bits of +0x04.  Two shape
 *           facts carry the whole match: every flag update is spelled out
 *           (`f = (u16)(f | X)`, which reuses the tested load; `|=` re-reads
 *           it), and every clear mask is the u16 constant (the pool holds
 *           0x0000EFFF, not ~0x1000).
 *
 * symbols:
 *   func_020252A8       0x020252A8  thumb
 *   func_0203568C       0x0203568C  arm
 *   func_0203CD98       0x0203CD98  arm
 *   func_0203D798       0x0203D798  arm
 *   func_0203D1B4       0x0203D1B4  arm
 *   func_0203D29C       0x0203D29C  arm
 *   func_0201058C       0x0201058C  thumb
 *   func_02026CA0       0x02026CA0  thumb
 *   gInfoWin            0x0214693C  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct InfoWin {
    u32 f00;
    u16 f04;
    u8  f06;
    u8  f07;
    u8  f08;
    u8  f09;
    u8  pad0A[2];
    u32 f0C;
    u32 f10;
    u32 f14;
    u32 f18;
    u8  f1C;
    u8  f1D;
    u8  f1E;
    u8  f1F;
    u32 f20;
    void *f24;
};

struct Link {
    u8 pad00[0x65];
    u8 f65;
    u8 f66;
    u8 f67;
};

extern struct InfoWin *gInfoWin;

extern void  func_020252A8(void);
extern int   func_0203568C(void);
extern int   func_0203CD98(void);
extern void *func_0203D798(void);
extern int   func_0203D1B4(void);
extern u32 func_0203D29C(void);
extern u32   func_0201058C(u32 a);
extern int   func_02026CA0(int *p);

void func_02024ABC(void)
{
    int flag = 0;
    u8 n = 0;
    struct Link *link = 0;
    u32 bits;
    int idx;

    if (gInfoWin == 0)
        return;

    func_020252A8();
    gInfoWin->f1E++;
    if (gInfoWin->f1E > 60) {
        u8 v = func_0203568C();
        if (gInfoWin->f1F != v) {
            gInfoWin->f1F = v;
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x20);
        }
        gInfoWin->f1E = 0;
    }

    if (func_0203CD98() == 1) {
        link = func_0203D798();
        n = func_0203D1B4();
        if (func_0203D29C() == 1)
            flag = 1;
    }

    if (n < 2 && flag == 0) {
        bits = func_0201058C(gInfoWin->f0C);
        idx = 0;
        if (gInfoWin->f10 == 1 && func_02026CA0(&idx) != 0x1E) {
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x1000);
        } else {
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
            gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xEFFF);
        }
        if (!(bits & 2)) {
            if (((gInfoWin->f04 & 0x200) ? 1 : 0) == 1) {
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 4);
                gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xFDFF);
            }
        }
        if (bits & 0x3C) {
            if (bits & 0xC) {
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x400);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x800);
            } else if (((gInfoWin->f04 & 0x400) ? 1 : 0) == 0) {
                gInfoWin->f08 = 0;
                gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xF7FF);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x400);
            }
        } else if (((gInfoWin->f04 & 0x400) ? 1 : 0) == 1) {
            gInfoWin->f08 = 0;
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
            gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xFBFF);
            gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xF7FF);
        }
        if (bits & 0x3C0) {
            if (gInfoWin->f20 == 0) {
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 8);
                gInfoWin->f20 = 1;
            }
        } else if (gInfoWin->f20 != 0) {
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 8);
            gInfoWin->f20 = 0;
        }
    } else if (link != 0) {
        if (link->f65 == 3) {
            if (((gInfoWin->f04 & 0x200) ? 1 : 0) == 0) {
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 4);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x200);
            }
        } else if (((gInfoWin->f04 & 0x200) ? 1 : 0) == 1) {
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 4);
            gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xFDFF);
        }
        if (link->f65 == 0 || link->f65 == 4 || link->f65 == 5) {
            if (((gInfoWin->f04 & 0x400) ? 1 : 0) == 0) {
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x400);
                gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xF7FF);
                gInfoWin->f08 = 0;
            }
            if (link->f67 == 2) {
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x400);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x800);
            }
        } else if (((gInfoWin->f04 & 0x400) ? 1 : 0) == 1) {
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
            gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xFBFF);
            gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xF7FF);
            gInfoWin->f08 = 0;
        }
        if (link->f65 == 1 || link->f65 == 2 || link->f65 == 6) {
            if (gInfoWin->f20 == 0) {
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 8);
                gInfoWin->f20 = 1;
            }
        } else if (gInfoWin->f20 != 0) {
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 8);
            gInfoWin->f20 = 0;
        }
    }
}
