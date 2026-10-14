/*
 * function: ZUKAN_DETAIL_HEADBAR_Delete
 * address: 0x021BE778
 * packet: pkt_ov208_021BE778
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   ZUKAN_DETAIL_HEADBAR_ClearIcon 0x021BE9C8 thumb
 *   ZUKAN_DETAIL_HEADBAR_DeleteWindows 0x021BE8FC thumb
 *   func_020307B0 0x020307B0 arm
 * tail: two zero alignment bytes after the function (listing extent is 2 bytes longer).
 */
struct Ov208Mgr { char pad[0x28]; void *f28; void *f2c; };
struct Node;
struct PrintSys;
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void func_02030EAC(struct Node *n);
extern void ZUKAN_DETAIL_HEADBAR_ClearIcon(struct Ov208Mgr *m);
extern void ZUKAN_DETAIL_HEADBAR_DeleteWindows(char *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void ZUKAN_DETAIL_HEADBAR_Delete(struct Ov208Mgr *m)
{
    PRINTSYS_QUE_Clear(m->f2c);
    PRINTSYS_QUE_Delete(m->f2c);
    func_02030EAC(m->f28);
    ZUKAN_DETAIL_HEADBAR_ClearIcon(m);
    ZUKAN_DETAIL_HEADBAR_DeleteWindows((char *)m);
    func_020307B0(m);
}
