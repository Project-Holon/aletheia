/*
 * unit:     yes
 * address:  0x0200C5F8
 * packet:   pkt_0200C5F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0200C5F8
 *
 * 0x0200C5F8..0x0200C6D8, 224 bytes, one function.
 *
 * The state machine of "musical_dist_save.c"; see src/matched/unit_0200C5A4.c
 * for the record it works on and for how the file name is attested.
 *
 * What held it open, and what closed it: 0x0200A7F8 is the target of exactly
 * one branch in the whole image, the `bl` at 0x0200C680 inside this very
 * function, so the `label` class discards its only witness under the honesty
 * rule and no cut helps, because shrinking the range to this one function
 * keeps the call in it.  The `matched` class carries it: 0x0200A7F8 is inside
 * src/matched/unit_0200A6F8.c, an EXACT entry verified against the original
 * bytes over a range this file does not touch.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_0200C5F8.c \
 *       --addr 0x0200C5F8 --thumb
 *
 * The tag the three service calls take is `(u16)((p->unk00 & 0x7FFF) |
 * 0x8000)` written out at each of the three sites: the original reloads the
 * halfword and redoes the mask each time while keeping 0x7FFF alive in r4,
 * and 0x8000 is reached as `adds rN, r4, #1` off that pool word rather than
 * from one of its own.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_0204913C  0x0204913C  arm
 *   func_0204A39C  0x0204A39C  arm
 *   func_02045C44  0x02045C44  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045A38  0x02045A38  arm
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_02049238  0x02049238  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Big;
struct MsgBank;
struct Rec;
struct U16Vec;
extern void *func_02012EBC(struct Big *p);
extern void  func_02012E4C(void *sys, u32 id);
extern int func_02012E7C(char *p, int a1);
extern void *func_0200A5F8(void *save);
extern void func_0200A7EC(struct Big *p, u8 value);
extern u8 *func_0200A7F8(struct Big *p);

extern void  func_020307B0(void *p);
extern void *func_0204913C(void *a0, u32 a1, u32 heap);
extern void *func_0204A39C(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);
extern struct MsgBank *func_02045C44(const void *file, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void  func_02045A38(void *a, void *b, u32 c);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045C04(struct Rec *rec);
extern void  func_02049238(void *a);

struct DistHdr {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
};

struct MusicalDist {
    u16 unk00;
    u32 unk04;
    u32 unk08;
    struct DistHdr unk0C;
    void *unk1C;
    void *unk20;
    u8   *unk24;
    void *unk28;
};

extern void func_0200C5A4(struct MusicalDist *p);

u32 func_0200C5F8(struct MusicalDist *p)
{
    u32 loc;
    void *a;
    void *c;
    void *d;
    void *e;
    void *f;

    switch (p->unk08) {
    case 0:
        if (p->unk1C == 0) {
            func_0200C5A4(p);
            return 1;
        }
        a = func_0200A5F8(func_02012EBC(p->unk28));
        func_0200A7EC(a, 1);
        c = func_0204913C(p->unk24, p->unk0C.unk00,
                          (u16)((p->unk00 & 0x7FFF) | 0x8000));
        d = func_0204A39C(c, 1, 0, (u16)((p->unk00 & 0x7FFF) | 0x8000), &loc);
        e = func_02045C44(d, (u16)((p->unk00 & 0x7FFF) | 0x8000));
        f = func_02045EC0(e, 0);
        func_02045A38(f, func_0200A7F8(a), 0x25);
        func_02045808(f);
        func_02045C04(e);
        func_020307B0(d);
        func_02049238(c);
        func_02012E4C(p->unk28, 6);
        p->unk08++;
        break;
    case 1:
        if (func_02012E7C(p->unk28, 6) == 2) {
            func_0200C5A4(p);
            return 1;
        }
        break;
    }
    return 0;
}
