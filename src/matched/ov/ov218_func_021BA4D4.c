/*
 * function: func_021BA4D4
 * address: 0x021BA4D4
 * packet: pkt_ov218_021BA4D4
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: original reads r0 at 021BA4F0 after 0204B294; extern retains that live return despite legacy void declaration.
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 */
typedef unsigned char u8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;
struct Obj;extern u32 func_0204B294(u32,u32,u32,u32,u32,u16,u16);extern void func_0204B92C(struct Obj *,u32);
struct Obj *func_021BA4D4(u32 owner,char *p){struct Obj *r;r=(struct Obj *)func_0204B294(owner,*(u32 *)(p+8),*(u32 *)(p+12),*(u32 *)(p+16),(u32)p,*(u16 *)(p+22),122);func_0204B92C(r,1);return r;}
