/*
 * function: FIELD_TASK_CreateRepeatPlayerEffect
 * address:  0x021C7D28
 * packet:   pkt_ov021_021C7D28
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FIELD_TASK_Create  0x021C6C70  thumb  ov021
 *   FIELD_TASK_GetWork  0x021C6CCC  thumb  ov021
 *   FIELD_TASK_UpdateRepeatPlayerEffect  0x021C7D78  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {
    int f0;
    int f4;
    void *f8;
    u8 fC;
    u8 padD;
    u16 fE;
    u16 f10;
    u16 f12;
} Obj;

typedef unsigned int   u32;
extern u16 FIELDMAP_GetHeapId(u8 *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u32 FIELDMAP_GetEffect(u8 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern int FIELD_TASK_Create(int, int, int (*)(Obj *));
extern u32 FIELD_TASK_GetWork(u8 *p);
extern int FIELD_TASK_UpdateRepeatPlayerEffect(Obj *);

int FIELD_TASK_CreateRepeatPlayerEffect(int a, int b, u16 c, u16 d)
{
    int w;
    void *s;
    int h;
    Obj *o;

    w = FIELDMAP_GetHeapId((u8 *)a);
    s = FIELDMAP_GetFieldPlayer((void *)a);
    h = FIELD_TASK_Create(w, 0x14, FIELD_TASK_UpdateRepeatPlayerEffect);
    o = (Obj *)FIELD_TASK_GetWork((u8 *)h);
    o->f0 = a;
    o->f4 = FIELDMAP_GetEffect((u8 *)a);
    o->f8 = FIELD_PLAYER_GetMmdl((void *)s);
    o->fC = 0;
    o->fE = 0;
    o->f10 = c;
    o->f12 = d;
    return h;
}
