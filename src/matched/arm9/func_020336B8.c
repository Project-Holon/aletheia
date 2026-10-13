/*
 * function: FLASH_ACCESS_StartWrite
 * address:  0x020336B8
 * packet:   pkt_02033534
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   str_020A78A0            0x020A78A0  data
 *   str_020A78B0            0x020A78B0  data
 *   d_020A789C              0x020A789C  data
 *   d_02146998              0x02146998  data
 *   func_02034714           0x02034714  arm
 *   func_02084EB8           0x02084EB8  arm
 *   func_02075E9C           0x02075E9C  arm
 *   FLASH_ACCESS_EndAccess           0x020338B8  arm
 *   CARDi_RequestStreamCommand 0x02076AC0  arm
 *   FLASH_ACCESS_OnWriteDone           0x020336A4  arm
 *
 * Two stream commands plus a 4-byte status read into a stack word.  The
 * first passes is_async = 0 and the retry count exercises the function at
 * 0x020336A4 (an unlabelled leaf, the follower of FLASH_ACCESS_Read, which sets
 * the flag at 0x02146998) as the dma callback.  d_02146998 is raised around
 * the synchronous read and d_020A789C lowered before the asynchronous one.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FLASH_ACCESS_StartWrite.c \
 *       --func FLASH_ACCESS_StartWrite --addr 0x020336B8 --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern const u8 str_020A78A0[];
extern const u8 str_020A78B0[];
extern u32 d_020A789C;
extern u32 d_02146998;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern int  func_02084EB8(u32 a);
extern void func_02075E9C(u16 a);
extern void FLASH_ACCESS_EndAccess(u16 a, u32 b, void (*cb)(u32));
extern int  CARDi_RequestStreamCommand(u32 src, u32 dst, u32 len, void *callback,
                                       void *arg, int is_async, int req_type,
                                       int req_retry, int req_mode);
extern void FLASH_ACCESS_OnWriteDone(void);

int FLASH_ACCESS_StartWrite(u32 a0, u32 a1, u32 a2, void *a3)
{
    int id = func_02084EB8(a0);
    u32 buf;

    if (id == -3) {
        func_02034714((const char *)str_020A78A0, 0xd4, (const char *)str_020A78B0);
    }
    func_02075E9C((u16)id);

    d_02146998 = 1;
    if (CARDi_RequestStreamCommand(0, (u32)&buf, 4, 0, 0, 0, 6, 1, 0) == 0) {
        FLASH_ACCESS_EndAccess((u16)id, 1, a3);
    }

    d_020A789C = 0;
    CARDi_RequestStreamCommand(a1, a0, a2, FLASH_ACCESS_OnWriteDone, 0, 1, 7, 10, 2);
    return (u16)id;
}
