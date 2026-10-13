/*
 * function: FIELD_WFBC_DATA_LOCAL_CreateItemMmdlHeaders
 * address:  0x021868B8
 * packet:   pkt_ov020_021868B8
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_WFBC_DATA_LOCAL_CountItemSlots  0x02186854  thumb  ov020
 *   func_02030734  0x02030734  arm
 *   FIELD_WFBC_DATA_LOCAL_OpenNpcData  0x021867C4  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_LoadMmdlPositionTable  0x02186830  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_IsItemSlotUsed  0x021868A0  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_GetItemPositionPair  0x0218684C  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_GetItemSlot  0x02186898  thumb  ov020
 *   FLDMMDL_InitPosRecord  0x0216E618  thumb  ov010
 *   FIELD_WFBC_DATA_LOCAL_FreeMmdlPositionTable  0x0218683C  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_CloseNpcData  0x02186804  thumb  ov020
 *   d_02187EB4     0x02187EB4  data  ov020  a1
 *   d_02187DE0     0x02187DE0  data  ov020  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u16 f8;
    u16 fA;
    int f0C[6];
} Tmpl;

extern const char d_02187EB4[];
extern const Tmpl d_02187DE0;

extern int FIELD_WFBC_DATA_LOCAL_CountItemSlots(u16 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct ArcFile;
extern int *FIELD_WFBC_DATA_LOCAL_OpenNpcData(int a, int id);
extern void *FIELD_WFBC_DATA_LOCAL_LoadMmdlPositionTable(struct ArcFile **p, int b, unsigned int heap);
extern int FIELD_WFBC_DATA_LOCAL_IsItemSlotUsed(u16 *p, int i);
extern u8 *FIELD_WFBC_DATA_LOCAL_GetItemPositionPair(u8 *t, int i);
extern u16 FIELD_WFBC_DATA_LOCAL_GetItemSlot(u16 *p, int i);
extern void FLDMMDL_InitPosRecord(Tmpl *, u16, u16, int);
extern void FIELD_WFBC_DATA_LOCAL_FreeMmdlPositionTable(void *p);
extern void FIELD_WFBC_DATA_LOCAL_CloseNpcData(void **p);

Tmpl *FIELD_WFBC_DATA_LOCAL_CreateItemMmdlHeaders(void *p, int a1, int a2, int id)
{
    Tmpl *buf;
    int h;
    u8 *t;
    u8 *q;
    int heap;
    int n;
    int k;
    Tmpl *e;
    int i;
    Tmpl tmp;

    if (a1 != 0)
        return 0;
    if (a2 == 0)
        return 0;
    heap = (u16)((id & 0x7FFF) | 0x8000);
    n = FIELD_WFBC_DATA_LOCAL_CountItemSlots(p);
    k = 0;
    buf = func_02030734(heap, n * 0x24, 1, d_02187EB4, 0x561);
    h = (int)FIELD_WFBC_DATA_LOCAL_OpenNpcData(0, heap);
    t = FIELD_WFBC_DATA_LOCAL_LoadMmdlPositionTable((struct ArcFile **)h, a2, heap);
    i = 0;
    tmp = d_02187DE0;
    for (; i < 10; i++) {
        if (FIELD_WFBC_DATA_LOCAL_IsItemSlotUsed(p, i)) {
            q = FIELD_WFBC_DATA_LOCAL_GetItemPositionPair(t, i);
            e = &buf[k];
            *e = tmp;
            e->f0 = i + 0xa0;
            e->fA = FIELD_WFBC_DATA_LOCAL_GetItemSlot(p, i);
            e->f8 = i + 0xaa0;
            FLDMMDL_InitPosRecord(e, q[0], q[1], 0);
            k++;
        }
    }
    FIELD_WFBC_DATA_LOCAL_FreeMmdlPositionTable(t);
    FIELD_WFBC_DATA_LOCAL_CloseNpcData((void **)h);
    return buf;
}
