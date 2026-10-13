/*
 * function: NWM_GetState
 * address:  0x027028B0
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NWMi_GetSystemWork  0x027026DC  arm twl a2
 *   func_020862B8  0x020862B8  arm twl a2
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 NWMi_GetSystemWork(void);
extern void func_020862B8(u32, u32);

u32 NWM_GetState(void) {
    u32 base = NWMi_GetSystemWork();
    u32 r1 = 0;
    if (base != 0) {
        u32 ptr = *(u32 *)(base + 0x2278);
        func_020862B8(ptr, 2);
        r1 = *(u16 *)(ptr + 0x24);
    }
    return r1;
}
