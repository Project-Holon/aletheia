/*
 * file:     comm_player_p06.c
 * unit:     yes
 * function: func_02167BCC, func_02167BD8, func_02167BE4
 * address:  0x02167BCC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Obj_02167BCC {
    u8 pad00[9];
    u8 b09;
    u8 pad0a[0x668 - 0x0A];
    u32 w668;
} Obj_02167BCC;

typedef struct Obj_02167BD8 {
    u8 pad00[0x668];
    u32 w668;
} Obj_02167BD8;

typedef struct Obj_02167BE4 {
    u8 pad00[0x668];
    u32 w668;
} Obj_02167BE4;

void func_02167BCC(Obj_02167BCC *o);
void func_02167BD8(Obj_02167BD8 *o, u32 v);
void func_02167BE4(Obj_02167BE4 *o, u32 v);


/*
 * Unlabelled Thumb leaf hidden in a word run (no lr saved); callee of ov010 func_02167BFC.
 */
void func_02167BCC(Obj_02167BCC *o)
{
    o->w668 = o->b09;
}


void func_02167BD8(Obj_02167BD8 *o, u32 v)
{
    o->w668 = v;
}


void func_02167BE4(Obj_02167BE4 *o, u32 v)
{
    o->w668 = v;
}
