/*
 * function: func_021B8AC4
 * address:  0x021B8AC4
 * packet:   pkt_ov091_021B8AC4
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm
 *   func_0203633C  0x0203633C  arm
 *   func_0204B3F4  0x0204B3F4  arm
 *   func_021B8F68  0x021B8F68  thumb  ov091
 *   func_021BAFA0  0x021BAFA0  thumb  ov091
 *   func_021BBE5C  0x021BBE5C  thumb  ov091
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_021BB468  0x021BB468  thumb  ov091
 *   func_021B9A84  0x021B9A84  thumb  ov091
 *   func_021B9AA0  0x021B9AA0  thumb  ov091
 *   func_021B9AB4  0x021B9AB4  thumb  ov091
 *   func_0201AA18  0x0201AA18  thumb
 *   func_021BB3C4  0x021BB3C4  thumb  ov091
 *   func_0204B878  0x0204B878  arm
 *   d_021BEAB0     0x021BEAB0  data  a1
 *   d_021BEAAA     0x021BEAAA  data  a1
 *
 * The two byte tables resolve as sole-ref only without an overlay token
 * (with `ov091` the hint is reported contested).  The spilled locals sit
 * up @0, done @4, old @8, trg @0xc: declared trg, old, done, up.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define W(o) (*(int *)(p + (o)))

extern u32  func_020362DC(void);
extern unsigned int func_0203633C(void);
extern int  func_0204B3F4(int h);
extern void func_021B8F68(u8 *p, int v);
extern void func_021BAFA0(u8 *p, int v, int z);
extern void func_021BBE5C(int h, int f);
extern void func_0204B3DC(int h, int f);
extern void func_020061E4(u32 id);
extern int  func_021BB468(u8 *p, int v);
extern int  func_021B9A84(u8 *p);
extern int  func_021B9AA0(u8 *p);
extern int  func_021B9AB4(u8 *p);
extern int  func_0201AA18(int);
extern int func_021BB3C4(void *unused, u32 p);
extern void func_0204B878(int h, int f);

extern const u8 d_021BEAB0[];
extern const u8 d_021BEAAA[];

void func_021B8AC4(u8 *p)
{
    u32 trg;
    int old;
    int done;
    u32 up;
    u32 rep;
    int dir;
    int max;
    u8 cnt;
    int n;

    trg = func_020362DC();
    rep = func_0203633C();
    if (W(8) == 1 && func_0204B3F4(W(0x1d8)) == 0) {
        if (trg != 0 && (trg & 0x402) == 0) {
            if (W(0x2c) <= 5) {
                func_021B8F68(p, W(0x2c));
                func_021BAFA0(p, *(int *)(p + W(0x2c) * 4 + 0x160), 1);
            } else {
                func_021BBE5C(*(int *)(p + (u8)(W(0x2c) - 6) * 4 + 0x108), 1);
                func_0204B3DC(W(0x1d8), 0);
            }
            func_020061E4(0x548);
            W(8) = 0;
        }
    } else {
        dir = 0;
        if (trg != 0) {
            W(8) = 0;
        }
        up = rep & 0x40;
        if (up) {
            dir = -2;
        } else if (rep & 0x80) {
            dir = 2;
        } else if (rep & 0x20) {
            dir = -1;
        } else if (rep & 0x10) {
            dir = 1;
        } else if (trg & 1) {
            if (W(0x2c) == 6) {
                p[0xf] = 0;
            } else if (W(0x2c) == 7) {
                p[0xf] = 1;
            } else if (W(0x28) == 0 && func_021BB468(p, *(int *)(p + W(0x2c) * 4 + 0x160)) == 1) {
                func_020061E4(0x557);
            } else {
                p[0xf] = 3;
            }
        }
        if (dir != 0) {
            old = W(0x2c);
            done = 0;
            if (func_021B9A84(p) == 1) {
                if (func_021B9AA0(p) == 1) {
                    max = 7;
                } else {
                    max = 6;
                }
            } else {
                max = 5;
            }
            if ((u32)(W(0x2c) - 6) <= 1 && (rep & 0xc0)) {
                cnt = func_0201AA18(*(int *)W(0x280));
                if (up) {
                    if (W(0x2c) == 7 || func_021B9AA0(p) == 0) {
                        W(0x2c) = d_021BEAB0[cnt - 1];
                    } else {
                        W(0x2c) = d_021BEAAA[cnt - 1];
                    }
                } else {
                    if (W(0x2c) == 7 || func_021B9AA0(p) == 0) {
                        if (cnt > 1) {
                            W(0x2c) = 1;
                        } else {
                            W(0x2c) = 0;
                        }
                    } else {
                        W(0x2c) = 0;
                    }
                }
            } else {
                do {
                    n = W(0x2c) + dir;
                    if (n > max) {
                        if (max == 6 && dir > 1 && old != 6) {
                            W(0x2c) = max;
                        } else {
                            W(0x2c) = n - (max + 1);
                        }
                    } else if (n < 0) {
                        if (max == 6 && dir < 1) {
                            W(0x2c) = max;
                        } else {
                            W(0x2c) = dir + (W(0x2c) + (max + 1));
                        }
                    } else {
                        W(0x2c) += dir;
                    }
                    if (W(0x2c) > 5 || func_021BB3C4(p, *(int *)(p + W(0x2c) * 4 + 0x160)) == 1) {
                        done = 1;
                    }
                } while (done == 0);
            }
            if (old != W(0x2c)) {
                if (W(0x2c) <= 5) {
                    func_021B8F68(p, W(0x2c));
                    func_021BAFA0(p, *(int *)(p + W(0x2c) * 4 + 0x160), 1);
                } else {
                    func_021BBE5C(*(int *)(p + (u8)(W(0x2c) - 6) * 4 + 0x108), 1);
                    func_0204B3DC(W(0x1d8), 0);
                }
                if (old <= 5) {
                    func_021BAFA0(p, *(int *)(p + old * 4 + 0x160), 0);
                } else {
                    func_021BBE5C(*(int *)(p + (u8)(old - 6) * 4 + 0x108), 0);
                }
                p[0x100] = 0xc;
            }
            func_020061E4(0x548);
        }
    }
    if (trg & 2) {
        if (func_021B9A84(p) == 0 || func_021B9AA0(p) == 1) {
            if (func_021B9AB4(p) == 1) {
                p[0xf] = 1;
                W(0x1e8) = W(0x1e0);
                func_0204B878(W(0x1e8), 9);
                W(8) = 0;
            }
        }
    } else if ((trg & 0x400) && W(0x14) == 1) {
        p[0xf] = 2;
        W(0x1e8) = W(0x1e4);
        func_0204B878(W(0x1e8), 8);
        W(8) = 0;
    }
}
