/*
 * function: func_021C567C
 * address:  0x021C567C
 * packet:   pkt_ov111_021C567C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02035C08  0x02035C08  arm
 *   func_021C5280  0x021C5280  thumb  ov111
 *   func_021C5484  0x021C5484  thumb  ov111
 *   func_021C55A4  0x021C55A4  thumb  ov111
 *   func_021C5BCC  0x021C5BCC  thumb  ov111
 *   d_021C8554     0x021C8554  data  a1
 *   d_021C8594     0x021C8594  data  a1
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
    u8 f4_7 : 1;
} Info;

typedef struct {
    u8 pad0[0x28];
    Info *info;
    u8 pad2C[0x3034 - 0x2C];
    u32 f3034;
    u8 pad3038[0x305E - 0x3038];
    u16 h305E;
} Work;

extern int func_02035C08(const void *rect);
extern int func_021C5280(Work *p, int hit);
extern int func_021C5484(Work *p, int hit);
extern void func_021C55A4(Work *p);
extern void func_021C5BCC(Work *p, int side);
extern const u8 d_021C8554[];
extern const u8 d_021C8594[];

int func_021C567C(Work *p)
{
    int hit;
    int r;

    if (p->info->f4_7 == 0) {
        hit = func_02035C08(d_021C8594);
    } else {
        hit = func_02035C08(d_021C8554);
    }
    if (p->h305E == 0) {
        r = func_021C5280(p, hit);
    } else {
        r = func_021C5484(p, hit);
    }
    if (r != 0) {
        return r;
    }
    if (p->f3034 != 0) {
        if (p->h305E == 0) {
            func_021C55A4(p);
            func_021C5BCC(p, 0);
        } else {
            func_021C5BCC(p, 1);
        }
    }
    return 0;
}
