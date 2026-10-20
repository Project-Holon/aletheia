/*
 * file:     sealed_checks_chain.c
 * unit:     yes
 * function: OV230_IntegrityChain0, OV230_IntegrityChain1, OV230_IntegrityChain2, OV230_IntegrityChain3, OV230_IntegrityChain4, OV230_IntegrityChain5
 * address:  0x02187F00
 * region:   ov230d
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Second-layer bodies of overlay 230 (region ov230d, opened by tools/ovcrypt.py): the six chain checks. Each one calls
 * the sealed checks named in its table through their call stubs, adds up their results and tests the sum against a
 * modulus (241 or 251). A sum that fails the test makes the check call the function it was given and return that
 * function's result; otherwise the sum is the result. A table address is a stub address plus the parameter-block bias
 * 0x1600 and the obfuscation offset 0x320, undone at call time. The bodies run through OV230_CallDispatcher, so the
 * caller of a stub passes (hook, hookArg).
 *
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
#include "../types.h"

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

u32 OV230_IntegrityChain0(u32 (*hook)(u32), u32 hookArg)
{
    u32 table[32];
    u32 *p;
    u32 sum;

    table[2] = 0;
    table[0] = (uptr)&OV230_CallSealedBody14[0x1600] + 0x320;
    table[1] = (uptr)&OV230_CallSealedBody8[0x1600] + 0x320;
    sum = 0x30EB87;
    p = table;
    do {
        sum += ((u32 (*)(void))(*p - 0x1920))();
    } while (*++p != 0);
    if (sum % 241 != 0) {
        sum = hook(hookArg);
    }
    return sum;
}

u32 OV230_IntegrityChain1(u32 (*hook)(u32), u32 hookArg)
{
    u32 table[32];
    u32 *p;
    u32 sum;

    table[2] = 0;
    table[0] = (uptr)&OV230_CallSealedBody15[0x1600] + 0x320;
    table[1] = (uptr)&OV230_CallSealedBody9[0x1600] + 0x320;
    sum = 0x30EB87;
    p = table;
    do {
        sum += ((u32 (*)(void))(*p - 0x1920))();
    } while (*++p != 0);
    if (sum % 251 == 0) {
        sum = hook(hookArg);
    }
    return sum;
}

u32 OV230_IntegrityChain2(u32 (*hook)(u32), u32 hookArg)
{
    u32 table[32];
    u32 *p;
    u32 sum;

    table[2] = 0;
    table[0] = (uptr)&OV230_CallSealedBody10[0x1600] + 0x320;
    table[1] = (uptr)&OV230_CallSealedBody6[0x1600] + 0x320;
    sum = 0x30EB87;
    p = table;
    do {
        sum += ((u32 (*)(void))(*p - 0x1920))();
    } while (*++p != 0);
    if (sum % 241 != 0) {
        sum = hook(hookArg);
    }
    return sum;
}

u32 OV230_IntegrityChain3(u32 (*hook)(u32), u32 hookArg)
{
    u32 table[32];
    u32 *p;
    u32 sum;

    table[2] = 0;
    table[0] = (uptr)&OV230_CallSealedBody11[0x1600] + 0x320;
    table[1] = (uptr)&OV230_CallSealedBody7[0x1600] + 0x320;
    sum = 0x30EB87;
    p = table;
    do {
        sum += ((u32 (*)(void))(*p - 0x1920))();
    } while (*++p != 0);
    if (sum % 251 == 0) {
        sum = hook(hookArg);
    }
    return sum;
}

u32 OV230_IntegrityChain4(u32 (*hook)(u32), u32 hookArg)
{
    u32 table[32];
    u32 *p;
    u32 sum;

    table[0] = (uptr)&OV230_CallSealedBody16[0x1600] + 0x320;
    table[1] = 0;
    sum = 0x30EB87;
    p = table;
    do {
        sum += ((u32 (*)(void))(*p - 0x1920))();
    } while (*++p != 0);
    if (sum % 241 != 0) {
        sum = hook(hookArg);
    }
    return sum;
}

u32 OV230_IntegrityChain5(u32 (*hook)(u32), u32 hookArg)
{
    u32 table[32];
    u32 *p;
    u32 sum;

    table[0] = (uptr)&OV230_CallSealedBody17[0x1600] + 0x320;
    table[1] = 0;
    sum = 0x30EB87;
    p = table;
    do {
        sum += ((u32 (*)(void))(*p - 0x1920))();
    } while (*++p != 0);
    if (sum % 251 == 0) {
        sum = hook(hookArg);
    }
    return sum;
}
