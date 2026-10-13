/*
 * function: NwmGetCommandBuffer4Arm7
 * address:  0x02703B98
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NWMi_GetSystemWork  0x027026DC  arm twl
 *   func_02085E50  0x02085E50  arm twl
 *   func_020862B8  0x020862B8  arm twl
 *   func_02085DBC  0x02085DBC  arm twl
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern u32 NWMi_GetSystemWork(void);
extern u32 func_02085E50(u32, u16 **, u32);
extern void func_020862B8(void *, u32);
extern void func_02085DBC(u32, u16 *, u32);

u16 *NwmGetCommandBuffer4Arm7(void) {
    u16 *msg = 0;
    u32 base = NWMi_GetSystemWork();

    do {
        if (func_02085E50(base + 0x2000, &msg, 0) == 0) {
            return 0;
        }
        func_020862B8((void *)base, 0x2000);
        func_020862B8(msg, 2);
        if (!(*msg & 0x8000)) {
            func_02085DBC(base + 0x2000, msg, 1);
            msg = 0;
        }
    } while (msg == 0);
    return msg;
}
