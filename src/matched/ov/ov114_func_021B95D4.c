/*
 * function: NHTTP_RAP_CreateRequest
 * address: 0x021B95D4
 * packet: pkt_ov114_021B95D4
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: lead ends 021B973C; the following null-safe getter already has
 * src/matched/ov/ov114_func_021B973C.c and pkt_ov114_021B973C.json coverage.
 * lever: two-word Pair entries preserve the table's format/mode stride.
 * symbols:
 *   NHTTP_RAP_Alloc 0x021B95A0 thumb ov114
 *   NHTTP_RAP_Free 0x021B95B0 thumb ov114
 *   NHTTP_RAP_ConnectionCallback 0x021B95C0 thumb ov114
 *   sNHTTPRapStrings 0x021CE2D4 data a4
 *   sNHTTPRapRequestTable 0x021CE284 data a4
 *   sNHTTPRapRootCA 0x021CE280 data a4
 *   NHTTP_Startup 0x021BE648 arm ov114
 *   NHTTP_CreateConnection 0x021BF04C arm ov114
 *   NHTTP_SetRootCA 0x021BE9C8 arm ov114
 *   NHTTP_AddHeaderField 0x021BE6BC arm ov114
 *   NHTTP_SetBasicAuthorization 0x021BE8E8 arm ov114
 *   func_02034714 0x02034714 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_0208D80C 0x0208D80C arm
 */
#include "../include/Obj08035.h"
#include "../include/G_Pair.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 format,mode; } Pair;
extern char sNHTTPRapStrings[],sNHTTPRapRootCA[];
extern struct Pair sNHTTPRapRequestTable[];
extern unsigned int NHTTP_RAP_Alloc(unsigned int,unsigned int);
extern void NHTTP_RAP_Free(int);
extern int NHTTP_RAP_ConnectionCallback(int,int,u32 *);
extern int NHTTP_Startup(int a, int b, int c);
extern void *NHTTP_CreateConnection(char *url_p, int method, char *buf_p, u32 len, int (*callback)(void *, int, void *), void *userParam_p);
extern int NHTTP_SetRootCA(int a, int b, int c);
extern int NHTTP_AddHeaderField(int,const char *,const char *);
extern int NHTTP_SetBasicAuthorization(void *handle, char *username_p, char *password_p);
extern void func_02034714(const char *,u32,const char *);
extern void MI_CpuFill8(void *,int,unsigned);
extern int func_0208D80C(char *,int,const char *,...);
int NHTTP_RAP_CreateRequest(int index,u8 *p)
{
    int h;
    if(NHTTP_Startup((int)NHTTP_RAP_Alloc,(int)NHTTP_RAP_Free,12)!=0) {
        func_02034714(sNHTTPRapStrings,0,sNHTTPRapStrings);
        return 0;
    }
    if(p==0) return 0;
    MI_CpuFill8(p+0x410,0,4);
    if(index==4) func_0208D80C((char *)(p+0x410),400,(char *)sNHTTPRapRequestTable[index].format,((struct Obj08035 *)p)->f8+69);
    else func_0208D80C((char *)(p+0x410),400,(char *)sNHTTPRapRequestTable[index].format,((struct Obj08035 *)p)->f5A4,21,2,1,((struct Obj08035 *)p)->f8+69);
    h=(int)NHTTP_CreateConnection((char *)((u32)(p+0x410)),sNHTTPRapRequestTable[index].mode,(char *)(p+0x10),1024,(int (*)(void *, int,  void *))NHTTP_RAP_ConnectionCallback,(void *)((int)p));
    if(h==0) func_02034714(sNHTTPRapStrings,0,sNHTTPRapStrings);
    if(h==0) return 0;
    ((struct Obj08035 *)p)->fC=h;
    if(NHTTP_SetRootCA(h,(int)sNHTTPRapRootCA,1)<0) {
        func_02034714(sNHTTPRapStrings,0,sNHTTPRapStrings);
        return 0;
    }
    if(NHTTP_AddHeaderField(h,sNHTTPRapStrings+4,sNHTTPRapStrings+12)!=0) {
        func_02034714(sNHTTPRapStrings,0,sNHTTPRapStrings);
        return 0;
    }
    if(NHTTP_AddHeaderField(h,sNHTTPRapStrings+16,sNHTTPRapStrings+28)!=0) {
        func_02034714(sNHTTPRapStrings,0,sNHTTPRapStrings);
        return 0;
    }
    if(NHTTP_SetBasicAuthorization((void *)h,sNHTTPRapStrings+40,sNHTTPRapStrings+48)!=0) {
        func_02034714(sNHTTPRapStrings,0,sNHTTPRapStrings);
        return 0;
    }
    return 1;
}
