/*
 * unit: yes
 * function: func_021BA374
 * address: 0x021BA374
 * packet: pkt_ov206_021BA374
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: cases 0/6/7 are empty labels inside the 8-entry jump table. The window registers are literal
 *   volatile addresses; the derived 0x04000000 base and 0x800 come from constant derivation.
 * symbols:
 *   func_021BBC9C 0x021BBC9C thumb ov206
 *   func_0207D658 0x0207D658 arm
 *   func_02006984 0x02006984 thumb
 *   func_0204B53C 0x0204B53C arm
 *   func_0204B528 0x0204B528 arm
 *   func_021BAF7C 0x021BAF7C thumb ov206
 *   func_0201C4E4 0x0201C4E4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Pt { s16 x; s16 y; };
extern void func_021BBC9C(char *p);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern u32 func_02006984(u32, u32, u32, u32, u32, u32, u32, u32);
struct Actor;
struct PrintSys;
extern void func_0204B53C(const struct Actor *actor, struct Pt *out);
extern void func_0204B528(struct Actor *actor, const struct Pt *src);
extern void func_021BAF7C(char *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
void func_021BA374(char *p)
{
    if (*(int *)(p+0x18) == 0) func_021BBC9C(p);
    *(int *)(p+0x64) += 1;
    if (*(int *)(p+0x64) == 4) {
        *(u8 *)(p+0x39) |= 1;
        *(int *)(p+0x64) = 0;
    }
    switch (*(int *)(p+0x54)) {
    case 0: case 6: case 7: break;
    case 1:
        *(int *)(p+0x60) += 1;
        if (*(int *)(p+0x60) == 15) *(int *)(p+0x54) = 2;
        break;
    case 2: {
        int v = *(int *)(p+0x68) - 1;
        *(int *)(p+0x68) = v;
        *(volatile u16 *)0x04000040 = 100;
        *(volatile u16 *)0x04000044 = (u16)(((8 << 8) & 0xFF00) | (v & 0xFF));
        if (*(int *)(p+0x68) == 16) {
            *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
            func_0207D658((u32)((volatile u16 *)0x04000050), 0x10, 0);
            func_02006984(*(u16 *)(p+0xc), *(u16 *)(p+0xe), 0x40, 0, 0, 0, 0, 0);
            *(int *)(p+0x54) = 3;
        }
        break;
    }
    case 3:
        if (*(int *)(p+0x58) != 0) *(int *)(p+0x54) = 4;
        break;
    case 4: {
        struct Pt pt;
        int fx = 0;
        int fy = 0;
        void *obj = *(void **)(p + *(int *)(p+0xb4) * 4 + 0xac);
        func_0204B53C(obj, &pt);
        pt.x += 1;
        pt.y += 1;
        if (pt.x > 0x80) { pt.x = 0x80; fx = 1; }
        if (pt.y > 0x48) { pt.y = 0x48; fy = 1; }
        func_0204B528(*(void **)(p + *(int *)(p+0xb4) * 4 + 0xac), &pt);
        if (fx && fy) *(int *)(p+0x54) = 6;
        break;
    }
    case 5:
        if (*(int *)(p+0x5c) != 0) {
            func_02006984(*(u16 *)(p+0xc), *(u16 *)(p+0xe), 0x40, 0, 0, 0, 0, 0);
            *(int *)(p+0x54) = 6;
        }
        break;
    }
    if (*(int *)(p+0x18) == 0 || *(int *)(p+0x18) == 2) func_021BAF7C(p);
    func_0201C4E4(*(void **)(p+0x2c));
}
