/*
 * function: NHTTP_RAP_VerifySignature
 * address: 0x021B9A1C
 * packet: pkt_ov114_021B9A1C
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * sNHTTPRapCryptoHeapId 0x021CE31C data a2
 * NHTTP_RAP_EvilCheckCryptoAlloc 0x021B9AA8 thumb ov114
 * NHTTP_RAP_EvilCheckCryptoFree 0x021B9AF8 thumb ov114
 * sNHTTPRapSignatureModulus 0x021CE320 data a4
 * CRYPTO_SetMemAllocator 0x021CAB1C arm ov114
 * CRYPTO_VerifySignature 0x021CAA70 arm ov114
 */
typedef unsigned short u16;
extern u16 sNHTTPRapCryptoHeapId;
extern unsigned int sNHTTPRapSignatureModulus[];
extern void *NHTTP_RAP_EvilCheckCryptoAlloc(int);
extern void NHTTP_RAP_EvilCheckCryptoFree(void *);
extern void CRYPTO_SetMemAllocator(void *, void *, int);
extern int CRYPTO_VerifySignature(void *data_ptr, int data_len, void *sign_ptr, void *mod_ptr);
int NHTTP_RAP_VerifySignature(void *a, int b, int c, char *d, u16 e)
{
    int result;
    sNHTTPRapCryptoHeapId = e;
    CRYPTO_SetMemAllocator(NHTTP_RAP_EvilCheckCryptoAlloc, NHTTP_RAP_EvilCheckCryptoFree, 0);
    result = CRYPTO_VerifySignature((void *)a, b*c, (void *)d, sNHTTPRapSignatureModulus);
    sNHTTPRapCryptoHeapId = 0xffff;
    return result;
}
