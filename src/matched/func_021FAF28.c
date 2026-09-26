/*
 * function: func_021FAF28
 * address:  0x021FAF28
 * packet:   pkt_021FAF28
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocker resolved: func_0201134C was matched in arm9 (src/matched/
 * func_0201134C.c, shard pkt_0201134C); the +0006 call now attests as
 * `matched`.  The symbols: line had it as `arm`; it is Thumb and now says so.
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int func_0201134C(void *);

int func_021FAF28(void *a, u8 *p)
{
    *(u16 *)(p + 0x14) = (u16)func_0201134C(*(void **)(p + 4));
    return 1;
}
