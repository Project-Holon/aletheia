/*
 * function: func_021B7CF8
 * address:  0x021B7CF8
 * packet:   pkt_ov067_021B7CF8
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The case-8 arm is laid out first in the original (the jump table's last
 * entry is its smallest displacement), so it is written first in the switch.
 *
 * symbols:
 *   func_02035C08  0x02035C08  arm
 *   func_020355C4  0x020355C4  arm
 *   func_020355D8  0x020355D8  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

struct Ent {
    u32 f0;
    u32 f4;
};

typedef struct S {
    u8 pad00[0x1c];
    struct Ent *f1c;
    u8 pad20[0x2c - 0x20];
    void *f2c;
    u8 pad30[0x4c - 0x30];
    u16 f4c;
    u8 pad4e[0x5c - 0x4e];
    s16 f5c;
    u16 f5e;
    s16 f60;
    s16 f62;
    u16 f64;
    u8 pad66[0x7c - 0x66];
    u8 f7c;
    u8 pad7d[0x95 - 0x7d];
    u8 f95;
} S;

extern int func_02035C08(void *p);
extern int func_020355C4(void);
extern void func_020355D8(int a);

int func_021B7CF8(S *p)
{
    int idx;
    int save;

    if (p->f2c == 0)
        return 14;
    idx = func_02035C08(p->f2c);
    if (idx == -1)
        return 14;
    save = func_020355C4();
    func_020355D8(1);
    switch (p->f1c[idx].f4) {
    case 8:
        if (idx >= p->f5e)
            return 13;
        p->f60 = p->f5c;
        p->f5c = idx;
        return 12;
    case 0:
        if (idx >= p->f5e)
            return 13;
        p->f60 = p->f5c;
        p->f5c = idx;
        return 11;
    case 1:
        if (p->f4c > p->f5e) {
            p->f7c = idx;
            p->f60 = p->f5c;
            return 10;
        }
        func_020355D8(save);
        break;
    case 2:
        if (p->f62 != 0) {
            p->f95 = 0;
            return 2;
        }
        break;
    case 3:
        if (p->f62 < p->f64) {
            p->f95 = 0;
            return 3;
        }
        break;
    case 4:
        if (p->f62 != 0)
            return 4;
        if (p->f5c != 0) {
            p->f60 = p->f5c;
            p->f5c = 0;
            return 6;
        }
        break;
    case 5:
        if (p->f62 < p->f64)
            return 5;
        if (p->f5c < p->f5e - 1) {
            p->f60 = p->f5c;
            p->f5c = p->f5e - 1;
            return 7;
        }
        break;
    case 6:
        if (p->f5c != 0 || p->f62 != 0)
            return 8;
        break;
    case 7:
        if (p->f5c != p->f5e - 1 || p->f62 != p->f64)
            return 9;
        break;
    }
    return 14;
}
