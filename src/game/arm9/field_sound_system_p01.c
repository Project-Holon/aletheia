/*
 * file:     field_sound_system_p01.c
 * unit:     yes
 * function: func_02028844, func_0202889C, func_020288C4, func_02028900, func_02028988
 * address:  0x02028844
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
 *   func_02030734  0x02030734  arm
 *   func_02028CD4  0x02028CD4  thumb
 *   func_02028760  0x02028760  thumb
 *   func_02029F14  0x02029F14  thumb
 *   func_02005D08  0x02005D08  thumb
 *   func_02028CB0  0x02028CB0  thumb
 *   g_020A7590     0x020A7590  data
 *   func_02028784  0x02028784  thumb
 *   func_02029F44  0x02029F44  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02028DCC  0x02028DCC  thumb
 *   _s32_div_f  0x0209C0A4  arm
 */
typedef unsigned char u8;

typedef unsigned int  u32;

struct Sys_02028844 {
    u8    pad_00[0xa4];
    void *unkA4;   /* 0xa4 */
    void *unkA8;   /* 0xa8 */
};

typedef unsigned short u16;

typedef int            s32_0202889C;

struct Sys_0202889C {
    u32 unk00;
    u32 unk04;
    u8  unk08[0x14];
    u32 unk1C;
    u32 unk20;
};

struct SoundSys {
    u8    unk00[0xA4];
    void *fader;
    void *ringtone;
};

typedef int            s32_020288C4;

struct Sys_020288C4 {
    u32 unk00;
    u32 unk04;
    u8  unk08[0x14];
    u32 unk1C;
    u32 unk20;
};

typedef signed int    s32_02028900;

typedef struct {
    u8   pad00[8];
    void *f08;
    void *f0c;
    void *f10;
    u8   pad14[0x20 - 0x14];
    s32_02028900  f20;
    s32_02028900  f24[1];
    u8   pad28[0xa0 - 0x28];
    u8   fa0;
    volatile u8 fa1;
} Obj;

typedef struct {
    s32_02028900 op;
    s32_02028900 a;
    s32_02028900 b;
} Ins;

typedef int            s32_02028988;

struct Sys_02028988 {
    u32 unk00;
    u32 unk04;
    u8  unk08[0x14];
    u32 unk1C;
    u32 unk20;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02028CD4(u8 *p, u32 v);
extern void *func_02028760(void *a, int v);
extern u32 *func_02029F14(u32 a0, u32 a1);
extern void  func_02005D08(void (*cb)(void));
extern int func_02028CB0(u32 v);
extern void func_02029F44(void *p);
extern void func_02028784(void *p);
extern u32 func_020307B0(void *p);
extern u8 func_02028DCC(struct Sys_020288C4 *s, u32 target);
extern s32_02028900 _s32_div_f(s32_02028900 a, s32_02028900 b);
struct Sys_02028844 *func_02028844(void *desc, u32 heap);
void *func_02028900(Obj *p);
extern const char g_020A7590[];


/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * Blocked at MATCH: all 88 concrete bytes are right, 3 of 7 relocations
 * resolve.  func_02028760, func_02029F14 and the callback pointer
 * func_02028CB0 have exactly one reference image-wide, this function's.  The
 * fourth blocker is the __FILE__ pointer: the string "field_sound_system.c"
 * at 0x020A7590 is preceded by a table of pointers rather than by another
 * string's terminator, so the `string` class cannot fix its start, exactly
 * the case docs/idioms/a-string-after-a-data-table-has-no-witness.md
 * describes.  That one caps the file at MATCH regardless of the C.
 *
 * The string does settle the translation unit's name: field_sound_system.c.
 *
 * field_sound_system.c: the constructor.  Allocates the 0xB8-byte system out
 * of the caller's heap through the debug allocator (the fourth and fifth
 * arguments are the __FILE__ pointer into the packed string area and the
 * literal line number, the line number being the pooled small constant that
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md warns
 * about reading as a symbol), initialises it from the caller's descriptor,
 * builds the two owned sub-objects at +0xA4 and +0xA8, and registers the
 * per-frame callback at func_02028CB0.
 *
 * +0xA4 is stored and then read back for the second construction rather than
 * kept live, which is the tell that the source spells the second argument
 * `s->unkA4` and not the value it just stored.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02028844.c \
 *       --func func_02028844 --addr 0x02028844 --cc 1.1p1 --thumb
 */
