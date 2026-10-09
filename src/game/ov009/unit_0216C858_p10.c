/*
 * file:     unit_0216C858_p10.c
 * unit:     yes
 * function: DWCi_ClearQR2Key, DWCi_ProcessMatchSynPacket
 * address:  0x0216EC18
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
 *   DWC_GetState        0x0216B994 arm
 *   DWCi_GetMatchCnt    0x02175F3C arm
 *   qr2_send_statechanged 0x0219B490 arm
 *   DWCi_IsFullMesh                        0x0217695C arm
 *   DWCi_ProcessMatchSynPacketSub_FullMesh 0x0216F008 arm
 *   DWCi_ProcessMatchSynPacketSub_Hybrid   0x0216EC84 arm
 */
typedef unsigned char u8;

typedef unsigned long u32;

struct DWCstMatchControl
{
    u8 pad0[0x10];
    void *qr2Obj;            /* +0x10 */
    u8 pad1[0x17 - 0x14];
    u8 qr2NumEntry;          /* +0x17 */
    u8 pad2[0x790 - 0x18];
    u32 groupID;             /* +0x790 */
};

extern int DWC_GetState(void);
extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern void qr2_send_statechanged(void *qrec);
extern int DWCi_IsFullMesh(void);
extern void DWCi_ProcessMatchSynPacketSub_FullMesh(unsigned char aid, unsigned short type, unsigned char *data);
extern void DWCi_ProcessMatchSynPacketSub_Hybrid(unsigned char aid, unsigned short type, unsigned char *data);
void DWCi_ClearQR2Key(void);
void DWCi_ProcessMatchSynPacket(unsigned char aid, unsigned short type, unsigned char *data);


void DWCi_ClearQR2Key(void)
{
    if (DWC_GetState() != 3)
        return;
    DWCi_GetMatchCnt()->qr2NumEntry = 0;
    DWCi_GetMatchCnt()->groupID = 0;
    qr2_send_statechanged(DWCi_GetMatchCnt()->qr2Obj);
}


void DWCi_ProcessMatchSynPacket(unsigned char aid, unsigned short type, unsigned char *data)
{
    if (DWCi_IsFullMesh())
        DWCi_ProcessMatchSynPacketSub_FullMesh(aid, type, data);
    else
        DWCi_ProcessMatchSynPacketSub_Hybrid(aid, type, data);
}
