/*
 * file:     net_lower_data_p04.c
 * unit:     yes
 * function: func_0203ECD8, func_0203ED84
 * address:  0x0203ECD8
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
 *   g_021469F4     0x021469F4  data
 *   func_0203D798  0x0203D798  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 */
struct Entry;
struct Link;
typedef unsigned char u8;

typedef unsigned int  u32;

struct Rec {
    u8  pad_00[0xc];
    u32 unk_0c;
};

struct Tbl {
    struct Rec *ent[0xe];
    u32 unk_38;
    u8  pad_3c[4];
    u32 unk_40;
};

struct Ctx {
    u8  pad_00[0x64];
    u8  unk_64;
};

struct S {
    unsigned int a : 2;
    unsigned int b : 30;
};

typedef signed int     s32;

extern void *func_0203D798(void);
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern struct Entry *func_0203996C(s32 idx);
extern u32 func_0203D4D0(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void func_0203ECD8(u32 idx, u32 delta, u32 a2, u32 a3, u32 who);
int func_0203ED84(int a0);
extern struct Tbl *g_021469F4;


/*
 * Credit `delta` to the score record of player `idx` (0xff meaning "me",
 * folded to slot 0 on entry).  The record table hangs off the one global the
 * whole file uses, g_021469F4, whose first words are the per-slot record
 * pointers and whose +0x38 / +0x40 are the mode and the dirty flag.
 *
 * Both entry guards are one `||` apiece, which is what makes the `cmpne` /
 * `ldrne` / `popeq` chain: the table pointer and the slot's record are tested
 * together and the null exit is each guard's own conditional return
 * (contrast func_0203EC7C in this packet, which shares one exit block; see
 * docs/notes/pkt_0203EC7C.c.txt).  The global is re-read after every call
 * because each callee may publish a new table.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203ECD8.c \
 *       --func func_0203ECD8 --addr 0x0203ECD8 --cc 1.1p1 --arm
 */
void func_0203ECD8(u32 idx, u32 delta, u32 a2, u32 a3, u32 who)
{
    struct Ctx *ctx;
    struct Rec *rec;

    if (idx == 0xff) {
        idx = 0;
    }
    if (g_021469F4 == 0 || g_021469F4->ent[idx] == 0) {
        return;
    }

    ctx = func_0203D798();

    if (g_021469F4 == 0 || g_021469F4->ent[idx] == 0) {
        return;
    }

    if ((u32)func_020399A8() != who && ctx->unk_64 == 0) {
        return;
    }

    rec = g_021469F4->ent[idx];
    rec->unk_0c += delta;

    if (g_021469F4->unk_38 != 1) {
        return;
    }

    if (idx != func_0203D1A4((struct Link *)((u32)func_020399A8()))) {
        g_021469F4->unk_40 = 1;
    }
}

int func_0203ED84(int a0)
{
    struct S sv;
    int t;
    if (*(int *)((char *)g_021469F4 + 0x2c) == 1)
        t = (int)func_0203996C(0xff);
    else
        t = (int)func_020399A8();
    sv.a = a0;
    sv.b = *(int *)((char *)g_021469F4 + 0x24);
    return func_0203D4D0(t, *(u8 *)((char *)g_021469F4 + 0x28), 0xf, 4, (u32)(&sv), 0, 1, 0);
}
