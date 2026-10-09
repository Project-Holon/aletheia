/*
 * file:     unit_0217576C_p05.c
 * unit:     yes
 * function: DWCi_SetHostStatus, func_02175FB8, func_02175FC8, func_02175FE4, func_0217601C, func_0217603C, func_0217604C, func_021760FC, func_02176164, func_02176254, func_02176344
 * address:  0x02175F84
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
 *   DWCi_GetMatchCnt       0x02175F3C arm
 *   qr2_send_statechanged  0x0219B490 arm
 *   s_bInNNThink           0x021AAA20 data
 *   func_0217637C  0x0217637C  arm  ov009
 *   func_02177748  0x02177748  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_021763AC  0x021763AC  arm  ov009
 */
typedef unsigned char u8;

struct DWCstMatchControl
{
	void **connection;
	unsigned char pad4[0x9];
	unsigned char f0d;
	unsigned char pade[0x2];
	void *qr2Obj;
	unsigned char pad14[0x1];
	unsigned char qr2MatchTypeExt;
	unsigned char hostState;
	unsigned char pad17[0x5];
	unsigned int suspendBitmap;
	unsigned long long f20;
	unsigned char pad28[0x8];
	unsigned char suspendSent;
	unsigned char pad31[0x523];
	int f554;
	unsigned char pad558[0x50];
	int lastStateBeforeStopMeshMaking;
	unsigned char  tempNodeInfoBeforeStopMeshMaking[0x28];
	unsigned char pad5d4[0xc];
	void *sbObj;
	unsigned char pad5e4[0x38];
	int f61c;
	unsigned char pad620[0x58];
	unsigned int f678;
	int f67c;
	unsigned char pad680[0x118];
	int f798;
	unsigned char pad79c[0x4];
	unsigned long long f7a0;
	unsigned char pad7a8[0x20];
	unsigned int f7c8;
	unsigned long long f7cc;
};

struct NNThinkGlobal
{
    int f0;
    struct DWCstMatchControl *pMatch;
};

struct node_s {
    int w[10];
};

typedef struct NodeRec { int w[10]; } NodeRec;

typedef struct Node { char pad[0x54]; NodeRec rec; } Node;

typedef struct NodeInfo {
    int profileID;
    unsigned char pad0[0x28 - 4];
} NodeInfo;

typedef struct MatchCnt {
    unsigned char pad0[0x50];
    int nodeCount;
    NodeInfo nodes[1];
} MatchCnt;

extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern void qr2_send_statechanged(void *qrec);
extern char *func_02175F3C(void);
extern unsigned char *func_0217637C(int index);
extern void func_02177748(int aid);
extern void func_02082BCC(void *p, int v, int n);
extern char *func_021763AC(int pid);
void DWCi_SetHostStatus(int host);
unsigned char func_02175FB8(void);
/* * Cleared when the word at +0x7b0 of the module block is one. */ int func_02175FC8(void);
/* * DWCi_ResetLastSomeDataRecvTimeByAidAll: restamps every node's transport record. */ void func_02175FE4(void);
/* * Clears the block 0x50 bytes into the module block. */ void func_0217601C(void);
/* * Word at +0x50 of the block func_02175F3C returns. */ int func_0217603C(void);
/* * sdk: DWCi_NodeInfoList_InsertToTop (dwc_match.o) */ int func_0217604C(struct node_s *newNode);
/* * sdk: DWCi_NodeInfoList_Append (dwc_match.o) */ int func_021760FC(struct node_s *newNode);
/* * sdk: DWCi_NodeInfoList_RemoveAID (TwlDWC/libdwcmatch.TWL.HYB.a(dwc_match.o)) * * Removes the node with this AID from the node-info list and shifts the tail * down one 0x28-byte record. * * The shift-down loop reads BOTH list bases first and only then does the index * arithmetic: the two func_02175F3C() results go into two raw char* locals, the * destination is `a + i * 0x28` (old i), then i is bumped, then the source is * `b + i * 0x28` (new i). That is what makes the image keep the first result * raw in r7 across the second call (`mov r7, r0`) and emit both `mla`s after * it; folding the arithmetic into the first call site loses those 4 bytes. * * Verified with: * python tools/match.py one --src src/matched/ov_sdk/ov009_func_02176164.c \ * --func func_02176164 --addr 0x02176164 --region ov009 --arm --lang c99 --cc 1.1p1 --diff */ int func_02176164(unsigned char aid);
/* * sdk: DWCi_NodeInfoList_RemoveProfileID (libdwcmatch.TWL.HYB.a dwc_match.o) */ int func_02176254(int profileID);
/* * Passes the word at +0x678 of the module block on. */ char *func_02176344(void);
extern struct NNThinkGlobal s_bInNNThink;




void DWCi_SetHostStatus(int host)
{
    s_bInNNThink.pMatch->hostState = host;
    if (DWCi_GetMatchCnt()->qr2Obj != 0)
        qr2_send_statechanged(DWCi_GetMatchCnt()->qr2Obj);
}





