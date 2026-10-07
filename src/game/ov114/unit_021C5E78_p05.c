/*
 * file:     unit_021C5E78_p05.c
 * unit:     yes
 * function: func_021C666C, func_021C6704, func_021C67FC, func_021C6898
 * address:  0x021C666C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C5E14  0x021C5E14  arm  ov114
 *   func_021C7934  0x021C7934  arm  ov114
 *   func_021C78E0  0x021C78E0  arm  ov114
 *   func_021C78F4  0x021C78F4  arm  ov114
 *   func_021BF374  0x021BF374  arm  ov114
 *   func_021C797C  0x021C797C  arm  ov114
 *   g_021D3B9C  0x021D3B9C  data
 *   func_0205CD24  0x0205CD24  arm
 *   func_021C7A68  0x021C7A68  arm  ov114
 *   func_021C7A44  0x021C7A44  arm  ov114
 *   func_021C60C8  0x021C60C8  arm  ov114
 *   g_021CE0E4  0x021CE0E4  data
 *   g_021D3C8C  0x021D3C8C  data
 *   func_021C7A30  0x021C7A30  arm  ov114
 *   func_02058518  0x02058518  arm
 *   func_021C7A74  0x021C7A74  arm  ov114
 */
struct tagDWCWiFiInfo;
typedef struct {
	char b[13];
} B13;

typedef struct {
	int type;
	int idx;
	int pad;
	char bssid[9];
} ApInfo;

typedef unsigned int   u32;

typedef struct {
	unsigned long long macid;
	int pad[3];
} WiFiInfo;

typedef unsigned char u8;

extern int func_021C5E14(unsigned long *received, unsigned long *contentlen);
extern int func_021C7934(void);
extern void func_021C78E0(void);
extern void func_021C78F4(void);
extern int func_021BF374(void *handle);
extern void func_021C797C(void);
extern int func_0205CD24(ApInfo *apinfo);
extern void func_021C7A68(char *p, u32 n);
extern void func_021C7A44(void *dst, void *src, int size);
extern int func_021C60C8(char *encstr, char *srcbin, int length);
extern void func_021C7A30(int a, int b);
extern void func_02058518(struct tagDWCWiFiInfo *buf);
extern int func_021C7A74(char *p, unsigned long long n, int figure);
extern int func_02084F80(char *dst, unsigned int len, const char *fmt, ...);
int func_021C666C(void);
int func_021C6704(char *apinfo);
int func_021C67FC(char *gamecode, char *userid);
void func_021C6898(int a);
extern int g_021D3B9C[];
extern B13 g_021CE0E4;
extern ApInfo g_021D3C8C;


int func_021C666C(void)
{
	unsigned long received;
	unsigned long contentlen;
	void *id;
	int rc;
	if (g_021D3B9C[2] == 0)
		return 0;
	rc = 0;
	received = 0;
	contentlen = 0;
	func_021C5E14(&received, &contentlen);
	if (received == contentlen)
		return rc;
	if (func_021C7934() == 0) {
		func_021C78E0();
		id = (void *)g_021D3B9C[4];
		func_021C78F4();
		if (func_021BF374(id) == 0)
			rc = 1;
		return rc;
	}
	func_021C797C();
	return rc;
}


/*
 * sdk:      DWCi_Ndi_getApInfo (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
int func_021C6704(char *apinfo)
{
	B13 strAp = g_021CE0E4;
	if (func_0205CD24(&g_021D3C8C)) {
		if (g_021D3C8C.type >= 0 && g_021D3C8C.type < 10)
			strAp.b[1] = g_021D3C8C.type + '0';
		else if (g_021D3C8C.type >= 10 && g_021D3C8C.type < 100)
			func_021C7A68(strAp.b, g_021D3C8C.type);
		if (g_021D3C8C.type == 4 || g_021D3C8C.type == 8) {
			if (g_021D3C8C.idx >= 0 && g_021D3C8C.idx < 10)
				strAp.b[3] = g_021D3C8C.idx + '0';
			func_021C7A44(&strAp.b[4], g_021D3C8C.bssid, 9);
		}
		func_021C60C8(apinfo, strAp.b, 13);
		return 1;
	}
	return 0;
}


/*
 * sdk:      DWCi_Ndi_getDSdesc (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
int func_021C67FC(char *gamecode, char *userid)
{
	WiFiInfo wifiinfo;
	char strId[13];
	func_021C7A30((int)(&wifiinfo), 20);
	func_02058518((struct tagDWCWiFiInfo *)(&wifiinfo));
	if (wifiinfo.macid == 0)
		return 0;
	if (func_021C7A74(strId, wifiinfo.macid, 13) < 0)
		return 0;
	func_021C60C8(userid, strId, 13);
	func_021C60C8(gamecode, (char *)0x02fffe0c, 4);
	return 1;
}


/*
 * Queues a 0x21/5 record against the 0x021CF464 block.
 */
void func_021C6898(int a)
{
    func_02084F80((char *)a, 0x21, (void *)0x021CF464, 5, 3);
}
