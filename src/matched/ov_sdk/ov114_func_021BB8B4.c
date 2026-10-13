/*
 * function: NHTTPi_DestroyRequest
 * address:  0x021BB8B4
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NHTTPi_free  0x021BA850  arm  ov114
 *   NHTTPi_destroyRequestObject  0x021BB934  arm  ov114
 *   NHTTPi_Request2Connection  0x021BEBE0  arm  ov114
 *   NHTTPi_GetMutexInfoP  0x021BEF58  arm  ov114
 *
 *
 * Unlinks the record from the module's list, releases its handle and then tears the record down.
 */

typedef unsigned char u8;
typedef unsigned int u32;
void *NHTTPi_GetMutexInfoP(int p);
u8 *NHTTPi_Request2Connection(int, int);
void NHTTPi_free(int a);
int NHTTPi_destroyRequestObject(int, u8 *);

void NHTTPi_DestroyRequest(int a, u8 *b)
{
    void *p = NHTTPi_GetMutexInfoP(a);
    u8 *r = NHTTPi_Request2Connection((int)p, (int)b);

    if (r != 0)
        *(u32 *)(r + 0x14) = 0;
    NHTTPi_free(*(u32 *)(b + 0x2c));
    NHTTPi_destroyRequestObject((int)p, b);
}
