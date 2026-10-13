/*
 * unit: yes
 * function: NHTTP_RAP_EvilCheckCryptoAlloc, NHTTP_RAP_EvilCheckCryptoFree
 * address: 0x021B9AA8
 * packet: pkt_ov114_021B9AA8
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Unlabelled follower 021B9AF8 is the free callback tail-call stub.
 * symbols:
 * sNHTTPRapCryptoHeapId 0x021CE31C data a2
 * sNHTTPRapEvilCheckEmptyString 0x021CE3B8 data a4
 * sNHTTPRapEvilCheckFileName 0x021CE3A0 data a4
 * func_02034714 0x02034714 arm
 * func_02030734 0x02030734 arm
 * func_020307B0 0x020307B0 arm
 */
typedef unsigned short u16;
extern u16 sNHTTPRapCryptoHeapId;
extern char sNHTTPRapEvilCheckEmptyString[], sNHTTPRapEvilCheckFileName[];
extern void func_02034714(const char *, unsigned int, const char *);
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
void *NHTTP_RAP_EvilCheckCryptoAlloc(int n)
{
    void *p;
    if (sNHTTPRapCryptoHeapId == 0xffff)
        func_02034714(sNHTTPRapEvilCheckEmptyString, 0, sNHTTPRapEvilCheckEmptyString);
    p = func_02030734(sNHTTPRapCryptoHeapId, n, 0, sNHTTPRapEvilCheckFileName, 0xe9);
    if (p == 0)
        func_02034714(sNHTTPRapEvilCheckEmptyString, 0, sNHTTPRapEvilCheckEmptyString);
    return p;
}
void NHTTP_RAP_EvilCheckCryptoFree(void *p)
{
    func_020307B0(p);
}
