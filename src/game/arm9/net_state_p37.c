/*
 * file:     net_state_p37.c
 * unit:     yes
 * function: func_0203B2FC, func_0203B344, func_0203B390
 * address:  0x0203B2FC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203D788  0x0203D788  arm
 *   func_02037A6C  0x02037A6C  arm
 *   func_02037928  0x02037928  arm
 *   func_0203AD80  0x0203AD80  arm
 *   func_0203B01C  0x0203B01C  arm
 *   g_021469DC     0x021469DC  data
 *   str_0203B950   0x0203B950  data
 */
typedef unsigned int u32;

typedef unsigned long long u64;

typedef unsigned char  u8;

typedef unsigned short u16;

struct Vt {
    u8  pad_00[0x78];
    u32 (*f78)(void);
};

struct Obj {
    u8         pad_00[0x340];
    struct Vt *f340;
};

struct Slot {
    u8  pad_00[0x53];
    u8  f53;
    u8  pad_54[2];
    u8  f56;
    u8  f57;
};

extern void func_0203B01C(void);
extern void *func_0203D788(void);
extern u32   func_02037A6C(u32 a, u32 b, u32 c, u32 d);
extern u32 func_02037928(u32 a0, u16 a1);
extern void  func_0203AD80(u32 ctx, void *tag, u32 val, u32 line);
u32 func_0203B2FC(char *p);
u32 func_0203B344(char *p);
extern u32  g_021469DC;
extern char str_0203B950[];


u32 func_0203B2FC(char *p)
{
    u32 hi;
    u64 acc = *(u64 *)(p + 0x14) * *(u64 *)(p + 0xc) + *(u64 *)(p + 0x1c);
    *(u64 *)(p + 0xc) = acc;
    hi = (u32)(acc >> 32);
    return (u32)(((u64)hi * 40) >> 32) + 0x3c;
}


u32 func_0203B344(char *p)
{
    u32 hi;
    u64 acc = *(u64 *)(p + 0x14) * *(u64 *)(p + 0xc) + *(u64 *)(p + 0x1c);
    *(u64 *)(p + 0xc) = acc;
    hi = (u32)(acc >> 32);
    return (u32)(((u64)hi * 32) >> 32) + 0xb4;
}


/*
 * Closes the residue docs/notes/pkt_0203B390.c.txt recorded ("DIFF, one
 * instruction": `mov r0, #1` hoisted above the `beq` in the original but
 * left inside the alt block in every spelling that note tried).  The note
 * was looking at the wrong constant.  What the original hoists is not the
 * `1`, it is the 0x200 -- `mov r4, #0x200` at +0x24, before the compare
 * chain -- and r4 then serves FOUR uses: the length argument of
 * func_02037A6C, the second argument of func_02037928 on the alt path, and
 * the base of both line numbers (`add r3, r4, #0x45` = 0x245 and
 * `add r3, r4, #0x4a` = 0x24A).  Binding it to ONE local `u32 n = 0x200;`
 * declared before the guards gives it a live range that spans both arms,
 * which is what pins it in r4 and frees r0 for the literal `1` to be
 * materialised in the pre-branch block.  The note's experiment of making
 * `one` a local was the right technique applied to the wrong value.
 *
 * EXACT on the first compile with that change; no permuter search needed.
 */
void func_0203B390(struct Slot *p)
{
    struct Obj *q = (struct Obj *)func_0203D788();
    u32 n = 0x200;

    if (q->f340->f78() == 0)
        return;
    if (p->f53 == 0 || p->f56 == 1)
        goto alt;

    if (func_02037A6C(1, (u32)&p->f57, n, (u32)func_0203B01C) == 0)
        return;
    func_0203AD80(g_021469DC, str_0203B950, func_0203B2FC((char *)p), n + 0x45);
    return;

alt:
    if (func_02037928(1, n) == 0)
        return;
    func_0203AD80(g_021469DC, str_0203B950, func_0203B344((char *)p), n + 0x4a);
}
