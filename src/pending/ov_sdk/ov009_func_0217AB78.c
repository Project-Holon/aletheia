/*
 * function: DWCi_Netcheck_Thread
 * address:  0x0217AB78
 * packet:   pkt_ov009_0217AB78
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      DWCi_Netcheck_Thread (sdk/TwlDWC/lib/ARM9-TS/Rom/libdwcauth.TWL.HYB.a dwc_netcheck.o)
 *
 * Full-body transcription taken from the vendor object listing, not from the
 * previous partial: dwc_netcheck.o's .text is byte-identical to the image
 * (sdkobj: "0 concrete mismatches of 2845 concrete bytes"), so the listing is
 * ground truth and `sdkobj <addr> --region ov009` supplies the DWARF locals with
 * their registers and the frame map.  What is transcribed here:
 *   frame 0x290, push {r3,r4,r5,r6,r7,r8,sb,sl,fp,lr}   (both correct now)
 *   local map from the DWARF: url_len [sp+8], retcode [sp+20], wifiinfo [sp+24],
 *     calinfo [sp+38] (0x94 bytes), authresult [sp+cc] (0x1c4 bytes: the frame is
 *     exactly 0x38+0x94+0x1c4 = 0x290)
 *   alloc/free are locals loaded once from nc+0x1108 / nc+0x110c (r5/r6 in the image)
 *   the whole call graph in image order: 3x (Create/FinishHeader/StartThread/
 *   IsThreadTerminated+JoinThread), 5x ParseResult, 9x GetResult+atoi, 3x
 *   Add_PostBase64Item, 4x GetBase64DecodedResult plus the strlen/alloc/strncpy
 *   buffer paths, 6x Destroy, and the 13 SetError exits + the free(data/url/wait)
 *   cleanup at 0x217b734.
 *   the constant pool, recovered by resolving every `ldr rX,[pc,#imm]` against the
 *   function's own literal pool: DWChttp, bFirst_0, DWCnetcheckhttpparam,
 *   OSi_ThreadInfo, g_021A2700, errno, DWCauthhttpparam, g_021A270C/272C/2734/273C,
 *   DWCnetcheckauthparam, g_021A274C/2754/275C/2768/276C/2774 and the constants
 *   40000 (/2 for the first-stage timeout), 302, -23302, 20000, 180000, 120000.
 *
 * blocker: STRUCTURE + REGISTER COLOURING.  compiled 2988 vs 3184 (SIZE, -196
 *   reachable bytes), 2546 concrete bytes differ, 104/104 relocations resolved.
 *   Wave-8 progress: the `preauth:` setup block and the `auth3:` parse tail were
 *   spurious duplicates (image has only 4 DWC_Http_Create / 4 Add_PostBase64Item
 *   / 4 FinishHeader / 2 GetCalInfo / 3 ParseResult sites; `preauth` and `auth3`
 *   added a 5th/4th), and stage2's `nc->0x1118==0` arm jumps to `parse_auth`
 *   (0x217af70), not to a setup.  Removing them cut 3408->2988 and 2912->2546.
 *   The remaining -196 is real image code the transcription still lacks (its
 *   tail/parse structure), plus the register colouring below.
 *   Lever applied: declared url before data and renamed interval->wait_sec to
 *   the DWARF spellings gave -33 concrete mismatches (2945->2912) but +8 bytes.
 *   The +216 means a whole extra block is emitted; the duplicated shared tails
 *   (stage2 vs preauth, the auth/`auth_r`/auth3 copies) are the prime suspect -
 *   the image cross-jumps those, this transcription spells each out.
 *   sdkobj 0x0217AB78 --region ov009 --brief gives the true DWARF local set and
 *   registers, which the current declaration list does not match:
 *     url r7, data r8, wait r9/sb, alloc r5, free r6, httpretcodei r10/sl,
 *     wait_sec r11/fp, wait_len r10, data_len r11, bodywayport r10, body302 r11,
 *     upper locals ... url_len [fb+8], retcode [fb+32], calinfo [fb+56],
 *     authresult [fb+204], DWC_netcheck_wifiinfo [fb+36], httpretcode r0.
 *   So the real names are url/data/wait (url FIRST - image `mov r7,#0` is url,
 *   then `mov r8,r7` is data), `wait_sec` (not `wait_sec`), and two extra body
 *   pointers `bodywayport`/`body302`.  The invented locals here (buf, st,
 *   m2..m5, t20000) are not in the DWARF and rotate the colouring; the image
 *   prologue materialises -2..-5 and folds 40000/2 in-place.  Do not sweep pins:
 *   the row is a 4.0.0.1025 stamp; the corrected U21-U30 finding says body.
 *
 * symbols:
 *   DWC_Http_Create                  0x0217956c arm
 *   DWC_Http_Destroy                 0x02179cf4 arm
 *   DWC_Http_FinishHeader            0x0217967c arm
 *   OS_GetThreadPriority             0x02085a30 arm
 *   DWC_Http_StartThread             0x02179718 arm
 *   OS_IsThreadTerminated            0x0208574c arm
 *   OS_JoinThread                    0x02085710 arm
 *   DWC_Http_ParseResult             0x0217a484 arm
 *   DWC_Http_GetResult               0x0217a728 arm
 *   atoi                             0x020964e0 arm
 *   strcmp                           0x020948e0 arm
 *   DWC_Auth_GetCalInfoFromNVRAM     0x02178f4c arm
 *   DWC_Auth_SetCalInfoToHttp        0x02179218 arm
 *   DWC_Http_Add_PostBase64Item      0x02179f3c arm
 *   strlen                           0x0209477c arm
 *   DWCi_Netcheck_SetError           0x0217b7e8 arm
 *   strncpy                          0x02094860 arm
 *   DWCi_BM_GetWiFiInfo              0x02058518 arm
 *   DWC_Auth_Create                  0x02177ee8 arm
 *   DWC_Auth_Join                    0x02178194 arm
 *   DWC_Auth_GetError                0x021781dc arm
 *   DWC_Auth_GetResult               0x02178224 arm
 *   DWC_Auth_Destroy                 0x02178144 arm
 *   DWC_Http_GetBase64DecodedResult  0x0217a77c arm
 *   DWC_Http_Add_Body                0x0217a044 arm
 *   OS_Sleep                         0x02085a38 arm
 *   DWChttp                          0x021ace5c data
 *   _ZZ23DWC_SimpleNetcheckAsynciE6bFirst_0 0x021a26d4 data
 *   DWCnetcheckhttpparam             0x021ace8c data
 *   OSi_ThreadInfo                   0x02150fec data
 *   g_021A2700                       0x021a2700 data
 *   errno                            0x02153fac data
 *   DWCauthhttpparam                 0x021a2358 data
 *   g_021A270C                       0x021a270c data
 *   g_021A272C                       0x021a272c data
 *   g_021A2734                       0x021a2734 data
 *   g_021A273C                       0x021a273c data
 *   DWCnetcheckauthparam             0x021acea8 data
 *   g_021A274C                       0x021a274c data
 *   g_021A2754                       0x021a2754 data
 *   g_021A275C                       0x021a275c data
 *   g_021A2768                       0x021a2768 data
 *   g_021A276C                       0x021a276c data
 *   g_021A2774                       0x021a2774 data
 *
 * Verified with:
 *   python tools/match.py one --src ... --func DWCi_Netcheck_Thread --addr 0x0217AB78
 *     --region ov009 --arm --cc 1.1p1 --lang c99 --diff
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *http;          /* +0x00 */
    void *nc;            /* +0x04 */
    int   f08;           /* +0x08 */
    int   f0c;           /* +0x0c */
    int   f10;           /* +0x10 */
    int   f14;           /* +0x14 */
    int   f18;           /* +0x18 */
    int   f1c;           /* +0x1c */
    int   f20;           /* +0x20 */
    int   f24;           /* +0x24 */
    int   f28;           /* +0x28 */
    int   f2c;           /* +0x2c */
    int   p00;           /* +0x30 DWCnetcheckhttpparam.f00 */
    int   p04;           /* +0x34 */
    int   p08;           /* +0x38 */
    int   p0c;           /* +0x3c */
    int   p10;           /* +0x40 */
    int   p14;           /* +0x44 */
    int   p18;           /* +0x48 */
} NetcheckGlob;
extern NetcheckGlob DWChttp;         /* 0x021ace5c */
extern u8 DWCnetcheckhttpparam[];    /* 0x021ace8c */
extern int DWCauthhttpparam;         /* 0x021a2358 */
extern int DWCnetcheckauthparam;     /* 0x021acea8 */
extern u8 OSi_ThreadInfo[];          /* 0x02150fec */
extern int errno;                    /* 0x02153fac */
extern int _ZZ23DWC_SimpleNetcheckAsynciE6bFirst_0;  /* 0x021a26d4 */
extern char g_021A2700[];            /* 0x021a2700 */
extern char g_021A270C[];            /* 0x021a270c */
extern char g_021A272C[];            /* 0x021a272c */
extern char g_021A2734[];            /* 0x021a2734 */
extern char g_021A273C[];            /* 0x021a273c */
extern char g_021A274C[];            /* 0x021a274c */
extern char g_021A2754[];            /* 0x021a2754 */
extern char g_021A275C[];            /* 0x021a275c */
extern char g_021A2768[];            /* 0x021a2768 */
extern char g_021A276C[];            /* 0x021a276c */
extern char g_021A2774[];            /* 0x021a2774 */

