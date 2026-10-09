/*
 * file:     unit_021C5E78.c
 * unit:     yes
 * function: func_021C5E78, func_021C5EBC, func_021C5F90, func_021C6004, func_021C6048, func_021C60A0, func_021C60AC, func_021C60C8, func_021C61C0, func_021C62FC, func_021C6348, func_021C64E0, func_021C651C, func_021C654C, func_021C659C, func_021C666C, func_021C6704, func_021C67FC, func_021C6898, func_021C68BC, func_021C6B44, func_021C6BEC, func_021C6C0C, func_021C70D4, DWCi_NdGetFileListAsync, func_021C73C0, func_021C757C, func_021C75BC, func_021C7614, func_021C7644, func_021C78C4
 * address:  0x021C5E78
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021D3BD8  0x021D3BD8  data
 *   g_021D3B9C  0x021D3B9C  data
 *   func_021C7A18  0x021C7A18  arm  ov114
 *   func_021C78E0  0x021C78E0  arm  ov114
 *   func_021C78F4  0x021C78F4  arm  ov114
 *   g_021CE0F4  0x021CE0F4  data
 *   func_021C7A44  0x021C7A44  arm  ov114
 *   func_021C79C0  0x021C79C0  arm  ov114
 *   func_021C7908  0x021C7908  arm  ov114
 *   func_021BE648  0x021BE648  arm  ov114
 *   func_021C78DC  0x021C78DC  arm  ov114
 *   g_021D3BE4  0x021D3BE4  data
 *   g_021D3C69  0x021D3C69  data
 *   g_021D3BCD  0x021D3BCD  data
 *   g_021D3C50  0x021D3C50  data
 *   g_021D3BF5  0x021D3BF5  data
 *   func_021C7930  0x021C7930  arm  ov114
 *   d_021D3B9C   0x021D3B9C  data
 *   nhttpCleanupCallback   0x021C64E0  arm
 *   func_021BF3BC  0x021BF3BC  arm  ov114
 *   func_021BF184  0x021BF184  arm  ov114
 *   func_02059F54  0x02059F54  arm
 *   func_021C5E14  0x021C5E14  arm  ov114
 *   func_021C7934  0x021C7934  arm  ov114
 *   func_021BF374  0x021BF374  arm  ov114
 *   func_021C797C  0x021C797C  arm  ov114
 *   func_0205CD24  0x0205CD24  arm
 *   func_021C7A68  0x021C7A68  arm  ov114
 *   g_021CE0E4  0x021CE0E4  data
 *   g_021D3C8C  0x021D3C8C  data
 *   func_021C7A30  0x021C7A30  arm  ov114
 *   func_02058518  0x02058518  arm
 *   func_021C7A74  0x021C7A74  arm  ov114
 *   NHTTP_GetUserParam              0x021BF444  arm  ov114
 *   NHTTP_GetConnectionError        0x021BF488  arm  ov114
 *   NHTTP_GetHeaderField            0x021BE7FC  arm  ov114
 *   DWCi_Ndi_strToInt               0x021C7A5C  arm  ov114
 *   NHTTP_GetBodyBuffer             0x021BF3E4  arm  ov114
 *   DWCi_Ndi_strncmp                0x021C7A24  arm  ov114
 *   DWCi_Ndi_decodeBASE64           0x021C61C0  arm  ov114
 *   DWCi_Ndi_response_count         0x021C75BC  arm  ov114
 *   DWCi_Ndi_response_contents      0x021C7614  arm  ov114
 *   freeHttpParam                   0x021C6B44  arm  ov114
 *   DWCi_Ndi_unprepareHttpCallback  0x021C797C  arm  ov114
 *   DWCi_Ndi_kickThread             0x021C79AC  arm  ov114
 *   DWCi_NdSetError                 0x021C659C  arm  ov114
 *   g_021CF47C                      0x021CF47C  data  ov114
 *   g_021CF48C                      0x021CF48C  data  ov114
 *   DWCi_Ndi_getDSdesc              0x021c67fc arm
 *   DWCi_Ndi_prepareHttpCallback    0x021c7934 arm
 *   DWCi_NdCleanupConnectionHandle  0x021c654c arm
 *   NHTTP_CreateConnection          0x021bf04c arm
 *   NHTTP_SetRootCA                 0x021be9c8 arm
 *   NHTTP_SetVerifyOption           0x021be8b8 arm
 *   NHTTP_AddHeaderField            0x021be6bc arm
 *   NHTTP_AddPostDataAscii          0x021be748 arm
 *   DWCi_Ndi_strlen                 0x021c7a18 arm
 *   freeHttp                        0x021c6bec arm
 *   DWCi_Ndi_memclr                 0x021c7a30 arm
 *   DWCi_Ndi_encodeBASE64           0x021c60c8 arm
 *   g_021D3BC4   0x021d3bc4 data
 *   g_021D3C0A   0x021d3c0a data
 *   g_021C68BC   0x021c68bc arm
 *   g_021CF37C   0x021cf37c data
 *   g_021CF498   0x021cf498 data
 *   g_021CF4A4   0x021cf4a4 data
 *   g_021CF4AC   0x021cf4ac data
 *   g_021CF4B8   0x021cf4b8 data
 *   g_021CF4C0   0x021cf4c0 data
 *   g_021CF4C8   0x021cf4c8 data
 *   g_021CF4D0   0x021cf4d0 data
 *   g_021CF4D8   0x021cf4d8 data
 *   g_021CF4E0   0x021cf4e0 data
 *   g_021CF4E8   0x021cf4e8 data
 *   g_021CF4F0   0x021cf4f0 data
 *   g_021CF4F8   0x021cf4f8 data
 *   g_021D3CCC   0x021d3ccc data
 *   g_021CF500   0x021cf500 data
 *   func_021BF308  0x021BF308  arm  ov114
 *   DWCi_Ndi_intToStr               0x021C7A68  arm  ov114
 *   DWCi_Ndi_getEncodeLenBASE64     0x021C60AC  arm  ov114
 *   runHttp                         0x021C70D4  arm  ov114
 *   DWCiNd_action_list              0x021CE0CE  data  ov114
 *   func_021C6C0C  0x021C6C0C  arm  ov114
 *   func_021BE748  0x021BE748  arm  ov114
 *   g_021CE0D7  0x021CE0D7  data
 *   NHTTP_GetConnectionProgress  0x021BF4B0  arm
 *   func_021BF3E4  0x021BF3E4  arm  ov114
 *   func_021C7A5C  0x021C7A5C  arm  ov114
 *   DWCi_Ndi_memcpy                0x021C7A44  arm  ov114
 *   g_021CF528                     0x021CF528  data  ov114
 *   @17416                          0x021CF510  data
 *   @17417                          0x021CF518  data
 *   @17442  0x021CF51C  data
 */
