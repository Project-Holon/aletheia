/*
 * docs/families/net_irc_wireless.h -- shared declarations for the
 * net_irc_wireless.c family (about 0x0203D814..0x0203E6C0 in the ARM9
 * image, ARM code).  The __FILE__ anchor is 0x020A7D34 (pool words at
 * 0x0203D9DC, 0x0203DBF8, 0x0203E4DC, 0x0203E588, 0x0203E5EC).
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; match.py never sees
 * it.  Every declaration is taken from a file in src/matched that is EXACT
 * (or from src/pending/func_0203DC70.c, byte-correct MATCH), named beside it.
 * Addresses are Black-image addresses (docs/AGENT-BRIEF.md section 8).
 *
 * Library shape: this is game code over the TwlSDK wireless layer, not an
 * SDK file itself.  Its callees are the net_state.c/net_system.c helpers
 * (func_020399A8 handle getter, func_02039C68/func_02039CB4 connect and
 * poll, func_0203D3A8 send), OS_GetMacAddress (func_02087C6C),
 * MI_CpuCopy8 (func_02082D44) and a memcmp (func_0203EFC8).
 */

#ifndef NET_IRC_WIRELESS_H
#define NET_IRC_WIRELESS_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

/* The first 0x70 bytes are a copy of the caller's task header
 * (func_0203D8F0 copies it with `*(Base *)obj = *src`, 7 x ldm/stm of 16). */
struct NetIrcBase {
    u8    pad_00[0x18];
    void *fn_18;                 /* replaced by func_0203E420 (func_0203D8F0) */
    void *fn_1c;                 /* replaced by func_0203E458 */
    u8    pad_20[0x2C - 0x20];
    void *fn_2c;                 /* func_0203DC4C, or the saved +0x80 (DC70 state 9) */
    u8    pad_30[0x54 - 0x30];
    u16   heap;                  /* allocated low: (heap & 0x7FFF) | 0x8000 */
    u8    pad_56[0x60 - 0x56];
    u8    f60;                   /* 4 selects the parent path (DC70 states 3, 10) */
    u8    pad_61[3];
    u8    f64;                   /* saved to +0x104 and cleared (func_0203D8F0) */
    u8    f65;                   /* set to 3 by func_0203D8F0 and DC70 states 4/14 */
    u8    pad_66;
    u8    f67;
    u8    pad_68[0x6E - 0x68];
    u16   f6e;
};

/* The 0x10C-byte record func_0203D8F0 allocates and publishes. */
struct NetIrc {
    struct NetIrcBase base;          /* +0x00 */
    u32   arg;                       /* +0x70  callback argument */
    u32   f74;                       /* +0x74 */
    void *(*fn_78)(void *);          /* +0x78  saved base.fn_18 (func_0203E420 calls it) */
    void *(*fn_7c)(void *);          /* +0x7C  saved base.fn_1c (func_0203E458 calls it) */
    void *fn_80;                     /* +0x80  saved base.fn_2c */
    void (*f84)(u32 arg);            /* +0x84  func_0203DA7C installs 84/88/8C */
    void (*f88)(u32 arg, int flag);  /* +0x88 */
    void (*f8c)(u32 arg);            /* +0x8C */
    u32   slot_index;                /* +0x90  func_0203DAC4; also a 0x24-byte send buffer base */
    u8    mac[4][8];                 /* +0x94  four 6-byte MAC slots, stride 8 (DAC4, DBB0) */
    u8    pad_b4[0x100 - 0xB4];      /* +0xB4 receives 0x4C bytes in func_0203E420 */
    u8    timer;                     /* +0x100 counts down from 0xC8 */
    u8    f101;                      /* 1 blocks func_0203D8F0 */
    u8    f102;                      /* set by func_0203DC04 */
    u8    f103;                      /* set by func_0203DC4C */
    u8    f104;
    u8    f105;
    u8    f106;                      /* func_0203DC04: f105 = f106 - 1 */
    u8    f107;
    u8    retries;                   /* +0x108, limit 3 (DC70 state 18) */
    u8    state;                     /* +0x109, set by func_0203DC68 */
    u8    f10a;
    u8    f10b;
};

extern struct NetIrc *g_021469F0;   /* the live record, 0 when idle */

/* Matched members and their levers:
 *   func_0203D8F0  wrap a task header; the header parameter is `const`
 *   func_0203DAC4  register a MAC; `u8 buf[6] = {0,...}` in a block scope
 *   func_0203DC4C  callback: f103 = 1       (unlabelled ARM leaf)
 *   func_0203DC68  state setter              (unlabelled ARM leaf)
 *   func_0203DC70  the 19-state machine (src/pending, MATCH on two bogus
 *                  SDK rows at 0x0203CFF0 and 0x0203D000)
 *   func_0203E420  runs fn_78(arg), copies 0x4C bytes to +0xB4, returns +0x90;
 *                  it takes an argument (r0 is forwarded untouched)
 */

#endif /* NET_IRC_WIRELESS_H */
