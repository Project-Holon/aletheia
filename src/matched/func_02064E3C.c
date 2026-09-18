/*
 * function: func_02064E3C
 * address:  0x02064E3C
 * packet:   pkt_020648E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02147B88   0x02147B88  data
 *   g_02147B98   0x02147B98  data
 *   g_02147D18   0x02147D18  data
 *   g_02147D28   0x02147D28  data
 *   g_02147D2C   0x02147D2C  data
 *   g_02148018   0x02148018  data
 *
 * Initialises one 0x18-byte slot of the renderer's per-slot tables, selected by
 * g_02147B88's +0xC field: either the two words at 0x02147D28 / 0x02147D2C are
 * cleared, or the six words of the template at 0x02147D18 are built
 * (0x1000, 0, 0, 0x1000, 0, 0) and copied whole into 0x02148018, which is the
 * 24-byte aggregate assignment the `ldm`/`stm` pair reproduces.  The slot's
 * entry in the u32 table at 0x02147B98 is cleared either way.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02064E3C.c \
 *       --func func_02064E3C --addr 0x02064E3C --arm --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct B8802064E3C {
    u8  pad_00[4];
    u32 unk_04;
    u8  pad_08[4];
    u32 unk_0c;
};

struct Blk02064E3C {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
};

extern struct B8802064E3C g_02147B88;
extern u32 g_02147B98[];
extern struct Blk02064E3C g_02147D18[];
extern u8 g_02147D28[];
extern u8 g_02147D2C[];
extern struct Blk02064E3C g_02148018[];

void func_02064E3C(void)
{
    u32 i = g_02147B88.unk_0c;

    if (g_02147B88.unk_04 != 0) {
        *(u32 *)&g_02147D28[i * 0x18] = 0;
        *(u32 *)&g_02147D2C[i * 0x18] = 0;
    } else {
        struct Blk02064E3C *s = &g_02147D18[i];

        s->unk_00 = 0x1000;
        s->unk_04 = 0;
        s->unk_08 = 0;
        s->unk_0c = 0x1000;
        s->unk_10 = 0;
        s->unk_14 = 0;
        g_02148018[i] = *s;
    }

    g_02147B98[i] = 0;
}