#define FREE(p) g_021D3B9C.free(p)
struct tagDWCWiFiInfo;
typedef void *(*NdAlloc)(unsigned int size, int align);

typedef void (*NdFree)(void *p);

typedef void (*NdCallback)(int reason, int err, int servererror);

typedef struct NdStatics {
    NdCallback callback;    /* +0x00 */
    NdAlloc alloc;          /* +0x04 */
    int initialized;        /* +0x08 */
    int apinfo;             /* +0x0c */
    void *handle;           /* +0x10 */
    NdFree free;            /* +0x14 */
    char *token;            /* +0x18 */
    char *url;              /* +0x1c */
    char pad20[4];
    void (*cleanup)(void);  /* +0x24 */
    char pad28[0x3c - 0x28];
    char *p3C;              /* +0x3c */
    char *p40;              /* +0x40 */
    char *p44;              /* +0x44 */
} NdStatics;

typedef struct DWCNdFileInfo {
    char name[33];
    short explain[51];
    char param1[11];
    char param2[11];
    char param3[11];
    unsigned int size;
} DWCNdFileInfo;

typedef struct tagDWCi_Ndi_HTTPREQ {
    int reason;                 /* +0x00 */
    NdCallback callback;        /* +0x04 */
    void *threadEvent;          /* +0x08 */
    union {
        struct {
            char *encName;      /* +0x0c */
            int size;           /* +0x10 */
        } getfile;
        struct {
            DWCNdFileInfo *filelist;
            int num;
            char *pBuf;
            char *strOffset;
            char *strNum;
        } list;
        struct {
            int *count;
        } getcount;
        char pad[20];
    } param;
} tagDWCi_Ndi_HTTPREQ;

typedef unsigned int   u32_021C5E78;

typedef unsigned char  u8;

typedef unsigned long u32_021C60A0;

typedef unsigned int u32_021C60AC;

typedef unsigned long u32_021C6348;

typedef struct {
	char b[13];
} B13;

typedef struct {
	int type;
	int idx;
	int pad;
	char bssid[9];
} ApInfo;

typedef unsigned int   u32_021C666C;

typedef struct {
	unsigned long long macid;
	int pad[3];
} WiFiInfo;

typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned int u32_021C7124;

typedef unsigned long u32_021C73C0;

extern u32_021C5E78 func_021C7A18(const u8 *a0);
extern void func_021C78E0(void);
extern void func_021C78F4(void);
extern void func_021C7A44(void *dst, void *src, int size);
extern void func_021C79C0(char *macaddr);
extern int func_021C7908(void);
extern int func_021BE648(int a, int b, int c);
extern void func_021C78DC(void);
extern void func_021C7930(void);
extern void func_021BE680(int a);
extern void nhttpCleanupCallback(void);
extern int func_021BF3BC(int a);
extern int func_021BF184(int a);
extern void func_02059F54(int error, int errorCode);
extern int func_021C5E14(unsigned long *received, unsigned long *contentlen);
extern int func_021C7934(void);
extern int func_021BF374(void *handle);
extern void func_021C797C(void);
extern int func_0205CD24(ApInfo *apinfo);
extern void func_021C7A68(char *p, u32_021C666C n);
extern void func_021C7A30(int a, int b);
extern void func_02058518(struct tagDWCWiFiInfo *buf);
extern int func_021C7A74(char *p, unsigned long long n, int figure);
extern int func_02084F80(char *dst, unsigned int len, const char *fmt, ...);
extern void *NHTTP_GetUserParam(void *handle);
extern int NHTTP_GetConnectionError(void *handle);
extern int NHTTP_GetHeaderField(void *handle, char *label_p, char **value_pp);
extern int DWCi_Ndi_strToInt(char *p, int len);
extern int NHTTP_GetBodyBuffer(void *handle, char **value_pp, unsigned long *size_p);
extern int DWCi_Ndi_strncmp(char *p1, char *p2, unsigned long size);
extern int DWCi_Ndi_decodeBASE64(char *decbin, char *str, int length);
extern int DWCi_Ndi_response_count(void *res, tagDWCi_Ndi_HTTPREQ *hrq);
extern int DWCi_Ndi_response_contents(void *res, tagDWCi_Ndi_HTTPREQ *hrq);
extern void freeHttpParam(tagDWCi_Ndi_HTTPREQ *hrq);
extern void DWCi_Ndi_unprepareHttpCallback(void);
extern void DWCi_Ndi_kickThread(void *threadEvent);
extern void DWCi_NdSetError(int err, int servererror);
extern int DWCi_Ndi_getDSdesc(char *gamecode, char *userid);
extern int DWCi_Ndi_prepareHttpCallback(void);
extern int DWCi_NdCleanupConnectionHandle(void *handle);
extern void *NHTTP_CreateConnection(char *url_p, int method, char *buf_p, unsigned long len, int (*callback)(void *, int, void *), void *userParam_p);
extern int NHTTP_SetRootCA(void *handle, char *rootCAData_p, unsigned long rootCASize);
extern int NHTTP_SetVerifyOption(void *handle, unsigned long verifyOption);
extern int NHTTP_AddHeaderField(void *handle, char *label_p, char *value_p);
extern int NHTTP_AddPostDataAscii(void *handle, char *label_p, char *value_p);
extern unsigned long DWCi_Ndi_strlen(char *p);
extern void freeHttp(tagDWCi_Ndi_HTTPREQ *hrq, void *req);
extern void DWCi_Ndi_memclr(void *p, int size);
extern int DWCi_Ndi_encodeBASE64(char *encstr, char *srcbin, int length);
extern int g_021C68BC(void *res, int event, void *arg);
extern int func_021BF308(void *handle);
extern int DWCi_Ndi_intToStr(char *p, unsigned long n);
extern int DWCi_Ndi_getEncodeLenBASE64(int len);
extern int runHttp(void *hrq, void *req);
extern int func_021C6C0C(tagDWCi_Ndi_HTTPREQ **phrq, void **preq, char *strAction, char *recvbuf,
                         unsigned int recvbufLen, char *opt);
