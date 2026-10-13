/*
 * unit:     no
 * address:  0x020314B8
 * packet:   pkt_02031324
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: PROCSYS_DeleteInternal
 *
 * symbols:
 *   ENV_SetResourceSet  0x020307B0  arm
 *   OS_Halt       0x020882D0  arm
 *
 * Frees an owned sub-object at +8 if present, then re-registers the object
 * itself with ENV_SetResourceSet. The same shutdown/re-init shape as
 * TCBL_Destroy and PROCSYS_FreeProcWork in the neighbouring packets, all working
 * the TwlSDK ENV resource-set table.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PROCSYS_DeleteInternal.c \
 *       --func PROCSYS_DeleteInternal --addr 0x020314B8 --cc 1.1p1
 */

struct S020314B8 {
    char  pad[8];
    void *field8;
};

extern void OS_Halt(void *p);
extern void ENV_SetResourceSet(void *p);

void PROCSYS_DeleteInternal(struct S020314B8 *p)
{
    if (p->field8 != 0) {
        OS_Halt(p->field8);
    }
    ENV_SetResourceSet(p);
}
