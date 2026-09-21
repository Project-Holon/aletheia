/*
 * function: func_0206A700
 * address:  0x0206A700
 * packet:   pkt_0206A700
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The 3D/rig register block init at data_02148B4C: sixteen pool constants
 * written into the block around three subsystem calls, then a second pass
 * over the 0xec..0x260 window after func_0207ADC4 returns.
 *
 * PINNED ../2.0/sp2 on the "kept constants" tell (docs/FRONTEND-PINS.md),
 * in both of its recorded forms at once. (a) The image RE-LOADS the block
 * base pool word 0x02148B4C THREE separate times -- `ldr r1, [pc, #0x108]`
 * at 0x0206A708, `ldr r1, [pc, #0xb4]` at 0x0206A75C and `ldr r0, [pc,
 * #0x44]` at 0x0206A7CC, all three resolving to the SINGLE pool word at
 * 0x0206A818 -- which is why the frame is a bare `push {r3, lr}`
 * (`08 40 2d e9`). (b) It materialises the f04 zero as its own `mov r0, #0`
 * (`00 00 a0 e3`) at 0x0206A70C and stores f00/f04 as two separate `str`.
 * dsi/1.1p1 -O4,p hoists the base into callee-saved r5 and CSEs the zero
 * into r4, needing `push {r3, r4, r5, lr}`, and then MERGES the f00/f04
 * pair into one `stm r5, {r0, r4}`: 312 bytes against the original's 340,
 * 247 concrete bytes out. Under the pin the same C is 340 bytes,
 * 0 mismatches, all 7 relocation sites resolving.
 *
 * symbols:
 *   data_02148B4C  0x02148B4C  data
 *   data_02148B54  0x02148B54  data
 *   data_02148B98  0x02148B98  data
 *   data_02148C08  0x02148C08  data
 *   func_0207B598  0x0207B598  arm
 *   func_0207BDB4  0x0207BDB4  arm
 *   func_0207ADC4  0x0207ADC4  arm
 */

typedef unsigned int u32;

extern u32 data_02148B4C[];
extern u32 data_02148B54[];
extern u32 data_02148B98[];
extern u32 data_02148C08[];

extern void func_0207B598(void *);
extern void func_0207BDB4(void *);
extern void func_0207ADC4(void *);

void func_0206A700(void)
{
    u32 *g = data_02148B4C;
    u32 a, b;

    g[0x00 / 4] = 0x17101610;
    g[0x04 / 4] = 0;
    g[0x48 / 4] = 2;
    g[0x7c / 4] = 0x32323232;
    g[0x90 / 4] = 0x60293130;
    g[0xa4 / 4] = 0x33333333;
    g[0xb8 / 4] = 0x002A1B19;
    func_0207B598(data_02148B98);
    func_0207BDB4(data_02148B54);

    a = 0x40000200;
    b = 0xC0080000;
    g = data_02148B4C;
    g[0x80 / 4] = 0x2D8B62D8;
    g[0x84 / 4] = a;
    g[0x88 / 4] = a + 0x3FFFFFFF;
    g[0x8c / 4] = b;
    g[0x94 / 4] = 0x4210C210;
    g[0x98 / 4] = 0x4210C210;
    g[0x9c / 4] = 0x001F008F;
    g[0xa0 / 4] = b - 0x90000;
    g[0xa8 / 4] = 0x00007FFF;
    g[0xac / 4] = 0x4000001F;
    g[0xb0 / 4] = 0x800003E0;
    g[0xb4 / 4] = 0x7e00 - a;
    g[0xe0 / 4] = 0;
    g[0xe4 / 4] = 0;
    g[0xe8 / 4] = 0;
    func_0207ADC4(data_02148C08);

    g = data_02148B4C;
    g[0xec / 4] = 0x1000;
    g[0xf0 / 4] = 0x1000;
    g[0xf4 / 4] = 0x1000;
    g[0xf8 / 4] = 0;
    g[0xfc / 4] = 0;
    g[0x248 / 4] = 0;
    g[0x244 / 4] = 0;
    g[0x240 / 4] = 0;
    g[0x254 / 4] = 0;
    g[0x24c / 4] = 0;
    g[0x250 / 4] = 0x1000;
    g[0x25c / 4] = 0;
    g[0x258 / 4] = 0;
    g[0x260 / 4] = (u32)-0x1000;
}
