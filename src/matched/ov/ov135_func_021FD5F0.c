/*
 * function: WORLDTRADE_LIST_DrawSelectedRecord
 * address:  0x021FD5F0
 * packet:   pkt_021FD5F0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204989C  0x0204989C  arm
 *   WORLDTRADE_LIST_PrintNames  0x021FD85C  thumb
 *   WORLDTRADE_LIST_PrintRecordRow  0x021FD7DC  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0xF0];
    u8 rec[0x128 - 0xF0];
} Entry;

typedef struct {
    u8 pad0[0xD4];
    int cur;
    u8 padD8[0x20C - 0xD8];
    Entry arr[8];
    u8 padB4C[0xB6C - 0xB4C];
    void *bank;
    void *names;
    u8 padB74[0xB90 - 0xB74];
    void *name0;
    void *name1;
    u8 padB98[0xDB8 - 0xB98];
    void *pane2[5];
    void *pane;
    u8 padDD0[0xFA0 - 0xDD0];
    u8 fFA0[4];
} Work;

extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
extern void WORLDTRADE_LIST_PrintNames(void *pane, void *s1, void *s2, void *g);
extern void WORLDTRADE_LIST_PrintRecordRow(void *pane, void *bank, void *names, void *rec, void *g);

void WORLDTRADE_LIST_DrawSelectedRecord(Work *p)
{
    func_0204989C(0x60, 0x1E, 1, 0, 0x800, 1, 0x48);
    WORLDTRADE_LIST_PrintNames(p->pane2, p->name0, p->name1, p->fFA0);
    WORLDTRADE_LIST_PrintRecordRow(&p->pane, p->bank, p->names, p->arr[p->cur].rec, p->fFA0);
}
