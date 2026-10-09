/*
 * file:     unit_0216F014_p12.c
 * unit:     yes
 * function: func_0217253C, func_021725EC, func_02172604
 * address:  0x0217253C
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
 *   DWCi_GetMatchCnt                     0x02175F3C arm
 *   DWCi_TempNewNodeInfo_IsValid         0x02176554 arm
 *   DWCi_NodeInfoList_Append             0x021760FC arm
 *   DWCi_TempNewNodeInfo_Clear           0x0217653C arm
 *   DWCi_NodeInfoList_GetCount           0x0217603C arm
 *   DWCi_NodeInfoList_InsertToTop        0x0217604C arm
 *   DWCi_NodeInfoList_GetNodeInfoForProfileID 0x021763AC arm
 *   DWCi_CloseConnectionHard             0x0216BEA4 arm
 *   DWCi_NodeInfoList_GetNodeInfoForAID  0x02176410 arm
 *   func_0217253C  0x0217253C  arm  ov009
 *   func_02175F3C                0x02175F3C arm   ov009
 *   func_02175F4C                0x02175F4C arm   ov009
 *   func_02176674                0x02176674 arm   ov009
 *   func_0217603C                0x0217603C arm   ov009
 *   func_020870D0                0x020870D0 arm
 *   qr2_send_statechanged        0x0219B490 arm   ov009
 *   func_0217637C                0x0217637C arm   ov009
 *   func_02173064                0x02173064 arm   ov009
 */
typedef unsigned char u8;

struct DWCstNodeInfo_0216F014
{
    int profileID;           /* +0x00 */
    u8 pad0[0x16 - 4];
    u8 aid;                  /* +0x16 */
    u8 pad1[0x28 - 0x17];
};

struct DWCstMatchControl_0216F014
{
    u8 pad0[0x14];
    u8 qr2MatchType;         /* +0x14 */
    u8 pad1[0x554 - 0x15];
    struct DWCstNodeInfo_0216F014 tempNewNodeInfo;    /* +0x554 */
    struct DWCstNodeInfo_0216F014 tempNewClientInfo;  /* +0x57c */
};

typedef unsigned short u16;

typedef unsigned long long u64;

struct DWCstMatchControl_02172604 {
    u8 pad0[0xd];
    u8 f0d;
    u8 pad1[0x10 - 0xe];
    void *qr2Obj;
    u8 f14;
    u8 pad2[0x18 - 0x15];
    u8 f18;
    u8 pad3[0x554 - 0x19];
    int f554;
    u8 pad4[0x56a - 0x558];
    u8 aid;
    u8 pad5[0x5a4 - 0x56b];
    int f5a4;
    int f5a8;
    u8 pad6[0x5dc - 0x5ac];
    int f5dc;
    u8 pad7[0x650 - 0x5e0];
    int f650;
    u8 pad8[0x680 - 0x654];
    int f680;
    u8 pad9[0x7a0 - 0x684];
    u64 f7a0;
};

struct DWCstNodeInfo_02172604 {
    u8 pad0[0x16];
    u8 aid;
};

extern struct DWCstMatchControl_0216F014 * DWCi_GetMatchCnt(void);
extern int DWCi_TempNewNodeInfo_IsValid(void);
extern int DWCi_NodeInfoList_Append(struct DWCstNodeInfo_0216F014 *newNode);
extern void DWCi_TempNewNodeInfo_Clear(void);
extern int DWCi_NodeInfoList_GetCount(void);
extern int DWCi_NodeInfoList_InsertToTop(struct DWCstNodeInfo_0216F014 *newNode);
extern struct DWCstNodeInfo_0216F014 * DWCi_NodeInfoList_GetNodeInfoForProfileID(int profileID);
extern int DWCi_CloseConnectionHard(unsigned char aid);
extern struct DWCstNodeInfo_0216F014 * DWCi_NodeInfoList_GetNodeInfoForAID(unsigned char aid);
extern void func_0217253C(void);
extern int func_02175F3C(void);
extern void func_02175F4C(int state);
extern int func_02176674(void);
extern int func_0217603C(void);
extern u64 func_020870D0(void);
extern void qr2_send_statechanged(void *qrec);
extern struct DWCstNodeInfo_02172604 *func_0217637C(int index);
extern void func_02173064(u8 aid, u16 type);
void DWCi_PostProcessConnectionSYNFinishHybrid(void);
/* * Clears the byte at +0x62f of the module block. */ void func_021725EC(void);
int func_02172604(void);