extern int func_021BE748(void *handle, char *label_p, char *value_p);
extern int NHTTP_GetConnectionProgress(void *handle, unsigned long *received_p, unsigned long *contentlen_p);
extern int func_021BF3E4(void *handle, char **value_pp, unsigned long *size_p);
extern int func_021C7A5C(char *p, int len);
extern void DWCi_Ndi_memcpy(void *dst, void *src, int size);
extern void func_02086004(void *);
void func_021C5E78(void);
int func_021C5EBC(int id, char *attr);
int func_021C5F90(char *attr1, char *attr2, char *attr3);
int func_021C6004(unsigned char *dst, char *p, int n);
int func_021C6048(unsigned char c);
u32_021C60A0 DWCi_Ndi_getDecodeLenBASE64(int len);
int func_021C60AC(int n);
int func_021C60C8(char *encstr, char *srcbin, int length);
int func_021C61C0(char *decbin, char *str, int length);
char *func_021C62FC(char *src);
int func_021C6348(NdAlloc alloc, NdFree free, char *url, char *token, char *gamecd, char *passwd, NdCallback callback);
void func_021C64E0(void);
void DWCi_NdCleanupAsync(void *callback);
int func_021C654C(void *volatile handle);
void func_021C659C(int err, int servererror);
int func_021C666C(void);
int func_021C6704(char *apinfo);
int func_021C67FC(char *gamecode, char *userid);
void func_021C6898(int a);
int req_callback(void *res, int event, void *arg);
void func_021C6B44(int *hrq);
void func_021C6BEC(void *a, int b);
int func_021C70D4(int unused, void *req);
int DWCi_NdGetFileListAsync(DWCNdFileInfo *filelist, int offset, int num);
int func_021C73C0(DWCNdFileInfo *filelist, char *buf, unsigned int bufsize, char *opt);
int func_021C757C(unsigned long *received, unsigned long *contentlen);
int func_021C75BC(void *res, tagDWCi_Ndi_HTTPREQ *hrq);
int func_021C7614(void *res, tagDWCi_Ndi_HTTPREQ *hrq);
int DWCi_Ndi_response_list(void *res, tagDWCi_Ndi_HTTPREQ *hrq);
int func_021C78C4(void);
extern NdStatics g_021D3B9C;
extern char *g_021D3BD8[3];
extern const char g_021CE0F4[];
extern char g_021D3BE4[];
extern char g_021D3C69[];
extern char g_021D3BCD[];
extern char g_021D3C50[];
extern char g_021D3BF5[];
extern char d_021D3B9C[];
extern B13 g_021CE0E4;
extern ApInfo g_021D3C8C;
extern char g_021CF47C[];
extern char g_021CF48C[];
extern char g_021D3BC4[9];
extern char g_021D3C0A[21];
extern char g_021CF37C[];
extern char g_021CF498[];
extern char g_021CF4A4[];
extern char g_021CF4AC[];
extern char g_021CF4B8[];
extern char g_021CF4C0[];
extern char g_021CF4C8[];
extern char g_021CF4D0[];
extern char g_021CF4D8[];
extern char g_021CF4E0[];
extern char g_021CF4E8[];
extern char g_021CF4F0[];
extern char g_021CF4F8[];
extern char g_021D3CCC[89];
extern char g_021CF500[];
extern char DWCiNd_action_list[9];
extern char g_021CE0D7[13];
extern char g_021CF528[];










/*
 * sdk:      DWCi_Ndi_freeAttr (libdwcnd.TWL.HYB.a dwci_nd.o)
 */
void func_021C5E78(void)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (g_021D3BD8[i] != 0) {
            g_021D3B9C.free(g_021D3BD8[i]);
            g_021D3BD8[i] = 0;
        }
    }
}











/*
 * sdk:      setAttr (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
int func_021C5EBC(int id, char *attr)
{
	int encLen;
	int n;
	if (*attr != 0) {
		if ((int)func_021C7A18((const u8 *)attr) > 10) {
			func_021C659C(5, 0);
			return 0;
		}
		n = func_021C7A18((const u8 *)attr);
		if (n > 10) {
			func_021C659C(5, 0);
			return 0;
		}
		g_021D3BD8[id] = (char *)g_021D3B9C.alloc(func_021C60AC(n) + 1, 4);
		if (g_021D3BD8[id] == 0) {
			func_021C659C(1, 0);
			return 0;
		}
		encLen = func_021C60C8(g_021D3BD8[id], attr, n);
		g_021D3BD8[id][encLen] = 0;
	}
	return 1;
}











/*
 * sdk:      DWCi_NdSetAttr (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
int func_021C5F90(char *attr1, char *attr2, char *attr3)
{
	func_021C78E0();
	func_021C5E78();
	if (func_021C5EBC(0, attr1) && func_021C5EBC(1, attr2) && func_021C5EBC(2, attr3)) {
		func_021C78F4();
		return 1;
	}
	func_021C5E78();
	func_021C78F4();
	return 0;
}










/*
 * sdk:      getNchar (libdwcnd.TWL.HYB.a dwci_nd.o)
 */
