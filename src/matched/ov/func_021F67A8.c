/*
 * function: func_021F67A8
 * address:  0x021F67A8
 * packet:   pkt_021F67A8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_DecodeBoxParam  0x02017DBC  thumb
 *   func_02017E88  0x02017E88  thumb
 *   POKE_TOOL_EncodeBoxParam  0x02017DE4  thumb
 *   func_021F66F0  0x021F66F0  thumb
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   func_0202136C  0x0202136C  thumb
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *
 * Read one Pokemon's display parameters (presence 0xA9, species 5, form
 * 0x6F, egg 0x4C, held item 6, parameter 0x6E + 1) into the info record,
 * clearing its +3 byte for an egg. A present Pokemon gets its icon loaded
 * (func_021F66F0) and shown; the item sprite is shown with animation 0x29
 * or 0x28 by func_0202136C, or hidden when there is no item. An empty
 * slot hides both sprites and clears the icon record's +8 word.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 species;
    s8 f2;
    u8 f3;
} Info;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
} IconRec;

struct Sav;
extern u32 POKE_TOOL_DecodeBoxParam(struct Sav *p);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_EncodeBoxParam(struct Sav *p, u32 f);
extern void func_021F66F0(u32 species, u32 form, u32 gender, u32 isEgg, u32 slot, u32 f8, u32 arc, IconRec *rec);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
extern u32 func_0202136C(u16 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

void func_021F67A8(void *mon, u32 icon, u32 item_spr, u16 *species, u32 slot, u32 arc, Info *info, IconRec *rec)
{
    u32 present;
    u32 item;
    u32 egg;
    u32 form;

    POKE_TOOL_DecodeBoxParam(mon);
    present = func_02017E88(mon, 0xa9, 0);
    *species = func_02017E88(mon, 5, 0);
    form = func_02017E88(mon, 0x6f, 0);
    egg = func_02017E88(mon, 0x4c, 0);
    item = func_02017E88(mon, 6, 0);
    info->species = *species;
    info->f2 = func_02017E88(mon, 0x6e, 0) + 1;
    if (egg != 0) {
        info->f3 = 0;
    }
    POKE_TOOL_EncodeBoxParam(mon, 1);
    if (present != 0) {
        func_021F66F0(*species, form, info->f2 - 1, egg, slot, icon, arc, rec);
        CLACT_SetActorDrawEnable((struct Obj *)icon, 1);
        if (item != 0) {
            CLACT_SetActorDrawEnable((struct Obj *)item_spr, 1);
            if (func_0202136C(item) != 0) {
                CLACT_SetActorAnimSeq((struct Obj *)item_spr, 0x29);
            } else {
                CLACT_SetActorAnimSeq((struct Obj *)item_spr, 0x28);
            }
        } else {
            CLACT_SetActorDrawEnable((struct Obj *)item_spr, 0);
        }
    } else {
        CLACT_SetActorDrawEnable((struct Obj *)icon, 0);
        CLACT_SetActorDrawEnable((struct Obj *)item_spr, 0);
        rec->f8 = 0;
    }
}
