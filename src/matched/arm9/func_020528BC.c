/*
 * function: func_020528BC
 * address:  0x020528BC
 * packet:   pkt_020526A8
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02052984  0x02052984  arm
 *   func_02052F90  0x02052F90  arm
 *
 * Twin of src/matched/func_020528A8.c, same twelve bytes by position: forward
 * r0 to 0x02052984 with the address of func_02052F90 as the second argument.
 * Same 1.2 pin and same tail-call schedule tell.
 *
 * The callback site resolves through the `matched` class once
 * src/matched/func_02052F90.c is in the manifest.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020528BC.c \
 *       --func func_020528BC --addr 0x020528BC --arm --cc ../1.2/sp2
 */

typedef unsigned int u32;

extern void func_02052984(u32 a0, void *cb);
extern void func_02052F90(void);

void func_020528BC(u32 a0)
{
    func_02052984(a0, (void *)func_02052F90);
}
