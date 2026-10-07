/*
 * file:     unit_0216F014_p03.c
 * unit:     yes
 * function: func_0216F5FC, func_0216F6C0
 * address:  0x0216F5FC
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216F388  0x0216F388  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   g_021AAA20  0x021AAA20  data
 *   func_0219ED4C  0x0219ED4C  arm  ov009
 *   func_02176B34  0x02176B34  arm  ov009
 *   func_02175F4C  0x02175F4C  arm  ov009
 *   DWC_Free  0x0205A1B0  arm
 *   func_02173B18  0x02173B18  arm  ov009
 *   func_0217601C  0x0217601C  arm  ov009
 *   func_0217653C  0x0217653C  arm  ov009
 *   func_0216F20C  0x0216F20C  arm  ov009
 */
#include "../../matched/include/G_NNThinkGlobal.h"

struct ServerBrowser;
extern void func_0216F388(int flag);
extern char *func_02175F3C(void);
extern void func_0219ED4C(struct ServerBrowser *sb);
extern void func_02176B34(void);
extern void func_02175F4C(int state);
extern void DWC_Free(int kind, void *p, int size);
extern void func_02173B18(void);
extern void func_0217601C(void);
extern void func_0217653C(void);
extern int func_0216F20C(int status);
void func_0216F5FC(unsigned char matchType, unsigned char numEntry, void *callback, void *param);
void func_0216F6C0(void);
extern struct NNThinkGlobal g_021AAA20;


/*
 * sdk:      DWCi_SetMatchCommonParam (dwc_match.o)
 */
void func_0216F5FC(unsigned char matchType, unsigned char numEntry, void *callback, void *param)
{
    func_0216F388(0);
    *(unsigned char *)(func_02175F3C() + 0x14) = matchType;
    *(unsigned char *)(func_02175F3C() + 0x17) = numEntry;
    *(void **)(func_02175F3C() + 0x770) = callback;
    *(void **)(func_02175F3C() + 0x774) = param;
    *(unsigned char *)(func_02175F3C() + 0x5f9) = 0;
    *(int *)(func_02175F3C() + 0x2c) = 0xff;
    *(unsigned char *)(func_02175F3C() + 0x30) = 0;
    *(unsigned char *)(func_02175F3C() + 0x16) = 0;
    *(unsigned char *)(func_02175F3C() + 0x7a8) = 1;
    *(int *)(func_02175F3C() + 0x7ac) = 0;
    *(unsigned char *)(func_02175F3C() + 0x17) = numEntry;
    *(int *)(func_02175F3C() + 0x1c) = 0;
    *(int *)(func_02175F3C() + 0x28) = 0;
    *(unsigned long long *)(func_02175F3C() + 0x20) = 0;
    *(int *)(func_02175F3C() + 0x48) = 0;
    *(int *)(func_02175F3C() + 0x7c4) = 1;
    *(unsigned long long *)(func_02175F3C() + 0x7cc) = 0;
    *(int *)(func_02175F3C() + 0x634) = 0;
}


/*
 * Resets the match state: frees the server browser and negotiation data and clears the node lists.
 */
void func_0216F6C0(void)
{
    if (func_02175F3C() == 0) {
        return;
    }
    if (*(void **)(func_02175F3C() + 0x5e0) != 0) {
        if (*(int *)(((char *)&g_021AAA20) + 0x14) != 0) {
            *(int *)(((char *)&g_021AAA20) + 0x10) = 1;
        } else {
            func_0219ED4C(*(void **)(func_02175F3C() + 0x5e0));
            *(void **)(func_02175F3C() + 0x5e0) = 0;
        }
    }
    func_02176B34();
    func_02175F4C(0);
    if (*(void **)(((char *)&g_021AAA20) + 0xc) != 0) {
        DWC_Free(4, *(void **)(((char *)&g_021AAA20) + 0xc), 0);
        *(void **)(((char *)&g_021AAA20) + 0xc) = 0;
    }
    func_02173B18();
    *(unsigned char *)(func_02175F3C() + 0x4c) = 1;
    func_0217601C();
    func_0217653C();
    *(int *)(func_02175F3C() + 0x7c4) = 1;
    func_0216F20C(1);
}
