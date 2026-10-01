/*
 * function: func_021C5680
 * address: 0x021C5680
 * packet: pkt_ov127_021C5680
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C58C8 0x021C58C8 thumb ov127
 *   func_021C49A4 0x021C49A4 thumb ov127
 *   func_021C5878 0x021C5878 thumb ov127
 *   func_021C40BC 0x021C40BC thumb ov127
 *   func_021C574C 0x021C574C thumb ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u8 *func_021C58C8(void *);
extern int func_021C49A4(void *, unsigned int);
extern int func_021C5878(int, int);
extern void *func_021C40BC(void *, s16 *, int, u32);
extern void func_021C574C(void *);
u8 *func_021C5680(u8 *p, void *q, int n, u32 heap)
{
    u8 *o = func_021C58C8(p);
    s16 pos[4];
    *(u16 *)(o+8) = func_021C49A4(q, 5);
    *(u16 *)(o+10) = func_021C49A4(q, 6);
    *(u16 *)(o+12) = func_021C49A4(q, 4);
    *(void **)o = q;
    o[18] = n;
    o[19] = 1;
    *(u16 *)(o+14) = 0;
    *(u16 *)(o+16) = 0;
    pos[0] = func_021C49A4(q, 0);
    pos[1] = func_021C49A4(q, 1);
    pos[2] = func_021C5878(pos[1], o[18]);
    pos[3] = p[10];
    *(void **)(o+4) = func_021C40BC(*(void **)p, pos, func_021C49A4(q, 7), heap);
    func_021C574C(o);
    return o;
}
