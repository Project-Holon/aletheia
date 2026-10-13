/*
 * function: GAME_DATA_Delete
 * address:  0x02012704
 * packet:   pkt_020124F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     wave 16: promoted.  0x0215E334 and 0x02159BBC are unlabelled ov010
 *           ENV_SetResourceSet thunks matched in src/matched/func_0215E334.c and
 *           func_02159BBC.c (`matched, overlay`); 0x021647D8, 0x0216CCB0 and
 *           0x021623BC resolve as sole-ref/code (overlay).
 * symbols:
 *   func_020307B0   0x020307B0  arm
 *   func_021647D8   0x021647D8  thumb  ov010
 *   BEACON_STATUS_Delete   0x02027584  thumb
 *   func_0202E794   0x0202E794  thumb
 *   func_0215E334   0x0215E334  thumb  ov010
 *   func_02006E64   0x02006E64  thumb
 *   func_02007AC8   0x02007AC8  thumb
 *   func_0216CCB0   0x0216CCB0  thumb  ov010
 *   func_02159BBC   0x02159BBC  thumb  ov010
 *   func_021623BC   0x021623BC  thumb  ov010
 *   FIELD_STATUS_Delete   0x02014444  thumb
 *   FIELD_SOUND_SYSTEM_Delete   0x0202889C  thumb
 *
 * A destructor: fifteen pointer fields of one big object handed to fifteen
 * different release functions, then the object itself to the base deleter
 * 0x020307B0 (the ARM `blx` target, called three times).
 *
 * The literal 0x6AC is pooled once and every other offset is derived from it
 * with `adds`/`subs` (0x690, 0x68C, 0x684, 0x5E4), which is why the second
 * group starts from 0x69 << 2: the offsets are the source's array indices
 * scaled by four, and the field reads are `p[0x1AB]`, `p[0x1A4]`, ... in a
 * `u32 *`.  Writing the fields as byte offsets through a `u8 *` reproduces
 * the same derived-constant chain.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_DATA_Delete.c \
 *       --func GAME_DATA_Delete --addr 0x02012704 --cc 1.1p1 --thumb
 */
#include "../include/Obj01611.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct SoundSys;
struct Sub02006E40Obj;
extern u32 func_020307B0(void *p);
extern int func_021647D8(int a0);
extern void BEACON_STATUS_Delete(u8 *p);
extern void func_0202E794(void *p);
extern void func_0215E334(void *ptr);
extern void func_02006E64(struct Sub02006E40Obj *obj);
extern void func_02007AC8(void *p);
extern int func_0216CCB0(int a0);
extern void func_02159BBC(void *ptr);
extern int func_021623BC(int a0);
extern void FIELD_STATUS_Delete(u32 p);
extern void FIELD_SOUND_SYSTEM_Delete(struct SoundSys *s);

void GAME_DATA_Delete(u8 *p)
{
    func_020307B0((void *)(((struct Obj01611 *)p)->f6AC));
    func_021647D8(((struct Obj01611 *)p)->f690);
    BEACON_STATUS_Delete((u8 *)(((struct Obj01611 *)p)->f68C));
    func_0202E794((void *)(((struct Obj01611 *)p)->f684));
    func_0215E334((void *)(((struct Obj01611 *)p)->f5E4));
    func_02006E64((struct Sub02006E40Obj *)(((struct Obj01611 *)p)->f1A4));
    func_020307B0((void *)(((struct Obj01611 *)p)->f1A0));
    func_02007AC8((void *)(((struct Obj01611 *)p)->f19C));
    func_020307B0((void *)(((struct Obj01611 *)p)->f18C));
    func_0216CCB0(((struct Obj01611 *)p)->f1A8);
    func_02159BBC((void *)(((struct Obj01611 *)p)->f1B0));
    func_021623BC(((struct Obj01611 *)p)->f158);
    FIELD_STATUS_Delete(((struct Obj01611 *)p)->f1B8);
    FIELD_SOUND_SYSTEM_Delete((struct SoundSys *)(((struct Obj01611 *)p)->f1B4));
    func_020307B0((void *)((u32)p));
}
