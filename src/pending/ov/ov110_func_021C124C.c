/*
 * function: func_021C124C
 * address: 0x021C124C
 * packet: pkt_ov110_021C124C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH
 * Blocked on ARM9 0x02024910 (no outside witness); verified leaf C follows.
 * blocker: 0x02024910 Thumb, EXACT (block24910.log)
 *   typedef unsigned char u8;
 *   void *func_02024910(u8 *p,int i) { return p+8+i*8; }
 * symbols:
 *   func_02024910 0x02024910 thumb
 *   func_0202452C 0x0202452C thumb
 *   func_021C080C 0x021C080C thumb ov110
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0202DE64 0x0202DE64 thumb
 *   func_0202DE5C 0x0202DE5C thumb
 *   func_02024464 0x02024464 thumb
 *   func_0202DC48 0x0202DC48 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_02024910(void *,u8);
extern u16 func_0202452C(void *);
extern void func_021C080C(u8 *,int,int,int);
extern void *func_02045770(void *);
extern void func_02043B5C(void *,unsigned);
extern void func_0202DE64(void *,u16);
extern void func_0202DE5C(void *,unsigned);
extern int func_02024464(void *,u16);
extern void func_0202DC48(void *,void *,void *,int);
void func_021C124C(u8 *p,int index,u8 which,int flag) {
    void *item;
    item=func_02024910(*(void **)(p+0x20),which);
    func_021C080C(p+0x24,index,func_0202452C(item),flag);
    if (flag) {
        func_02043B5C(func_02045770(*(void **)(p+0x6c+index*4)),14);
        func_0202DE64(*(void **)(p+0x8c),0x44e);
        func_0202DE5C(*(void **)(p+0x8c),14);
    } else {
        func_02043B5C(func_02045770(*(void **)(p+0x6c+index*4)),13);
        func_0202DE64(*(void **)(p+0x8c),0x44d);
        func_0202DE5C(*(void **)(p+0x8c),13);
    }
    if (func_02024464(item,*(u16 *)(p+4))==1) {
        func_0202DC48(*(void **)(p+0x8c),*(void **)(p+0x6c+index*4),item,index);
        *(int *)(p+0x7c+index*4)=1;
    }
}
