/*
 * function: func_021B8EA8
 * address:  0x021B8EA8
 * packet:   pkt_ov070_021B8EA8
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B98C  0x0204B98C  arm
 *   func_0204B878  0x0204B878  arm
 *   func_021B809C  0x021B809C  thumb  ov070
 *   func_0204B92C  0x0204B92C  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_021BACF0  0x021BACF0  thumb  ov070
 *   func_021BB580  0x021BB580  thumb  ov070
 *   func_021BB3F4  0x021BB3F4  thumb  ov070
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B8F0C  0x021B8F0C  thumb  ov070
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Actor;
struct MsgBank;
struct Obj;
extern u32 func_0204B98C(struct Actor *a);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021B809C(u8 *p);
struct Obj;
extern void func_0204B92C(struct Obj *, unsigned int);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021BACF0(int p, int mode);
extern void func_021BB580(char *p, int v);
extern void func_021BB3F4(int p, int mode);
extern void func_021B6100(char *p, int k);
extern void func_021B8F0C(int p);

void func_021B8EA8(int p)
{
    if (func_0204B98C((struct Actor *)(*(int *)((char *)p + 0x72C))) == 0) {
        func_0204B878((struct Obj *)(*(int *)((char *)p + 0x72C)), 0);
        func_021B809C((u8 *)p);
        func_0204B92C((struct Obj *)*(int *)((char *)p + 0x6A8), 0);
        func_02045CAC((struct MsgBank *)(*(int *)((char *)p + 0x51C)), 0x8A, (void *)(*(int *)((char *)p + 0x528)));
        func_021BACF0(p, 0);
        func_021BB580((char *)p, 0);
        func_021BB3F4(p, 0);
        func_021B6100((char *)p, (int)func_021B8F0C);
    }
}
