/*
 * function: func_02025D2C
 * address:  0x02025D2C
 * packet:   pkt_02025D2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02025EA4  0x02025EA4  thumb
 *   func_02025FC8  0x02025FC8  thumb
 *   func_02025F60  0x02025F60  thumb
 *   func_02026010  0x02026010  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_020355D8  0x020355D8  arm
 *
 * field_sound_system.c.  The primary-pad poll: with no pending selection, read the four direction bits of the button word and hand the matching entry to func_02026010; B answers the current slot and A answers -2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02025D2C.c \
 *       --func func_02025D2C --addr 0x02025D2C --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Sound {
    const u8 *entries;
    u32 field_4;
    u32 field_8;
    u8  field_C;
    u8  field_D;
    u8  field_E;
    u8  field_F;
    u32 field_10;
    u32 field_14;
    u32 field_18;
    u32 field_1C;
};

extern int  func_02025EA4(struct Sound *obj, int *out);
extern int  func_02025FC8(struct Sound *obj);
extern u32  func_02025F60(const u8 *ptr, u32 idx, u32 type);
extern int  func_02026010(struct Sound *obj, u32 dir, u32 sel);
extern u32  func_020362DC(void);
extern u32  func_020362DC(void);
extern void func_020355D8(u8 v);

int func_02025D2C(struct Sound *obj)
{
    int dir;
    int res;
    u32 sel;

    if (func_02025EA4(obj, &res) == 1) {
        return res;
    }
    if (obj->field_4 == 0 && obj->field_C == 1) {
        return func_02025FC8(obj);
    }

    if (func_020362DC() & 0x40) {
        sel = func_02025F60(obj->entries, obj->field_D, 0);
        dir = 0;
    } else if (func_020362DC() & 0x80) {
        sel = func_02025F60(obj->entries, obj->field_D, 1);
        dir = 1;
    } else if (func_020362DC() & 0x20) {
        sel = func_02025F60(obj->entries, obj->field_D, 2);
        dir = 2;
    } else if (func_020362DC() & 0x10) {
        sel = func_02025F60(obj->entries, obj->field_D, 3);
        dir = 3;
    } else {
        sel = 0xff;
    }

    if (sel != 0xff) {
        return func_02026010(obj, dir, sel);
    }
    if (func_020362DC() & 1) {
        func_020355D8(0);
        return obj->field_D;
    }
    if (func_020362DC() & 2) {
        dir = 0;
        func_020355D8(0);
        return dir - 2;
    }
    return -1;
}

/*
 * Note: func_02026010 takes three arguments; the third is the slot value
 * func_02025F60 returned, which reads at the call site as a leftover r2 but
 * is a real argument -- without it the `adds r2, r0, #0` after the call is
 * dead-code eliminated and the function comes out two bytes short.
 */
