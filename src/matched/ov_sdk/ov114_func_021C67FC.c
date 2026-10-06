/*
 * function: func_021C67FC
 * address:  0x021C67FC
 * packet:   pkt_ov114_021C67FC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Ndi_getDSdesc (libdwcnd.TWL.HYB.a(dwci_nd.o))
 *
 * symbols:
 *   func_021C7A30  0x021C7A30  arm  ov114
 *   func_02058518  0x02058518  arm
 *   func_021C7A74  0x021C7A74  arm  ov114
 *   func_021C60C8  0x021C60C8  arm  ov114
 */

typedef struct {
	unsigned long long macid;
	int pad[3];
} WiFiInfo;

extern void func_021C7A30(int a, int b);
struct tagDWCWiFiInfo;
extern void func_02058518(struct tagDWCWiFiInfo *buf);
extern int func_021C7A74(char *p, unsigned long long n, int figure);
extern int func_021C60C8(char *encstr, char *srcbin, int length);

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
