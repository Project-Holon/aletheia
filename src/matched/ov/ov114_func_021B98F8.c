/*
 * function: NHTTP_RAP_CreatePostRequest
 * address: 0x021B98F8
 * packet: pkt_ov114_021B98F8
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * NHTTP_RAP_Alloc 0x021B95A0 thumb ov114
 * NHTTP_RAP_Free 0x021B95B0 thumb ov114
 * NHTTP_RAP_ConnectionCallback 0x021B95C0 thumb ov114
 * sNHTTPRapStrings 0x021CE2D4 data a4
 * sNHTTPRapRequestTable 0x021CE284 data a4
 * sNHTTPRapRootCA 0x021CE280 data a4
 * NHTTP_Startup 0x021BE648 arm ov114
 * NHTTP_CreateConnection 0x021BF04C arm ov114
 * NHTTP_GetError 0x021BE6AC arm ov114
 * NHTTP_SetRootCA 0x021BE9C8 arm ov114
 * NHTTP_AddPostDataRaw 0x021BE79C arm ov114
 * func_02034714 0x02034714 arm
 * MI_CpuFill8 0x02082BCC arm
 * func_0208CADC 0x0208CADC arm
 */
#include "../include/Obj10329.h"
#include "../include/G_Pair.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern char sNHTTPRapStrings[], sNHTTPRapRootCA[];
extern unsigned int NHTTP_RAP_Alloc(unsigned int, unsigned int);
extern void NHTTP_RAP_Free(int);
extern int NHTTP_RAP_ConnectionCallback(int, int, unsigned int *);
extern struct Pair sNHTTPRapRequestTable;
extern int NHTTP_Startup(int a, int b, int c);
extern void *NHTTP_CreateConnection(char *url_p, int method, char *buf_p, u32 len, int (*callback)(void *, int, void *), void *userParam_p);
extern u32 NHTTP_GetError(void);
extern int NHTTP_SetRootCA(int a, int b, int c);
extern int NHTTP_AddPostDataRaw(void *handle, void *value_p, unsigned long length);
extern void func_02034714(const char *, u32, const char *);
extern void MI_CpuFill8(int, int, int);
extern char *func_0208CADC(char *, const char *);
int NHTTP_RAP_CreatePostRequest(u8 *p)
{
    int h;
    if (p == 0) return 0;
    if (NHTTP_Startup((int)NHTTP_RAP_Alloc, (int)NHTTP_RAP_Free, 12) != 0) {
        func_02034714(sNHTTPRapStrings, 0, sNHTTPRapStrings);
        return 0;
    }
    MI_CpuFill8((int)(p+0x410), 0, 4);
    func_0208CADC((char *)(p+0x410), (char *)((u32 *)&sNHTTPRapRequestTable)[14]);
    h = (int)NHTTP_CreateConnection((char *)((u32 *)&sNHTTPRapRequestTable)[14], ((u32 *)&sNHTTPRapRequestTable)[15], (char *)(p+0x10), 0x400, (int (*)(void *, int,  void *))NHTTP_RAP_ConnectionCallback, 0);
    if (h == 0) {
        NHTTP_GetError();
        if (h == 0) func_02034714(sNHTTPRapStrings, 0, sNHTTPRapStrings);
        return 0;
    }
    ((struct Obj10329 *)p)->fC = h;
    if (NHTTP_SetRootCA(h, (int)sNHTTPRapRootCA, 1) < 0) {
        func_02034714(sNHTTPRapStrings, 0, sNHTTPRapStrings);
        return 0;
    }
    NHTTP_AddPostDataRaw((void *)h, (void *)(((struct Obj10329 *)p)->f0), ((struct Obj10329 *)p)->f4);
    return 1;
}
