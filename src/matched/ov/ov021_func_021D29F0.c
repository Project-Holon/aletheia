/*
 * function: SCRCMD_ShowOrClearInfoWindow
 * address:  0x021D29F0
 * packet:   pkt_ov021_021D29F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   VM_ReadU16  0x02011330  thumb
 *   func_02045B38  0x02045B38  arm
 *   BMP_WIN_CreateAt  0x02045180  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   FIELD_MSGBG_GetFont  0x021904AC  thumb  ov021
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   func_02041B6C  0x02041B6C  arm
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BG_SYS_SetTileEntry  0x02041300  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
typedef signed short   s16;
struct Cfg;
struct Descriptor;
struct MsgBank;
struct Rec;
struct U16Vec;
extern int SCRIPT_WORK_ResetFieldParam(int a0);
typedef unsigned short u16;
typedef unsigned char  u8;
extern u16 FIELDMAP_GetHeapId(u8 *p);
struct CharBuf;
struct Stream;
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern u16 VM_ReadU16(struct Stream *s);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 BMP_WIN_CreateAt(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u32 offset);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *a);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 FIELD_MSGBG_GetFont(u8 *p);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void func_02041B6C(u32);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BG_SYS_SetTileEntry(int, int, int, int, int, int, int);

int SCRCMD_ShowOrClearInfoWindow(u32 a, u32 b)
{
    void **q;
    u32 heap, msg, win, s;
    void *m;

    q = (void **)SCRIPT_WORK_ResetFieldParam((int)SCRCMD_WORK_GetScriptWork((void *)b));
    heap = FIELDMAP_GetHeapId(q[1]);
    m = (void *)FIELDMAP_GetMsgBg(q[1]);
    if (VM_ReadU16((struct Stream *)a)) {
        msg = (u32)func_02045B38(0, 2, 0x16, heap);
        win = BMP_WIN_CreateAt(2, 1, 1, 0x1E, 10, 14, 0x40);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)win)), 0xF);
        BMP_WIN_TransferChars((struct Descriptor *)win);
        BMP_WIN_MakeScreen((struct Cfg *)win);
        BMP_MENUWORK_DrawWindow((void *)win, 0, 1, 0xD);
        s = (u32)STRBUF_Create(0xB4, heap);
        func_02045CAC((struct MsgBank *)msg, 3, (void *)s);
        PRINTSYS_Print((void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)win)), 0, 0, (void *)s, (void *)FIELD_MSGBG_GetFont(m));
        BMP_WIN_TransferChars((struct Descriptor *)win);
        func_02041B6C(2);
        STRBUF_Delete((struct U16Vec *)s);
        MSGDATA_Delete((struct Rec *)msg);
        BMP_WIN_Delete((struct Descriptor *)win);
    } else {
        BG_SYS_SetTileEntry(2, 0, 0, 0, 0x20, 0xC, 0x11);
        func_02041B6C(2);
    }
    return 0;
}
