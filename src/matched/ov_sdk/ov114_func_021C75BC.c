/*
 * function: DWCi_Ndi_response_count
 * address:  0x021C75BC
 * packet:   pkt_ov114_021C75BC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Ndi_response_count (libdwcnd.TWL.HYB.a(dwci_nd.o))
 *
 * symbols:
 *   NHTTP_GetBodyBuffer  0x021BF3E4  arm  ov114
 *   DWCi_Ndi_strToInt  0x021C7A5C  arm  ov114
 */

typedef struct {
	int a, b, c;
	int *count;
} HTTPREQ;

extern int NHTTP_GetBodyBuffer(void *handle, char **value_pp, unsigned long *size_p);
extern int DWCi_Ndi_strToInt(char *p, int len);

int DWCi_Ndi_response_count(void *res, HTTPREQ *hrq)
{
	char *body;
	int bodyLen;
	unsigned long bodyBufSize;
	bodyLen = NHTTP_GetBodyBuffer(res, &body, &bodyBufSize);
	if (bodyLen >= 0) {
		*hrq->count = DWCi_Ndi_strToInt(body, bodyLen);
		return *hrq->count >= 0;
	}
	return 0;
}
