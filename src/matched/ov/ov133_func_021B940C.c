/*
 * function: func_021B940C
 * address: 0x021B940C
 * packet: pkt_ov133_021B940C
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021BA594 0x021BA594 data ov133 a1
 *   func_02035CB8 0x02035CB8 arm
 *   func_02035C08 0x02035C08 arm
 *   func_021B96D8 0x021B96D8 thumb ov133
 *   func_020061E4 0x020061E4 thumb
 *   func_021BA098 0x021BA098 thumb ov133
 *   func_021B94C0 0x021B94C0 thumb ov133
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_021B9C08 0x021B9C08 thumb ov133
 *   func_0201ED04 0x0201ED04 thumb
 *   func_021B952C 0x021B952C thumb ov133
 *   func_021B8FA8 0x021B8FA8 thumb ov133
 */
#include "../include/Obj00004.h"
#include "../include/Obj23317.h"
#include "../include/Obj23318.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 bytes[12]; } Rects;
extern const Rects d_021BA594;
extern int func_02035CB8(int *, int *);
extern int func_02035C08(const void *);
extern void func_021B96D8(u8 *);
typedef unsigned int   u32;
struct WordSet;
extern void func_020061E4(u32 a);
extern void func_021BA098(u8 *);
extern void func_021B94C0(u8 *);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_021B9C08(u8 *, unsigned int, void *);
extern void func_0201ED04(struct WordSet *p);
extern void func_021B952C(u8 *);
extern void func_021B8FA8(u8 *);
int func_021B940C(u8 *p)
{
    Rects rects = d_021BA594;
    void *obj;
    func_02035CB8((int *)(p + 0x1c), (int *)(p + 0x20));
    switch (func_02035C08(&rects)) {
    case 0:
        func_021B96D8(p);
        func_020061E4(1358);
        func_021BA098(p);
        return 2;
    case 1:
        ((struct Obj00004 *)p)->fC = 6;
        ((struct Obj00004 *)p)->f10 = 192;
        func_020061E4(1962);
        func_021B94C0(p);
        obj = func_0201EC64(((struct Obj00004 *)p)->f0);
        func_0201EEF4(obj, 0, ((struct Obj23318 *)(*(u8 * *)&((struct Obj23317 *)(*(u8 * *)&((struct Obj00004 *)p)->f4))->f4))->f4);
        func_021B9C08(p, 0, obj);
        func_0201ED04(obj);
        func_021BA098(p);
        break;
    case -1:
        func_021B952C(p);
        break;
    }
    func_021B8FA8(p);
    return 0;
}
