/*
 * unit:     yes
 * function: BTLV_SCD_StartActionMenu, BTLV_SCD_StartActionMenuBackOnly
 * address:  0x06899ED0
 * packet:   pkt_ov095_06899ED0
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two functions: 0x06899ED0 and the unlabelled tail-call stub 0x06899F00
 * (the extent 0x06899ED0..0x06899F28 is code and pool only).
 *
 * symbols:
 *   BTLV_SCD_PushTask  0x06899E48  thumb  ov095
 *   BTLV_SCD_OpenActionMenuStep  0x0689A030  thumb  ov095
 *   BTLV_SCD_WaitActionTouchStep  0x0689A76C  thumb  ov095
 *   BTLV_SCD_WaitBackTouchStep  0x0689A84C  thumb  ov095
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Obj {
    u8 pad0[0x6c];
    int f6c;
    int f70;
    u8 pad74[0x8b - 0x74];
    u8 f8b;
    u8 pad8c[0x91 - 0x8c];
    u8 f91;
    u8 pad92[0x98 - 0x92];
    int f98;
} Obj;

struct Q;
extern int BTLV_SCD_OpenActionMenuStep(int unused, u8 *p);
extern int BTLV_SCD_WaitActionTouchStep(int *st, u8 *s);
extern int BTLV_SCD_WaitBackTouchStep(u32 unused, u32 p);
extern void BTLV_SCD_PushTask(struct Q *p, void *a, void *b);

void BTLV_SCD_StartActionMenu(Obj *o, int a, u8 b, u8 c, int d)
{
    o->f6c = a;
    o->f70 = d;
    o->f98 = 0;
    o->f8b = b;
    o->f91 = c;
    BTLV_SCD_PushTask((struct Q *)o, BTLV_SCD_OpenActionMenuStep, (void (*)(void))BTLV_SCD_WaitActionTouchStep);
}

void BTLV_SCD_StartActionMenuBackOnly(Obj *o, int a, u8 b, int c)
{
    o->f6c = a;
    o->f70 = c;
    o->f98 = 0;
    o->f8b = b;
    BTLV_SCD_PushTask((struct Q *)o, BTLV_SCD_OpenActionMenuStep, (void (*)(void))BTLV_SCD_WaitBackTouchStep);
}
