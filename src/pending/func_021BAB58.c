/*
 * function: func_021BAB58
 * address:  0x021BAB58
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Blocker for 0x02005654 resolved: it was matched in arm9 (src/matched/
 * func_02005654.c, shard pkt_02005654); it is Thumb (the old symbols line
 * said arm, which refused the match).  0x021BAB50 is the 8-byte stub
 * `ldr r0,[pc]; bx r3` in ov217, resolved by the ov217 hint.
 *
 * symbols:
 *   func_021BAB50  0x021BAB50  thumb  ov217
 *   func_02005654  0x02005654  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_02005654(void (*)(), int);
extern void func_021BAB50();
void func_021BAB58(void)
{
    func_02005654(func_021BAB50, 0);
}

