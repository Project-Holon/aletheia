/*
 * function: func_021C5DD8
 * address: 0x021C5DD8
 * packet: pkt_ov136_021C5DD8
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201C440 0x0201C440 thumb
 *   func_0204B100 0x0204B100 arm
 *   func_0202DB0C 0x0202DB0C thumb
 *   func_0202DE5C 0x0202DE5C thumb
 */
typedef unsigned char u8;
extern void *func_0201C440(int);
typedef unsigned int   u32;
struct Bank;
struct PmsDraw;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void *func_0202DB0C(void *,int,void *,void *,int,int,int);
extern void func_0202DE5C(struct PmsDraw *p, u8 v);
void func_021C5DD8(u8 *p)
{
    *(void **)(*(u8 **)(p+8)+0x36c) = func_0201C440(102);
    *(void **)(*(u8 **)(p+8)+0x368) = func_0204B100(8,2,102);
    *(void **)(*(u8 **)(p+8)+0x35c) = func_0202DB0C(*(void **)(*(u8 **)(p+8)+0x368),1,*(void **)(*(u8 **)(p+8)+0x36c),*(void **)(p+24),4,4,102);
    func_0202DE5C(*(void **)(*(u8 **)(p+8)+0x35c),0);
}
