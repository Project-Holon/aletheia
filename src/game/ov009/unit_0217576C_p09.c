/*
 * file:     unit_0217576C_p09.c
 * unit:     yes
 * function: func_02176410, func_02176474, func_02176500, func_0217653C, func_02176554
 * address:  0x02176410
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
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   DWCi_NodeInfoList_GetNodeInfoForProfileID 0x021763AC arm
 *   DWCi_NodeInfoList_GetMyNodeInfo           0x02176344 arm
 *   DWCi_GetGT2Connection                     0x0216BAF4 arm
 */
typedef unsigned char u8;

struct DWCstNodeInfo
{
    u8 pad0[0x16];
    u8 aid;
};

extern char *func_02175F3C(void);
extern struct DWCstNodeInfo * DWCi_NodeInfoList_GetNodeInfoForProfileID(int profileID);
extern struct DWCstNodeInfo * DWCi_NodeInfoList_GetMyNodeInfo(void);
extern void * DWCi_GetGT2Connection(unsigned char aid);
extern void func_0217656C(void *p);
extern int func_02176580(const int *p);
char *func_02176410(unsigned char aid);
unsigned char func_02176474(void);
int DWCi_NodeInfoList_HasNoGT2ConnectionToProfileID(int profileID);
void func_0217653C(void);
int func_02176554(void);


/*
 * sdk:      DWCi_NodeInfoList_GetNodeInfoForAID (dwc_match.o)
 *
 * Extra open callee of DWCi_DeleteAID (0x0216BCA4).
 */
char *func_02176410(unsigned char aid)
{
    int i;

    for (i = 0; i < *(int *)(func_02175F3C() + 0x50); i++) {
        if (aid == *(unsigned char *)(func_02175F3C() + i * 0x28 + 0x6a))
            return func_02175F3C() + 0x54 + i * 0x28;
    }
    return 0;
}


/*
 * sdk:      DWCi_NodeInfoList_GetFreeAID (dwc_match.o)
 */
unsigned char func_02176474(void)
{
    unsigned char i;
    int j;

    if (*(int *)(func_02175F3C() + 0x50) == 32)
        return 0xff;
    for (i = 0; i < 32; i++) {
        for (j = 0; j < *(int *)(func_02175F3C() + 0x50); j++) {
            if (i == *(unsigned char *)(func_02175F3C() + j * 40 + 0x6a))
                break;
        }
        if (j == *(int *)(func_02175F3C() + 0x50))
            return i;
    }
    return 0xff;
}


int DWCi_NodeInfoList_HasNoGT2ConnectionToProfileID(int profileID)
{
    struct DWCstNodeInfo *pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForProfileID(profileID);

    if (pNodeInfo == 0)
        return 0;
    if (pNodeInfo == DWCi_NodeInfoList_GetMyNodeInfo())
        return 0;
    return DWCi_GetGT2Connection(pNodeInfo->aid) == 0;
}


/*
 * Clears the block 0x554 bytes into the module block.
 */
void func_0217653C(void)
{
    func_0217656C((void *)(func_02175F3C() + 0x554));
}


/*
 * Prepares the block 0x554 bytes into the module block.
 */
int func_02176554(void)
{
    return func_02176580((const int *)(func_02175F3C() + 0x554));
}
