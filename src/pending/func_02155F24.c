/*
 * function: func_02155F24
 * address:  0x02155F24
 * packet:   pkt_02155F24
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocker:  compiled 38 bytes; every concrete byte reproduces and the two
 * trailing bytes of the 40-byte listing extent (0x02155F4A `movs r0,r0`)
 * are alignment padding.  The single unresolved relocation is the bl at
 * +0018 to 0x021FD904: four overlays overlap that address (ov094, ov132,
 * ov135, ov186) and none carries a func_ label there, so no evidence class
 * can attest it without a region hint the file cannot honestly supply.
 *
 * symbols:
 *   func_021F675C  0x021F675C  thumb
 *   func_021FD904  0x021FD904  thumb
 *   func_021FD938  0x021FD938  thumb
 */

extern int func_021F675C(int, int);
extern void func_021FD904(int);
extern void func_021FD938(int);

void func_02155F24(int *p)
{
    *(int *)((char *)p + 0x3c) = func_021F675C(*(int *)((char *)p + 0x18), 4);
    if (*(int *)((char *)p + 0x14) != 0) {
        func_021FD904(*(int *)(*(int *)((char *)p + 8) + 4));
        func_021FD938(*(int *)(*(int *)((char *)p + 8) + 4));
    }
}
