/*
 * function: func_0216A0BC
 * address:  0x0216A0BC
 * packet:   pkt_ov010_0216A0BC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct (first draft). Blocker: 0x021904A8 has no func_ label in
 * any overlay listing (ov009 and ov021 overlap it); it sits four bytes before
 * ov021's func_021904AC and is almost certainly a Thumb accessor there. Seeding
 * it in ov021 closes this file.
 *
 * symbols:
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045C04  0x02045C04  arm
 *   func_021904AC  0x021904AC  thumb  ov021
 *   func_021904A8  0x021904A8  thumb  ov021
 *   func_02027F60  0x02027F60  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Res {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    u8 pad0C[0x10 - 0x0C];
    void *f10;          /* 0x10 */
    void *f14;          /* 0x14 */
    void *f18;          /* 0x18 */
    void *f1C;          /* 0x1C */
    u32 f20;            /* 0x20 */
    void *f24;          /* 0x24 */
    u16 f28;            /* 0x28 */
    u32 f2C;            /* 0x2C */
    void *f30;          /* 0x30 */
    u16 f34;            /* 0x34 */
    u32 f38;            /* 0x38 */
    void *f3C;          /* 0x3C */
    void *f40;          /* 0x40 */
} Res;

typedef struct Work {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u8 *f08;            /* 0x08 */
    void *f0C;          /* 0x0C */
    u16 f10;            /* 0x10 */
    u8 pad12[0x18 - 0x12];
    Res *f18;           /* 0x18 */
} Work;

extern void *func_02045B38(u32 resident, u32 arc, u32 file, u32 heap);
extern void *func_02045EC0(void *bank, u32 index);
extern void func_02045C04(void *bank);
extern u32 func_021904AC(void *p);
extern u32 func_021904A8(void *p);
extern void *func_02027F60(u32 a0, u32 a1, u32 a2, u32 a3, u16 heap);

void func_0216A0BC(Work *w)
{
    void *bank;
    u32 a;

    bank = func_02045B38(0, 2, 0xA8, w->f10);
    w->f18->f24 = func_02045EC0(bank, 8);
    w->f18->f28 = 0x39E3;
    w->f18->f2C = 0;
    w->f18->f30 = func_02045EC0(bank, 9);
    w->f18->f34 = 0x39E3;
    w->f18->f38 = 0;
    func_02045C04(bank);
    a = func_021904AC(w->f0C);
    w->f18->f3C = func_02027F60(6, 14, a, func_021904A8(w->f0C), w->f10);
}
