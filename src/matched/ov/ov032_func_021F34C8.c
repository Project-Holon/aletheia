/*
 * function: BEACON_VIEW_DeleteEntry
 * address:  0x021F34C8
 * packet:   pkt_021F34C8
 * region:   ov032
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   STRBUF_Delete  0x02045808  arm
 *   BMP_OAM_SetEnabled  0x02025774  thumb
 *   BMP_OAM_Delete  0x0202570C  thumb
 *   BMP_Delete  0x020437AC  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   MI_CpuFill8  0x02082BCC  arm
 */

typedef struct {
    char _pad0[0xc];
    unsigned f0c;
    unsigned f10;
    unsigned f14;
    unsigned f18;
    unsigned f1c;
    unsigned f20;
    unsigned f24;
} T_021F34C8;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Grid;
struct Obj;
struct Obj020437AC;
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_OAM_SetEnabled(u8 *g, u32 a);
extern void BMP_OAM_Delete(struct Grid *g);
extern void BMP_Delete(struct Obj020437AC *p);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void CLACT_DeleteActor(struct Obj *p);
extern void MI_CpuFill8(void *p, int v, int n);

void BEACON_VIEW_DeleteEntry(char *a0, int a1)
{
    T_021F34C8 *p = (T_021F34C8 *)(a0 + 0x1B8 + a1 * 0x34);

    STRBUF_Delete((struct U16Vec *)p->f24);
    STRBUF_Delete((struct U16Vec *)p->f20);
    BMP_OAM_SetEnabled((u8 *)p->f18, 0);
    BMP_OAM_Delete((struct Grid *)p->f18);
    BMP_Delete((struct Obj020437AC *)p->f1c);
    CLACT_SetActorDrawEnable((struct Obj *)p->f14, 0);
    CLACT_DeleteActor((struct Obj *)p->f14);
    CLACT_SetActorDrawEnable((struct Obj *)p->f10, 0);
    CLACT_DeleteActor((struct Obj *)p->f10);
    CLACT_SetActorDrawEnable((struct Obj *)p->f0c, 0);
    CLACT_DeleteActor((struct Obj *)p->f0c);
    MI_CpuFill8(p, 0, 0x34);
}
