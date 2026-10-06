/*
 * file:     field_sound_system_p04.c
 * unit:     yes
 * function: func_02028E48, func_02028E80, func_02028EAC
 * address:  0x02028E48
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
 *   func_02028D8C  0x02028D8C  thumb
 *   func_02028FD0  0x02028FD0  thumb
 *   g_0209FD90     0x0209FD90  data
 *   func_02028DB8  0x02028DB8  thumb
 *   _s32_div_f     0x0209C0A4  arm
 *   func_02028F18  0x02028F18  thumb
 *   func_02028F30  0x02028F30  thumb
 *   func_02028F48  0x02028F48  thumb
 *   func_02028F60  0x02028F60  thumb
 *   func_02028F7C  0x02028F7C  thumb
 *   func_02028F9C  0x02028F9C  thumb
 *   func_02028FB8  0x02028FB8  thumb
 */
struct SoundParam;
struct SoundParam2;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Cmd {
    u32 unk00;
    u32 unk04;
    u16 unk08;
    u16 unk0A;
};

struct Sys_02028E48 {
    u8  pad_00[0x1c];
    u32 unk1C;      /* 0x1c */
};

typedef signed int     s32;

struct Sys_02028E80 {
    u8         pad_00[0x28];
    struct Cmd queue[10];
    u8         tail;
    u8         head;
};

extern struct Cmd *func_02028D8C(struct Sys_02028E48 *s);
extern u32 func_02028FD0(struct SoundParam *obj, u32 kind);
extern int func_02028DB8(void *obj);
extern void func_02028F18(struct SoundParam2 *obj, u16 a1);
extern void func_02028F30(u8 *p, u32 a);
extern void func_02028F48(u8 *p, u32 a);
extern void func_02028F60(u8 *p, u32 a, u32 b);
extern void func_02028F7C(u8 *p, u32 a, u32 b, u32 c);
extern void func_02028F9C(u8 *p, u32 a, u32 b);
extern void func_02028FB8(u8 *p, u32 a);
extern u8 g_0209FD90[][8];


/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * Blocked at MATCH on one data address: all 56 concrete bytes are right and
 * func_02028D8C and func_02028FD0 both resolve, but the permission table at
 * 0x0209FD90 appears in exactly one literal pool image-wide, this function's
 * own at 0x02028E7C, so the `literal` class has no outside site.  The word at
 * 0x0209FD90 is zero, so nothing distinguishes the table's start from the run
 * of zeros before it either.  Closing this file would close
 * src/pending/func_02028E0C.c and src/pending/func_020289F8.c behind it.
 *
 * field_sound_system.c: decide whether a new command of class `kind` may be
 * accepted.  Two states are consulted in order, the class of the command the
 * ring is currently pointing at (func_02028D8C) and the class latched at
 * +0x1C; the first non-zero one indexes the 8-wide permission table at
 * 0x0209FD90 by (state, kind).  With neither set the decision falls through
 * to func_02028FD0.
 *
 * The table base is loaded from the pool separately in each arm: the two arms
 * are siblings, not a dominator and a dominated block, and mwccarm does not
 * share an address constant across them.
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/func_02028E48.c \
 *       --addr 0x02028E48 --thumb
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
u32 func_02028E48(struct Sys_02028E48 *s, u32 kind)
{
    u32 state;

    state = func_02028D8C(s)->unk00;
    if (state != 0) {
        return g_0209FD90[state][kind];
    }
    state = s->unk1C;
    if (state != 0) {
        return g_0209FD90[state][kind];
    }
    return func_02028FD0((struct SoundParam *)s, kind);
}


void func_02028E80(struct Sys_02028E80 *s)
{
    s32 tail = s->tail;

    if (func_02028DB8(s) != 0) {
        s->queue[tail].unk00 = 0;
        s->tail = (tail + 1) % 10;
    }
}


/*
 * Byte-correct, MATCH*-capped. NOT in the manifest; see src/pending/README.md.
 *
 * closed:   blocker func_02028D54.c is now a manifest entry (matched class)
 * Previously blocked at MATCH* on callees: func_02028F30 through func_02028FB8 reside in
 * unit_02028F18 (pkt_02028B50), but unit_02028F18's header only lists func_02028F18,
 * so the other internal functions have no external branch witness in the manifest.
 */
void func_02028EAC(struct SoundParam2 *obj, struct Cmd *cmd)
{
    switch (cmd->unk00) {
    case 1:
        func_02028F18(obj, cmd->unk0A);
        break;
    case 2:
        func_02028F30((u8 *)obj, cmd->unk08);
        break;
    case 3:
        func_02028F48((u8 *)obj, cmd->unk08);
        break;
    case 4:
        func_02028F60((u8 *)obj, cmd->unk08, cmd->unk0A);
        break;
    case 5:
        func_02028F7C((u8 *)obj, cmd->unk04, cmd->unk08, cmd->unk0A);
        break;
    case 6:
        func_02028F9C((u8 *)obj, cmd->unk04, cmd->unk08);
        break;
    case 7:
        func_02028FB8((u8 *)obj, (u16)cmd->unk04);
        break;
    default:
        break;
    }
}
