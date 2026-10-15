/*
 * function: BTLV_INPUT_Delete
 * address:  0x022021F4
 * packet:   pkt_ov094_022021F4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_INPUT_DeleteAllTasks  0x022068E8  thumb  ov094
 *   BTLV_INPUT_ReleaseScreenResources  0x022023D0  thumb  ov094
 *   BTLV_FINGER_CURSOR_Delete  0x02209B30  thumb  ov094
 *   MSGDATA_Delete  0x02045C04  arm  arm9
 *   TCB_Noop  0x02030DA4  arm  arm9
 */
typedef struct Obj {
    void *h0;
    void *h4;
    char pad[0x5c - 8];
    void *h5c;
    void *h60;
} Obj;
extern void BTLV_INPUT_DeleteAllTasks(char *p);
extern void BTLV_INPUT_ReleaseScreenResources(char *p);
struct Rec;
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern void BTLV_FINGER_CURSOR_Delete(void *);
extern void TCB_Noop(void *);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void BTLV_INPUT_Delete(Obj *p)
{
    if (p == 0)
        return;
    BTLV_INPUT_DeleteAllTasks((char *)p);
    BTLV_INPUT_ReleaseScreenResources((char *)p);
    MSGDATA_Delete(p->h5c);
    if (p->h60 != 0)
        BTLV_FINGER_CURSOR_Delete(p->h60);
    TCB_Noop(p->h0);
    func_020307B0(p->h4);
    func_020307B0(p);
}
