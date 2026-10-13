/*
 * function: FIELD_MSGBG_MakeListHeader
 * address:  0x02190B2C
 * packet:   pkt_ov021_02190B2C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Src {
    u16 a00;
    u16 a02;
    u8  a04;
    u8  a05;
    u8  a06;
    u8  a07lo : 4;
    u8  a07hi : 4;
    u8  a08lo : 4;
    u8  a08hi : 4;
    u8  pad09;
    u16 a0a_lo : 3;
    u16 a0a_mid : 4;
    u16 a0a_hi : 9;
    int a0c : 2;
    int pad0c : 30;
    u16 a10;
    u16 a12;
    u8  pad14[8];
    u32 a1c;
} Src;

typedef struct Dst {
    u8  pad00[8];
    u32 d08;
    u8  pad0c[4];
    u16 d10;
    u16 d12;
    u8  d14;
    u8  d15;
    u8  d16;
    u8  d17lo : 4;
    u8  d17hi : 4;
    u8  d18lo : 4;
    u8  d18hi : 4;
    u8  pad19;
    u16 d1a_lo : 3;
    u16 d1a_mid : 4;
    u16 d1a_z : 2;
    u16 d1a_hi : 7;
    u8  pad1c[4];
    u16 d20;
    u16 d22;
} Dst;

extern void func_02082BCC(void *p, int v, int n);

void FIELD_MSGBG_MakeListHeader(Dst *d, const Src *s)
{
    func_02082BCC(d, 0, 0x34);
    d->d10 = s->a00;
    d->d12 = s->a02;
    d->d14 = s->a04;
    d->d15 = s->a05;
    d->d16 = s->a06;
    d->d17lo = s->a07lo;
    d->d17hi = s->a07hi;
    d->d18lo = s->a08lo;
    d->d18hi = s->a08hi;
    d->d1a_lo = s->a0a_lo;
    d->d1a_mid = s->a0a_mid;
    d->d1a_z = s->a0c;
    d->d20 = s->a10;
    d->d22 = s->a12;
    d->d08 = s->a1c;
}
