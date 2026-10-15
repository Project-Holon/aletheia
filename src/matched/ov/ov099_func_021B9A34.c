/*
 * function: WIFICLUBACTOR_FreeActor
 * address:  0x021B9A34
 * packet:   pkt_ov099_021BF2C4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocker: callee 0x021C4948 (ov127) is unlabelled in the ov127 listing
 * ("ldr r3, =0x02082BCC; movs r1, #0; movs r2, #0x18; bx r3"); witness
 * bl from ov099 at 0x021B9A40. Seeding it (ov127 lane) makes this EXACT.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   WF2DMAP_OBJ_Clear  0x021C4948  thumb  ov127
 *   WF2DMAP_OBJDRAW_RemoveActor  0x021C5704  thumb  ov127
 */
typedef unsigned char  u8;
extern void WF2DMAP_OBJDRAW_RemoveActor(u8 *p);
extern void WF2DMAP_OBJ_Clear(void *p);
extern void MI_CpuFill8(void *p, int v, int n);

typedef struct {
    void *f0;
    void *f4;
    char pad[0x14];
} Obj;

void WIFICLUBACTOR_FreeActor(Obj *p)
{
    WF2DMAP_OBJDRAW_RemoveActor(p->f4);
    WF2DMAP_OBJ_Clear(p->f0);
    MI_CpuFill8(p, 0, sizeof(Obj));
}
