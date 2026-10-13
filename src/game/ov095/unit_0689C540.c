/*
 * file:     unit_0689C540.c
 * function: func_0689C540
 * address:  0x0689C540
 * packet:   pkt_ov095_0689C540
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb
 *   BTL_POKEPARAM_GetSickContRaw  0x021D6314  thumb
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb
 *   BTLV_CORE_GetSlotValue  0x021E8B80  thumb
 *   BTLV_CORE_GetSlotFlag  0x021E8C24  thumb
 */

typedef unsigned char u8;

extern int BTL_POKEPARAM_HasSick(void *, int);
typedef struct Word { int v; } Word;
extern Word BTL_POKEPARAM_GetSickContRaw(void *, int);
extern int BTLV_CORE_GetSlotValue(void);
extern int BTL_EVENT_GetVar(int);
extern int BTLV_CORE_GetSlotFlag(int);
extern void BTL_EVENT_OverwriteVar(int, int);

void func_0689C540(void *a, void *b)
{
    int k;
    int v;
    u8 x;

    k = 0x11;
    if (BTL_POKEPARAM_HasSick(b, k) != 0) {
        v = BTL_POKEPARAM_GetSickContRaw(b, k).v;
        x = BTLV_CORE_GetSlotValue();
        if (x == (u8)BTL_EVENT_GetVar(0x15)) {
            BTL_EVENT_OverwriteVar(BTLV_CORE_GetSlotFlag(v) == 0 ? 0x4b : 0x4c, 1);
        }
    }
    if (BTL_POKEPARAM_HasSick(b, 0x15) != 0) {
        if (BTL_EVENT_GetVar(0x16) == 4)
            BTL_EVENT_OverwriteVar(0x4b, 1);
    }
    if (BTL_POKEPARAM_HasSick(b, 0x1f) != 0) {
        if (BTL_EVENT_GetVar(0x16) == 4)
            BTL_EVENT_OverwriteVar(0x4b, 1);
    }
}