int func_021C6004(unsigned char *dst, char *p, int n)
{
    int i;
    int len;

    len = 0;
    for (i = 0; i < n; i++) {
        if (*p != 0) {
            *dst++ = *p;
            len++;
            p++;
        } else {
            *dst++ = 0;
        }
    }
    return len;
}










/*
 * sdk:      decodeChar (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
int func_021C6048(unsigned char c)
{
	if (c >= 'A' && c <= 'Z')
		return c - 'A';
	if (c >= 'a' && c <= 'z')
		return c - 'a' + 26;
	if (c >= '0' && c <= '9')
		return c - '0' + 52;
	if (c == '.')
		return 62;
	if (c == '-')
		return 63;
	return -1;
}











u32_021C60A0 DWCi_Ndi_getDecodeLenBASE64(int len)
{
    return (len >> 2) * 3;
}










/*
 * Row stride: rounds `n` up into 3-byte triples and scales by 4.
 */
int func_021C60AC(int n)
{
    return ((n + 2) / 3) * 4;
}










/*
 * Three levers, all required:
 *   1. `const` on the read-only extern table g_021CE0F4.  Without it the
 *      hoisted `ldr <tbl>, [pc]` grabbed r4 (the lowest free callee-saved)
 *      and the WHOLE callee-saved set rotated one register high
 *      (95 concrete diffs).  With it the allocation matches the image
 *      (r4=0-copy, r5=0, r6=len, r7=length, r8=srcbin, sb=encstr, sl=table).
 *      See docs/idioms/const-on-a-read-only-extern-table-settles-a-register-tie.md.
 *   2. the update block order is `srcbin += n; encstr += 4; len += 4;
 *      length -= n;` (srcbin first, len after encstr).  Other orders emit
 *      subs/add in the wrong place in the tail (47..55 diffs).
 *   3. the four base assignments are ordered base1 (=c[0]>>2), base0, base2,
 *      base3; this settles which scratch register (r1/r2/r3/ip) each byte
 *      load and each masked value lands in.  Declaration order of the base
 *      locals is inert; it is the statement order that colours them.
 *
 * sdk:      DWCi_Ndi_encodeBASE64 (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
int func_021C60C8(char *encstr, char *srcbin, int length)
{
	unsigned char c[3];
	unsigned char base2;
	unsigned char base3;
	unsigned char base1;
	unsigned char base0;
	int n;
	int len = 0;
	n = func_021C6004(c, srcbin, length > 3 ? 3 : length);
	while (n > 0) {
		if (length < 3)
			c[2] = 0;
		if (length < 2)
			c[1] = 0;
		base1 = (unsigned char)(c[0] >> 2);
		base0 = ((c[0] << 4) | (c[1] >> 4)) & 0x3f;
		base2 = ((c[1] << 2) | (c[2] >> 6)) & 0x3f;
		base3 = c[2] & 0x3f;
		encstr[0] = g_021CE0F4[base1];
		encstr[1] = g_021CE0F4[base0];
		encstr[2] = n > 1 ? g_021CE0F4[base2] : '*';
		encstr[3] = n > 2 ? g_021CE0F4[base3] : '*';
		srcbin += n;
		encstr += 4;
		len += 4;
		length -= n;
		if (length == 0)
			break;
		n = func_021C6004(c, srcbin, length > 3 ? 3 : length);
	}
	*encstr = 0;
	return len;
}










/*
 * sdk:      DWCi_Ndi_decodeBASE64 (libdwcnd.TWL.HYB.a dwci_nd.o)
 */
int func_021C61C0(char *decbin, char *str, int length)
{
    unsigned char c[4];
    char dec[3];
    int d;
    int i;
    int n;
    int len;

    len = 0;
    n = func_021C6004(c, str, 4);
    d = 0;
    while (n > 0 && d >= 0) {
        dec[0] = 0;
        dec[1] = 0;
        dec[2] = 0;
        d = func_021C6048(c[0]);
        if (d >= 0) {
            dec[0] = d << 2;
            d = func_021C6048(c[1]);
            if (d >= 0) {
                dec[0] |= d >> 4;
                dec[1] = d << 4;
                d = func_021C6048(c[2]);
                if (d >= 0) {
                    dec[1] |= d >> 2;
                    dec[2] = d << 6;
                    d = func_021C6048(c[3]);
                    if (d >= 0)
                        dec[2] |= d;
                }
            }
        }
        for (i = 0; i < n - 1; i++)
            *decbin++ = dec[i];
        str += n;
        len += n - 1;
        length -= 4;
        if (length <= 0)
            break;
        n = func_021C6004(c, str, 4);
    }
    *decbin = 0;
    return len;
}








/*
 * sdk:      strAlloc (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
char *func_021C62FC(char *src)
{
	int n;
	char *dst;
	n = func_021C7A18((const u8 *)src);
	dst = (char *)g_021D3B9C.alloc(n + 1, 4);
	if (dst) {
		func_021C7A44(dst, src, n);
		dst[n] = 0;
	}
	return dst;
}






/*
 * sdk:      DWCi_NdStartup (libdwcnd.TWL.HYB.a(dwci_nd.o))
 *
 * The file statics of dwci_nd.o sit in one block based at DWCi_Ndi_dlcallback
 * (0x021D3B9C); the struct below names its words by offset.
 */
