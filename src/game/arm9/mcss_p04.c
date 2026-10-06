/*
 * file:     mcss_p04.c
 * unit:     yes
 * function: func_02015D88, func_02015D94, func_02015DB0, func_02015DC0, func_02015DD4, func_02015DF8, func_02015E04, func_02015E28, func_02015E4C, func_02015E70, func_02015E94, func_02015EA0, func_02015EB0, func_02015EC4, func_02015EE8, func_02015EEC, func_02015EF4, func_02015EFC, func_02015F04, func_02015F0C, func_02015F14, func_02015F1C, func_02015F24, func_02015F2C, func_02015F40, func_02015F50, func_02015FAC, func_02015FBC, func_02015FD4, func_02015FF0, func_0201600C, func_02016020, func_02016024, func_02016028, func_02016068, sub_02016078
 * address:  0x02015D88
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
 *   func_02063000  0x02063000  arm
 *   func_02064D70  0x02064D70  arm
 *   func_020627D8  0x020627D8  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02016984  0x02016984  thumb
 *   func_0206469C  0x0206469C  arm
 *   func_02016BA0  0x02016BA0  thumb
 *   func_020163C4  0x020163C4  thumb
 */
#include "../../matched/include/Obj15660.h"
#include "../../matched/include/Obj08771.h"
#include "../../matched/include/Obj15661.h"
#include "../../matched/include/Obj15662.h"
#include "../../matched/include/Obj15663.h"
#include "../../matched/include/Obj15664.h"
#include "../../matched/include/Obj15665.h"
#include "../../matched/include/Obj15667.h"
#include "../../matched/include/Obj15669.h"
#include "../../matched/include/Obj00933.h"
#include "../../matched/include/Obj11257.h"
#include "../../matched/include/Obj15670.h"
#include "../../matched/include/Obj02301.h"
#include "../../matched/include/Obj16729.h"

struct AnimBank;
struct AnimSequence;
struct Obj0206469C;
struct Ctx;
struct Src;
typedef unsigned short u16;

struct R_02015DD4 {
    unsigned int : 8;
    unsigned int f : 1;
};

typedef struct {
    char pad[0x140];
    unsigned int lo : 9;
    unsigned int b : 2;
    unsigned int hi : 21;
} R_02015DF8;

typedef unsigned int u32;

struct Reg02015Exx {
    unsigned int : 9;
    unsigned int f : 2;
};

struct R_02015E28 {
    unsigned int : 9;
    unsigned int f : 2;
};

struct Reg02015E4C {
    unsigned int : 9;
    unsigned int f : 2;
};

struct R {
    unsigned int : 9;
    unsigned int f : 2;
};

typedef struct {
    char pad[0x140];
    unsigned int lo : 11;
    unsigned int b : 1;
    unsigned int hi : 20;
} R;

typedef unsigned char u8;

typedef signed short s16;

typedef struct {
    char pad[0x30];
    u8 *p30;
} S;

typedef signed char   s8;

typedef signed int    s32;

struct McssFade {
    u8  pad[0x134];
    s8  f134;       /* +0x134  current value */
    s8  f135;       /* +0x135  target value  */
    u8  f136;
    u8  f137;
    s32 f138;       /* +0x138  step          */
    u32 f13c;
    u32 f140;       /* +0x140  flag word     */
};

typedef struct {
    char pad[0x140];
    unsigned int value : 8;
} Data_0;

struct Flags0201600C {
    u32   : 12;
    u32 f : 1;
};

typedef struct {
    char pad[0x140];
    unsigned int padbits : 24;
    unsigned int value : 4;
} Data_02016068;

struct Sub02016078Word {
    u32 low24 : 24;
    u32 mode  : 4;
    u32 hi4   : 4;
};

extern void func_02063000(int p0, int p1, int p2, int p3);
extern void func_02064D70(void *, void *, unsigned);
u8 func_02015FAC(Data_0 *p);
void func_02015FBC(char *p, int v);
void func_02015FD4(char *p, int v);
void func_02015FF0(char *p, int v);
int func_0201600C(void *p);
void func_02016020(void *p, u32 v);
extern struct AnimSequence *func_020627D8(struct AnimBank *bank, u32 idx);
extern u32 func_020307B0(void *p);
extern void func_02016984(char *a0, int a1);
extern void func_0206469C(struct Obj0206469C *o, void *bank);
void func_02016024(char *p, unsigned int v);
void sub_02016028(void *a, u32 flag);
u8 func_02016068(Data_02016068 *p);
extern void func_02016BA0(void *b);
extern void func_020163C4(struct Ctx *a0, u32 idx, const struct Src *a2);
void func_02015D88(char *p, u16 value);
void func_02015D94(char *p, int *src);
void func_02015DB0(void *p);
void func_02015DC0(void *p);
void func_02015DD4(void *p);
int func_02015DF8(R_02015DF8 *p);
void func_02015E04(void *p);
void func_02015E28(void *p);
void func_02015E4C(void *p);
void func_02015E70(void *p);
int func_02015E94(R *p);
void func_02015EA0(void *p);
void func_02015EB0(void *p);
void func_02015EC4(R *p);
void *func_02015EE8(void *p);
u16 func_02015EEC(char *p);
u8 func_02015EF4(char *p);
u8 func_02015EFC(char *p, u8 i);
u16 func_02015F04(void *p);
u16 func_02015F0C(void *p);
s16 func_02015F14(void *p);
s16 func_02015F1C(void *p);
u8 func_02015F24(S *s);
void sub_02015F2C(void *a, u32 arg1, u32 arg2);
void func_02015F40(char *p, unsigned flags, void *callback);
void sub_02016078(void *a, void *b, int mode);








