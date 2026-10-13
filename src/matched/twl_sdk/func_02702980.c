/*
 * function: NWM_GetAllowedChannel
 * address:  0x02702980
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
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 NWMi_GetSystemWork(void);

u32 NWM_GetAllowedChannel(void) {
    u32 base = NWMi_GetSystemWork();
    u32 ptr = *(u32 *)(base + 0x2278);
    return *(u16 *)(ptr + 0x9E);
}