int func_021C6348(NdAlloc alloc, NdFree free, char *url, char *token, char *gamecd,
                  char *passwd, NdCallback callback)
{
    int len;

    g_021D3B9C.alloc = alloc;
    g_021D3B9C.free = free;
    g_021D3B9C.callback = callback;
    g_021D3B9C.p3C = 0;
    g_021D3B9C.p40 = 0;
    g_021D3B9C.p44 = 0;
    g_021D3B9C.apinfo = 0;
    g_021D3B9C.handle = 0;
    g_021D3B9C.token = 0;
    g_021D3B9C.url = 0;

    func_021C79C0(g_021D3BE4);
    func_021C6898((int)g_021D3C69);

    g_021D3B9C.url = func_021C62FC(url);
    if (g_021D3B9C.url == 0)
        goto fail;
    g_021D3B9C.token = func_021C62FC(token);
    if (g_021D3B9C.token == 0)
        goto fail;

    len = func_021C60C8(g_021D3BCD, gamecd, 4);
    g_021D3BCD[len] = 0;
    len = func_021C60C8(g_021D3C50, passwd, 16);
    g_021D3C50[len] = 0;

    if (func_021C7908() && func_021C78C4()) {
        if (func_021BE648((int)alloc, (int)free, 17) != -1) {
            g_021D3B9C.apinfo = func_021C6704(g_021D3BF5);
            g_021D3B9C.initialized = 1;
            return 1;
        }
        func_021C78DC();
    }
    g_021D3B9C.free(g_021D3B9C.token);
    g_021D3B9C.free(g_021D3B9C.url);
    func_021C659C(8, 0);
    return 0;

fail:
    if (g_021D3B9C.token != 0)
        g_021D3B9C.free(g_021D3B9C.token);
    if (g_021D3B9C.url != 0)
        g_021D3B9C.free(g_021D3B9C.url);
    func_021C659C(1, 0);
    return 0;
}






void func_021C64E0(void)
{
    func_021C5E78();
    func_021C78DC();
    func_021C7930();
    g_021D3B9C.free(g_021D3B9C.token);
    g_021D3B9C.free(g_021D3B9C.url);
    g_021D3B9C.cleanup();
}






void DWCi_NdCleanupAsync(void *callback)
{
    *(u32_021C5E78 *)(d_021D3B9C + 8) = 0;
    *(void **)(d_021D3B9C + 0x24) = callback;
    func_021C654C(*(void **)(d_021D3B9C + 0x10));
    func_021BE680((int)nhttpCleanupCallback);
}






/*
 * sdk:      DWCi_NdCleanupConnectionHandle (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
int func_021C654C(void *volatile handle)
{
	int result = 1;
	func_021C78E0();
	if (handle) {
		func_021BF3BC((int)handle);
		if (func_021BF184((int)handle) != 0)
			result = 0;
		else
			handle = 0;
	}
	func_021C78F4();
	return result;
}






/*
 * sdk:      DWCi_NdSetError (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
void func_021C659C(int err, int servererror)
{
	switch (err) {
	case 1:
		func_02059F54(9, -31001);
		break;
	case 3:
		func_02059F54(14, -31020);
		break;
	case 4:
		func_02059F54(13, -31040);
		break;
	case 7:
		func_02059F54(13, -31000 - servererror);
		break;
	case 5:
		func_02059F54(13, -31040);
		break;
	case 8:
		func_02059F54(9, -31009);
		break;
	case 2:
		func_02059F54(13, -31010);
		break;
	case 0:
	case 6:
		break;
	default:
		func_02059F54(9, -31009);
		break;
	}
}






int func_021C666C(void)
{
	unsigned long received;
	unsigned long contentlen;
	void *id;
	int rc;
	if (g_021D3B9C.initialized == 0)
		return 0;
	rc = 0;
	received = 0;
	contentlen = 0;
	func_021C5E14(&received, &contentlen);
	if (received == contentlen)
		return rc;
	if (func_021C7934() == 0) {
		func_021C78E0();
		id = g_021D3B9C.handle;
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






int req_callback(void *res, int event, void *arg)
{
    tagDWCi_Ndi_HTTPREQ *hrq;
    int reason;
    void (*callback)(int, int, int);
    void *threadEvent;
    int httpStatus;
    int serverError;
    int result;
    unsigned long bodyBufSize;
    char *strHttpStatus;
    int n;
    char *v;
    int bgn;
    int len;
    int pos;
    char outstr[4];
    int isCode;

    serverError = -1;
    hrq = (tagDWCi_Ndi_HTTPREQ *)NHTTP_GetUserParam(res);
    reason = hrq->reason;
    callback = (void (*)(int, int, int))hrq->callback;
    threadEvent = hrq->threadEvent;
    switch (event) {
    case 4:
        if (NHTTP_GetConnectionError(res) == 8) {
            result = 6;
        } else if (NHTTP_GetHeaderField(res, g_021CF47C, &strHttpStatus) != 3) {
            result = 3;
        } else {
            httpStatus = DWCi_Ndi_strToInt(strHttpStatus, 3);
            if (httpStatus == 0x12e) {
                isCode = 0;
                n = NHTTP_GetBodyBuffer(res, &v, &bodyBufSize);
                if (n < 0) {
                    result = 3;
                } else {
                    pos = 0;
                    while (pos < n) {
                        bgn = pos;
                        while (v[pos] != '=' && pos < n)
                            pos++;
                        len = pos - bgn;
                        pos++;
                        if (len == 8)
                            isCode = DWCi_Ndi_strncmp(v + bgn, g_021CF48C, 8) == 0;
                        bgn = pos;
                        while (v[pos] != '&' && v[pos] != '\r' && v[pos] != '\0' && pos < n)
                            pos++;
                        len = pos - bgn;
                        pos++;
                        if (isCode) {
                            if (len == 4) {
                                len = DWCi_Ndi_decodeBASE64(outstr, v + bgn, len);
                                outstr[len] = 0;
                                serverError = DWCi_Ndi_strToInt(outstr, len);
                            }
                            break;
                        }
                    }
                    if (serverError < 0)
                        result = 3;
                    else
                        result = 7;
                }
            } else if (httpStatus <= 0 || httpStatus != 0xc8) {
                result = 3;
            } else {
                switch (reason) {
                case 1:
                    result = DWCi_Ndi_response_count(res, hrq) ? 0 : 3;
                    break;
                case 2:
                    result = DWCi_Ndi_response_list(res, hrq) ? 0 : 3;
                    break;
                case 3:
                    result = DWCi_Ndi_response_contents(res, hrq) ? 0 : 3;
                    break;
                }
            }
        }
        freeHttpParam(hrq);
        DWCi_Ndi_unprepareHttpCallback();
        if (callback != 0)
            callback(reason, result, serverError);
        if (threadEvent != 0)
            DWCi_Ndi_kickThread(threadEvent);
        break;
    case 2:
        isCode = 4;
        ((int *)arg)[2] = 0;
        DWCi_NdSetError(isCode, serverError);
        if (callback != 0)
            callback(reason, isCode, serverError);
        break;
    case 3:
        break;
    }
    return 0;
}






/*
 * sdk:      freeHttpParam (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
void func_021C6B44(int *hrq)
{
	if (hrq == 0)
		return;
	switch (hrq[0]) {
	case 1:
		break;
	case 2:
		if (hrq[7]) {
			FREE((void *)hrq[7]);
			hrq[7] = 0;
		}
		if (hrq[6]) {
			FREE((void *)hrq[6]);
			hrq[6] = 0;
		}
		FREE((void *)hrq[5]);
		hrq[5] = 0;
		break;
	case 3:
		FREE((void *)hrq[3]);
		hrq[3] = 0;
		break;
	}
	FREE(hrq);
}





/*
 * Rebuilds the +0x? table for `b`, refreshes the pool, then re-links `a`.
 */
