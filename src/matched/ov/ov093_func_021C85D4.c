/*
 * function: func_021C85D4
 * address: 0x021C85D4
 * packet: pkt_ov093_021C85D4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C87A0 0x021C87A0 thumb ov093
 *   func_021C87B0 0x021C87B0 thumb ov093
 *   func_021C87C0 0x021C87C0 thumb ov093
 *   func_021C87D0 0x021C87D0 thumb ov093
 *   func_021C87E0 0x021C87E0 thumb ov093
 *   func_021C87F0 0x021C87F0 thumb ov093
 *   func_021C8800 0x021C8800 thumb ov093
 *   func_021BD1E0 0x021BD1E0 thumb ov093
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Flags { u8 low : 3; u8 a : 1; u8 b : 1; u8 high : 3; };
struct Unk021BD1E0 {
    u16 f0; u8 f2; u8 f3; u8 f4;
    u8 b0 : 1; u8 b1 : 1; u8 rest : 6;
};
extern void func_021C87A0(void *);
extern void func_021C87B0(void *);
extern void func_021C87C0(void *);
extern void func_021C87D0(void *);
extern void func_021C87E0(void *);
extern void func_021C87F0(void *);
extern void func_021C8800(void *);
extern void func_021BD1E0(struct Unk021BD1E0 *);
extern void func_02082BCC(void *, int, u32);

void func_021C85D4(u8 *p, int index, int clear)
{
    u8 *q = p + 0x874 + index * 0x290;
    *(u8 **)(p + 0x850) = q;
    *(u8 **)(p + 0x854) = q + 0x48;
    *(u8 **)(p + 0x858) = q + 0x90;
    *(u8 **)(p + 0x85c) = q + 0xd8;
    *(u8 **)(p + 0x860) = q + 0x120;
    *(u8 **)(p + 0x864) = q + 0x168;
    *(u8 **)(p + 0x868) = q + 0x1b0;
    *(u8 **)(p + 0x4a8) = q + 0x1f8;
    *(u8 **)(p + 0x1ab0) = q + 0x200;
    *(u8 **)(p + 0x1ab4) = q + 0x214;
    *(u8 **)(p + 0x4b4) = q + 0x228;
    *(u8 **)(p + 0x4ac) = q + 0x22e;
    *(u8 **)(p + 0x4b0) = q + 0x241;
    *(u8 **)(p + 0x86c) = q + 0x254;
    *(u8 **)(p + 0x870) = q + 0x270;
    p[0x77f] = q[0x28c];
    ((struct Flags *)(p + 0x78a))->a = q[0x28d];
    ((struct Flags *)(p + 0x78a))->b = q[0x28e];
    if (clear) {
        func_021C87A0(q);
        func_021C87B0(*(void **)(p + 0x854));
        func_021C87C0(*(void **)(p + 0x858));
        func_021C87D0(*(void **)(p + 0x85c));
        func_021C87E0(*(void **)(p + 0x860));
        func_021C87F0(*(void **)(p + 0x864));
        func_021C8800(*(void **)(p + 0x868));
        func_021BD1E0(*(struct Unk021BD1E0 **)(p + 0x4a8));
        func_02082BCC(*(void **)(p + 0x1ab0), 0, 0x14);
        func_02082BCC(*(void **)(p + 0x1ab4), 0, 0x14);
        func_02082BCC(*(void **)(p + 0x4b4), 0, 6);
        func_02082BCC(*(void **)(p + 0x4ac), 0, 0x13);
        func_02082BCC(*(void **)(p + 0x4b0), 0, 0x13);
        func_02082BCC(*(void **)(p + 0x86c), 0, 0x1c);
        func_02082BCC(*(void **)(p + 0x870), 0, 0x1c);
        p[0x77f] = 6;
        ((struct Flags *)(p + 0x78a))->a = 0;
        ((struct Flags *)(p + 0x78a))->b = 0;
    }
}
