/*
 * function: func_021BC924
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
 *   func_021BEF08  0x021BEF08  arm  ov114
 *   func_021BEF48  0x021BEF48  arm  ov114
 *   func_021BABF4  0x021BABF4  arm  ov114
 *   func_021BA118  0x021BA118  arm  ov114
 *   func_021BC384  0x021BC384  arm  ov114
 *   func_021BA850  0x021BA850  arm  ov114
 *   g_021CE4B0     0x021CE4B0  data
 *   g_021CE440     0x021CE440  data
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

extern void *func_021BEF08(void);
extern ReqInfo **func_021BEF48(void *sysInfo);
extern DataList *func_021BABF4(void *list);
extern int func_021BA118(const char *s);
extern int func_021BC384(void *threadData, const char *src, int srclen);
extern void func_021BA850(void *ptr);
extern char g_021CE4B0[];
extern char g_021CE440[];

int func_021BC924(void *threadData_p)
{
	int sendStatus;
	DataList *datalist_p;
	Req *req_p;
	ReqInfo *reqInfo_p;
	void *sysInfo_p;

	sysInfo_p = func_021BEF08();
	reqInfo_p = *func_021BEF48(sysInfo_p);
	req_p = reqInfo_p->req;
	while ((datalist_p = func_021BABF4(&req_p->hdrlist)) != 0) {
		sendStatus = func_021BC384(threadData_p, datalist_p->name, func_021BA118(datalist_p->name));
		if (sendStatus) {
			return sendStatus;
		}
		sendStatus = func_021BC384(threadData_p, g_021CE4B0, 2);
		if (sendStatus) {
			return sendStatus;
		}
		sendStatus = func_021BC384(threadData_p, datalist_p->value, func_021BA118(datalist_p->value));
		if (sendStatus) {
			return sendStatus;
		}
		sendStatus = func_021BC384(threadData_p, g_021CE440, 2);
		if (sendStatus) {
			return sendStatus;
		}
		func_021BA850(datalist_p);
	}
	return 0;
}
