/*
 * function: FLASH_ACCESS_EndAccess
 * address:  0x020338B8
 * packet:   pkt_020334E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_02146998     0x02146998  data
 *   func_02075EAC   0x02075EAC  arm
 *   OS_ReleaseLockID   0x02084F10  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 g_02146998;
extern void func_02075EAC(u16 lock_id);
extern void OS_ReleaseLockID(u32 a);

void FLASH_ACCESS_EndAccess(u16 a, u32 b, void (*cb)(u32))
{
    func_02075EAC(a);
    OS_ReleaseLockID(a);
    g_02146998 = 0;
    if (cb != 0) {
        cb(b);
    }
}
