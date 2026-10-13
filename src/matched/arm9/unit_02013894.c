/*
 * unit:     yes
 * function: BTL_SETUP_SetupCommRotation
 * address:  0x02013894
 * packet:   pkt_02013528
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SETUP_SetupComm     0x02013528  thumb
  *   func_0203D1A4     0x0203D1A4  arm
 *
 * The id-3 member of the same family - byte for byte BTL_SETUP_SetupCommSingle with a 3
 * where it has a 0 (the third argument of BTL_SETUP_SetupComm).

 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupCommRotation.c \
 *       --func BTL_SETUP_SetupCommRotation --addr 0x02013894 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void BTL_SETUP_SetupComm(u32 p0, u32 p1, u32 id, u32 b, u32 c, u32 d, u32 e, u32 f);
struct Link;
extern u32 func_0203D1A4(struct Link *p);
void BTL_SETUP_SetupCommRotation(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4)
{
    u32 r = func_0203D1A4((struct Link *)p2);

    BTL_SETUP_SetupComm(p0, p1, 3, 0, p2, p3, r, p4);
}

