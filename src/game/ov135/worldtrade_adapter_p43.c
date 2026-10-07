/*
 * file:     worldtrade_adapter_p43.c
 * unit:     yes
 * function: func_0220262C, func_02202644, func_02202670, func_022026A0
 * address:  0x0220262C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020456F8  0x020456F8  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02041B6C  0x02041B6C  arm
 */
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Mon;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef signed short s16;

extern u32 func_020173EC(void);
extern void func_02082D44(u32 a, u32 b, u32 c);
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void func_02041B6C(u32 bit);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern void *func_0201747C(struct Mon *p, u32 heap);
extern u32 func_020307B0(void *p);
void func_0220262C(u32 a, u32 b);
void func_02202644(u32 a, int kind);
u32 func_02202670(u32 a, u32 b, u32 c, u32 d);
void func_022026A0(u8 *p, u32 k);


/*
 * Hand the size guess back to the main writer with the caller's handle.
 */
void func_0220262C(u32 a, u32 b)
{
    func_02082D44(a, b, func_020173EC());
}


/*
 * switch on kind
 */
void func_02202644(u32 a, int kind)
{
    func_020456F8((struct Descriptor *)a);
    switch (kind) {
    case 0:
        func_020409B4(func_02045730((struct Descriptor *)a));
        break;
    case 1:
        func_02041B6C(func_02045730((struct Descriptor *)a));
        break;
    }
}


/*
 * Encode one record through the two stage helpers and flush it to the writer.
 */
u32 func_02202670(u32 a, u32 b, u32 c, u32 d)
{
    u32 t1 = (u32)func_02045EC0((struct MsgBank *)b, c);
    u32 t2 = (u32)func_020457B0(0x200, d);

    func_0201F250((struct WordSet *)a, (void *)t2, (void *)t1);
    func_02045808((struct U16Vec *)t1);
    return t2;
}


/*
 * Create the 0x48 sub-object, register the handle and hand it to the callback.
 */
void func_022026A0(u8 *p, u32 k)
{
    u32 h = (u32)func_0201747C((struct Mon *)p, 0x48);

    func_0220262C(h, k);
    func_020307B0((void *)h);
}
