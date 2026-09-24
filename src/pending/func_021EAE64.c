/*
 * function: func_021EAE64
 * address:  0x021EAE64
 * packet:   pkt_021EAE64
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_021EAE64   0x021EAE64  thumb  ov093
 *   func_0689B790   0x0689B790  thumb  ov095
 *
 * Blocking site: the ABS32 pool word at +000C names 0x0689B790, which is a
 * function start in no listing at all and whose address is held by two overlays
 * (ov093, ov170), so nothing attests it and the field stays wildcarded; the entry
 * cannot reach EXACT and the region token does not help.  Every concrete byte
 * matches.  Rule 10 clears it: file 0x0689B790 first and this call site
 * attests with no header change.
 *
 * Indexed-dispatch thunk, o18's 23-member shape: void func_021EAE64(E64 *p) { func_0689B790(p[0x6].f0); }
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

typedef struct { u32 f0; u8 pad[60]; } E64;

void func_021EAE64(E64 *p) { func_0689B790(p[0x6].f0); }
