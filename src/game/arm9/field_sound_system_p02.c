/*
 * file:     field_sound_system_p02.c
 * unit:     yes
 * function: func_020289B8, func_020289D4, func_020289F8, func_02028A14, func_02028A50, func_02028A58, func_02028A64, func_02028A70, func_02028A7C, func_02028ACC, func_02028B18, func_02028B50, func_02028BA0, func_02028BDC, func_02028C30, func_02028C50, func_02028CB0, func_02028CD4, func_02028D2C, func_02028D54, func_02028D7C, func_02028D8C, func_02028DB8
 * address:  0x020289B8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02028DCC  0x02028DCC  thumb
 *   func_02028E0C  0x02028E0C  thumb
 *   g_020A7518  0x020A7518  data
 *   g_020A7554  0x020A7554  data
 *   func_02028794  0x02028794  thumb
 *   func_02029F54  0x02029F54  thumb
 *   func_02029F60  0x02029F60  thumb
 *   func_02006148  0x02006148  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_021D21C0  0x021D21C0  thumb ov021
 *   func_021D21E0  0x021D21E0  thumb ov021
 *   func_020061F0  0x020061F0  thumb
 *   func_020062BC  0x020062BC  thumb
 *   func_020061F8  0x020061F8  thumb
 *   sTable_0209FDD0  0x0209FDD0  data
 *   func_02074324  0x02074324  arm
 *   func_0207466C  0x0207466C  arm
 *   func_020743EC  0x020743EC  arm
 *   func_02074450  0x02074450  arm
 *   func_020293D8  0x020293D8  thumb
 *   func_02005D28  0x02005D28  thumb
 *   _s32_div_f     0x0209C0A4  arm
 */
#include "../../matched/include/Obj11294.h"
#include "../../matched/include/Obj00164.h"

struct Cmd;
struct Fader;
struct Sys;
struct T;
struct SoundParam;
struct SoundParam2;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int            s32_0;

struct Sys {
    u32 unk00;
    u32 unk04;
    u8  unk08[0x14];
    u32 unk1C;
    u32 unk20;
};

struct SndCmd {
    u32 unk00;
    u32 unk04;
    u16 unk08;
    u16 unk0A;
};

struct T {
    u32 pad00;
    u32 f04;
};

struct SoundSys {
    u8            unk00[0xA4];
    struct Fader *fader;
    void         *ringtone;
};

struct SoundSys2 {
    u16 unk00[0x56];
    u16 slot[2];
    u16 owner[2];
    u32 unkB4;
};

struct S_02028B50 { u8 pad[0xac]; u16 lo[2]; u16 hi[2]; };

struct S_02028BDC { u8 pad[0xac]; u16 lo[2]; u16 hi[2]; u32 mask; };

struct EntryA {
    u32 f00;
    u16 f04;
};

struct EntryB {
    u32 f00;
    u16 f04[4];
};

struct EntryC {
    u32 f00 : 24;
};

struct Sys_02028D2C {
    u8  pad_00[0x20];
    u32 pending;   /* 0x20 */
};

typedef signed int     s32_1;

struct Cmd {
    u32 unk00;
    u32 unk04;
    u16 unk08;
    u16 unk0A;
};

struct Sys_02028D8C {
    u8         pad_00[0x28];
    struct Cmd queue[10];   /* 0x28 */
    u8         tail;        /* 0xa0 */
    u8         head;        /* 0xa1 */
};

