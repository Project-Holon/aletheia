/*
 * function: BTLV_EFFECT_FreeTaskArg
 * address:  0x021F9028
 * packet:   pkt_ov094_021F9028
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: the listing extent includes two bytes of trailing alignment padding.
 *
 * Frees the buffer at 0x10 of the current task's work, if any.
 *
 * symbols:
 *   TCBL_GetTaskUserData 0x02030EE8 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned int   u32;
struct S02030EE8;
extern u32 TCBL_GetTaskUserData(struct S02030EE8 *p);
extern u32 func_020307B0(void *p);

void BTLV_EFFECT_FreeTaskArg(void *h)
{
    void *p = *(void **)(TCBL_GetTaskUserData(h) + 0x10);
    if (p != 0)
        func_020307B0(p);
}
