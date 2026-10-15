/*
 * function: DEMO3D_DATA_FadeSeVolume
 * address:  0x021BEC3C
 * packet:   pkt_021BEC3C
 * region:   ov203
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DEMO3D_DATA_CreateSeFade 0x021BECA8 thumb
 */

typedef unsigned short u16;
typedef unsigned char  u8;
struct Owner;
extern void DEMO3D_DATA_CreateSeFade(struct Owner *owner, u8 kind, u16 target, int start, int end, int duration, int flag);

void DEMO3D_DATA_FadeSeVolume(int a0, int a1, int *src)
{
    DEMO3D_DATA_CreateSeFade((struct Owner *)a0, 0, (unsigned short)src[0], src[1], src[2], src[3], src[4]);
}
