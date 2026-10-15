/*
 * function: DIGITALCARDCHECK_DeleteInitRecord,DIGITALCARDCHECK_IsInitRecordDone,DIGITALCARDCHECK_IsInitWorkDone
 * unit: yes
 * address: 0x0217DE60
 * packet: pkt_ov176_0217DE60
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_VIEW_StepMainWindow 0x021E64C8 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_StepMainWindowIdle 0x021E65FC thumb ov177
 *   WIFIBATTLEMATCH_VIEW_DeleteStatusWindow 0x021E5EF8 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_DeleteDateWindow 0x021E62A0 thumb ov177
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_PushTile 0x020409B4 arm
 */
extern void WIFIBATTLEMATCH_VIEW_DeleteStatusWindow(void *p);
extern void WIFIBATTLEMATCH_VIEW_DeleteDateWindow(void *p);
typedef unsigned int   u32;
extern void BG_SYS_ClearSlot(u32 i);
extern void BG_SYS_PushTile(u32 index);
extern int WIFIBATTLEMATCH_VIEW_StepMainWindow(int);
extern int WIFIBATTLEMATCH_VIEW_StepMainWindowIdle(int);
void DIGITALCARDCHECK_DeleteInitRecord(int *p)
{
    if (p[2]) {
        if (p[5] == 0)
            WIFIBATTLEMATCH_VIEW_DeleteStatusWindow((void *)p[2]);
        else
            WIFIBATTLEMATCH_VIEW_DeleteDateWindow((void *)p[2]);
        p[2] = 0;
    }
    BG_SYS_ClearSlot(1);
    BG_SYS_PushTile(1);
}
int DIGITALCARDCHECK_IsInitRecordDone(int *p) { return WIFIBATTLEMATCH_VIEW_StepMainWindow(p[2]); }
int DIGITALCARDCHECK_IsInitWorkDone(int *p) { return WIFIBATTLEMATCH_VIEW_StepMainWindowIdle(p[2]); }