struct Sys_02028844 *func_02028844(void *desc, u32 heap)
{
    struct Sys_02028844 *s;

    s = func_02030734(heap, 0xb8, 1, g_020A7590, 331);
    func_02028CD4((u8 *)s, (u32)desc);
    s->unkA4 = func_02028760((void *)heap, 0);
    s->unkA8 = func_02029F14(heap, (u32)s->unkA4);
    func_02005D08((void (*)(void))func_02028CB0);
    return s;
}


/*
 * field_sound_system.c.  The destructor: it drops the frame callback, tears down the ringtone handle
 * at +0xA8 and the volume fader at +0xA4, and frees the object.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/func_0202889C.c  *       --addr 0x0202889C --thumb
 */
void func_0202889C(struct SoundSys *s)
{
    func_02005D08(0);
    func_02029F44(s->ringtone);
    func_02028784(s->fader);
    func_020307B0(s);
}


/*
 * field_sound_system.c.  The queue depth the callers poll: the recorded base count plus the pending
 * requests of kind 3, less those of kind 4, with two mode specific
 * corrections.  The mode word is read once and kept, which is what makes it a
 * named local rather than two reads
 * (docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/func_020288C4.c  *       --addr 0x020288C4 --thumb
 */
s32_020288C4 func_020288C4(struct Sys_020288C4 *s)
{
    s32_020288C4 n = s->unk20;
    u32 mode;

    n = n + func_02028DCC(s, 3);
    n = n - func_02028DCC(s, 4);
    mode = s->unk1C;
    if (mode == 3) {
        if (s->unk04 == 5 || s->unk04 - 0xB <= 1) {
            n++;
        }
    }
    if (mode == 4) {
        if (s->unk04 == 6) {
            n--;
        }
    }
    return n;
}


void *func_02028900(Obj *p)
{
    void *cur;
    s32_02028900 n;
    s32_02028900 i;
    s32_02028900 pc;
    Ins *ins;
    void *stack[1];

    cur = p->f08;
    if (p->f0c != 0) {
        cur = p->f0c;
    }
    if (p->f10 != 0) {
        cur = p->f10;
    }
    n = p->f20;
    pc = p->fa0;
    for (i = 0; i < n; i++) {
        stack[i] = (void *)p->f24[i];
    }
    while (pc != p->fa1) {
        ins = (Ins *)((char *)p + 0x28) + pc;
        if (ins->op == 3) {
            stack[n++] = cur;
        } else if (ins->op == 4) {
            n--;
            cur = stack[n];
        } else if ((unsigned)(ins->op - 5) <= 2) {
            cur = (void *)ins->a;
        }
        pc = (pc + 1) % 10;
    }
    return cur;
}


/*
 * field_sound_system.c.  A pure predicate over the system's mode word: nine accepted values written
 * as one disjunction so that all nine tests share the single `movs r0, #1`
 * exit (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md).
 * The source order of the nine is the order of the nine `cmp` instructions,
 * which is not sorted.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/func_02028988.c  *       --addr 0x02028988 --thumb
 */
u32 func_02028988(struct Sys_02028988 *s)
{
    u32 v = s->unk04;

    if (v == 4 || v == 3 || v == 6 || v == 7 || v == 5 || v == 8 || v == 10 ||
        v == 11 || v == 13) {
        return 1;
    }
    return 0;
}
