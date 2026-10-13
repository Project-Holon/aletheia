/*
 * function: FLASH_ACCESS_PollWrite
 * address:  0x020337B8
 * packet:   pkt_02033534
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_020A789C     0x020A789C  data
 *   g_02146998     0x02146998  data
 *   func_02075EAC  0x02075EAC  arm
 *   func_02084F10  0x02084F10  arm
 *   func_02075DD8  0x02075DD8  arm
 *   FLASH_ACCESS_EndAccess  0x020338B8  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  g_020A789C[];
extern u32  g_02146998;
extern void func_02075EAC(void *a);
extern void func_02084F10(void *a);
extern u32  func_02075DD8(void);
extern void FLASH_ACCESS_EndAccess(u16 a, u32 b, void (*cb)(u32));

int FLASH_ACCESS_PollWrite(u16 a0, u32 *a1, u32 a2)
{
    if (g_020A789C[0] == 1) {
        func_02075EAC((void *)a0);
        func_02084F10((void *)a0);
        g_02146998 = 0;

        switch (func_02075DD8()) {
        case 0:
            *a1 = 1;
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 7:
        default:
            *a1 = 0;
            FLASH_ACCESS_EndAccess(a0, 0, (void (*)(u32))a2);
            break;
        case 6:
            *a1 = 0;
            FLASH_ACCESS_EndAccess(a0, 1, (void (*)(u32))a2);
            break;
        }
        return 1;
    }
    return 0;
}