/*
 * Unlabelled Thumb leaf in the ARM9 module. Stores a halfword at +0x17A.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015D88(char *p, u16 value)
{
    ((struct Obj15660 *)p)->f17A = value;
}









/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into +0x17C.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015D94(char *p, int *src)
{
    ((struct Obj08771 *)p)->f17C = src[0];
    ((struct Obj08771 *)p)->f180 = src[1];
    ((struct Obj08771 *)p)->f184 = src[2];
}









/*
 * Unlabelled Thumb leaf in the ARM9 module. Sets bit 8 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015DB0(void *p)
{
    ((struct Obj15661 *)p)->f140 |= 0x100u;
}









/*
 * Unlabelled Thumb leaf in the ARM9 module. Clears bit 8 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015DC0(void *p)
{
    ((struct Obj15662 *)p)->f140 &= ~0x100u;
}








/*
 * Unlabelled Thumb leaf in the ARM9 module. Toggles bit 8 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015DD4(void *p)
{
    ((struct R_02015DD4 *)((char *)p + 0x140))->f ^= 1;
}








/*
 * Unlabelled Thumb leaf in the ARM9 module. Reads the two-bit field at bits 9..10 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
int func_02015DF8(R_02015DF8 *p)
{
    return p->b;
}








/*
 * Unlabelled Thumb leaf in the ARM9 module. Compound-OR of the 2-bit
 * bitfield at bits 9..10 of the register at +0x140 with 1. The access is
 * non-volatile in the original: mwcc reads the word once and reinserts the
 * field without a reload (a `volatile` spelling forces a second `ldr` and
 * diverges). Pairs with func_02015E4C, which clears bit 9.
 *
 * Addresses are Black-image addresses.
 */
void func_02015E04(void *p)
{
    ((struct Reg02015Exx *)((char *)p + 0x140))->f |= 1;
}








/*
 * Unlabelled Thumb leaf in the ARM9 module. Sets bit 10 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015E28(void *p)
{
    ((struct R_02015E28 *)((char *)p + 0x140))->f |= 2;
}








/*
 * Unlabelled Thumb leaf in the ARM9 module. Compound-AND of the 2-bit
 * bitfield at bits 9..10 of the register at +0x140 with ~1 (clears bit 9).
 * Same non-volatile codegen lever as func_02015E04.
 *
 * Addresses are Black-image addresses.
 */
void func_02015E4C(void *p)
{
    ((struct Reg02015E4C *)((char *)p + 0x140))->f &= ~1u;
}







/*
 * Unlabelled Thumb leaf in the ARM9 module. Clears bit 10 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015E70(void *p)
{
    ((struct R *)((char *)p + 0x140))->f &= ~2u;
}







/*
 * Unlabelled Thumb leaf in the ARM9 module. Reads bit 11 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
int func_02015E94(R *p)
{
    return p->b;
}







/*
 * Unlabelled Thumb leaf in the ARM9 module. Sets bit 11 (0x800) of the
 * 32-bit register at +0x140. Pairs with func_02015EB0, which clears it.
 *
 * Addresses are Black-image addresses.
 */
void func_02015EA0(void *p)
{
    *(volatile u32 *)&((struct Obj15663 *)p)->f140 |= 0x800u;
}







/*
 * Unlabelled Thumb leaf in the ARM9 module (saves nothing, so disasm.py emits
 * it as a run of .word; the live bytes decode as Thumb). Clears bit 11
 * (0x800) of the 32-bit field at +0x140. This is one of the pair
 * func_02015EA0/func_02015EB0 that set and clear the same bit; it is called
 * from the ov118 event state machine at 0x021D7130 and from
 * func_021D6E04, and is an image-wide-only reference target (no func_ label),
 * so matching it supplies the `matched` witness those callers lack.
 *
 * Addresses are Black-image addresses.
 */
