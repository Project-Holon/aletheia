/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: BG_SYS_ClearLayer, BG_SYS_ClearLayerEx, BG_SYS_GetGraphics
 * address:  0x0204152C
 * packet:   pkt_0204152C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   ptr_02146A44    0x02146A44  data
 *   MIi_CpuClear16  0x02082A48  arm
 *   BG_SYS_PushTile   0x020409B4  arm
 *   func_02041B6C   0x02041B6C  arm
 *   G2_GetBG0CharPtr   0x0207E1F8  arm
 *   G2_GetBG1CharPtr   0x0207E24C  arm
 *   G2_GetBG2CharPtr   0x0207E2A0  arm
 *   G2_GetBG3CharPtr   0x0207E330  arm
 *   func_0207E22C   0x0207E22C  arm
 *   func_0207E280   0x0207E280  arm
 *   G2S_GetBG2CharPtr   0x0207E2F0  arm
 *   G2S_GetBG3CharPtr   0x0207E388  arm
 *
 * Channel clear and audio dispatcher functions.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204152C.c \
 *       --addr 0x0204152C --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Channel {
    u8   pad00[8];
    void *field_08;
    u32  field_0c;
    u8   pad10[0x1c];
};

extern struct Channel *ptr_02146A44;
extern void MIi_CpuClear16(u16 val, void *dest, u32 size);
extern void BG_SYS_PushTile(u32 index);
extern void func_02041B6C(u32 bit);

void BG_SYS_ClearLayer(int channel, u16 val)
{
    struct Channel *ch = &ptr_02146A44[channel];
    if (ch->field_08 == 0) {
        return;
    }
    MIi_CpuClear16(val, ch->field_08, ch->field_0c);
    BG_SYS_PushTile(channel);
}

void BG_SYS_ClearLayerEx(int channel, u16 val)
{
    struct Channel *ch = &ptr_02146A44[channel];
    if (ch->field_08 == 0) {
        return;
    }
    MIi_CpuClear16(val, ch->field_08, ch->field_0c);
    func_02041B6C(channel);
}

extern void *G2_GetBG0CharPtr(void);
extern void *G2_GetBG1CharPtr(void);
extern void *G2_GetBG2CharPtr(void);
extern void *G2_GetBG3CharPtr(void);
extern u32 func_0207E22C(void);
extern u32 func_0207E280(void);
extern void *G2S_GetBG2CharPtr(void);
extern void *G2S_GetBG3CharPtr(void);

u32 BG_SYS_GetGraphics(u32 channel)
{
    switch (channel) {
    case 0: return (u32)G2_GetBG0CharPtr();
    case 1: return (u32)G2_GetBG1CharPtr();
    case 2: return (u32)G2_GetBG2CharPtr();
    case 3: return (u32)G2_GetBG3CharPtr();
    case 4: return func_0207E22C();
    case 5: return func_0207E280();
    case 6: return (u32)G2S_GetBG2CharPtr();
    case 7: return (u32)G2S_GetBG3CharPtr();
    default: return 0;
    }
}