unsigned char func_02175FB8(void)
{
    return *(unsigned char *)(func_02175F3C() + 0x16);
}





/*
 * Cleared when the word at +0x7b0 of the module block is one.
 */
int func_02175FC8(void)
{
    return *(int *)(func_02175F3C() + 0x7b0) != 1;
}





/*
 * DWCi_ResetLastSomeDataRecvTimeByAidAll: restamps every node's transport record.
 */
void func_02175FE4(void)
{
    int i;

    for (i = 0; i < func_0217603C(); i++) {
        func_02177748(func_0217637C(i)[0x16]);
    }
}




/*
 * Clears the block 0x50 bytes into the module block.
 */
void func_0217601C(void)
{
    func_02082BCC((void *)(func_02175F3C() + 0x50), 0, 0x504);
}




/*
 * Word at +0x50 of the block func_02175F3C returns.
 */
int func_0217603C(void)
{
    return *(int *)(func_02175F3C() + 0x50);
}




/*
 * sdk:      DWCi_NodeInfoList_InsertToTop (dwc_match.o)
 */
int func_0217604C(struct node_s *newNode)
{
    int i;

    if (*(int *)(func_02175F3C() + 0x50) == 32)
        return 0;
    for (i = *(int *)(func_02175F3C() + 0x50); i > 0; i--)
        ((struct node_s *)(func_02175F3C() + 0x54))[i] = ((struct node_s *)(func_02175F3C() + 0x54))[i - 1];
    *(struct node_s *)(func_02175F3C() + 0x54) = *newNode;
    *(int *)(func_02175F3C() + 0x50) += 1;
    return 1;
}




/*
 * sdk:      DWCi_NodeInfoList_Append (dwc_match.o)
 */
int func_021760FC(struct node_s *newNode)
{
    if (*(int *)(func_02175F3C() + 0x50) == 32)
        return 0;
    *(struct node_s *)(func_02175F3C() + 0x54 + *(int *)(func_02175F3C() + 0x50) * 40) = *newNode;
    *(int *)(func_02175F3C() + 0x50) += 1;
    return 1;
}




/*
 * sdk:      DWCi_NodeInfoList_RemoveAID (TwlDWC/libdwcmatch.TWL.HYB.a(dwc_match.o))
 *
 * Removes the node with this AID from the node-info list and shifts the tail
 * down one 0x28-byte record.
 *
 * The shift-down loop reads BOTH list bases first and only then does the index
 * arithmetic: the two func_02175F3C() results go into two raw char* locals, the
 * destination is `a + i * 0x28` (old i), then i is bumped, then the source is
 * `b + i * 0x28` (new i).  That is what makes the image keep the first result
 * raw in r7 across the second call (`mov r7, r0`) and emit both `mla`s after
 * it; folding the arithmetic into the first call site loses those 4 bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov009_func_02176164.c \
 *       --func func_02176164 --addr 0x02176164 --region ov009 --arm --lang c99 --cc 1.1p1 --diff
 */
int func_02176164(unsigned char aid)
{
    int removeAidIndex;
    int i;
    Node *d;
    Node *s;

    if (*(int *)(func_02175F3C() + 0x50) == 0) return 0;
    for (removeAidIndex = 0; removeAidIndex < *(int *)(func_02175F3C() + 0x50);
         removeAidIndex++) {
        if (aid == *(unsigned char *)(func_02175F3C() + removeAidIndex * 0x28 + 0x6a))
            break;
    }
    if (removeAidIndex == *(int *)(func_02175F3C() + 0x50)) return 0;
    for (i = removeAidIndex; i < *(int *)(func_02175F3C() + 0x50) - 1; ) {
        char *a = (char *)func_02175F3C();
        char *b = (char *)func_02175F3C();
        d = (Node *)(a + i * 0x28);
        i++;
        s = (Node *)(b + i * 0x28);
        d->rec = s->rec;
    }
    *(int *)(func_02175F3C() + 0x50) -= 1;
    return 1;
}




/*
 * sdk:      DWCi_NodeInfoList_RemoveProfileID (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int func_02176254(int profileID)
{
    int removeIndex;

    if (((MatchCnt *)func_02175F3C())->nodeCount == 0)
        return 0;
    for (removeIndex = 0; removeIndex < ((MatchCnt *)func_02175F3C())->nodeCount; removeIndex++) {
        if (profileID == ((MatchCnt *)func_02175F3C())->nodes[removeIndex].profileID)
            break;
    }
    if (removeIndex == ((MatchCnt *)func_02175F3C())->nodeCount)
        return 0;
    for (; removeIndex < ((MatchCnt *)func_02175F3C())->nodeCount - 1; removeIndex++)
        ((MatchCnt *)func_02175F3C())->nodes[removeIndex] = ((MatchCnt *)func_02175F3C())->nodes[removeIndex + 1];
    ((MatchCnt *)func_02175F3C())->nodeCount--;
    return 1;
}




/*
 * Passes the word at +0x678 of the module block on.
 */
char *func_02176344(void)
{
    return func_021763AC(*(int *)(func_02175F3C() + 0x678));
}
