/*
 * function: func_021F9028
 * address:  0x021F9028
 * packet:   pkt_ov094_021F9028
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Frees the buffer at 0x10 of the current task's work, if any.
 *
 * symbols:
 *   func_02030EE8 0x02030EE8 arm
 *   func_020307B0 0x020307B0 arm
 */
extern char *func_02030EE8(void);
extern void func_020307B0(void *);

void func_021F9028(void)
{
    void *p = *(void **)(func_02030EE8() + 0x10);
    if (p != 0)
        func_020307B0(p);
}
