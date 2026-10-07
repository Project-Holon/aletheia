/*
 * file:     gfl_use_p04.c
 * unit:     yes
 * function: sub_0200545C, func_020055F8, func_0200560C, func_02005610, func_02005624, func_02005640, func_02005654, func_0200566C
 * address:  0x0200545C
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
 *   g_020AA194      0x020AA194  data
 *   s_gfl_use_c     0x020A7004  data
 *   d_0209D8A0      0x0209D8A0  data
 *   d_0209D8B0      0x0209D8B0  data
 *   d_020A6C58      0x020A6C58  data
 *   sub_02005768    0x02005768  thumb
 *   func_0202F768   0x0202F768  thumb
 *   func_0202F774   0x0202F774  thumb
 *   OS_IsRunOnTwl       0x02085D3C  arm
 *   OS_GetArenaHi       0x0208656C  arm
 *   OS_GetArenaLo       0x02086580  arm
 *   OS_InitAlloc        0x02086A50  arm
 *   OS_SetArenaLo       0x02086774  arm
 *   OS_CreateExtraHeap  0x02086B98  arm
 *   OS_AllocFromHeap    0x020868E0  arm
 *   OS_GetConsoleType   0x02085CBC  arm
 *   sub_020056D0    0x020056D0  thumb
 *   func_020057AC   0x020057AC  thumb
 *   sub_02005610_Sys  0x020AA194  data
 *   func_02030D28     0x02030D28  arm
 *   func_02030DA8     0x02030DA8  arm
 */
struct Ctx;
struct Node;
typedef unsigned char      u8;

typedef unsigned int       u32;

typedef unsigned long long u64;

struct GflHeaps {
    u64   seed;
    u64   mul;
    u64   add;
    void *unk18;
    void *unk1C;
    void *unk20;
    void *unk24;
};

struct GflSys {
    void *unk00;
    u32   unk04;
    void (*unk08)(void *);
    u32   unk0C;
    struct GflHeaps *heaps;
    void *unk14;
};

typedef signed int     s32;

struct Sub02005610Heaps {
    u32   unk00;
    u32   unk04;
    u32   unk08;
    u32   unk0C;
    u32   unk10;
    u32   unk14;
    void *unk18;
    void *unk1C;
    void *unk20;
    void *unk24;
};

struct Sub02005610Sys {
    void *unk00;
    u32   unk04;
    void (*unk08)(void *);
    u32   unk0C;
    struct Sub02005610Heaps *unk10;
    void *unk14;
};

extern u32   OS_IsRunOnTwl(void);
extern void *OS_GetArenaHi(u32 id);
extern void *OS_GetArenaLo(u32 id);
extern void *OS_InitAlloc(u32 id, void *lo, void *hi, u32 n);
extern void  OS_SetArenaLo(u32 id, void *lo);
extern u32   OS_CreateExtraHeap(u32 id);
extern void *OS_AllocFromHeap(u32 id, u32 heap, u32 size);
extern u32   OS_GetConsoleType(void);
extern void func_02030608(u32 a, u32 b, u32 c, u32 d);
extern void  func_02030BA4(u32 a);
extern void  func_0203064C(u32 a, u32 b, u32 c);
extern void  func_02030678(void *a, u32 b, u32 c);
extern void  func_0203EF5C(u32 a);
extern void func_02048CEC(u32 a, u32 b);
extern void func_02034E24(u32 heap, u8 mode);
extern void  func_02034978(void);
extern void func_020346EC(u32 a, u32 b, u32 c);
extern void func_0203499C(u32 heap, int n0, int n1, int n2);
extern void  func_0203129C(u32 a);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, unsigned short tag);
extern u32   func_02030CB0(u32 n);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void  sub_020056D0(void);
extern void  func_0204E5E8(u32 a);
extern void func_020316C8(u32 a0, u32 a1, u32 a2);
extern void  func_0204E130(u32 a);
extern void  func_0203F3B4(void);
extern void  func_020057AC(void);
extern void func_0204E6F4(s32 a);
extern void  sub_02005768(void);
extern void  func_0202F768(void);
extern void func_0202F774(u32 on);
extern void func_02034F5C(void);
extern int func_0200F2D4(void);
extern int func_020312B4(void);
extern void func_0203F3F0(void);
extern void func_02030D28(struct Ctx *c);
extern struct Node *func_02030DA8(struct Ctx *c, u32 a, u32 b, u32 key);
void sub_0200545C(void);
void func_020055F8(void);
void sub_0200560C(void);
void sub_02005610(void);
void *sub_02005624(u32 a, u32 b, u32 c);
void sub_02005640(void);
u32 sub_02005654(void (*fn)(void *), void *arg);
void sub_0200566C(void);
extern struct GflSys g_020AA194;
extern u8 s_gfl_use_c[];
extern u8 d_0209D8A0[];
extern u8 d_0209D8B0[];
extern u8 d_020A6C58[];
extern struct Sub02005610Sys sub_02005610_Sys;


