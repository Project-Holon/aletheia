/*
 * function: FIELD_GIMMICK_GATE_ReadSaveBlockValues
 * address:  0x021F3B64
 * packet:   pkt_ov048_021F3B64
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetSaveBlock42  0x02012F68  thumb
 *   MISC_SAVEDATA_FindFreeRecordSlot  0x0200EC14  thumb
 *   MISC_SAVEDATA_ExportRecord  0x0200EC2C  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_Delete  0x02045808  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct St {
    void *p0;
    void *p1;
    int a;
    int b;
    u16 c;
    u8 pad[10];
} St;

extern void *GAME_DATA_GetSaveBlock42(void **h);
struct U16Vec;
extern int MISC_SAVEDATA_FindFreeRecordSlot(char *p);
struct Src0200EC2C;
struct Dst0200EC2C;
extern void MISC_SAVEDATA_ExportRecord(const struct Src0200EC2C *base, int idx, struct Dst0200EC2C *dst);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_Delete(struct U16Vec *vec);

void FIELD_GIMMICK_GATE_ReadSaveBlockValues(u16 *p, u32 *out, int *cnt)
{
    void *s;
    int i;
    St st;

    s = GAME_DATA_GetSaveBlock42((void **)(((int *)p)[2]));
    *cnt = MISC_SAVEDATA_FindFreeRecordSlot(s);
    for (i = 0; i < *cnt; i++) {
        st.p0 = STRBUF_Create(0x40, p[0]);
        st.p1 = STRBUF_Create(0x40, p[0]);
        MISC_SAVEDATA_ExportRecord(s, i, (struct Dst0200EC2C *)&st);
        out[i] = st.c;
        STRBUF_Delete(st.p0);
        STRBUF_Delete(st.p1);
    }
}