void func_021C6BEC(void *a, int b)
{
    func_021C654C((void * volatile)b);
    func_021C797C();
    func_021C6B44(a);
}





static int setupHttp(tagDWCi_Ndi_HTTPREQ **phrq, void **preq, char *strAction, char *recvbuf, unsigned int recvbufLen, char *opt)
{
    char strTemp[256];
    int n;
    tagDWCi_Ndi_HTTPREQ *hrq;
    void *req;

    if (DWCi_Ndi_getDSdesc(g_021D3BC4, g_021D3C0A) == 0) {
        DWCi_NdSetError(8, 0);
        return 0;
    }
    hrq = (tagDWCi_Ndi_HTTPREQ *)g_021D3B9C.alloc(0x20, 4);
    if (hrq == 0) {
        DWCi_NdSetError(1, 0);
        return 0;
    }
    hrq->callback = g_021D3B9C.callback;
    hrq->threadEvent = 0;
    if (DWCi_Ndi_prepareHttpCallback() == 0) {
        freeHttpParam(hrq);
        DWCi_NdSetError(2, 0);
        return 0;
    }
    if (DWCi_NdCleanupConnectionHandle(g_021D3B9C.handle) == 0)
        return 0;
    req = NHTTP_CreateConnection(g_021D3B9C.url, 1, recvbuf, recvbufLen, g_021C68BC, hrq);
    if (req == 0) {
        DWCi_Ndi_unprepareHttpCallback();
        freeHttpParam(hrq);
        DWCi_NdSetError(3, 0);
        return 0;
    }
    *phrq = hrq;
    *preq = req;
    if (NHTTP_SetRootCA(req, g_021CF37C, 1) == -1)
        goto fail;
    if (NHTTP_SetVerifyOption(req, 0) == -1)
        goto fail;
    if (NHTTP_AddHeaderField(req, g_021CF498, g_021D3C69) == -1)
        goto fail;
    if (NHTTP_AddPostDataAscii(req, g_021CF4A4, g_021D3BCD) == -1)
        goto fail;
    if (NHTTP_AddPostDataAscii(req, g_021CF4AC, g_021D3BC4) == -1)
        goto fail;
    if (NHTTP_AddPostDataAscii(req, g_021CF4B8, g_021D3C50) == -1)
        goto fail;
    if (NHTTP_AddPostDataAscii(req, g_021CF4C0, g_021D3B9C.token) == -1)
        goto fail;
    if (NHTTP_AddPostDataAscii(req, g_021CF4C8, g_021D3C0A) == -1)
        goto fail;
    if (NHTTP_AddPostDataAscii(req, g_021CF4D0, g_021D3BE4) == -1)
        goto fail;
    if (NHTTP_AddPostDataAscii(req, g_021CF4D8, strAction) == -1)
        goto fail;
    if (g_021D3B9C.p3C != 0 && NHTTP_AddPostDataAscii(req, g_021CF4E0, g_021D3B9C.p3C) == -1)
        goto fail;
    if (g_021D3B9C.p40 != 0 && NHTTP_AddPostDataAscii(req, g_021CF4E8, g_021D3B9C.p40) == -1)
        goto fail;
    if (g_021D3B9C.p44 != 0 && NHTTP_AddPostDataAscii(req, g_021CF4F0, g_021D3B9C.p44) == -1)
        goto fail;
    if (g_021D3B9C.apinfo != 0 && NHTTP_AddPostDataAscii(req, g_021CF4F8, g_021D3BF5) == -1)
        goto fail;
    if (opt != 0) {
        n = DWCi_Ndi_strlen(opt);
        if (n > 0x40) {
            DWCi_NdSetError(5, 0);
            freeHttp(hrq, req);
            return 0;
        }
        DWCi_Ndi_memclr(g_021D3CCC, 0x59);
        DWCi_Ndi_encodeBASE64(g_021D3CCC, opt, n);
        if (NHTTP_AddPostDataAscii(req, g_021CF500, g_021D3CCC) == -1)
            goto fail;
    }
    DWCi_Ndi_decodeBASE64(strTemp, g_021D3BCD, 0x80);
    DWCi_Ndi_decodeBASE64(strTemp, g_021D3BC4, 0x80);
    DWCi_Ndi_decodeBASE64(strTemp, g_021D3C50, 0x80);
    DWCi_Ndi_decodeBASE64(strTemp, g_021D3B9C.token, 0x80);
    DWCi_Ndi_decodeBASE64(strTemp, g_021D3C0A, 0x80);
    DWCi_Ndi_decodeBASE64(strTemp, g_021D3BE4, 0x80);
    DWCi_Ndi_decodeBASE64(strTemp, strAction, 0x80);
    DWCi_Ndi_decodeBASE64(strTemp, g_021D3BF5, 0x80);
    if (g_021D3B9C.p3C != 0)
        DWCi_Ndi_decodeBASE64(strTemp, g_021D3B9C.p3C, 0x80);
    if (g_021D3B9C.p40 != 0)
        DWCi_Ndi_decodeBASE64(strTemp, g_021D3B9C.p40, 0x80);
    if (g_021D3B9C.p44 != 0)
        DWCi_Ndi_decodeBASE64(strTemp, g_021D3B9C.p44, 0x80);
    if (opt != 0)
        DWCi_Ndi_decodeBASE64(strTemp, g_021D3CCC, 0x80);
    return 1;
fail:
    freeHttp(hrq, req);
    DWCi_NdSetError(1, 0);
    return 0;
}




