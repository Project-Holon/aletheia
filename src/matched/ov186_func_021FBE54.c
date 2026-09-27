/*
 * function: func_021FBE54
 * address:  0x021FBE54
 * packet:   pkt_ov186_021FBE54
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds the three sprite handles of the 12-byte entry `idx` (at base+8+idx*12)
 * from the per-index asset category: one resource set opened on the caller's
 * heap, then func_0204A6C8 / func_0204AF28 (or ENV_SetResourceSet for the
 * 0x11/0x12 cases, which fill the +8 field instead), then the set closed.
 * symbols:
 *   d_02200D48       0x02200D48  data
 *   func_02034714    0x02034714  arm
 *   func_020490F4    0x020490F4  arm
 *   func_0204A6C8    0x0204A6C8  arm
 *   func_0204AC18    0x0204AC18  arm
 *   func_0204AF28    0x0204AF28  arm
 *   func_02049238    0x02049238  arm
 */

typedef unsigned int u32;

extern char d_02200D48[];
extern void func_02034714(char *a, u32 b, char *c);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_0204A6C8(void *h, u32 a1, u32 a2, u32 a3, u32 s0);
extern u32 func_0204AC18(void *h, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2);
extern void *func_0204AF28(void *h, u32 a1, u32 a2, u32 s0);
extern void func_02049238(void *h);

void func_021FBE54(char *base, u32 idx, u32 area)
{
    u32 *r4;

    r4 = (u32 *)(base + 8 + idx * 12);

    if (*(u32 *)(base + 0xb0 + idx * 4) != 0) {
        func_02034714(d_02200D48, 0, d_02200D48);
    }

    switch (idx) {
    case 4: {
        void *h = func_020490F4(0x89, area);
        r4[2] = *(u32 *)base;
        r4[1] = func_0204A6C8(h, 0x24, 0, 0, area);
        r4[0] = (u32)func_0204AF28(h, 0x15, 0x14, area);
        func_02049238(h);
        break;
    }
    case 5: {
        void *h = func_020490F4(0x89, area);
        r4[2] = *(u32 *)(base + 4);
        r4[1] = func_0204A6C8(h, 0x24, 0, 1, area);
        r4[0] = (u32)func_0204AF28(h, 0x15, 0x14, area);
        func_02049238(h);
        break;
    }
    case 0: {
        void *h = func_020490F4(0x89, area);
        r4[2] = *(u32 *)base;
        r4[1] = func_0204A6C8(h, 0x22, 0, 0, area);
        r4[0] = (u32)func_0204AF28(h, 9, 0xa, area);
        func_02049238(h);
        break;
    }
    case 1: {
        void *h = func_020490F4(0x89, area);
        r4[2] = *(u32 *)(base + 4);
        r4[1] = func_0204A6C8(h, 0x22, 0, 1, area);
        r4[0] = (u32)func_0204AF28(h, 9, 0xa, area);
        func_02049238(h);
        break;
    }
    case 2: {
        void *h = func_020490F4(0x89, area);
        r4[2] = *(u32 *)base;
        r4[1] = func_0204A6C8(h, 0x3f, 0, 0, area);
        r4[0] = (u32)func_0204AF28(h, 0x3d, 0x3e, area);
        func_02049238(h);
        break;
    }
    case 3: {
        void *h = func_020490F4(0x89, area);
        r4[2] = *(u32 *)(base + 4);
        r4[1] = func_0204A6C8(h, 0x3f, 0, 1, area);
        r4[0] = (u32)func_0204AF28(h, 0x3d, 0x3e, area);
        func_02049238(h);
        break;
    }
    case 6: {
        void *h = func_020490F4(0x89, area);
        r4[2] = *(u32 *)(base + 4);
        r4[1] = func_0204A6C8(h, 0x23, 0, 1, area);
        r4[0] = (u32)func_0204AF28(h, 7, 8, area);
        func_02049238(h);
        break;
    }
    case 8: {
        void *h = func_020490F4(0x89, area);
        r4[2] = *(u32 *)(base + 4);
        r4[1] = func_0204A6C8(h, 0x56, 0, 1, area);
        r4[0] = (u32)func_0204AF28(h, 0x55, 0x54, area);
        func_02049238(h);
        break;
    }
    case 7: {
        void *h = func_020490F4(0x89, area);
        r4[2] = *(u32 *)base;
        r4[1] = func_0204A6C8(h, 0x56, 0, 0, area);
        r4[0] = (u32)func_0204AF28(h, 0x55, 0x54, area);
        func_02049238(h);
        break;
    }
    case 11: {
        void *h = func_020490F4(0x89, area);
        r4[2] = func_0204AC18(h, 0x13, 1, 0x80, 0, 1, area);
        r4[1] = func_0204A6C8(h, 0xf, 0, 1, area);
        r4[0] = (u32)func_0204AF28(h, 0x10, 0x11, area);
        func_02049238(h);
        break;
    }
    case 12: {
        void *h = func_020490F4(0x89, area);
        r4[2] = func_0204AC18(h, 0x33, 1, 0xa0, 0, 1, area);
        r4[1] = func_0204A6C8(h, 0x32, 0, 1, area);
        r4[0] = (u32)func_0204AF28(h, 0x30, 0x31, area);
        func_02049238(h);
        break;
    }
    case 9: {
        void *h = func_020490F4(0x89, area);
        r4[2] = *(u32 *)base;
        r4[1] = func_0204A6C8(h, 0x36, 0, 0, area);
        r4[0] = (u32)func_0204AF28(h, 0x34, 0x35, area);
        func_02049238(h);
        break;
    }
    case 10: {
        void *h = func_020490F4(0x89, area);
        r4[2] = *(u32 *)(base + 4);
        r4[1] = func_0204A6C8(h, 0x36, 0, 1, area);
        r4[0] = (u32)func_0204AF28(h, 0x34, 0x35, area);
        func_02049238(h);
        break;
    }
    case 13: {
        void *h = func_020490F4(0x89, area);
        r4[2] = *(u32 *)base;
        r4[0] = (u32)func_0204AF28(h, 0x29, 0x2a, area);
        r4[1] = func_0204A6C8(h, 0x25, 0, 0, area);
        func_02049238(h);
        break;
    }
    default:
        break;
    }

    *(u32 *)(base + 0xb0 + idx * 4) = 1;
}
