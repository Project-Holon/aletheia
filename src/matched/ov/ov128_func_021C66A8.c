/*
 * function: func_021C66A8
 * address: 0x021C66A8
 * packet: pkt_ov128_021C66A8
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * calls: Heap arguments are full-width here: the caller does not truncate.
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040B94 0x02040B94 arm
 *   func_0204152C 0x0204152C arm
 *   func_02040588 0x02040588 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   d_021CA664 0x021CA664 data a4
 *   d_021CA718 0x021CA718 data a4
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {u32 a,b,c,d;} DispConfig;
extern const DispConfig d_021CA664;
extern const u8 d_021CA718[][32];
extern void func_0203F8F4(u32);
extern void func_0203FC28(DispConfig *);
extern void func_0203FCA0(u8,const void *,u32);
extern void func_02040B94(u8,u32,u32,u32);
extern void func_0204152C(u8,u16);
extern void func_02040588(u8,u32);
extern void func_02049B68(void *,u32,u32,u32,u32,u32);
extern void func_02049658(void *,u32,u32,u32,u32,u32,u32);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u32);
void func_021C66A8(char *p,int heap)
{
    DispConfig config;
    int i;
    func_0203F8F4(heap);
    config=d_021CA664;
    func_0203FC28(&config);
    for(i=0;i<5;i++) {
        func_0203FCA0(i,d_021CA718[i],0);
        func_02040B94(i,32,0,heap);
        func_0204152C(i,0);
        func_02040588(i,1);
    }
    func_02049B68(*(void **)(p+8),0,0,0,192,heap);
    func_02049B68(*(void **)(p+8),0,4,0,192,heap);
    func_02049658(*(void **)(p+8),3,0,0,0,0,heap);
    func_02049658(*(void **)(p+8),3,2,0,0,0,heap);
    func_02049658(*(void **)(p+8),3,4,0,0,0,heap);
    func_020498F4(*(void **)(p+8),5,0,0,0,0,heap);
    func_020498F4(*(void **)(p+8),14,4,0,0,0,heap);
}
