/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: func_0204152C, func_02041570, func_020415B4
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
 *   func_020409B4   0x020409B4  arm
 *   func_02041B6C   0x02041B6C  arm
 *   func_0207E1F8   0x0207E1F8  arm
 *   func_0207E24C   0x0207E24C  arm
 *   func_0207E2A0   0x0207E2A0  arm
 *   func_0207E330   0x0207E330  arm
 *   func_0207E22C   0x0207E22C  arm
 *   func_0207E280   0x0207E280  arm
 *   func_0207E2F0   0x0207E2F0  arm
 *   func_0207E388   0x0207E388  arm
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
extern void func_020409B4(u32 index);
extern void func_02041B6C(u32 bit);

void func_0204152C(int channel, u16 val)
{
    struct Channel *ch = &ptr_02146A44[channel];
    if (ch->field_08 == 0) {
        return;
    }
    MIi_CpuClear16(val, ch->field_08, ch->field_0c);
    func_020409B4(channel);
}

void func_02041570(int channel, u16 val)
{
    struct Channel *ch = &ptr_02146A44[channel];
    if (ch->field_08 == 0) {
        return;
    }
    MIi_CpuClear16(val, ch->field_08, ch->field_0c);
    func_02041B6C(channel);
}

extern u32 func_0207E1F8(void);
extern u32 func_0207E24C(void);
extern u32 func_0207E2A0(void);
extern u32 func_0207E330(void);
extern u32 func_0207E22C(void);
extern u32 func_0207E280(void);
extern u32 func_0207E2F0(void);
extern u32 func_0207E388(void);

u32 func_020415B4(u32 channel)
{
    switch (channel) {
    case 0: return func_0207E1F8();
    case 1: return func_0207E24C();
    case 2: return func_0207E2A0();
    case 3: return func_0207E330();
    case 4: return func_0207E22C();
    case 5: return func_0207E280();
    case 6: return func_0207E2F0();
    case 7: return func_0207E388();
    default: return 0;
    }
}