void func_02015EB0(void *p)
{
    *(volatile u32 *)&((struct Obj15664 *)p)->f140 &= 0xFFFFF7FFu;
}







/*
 * Unlabelled Thumb leaf in the ARM9 module. Toggles bit 11 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02015EC4(R *p)
{
    p->b = p->b ^ 1;
}






/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Returns the address
 * of the embedded renderer sub-object at +0x34.
 *
 * Addresses are Black-image addresses.
 */
void *func_02015EE8(void *p)
{
    return (char *)p + 0x34;
}







u16 func_02015EEC(char *p)
{
    return **(u16 * *)&((struct Obj15665 *)p)->f28;
}







u8 func_02015EF4(char *p)
{
    return **(u8 * *)&((struct Obj15667 *)p)->f30;
}







u8 func_02015EFC(char *p, u8 i)
{
    return (*(u8 * *)&((struct Obj15669 *)p)->f30 + i)[2];
}







/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Reads the u16 at
 * +4 of the table the word at +0x2C points to (`ldrh` proves unsigned).
 * Witness for the call from ov119 func_021E33FC at 0x021E3520.
 */
u16 func_02015F04(void *p)
{
    return (*(u16 **)((char *)p + 0x2C))[2];
}







/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Reads the u16 at
 * +6 of the table the word at +0x2C points to (`ldrh` proves unsigned).
 *
 * Addresses are Black-image addresses.
 */
u16 func_02015F0C(void *p)
{
    return (*(u16 **)((char *)p + 0x2C))[3];
}







/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Reads the s16 at
 * +8 of the table the word at +0x2C points to (`ldrsh` with a register
 * offset proves signed).
 *
 * Addresses are Black-image addresses.
 */
s16 func_02015F14(void *p)
{
    return (*(s16 **)((char *)p + 0x2C))[4];
}







/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Reads the s16 at
 * +0xA of the table the word at +0x2C points to; sibling of
 * func_02015F14.
 *
 * Addresses are Black-image addresses.
 */
s16 func_02015F1C(void *p)
{
    return (*(s16 **)((char *)p + 0x2C))[5];
}







/*
 * Unlabelled Thumb leaf in the ARM9 module. Reads byte 1 of the record behind the pointer at +0x30.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
u8 func_02015F24(S *s)
{
    return s->p30[1];
}







/*
 * A pure forwarder: tail-calls func_02063000 on a member 0x34 bytes into
 * the object, with a fixed 1 as the second argument.
 *
 * EXACT* because the 18 compiled bytes fall far short of the disasm.py
 * extent (252 bytes): the packet's next several functions carry no
 * register-saving prologue and disasm.py's extent runs to the following
 * labelled function; they are not matched here.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02015F2C.c \
 *       --func sub_02015F2C --addr 0x02015F2C --cc 1.1p1
 */
void sub_02015F2C(void *a, u32 arg1, u32 arg2)
{
    func_02063000((int)((char *)a + 0x34), 1, arg1, arg2);
}







void func_02015F40(char *p, unsigned flags, void *callback)
{
    func_02064D70(p + 0x68, callback, flags);
}







/*
 * Unlabelled Thumb function in the ARM9 module (mcss.c). Starts the
 * +0x134 fade: sets bit 12 of the +0x140 flag word, stores the current
 * and target bytes (+0x134, +0x135), the fifth argument at +0x13C, clears
 * +0x136, splits the signed step into +0x137 and the s32 step at +0x138
 * (1 - step when negative), and negates the step when the current value
 * is above the target (`cmp r1, r2 / bls`, so both are unsigned bytes).
 *
 * The step is stored as a field in each arm and the negation re-reads the
 * field (the original reloads +0x138 with a fresh `0x4e << 2` base).
 * Written through raw char offsets with the step in a local, mwcc forwards
 * the stored value into the `muls` and colours the 0x140 base into r5;
 * the struct spelling below is byte-exact. `* 0xFFFFFFFF` rather than
 * `-x` is what emits the `mvns`/`muls` pair.
 *
 * Addresses are Black-image addresses.
 */
