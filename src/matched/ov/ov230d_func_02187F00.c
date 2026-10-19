/*
 * function: OV230_IntegrityChain0
 * address:  0x02187F00
 * packet:   pkt_ov230d_02187F00
 * region:   ov230d
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     from src/game/ov230/sealed_checks_chain.c (decrypted view of overlay 230, region ov230d)
 * symbols:
 *   OV230_IntegrityChain0  0x02187F00  arm  ov230d
 *   OV230_IntegrityChain1  0x02187FA0  arm  ov230d
 *   OV230_IntegrityChain2  0x02188040  arm  ov230d
 *   OV230_IntegrityChain3  0x021880E0  arm  ov230d
 *   OV230_IntegrityChain4  0x02188180  arm  ov230d
 *   OV230_IntegrityChain5  0x02188210  arm  ov230d
 *   OV230_CallSealedBody6  0x021888C0  arm  ov230d
 *   OV230_CallSealedBody7  0x021888FC  arm  ov230d
 *   OV230_CallSealedBody8  0x02188938  arm  ov230d
 *   OV230_CallSealedBody9  0x02188974  arm  ov230d
 *   OV230_CallSealedBody10  0x02188E3C  arm  ov230d
 *   OV230_CallSealedBody11  0x02188E78  arm  ov230d
 *   OV230_CallSealedBody14  0x02189340  arm  ov230d
 *   OV230_CallSealedBody15  0x0218937C  arm  ov230d
 *   OV230_CallSealedBody16  0x021893D0  arm  ov230d
 *   OV230_CallSealedBody17  0x0218940C  arm  ov230d
 */
typedef unsigned int u32;
typedef unsigned char u8;

extern u8 OV230_CallSealedBody6[];
extern u8 OV230_CallSealedBody7[];
extern u8 OV230_CallSealedBody8[];
extern u8 OV230_CallSealedBody9[];
extern u8 OV230_CallSealedBody10[];
extern u8 OV230_CallSealedBody11[];
extern u8 OV230_CallSealedBody14[];
extern u8 OV230_CallSealedBody15[];
extern u8 OV230_CallSealedBody16[];
extern u8 OV230_CallSealedBody17[];

u32 OV230_IntegrityChain0(u32 (*onFail)(u32), u32 arg)
{
    u32 table[32];
    u32 *p;
    u32 sum;

    table[2] = 0;
    table[0] = (u32)&OV230_CallSealedBody14[0x1600] + 0x320;
    table[1] = (u32)&OV230_CallSealedBody8[0x1600] + 0x320;
    sum = 0x30EB87;
    p = table;
    do {
        sum += ((u32 (*)(void))(*p - 0x1920))();
    } while (*++p != 0);
    if (sum % 241 != 0) {
        sum = onFail(arg);
    }
    return sum;
}
