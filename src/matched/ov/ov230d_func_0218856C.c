/*
 * function: OV230_CheckStubSignature1
 * address:  0x0218856C
 * packet:   pkt_ov230d_0218856C
 * region:   ov230d
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     from src/game/ov230/sealed_checks_signature.c (decrypted view of overlay 230, region ov230d)
 * symbols:
 *   OV230_CheckStubSignature0  0x02188450  arm  ov230d
 *   OV230_CheckStubSignature1  0x0218856C  arm  ov230d
 *   OV230_CheckStubSignature2  0x02188688  arm  ov230d
 *   OV230_CheckStubSignature3  0x021887A4  arm  ov230d
 *   OV230_CallSealedBody10  0x02188E3C  arm  ov230d
 *   OV230_CallSealedBody11  0x02188E78  arm  ov230d
 *   OV230_CallSealedBody14  0x02189340  arm  ov230d
 *   OV230_CallSealedBody15  0x0218937C  arm  ov230d
 */
typedef unsigned int u32;
typedef unsigned char u8;

extern u8 OV230_CallSealedBody10[];
extern u8 OV230_CallSealedBody11[];
extern u8 OV230_CallSealedBody14[];
extern u8 OV230_CallSealedBody15[];

u32 OV230_CheckStubSignature1(void)
{
    const u8 *p = (const u8 *)((u32)&OV230_CallSealedBody11[0x1600] - 0x2C00) + 0x1000;

    if (p[0x600] != 0xF) {
        return 0xB5B1;
    }
    if (p[0x601] != 0xC0) {
        return 0xB5B1;
    }
    if (p[0x602] != 0x8F) {
        return 0xB5B1;
    }
    if (p[0x603] != 0xE1) {
        return 0xB5B1;
    }
    if (p[0x604] != 0xC) {
        return 0xB5B1;
    }
    if (p[0x605] != 0xC0) {
        return 0xB5B1;
    }
    if (p[0x606] != 0x1C) {
        return 0xB5B1;
    }
    if (p[0x607] != 0xE0) {
        return 0xB5B1;
    }
    if (p[0x608] != 0x0) {
        return 0xB5B1;
    }
    if (p[0x609] != 0xC0) {
        return 0xB5B1;
    }
    if (p[0x60A] != 0xA0) {
        return 0xB5B1;
    }
    if (p[0x60B] != 0x3) {
        return 0xB5B1;
    }
    if (p[0x60C] != 0x1C) {
        return 0xB5B1;
    }
    if (p[0x60D] != 0xC0) {
        return 0xB5B1;
    }
    if (p[0x60E] != 0x8C) {
        return 0xB5B1;
    }
    if (p[0x60F] != 0x12) {
        return 0xB5B1;
    }
    return 0xBD3B;
}
