/*
 * function: func_021B0F38
 * address:  0x021B0F38
 * packet:   pkt_ov013_021B0F38
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The last two arguments are one u64 (an OS tick, stored to v+0x464):
 * split across r3 and the stack, which is what pulls the high word into a
 * register at entry.
 *
 * symbols:
 *   d_021B3C84  0x021B3C84  data  ov013  a4
 *   d_021B3CBC  0x021B3CBC  data  ov013  a4
 *   d_021B3AD0  0x021B3AD0  data  ov013  a1
 *   func_021B2FB0  0x021B2FB0  arm  ov013
 *   func_021B1720  0x021B1720  arm  ov013
 *   func_021B133C  0x021B133C  arm  ov013
 *   func_021B1790  0x021B1790  arm  ov013
 *   func_021B1398  0x021B1398  arm  ov013
 *   func_021B1B94  0x021B1B94  arm  ov013
 *   func_021B1404  0x021B1404  arm  ov013
 *   func_021B2FE4  0x021B2FE4  arm  ov013
 *   func_02082D44  0x02082D44  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct {
    u32 f0;
    u8 f4;
    u8 f5;
    u16 f6;
    u32 f8;
    u8 data[1];
} Frame;

typedef struct {
    u8 pad0[0x24];
    int f24;
    u8 pad28[0x8];
    u32 f30;
    u32 f34;
    u32 f38;
    u8 pad3C[0x10];
    u32 f4C;
    u8 pad50[0x1c];
    u32 f6C;
    u8 pad70[0x94 - 0x70];
} Chan;

typedef struct {
    u8 a;
    u8 b;
} SizeEnt;

typedef struct {
    u32 f0;
    u32 f4;
    u8 pad8[0x18];
    u32 f20;
} Ctx3C84;

typedef struct Voice {
    u32 f0;
    u32 f4;
    u32 f8;
    int fC;
    u8 f10;
    u8 f11;
    u8 pad12[2];
    u32 f14;
    u32 f18;
    u8 buf[0x45c - 0x1c];
    u32 f45C;
    u32 f460;
    u64 tick;
    u32 f46C;
    u32 f470;
    void *f474;
} Voice;

extern Ctx3C84 d_021B3C84;
extern Chan d_021B3CBC[3];
extern SizeEnt d_021B3AD0[];

extern Voice *func_021B2FB0(void);
extern void func_021B1720(u32 x);
extern void func_021B133C(u32 x);
extern void func_021B1790(void);
extern void func_021B1398(void);
extern int func_021B1B94(Chan *ch, Voice *v);
extern void func_021B1404(Voice *v);
extern void func_021B2FE4(Voice *v);
extern void func_02082D44(void *src, void *dst, u32 n);

int func_021B0F38(u32 id, Frame *hdr, u32 size, u64 tick)
{
    Voice *v;
    Chan *ch;
    int mode;
    u32 i;
    u8 *dst;

    ch = 0;
    if (d_021B3C84.f20 == 0)
        return 0;

    for (i = 0; i < 3; i++) {
        if (id == d_021B3CBC[i].f38) {
            ch = &d_021B3CBC[i];
            break;
        }
    }
    if (ch == 0)
        return 0;

    if (hdr->f4 == 0x41) {
        ch->f30 = hdr->f6;
        ch->f4C = 0;
        ch->f6C = 1;
        return 0;
    }
    if (hdr->f4 != 0x40)
        return 0;

    mode = hdr->f5 & 0x7f;
    ch->f24 = mode;
    if (mode >= 5)
        return 0;
    if (size != d_021B3AD0[mode].a * 0x44 + d_021B3AD0[mode].b + 0xc)
        return 0;
    if ((d_021B3C84.f4 & (id != 0 ? 1 << id : 1)) == 0)
        return 0;

    if ((v = func_021B2FB0()) == 0) {
        func_021B1720(ch->f34);
        func_021B133C(ch->f34);
        if ((v = func_021B2FB0()) == 0) {
            func_021B1790();
            func_021B1398();
            v = func_021B2FB0();
        }
        if (v == 0)
            return 0;
    }

    dst = &v->buf[sizeof(v->buf)] - (size - 0xc);
    func_02082D44(hdr->data, dst, size - 0xc);
    v->f11 = ch->f34;
    v->fC = mode;
    v->f474 = dst;
    v->f14 = size - 0xc;
    v->tick = tick;
    v->f10 = id;
    v->f45C = hdr->f5 & 0x80;
    v->f460 = hdr->f8;
    v->f18 = hdr->f6;
    if (func_021B1B94(ch, v) == 0) {
        func_021B2FE4(v);
        return 0;
    }
    func_021B1404(v);
    return 1;
}