extern u8 func_02028DCC(struct Sys *s, u32 target);
extern void func_02028E0C(struct Sys *s, struct Cmd *cmd);
extern void func_02029F4C(void *p);
extern void func_0202878C(struct Fader *s);
extern void func_02028794(struct Fader *s, u8 level, u16 frames);
extern void func_02029F54(void *p);
extern void func_02029F60(void *p);
extern int func_021D21C0(u32 id);
extern int func_021D21E0(u32 id);
extern int func_02006148(u32 a0);
extern void func_020061E4(u32 id);
extern void func_020061F0(u32 id, u32 who);
extern void func_020062BC(int i, u32 level);
extern void func_020061F8(int i);
extern void *func_02074324(int index);
extern u32 func_0207466C(u32 idx);
extern void *func_020743EC(int index);
extern struct EntryC *func_02074450(u32 id);
extern void func_020293D8(struct T *p);
extern void func_02005D28(void);
extern u32 func_02028FD0(struct SoundParam *obj, u32 kind);
extern void func_02028EAC(struct SoundParam2 *obj, struct Cmd *cmd);
extern void func_02028E80(struct Sys *s);
u32 func_020289B8(struct Sys *s);
u32 func_020289D4(struct Sys *s);
void func_020289F8(struct Sys *s, u32 a, u32 b, u16 c, u16 d);
void func_02028A14(struct T *p);
void func_02028A50(void *sys, void *res);
void func_02028A58(struct SoundSys *sys, u8 level, u16 frames);
void func_02028A64(struct SoundSys *sys);
void func_02028A70(struct SoundSys *sys);
void func_02028A7C(struct SoundSys2 *s, u32 id);
void func_02028ACC(struct SoundSys2 *s, u32 id, u32 who);
void func_02028B18(struct SoundSys2 *s, u32 id, u32 who);
void func_02028B50(u8 *p, int a0);
void func_02028BA0(u8 *o, u32 v);
void func_02028BDC(struct S_02028BDC *s, u32 mask);
int func_02028C30(u32 v);
u32 func_02028C50(int index);
int func_02028CB0(u32 v);
void func_02028CD4(u8 *p, u32 v);
void func_02028D2C(struct Sys_02028D2C *s, void *desc);
void func_02028D54(int a0);
void *func_02028D7C(void *obj);
struct Cmd *func_02028D8C(struct Sys_02028D8C *s);
int func_02028DB8(void *obj);
extern u32  g_020A7554[];
extern u32  g_020A7518[];
extern const u16 sTable_0209FDD0[];




/*
 * field_sound_system.c.  "Is the system busy": either the queue helper says so or the mode word is
 * non zero.  It is written as the negated conjunction rather than the
 * disjunction the semantics suggest, because the block the source puts inside
 * the `if` is the one emitted first and here that is the `return 0`
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/func_020289B8.c  *       --addr 0x020289B8 --thumb
 */
u32 func_020289B8(struct Sys *s)
{
    if (func_02028DB8(s) == 0 && s->unk1C == 0) {
        return 0;
    }
    return 1;
}




/*
 * field_sound_system.c.  "Can the system take another request": two independent rejections, each
 * with its own epilogue, which is what says they are two `if`s and not one
 * conjunction (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/func_020289D4.c  *       --addr 0x020289D4 --thumb
 */
u32 func_020289D4(struct Sys *s)
{
    if (s->unk1C == 4 && s->unk04 == 6) {
        return 0;
    }
    if (func_02028DCC(s, 4) != 0) {
        return 0;
    }
    return 1;
}




