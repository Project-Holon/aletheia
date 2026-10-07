/*
 * file:     fieldmap_p11.c
 * unit:     yes
 * function: func_021897A0, func_021897BC, func_021897DC
 * address:  0x021897A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_021A0170  0x021A0170  thumb  ov021
 *   func_021A0568  0x021A0568  thumb  ov021
 *   func_02048AD0  0x02048AD0  arm
 *   func_02048C58  0x02048C58  arm
 *   func_0218CC64  0x0218CC64  thumb  ov021
 */
#include "../../matched/include/Obj04887.h"

struct Light;
struct LightSlot;
typedef struct {
    int id;
    void *buf;
} Slot;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

u32 func_020307B0(void *p);
extern void func_02048AD0(struct Light *l);
extern void func_02048C58(struct LightSlot *slots);
extern u32 func_0218CC64(u32, u32, u32);
extern void func_021A0170(u8 *p, u32 a1, u32 a2, u32 a3);
extern void func_021A0568(u8 *p, int force);
void func_021897A0(unsigned char *p, int id);
int *func_021897BC(char *p, int idx);
int func_021897DC(u32 a, u32 b, u32 c, u32 d);


void func_021897A0(unsigned char *p, int id)
{
    Slot *s = (Slot *)(p + 0x118);
    if (id != -1) {
        func_020307B0(s->buf);
        s->id = -1;
    }
}

int *func_021897BC(char *p, int idx)
{
    int *q = (int *)(p + 0x118);

    if (idx == -1)
        return 0;
    if (idx != q[0])
        return 0;
    return (int *)q[1];
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021897DC(u32 a, u32 b, u32 c, u32 d)
{
func_021A0170((u8 *)(((struct Obj04887 *)((u8 *)(a)))->f18), b, c, d);
func_021A0568((u8 *)(((struct Obj04887 *)((u8 *)(a)))->f14), 0);
func_02048AD0((struct Light *)(*(u32 *)((u8 *)((a + 164)))));
func_02048C58((struct LightSlot *)(*(u32 *)((u8 *)((a + 168)))));
return func_0218CC64(((struct Obj04887 *)((u8 *)(a)))->f48, *(u32 *)((u8 *)((a + 164))), 0);
}
