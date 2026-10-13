/*
 * function: EVENT_FIELD_PROCLINK_ObjAnimEventMain
 * address:  0x02161850
 * packet:   pkt_ov010_02161850
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   EVENT_FIELD_PROCLINK_InitAnimNode  0x02161938  thumb  ov010
 *   FLDMMDL_ACMD_ListCreate  0x02197D3C  thumb  ov021
 *   EVENT_FIELD_PROCLINK_IsAnimNodeDone  0x02161964  thumb  ov010
 *   EVENT_FIELD_PROCLINK_UpdateAnimNode  0x02161984  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Obj {
    u8 pad00[4];
    void *f04;          /* 0x04 */
    u8 pad08[4];
    u16 f0c;            /* 0x0C */
    u8 pad0e[2];
    void *f10;          /* 0x10 */
} Obj;

extern void *FIELDMAP_GetMmdlSys(u8 *p);
extern void *EVENT_FIELD_PROCLINK_InitAnimNode(void *a, u32 b);
extern void *FLDMMDL_ACMD_ListCreate(void *a, void *b);
extern int EVENT_FIELD_PROCLINK_IsAnimNodeDone(int a0, int a1);
extern int EVENT_FIELD_PROCLINK_UpdateAnimNode(int a0);

int EVENT_FIELD_PROCLINK_ObjAnimEventMain(void *a0, int *state, Obj *o)
{
    void *t;

    t = FIELDMAP_GetMmdlSys(o->f04);
    switch (*state) {
    case 0:
        t = EVENT_FIELD_PROCLINK_InitAnimNode(t, o->f0c);
        if (t == 0)
            return 1;
        EVENT_FIELD_PROCLINK_IsAnimNodeDone((int)o, (int)FLDMMDL_ACMD_ListCreate(t, o->f10));
        *state = *state + 1;
        break;
    case 1:
        if (EVENT_FIELD_PROCLINK_UpdateAnimNode((int)o) == 0)
            return 1;
        break;
    }
    return 0;
}
