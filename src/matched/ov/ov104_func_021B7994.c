/*
 * function: func_021B7994
 * address: 0x021B7994
 * packet: pkt_ov104_021B7994
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: Observed byte truncations require u8 extern arguments at all three BG calls.
 * prototype: Incoming heap is u16, forwarded unchanged to narrow stack arguments.
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02040C14 0x02040C14 arm
 *   func_02049740 0x02049740 arm
 *   func_02049238 0x02049238 arm
 *   func_02049B40 0x02049B40 arm
 *   d_021B8F30 0x021B8F30 data ov104
 *   d_021B8F5C 0x021B8F5C data
 *   d_021B8FB4 0x021B8FB4 data
 *   d_021B8F40 0x021B8F40 data ov104
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { BG0=0 } BgId;
struct DispConfig;
struct BgTemplate { u8 bytes[32]; };
extern struct DispConfig d_021B8F30;
extern const u32 d_021B8F5C[];
extern const struct BgTemplate d_021B8FB4[];
extern const u32 d_021B8F40[];
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0203FC28(struct DispConfig *);
extern void func_0203FCA0(u8,const struct BgTemplate *,u8);
extern void func_020414AC(u8);
extern void func_02040588(u8,u32);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_02049B68(u32,u32,u32,u32,u32,u16);
extern void func_02049658(u32,u32,u32,u32,u32,u32,u16);
extern void func_020498F4(u32,u32,u32,u32,u32,u32,u16);
extern void func_02040C14(u32,u32,u32,u32);
extern u32 func_02049740(u32,u32,u32,u32,u32,u16);
extern void func_02049238(void *);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
void func_021B7994(void *p,u16 heap) {
 int i; BgId bg; void *archive;
 func_0203F8F4(heap);
 func_02045088(heap);
 func_0203FC28(&d_021B8F30);
 for(i=0;i<7;i++) {
  bg=d_021B8F5C[i];
  func_0203FCA0(bg,&d_021B8FB4[i],d_021B8F40[i]);
  func_020414AC(bg);
  func_02040588(bg,1);
 }
 archive=func_020490F4(0x5e,heap);
 func_02049B68((u32)archive,1,0,0,0,heap);
 func_02049B68((u32)archive,1,4,0,0,heap);
 func_02049658((u32)archive,0x24,1,0,0,0,heap);
 func_02049658((u32)archive,0,6,0,0,0,heap);
 func_02049658((u32)archive,0x30,4,0,0,0,heap);
 func_020498F4((u32)archive,0x25,1,0,0,0,heap);
 func_020498F4((u32)archive,4,6,0,0,0,heap);
 func_020498F4((u32)archive,0x2f,4,0,0,0,heap);
 func_02040C14(5,0,1,0);
 *(u32 *)p=func_02049740((u32)archive,0x31,5,0,0,heap);
 func_02049238(archive);
 func_02049B40(0x17,5,0,0x1a0,0x20,heap);
 func_02040C14(2,0,1,0);
}
