/*
 * unit:     no
 * function: func_0202DBC4
 * address:  0x0202DBC4
 * packet:   pkt_0202DAA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Picks the selected entry of the 0x28-byte element array hung off +0xc:
 * the selection at +0x28 is primed to 1, then every element whose +0x18
 * bit 0 is set is offered to func_0202E0E0 along with the two cursor
 * words at +8 and +0x2c; the first one that answers non-zero resets the
 * selection to 0.  The count at +0x30 is a signed char and is re-read at
 * the top of every iteration (the call may change it), which is what
 * keeps the `adds r0, r5, #0x30; ldrb` pair inside the loop -- 0x30 is
 * past the Thumb `ldrb` immediate reach of +31.
 *
 * symbols:
 *   func_0202E0E0  0x0202E0E0  thumb
 */

typedef unsigned char u8;
typedef signed char   s8;
typedef unsigned int  u32;
typedef signed int    s32;

struct Ent { u32 pad[6]; u32 bit0 : 1; };

extern s32 func_0202E0E0(void *e, void *a1, u32 a2);

void func_0202DBC4(u8 *p)
{
    s32 i;

    *(u32 *)(p + 0x28) = 1;
    for (i = 0; i < (s32)*(u8 *)(p + 0x30); i++) {
        u8 *e = *(u8 **)(p + 0xc) + i * 0x28;
        if (((struct Ent *)e)->bit0 != 0) {
            if (func_0202E0E0(e, *(void **)(p + 8), *(u32 *)(p + 0x2c)) != 0) {
                *(u32 *)(p + 0x28) = 0;
            }
        }
    }
}
