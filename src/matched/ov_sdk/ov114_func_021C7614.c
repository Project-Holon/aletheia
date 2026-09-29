/*
 * function: func_021C7614
 * address:  0x021C7614
 * packet:   pkt_ov114_021C7614
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Ndi_response_contents (libdwcnd.TWL.HYB.a dwci_nd.o)
 *
 * symbols:
 *   NHTTP_GetBodyBuffer  0x021BF3E4  arm
 */

typedef struct HTTPREQ {
    unsigned char pad0[0x10];
    int f10;
} HTTPREQ;

extern int NHTTP_GetBodyBuffer(void *handle, char **value_pp, unsigned long *size_p);

int func_021C7614(void *res, HTTPREQ *hrq)
{
    char *body;
    int bodyLen;
    unsigned long bodyBufSize;

    bodyLen = NHTTP_GetBodyBuffer(res, &body, &bodyBufSize);
    return bodyLen == hrq->f10;
}
