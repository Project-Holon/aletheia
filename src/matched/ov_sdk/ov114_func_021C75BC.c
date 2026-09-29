/*
 * function: func_021C75BC
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
 *   func_021BF3E4  0x021BF3E4  arm  ov114
 *   func_021C7A5C  0x021C7A5C  arm  ov114
 */

typedef struct {
	int a, b, c;
	int *count;
} HTTPREQ;

extern int func_021BF3E4(void *handle, char **value_pp, unsigned long *size_p);
extern int func_021C7A5C(char *p, int len);

int func_021C75BC(void *res, HTTPREQ *hrq)
{
	char *body;
	int bodyLen;
	unsigned long bodyBufSize;
	bodyLen = func_021BF3E4(res, &body, &bodyBufSize);
	if (bodyLen >= 0) {
		*hrq->count = func_021C7A5C(body, bodyLen);
		return *hrq->count >= 0;
	}
	return 0;
}
