/*
 * function: SPL_EMITTER_AllocTexVramDefault
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
 *   SPL_EMITTER_AllocTexVramList  0x02052984  arm
 *   SPL_EMITTER_AllocTexVram  0x02052F90  arm
 *
 * Twin of src/matched/SPL_EMITTER_AllocPlttVramDefault.c, same twelve bytes by position: forward
 * r0 to 0x02052984 with the address of SPL_EMITTER_AllocTexVram as the second argument.
 * Same 1.2 pin and same tail-call schedule tell.
 *
 * The callback site resolves through the `matched` class once
 * src/matched/SPL_EMITTER_AllocTexVram.c is in the manifest.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SPL_EMITTER_AllocTexVramDefault.c \
 *       --func SPL_EMITTER_AllocTexVramDefault --addr 0x020528BC --arm --cc ../1.2/sp2
 */

typedef unsigned int u32;

extern void SPL_EMITTER_AllocTexVramList(u32 a0, void *cb);
extern int SPL_EMITTER_AllocTexVram(u32 a0, u32 a1);

void SPL_EMITTER_AllocTexVramDefault(u32 a0)
{
    SPL_EMITTER_AllocTexVramList(a0, (void *)SPL_EMITTER_AllocTexVram);
}
