/*
 * function: func_0689B354
 * address: 0x0689B354
 * packet: pkt_ov095_0689B354
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 0689B4D2..0689B4D4 is the two-byte C0 46 alignment nop; no follower.
 * prototype: entry r1 is live s (0689B356); the existing B0D4 caller's one-argument extern omits this forwarded argument.
 * symbols:
 *   func_0689B4D4 0x0689B4D4 thumb ov095
 *   func_0689B4E4 0x0689B4E4 thumb ov095
 *   func_0689B4F4 0x0689B4F4 thumb ov095
 *   func_0689B504 0x0689B504 thumb ov095
 *   func_0689ACCC 0x0689ACCC thumb ov095
 *   func_0689ACD8 0x0689ACD8 thumb ov095
 *   func_0689ACFC 0x0689ACFC thumb ov095
 *   func_0689AD24 0x0689AD24 thumb ov095
 *   func_0689AD4C 0x0689AD4C thumb ov095
 */
#include "../../../matched/include/Obj00409.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 kind:7, id:16, rest:9; } Q;
typedef struct { u8 n, pad[2], d[16]; } St;
extern u32 func_0689B4D4(u16, u32);
extern u8 func_0689B4E4(void *);
extern int func_0689B4F4(void *, void *, u32);
extern int func_0689B504(void *);
extern void func_0689ACCC(void *);
extern void func_0689ACD8(u8 *p, int a, unsigned short b);
extern void func_0689ACFC(u8 *p, int a, unsigned short b);
extern void func_0689AD24(u8 *p, int a, unsigned short b);
extern void func_0689AD4C(St *, u32, u32, u32);
void func_0689B354(St *st, u8 *s)
{
    u16 key;
    u32 k;
    int mode;
    key = (*(Q * *)&((struct Obj00409 *)s)->f70)->id;
    k = func_0689B4D4(key, 0x1b);
    mode = func_0689B4F4(((struct Obj00409 *)s)->fA0, ((struct Obj00409 *)s)->fA4, func_0689B4E4(((struct Obj00409 *)s)->f6C));
    func_0689ACCC(st);
    if (key == 0xae) k = func_0689B504(((struct Obj00409 *)s)->f6C);
    switch (k) {
    case 0:
        func_0689ACD8((u8 *)st, *(u32 *)&((struct Obj00409 *)s)->fA0, mode | 0x200);
        func_0689AD4C(st, *(u32 *)&((struct Obj00409 *)s)->fA0, key, mode);
        return;
    case 3:
        func_0689ACD8((u8 *)st, *(u32 *)&((struct Obj00409 *)s)->fA0, mode | 0x100);
        func_0689AD4C(st, *(u32 *)&((struct Obj00409 *)s)->fA0, key, mode);
        return;
    case 1:
        func_0689ACD8((u8 *)st, *(u32 *)&((struct Obj00409 *)s)->fA0, mode | 0x300);
        return;
    case 2:
        func_0689ACD8((u8 *)st, *(u32 *)&((struct Obj00409 *)s)->fA0, mode | 0x400);
        return;
    case 5:
        func_0689ACFC((u8 *)st, *(u32 *)&((struct Obj00409 *)s)->fA0, mode | 0x100);
        return;
    case 4:
        func_0689ACFC((u8 *)st, *(u32 *)&((struct Obj00409 *)s)->fA0, mode | 0x200);
        return;
    case 7:
    case 9:
        func_0689ACFC((u8 *)st, *(u32 *)&((struct Obj00409 *)s)->fA0, mode);
        return;
    case 6:
    case 12:
        func_0689AD24((u8 *)st, *(u32 *)&((struct Obj00409 *)s)->fA0, mode | 0x700);
        return;
    case 11:
        func_0689AD24((u8 *)st, *(u32 *)&((struct Obj00409 *)s)->fA0, mode | 0x600);
        return;
    case 8:
    case 10:
        func_0689AD24((u8 *)st, *(u32 *)&((struct Obj00409 *)s)->fA0, mode | 0x800);
        return;
    case 13:
        func_0689ACFC((u8 *)st, *(u32 *)&((struct Obj00409 *)s)->fA0, mode);
        break;
    }
}
