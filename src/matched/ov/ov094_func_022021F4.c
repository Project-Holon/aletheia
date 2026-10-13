/*
 * function: func_022021F4
 * address:  0x022021F4
 * packet:   pkt_ov094_022021F4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_022068E8  0x022068E8  thumb  ov094
 *   func_022023D0  0x022023D0  thumb  ov094
 *   func_02209B30  0x02209B30  thumb  ov094
 *   MSGDATA_Delete  0x02045C04  arm  arm9
 */
typedef struct Obj {
    void *h0;
    void *h4;
    char pad[0x5c - 8];
    void *h5c;
    void *h60;
} Obj;
extern void func_022068E8(char *p);
extern void func_022023D0(char *p);
struct Rec;
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern void func_02209B30(void *);
extern void func_02030DA4(void *);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void func_022021F4(Obj *p)
{
    if (p == 0)
        return;
    func_022068E8((char *)p);
    func_022023D0((char *)p);
    MSGDATA_Delete(p->h5c);
    if (p->h60 != 0)
        func_02209B30(p->h60);
    func_02030DA4(p->h0);
    func_020307B0(p->h4);
    func_020307B0(p);
}