void DWCi_PostProcessConnectionSYNFinishHybrid(void)
{
    struct DWCstMatchControl_0216F014 *p;

    if (DWCi_GetMatchCnt()->qr2MatchType == 2) {
        if (DWCi_TempNewNodeInfo_IsValid() == 0)
            return;
        DWCi_NodeInfoList_Append(&DWCi_GetMatchCnt()->tempNewNodeInfo);
        DWCi_TempNewNodeInfo_Clear();
        return;
    }
    if (DWCi_NodeInfoList_GetCount() == 1) {
        DWCi_NodeInfoList_InsertToTop(&DWCi_GetMatchCnt()->tempNewNodeInfo);
        DWCi_TempNewNodeInfo_Clear();
        return;
    }
    p = DWCi_GetMatchCnt();
    {
        struct DWCstNodeInfo_0216F014 *newNode = &p->tempNewClientInfo;
        struct DWCstNodeInfo_0216F014 *n;

        if (newNode->profileID == 0)
            return;
        n = DWCi_NodeInfoList_GetNodeInfoForProfileID(newNode->profileID);
        if (n != 0)
            DWCi_CloseConnectionHard(n->aid);
        n = DWCi_NodeInfoList_GetNodeInfoForAID(newNode->aid);
        if (n != 0)
            DWCi_CloseConnectionHard(n->aid);
        DWCi_NodeInfoList_Append(newNode);
        newNode->profileID = 0;
    }
}



/*
 * Clears the byte at +0x62f of the module block.
 */
void func_021725EC(void)
{
    func_0217253C();

    *(unsigned char *)(func_02175F3C() + 0x62f) = 0;
}


/*
 * sdk:      DWCi_PostProcessSVConnectionHybrid (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int func_02172604(void)
{
    int sbClear = 0;
    int i;
    u64 tick;

    if (((struct DWCstMatchControl_02172604 *)func_02175F3C())->f5a4 != 0 || ((struct DWCstMatchControl_02172604 *)func_02175F3C())->f5a8 == 0xf) {
        ((struct DWCstMatchControl_02172604 *)func_02175F3C())->f18 = 0;
        ((struct DWCstMatchControl_02172604 *)func_02175F3C())->f5dc = 0;
        func_02175F4C(1);
        func_02176674();
        return sbClear;
    }
    ((struct DWCstMatchControl_02172604 *)func_02175F3C())->f18 = 0;
    ((struct DWCstMatchControl_02172604 *)func_02175F3C())->f5dc = 0;
    if (((struct DWCstMatchControl_02172604 *)func_02175F3C())->f0d == 0 && func_0217603C() == 1) {
        tick = func_020870D0();
        ((struct DWCstMatchControl_02172604 *)func_02175F3C())->f7a0 = tick;
    }
    qr2_send_statechanged(((struct DWCstMatchControl_02172604 *)func_02175F3C())->qr2Obj);
    if (((struct DWCstMatchControl_02172604 *)func_02175F3C())->f14 == 2)
        ((struct DWCstMatchControl_02172604 *)func_02175F3C())->f680 = ((struct DWCstMatchControl_02172604 *)func_02175F3C())->f554;
    func_02175F4C(0x13);
    ((struct DWCstMatchControl_02172604 *)func_02175F3C())->f650 = 0;
    for (i = 1; i < func_0217603C(); i++)
        func_02173064(func_0217637C(i)->aid, 2);
    func_02173064(((struct DWCstMatchControl_02172604 *)func_02175F3C())->aid, 2);
    if (((struct DWCstMatchControl_02172604 *)func_02175F3C())->f14 != 2)
        sbClear = 1;
    return sbClear;
}
