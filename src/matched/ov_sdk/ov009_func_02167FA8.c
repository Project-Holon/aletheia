/*
 * function: func_02167FA8
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
 *   func_02058FB4  0x02058FB4  arm
 *   func_0217C070  0x0217C070  arm  ov009
 *   func_0209477C  0x0209477C  arm
 *   func_0217C144  0x0217C144  arm  ov009
 *   func_0217C104  0x0217C104  arm  ov009
 *   DWC_Alloc      0x0205A16C  arm
 *   DWC_Free       0x0205A1B0  arm
 *   g_021A1F6C     0x021A1F6C  data
 */

typedef struct AuthId {
    int f0[4];
    int f10;
} AuthId;

extern void func_02058FB4(AuthId *id);
extern int func_0217C070(void *alloc, void *free);
extern int func_0209477C(char *s);
extern int func_0217C144(char *svl, void *result);
extern void func_0217C104(void);
extern void DWC_Alloc(void);
extern void DWC_Free(void);
extern char g_021A1F6C[];

int func_02167FA8(char *svl, void *result)
{
    AuthId id;
    int flag;

    func_02058FB4(&id);
    if (id.f10 == 0)
        return 0;
    if (func_0217C070(DWC_Alloc, DWC_Free) == 0)
        return 0;
    if (func_0209477C(svl) == 0)
        flag = func_0217C144(g_021A1F6C, result);
    else
        flag = func_0217C144(svl, result);
    if (flag != 0)
        return 1;
    func_0217C104();
    return 0;
}
