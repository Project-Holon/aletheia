/*
 * file:     unit_021BA2F8_p07.c
 * unit:     yes
 * function: MD5_memcpy, func_021BC544, func_021BC55C, GetTickCount
 * address:  0x021BC52C
 * region:   ov016
 * compiler: dsi/../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MY_MD5Init    0x021BBB98  thumb
 *   MY_MD5Update  0x021BBBC0  thumb
 *   MY_MD5Final   0x021BBC38  thumb
 *   OS_GetTick  0x020870D0  arm
 *   _ll_udiv    0x0209C00C  arm
 */
typedef unsigned long UINT4;

typedef struct {
    UINT4         state[4];
    UINT4         count[2];
    unsigned char buffer[64];
} MY_MD5_CTX;

extern void MY_MD5Init(MY_MD5_CTX *context);
extern void MY_MD5Update(MY_MD5_CTX *context, unsigned char *input, unsigned int inputLen);
extern void MY_MD5Final(unsigned char digest[16], MY_MD5_CTX *context);
extern unsigned long long OS_GetTick(void);
void MD5_memcpy(unsigned char *output, unsigned char *input, unsigned int len);
void MD5_memset(unsigned char *output, int value, unsigned int len);
unsigned long GetTickCount(void);


void MD5_memcpy(unsigned char *output, unsigned char *input, unsigned int len)
{
    unsigned int i;

    for (i = 0; i < len; i++)
        output[i] = input[i];
}



void MD5_memset(unsigned char *output, int value, unsigned int len)
{
    unsigned int i;

    for (i = 0; i < len; i++)
        ((char *)output)[i] = (char)value;
}




static void MD5Encode(unsigned char *digest, unsigned char *psrc, int srclen)
{
    MY_MD5_CTX context;

    MY_MD5Init(&context);
    MY_MD5Update(&context, psrc, srclen);
    MY_MD5Final(digest, &context);
}


unsigned long GetTickCount(void)
{
    return (unsigned long)((OS_GetTick() * 64) / 0x82EA);
}
