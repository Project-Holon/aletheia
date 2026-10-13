/*
 * function: ENTRANCE_CAMERA_InitWork
 * address:  0x021BDD7C
 * packet:   pkt_ov021_021BDD7C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 */

typedef struct {
    void *f0;
    void *f4;
    char pad[0x5C];
    int f64;
} Obj;

extern void func_02082BCC(void *p, int v, int n);
extern void *FIELDMAP_GetCamera(void *a);

void ENTRANCE_CAMERA_InitWork(Obj *p, void *a)
{
    func_02082BCC(p, 0, 0x70);
    p->f0 = a;
    p->f4 = FIELDMAP_GetCamera(a);
    p->f64 = 0;
}
