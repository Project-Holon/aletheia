/*
 * function: func_021A066C
 * address:  0x021A066C
 * packet:   pkt_ov021_021A066C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02048CA4  0x02048CA4  arm
 *   func_02048CDC  0x02048CDC  arm
 *   func_0206AA8C  0x0206AA8C  arm
 *   func_0206AAB0  0x0206AAB0  arm
 *   func_021A01C4  0x021A01C4  thumb  ov021
 *   func_0207DD24  0x0207DD24  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 x, y, z;
} V3s;

typedef struct {
    u8 pad[0x35A];
    u8 used[4];
    u16 c[4];
    V3s b[4];
    u16 f37E;
    u16 f380;
    u16 f382;
    u16 f384;
    u16 f386;
    u16 f388;
    u16 active;
} W;

extern void func_02048CA4(u32, u8, const V3s *);
extern void func_02048CDC(u32, u8, const u16 *);
extern void func_0206AA8C(u16, u16, u32);
extern void func_0206AAB0(u16, u16, u32);
extern void func_021A01C4(u32, u16);
extern void func_0207DD24(u16, int, int, int, int);

void func_021A066C(const W *w, u32 a, u32 p)
{
    int i;
    V3s zb = {0, 0, 0};
    u16 zc = 0;

    if (w->active == 0) {
        return;
    }
    for (i = 0; i < 4; i++) {
        if (w->used[i]) {
            func_02048CA4(p, i, &w->b[i]);
            func_02048CDC(p, i, &w->c[i]);
        } else {
            func_02048CA4(p, i, &zb);
            func_02048CDC(p, i, &zc);
        }
    }
    func_0206AA8C(w->f37E, w->f380, 1);
    func_0206AAB0(w->f382, w->f384, 0);
    func_021A01C4(a, w->f386);
    func_0207DD24(w->f388, 0x1F, 0x7FFF, 0, 0);
}