void func_02015F50(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e)
{
    w->f140 |= 0x1000;
    w->f134 = cur;
    w->f135 = target;
    w->f13c = e;
    w->f136 = 0;
    if (step < 0) {
        w->f137 = 0;
        w->f138 = -(step - 1);
    } else {
        w->f137 = step;
        w->f138 = 1;
    }
    if (cur > target) {
        w->f138 *= 0xFFFFFFFF;
    }
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Reads the low byte of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
u8 func_02015FAC(Data_0 *p)
{
    return p->value;
}


/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness (ov117 func_021D49F4): the low byte of the word at +0x140.
 * Addresses are Black-image addresses.
 */
void func_02015FBC(char *p, int v)
{
    ((struct Obj00933 *)p)->f140 = (((struct Obj00933 *)p)->f140 & ~0xFF) | (unsigned char)v;
}



/*
 * Unlabelled leaf accessor, the follower of func_02015FBC: a 9-bit field at
 * bit 14 of the word at +0x140. Labelled so that func_02015FBC's extent ends
 * at its own bx lr. Addresses are Black-image addresses.
 */
void func_02015FD4(char *p, int v)
{
    ((struct Obj11257 *)p)->f140 = (((struct Obj11257 *)p)->f140 & 0xFF803FFF) | ((v & 0x1FF) << 14);
}



/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 */
void func_02015FF0(char *p, int v)
{
    ((struct Obj00933 *)p)->f140 = (((struct Obj00933 *)p)->f140 & 0xFF7FFFFF) | ((v & 1) << 23);
}



/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Tests bit 12 of the
 * flag word at +0x140 (the bit func_02015F50 sets). A one-bit bitfield
 * keeps the original's lsls/lsrs pair; a mask would fold to `ands`.
 *
 * Addresses are Black-image addresses.
 */
int func_0201600C(void *p)
{
    if (((struct Flags0201600C *)((char *)p + 0x140))->f) {
        return 1;
    }
    return 0;
}



/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Stores its second
 * argument into the word at +0x30. Seeded from overlay call sites.
 *
 * Addresses are Black-image addresses.
 */
void func_02016020(void *p, u32 v)
{
    ((struct Obj15670 *)p)->f30 = v;
}


void func_02016024(char *p, unsigned int v)
{
    *(unsigned int *)(p + 52) = v;
}



/*
 * promoted: from src/pending on 2026-09-19, no C change: its blocker is filed,
 *           every relocation site resolves and match.py one reports EXACT*.
 *
 * Reconfigures the object: derives a value from func_020627D8 on field
 * +0x28 and a caller-supplied flag truncated to 16 bits (the explicit
 * lsls/lsrs #0x10 pair in the original is exactly that narrowing cast in
 * the callee, not something the caller is trusted to have done), releases
 * the handle at +0x98 through func_020307B0 if one is set, calls
 * func_02016984(a, 1), passes the derived value into func_0206469C on the
 * member at +0x34, then clears bit 0 of the word at +0x144.
 *
 * Every concrete byte matches; func_02016984 (0x02016984, later in this
 * same packet, not yet matched) is called from exactly this one site in
 * the whole ROM, so that relocation stays unresolved under the honesty
 * rule.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02016028.c \
 *       --func sub_02016028 --addr 0x02016028 --cc 1.1p1
 *
 * The `matched` class does not reach it: func_02016984 is not matched, so
 * no EXACT entry covers that address. Closes to EXACT the day it is
 * matched, or gets a second caller elsewhere in the image.
 */
void sub_02016028(void *a, u32 flag)
{
    u8 *p = (u8 *)a;
    u32 value = (u32)func_020627D8((struct AnimBank *)(((struct Obj02301 *)p)->f28), (u16)flag);

    if (((struct Obj02301 *)p)->f98 != 0) {
        func_020307B0((void *)(((struct Obj02301 *)p)->f98));
    }

    func_02016984(a, 1);
    func_0206469C((struct Obj0206469C *)(p + 0x34), (void *)value);
    ((struct Obj02301 *)p)->f144 &= ~1u;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module. Reads bits 24..27 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
u8 func_02016068(Data_02016068 *p)
{
    return p->value;
}


/*
 * Updates a packed 4-bit mode field at b+0x140 (bits 24-27 of that word;
 * see docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md) if
 * the caller's requested mode (clamped to 15) differs from the current
 * one, then reinitialises through func_02016BA0 and forwards a nested
 * word and struct pointer into func_020163C4. The bitfield pointer is
 * recomputed fresh for the store rather than kept in a local across the
 * clamp branch: the original re-issues the same "5 << 6" multiply instead
 * of reusing the register from the read, the same shape as
 * docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md.
 *
 * EXACT* because the 72 compiled bytes fall short of the disasm.py extent
 * (92 bytes): the extent runs into the next function's own literal pool,
 * not a byte difference.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02016078.c \
 *       --func sub_02016078 --addr 0x02016078 --cc 1.1p1
 */
void sub_02016078(void *a, void *b, int mode)
{
    u8 *pb = (u8 *)b;

    if (((struct Sub02016078Word *)(pb + 0x140))->mode != (u32)mode) {
        if (mode > 15) {
            mode = 15;
        }
        ((struct Sub02016078Word *)(pb + 0x140))->mode = mode;

        func_02016BA0(b);
        func_020163C4(a, ((struct Obj16729 *)pb)->f148, (const struct Src *)(pb + 0x150));
    }
}
