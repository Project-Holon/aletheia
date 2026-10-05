/*
 * function: func_02075FCC
 * address:  0x02075FCC
 * packet:   pkt_02075DA0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_GetBootType  0x02087B04  arm
 *   OS_IsRunOnTwl   0x02085D3C  arm
 *   func_02075E04   0x02075E04  arm
 *
 * A permission mask built from the TWL ROM header.  func_02075E04 returns the
 * header buffer (its pool word is 0x02FFE000), and the four one-bit extracts
 * of the word at +0x1B4 are its access-control flags, read as u32 bitfields
 * (bits 5, 8, 15, 16).  A ROM boot (OS_GetBootType() == 1) or a non-TWL run
 * grants everything (7).  Otherwise bit 8 grants 4 and enables the other two
 * checks, bit 5 only enables them, and bits 15/16 grant 1/2.  Byte-exact under
 * both 1.1p1 and ../2.0/sp2 on the first compile; EXACT* because the follower
 * 0x02076050 (already filed) carries no label.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02075FCC.c \
 *       --func func_02075FCC --addr 0x02075FCC --arm --cc 1.1p1
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef int BOOL;
typedef struct {
    u32 b0_4  : 5;
    u32 b5    : 1;
    u32 b6_7  : 2;
    u32 b8    : 1;
    u32 b9_14 : 6;
    u32 b15   : 1;
    u32 b16   : 1;
    u32 rest  : 15;
} Access;
typedef struct { u8 pad[0x1b4]; Access access; } Hdr;
extern int OS_GetBootType(void);
extern BOOL OS_IsRunOnTwl(void);
extern Hdr *func_02075E04(void);
u32 func_02075FCC(void)
{
    u32 result = 0;
    Hdr *hdr;
    BOOL enable;
    if (OS_GetBootType() == 1) {
        result = 7;
    } else if (!OS_IsRunOnTwl()) {
        result = 7;
    } else {
        hdr = func_02075E04();
        enable = 0;
        if (hdr->access.b8) {
            result |= 4;
            enable = 1;
        } else if (hdr->access.b5) {
            enable = 1;
        }
        if (enable) {
            if (hdr->access.b15) result |= 1;
            if (hdr->access.b16) result |= 2;
        }
    }
    return result;
}