/*
 * sdk:      runHttp (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
int func_021C70D4(int unused, void *req)
{
	int err;
	func_021C78E0();
	err = func_021BF308(req);
	if (err) {
		req = 0;
		func_021C659C(3, (int)req);
		func_021C78F4();
		return (int)req;
	}
	g_021D3B9C.handle = (void *)req;
	func_021C78F4();
	return 1;
}




int DWCi_NdGetFileListAsync(DWCNdFileInfo *filelist, int offset, int num)
{
    int lenBuf;
    char *pBuf;
    char *strOffset;
    char *strNum;
    int lenNum;
    int lenOffset;
    tagDWCi_Ndi_HTTPREQ *hrq;
    void *req;
    char strBuf[12];

    lenBuf = num << 8;
    if (lenBuf < 0x80)
        lenBuf = 0x80;
    pBuf = g_021D3B9C.alloc(lenBuf, 4);
    if (pBuf == 0) {
        DWCi_NdSetError(1, 0);
        return 0;
    }
    lenOffset = DWCi_Ndi_intToStr(strBuf, offset);
    strOffset = g_021D3B9C.alloc(DWCi_Ndi_getEncodeLenBASE64(lenOffset) + 1, 4);
    if (strOffset == 0) {
        g_021D3B9C.free(pBuf);
        DWCi_NdSetError(1, 0);
        return 0;
    }
    strOffset[DWCi_Ndi_encodeBASE64(strOffset, strBuf, lenOffset)] = 0;
    lenNum = DWCi_Ndi_intToStr(strBuf, num);
    strNum = g_021D3B9C.alloc(DWCi_Ndi_getEncodeLenBASE64(lenNum) + 1, 4);
    if (strNum == 0) {
        g_021D3B9C.free(strOffset);
        g_021D3B9C.free(pBuf);
        DWCi_NdSetError(1, 0);
        return 0;
    }
    strNum[DWCi_Ndi_encodeBASE64(strNum, strBuf, lenNum)] = 0;
    if (!setupHttp(&hrq, &req, DWCiNd_action_list, pBuf, lenBuf, 0)) {
        g_021D3B9C.free(strNum);
        g_021D3B9C.free(strOffset);
        g_021D3B9C.free(pBuf);
        return 0;
    }
    if (NHTTP_AddPostDataAscii(req, "offset", strOffset) == -1)
        goto error;
    if (NHTTP_AddPostDataAscii(req, "num", strNum) == -1)
        goto error;
    hrq->reason = 2;
    hrq->param.list.filelist = filelist;
    hrq->param.list.strOffset = strOffset;
    hrq->param.list.strNum = strNum;
    hrq->param.list.num = num;
    hrq->param.list.pBuf = pBuf;
    if (runHttp(hrq, req))
        return 1;
    g_021D3B9C.free(strNum);
    g_021D3B9C.free(strOffset);
    g_021D3B9C.free(pBuf);
    return 0;

error:
    g_021D3B9C.free(strNum);
    g_021D3B9C.free(strOffset);
    g_021D3B9C.free(pBuf);
    freeHttp(hrq, req);
    DWCi_NdSetError(1, 0);
    return 0;
}




int func_021C73C0(DWCNdFileInfo *filelist, char *buf, unsigned int bufsize, char *opt)
{
    tagDWCi_Ndi_HTTPREQ *hrq;
    void *req;
    int fnameLen;
    char *encName;
    int n;

    if (bufsize < filelist->size) {
        func_021C659C(5, 0);
        return 0;
    }
    fnameLen = func_021C7A18((const u8 *)filelist->name);
    if (fnameLen > 32) {
        func_021C659C(5, 0);
        return 0;
    }
    if (fnameLen > 0)
        n = func_021C60AC(fnameLen);
    else
        n = 0;
    encName = g_021D3B9C.alloc(n + 1, 4);
    if (encName == 0) {
        func_021C659C(1, 0);
        return 0;
    }
    if (!func_021C6C0C(&hrq, &req, g_021CE0D7, buf, filelist->size, opt)) {
        g_021D3B9C.free(encName);
        return 0;
    }
    if (n > 0) {
        encName[func_021C60C8(encName, filelist->name, fnameLen)] = 0;
        if (func_021BE748(req, "contents", encName) == -1)
            goto error;
    }
    hrq->reason = 3;
    hrq->param.getfile.encName = encName;
    hrq->param.getfile.size = filelist->size;
    if (func_021C70D4((int)hrq, req))
        return 1;
    g_021D3B9C.free(encName);
    return 0;

error:
    func_021C6BEC(hrq, (int)req);
    g_021D3B9C.free(encName);
    func_021C659C(1, 0);
    return 0;
}




/*
 * sdk:      DWCi_NdGetProgress (libdwcnd.TWL.HYB.a dwci_nd.o)
 */
