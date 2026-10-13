/*
 * function: NWMi_CheckState
 * address:  0x027028E4
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NWMi_GetSystemWork 0x027026DC arm twl
 *   NWMi_CheckInitialized 0x02702698 arm twl
 *   func_020862B8 0x020862B8 arm twl
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef char *va_list;

#define va_start(ap, last) ((ap) = (char *)(((u32)&(last)) & ~3) + 4)
#define va_arg(ap, t) (*(t *)(((ap) += 4) - 4))

extern u32 NWMi_GetSystemWork(void);
extern u32 NWMi_CheckInitialized(void);
extern void func_020862B8(u32, u32);

/* Returns 0 when the current state is one of the n listed values, 3 when it is not. */
u32 NWMi_CheckState(u32 n, ...) {
    u32 base = NWMi_GetSystemWork();
    u32 st = NWMi_CheckInitialized();
    u32 cur;
    u32 ret;
    va_list ap;
    if (st != 0 && st != 2) {
        return st;
    }
    func_020862B8(*(u32 *)(base + 0x2278) + 0x24, 2);
    cur = *(u16 *)(*(u32 *)(base + 0x2278) + 0x24);
    ret = 3;
    va_start(ap, n);
    while (n != 0) {
        if (va_arg(ap, u32) == cur) ret = 0;
        n--;
    }
    return ret;
}
