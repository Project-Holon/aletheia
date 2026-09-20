/*
 * function: func_020336B8
 * address:  0x020336B8
 * packet:   pkt_02033534
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * blocker:  func_020336A4 (ABS32, data/arm pointer) -- has no witness outside
 *           020336B8..020337B8.  The address is the unlabelled leaf that
 *           follows func_020335E8; it saves no lr, so disasm.py gives it no
 *           label and neither `label` nor `veneer` applies, and the single
 *           occurrence of the word in the image is the pool word at
 *           0x020337B4 inside this very range.  --suggest-split confirms no
 *           cut helps (1 witness image wide, 1 inside).  Every concrete byte
 *           of all 256 reproduces; seeding 0x020336A4 into
 *           layout/function_starts.txt is what unblocks it.
 *
 * symbols:
 *   str_020A78A0            0x020A78A0  data
 *   str_020A78B0            0x020A78B0  data
 *   d_020A789C              0x020A789C  data
 *   d_02146998              0x02146998  data
 *   func_02034714           0x02034714  arm
 *   func_02084EB8           0x02084EB8  arm
 *   func_02075E9C           0x02075E9C  arm
 *   func_020338B8           0x020338B8  arm
 *   CARDi_RequestStreamCommand 0x02076AC0  arm
 *   func_020336A4           0x020336A4  arm
 *
 * Two stream commands plus a 4-byte status read into a stack word.  The
 * first passes is_async = 0 and the retry count exercises the function at
 * 0x020336A4 (an unlabelled leaf, the follower of func_020335E8, which sets
 * the flag at 0x02146998) as the dma callback.  d_02146998 is raised around
 * the synchronous read and d_020A789C lowered before the asynchronous one.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020336B8.c \
 *       --func func_020336B8 --addr 0x020336B8 --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern const u8 str_020A78A0[];
extern const u8 str_020A78B0[];
extern u32 d_020A789C;
extern u32 d_02146998;
extern void func_02034714(const u8 *file, int line, const u8 *msg);
extern int  func_02084EB8(u32 a);
extern void func_02075E9C(u16 a);
extern void func_020338B8(u16 a, int b, void *c);
extern int  CARDi_RequestStreamCommand(u32 src, u32 dst, u32 len, void *callback,
                                       void *arg, int is_async, int req_type,
                                       int req_retry, int req_mode);
extern void func_020336A4(void);

int func_020336B8(u32 a0, u32 a1, u32 a2, void *a3)
{
    int id = func_02084EB8(a0);
    u32 buf;

    if (id == -3) {
        func_02034714(str_020A78A0, 0xd4, str_020A78B0);
    }
    func_02075E9C((u16)id);

    d_02146998 = 1;
    if (CARDi_RequestStreamCommand(0, (u32)&buf, 4, 0, 0, 0, 6, 1, 0) == 0) {
        func_020338B8((u16)id, 1, a3);
    }

    d_020A789C = 0;
    CARDi_RequestStreamCommand(a1, a0, a2, func_020336A4, 0, 1, 7, 10, 2);
    return (u16)id;
}
