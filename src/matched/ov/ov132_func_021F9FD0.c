/*
 * function: func_021F9FD0
 * address:  0x021F9FD0
 * packet:   pkt_021F9FD0
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BUTTON_MAN_SetEmitterPos  0x02051838  arm
 *
 * Addresses are Black-image addresses.
 */

extern void BUTTON_MAN_SetEmitterPos(void *, int);

void func_021F9FD0(char *p, int i, int a)
{
    void *v = *(void **)(p + i * 16 + 0x4808);

    if (v != 0)
        BUTTON_MAN_SetEmitterPos(v, a);
}
