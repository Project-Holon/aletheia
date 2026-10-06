/*
 * file:     button_man_p01.c
 * unit:     yes
 * function: func_02051880, func_0205189C, func_020518A4
 * address:  0x02051880
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned short u16;

struct Vec3 {
    u16 x;
    u16 y;
    u16 z;
};

struct Obj_02051880 {
    char pad[0x50];
    u16 x;
    u16 y;
    u16 z;
};

typedef unsigned int u32;

struct Obj_0205189C {
    char pad[0x6c];
    u32 f6c;
};

struct Obj_020518A4 {
    char pad[0x70];
    u16 f70;
};



/*
 * Setter on the same object as its packet-mate src/matched/func_020518AC.c:
 * copies a three-component 16-bit vector into the object's 0x50..0x54
 * triple.  The three loads come out ahead of the three stores, which is the
 * plain field-by-field spelling; a struct assignment would be ldm/stm.
 */
void func_02051880(struct Obj_02051880 *o, const struct Vec3 *v)
{
    o->x = v->x;
    o->y = v->y;
    o->z = v->z;
}


/*
 * Word setter on the same object as its packet-mate
 * src/matched/func_020518AC.c: stores the argument into field 0x6c.
 */
void func_0205189C(struct Obj_0205189C *o, u32 v)
{
    o->f6c = v;
}


/*
 * Halfword setter on the same object as its packet-mate
 * src/matched/func_020518AC.c: stores the argument into field 0x70.
 */
void func_020518A4(struct Obj_020518A4 *o, u16 v)
{
    o->f70 = v;
}