/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * field_sound_system.c.  The command enqueue every caller in the region goes through: it builds the
 * sixteen byte command record on its own stack and hands its address to the
 * queue.  The fifth argument arrives at [sp, #0x10], which is the pushed `lr`
 * plus the twelve bytes of the record.
 *
 * Why it is capped: the single relocation is the call to func_02028E0C, and a
 * scan of the image finds exactly one branch to 0x02028E0C, the one inside
 * this function.  The `label` class therefore has no witness outside the
 * compared range and no cut helps: the range cannot be made smaller than the
 * one function that holds the call.  It closes the day 0x02028E0C itself is
 * matched (it is in the packet that starts at 0x02028D7C, not in
 * pkt_0202878C), or the day a second caller appears.
 *
 * Wave 26: 0x02028E0C is now decompiled and byte-correct in
 * src/pending/func_02028E0C.c, but it is capped in turn, and permanently, by
 * the permission table at 0x0209FD90 that its own callee func_02028E48 reads
 * (src/pending/func_02028E48.c).  That word appears in exactly one literal
 * pool image-wide, inside func_02028E48 itself, so this chain cannot be closed
 * from inside field_sound_system.c.  A second caller is the only route left.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020289F8.c  *       --func func_020289F8 --addr 0x020289F8 --thumb
 */
void func_020289F8(struct Sys *s, u32 a, u32 b, u16 c, u16 d)
{
    struct SndCmd cmd;

    cmd.unk00 = a;
    cmd.unk04 = b;
    cmd.unk08 = c;
    cmd.unk0A = d;
    func_02028E0C(s, (struct Cmd *)(&cmd));
}




void func_02028A14(struct T *p)
{
    func_02028D54((int)p);
    ((void (*)(struct T *))g_020A7554[p->f04])(p);
    ((void (*)(struct T *))g_020A7518[p->f04])(p);
    func_02029F4C(((struct Obj11294 *)p)->fA8);
    func_0202878C(((struct Obj11294 *)p)->fA4);
}




/*
 * Four forwarding thunks in field_sound_system.c, each a pool word and a `bx`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  The last three first
 * chase a sub-object pointer out of the sound system object: the volume fader
 * at +0xA4 that src/matched/unit_0202878C.c drives, and the ringtone handle at
 * +0xA8.  Both offsets are past the Thumb `ldr` immediate's reach of 124 and
 * so cost an `adds r0, #0xa4` first, which is an encoding artefact and not a
 * second pointer
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).
 *
 * UNLABELLED FOLLOWERS: none of these four saves `lr`, so `disasm.py` labels
 * none of them and `layout/function_starts.txt` has no seed for 0x02028A50,
 * 0x02028A64 or 0x02028A70 (it has one for 0x02028A58, sized 8 rather than
 * 12).  The witness for all four is this unit reproducing 0x02028A50..0x02028A7C
 * byte for byte, four sections of 8, 12, 12 and 12 bytes with no padding
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * ARITY: a thunk that moves no argument register says nothing about how many
 * arguments it forwards
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 * func_02028A58 is written with the three parameters func_02028794 takes,
 * because src/matched/unit_0202878C.c fixes that signature; the other three
 * are written with one argument each, which is the conservative reading and
 * compiles to the same bytes as any other arity.
 *
 * func_02028A50 is why this file exists as its own unit: it is the only caller
 * of func_02028D2C reachable from src/matched/unit_020298E0.c, whose third
 * state hands a resource off through it, and that file has no other witness
 * for 0x02028A50.
 *
 * Wave 26 closed it.  All four pool words are the only reference in the image
 * to their target, so the `label` class sees nothing and no cut helps; the way
 * through was to decompile the three targets that live outside this packet.
 * func_02028D2C is now src/matched/func_02028D2C.c (pkt_02028B50),
 * func_02029F54 and func_02029F60 are src/matched/unit_02029F54.c and
 * src/matched/unit_02029F60.c (pkt_02029F4C), and all three resolve `matched`;
 * func_02028794 resolves `matched` off src/matched/unit_0202878C.c.  That also
 * lifts the cap this file placed on src/pending/unit_020298E0.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02028A50.c \
 *       --addr 0x02028A50 --thumb
 */
void func_02028A50(void *sys, void *res)
{
    func_02028D2C(sys, res);
}




/*
 * Four forwarding thunks in field_sound_system.c, each a pool word and a `bx`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  The last three first
 * chase a sub-object pointer out of the sound system object: the volume fader
 * at +0xA4 that src/matched/unit_0202878C.c drives, and the ringtone handle at
 * +0xA8.  Both offsets are past the Thumb `ldr` immediate's reach of 124 and
 * so cost an `adds r0, #0xa4` first, which is an encoding artefact and not a
 * second pointer
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).
 *
 * UNLABELLED FOLLOWERS: none of these four saves `lr`, so `disasm.py` labels
 * none of them and `layout/function_starts.txt` has no seed for 0x02028A50,
 * 0x02028A64 or 0x02028A70 (it has one for 0x02028A58, sized 8 rather than
 * 12).  The witness for all four is this unit reproducing 0x02028A50..0x02028A7C
 * byte for byte, four sections of 8, 12, 12 and 12 bytes with no padding
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * ARITY: a thunk that moves no argument register says nothing about how many
 * arguments it forwards
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 * func_02028A58 is written with the three parameters func_02028794 takes,
 * because src/matched/unit_0202878C.c fixes that signature; the other three
 * are written with one argument each, which is the conservative reading and
 * compiles to the same bytes as any other arity.
 *
 * func_02028A50 is why this file exists as its own unit: it is the only caller
 * of func_02028D2C reachable from src/matched/unit_020298E0.c, whose third
 * state hands a resource off through it, and that file has no other witness
 * for 0x02028A50.
 *
 * Wave 26 closed it.  All four pool words are the only reference in the image
 * to their target, so the `label` class sees nothing and no cut helps; the way
 * through was to decompile the three targets that live outside this packet.
 * func_02028D2C is now src/matched/func_02028D2C.c (pkt_02028B50),
 * func_02029F54 and func_02029F60 are src/matched/unit_02029F54.c and
 * src/matched/unit_02029F60.c (pkt_02029F4C), and all three resolve `matched`;
 * func_02028794 resolves `matched` off src/matched/unit_0202878C.c.  That also
 * lifts the cap this file placed on src/pending/unit_020298E0.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02028A50.c \
 *       --addr 0x02028A50 --thumb
 */
void func_02028A58(struct SoundSys *sys, u8 level, u16 frames)
{
    func_02028794(sys->fader, level, frames);
}



/*
 * Four forwarding thunks in field_sound_system.c, each a pool word and a `bx`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  The last three first
 * chase a sub-object pointer out of the sound system object: the volume fader
 * at +0xA4 that src/matched/unit_0202878C.c drives, and the ringtone handle at
 * +0xA8.  Both offsets are past the Thumb `ldr` immediate's reach of 124 and
 * so cost an `adds r0, #0xa4` first, which is an encoding artefact and not a
 * second pointer
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).
 *
 * UNLABELLED FOLLOWERS: none of these four saves `lr`, so `disasm.py` labels
 * none of them and `layout/function_starts.txt` has no seed for 0x02028A50,
 * 0x02028A64 or 0x02028A70 (it has one for 0x02028A58, sized 8 rather than
 * 12).  The witness for all four is this unit reproducing 0x02028A50..0x02028A7C
 * byte for byte, four sections of 8, 12, 12 and 12 bytes with no padding
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * ARITY: a thunk that moves no argument register says nothing about how many
 * arguments it forwards
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 * func_02028A58 is written with the three parameters func_02028794 takes,
 * because src/matched/unit_0202878C.c fixes that signature; the other three
 * are written with one argument each, which is the conservative reading and
 * compiles to the same bytes as any other arity.
 *
 * func_02028A50 is why this file exists as its own unit: it is the only caller
 * of func_02028D2C reachable from src/matched/unit_020298E0.c, whose third
 * state hands a resource off through it, and that file has no other witness
 * for 0x02028A50.
 *
 * Wave 26 closed it.  All four pool words are the only reference in the image
 * to their target, so the `label` class sees nothing and no cut helps; the way
 * through was to decompile the three targets that live outside this packet.
 * func_02028D2C is now src/matched/func_02028D2C.c (pkt_02028B50),
 * func_02029F54 and func_02029F60 are src/matched/unit_02029F54.c and
 * src/matched/unit_02029F60.c (pkt_02029F4C), and all three resolve `matched`;
 * func_02028794 resolves `matched` off src/matched/unit_0202878C.c.  That also
 * lifts the cap this file placed on src/pending/unit_020298E0.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02028A50.c \
 *       --addr 0x02028A50 --thumb
 */
void func_02028A64(struct SoundSys *sys)
{
    func_02029F54(sys->ringtone);
}



/*
 * Four forwarding thunks in field_sound_system.c, each a pool word and a `bx`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  The last three first
 * chase a sub-object pointer out of the sound system object: the volume fader
 * at +0xA4 that src/matched/unit_0202878C.c drives, and the ringtone handle at
 * +0xA8.  Both offsets are past the Thumb `ldr` immediate's reach of 124 and
 * so cost an `adds r0, #0xa4` first, which is an encoding artefact and not a
 * second pointer
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).
 *
 * UNLABELLED FOLLOWERS: none of these four saves `lr`, so `disasm.py` labels
 * none of them and `layout/function_starts.txt` has no seed for 0x02028A50,
 * 0x02028A64 or 0x02028A70 (it has one for 0x02028A58, sized 8 rather than
 * 12).  The witness for all four is this unit reproducing 0x02028A50..0x02028A7C
 * byte for byte, four sections of 8, 12, 12 and 12 bytes with no padding
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * ARITY: a thunk that moves no argument register says nothing about how many
 * arguments it forwards
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 * func_02028A58 is written with the three parameters func_02028794 takes,
 * because src/matched/unit_0202878C.c fixes that signature; the other three
 * are written with one argument each, which is the conservative reading and
 * compiles to the same bytes as any other arity.
 *
 * func_02028A50 is why this file exists as its own unit: it is the only caller
 * of func_02028D2C reachable from src/matched/unit_020298E0.c, whose third
 * state hands a resource off through it, and that file has no other witness
 * for 0x02028A50.
 *
 * Wave 26 closed it.  All four pool words are the only reference in the image
 * to their target, so the `label` class sees nothing and no cut helps; the way
 * through was to decompile the three targets that live outside this packet.
 * func_02028D2C is now src/matched/func_02028D2C.c (pkt_02028B50),
 * func_02029F54 and func_02029F60 are src/matched/unit_02029F54.c and
 * src/matched/unit_02029F60.c (pkt_02029F4C), and all three resolve `matched`;
 * func_02028794 resolves `matched` off src/matched/unit_0202878C.c.  That also
 * lifts the cap this file placed on src/pending/unit_020298E0.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02028A50.c \
 *       --addr 0x02028A50 --thumb
 */
void func_02028A70(struct SoundSys *sys)
{
    func_02029F60(sys->ringtone);
}




/*
 * field_sound_system.c: claim a sequence slot for a caller that gives no owner id, marking the
 * slot's owner 0xFFFF
 *
 * The two slot tables at +0xAC and +0xB0 are two halfwords each; the loop in
 * func_02028B18 is what fixes the count at two.  Both are past the Thumb
 * halfword immediate's reach of 62, so each access recomputes
 * `base + index*2` and then adds 0xAC or 0xB0
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).
 *
 * The overlay callee 0x021D21C0 is attested through the label class
 * with the ov021 region hint on the symbols line.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/func_02028A7C.c --addr 0x02028A7C --thumb
 */
void func_02028A7C(struct SoundSys2 *s, u32 id)
{
    u32 n;

    if (func_021D21C0(id) == 0) {
        func_020061E4(id);
        return;
    }
    if (func_021D21E0(id) != 0) {
        n = func_02006148(id) - 1;
        s->slot[n] = id;
        s->owner[n] = 0xFFFF;
    }
    if (s->unkB4 == 0) {
        func_020061E4(id);
    }
}




/*
 * field_sound_system.c: the same claim with an owner id supplied by the caller
 *
 * The two slot tables at +0xAC and +0xB0 are two halfwords each; the loop in
 * func_02028B18 is what fixes the count at two.  Both are past the Thumb
 * halfword immediate's reach of 62, so each access recomputes
 * `base + index*2` and then adds 0xAC or 0xB0
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).
 *
 * The overlay callee 0x021D21C0 is attested through the label class
 * with the ov021 region hint on the symbols line.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/func_02028ACC.c --addr 0x02028ACC --thumb
 */
void func_02028ACC(struct SoundSys2 *s, u32 id, u32 who)
{
    u32 n;

    if (func_021D21C0(id) == 0) {
        func_020061E4(id);
        return;
    }
    if (func_021D21E0(id) != 0) {
        n = func_02006148(id) - 1;
        s->slot[n] = id;
        s->owner[n] = who;
    }
    if (s->unkB4 == 0) {
        func_020061F0(id, who);
    }
}




/*
 * field_sound_system.c: hand an already claimed slot to a new owner
 *
 * The two slot tables at +0xAC and +0xB0 are two halfwords each; the loop in
 * func_02028B18 is what fixes the count at two.  Both are past the Thumb
 * halfword immediate's reach of 62, so each access recomputes
 * `base + index*2` and then adds 0xAC or 0xB0
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).
 *
 * The overlay callee 0x021D21C0 is attested through the label class
 * with the ov021 region hint on the symbols line.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/func_02028B18.c --addr 0x02028B18 --thumb
 */
void func_02028B18(struct SoundSys2 *s, u32 id, u32 who)
{
    s32_0 i;

    if (func_021D21C0(id) != 0) {
        for (i = 0; i < 2; i++) {
            if (s->slot[i] == id) {
                func_020062BC(i + 1, who);
                s->owner[i] = who;
                return;
            }
        }
    }
}



/*
 * Both halfword cells the caller clears sit in ONE struct, four bytes apart
 * (0xac and 0xb0), and the same index reaches both.  Spelled as two
 * independent `u16 *` locals the compiler recomputes the second address from
 * `idx + 1` and the frame loses two bytes; as two adjacent u16[2] fields of
 * one struct both accesses share the scaled index register and the function
 * is EXACT.
 */
void func_02028B50(u8 *p, int a0)
{
    u32 idx;
    struct S_02028B50 *s = (struct S_02028B50 *)p;
    idx = func_02006148(a0);
    if (func_021D21C0(a0) == 0) {
        func_020061F8(idx);
        return;
    }
    if (func_021D21E0(a0) != 0) {
        if (a0 == s->lo[idx - 1]) {
            s->lo[idx - 1] = 0xffff;
            s->hi[idx - 1] = 0xffff;
        }
    }
    func_020061F8(idx);
}




void func_02028BA0(u8 *o, u32 v)
{
    int i;

    if (((struct Obj00164 *)o)->fB4 == 0) {
        for (i = 0; i < 2; i++) {
            if (*(u16 *)(o + 0xac + i * 2) != 0xffff) {
                func_020061F8(i + 1);
            }
        }
    }
    ((struct Obj00164 *)o)->fB4 |= v;
}




/*
 * field_sound_system.c: drop the bits of mask from the pending set at
 * +0xB4 and, when the set empties, replay the two stored sounds.  The
 * 4-byte residue of docs/notes/pkt_02028BDC.c.txt ("a dead-after-use scaled
 * index") was the callee arity: both callees take the sound id (and
 * func_020061F0 the second id), so the index is not dead; the image passes
 * the loaded halfwords on in r0/r1.
 */
void func_02028BDC(struct S_02028BDC *s, u32 mask)
{
    int i;

    if ((s->mask & mask) == 0)
        return;

    s->mask = s->mask & ~mask;

    if (s->mask != 0)
        return;

    for (i = 0; i < 2; i++) {
        if (s->lo[i] != 0xffff) {
            if (s->hi[i] == 0xffff)
                func_020061E4(s->lo[i]);
            else
                func_020061F0(s->lo[i], s->hi[i]);
        }
    }
}




/*
 * Blocked at MATCH: every concrete byte is identical; the ABS32 at +0x1C
 * naming the 0x26-entry u16 table at 0x0209FDD0 has no witness outside
 * 02028C30..02028C50.  The only pool word in the image that names that
 * address is 0x02028C4C, which is inside this function's own extent, and
 * the table fails `string` (no printable run) and `data_table` (not a run
 * of in-region pointers).  This is the wall already recorded in
 * docs/notes/lane2_band_0_64_pass3.c.txt; it cannot close from C.
 * Consequence: src/pending/func_02028CB0.c stays MATCH* on the 02028C30
 * blocker -- only func_02028C50 of its two sites is closable.
 *
 * 2026-09-21, FAMILY wave.  Re-verified in a fresh process: still MATCH,
 * every concrete byte identical.  Evidence worked to exhaustion:
 *   - `--suggest-split` reports "witnesses image wide: 1, of them inside
 *     this range: 1"; a single-function file has nothing to cut against.
 *   - No sibling in field_sound_system.c (0x02028844..0x02029EB4) references
 *     the object: the only other listing hits are the rodata DEFINITION in
 *     asm/arm9/src/030_*.s, which is a referent, not a referrer.
 *   - sole-ref/data was probed directly.  in_data_section = True and the
 *     layout/data_objects.txt row IS an object start when the range is
 *     ignored, but `_map_attests(addr, lo, hi)` = False once the range is
 *     applied, because that row's sole referrer is this function's own pool
 *     word.  This is the documented "a lone reference never contributes its
 *     own start" rule firing correctly, not a tooling gap.
 * Declarations cross-checked against docs/families/field_sound_system.h.
 */
int func_02028C30(u32 v)
{
    u32 i;

    for (i = 0; i < 0x26; i++) {
        if (v == sTable_0209FDD0[i]) {
            return 1;
        }
    }
    return 0;
}




u32 func_02028C50(int index)
{
    struct EntryA *a;
    int i;
    struct EntryB *b;

    a = func_02074324(index);
    if (func_0207466C(a->f00) == 0) {
        return 0;
    }

    b = func_020743EC(a->f04);
    if (func_0207466C(b->f00) == 0) {
        return 0;
    }

    for (i = 0; i < 4; i++) {
        if (b->f04[i] != 0xffff) {
            if (func_0207466C(func_02074450(b->f04[i])->f00) == 0) {
                return 0;
            }
        }
    }

    return 1;
}




int func_02028CB0(u32 v)
{
    if (func_02028C30(v) == 0) {
        return 0;
    }
    if (func_02028C50(v) != 0) {
        return 1;
    }
    return 0;
}




void func_02028CD4(u8 *p, u32 v)
{
    int i;

    ((struct Obj00164 *)p)->f0 = v;
    ((struct Obj00164 *)p)->f4 = 0;
    ((struct Obj00164 *)p)->f1C = 0;
    ((struct Obj00164 *)p)->f8 = 0;
    ((struct Obj00164 *)p)->fC = 0;
    ((struct Obj00164 *)p)->f10 = 0;
    ((struct Obj00164 *)p)->f14 = 0;
    ((struct Obj00164 *)p)->f18 = 0;
    ((struct Obj00164 *)p)->f1A = 0;
    *(u32 *)&((struct Obj00164 *)p)->f20 = 0;
    ((struct Obj00164 *)p)->f24 = 0;

    for (i = 0; i < 10; i++)
        *(u32 *)(p + 0x28 + i * 12) = 0;

    ((struct Obj00164 *)p)->fA0 = 0;
    ((struct Obj00164 *)p)->fA1 = 0;

    for (i = 0; i < 2; i++)
        *(u16 *)(p + 0xac + i * 2) = 0xffff;

    ((struct Obj00164 *)p)->fB4 = 0;
}



/*
 * field_sound_system.c: drain and re-arm.  Runs func_020293D8 until the
 * pending counter at +0x20 falls to zero, closes the frame with
 * func_02005D28, and then re-initialises the system from the descriptor the
 * caller passed, through the same func_02028CD4 the constructor uses.
 *
 * Nothing branches to this function anywhere in the image; its only reference
 * is the pool word of the forwarder at 0x02028A50, so the `label` class
 * cannot see it and src/matched/func_02028A50.c is EXACT only because this
 * file is a `matched` witness for it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02028D2C.c \
 *       --func func_02028D2C --addr 0x02028D2C --cc 1.1p1 --thumb
 */
void func_02028D2C(struct Sys_02028D2C *s, void *desc)
{
    while (s->pending != 0) {
        func_020293D8((struct T *)s);
    }
    func_02005D28();
    func_02028CD4((u8 *)s, (u32)desc);
}


/*
 * closed:   blocker func_02028D54.c is now a manifest entry (matched class)
 */
void func_02028D54(int a0)
{
    int *p = func_02028D7C((void *)a0);
    if (func_02028FD0((struct SoundParam *)a0, *p)) {
        func_02028EAC((struct SoundParam2 *)a0, (struct Cmd *)((int)p));
        func_02028E80((struct Sys *)a0);
    }
}



void *func_02028D7C(void *obj)
{
    u8 idx = *((u8 *)obj + 0xa0);
    return (u8 *)obj + 0x28 + idx * 12;
}



/*
 * field_sound_system.c: pick the command slot the caller should look at.
 * While func_02028DB8 says the ring is idle that is the read cursor at +0xA0;
 * otherwise it is the slot just before the write cursor at +0xA1, which is
 * `(head + 9) % 10` rather than `head - 1` because the subtraction has to wrap
 * (the modulo is a real call to the runtime's signed divide helper, which
 * returns the remainder in r1 and so feeds the index computation directly).
 *
 * Both arms fall into one address computation, so the index is assigned in
 * each arm and the `&s->queue[i]` is written once after the `if`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/func_02028D8C.c \
 *       --addr 0x02028D8C --thumb
 */
struct Cmd *func_02028D8C(struct Sys_02028D8C *s)
{
    s32_1 i;

    if (func_02028DB8(s) == 0) {
        i = s->tail;
    } else {
        i = (s->head + 9) % 10;
    }
    return &s->queue[i];
}



int func_02028DB8(void *obj)
{
    return *(u32 *)func_02028D7C(obj) != 0;
}
