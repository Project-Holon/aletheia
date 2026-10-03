/*
 * function: func_021A8FFC
 * address:  0x021A8FFC
 * packet:   pkt_ov021_021A8FFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   func_02035C08  0x02035C08  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_020355D8  0x020355D8  arm
 *   func_021A90A4  0x021A90A4  thumb  ov021
 *   d_021D8C2C     0x021D8C2C  data  ov021  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Slot {
    u32 f00;
    u32 f04;
    u32 f08;
    u8 pad0C[8];
    u8 f14;
    u8 f15;
    u8 pad16[2];
    void *f18;
};

struct W {
    u8 pad00[0x1E];
    u8 f1E;
    u8 f1F;
    u8 pad20[4];
    u32 f24;
    u8 pad28[4];
    u32 f2C;
    u32 f30;
    struct Slot slots[7];
    u32 cur;
    u8 padFC[0x28];
    void *f124;
};

struct Buf32 {
    u8 b[32];
};

extern struct Buf32 d_021D8C2C;

extern int func_02035C08(struct Buf32 *b);
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_020355D8(u8 v);
extern void func_021A90A4(struct W *w, u32 v);

void func_021A8FFC(struct W *w)
{
    struct Buf32 buf = d_021D8C2C;
    int r = func_02035C08(&buf);
    u32 z;

    if (r != -1 && w->slots[r].f08 != 7) {
        w->f1E = r % 2;
        w->f1F = r / 2;
        z = 0;
        w->f2C = z;
        func_0204B3DC(w->f124, 0);
        if (r == 6) {
            func_021A90A4(w, 1);
            return;
        }
        w->f24 = 1;
        func_021A90A4(w, z);
        func_020355D8(1);
    }
}
