/*
 * function: func_02186988
 * address: 0x02186988
 * packet: pkt_ov023_02186988
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef struct { u8 b[4]; u8 lo:3; u8 mid:3; u8 hi:2; u8 b5; } Rec;
typedef struct { Rec r[5]; } Grp;
void func_02186988(Rec *s, char *p, int i)
{
    ((Grp *)p)[*(int *)(p + 0xBBC)].r[i] = *s;
}
