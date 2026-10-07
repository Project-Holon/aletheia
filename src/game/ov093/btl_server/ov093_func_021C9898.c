/*
 * function: func_021C9898
 * address: 0x021C9898
 * packet: pkt_ov093_021C9898
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of trailing alignment padding.
 * symbols:
 *   func_021C3C60 0x021C3C60 thumb ov093
 *   func_021C99A0 0x021C99A0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { int x; } S;
struct Msg;
extern int func_021C3C60(u8 *, int, S, int);
extern int func_021C99A0(void *, const struct Msg *);
int func_021C9898(u8 *p, u8 *q)
{
    if (func_021C3C60(p, *(int *)(q + 4), *(S *)(q + 8), q[12])) {
        func_021C99A0(p, (const struct Msg *)(q + 16));
        return 1;
    }
    return 0;
}
