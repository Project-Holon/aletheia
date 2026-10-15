/*
 * unit:     yes
 * function: UI_SetResumeHook, sub_0203512C
 * address:  0x02035120
 * packet:   pkt_02035080
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Two more plain field setters right after UI_SetSuspendHook's pair, same shape:
 * "str r1,[r0,#0x18]; str r2,[r0,#0x2c]; bx lr" then
 * "str r1,[r0,#0x20]; str r2,[r0,#0x30]; bx lr", twelve bytes each, no
 * relocations.  A third function follows in the same block at 0x02035138
 * (not attempted here: it loads through two pool words and is not a plain
 * accessor).
 *
 * The struct here only pins the four offsets these two functions touch, not
 * the real layout.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02035120.c \
 *       --addr 0x02035120 --arm
 */

typedef unsigned int u32;

struct Obj02035120 {
    unsigned char pad[0x18];
    u32 unk18;
    unsigned char pad2[0x04];
    u32 unk20;
    unsigned char pad3[0x08];
    u32 unk2C;
    u32 unk30;
};

void UI_SetResumeHook(struct Obj02035120 *p, u32 a, u32 b)
{
    p->unk18 = a;
    p->unk2C = b;
}

void sub_0203512C(struct Obj02035120 *p, u32 a, u32 b)
{
    p->unk20 = a;
    p->unk30 = b;
}
