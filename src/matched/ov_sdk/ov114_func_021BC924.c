/*
 * function: NHTTPi_SendHeaderList
 * address:  0x021BC924
 * packet:   pkt_ov114_021BC924
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_SendHeaderList (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * symbols:
 *   NHTTPi_GetSystemInfoP  0x021BEF08  arm  ov114
 *   NHTTPi_GetReqInfoP  0x021BEF48  arm  ov114
 *   NHTTPi_getHdrFromList  0x021BABF4  arm  ov114
 *   NHTTPi_strlen  0x021BA118  arm  ov114
 *   NHTTPi_SendData  0x021BC384  arm  ov114
 *   NHTTPi_free  0x021BA850  arm  ov114
 *   sNHTTPHeaderSeparator     0x021CE4B0  data
 *   sNHTTPCrLf     0x021CE440  data
 */

typedef struct {
	unsigned char pad0[0x30];
	unsigned long hdrlist;
} Req;

typedef struct {
	unsigned char pad0[0x0c];
	Req *req;
} ReqInfo;

typedef struct {
	unsigned long pad0[2];
	char *name;
	char *value;
} DataList;

typedef unsigned char  u8;
extern u8 *NHTTPi_GetSystemInfoP(void);
extern ReqInfo **NHTTPi_GetReqInfoP(void *sysInfo);
extern DataList *NHTTPi_getHdrFromList(void *list);
extern int NHTTPi_strlen(const char *s);
extern int NHTTPi_SendData(void *threadData, const char *src, int srclen);
extern void NHTTPi_free(int a);
extern char sNHTTPHeaderSeparator[];
extern char sNHTTPCrLf[];

int NHTTPi_SendHeaderList(void *threadData_p)
{
	int sendStatus;
	DataList *datalist_p;
	Req *req_p;
	ReqInfo *reqInfo_p;
	void *sysInfo_p;

	sysInfo_p = NHTTPi_GetSystemInfoP();
	reqInfo_p = *NHTTPi_GetReqInfoP(sysInfo_p);
	req_p = reqInfo_p->req;
	while ((datalist_p = NHTTPi_getHdrFromList(&req_p->hdrlist)) != 0) {
		sendStatus = NHTTPi_SendData(threadData_p, datalist_p->name, NHTTPi_strlen(datalist_p->name));
		if (sendStatus) {
			return sendStatus;
		}
		sendStatus = NHTTPi_SendData(threadData_p, sNHTTPHeaderSeparator, 2);
		if (sendStatus) {
			return sendStatus;
		}
		sendStatus = NHTTPi_SendData(threadData_p, datalist_p->value, NHTTPi_strlen(datalist_p->value));
		if (sendStatus) {
			return sendStatus;
		}
		sendStatus = NHTTPi_SendData(threadData_p, sNHTTPCrLf, 2);
		if (sendStatus) {
			return sendStatus;
		}
		NHTTPi_free((int)datalist_p);
	}
	return 0;
}
