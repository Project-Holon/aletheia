/*
 * function: SYMBOL_MAP_CreateRecordTask
 * address: 0x0216666C
 * packet: pkt_ov010_0216666C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SYMBOL_MAP_RecordTaskMain 0x021666B8 thumb ov010
 *   EVENT_FIELD_PROCLINK_StartCommProc 0x02161CDC thumb ov010
 *   SYMBOL_MAP_GetLastResult 0x0216670C thumb ov010
 */
typedef unsigned char u8;
extern int SYMBOL_MAP_RecordTaskMain(void *, unsigned int *);
typedef unsigned int   u32;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void EVENT_FIELD_PROCLINK_StartCommProc(void *, void *, u8, u8);
extern int SYMBOL_MAP_GetLastResult(void *);
void *SYMBOL_MAP_CreateRecordTask(void *a, void *b, void *c) {
    void *task;
    void **w;
    task = func_020122C0(a, 0, SYMBOL_MAP_RecordTaskMain, 32);
    w = func_020124E8(task);
    w[6] = b;
    w[7] = c;
    EVENT_FIELD_PROCLINK_StartCommProc(w, a, 1, 0);
    ((int *)w)[2] = SYMBOL_MAP_GetLastResult(b);
    return task;
}
