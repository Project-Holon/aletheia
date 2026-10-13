/*
 * unit:     no
 * function: APP_TASKMENU_WIN_SetActive
 * address:  0x02028218
 * packet:   pkt_02028178
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A tail call that clears the u16 at offset 0x14 and forwards two of the
 * object's own fields plus the caller's argument.
 *
 * symbols:
 *   APP_TASKMENU_SetWinActive  0x02027B30  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj {
    u32 field_00;
    u32 pad_04[4];
    u16 field_14;
    u16 pad_16;
    u32 field_18;
};

struct S;
extern void APP_TASKMENU_SetWinActive(u32 a0, struct S *s, int mode);

void APP_TASKMENU_WIN_SetActive(struct Obj *obj, u32 a)
{
    obj->field_14 = 0;
    APP_TASKMENU_SetWinActive(obj->field_00, (struct S *)obj->field_18, a);
}
