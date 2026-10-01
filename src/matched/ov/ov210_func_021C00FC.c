/*
 * function: func_021C00FC
 * address: 0x021C00FC
 * packet: pkt_ov210_021C00FC
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 02035C60 returns live r0 from 02035C48/020357C0; caller compares result at 021C0118, overriding matched void declaration.
 * symbols:
 *   func_02035C60 0x02035C60 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020362DC 0x020362DC arm
 */
extern int func_02035C60(void);
extern void func_020355D8(unsigned);
extern unsigned func_020362DC(void);
int func_021C00FC(unsigned char *ctx)
{
    if (ctx[0x2bb] == 90) {
        ctx[0x2bb] = 0;
        return 1;
    }
    ctx[0x2bb]++;
    if (func_02035C60()) {
        func_020355D8(1);
        ctx[0x2bb] = 0;
        return 1;
    }
    if (func_020362DC() & 3) {
        func_020355D8(0);
        ctx[0x2bb] = 0;
        return 1;
    }
    return 0;
}
