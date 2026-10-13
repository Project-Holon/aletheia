/*
 * function: NHTTPi_InitSystemInfo
 * address:  0x021BEEC4
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NHTTPi_InitBgnEndInfo  0x021BA7DC  arm  ov114
 *   NHTTPi_InitListInfo  0x021BACEC  arm  ov114
 *   NHTTPi_InitRequestInfo  0x021BB3C0  arm  ov114
 *   NHTTPi_InitThreadInfo  0x021BBE94  arm  ov114
 *   NHTTPi_GetBgnEndInfoP  0x021BEF3C  arm  ov114
 *   NHTTPi_GetListInfoP  0x021BEF40  arm  ov114
 *   NHTTPi_GetReqInfoP  0x021BEF48  arm  ov114
 *   NHTTPi_GetThreadInfoP  0x021BEF50  arm  ov114
 *   NHTTPi_GetMutexInfoP  0x021BEF58  arm  ov114
 *   NHTTPi_InitMutexInfo  0x021BEF98  arm  ov114
 *
 *
 * Constructs the module object: zeroes each of its four sub-blocks.
 */

typedef unsigned char u8;
typedef unsigned int u32;
void NHTTPi_GetBgnEndInfoP(void);
void NHTTPi_InitBgnEndInfo(void);
void *NHTTPi_GetListInfoP(int p);
void NHTTPi_InitListInfo(u8 *);
void *NHTTPi_GetReqInfoP(int p);
void NHTTPi_InitRequestInfo(u8 *);
void *NHTTPi_GetMutexInfoP(int p);
void NHTTPi_InitMutexInfo(u8 *);
void *NHTTPi_GetThreadInfoP(int p);
void NHTTPi_InitThreadInfo(u8 *);

void NHTTPi_InitSystemInfo(u8 *p)
{
    NHTTPi_GetBgnEndInfoP();
    NHTTPi_InitBgnEndInfo();
    NHTTPi_InitListInfo(NHTTPi_GetListInfoP((int)p));
    NHTTPi_InitRequestInfo(NHTTPi_GetReqInfoP((int)p));
    NHTTPi_InitMutexInfo(NHTTPi_GetMutexInfoP((int)p));
    NHTTPi_InitThreadInfo(NHTTPi_GetThreadInfoP((int)p));
}
