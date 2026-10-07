/*
 * file:     worldtrade_box_p17.c
 * unit:     yes
 * function: func_021F72C4, func_021F7338
 * address:  0x021F72C4
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
 *   func_0200846C  0x0200846C  thumb
 *   func_020084A0  0x020084A0  thumb
 *   func_020084D4  0x020084D4  thumb
 *   func_02008560  0x02008560  thumb
 *   func_02008568  0x02008568  thumb
 *   func_0200854C  0x0200854C  thumb
 *   func_02008558  0x02008558  thumb
 *   func_02008574  0x02008574  thumb
 *   func_02034714  0x02034714  arm
 */
struct Sub0200852CObj;
typedef signed char s8;

typedef signed short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u8 pad0[0x10];
    u32 f10;
    u32 f14;
} Info;

typedef struct {
    u8 pad0[0xF6];
    u8 fF6;
    u8 padF7[0x108 - 0xF7];
    u32 f108;
    u32 f10C;
    u8 name[0x120 - 0x110];
    u8 f120;
    u8 f121;
    u8 f122;
    u8 pad123;
    u8 f124;
    u8 f125;
} Entry_021F72C4;

typedef struct {
    u8 data[0x128];
} Entry_021F7338;

typedef struct {
    u8 pad0[0xD4];
    int cur;
    u8 padD8[0xE4 - 0xD8];
    Entry_021F7338 single;
    Entry_021F7338 arr[1];
} Obj;

extern void *func_0200846C(int a0);
extern void func_020084A0(struct Sub0200852CObj *p);
extern u32 func_020084D4(u32 value, void *dst);
extern void func_02008560(struct Sub0200852CObj *obj, u8 value);
extern void func_02008568(struct Sub0200852CObj *obj, u8 value);
extern void func_0200854C(struct Sub0200852CObj *obj, u8 value);
extern void func_02008558(struct Sub0200852CObj *obj, u8 value);
extern void func_02008574(struct Sub0200852CObj *obj, u8 a, u8 b);
extern void func_02034714(const char *expr, u32 line, const char *file);
Info *func_021F72C4(Entry_021F72C4 *e);
Entry_021F7338 *func_021F7338(Obj *p, int kind);


Info *func_021F72C4(Entry_021F72C4 *e)
{
    Info *info;

    info = func_0200846C(0x48);
    func_020084A0((struct Sub0200852CObj *)info);
    func_020084D4((u32)info, e->name);
    func_02008560((struct Sub0200852CObj *)info, e->f124);
    func_02008568((struct Sub0200852CObj *)info, e->f125);
    func_0200854C((struct Sub0200852CObj *)info, e->fF6);
    func_02008558((struct Sub0200852CObj *)info, e->f122);
    func_02008574((struct Sub0200852CObj *)info, e->f120, e->f121);
    info->f10 = e->f10C;
    info->f14 = e->f108;
    return info;
}


/*
 * Return the slot record for a kind: kind 9 is the current 0x128-byte
 * entry of the +0x20C array (index at +0xD4), kinds 10 and 8 share the
 * record at +0xE4. Any other kind reports through func_02034714 (raw
 * address 0x02203B80, a plain constant as in func_02202B20) and yields 0.
 */
Entry_021F7338 *func_021F7338(Obj *p, int kind)
{
    if (kind == 9) {
        return &p->arr[p->cur];
    } else if (kind == 10) {
        return &p->single;
    } else if (kind == 8) {
        return &p->single;
    }
    func_02034714((void *)0x02203B80, 0, (void *)0x02203B80);
    return 0;
}
