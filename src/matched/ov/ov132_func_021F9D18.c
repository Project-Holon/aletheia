/*
 * function: func_021F9D18
 * address: 0x021F9D18
 * packet: pkt_ov132_021F9D18
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F8044 0x021F8044 thumb ov112
 *   func_021F9F74 0x021F9F74 thumb ov132
 *   func_020061E4 0x020061E4 thumb
 */
typedef unsigned char u8;
typedef struct { int x, y, z; } Vec;
extern void func_021F8044(void *, void *, Vec *);
extern void func_021F9F74(char *, unsigned, const int *);
extern void func_020061E4(int);
void func_021F9D18(char *p, unsigned i)
{
    Vec v;
    u8 j;
    func_021F8044(*(void **)(p + 0x40), *(void **)(p + i * 4 + 0x44), &v);
    v.x /= 16;
    v.y = (0xc0000 - (v.y - 0x20000)) / 16;
    v.z = 0xb4000;
    for (j = 0; j < 3; j++) func_021F9F74(*(char **)(p + 0xbc), j, &v.x);
    func_020061E4(1961);
}
