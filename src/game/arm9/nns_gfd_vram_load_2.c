/*
 * file:     nns_gfd_vram_load_2.c
 * unit:     yes
 * function: NNSi_GfdLoadSubObjExtPltt, NNSi_GfdLoadSubBgExtPltt, NNSi_GfdLoadSubOam, NNSi_GfdLoadSubObjChar
 * address:  0x02061ABC
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

extern void func_0207F6A8(void);
extern void func_0207F6C0(const void *pSrc, u32 offset, u32 szByte);
extern void func_0207F754(void);
extern void func_0207F5B0(void);
extern void func_0207F5C8(const void *pSrc, u32 offset, u32 szByte);
extern void func_0207F65C(void);
void NNSi_GfdLoadSubObjExtPltt(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubBgExtPltt(const void *pSrc, u32 offset, u32 szByte);
extern void func_0207E708(const void *pSrc, u32 offset, u32 szByte);
extern void func_0207E804(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubOam(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubObjChar(const void *pSrc, u32 offset, u32 szByte);


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_GfdLoadSubObjExtPltt.c \
 *       --func NNSi_GfdLoadSubObjExtPltt --addr 0x02061ABC --arm --cc 1.1p1
 */
void NNSi_GfdLoadSubObjExtPltt(const void *pSrc, u32 offset, u32 szByte)
{
    func_0207F6A8();
    func_0207F6C0(pSrc, offset, szByte);
    func_0207F754();
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_GfdLoadSubBgExtPltt.c \
 *       --func NNSi_GfdLoadSubBgExtPltt --addr 0x02061AE8 --arm --cc 1.1p1
 */
void NNSi_GfdLoadSubBgExtPltt(const void *pSrc, u32 offset, u32 szByte)
{
    func_0207F5B0();
    func_0207F5C8(pSrc, offset, szByte);
    func_0207F65C();
}


void NNSi_GfdLoadSubOam(const void *pSrc, u32 offset, u32 szByte)
{
    func_0207E708(pSrc, offset, szByte);
}


void NNSi_GfdLoadSubObjChar(const void *pSrc, u32 offset, u32 szByte)
{
    func_0207E804(pSrc, offset, szByte);
}
