/*
 * function: func_021B98F0
 * address:  0x021B98F0
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 *
 * symbols:
 *   func_021B9FD0  0x021B9FD0  thumb
 * Tail call thunk onto func_021B9FD0.
 *
 * NOT EXACT.  MATCH: the 4 bytes and the pool word are right, but the target
 * 0x021B9FD0 is not a traced function label of ov099's listing -- the words at
 * 0x021B9FD0 (`ldr r0, [r0, #0x2c]` / `ldr r3, [pc, #4]` / `movs r1, #0` /
 * `bx r3`) are emitted as data, so nothing attests the address and the ABS32
 * stays wildcarded.  It turns EXACT the moment 0x021B9FD0 becomes a label.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_021B98F0.c --func func_021B98F0 --addr 0x021B98F0 \n    --region ov099 --thumb --cc dsi/1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void func_021B9FD0(void *a);

void func_021B98F0(void *a)
{
    func_021B9FD0(a);
}
