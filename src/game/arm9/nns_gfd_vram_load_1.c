/*
 * file:     nns_gfd_vram_load_1.c
 * unit:     yes
 * function: NNSi_GfdLoadMainObjExtPltt, NNSi_GfdLoadMainBgExtPltt, NNSi_GfdLoadMainOam, NNSi_GfdLoadMainObjChar, NNSi_GfdLoadSubBg0Char, NNSi_GfdLoadSubBg1Char, NNSi_GfdLoadSubBg2Char, NNSi_GfdLoadSubBg3Char, NNSi_GfdLoadSubBg0Scr, NNSi_GfdLoadSubBg1Scr, NNSi_GfdLoadSubBg2Scr, NNSi_GfdLoadSubBg3Scr, NNSi_GfdLoadSubBg2ScrAffine, NNSi_GfdLoadSubBg3ScrAffine, NNSi_GfdLoadSubObjPltt, NNSi_GfdLoadSubBgPltt
 * address:  0x020619BC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned int u32;

extern void func_0207F47C(void);
extern void func_0207F4C4(const void *pSrc, u32 offset, u32 szByte);
extern void func_0207F560(void);
extern void func_0207F308(void);
extern void func_0207F394(const void *pSrc, u32 offset, u32 szByte);
extern void func_0207F428(void);
void NNSi_GfdLoadMainObjExtPltt(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadMainBgExtPltt(const void *pSrc, u32 offset, u32 szByte);
extern void func_0207E684(const void *pSrc, u32 offset, u32 szByte);
extern void func_0207E780(const void *pSrc, u32 offset, u32 szByte);
extern void func_0207EEFC(const void *pSrc, u32 offset, u32 szByte);
extern void func_0207F024(const void *pSrc, u32 offset, u32 szByte);
extern void func_0207F14C(const void *pSrc, u32 offset, u32 szByte);
extern void func_0207F274(const void *pSrc, u32 offset, u32 szByte);
extern void func_0207E944(const void *pSrc, u32 offset, u32 szByte);
extern void func_0207EABC(const void *pSrc, u32 offset, u32 szByte);
extern void func_0207EC34(const void *pSrc, u32 offset, u32 szByte);
extern void func_0207EDAC(const void *pSrc, u32 offset, u32 szByte);
extern void func_0207EC34(const void *pSrc, u32 offset, u32 szByte);
extern void func_0207EDAC(const void *pSrc, u32 offset, u32 szByte);
extern void func_0207E5D0(const void *pSrc, u32 offset, u32 szByte);
extern void func_0207E468(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadMainOam(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadMainObjChar(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubBg0Char(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubBg1Char(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubBg2Char(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubBg3Char(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubBg0Scr(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubBg1Scr(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubBg2Scr(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubBg3Scr(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubBg2ScrAffine(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubBg3ScrAffine(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubObjPltt(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubBgPltt(const void *pSrc, u32 offset, u32 szByte);


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_GfdLoadMainObjExtPltt.c \
 *       --func NNSi_GfdLoadMainObjExtPltt --addr 0x020619BC --arm --cc 1.1p1
 */
void NNSi_GfdLoadMainObjExtPltt(const void *pSrc, u32 offset, u32 szByte)
{
    func_0207F47C();
    func_0207F4C4(pSrc, offset, szByte);
    func_0207F560();
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_GfdLoadMainBgExtPltt.c \
 *       --func NNSi_GfdLoadMainBgExtPltt --addr 0x020619E8 --arm --cc 1.1p1
 */
void NNSi_GfdLoadMainBgExtPltt(const void *pSrc, u32 offset, u32 szByte)
{
    func_0207F308();
    func_0207F394(pSrc, offset, szByte);
    func_0207F428();
}


void NNSi_GfdLoadMainOam(const void *pSrc, u32 offset, u32 szByte)
{
    func_0207E684(pSrc, offset, szByte);
}


void NNSi_GfdLoadMainObjChar(const void *pSrc, u32 offset, u32 szByte)
{
    func_0207E780(pSrc, offset, szByte);
}


void NNSi_GfdLoadSubBg0Char(const void *pSrc, u32 offset, u32 szByte)
{
    func_0207EEFC(pSrc, offset, szByte);
}


void NNSi_GfdLoadSubBg1Char(const void *pSrc, u32 offset, u32 szByte)
{
    func_0207F024(pSrc, offset, szByte);
}


void NNSi_GfdLoadSubBg2Char(const void *pSrc, u32 offset, u32 szByte)
{
    func_0207F14C(pSrc, offset, szByte);
}


void NNSi_GfdLoadSubBg3Char(const void *pSrc, u32 offset, u32 szByte)
{
    func_0207F274(pSrc, offset, szByte);
}


void NNSi_GfdLoadSubBg0Scr(const void *pSrc, u32 offset, u32 szByte)
{
    func_0207E944(pSrc, offset, szByte);
}


void NNSi_GfdLoadSubBg1Scr(const void *pSrc, u32 offset, u32 szByte)
{
    func_0207EABC(pSrc, offset, szByte);
}


void NNSi_GfdLoadSubBg2Scr(const void *pSrc, u32 offset, u32 szByte)
{
    func_0207EC34(pSrc, offset, szByte);
}


void NNSi_GfdLoadSubBg3Scr(const void *pSrc, u32 offset, u32 szByte)
{
    func_0207EDAC(pSrc, offset, szByte);
}


void NNSi_GfdLoadSubBg2ScrAffine(const void *pSrc, u32 offset, u32 szByte)
{
    func_0207EC34(pSrc, offset, szByte);
}


void NNSi_GfdLoadSubBg3ScrAffine(const void *pSrc, u32 offset, u32 szByte)
{
    func_0207EDAC(pSrc, offset, szByte);
}


void NNSi_GfdLoadSubObjPltt(const void *pSrc, u32 offset, u32 szByte)
{
    func_0207E5D0(pSrc, offset, szByte);
}


void NNSi_GfdLoadSubBgPltt(const void *pSrc, u32 offset, u32 szByte)
{
    func_0207E468(pSrc, offset, szByte);
}
