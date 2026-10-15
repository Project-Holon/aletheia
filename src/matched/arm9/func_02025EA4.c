/*
 * function: CURSOR_MOVE_PollTouch
 * address:  0x02025EA4
 * packet:   pkt_02025D2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TOUCHPANEL_HitTrg  0x02035C08  arm
 *   CURSOR_MOVE_TestSkipBit  0x020261C4  thumb
 *   func_020355D8  0x020355D8  arm
 *   gCursorMoveTouchTag     0x0209FB58  data
 *
 * field_sound_system.c.  Scan the entry table hanging off the object for a
 * live record: each 12-byte entry's tag word (bytes 8..11) is copied into
 * the low half of a 8-byte stack scratch whose high half is preloaded from
 * the four-byte template gCursorMoveTouchTag, then handed to TOUCHPANEL_HitTrg.  A hit
 * that also passes the bitmap test at +0x10 commits the entry: the previous
 * slot id is shifted to +0xe, the new index becomes +0xd, an in-flight
 * request (field_4 == 1 with field_C == 1) is cancelled through the record's
 * vtable slot +4 before the normal slot +0xc notification, and the caller's
 * out word receives the index.
 *
 * Blocker: the pool word at 0x02025F5C holds 0x0209FB58 and that is the only
 * occurrence of the address anywhere in the image (arm9 and overlays), so the
 * only witness for the ABS32 site lies inside this function's own extent.
 * No evidence class applies -- `literal` needs the word at a different
 * address, `label` and `matched` need code -- so the function caps at MATCH
 * regardless of how the C is spelled.  Unstick it by decompiling any other
 * reader of 0x0209FB58, which would supply a second pool word.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/CURSOR_MOVE_PollTouch.c \
 *       --func CURSOR_MOVE_PollTouch --addr 0x02025EA4 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef void (*Callback)(u32, u8, u8);

struct Entry {
    u8 pad_0[8];
    u8 tag[4];
};

struct Vtbl {
    void (*slot0)(u32, u8, u8);
    void (*slot4)(u32, u8, u8);
    void (*slot8)(u32, u8, u8);
    void (*slotC)(u32, u8, u8);
};

struct Sound {
    struct Entry *entries;
    u32 field_4;
    u32 field_8;
    u8  field_C;
    u8  field_D;
    u8  field_E;
    u8  field_F;
    u32 field_10;
    u32 field_14;
    struct Vtbl *vtbl;
    u32 field_1C;
};

extern int TOUCHPANEL_HitTrg(const void *key);
extern int CURSOR_MOVE_TestSkipBit(const u32 *bitmap, u32 bit);
extern void func_020355D8(u8 v);
extern const u8 gCursorMoveTouchTag[4];

int CURSOR_MOVE_PollTouch(struct Sound *obj, int *out)
{
    u8 key[8];
    u16 i;
    int res;
    u32 *bitmap;
    struct Entry *e;

    key[4] = gCursorMoveTouchTag[0];
    key[5] = gCursorMoveTouchTag[1];
    key[6] = gCursorMoveTouchTag[2];
    key[7] = gCursorMoveTouchTag[3];
    res = 0;
    i = res;
    bitmap = (u32 *)((u8 *)obj + 0x10);
    *out = res - 1;

    while (1) {
        e = (struct Entry *)((u8 *)obj->entries + i * 12);
        if (e->tag[0] == 0xff) {
            break;
        }
        key[0] = ((volatile struct Entry *)e)->tag[0];
        key[1] = e->tag[1];
        key[2] = e->tag[2];
        key[3] = e->tag[3];
        if (TOUCHPANEL_HitTrg(key) != -1) {
            res = 1;
            if (CURSOR_MOVE_TestSkipBit(bitmap, i) == 1) {
                obj->field_E = obj->field_D;
                obj->field_D = (u8)i;
                if (obj->field_4 == 1 && obj->field_C == 1) {
                    obj->field_4 = 0;
                    obj->vtbl->slot4(obj->field_1C, obj->field_D, obj->field_E);
                }
                obj->vtbl->slotC(obj->field_1C, obj->field_D, obj->field_E);
                obj->field_E = 0xff;
                obj->field_F = 0xff;
                *out = i;
                func_020355D8(1);
                break;
            }
        }
        i = i + 1;
    }
    return res;
}
