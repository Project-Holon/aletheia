/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200BDBC
 * packet:   pkt_0200B448
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0200BDBC, func_0200BDC4, func_0200BDE4, func_0200BDF8,
 *           func_0200BDFC, func_0200BE00, func_0200BE24
 *
 * 140 bytes, 0x0200BDBC..0x0200BE48, 7 functions, five of which carry no
 * label in the generated listing.
 *
 * A 0x1B0-byte record: func_0200BDBC returns its size and func_0200BDC4
 * clears exactly that many bytes, which is the block-file opening this region
 * keeps producing.  The constructor then seeds the byte at +0x1A0 with 0x30
 * and reaches it by subtracting 0x10 from the size it already has in a
 * register rather than materialising 0x1A0 again; that is the compiler's
 * doing and not a second constant in the source.
 *
 * func_0200BDE4 hands the first sixteen bytes to func_021763BC, which lives
 * in overlay address space.  The call is attested because ov019's generated
 * listing carries a `func_` label at 0x021763BC and branches elsewhere in the
 * image reach it; see "Callees that live in an overlay" in docs/MATCHING.md.
 *
 * func_0200BE00 and func_0200BE24 are the same clamped adder over two
 * neighbouring `u16` counters, and the ceiling 999 arrives from a literal
 * pool in each of them because it does not fit a Thumb immediate.  The
 * increment has to be written `p->f += v` with a **signed** parameter: the
 * comparison is a signed `ble`, and spelling the store as
 * `p->f = p->f + (u16)v` adds the truncation pair the store already does for
 * free.
 *
 * symbols:
 *   MI_CpuFill8     0x02082BCC  arm
 *   func_021763BC   0x021763BC  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void MI_CpuFill8(void *dest, u8 value, u32 size);
extern void func_021763BC(void *p);

struct Rec1B0 {
    u8  unk00[0x0C];
    u16 unk0C;
    u16 unk0E;
    u8  unk10[0x1A0 - 0x10];
    u8  unk1A0;
    u8  unk1A1[0x0F];
};

void func_0200BDE4(struct Rec1B0 *p);

u32 func_0200BDBC(void)
{
    return sizeof(struct Rec1B0);
}

void func_0200BDC4(struct Rec1B0 *p)
{
    MI_CpuFill8(p, 0, sizeof(struct Rec1B0));
    func_0200BDE4(p);
    p->unk1A0 = 0x30;
}

void func_0200BDE4(struct Rec1B0 *p)
{
    MI_CpuFill8(p, 0, 0x10);
    func_021763BC(p);
}

u16 func_0200BDF8(struct Rec1B0 *p)
{
    return p->unk0C;
}

u16 func_0200BDFC(struct Rec1B0 *p)
{
    return p->unk0E;
}

void func_0200BE00(struct Rec1B0 *p, s32 v)
{
    if (p->unk0C + v > 999) {
        p->unk0C = 999;
    } else {
        p->unk0C += v;
    }
}

void func_0200BE24(struct Rec1B0 *p, s32 v)
{
    if (p->unk0E + v > 999) {
        p->unk0E = 999;
    } else {
        p->unk0E += v;
    }
}
