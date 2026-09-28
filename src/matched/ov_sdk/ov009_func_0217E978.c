/*
 * function: gsLargeIntAddToMD5
 * address:  0x0217E978
 * packet:   pkt_ov009_0217E978
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsLargeIntAddToMD5 (gslargeint.o)
 *
 * symbols:
 *   memcpy                           0x02092344 arm
 *   gsLargeIntGetByteLength          0x0217e9ec arm
 *   gsLargeIntReverseBytes           0x0217e934 arm
 *   GSMD5Update                      0x0218497c arm
 */

struct gsLargeInt_s {
    unsigned int mLength;
    unsigned int mData[64];
};

struct GSMD5_CTX;

extern void memcpy(void * dst, const void * src, unsigned int n);
extern unsigned int gsLargeIntGetByteLength(struct gsLargeInt_s * lint);
extern int gsLargeIntReverseBytes(struct gsLargeInt_s * lint);
extern void GSMD5Update(struct GSMD5_CTX * context, unsigned char * input, unsigned int inputLen);

void gsLargeIntAddToMD5(struct gsLargeInt_s * _lint, struct GSMD5_CTX * md5)
{
    struct gsLargeInt_s lint;
    int byteLength;
    unsigned char * dataStart;

    memcpy(&lint, _lint, sizeof(lint));
    byteLength = gsLargeIntGetByteLength(&lint);
    if (byteLength == 0)
        return;

    dataStart = (unsigned char *)&lint.mData;
    if (byteLength & 3)
        dataStart += 4 - (byteLength & 3);

    gsLargeIntReverseBytes(&lint);
    GSMD5Update(md5, dataStart, byteLength);
    gsLargeIntReverseBytes(&lint);
}