extern int DWC_Http_Create(void *http, void *param);
extern void DWC_Http_Destroy(void *http);
extern int DWC_Http_FinishHeader(void *http);
extern int OS_GetThreadPriority(void *thread);
extern void DWC_Http_StartThread(void *http, unsigned long prio);
extern int OS_IsThreadTerminated(void *thread);
extern void OS_JoinThread(void *thread);
extern int DWC_Http_ParseResult(void *http, int noparsebody);
extern char *DWC_Http_GetResult(void *http, char *label);
extern int atoi(const char *p);
extern int strcmp(const char *a, const char *b);
extern int DWC_Auth_GetCalInfoFromNVRAM(void *cal);
extern int DWC_Auth_SetCalInfoToHttp(void *http, void *calinfo, int allowessid);
extern int DWC_Http_Add_PostBase64Item(void *http, char *label, char *data, unsigned long len);
extern unsigned long strlen(const char *p);
extern void DWCi_Netcheck_SetError(int error);
extern char *strncpy(char *dst, const char *src, unsigned long n);
extern void DWCi_BM_GetWiFiInfo(void *buf);
extern int DWC_Auth_Create(void *param, void *http);
extern void DWC_Auth_Join(void);
extern int DWC_Auth_GetError(void);
extern void DWC_Auth_GetResult(void *result);
extern void DWC_Auth_Destroy(void);
extern int DWC_Http_GetBase64DecodedResult(void *http, char *label, char *buffer, unsigned long len);
extern int DWC_Http_Add_Body(void *http, char *data);
extern void OS_Sleep(unsigned long msec);

