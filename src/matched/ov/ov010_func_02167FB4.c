/*
 * function: func_02167FB4
 * address:  0x02167FB4
 * packet:   pkt_ov010_02167FB4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Sub-process sequence: runs five child processes one after another
 * (two from ov021, three from arm9), copying the result of the fifth
 * back and re-adding the chosen party members.
 *
 * First draft plus one lever (2026-09-28 tree_ov010_4): w->heap read into
 * a local before the switch. The member index is taken before the range
 * fix-up, so a reset slot still passes its old index (the image does not
 * reload it).
 *
 * symbols:
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   func_02014910  0x02014910  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_0201AA14  0x0201AA14  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0201A98C  0x0201A98C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct SeqWork {
    u32 heap;           /* 0x000 */
    void *arg;          /* 0x004 */
    u8 f08[0x28];       /* 0x008 */
    u8 f30[0x3C];       /* 0x030 */
    u32 f6c;            /* 0x06C */
    u32 f70;            /* 0x070 */
    u8 pad74[5];
    u8 order[6];        /* 0x079 */
    u8 pad7F[0x105];
    u32 *out184;        /* 0x184 */
    u32 *out188;        /* 0x188 */
    u8 *order18c;       /* 0x18C */
    void *party190;     /* 0x190 */
    void *party194;     /* 0x194 */
} SeqWork;

extern int func_021BE8D4(void *a, int b, int sel, int d);
struct Evt;
struct Party;
struct PartyMon;
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1);
extern void *func_02014910(char *a0, int a1, int a2, int a3);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *a0);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u32 func_0201AA14(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);

int func_02167FB4(void *evt, u32 *seq, SeqWork *w)
{
    int n;
    int i;
    int idx;
    u32 heap;

    heap = w->heap;
    switch (*seq) {
    case 0:
        func_02012374(evt, (struct Evt **)func_021BE8D4((void *)heap, (int)w->arg, 0, 0));
        (*seq)++;
        break;
    case 1:
        func_02012374(evt, (struct Evt **)FIELD_STATUS_CreateFieldCloseEvent(heap, (int)w->arg));
        (*seq)++;
        break;
    case 2:
        func_02012374(evt, func_02014910((char *)heap, (int)w->arg, (int)w->f30, (int)w->f08));
        (*seq)++;
        break;
    case 3:
        func_02012374(evt, FIELD_STATUS_CreateFieldOpenEvent((void *)heap));
        (*seq)++;
        break;
    case 4:
        func_02012374(evt, (struct Evt **)func_021BE92C((void *)heap, (int)w->arg, 0, 0, 1, 0, 0));
        MI_CpuCopy8(w->order, w->order18c, 6);
        *w->out188 = w->f6c;
        *w->out184 = w->f70;
        if (*w->out188 != 7 && *w->out188 != 8 && w->party194 != 0) {
            n = func_0201AA14(w->party194);
            for (i = 0; i < n; i++) {
                idx = w->order18c[i] - 1;
                if (idx >= 6)
                    w->order18c[i] = 1;
                func_0201A98C(w->party194, func_0201AB28(w->party190, idx));
            }
        }
        (*seq)++;
        break;
    case 5:
        return 1;
    }
    return 0;
}
