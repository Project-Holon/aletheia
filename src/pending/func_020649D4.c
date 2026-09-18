/*
 * function: func_020649D4
 * address:  0x020649D4
 * packet:   pkt_020648E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * symbols:
 *   func_020629E8   0x020629E8  arm
 *   func_02062D40   0x02062D40  arm
 *   func_02062D4C   0x02062D4C  arm
 *   func_020640DC   0x020640DC  arm
 *   func_02064100   0x02064100  arm
 *   func_02064120   0x02064120  arm
 *   func_02064140   0x02064140  arm
 *   func_020643CC   0x020643CC  arm
 *   func_02064934   0x02064934  arm
 *
 * The timed form of the node walk: it advances the node's counter at +0x30 by
 * the frame delta in the header's word at +4 first, and when func_02062D4C
 * reports that the animation has no next frame it hands the whole node to
 * func_02064934 instead.  The rest is func_0206469C's frame rebuild.
 *
 * Residue, eight bytes: the same cross-jumped `add r0, r4, #0x48;
 * bl func_020640DC` tail that blocks func_0206469C.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020649D4.c \
 *       --func func_020649D4 --addr 0x020649D4 --arm --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Srt020649D4 {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    s16 unk_0c;
    s16 unk_0e;
    u16 unk_10;
    u16 unk_12;
};

struct FrameHdr020649D4 {
    u8  pad_00[4];
    u32 kind;
};

struct Node020649D4 {
    u16 unk_00;
    u16 unk_02;
    s16 unk_04;
    s16 unk_06;
    u32 unk_08;
    s16 unk_0c;
    s16 unk_0e;
};

struct Obj020649D4 {
    u8  *unk_00;    /* +0x00 */
    u8  *unk_04;    /* +0x04 */
    u8   pad_08[0x14];
    struct FrameHdr020649D4 *unk_1c;
    u8   pad_20[0x10];
    u16  unk_30;
    u8   pad_32[2];
    u32  unk_34[4];
    void *unk_44;
    struct Srt020649D4 unk_48;
};

extern void func_02064934(void *walk, void *arg);
extern s32 func_02062D4C(struct Obj020649D4 *o);
extern void *func_02062D40(struct Obj020649D4 *o);
extern void *func_020629E8(void *bank, u32 idx);
extern void func_02064140(struct Srt020649D4 *srt, u32 a);
extern void func_020640DC(struct Srt020649D4 *srt, s16 x, s16 y);
extern void func_02064100(struct Srt020649D4 *srt, u16 rot);
extern void func_02064120(struct Srt020649D4 *srt, u32 sx, u32 sy);
extern void func_020643CC(void *walk, u32 a, u16 b);

void func_020649D4(struct Obj020649D4 *o, void *arg)
{
    struct Node020649D4 *p;
    u32 k;
    u32 r;
    u16 d = *(u16 *)(o->unk_00 + 4);

    if (func_02062D4C(o) == 0) {
        func_02064934(o->unk_34, arg);
        return;
    }

    o->unk_30 += d;

    if (*(u16 *)(o->unk_04 + 4) == 0) {
        return;
    }

    p = func_02062D40(o);
    r = (u32)func_020629E8(o->unk_44, p->unk_00);
    k = o->unk_1c->kind & 0xff;

    func_02064140(&o->unk_48, 1);

    if (k == 0) {
        goto done;
    }

    if (k == 2) {
        func_020640DC(&o->unk_48, p->unk_04, p->unk_06);
    } else {
        func_02064120(&o->unk_48, *(u32 *)&p->unk_04, p->unk_08);
        func_02064100(&o->unk_48, p->unk_02);
        func_020640DC(&o->unk_48, p->unk_0c, p->unk_0e);
    }

done:
    func_020643CC(o->unk_34, r, o->unk_30);
}