static void DWCi_Netcheck_Thread(void)
{
    void *(*alloc)(unsigned long, long);
    void (*freefn)(unsigned long, void *, long);
    char *url = 0;
    char *data = 0;
    char *wait = 0;
    int wait_len;
    int url_len;
    int data_len;
    int wait_sec;
    int httpretcodei;
    char *httpretcode;
    u8 calinfo[0x94];
    u8 authresult[0x1c4];
    u8 wifiinfo[0x14];
    char retcode[4];
    int m2 = -2;
    int m3 = -3;
    int m4 = -4;
    int m5 = -5;
    int t20000 = 40000 / 2;
    u8 *buf;
    int st;

    alloc = *(void *(**)(unsigned long, long))((u8 *)DWChttp.nc + 0x1108);
    freefn = *(void (**)(unsigned long, void *, long))((u8 *)DWChttp.nc + 0x110c);

loop:
    DWChttp.p00 = *(int *)((u8 *)&_ZZ23DWC_SimpleNetcheckAsynciE6bFirst_0 + 4);
    DWChttp.p04 = 1;
    DWChttp.p08 = 0x1000;
    DWChttp.p0c = (int)alloc;
    DWChttp.p10 = (int)freefn;
    DWChttp.p18 = t20000;
    *(int *)((u8 *)DWChttp.nc + 0x1004) = m2;
    if (DWC_Http_Create((u8 *)DWChttp.http, (void *)DWCnetcheckhttpparam) != 0)
        goto err1;
    if (DWC_Http_FinishHeader((u8 *)DWChttp.http) != 0)
        goto err1;
    DWC_Http_StartThread((u8 *)DWChttp.http, OS_GetThreadPriority(OSi_ThreadInfo) - 1);
    if (*(int *)((u8 *)DWChttp.http + 0x1be0) != 0 && !OS_IsThreadTerminated((u8 *)DWChttp.http + 0x1f74))
        OS_JoinThread((u8 *)DWChttp.http + 0x1f74);

    st = *(int *)((u8 *)DWChttp.http + 0x1020);
    if (st == 8)
        goto parse0;
    if (st == 2)
        *(int *)((u8 *)DWChttp.nc + 0x1004) = -1;
    DWC_Http_Destroy((u8 *)DWChttp.http);
    DWCi_Netcheck_SetError(3);
    goto out;

parse0:
    if (DWC_Http_ParseResult((u8 *)DWChttp.http, 0) != 1) {
        DWC_Http_Destroy((u8 *)DWChttp.http);
        goto err2;
    }
    httpretcode = DWC_Http_GetResult((u8 *)DWChttp.http, g_021A2700);
    httpretcodei = atoi(httpretcode);
    if (errno == 0x22)
        goto err2;
    if (httpretcodei == 0xc8)
        goto res_ok;
    if (httpretcodei == 302)
        goto stage2;
    DWC_Http_Destroy((u8 *)DWChttp.http);
    DWCi_Netcheck_SetError(10);
    goto out;

res_ok:                                   /* 0x217ad48 */
    DWChttp.f0c = *(int *)((u8 *)DWChttp.http + 0x112c);
    goto wifi;                            /* 0x217b008 */

stage2:                                   /* 0x217ad5c */
    DWChttp.f14 = 1;
    if (*(int *)((u8 *)DWChttp.nc + 0x1118) == 0)
        goto parse_auth;                  /* 0x217af70 */
    *(int *)((u8 *)DWChttp.nc + 0x1004) = -6;
    DWC_Http_Destroy((u8 *)DWChttp.http);
    DWChttp.p00 = DWCauthhttpparam;
    DWChttp.p04 = 0;
    DWChttp.p08 = 0x200;
    DWChttp.p0c = (int)alloc;
    DWChttp.p10 = (int)freefn;
    DWChttp.p18 = 20000;
    if (strcmp((char *)DWCauthhttpparam, g_021A270C) != 0)
        DWChttp.p14 = 1;
    if (DWC_Http_Create((u8 *)DWChttp.http, (void *)DWCnetcheckhttpparam) != 0)
        goto err1;
    if (DWC_Auth_GetCalInfoFromNVRAM(calinfo) != 0) {
        if (DWC_Auth_SetCalInfoToHttp((u8 *)DWChttp.http, calinfo, 1) == 0)
            goto err8;
    } else {
        goto err8;
    }
    if (DWC_Http_Add_PostBase64Item((u8 *)DWChttp.http, g_021A272C, g_021A2734, 7) != 0)
        goto err8;
    buf = (u8 *)*(int *)((u8 *)DWChttp.nc + 0x1118);
    if (DWC_Http_Add_PostBase64Item((u8 *)DWChttp.http, g_021A273C, (char *)buf,
                                    strlen((char *)buf)) == 0)
        goto freepost;
    DWC_Http_Destroy((u8 *)DWChttp.http);
    DWCi_Netcheck_SetError(8);
    goto out;

freepost:                                 /* 0x217ae90 */
    freefn(0, *(void **)((u8 *)DWChttp.nc + 0x1118), 0);
    *(int *)((u8 *)DWChttp.nc + 0x1118) = 0;
    if (DWC_Http_FinishHeader((u8 *)DWChttp.http) != 0)
        goto err1;
    DWC_Http_StartThread((u8 *)DWChttp.http, OS_GetThreadPriority(OSi_ThreadInfo) - 1);
    if (*(int *)((u8 *)DWChttp.http + 0x1be0) != 0 && !OS_IsThreadTerminated((u8 *)DWChttp.http + 0x1f74))
        OS_JoinThread((u8 *)DWChttp.http + 0x1f74);
    st = *(int *)((u8 *)DWChttp.http + 0x1020);
    if (st == 2) {
        *(int *)((u8 *)DWChttp.nc + 0x1004) = -1;
        goto st3b;
    }
    if (st == 8)
        goto parse_auth;
st3b:
    DWC_Http_Destroy((u8 *)DWChttp.http);
    DWCi_Netcheck_SetError(3);
    goto out;

parse_auth:                               /* 0x217af70 */
    url_len = *(int *)((u8 *)DWChttp.http + 0x1a44);
    if (url_len != 0) {
        buf = (u8 *)alloc(0, strlen((char *)url_len) + 1);
        *(int *)((u8 *)DWChttp.nc + 0x1114) = (int)buf;
        if (buf == 0)
            goto err4;
        strncpy((char *)buf, (char *)url_len, strlen((char *)url_len) + 1);
        goto wifi;
    }
    DWC_Http_Destroy((u8 *)DWChttp.http);
    DWCi_Netcheck_SetError(4);
    goto out;

wifi:                                     /* 0x217b008 */
    DWC_Http_Destroy((u8 *)DWChttp.http);
    DWCi_BM_GetWiFiInfo(wifiinfo);
    if (*(int *)(wifiinfo + 4) != 0 || *(int *)(wifiinfo + 0) != 0)
        goto auth;

    *(int *)((u8 *)DWChttp.nc + 0x1004) = m3;
    *(int *)DWCnetcheckauthparam = 0;
    *(u16 *)DWCnetcheckauthparam = 0;
    *(u8 *)((u8 *)&DWCnetcheckauthparam + 0x34) = 0;
    *(void **)((u8 *)&DWCnetcheckauthparam + 0x40) = alloc;
    *(void **)((u8 *)&DWCnetcheckauthparam + 0x44) = freefn;
    if (DWC_Auth_Create((void *)&DWCnetcheckauthparam, (u8 *)DWChttp.http) != 0) {
        DWCi_Netcheck_SetError(5);
        goto out;
    }
    DWC_Auth_Join();
    if (DWC_Auth_GetError() == 0x15)
        goto auth_cancel;
    if (DWC_Auth_GetError() == 9) {
        *(int *)((u8 *)DWChttp.nc + 0x1004) = -1;
        goto auth_err6;
    }
    DWC_Auth_GetResult(authresult);
    if (DWChttp.f10 == 1 && *(int *)authresult == -23302)
        goto auth_okb;
    if (DWC_Auth_GetError() != 0xb)
        goto auth_fail;
    *(int *)((u8 *)DWChttp.nc + 0x1004) = 0;
    DWC_Auth_Destroy();
    DWCi_Netcheck_SetError(0xb);
    goto out;
auth_fail:
    *(int *)((u8 *)DWChttp.nc + 0x1004) = *(int *)authresult;
auth_err6:
    DWC_Auth_Destroy();
    DWCi_Netcheck_SetError(6);
    goto out;
auth_okb:
    DWC_Auth_Destroy();

auth_cancel:                              /* 0x217b11c */
    DWC_Auth_Destroy();

auth:                                     /* 0x217b120 */
    if (httpretcodei == 0xc8) {
        *(int *)((u8 *)DWChttp.nc + 0x1004) = 0;
        DWCi_Netcheck_SetError(11);
        goto out;
    }
    *(int *)((u8 *)DWChttp.nc + 0x1004) = m3;
    DWChttp.p00 = DWCauthhttpparam;
    DWChttp.p04 = 0;
    DWChttp.p08 = 0x1000;
    DWChttp.p0c = (int)alloc;
    DWChttp.p10 = (int)freefn;
    DWChttp.p18 = 40000;
    if (strcmp((char *)DWCauthhttpparam, g_021A270C) != 0)
        DWChttp.p14 = 1;
    if (DWC_Http_Create((u8 *)DWChttp.http, (void *)DWCnetcheckhttpparam) != 0)
        goto err1;
    if (DWC_Auth_GetCalInfoFromNVRAM(calinfo) != 0) {
        if (DWC_Auth_SetCalInfoToHttp((u8 *)DWChttp.http, calinfo, 1) == 0)
            goto err8;
    } else {
        goto err8;
    }
    if (DWC_Http_Add_PostBase64Item((u8 *)DWChttp.http, g_021A272C, g_021A274C, 5) != 0)
        goto err8;
    buf = (u8 *)*(int *)((u8 *)DWChttp.nc + 0x1114);
    if (DWC_Http_Add_PostBase64Item((u8 *)DWChttp.http, g_021A2754, (char *)buf,
                                    strlen((char *)buf)) != 0)
        goto err8;
    freefn(0, *(void **)((u8 *)DWChttp.nc + 0x1114), 0);
    *(int *)((u8 *)DWChttp.nc + 0x1114) = 0;
    if (DWC_Http_FinishHeader((u8 *)DWChttp.http) != 0)
        goto err1;
    DWC_Http_StartThread((u8 *)DWChttp.http, OS_GetThreadPriority(OSi_ThreadInfo) - 1);
    if (*(int *)((u8 *)DWChttp.http + 0x1be0) != 0 && !OS_IsThreadTerminated((u8 *)DWChttp.http + 0x1f74))
        OS_JoinThread((u8 *)DWChttp.http + 0x1f74);
    st = *(int *)((u8 *)DWChttp.http + 0x1020);
    if (st == 2) {
        *(int *)((u8 *)DWChttp.nc + 0x1004) = -1;
        goto st3c;
    }
    if (st == 3)
        goto st3d;
    if (st == 8)
        goto parse2;
st3c:                                     /* 0x217b320 -> 0x217acd0 */
    DWC_Http_Destroy((u8 *)DWChttp.http);
    DWCi_Netcheck_SetError(3);
    goto out;

st3d:                                     /* 0x217b2dc */
    DWC_Http_Destroy((u8 *)DWChttp.http);
    if (DWChttp.f10 == 1) {
        *(int *)((u8 *)DWChttp.nc + 0x1004) = 0;
        DWCi_Netcheck_SetError(11);
        goto out;
    }
    DWC_Http_Destroy((u8 *)DWChttp.http);
    DWCi_Netcheck_SetError(3);
    goto out;

parse2:                                   /* 0x217b324 */
    if (DWC_Http_ParseResult((u8 *)DWChttp.http, 0) != 1)
        goto err2;
    httpretcode = DWC_Http_GetResult((u8 *)DWChttp.http, g_021A2700);
    httpretcodei = atoi(httpretcode);
    if (errno == 0x22)
        goto err2;
    if (httpretcodei == 0xc8)
        goto res2;
    DWC_Http_Destroy((u8 *)DWChttp.http);
    if (DWChttp.f10 == 1 && httpretcodei == 302) {
        *(int *)((u8 *)DWChttp.nc + 0x1004) = 0;
        DWCi_Netcheck_SetError(11);
        goto out;
    }
    goto err2;

res2:                                     /* 0x217b3a4 */
    if (DWC_Http_GetBase64DecodedResult((u8 *)DWChttp.http, g_021A275C, retcode, 4) <= 0)
        goto err9;
    httpretcodei = atoi(retcode);
    if (errno == 0x22)
        goto err9;
    if (DWChttp.f10 == 1 && httpretcodei == 0x72) {
        *(int *)((u8 *)DWChttp.nc + 0x1004) = 0;
        DWCi_Netcheck_SetError(11);
        goto out;
    }
    if (httpretcodei >= 0x64)
        goto err9;
    data_len = DWC_Http_GetBase64DecodedResult((u8 *)DWChttp.http, g_021A2768, 0, 0);
    if (data_len <= 0)
        goto err9;
    wait_len = DWC_Http_GetBase64DecodedResult((u8 *)DWChttp.http, g_021A276C, 0, 0);
    if (wait_len <= 0)
        goto err9;
    url_len = DWC_Http_GetBase64DecodedResult((u8 *)DWChttp.http, g_021A2774, 0, 0);
    data = (char *)alloc(0, data_len + 1);
    if (data == 0)
        goto err4;
    url = (char *)alloc(0, wait_len + 1);
    if (url == 0)
        goto err4;
    if (url_len > 0) {
        wait = (char *)alloc(0, url_len + 1);
        if (wait == 0)
            goto err4;
    }
    if (DWC_Http_GetBase64DecodedResult((u8 *)DWChttp.http, g_021A2768, data, data_len + 1) < 0)
        goto err9;
    data[0] = 0;
    if (DWC_Http_GetBase64DecodedResult((u8 *)DWChttp.http, g_021A276C, url, wait_len + 1) < 0)
        goto err9;
    url[0] = 0;
    if (url_len > 0) {
        if (DWC_Http_GetBase64DecodedResult((u8 *)DWChttp.http, g_021A2774, wait, url_len + 1) < 0)
            goto err9;
        wait[0] = 0;
        wait_sec = atoi(wait) * 0x3e8;
        if (errno == 0x22)
            goto err9;
    } else {
        wait_sec = 0;
    }
    if (wait_sec > 180000)
        wait_sec = 180000;
    DWC_Http_Destroy((u8 *)DWChttp.http);
    *(int *)((u8 *)DWChttp.nc + 0x1004) = m5;
    DWChttp.p00 = (int)data;
    DWChttp.p04 = 0;
    DWChttp.p08 = 0x1000;
    DWChttp.p0c = (int)alloc;
    DWChttp.p10 = (int)freefn;
    DWChttp.p18 = 120000;
    if (DWC_Http_Create((u8 *)DWChttp.http, (void *)DWCnetcheckhttpparam) != 0)
        goto err1;
    if (DWC_Http_Add_Body((u8 *)DWChttp.http, url) != 0)
        goto err8;
    if (DWC_Http_FinishHeader((u8 *)DWChttp.http) != 0)
        goto err1;
    DWC_Http_StartThread((u8 *)DWChttp.http, OS_GetThreadPriority(OSi_ThreadInfo) - 1);
    if (*(int *)((u8 *)DWChttp.http + 0x1be0) != 0 && !OS_IsThreadTerminated((u8 *)DWChttp.http + 0x1f74))
        OS_JoinThread((u8 *)DWChttp.http + 0x1f74);
    st = *(int *)((u8 *)DWChttp.http + 0x1020);
    if (st == 2) {
        *(int *)((u8 *)DWChttp.nc + 0x1004) = -1;
        goto st3e;
    }
    if (st == 8)
        goto parse3;
st3e:                                     /* 0x217b698 -> 0x217acd0 */
    DWC_Http_Destroy((u8 *)DWChttp.http);
    DWCi_Netcheck_SetError(3);
    goto out;

parse3:                                   /* 0x217b69c */
    if (DWC_Http_ParseResult((u8 *)DWChttp.http, 1) != 1)
        goto err2;
    url_len = *(int *)((u8 *)DWChttp.http + 0x1a44);
    if (url_len == 0) {
        DWC_Http_Destroy((u8 *)DWChttp.http);
        DWCi_Netcheck_SetError(4);
        goto out;
    }
    buf = (u8 *)alloc(0, strlen((char *)url_len) + 1);
    *(int *)((u8 *)DWChttp.nc + 0x1118) = (int)buf;
    if (buf == 0)
        goto err4;
    strncpy((char *)buf, (char *)url_len, strlen((char *)url_len) + 1);
    DWC_Http_Destroy((u8 *)DWChttp.http);
    OS_Sleep(wait_sec);
    goto loop;

err1:
    DWC_Http_Destroy((u8 *)DWChttp.http);
    DWCi_Netcheck_SetError(1);
    goto out;
err2:
    DWC_Http_Destroy((u8 *)DWChttp.http);
    DWCi_Netcheck_SetError(2);
    goto out;
err8:
    DWC_Http_Destroy((u8 *)DWChttp.http);
    DWCi_Netcheck_SetError(8);
    goto out;
err9:
    DWC_Http_Destroy((u8 *)DWChttp.http);
    DWCi_Netcheck_SetError(9);
    goto out;
err4:
    DWC_Http_Destroy((u8 *)DWChttp.http);
    DWCi_Netcheck_SetError(4);
    goto out;

out:
    if (data != 0)
        freefn(0, data, 0);
    if (url != 0)
        freefn(0, url, 0);
    if (wait != 0)
        freefn(0, wait, 0);
}
