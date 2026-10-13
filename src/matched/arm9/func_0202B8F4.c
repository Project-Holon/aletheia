/*
 * function: ISS_3DS_SYS_Update
 * address:  0x0202B8F4
 * packet:   pkt_0202B7BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * Artifact, not C: 0x0202B8F4 is a four-byte linker veneer
 * (`00 4b 18 47` = ldr r3, [pc, #0]; bx r3; .word 0x0202BAF5) sitting in a
 * run of identical veneers at 0x0202B8F4/0x0202B8FC/0x0202B904/0x0202B90C.
 * No C spelling produces this shape; reported in
 * docs/notes/pkt_0202B7BC.ISS_3DS_SYS_Update.c.txt and left parked.
 *
 * A bare tail-call thunk to func_0202BAF4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_3DS_SYS_Update.c \
 *       --func ISS_3DS_SYS_Update --addr 0x0202B8F4 --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
extern void func_0202BAF4(u8 *o);

void ISS_3DS_SYS_Update(u8 *a0)
{
    func_0202BAF4(a0);
}
