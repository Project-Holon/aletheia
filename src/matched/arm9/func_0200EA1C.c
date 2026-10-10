/*
 * function: func_0200EA1C
 * address: 0x0200EA1C
 * packet: pkt_arm9_0200EA1C
 * region: arm9
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/arm9/unit_0200E44C.c and filed here.
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 */

extern void MI_CpuFill8(void *dst, unsigned char val, unsigned long size);
void func_0200EA1C(void *p);

void func_0200EA1C(void *p)
{
    MI_CpuFill8(p, 0, 0x155C);
}
