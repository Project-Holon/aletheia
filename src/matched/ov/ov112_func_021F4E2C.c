/*
 * function: func_021F4E2C
 * address: 0x021F4E2C
 * packet: pkt_ov112_021F4E2C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Three-shift single-bit extraction is a halfword bitfield copy.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct { u16 a:2; u16 flag:1; u16 b:13; } Flags;
void func_021F4E2C(void *unused, u8 *s, u8 *d)
{
    *(int *)(d + 16) = *(int *)(s + 16) + 8192;
    *(int *)(d + 20) = *(int *)(s + 20) + 8192;
    *(int *)(d + 24) = *(int *)(s + 24) - 2048;
    *(s16 *)(d + 28) = *(s16 *)(s + 28);
    *(s16 *)(d + 30) = *(s16 *)(s + 30);
    *(u16 *)(d + 2) = *(u16 *)(s + 2);
    ((Flags *)d)->flag = ((Flags *)s)->flag;
}
