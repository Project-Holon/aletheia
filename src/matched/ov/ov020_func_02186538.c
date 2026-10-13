/*
 * function: FIELD_WFBC_DATA_LOCAL_CreateMmdlHeaders
 * address:  0x02186538
 * packet:   pkt_ov020_02186538
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_WFBC_DATA_LOCAL_CountPeople  0x02186278  thumb  ov020
 *   func_02030734  0x02030734  arm
 *   FIELD_WFBC_DATA_LOCAL_OpenNpcData  0x021867C4  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_LoadMmdlPositionTable  0x02186830  thumb  ov020
 *   EVENT_FIELD_PROCLINK_IsReturnEntryValid  0x02161ECC  thumb  ov010
 *   FIELD_WFBC_DATA_LOCAL_GetNpcId  0x021867B0  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_LoadNpcData  0x02186818  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_GetNpcRecord  0x0218682C  thumb  ov020
 *   FLDMMDL_InitPosRecord  0x0216E618  thumb  ov010
 *   FIELD_WFBC_DATA_LOCAL_FreeMmdlPositionTable  0x0218683C  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_CloseNpcData  0x02186804  thumb  ov020
 *   d_02187EB4     0x02187EB4  data  ov020  a1
 *   d_02187DBC     0x02187DBC  data  ov020  a4
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
extern const Tmpl d_02187DBC;

extern int FIELD_WFBC_DATA_LOCAL_CountPeople(char *p, int which);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct ArcFile;
extern int *FIELD_WFBC_DATA_LOCAL_OpenNpcData(int a, int id);
extern void *FIELD_WFBC_DATA_LOCAL_LoadMmdlPositionTable(struct ArcFile **p, int b, unsigned int heap);
extern int EVENT_FIELD_PROCLINK_IsReturnEntryValid(void *p);
extern int FIELD_WFBC_DATA_LOCAL_GetNpcId(u8 *p);
extern void FIELD_WFBC_DATA_LOCAL_LoadNpcData(u32 *p, u32 member);
extern char *FIELD_WFBC_DATA_LOCAL_GetNpcRecord(char *p);
extern void FLDMMDL_InitPosRecord(Tmpl *, u16, u16, int);
extern void FIELD_WFBC_DATA_LOCAL_FreeMmdlPositionTable(void *p);
extern void FIELD_WFBC_DATA_LOCAL_CloseNpcData(void **p);

Tmpl *FIELD_WFBC_DATA_LOCAL_CreateMmdlHeaders(u16 *p, int which, int id)
{
    int k;
    Tmpl *buf;
    int h;
    u8 *t;
    int heap;
    int n;
    int i;
    int off;
    char *base;
    u16 *r;
    Tmpl *e;
    Tmpl tmp;

    heap = (u16)((id & 0x7FFF) | 0x8000);
    n = FIELD_WFBC_DATA_LOCAL_CountPeople((char *)p, which);
    if (n == 0)
        return 0;
    if (which == 0)
        base = (char *)p + 8;
    else
        base = (char *)p + 0xf8;
    buf = func_02030734(heap, n * 0x24, 1, d_02187EB4, 0x2E3);
    k = 0;
    h = (int)FIELD_WFBC_DATA_LOCAL_OpenNpcData(0, heap);
    t = FIELD_WFBC_DATA_LOCAL_LoadMmdlPositionTable((struct ArcFile **)h, p[1], heap);
    i = 0;
    tmp = d_02187DBC;
    for (; i < 10; i++) {
        off = i * 0x18;
        if (EVENT_FIELD_PROCLINK_IsReturnEntryValid(base + off)) {
            e = &buf[k];
            *e = tmp;
            FIELD_WFBC_DATA_LOCAL_LoadNpcData((u32 *)h, FIELD_WFBC_DATA_LOCAL_GetNpcId((u8 *)(base + off)));
            r = (u16 *)FIELD_WFBC_DATA_LOCAL_GetNpcRecord((char *)h);
            e->f0 = FIELD_WFBC_DATA_LOCAL_GetNpcId((u8 *)(base + off)) + 0x80;
            e->f2 = r[0];
            e->f4 = 3;
            if (which == 0) {
                if (p[1] == 0)
                    e->fA = r[0xf];
                else
                    e->fA = r[0xe];
            } else {
                if (p[1] == 0)
                    e->fA = r[0x11];
                else
                    e->fA = r[0x10];
            }
            FLDMMDL_InitPosRecord(e, t[i * 2], t[i * 2 + 1], 0);
            k++;
        }
    }
    FIELD_WFBC_DATA_LOCAL_FreeMmdlPositionTable(t);
    FIELD_WFBC_DATA_LOCAL_CloseNpcData((void **)h);
    return buf;
}