int func_021C757C(unsigned long *received, unsigned long *contentlen)
{
    if (g_021D3B9C.initialized == 0)
        return 0;
    return NHTTP_GetConnectionProgress(g_021D3B9C.handle, received, contentlen) == 0;
}





/*
 * sdk:      DWCi_Ndi_response_count (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
int func_021C75BC(void *res, tagDWCi_Ndi_HTTPREQ *hrq)
{
	char *body;
	int bodyLen;
	unsigned long bodyBufSize;
	bodyLen = func_021BF3E4(res, &body, &bodyBufSize);
	if (bodyLen >= 0) {
		*hrq->param.getcount.count = func_021C7A5C(body, bodyLen);
		return *hrq->param.getcount.count >= 0;
	}
	return 0;
}





/*
 * sdk:      DWCi_Ndi_response_contents (libdwcnd.TWL.HYB.a dwci_nd.o)
 */
int func_021C7614(void *res, tagDWCi_Ndi_HTTPREQ *hrq)
{
    char *body;
    int bodyLen;
    unsigned long bodyBufSize;

    bodyLen = NHTTP_GetBodyBuffer(res, &body, &bodyBufSize);
    return bodyLen == hrq->param.getfile.size;
}





int DWCi_Ndi_response_list(void *res, tagDWCi_Ndi_HTTPREQ *hrq)
{
    char *body;
    int bodyLen;
    int n;
    int p;
    int state;
    int bgn;
    int isComplete;
    int detect0x0d;
    DWCNdFileInfo *pfi;
    int size;
    unsigned long bodyBufSize;
    char *contentlen;
    char tempBuf[104];
    int decordedLen;

    isComplete = 0;
    DWCi_Ndi_memclr(hrq->param.getfile.encName, hrq->param.getfile.size * 0xb0);
    if (NHTTP_GetHeaderField(res, g_021CF528, &contentlen) > 0) {
        if (contentlen[0] == '0' && contentlen[1] == 0)
            return 1;
    }
    bodyLen = NHTTP_GetBodyBuffer(res, &body, &bodyBufSize);
    if (bodyLen > 0) {
        p = 0;
        for (n = 0; n < hrq->param.getfile.size; n++) {
            if (p >= bodyLen) { isComplete = 1; break; }
            pfi = (DWCNdFileInfo *)(hrq->param.getfile.encName + n * 0xb0);
            state = 0;
            bgn = p;
            detect0x0d = 0;
            isComplete = 0;
            for (; p < bodyLen; p++) {
                if (body[p] == 0x0d) {
                    detect0x0d = 1;
                    continue;
                }
                if (detect0x0d) {
                    if (body[p] == 0x0a) {
                        if (state == 5) {
                            if (p - 1 - bgn > 8)
                                goto done;
                            decordedLen = DWCi_Ndi_strToInt(body + bgn, p - 1 - bgn);
                            if (decordedLen < 0)
                                goto done;
                            pfi->size = decordedLen;
                        }
                        p++;
                        isComplete = state >= 5;
                        break;
                    }
                } else if (body[p] == 0x09) {
                    switch (state) {
                    case 0:
                        if (p - bgn > sizeof(pfi->name) - 1)
                            goto done;
                        DWCi_Ndi_memcpy(pfi->name, body + bgn, p - bgn);
                        break;
                    case 1:
                        size = p - bgn;
                        decordedLen = DWCi_Ndi_getDecodeLenBASE64(size);
                        if (decordedLen > sizeof(pfi->explain))
                            goto done;
                        decordedLen = DWCi_Ndi_decodeBASE64(tempBuf, body + bgn, size);
                        if (decordedLen > sizeof(pfi->explain))
                            decordedLen = sizeof(pfi->explain);
                        DWCi_Ndi_memcpy(pfi->explain, tempBuf, decordedLen);
                        pfi->explain[50] = 0;
                        break;
                    case 2:
                        if (p - bgn > sizeof(pfi->param1) - 1)
                            goto done;
                        DWCi_Ndi_memcpy(pfi->param1, body + bgn, p - bgn);
                        break;
                    case 3:
                        if (p - bgn > sizeof(pfi->param2) - 1)
                            goto done;
                        DWCi_Ndi_memcpy(pfi->param2, body + bgn, p - bgn);
                        break;
                    case 4:
                        if (p - bgn > sizeof(pfi->param3) - 1)
                            goto done;
                        DWCi_Ndi_memcpy(pfi->param3, body + bgn, p - bgn);
                        break;
                    case 5:
                        if (p - bgn > 8)
                            goto done;
                        decordedLen = DWCi_Ndi_strToInt(body + bgn, p - bgn);
                        if (decordedLen < 0)
                            goto done;
                        pfi->size = decordedLen;
                        break;
                    }
                    state++;
                    bgn = p + 1;
                }
                detect0x0d = 0;
            }
        }
    }
done:
    return isComplete;
}





int func_021C78C4(void)
{
    func_02086004((void *)0x021D3C38);
    return 1;
}
