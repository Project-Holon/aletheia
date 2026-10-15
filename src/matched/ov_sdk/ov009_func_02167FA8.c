/*
 * function: DWC_SVLGetTokenAsync
 * address:  0x02167FA8
 * packet:   pkt_ov009_02167FA8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_SVLGetTokenAsync (libdwcnas.TWL.HYB.a dwc_nasfunc.o)
 *
 * symbols:
 *   DWC_Auth_GetId  0x02058FB4  arm
 *   DWC_Svl_Init  0x0217C070  arm  ov009
 *   strlen  0x0209477C  arm
 *   DWC_Svl_GetTokenAsync  0x0217C144  arm  ov009
 *   DWC_Svl_Cleanup  0x0217C104  arm  ov009
 *   DWC_Alloc      0x0205A16C  arm
 *   DWC_Free       0x0205A1B0  arm
 *   gDwcNasTokenInitial     0x021A1F6C  data
 */

typedef struct AuthId {
    int f0[4];
    int f10;
} AuthId;

extern void DWC_Auth_GetId(AuthId *id);
extern int DWC_Svl_Init(void *alloc, void *free);
typedef unsigned char  u8;
extern int strlen(const u8 *s);
struct DWCSvlResult;
extern int DWC_Svl_GetTokenAsync(char *svc, struct DWCSvlResult *result);
extern void DWC_Svl_Cleanup(void);
extern void DWC_Alloc(void);
extern void DWC_Free(void);
extern char gDwcNasTokenInitial[];

int DWC_SVLGetTokenAsync(char *svl, void *result)
{
    AuthId id;
    int flag;

    DWC_Auth_GetId(&id);
    if (id.f10 == 0)
        return 0;
    if (DWC_Svl_Init(DWC_Alloc, DWC_Free) == 0)
        return 0;
    if (strlen((const u8 *)svl) == 0)
        flag = DWC_Svl_GetTokenAsync(gDwcNasTokenInitial, result);
    else
        flag = DWC_Svl_GetTokenAsync(svl, result);
    if (flag != 0)
        return 1;
    DWC_Svl_Cleanup();
    return 0;
}