/*
 * gfl_use.c, the file's __FILE__ anchor function: system boot set-up.  On a
 * non-TWL console, carve the main arena into the OS heap (Hi read before Lo,
 * hence the named local), create the extra heap and take a 0x3F00 block
 * from it; then the heap system on the console's arena table, the graphics,
 * card and sound bring-up, the three heap-tracked allocations at lines
 * 0x117 / 0x119 / 0x11C of gfl_use.c (s_gfl_use_c is the __FILE__ pointer),
 * and the task/callback installs.
 *
 * Closed in wave 14.  The pool was misread by one word in the older note
 * (docs/notes/sub_0200545C.c.txt): 0x020A6C58 is func_02048CEC's argument
 * and 0x02005769 (sub_02005768, src/matched/unit_0200575C.c) is
 * func_020346EC's third, and the two words 0x0202F769 / 0x0202F775 are
 * Thumb pointers to two unlabelled callback leaves of time_icon.c, filed
 * EXACT this wave as src/matched/func_0202F768.c and func_0202F774.c, which
 * is what attests them (`matched`).  d_0209D8A0 / d_0209D8B0 now resolve on
 * sole-ref.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200545C.c \
 *       --func sub_0200545C --addr 0x0200545C --cc 1.1p1 --thumb
 */
void sub_0200545C(void)
{
    if (OS_IsRunOnTwl() == 0) {
        void *hi = OS_GetArenaHi(0);
        OS_SetArenaLo(0, OS_InitAlloc(0, OS_GetArenaLo(0), hi, 1));
        g_020AA194.unk04 = OS_CreateExtraHeap(0);
        g_020AA194.unk14 = OS_AllocFromHeap(0, g_020AA194.unk04, 0x3F00);
    }

    if (OS_IsRunOnTwl() != 0) {
        func_02030608((u32)d_0209D8A0, 2, 0xAD, 0);
    } else {
        func_02030608((u32)d_0209D8B0, 2, 0xAD, 0);
    }

    func_02030BA4(0x2000);
    func_0203064C(1, 7, 0x25000);

    if (OS_IsRunOnTwl() == 0) {
        func_02030678(g_020AA194.unk14, 0x3F00, 9);
    } else {
        func_0203064C(1, 9, 0x3F00);
    }

    func_0203EF5C(0);
    func_02048CEC((u32)d_020A6C58, 0xEB);
    func_02034E24(0, 0);

    if (OS_GetConsoleType() & 0x81000000) {
        func_02034978();
    } else {
        func_020346EC(0, 0, (u32)sub_02005768);
    }

    func_0203499C(0, 0x10, 4, 4);
    func_0203129C(0);

    g_020AA194.heaps = func_02030734(0, 0x28, 0, (const char *)s_gfl_use_c, 0x117);
    g_020AA194.heaps->unk1C = func_02030734(0, func_02030CB0(4), 0, (const char *)s_gfl_use_c, 0x119);
    g_020AA194.heaps->unk18 = func_02030CBC(4, g_020AA194.heaps->unk1C);
    g_020AA194.heaps->unk24 = func_02030734(0, func_02030CB0(0x10), 0, (const char *)s_gfl_use_c, 0x11C);
    g_020AA194.heaps->unk20 = func_02030CBC(0x10, g_020AA194.heaps->unk24);

    sub_020056D0();
    func_0204E5E8(0);
    func_020316C8(7, (u32)func_0202F768, (u32)func_0202F774);
    func_0204E130(0);
    func_0203F3B4();
    g_020AA194.unk0C = 0;
    sub_0200566C();
    func_020057AC();
    func_0204E6F4(2);
}


void func_020055F8(void)
{
    func_02034F5C();
    func_0200F2D4();
    func_020312B4();
    func_0203F3F0();
}



/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 *           sub_02005654, sub_0200566C
 *
 * Six functions on the one system record at 0x020AA194 that the whole of this
 * packet reaches its state through.  Three of the six carry no label, because
 * they save nothing: sub_0200560C is two bytes of `bx lr` padded to four, the
 * empty hook shape
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md records;
 * sub_02005610 is a tail call through a pool word; and sub_02005654 is a two
 * arm register-and-return.
 *
 * sub_02005640 calls the hook at +8 with the argument at +0 when the hook is
 * present, sub_02005654 installs the pair only when the slot is free, and
 * sub_0200566C clears both.  In all three the store to +8 comes before the
 * store to +0, which is the source order.
 *
 * The record's +0x10 is the object src/matched/unit_020056A0.c calls its
 * heaps; the two files name it separately because each pins its own address
 * block.  The range stops at 0x0200567C because sub_0200567C is held open by
 * one unresolved call site; see the near miss register in the header of
 * src/matched/unit_020056A0.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200560C.c \
 *       --addr 0x0200560C --thumb
 */
void sub_0200560C(void)
{
}



void sub_02005610(void)
{
    func_02030D28(sub_02005610_Sys.unk10->unk18);
}



void *sub_02005624(u32 a, u32 b, u32 c)
{
    return func_02030DA8(sub_02005610_Sys.unk10->unk18, a, b, c);
}



void sub_02005640(void)
{
    if (sub_02005610_Sys.unk08 != 0) {
        sub_02005610_Sys.unk08(sub_02005610_Sys.unk00);
    }
}



u32 sub_02005654(void (*fn)(void *), void *arg)
{
    if (sub_02005610_Sys.unk08 != 0) {
        return 0;
    }
    sub_02005610_Sys.unk08 = fn;
    sub_02005610_Sys.unk00 = arg;
    return 1;
}



void sub_0200566C(void)
{
    sub_02005610_Sys.unk08 = 0;
    sub_02005610_Sys.unk00 = 0;
}
