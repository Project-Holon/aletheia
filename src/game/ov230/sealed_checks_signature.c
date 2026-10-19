/*
 * file:     sealed_checks_signature.c
 * unit:     yes
 * function: OV230_CheckStubSignature0, OV230_CheckStubSignature1, OV230_CheckStubSignature2, OV230_CheckStubSignature3
 * address:  0x02188450
 * region:   ov230d
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Second-layer bodies of overlay 230 (region ov230d, opened by tools/ovcrypt.py): four checks that the first 16 bytes
 * of a call stub are still the stub template (orr ip, pc, pc; ands ip, ip, ip; moveq ip, #0; addne ip, ip, #0x1c).
 * The result is one of two tags, which the chain checks add up: 0xB5B1 and 0xBD3B swap roles between the checks.
 * The stub address is held as the stub plus the parameter-block bias 0x1600.
 *
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

u32 OV230_CheckStubSignature0(void)
{
    const u8 *p = (const u8 *)((u32)&OV230_CallSealedBody10[0x1600] - 0x2C00) + 0x1000;

    if (p[0x600] != 0xF) {
        return 0xBD3B;
    }
    if (p[0x601] != 0xC0) {
        return 0xBD3B;
    }
    if (p[0x602] != 0x8F) {
        return 0xBD3B;
    }
    if (p[0x603] != 0xE1) {
        return 0xBD3B;
    }
    if (p[0x604] != 0xC) {
        return 0xBD3B;
    }
    if (p[0x605] != 0xC0) {
        return 0xBD3B;
    }
    if (p[0x606] != 0x1C) {
        return 0xBD3B;
    }
    if (p[0x607] != 0xE0) {
        return 0xBD3B;
    }
    if (p[0x608] != 0x0) {
        return 0xBD3B;
    }
    if (p[0x609] != 0xC0) {
        return 0xBD3B;
    }
    if (p[0x60A] != 0xA0) {
        return 0xBD3B;
    }
    if (p[0x60B] != 0x3) {
        return 0xBD3B;
    }
    if (p[0x60C] != 0x1C) {
        return 0xBD3B;
    }
    if (p[0x60D] != 0xC0) {
        return 0xBD3B;
    }
    if (p[0x60E] != 0x8C) {
        return 0xBD3B;
    }
    if (p[0x60F] != 0x12) {
        return 0xBD3B;
    }
    return 0xB5B1;
}

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

u32 OV230_CheckStubSignature2(void)
{
    const u8 *p = (const u8 *)((u32)&OV230_CallSealedBody14[0x1600] - 0x2C00) + 0x1000;

    if (p[0x600] != 0xF) {
        return 0xBD3B;
    }
    if (p[0x601] != 0xC0) {
        return 0xBD3B;
    }
    if (p[0x602] != 0x8F) {
        return 0xBD3B;
    }
    if (p[0x603] != 0xE1) {
        return 0xBD3B;
    }
    if (p[0x604] != 0xC) {
        return 0xBD3B;
    }
    if (p[0x605] != 0xC0) {
        return 0xBD3B;
    }
    if (p[0x606] != 0x1C) {
        return 0xBD3B;
    }
    if (p[0x607] != 0xE0) {
        return 0xBD3B;
    }
    if (p[0x608] != 0x0) {
        return 0xBD3B;
    }
    if (p[0x609] != 0xC0) {
        return 0xBD3B;
    }
    if (p[0x60A] != 0xA0) {
        return 0xBD3B;
    }
    if (p[0x60B] != 0x3) {
        return 0xBD3B;
    }
    if (p[0x60C] != 0x1C) {
        return 0xBD3B;
    }
    if (p[0x60D] != 0xC0) {
        return 0xBD3B;
    }
    if (p[0x60E] != 0x8C) {
        return 0xBD3B;
    }
    if (p[0x60F] != 0x12) {
        return 0xBD3B;
    }
    return 0xB5B1;
}

u32 OV230_CheckStubSignature3(void)
{
    const u8 *p = (const u8 *)((u32)&OV230_CallSealedBody15[0x1600] - 0x2C00) + 0x1000;

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
