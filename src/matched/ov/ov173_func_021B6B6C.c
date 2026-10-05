/*
 * function: func_021B6B6C
 * address: 0x021B6B6C
 * packet: pkt_ov173_021B6B6C
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 (final push G5L1): the byte store p[0x1ba] is written in each branch (4 / 3), not
 *   from one merged local after the join. The compiler merges the two stores itself, but then no
 *   longer derives 0x1b0 from the live 0x1ba register: it builds 0x1b0 fresh (movs 0x1b; lsls 4) as the original does.
 * symbols:
 *   func_021B7460 0x021B7460 thumb ov173
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021B7460(char *, u32);
int func_021B6B6C(char *p)
{
    if (*(u8 *)(*(char **)p + 0x1b) < 4) {
        func_021B7460(p, 10);
        p[0x1ba] = 4;
    } else {
        func_021B7460(p, 7);
        p[0x1ba] = 3;
    }
    *(u32 *)(p + 0x1b0) = 3;
    return 2;
}
