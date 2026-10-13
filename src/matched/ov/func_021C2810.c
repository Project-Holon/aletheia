/*
 * function: WIFICLUB_CountChangeAndCopyPeerAddr
 * address:  0x021C2810
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 *
 * Bumps the counter at +0x1C and tails onto the arm9 routine with the block 8 bytes in.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

typedef struct {
    char pad[0x1C];
    u8 f1C;
} S;

extern void MI_CpuCopy8(void *a, void *b, int c);

void WIFICLUB_CountChangeAndCopyPeerAddr(S *s, char *q)
{
    s->f1C++;
    MI_CpuCopy8(q + 0xE, (char *)s + 8, 6);
}
