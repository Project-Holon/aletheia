/*
 * function: func_021C526C
 * address: 0x021C526C
 * packet: pkt_ov208_021C526C
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02015EA0 0x02015EA0 thumb
 *   func_02015EB0 0x02015EB0 thumb
 *   func_021C595C 0x021C595C thumb ov208
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_02015EA0(void *p);
extern void func_02015EB0(void *p);
extern void func_021C595C(u16 *heap,u8 *p,int key);
void func_021C526C(u16 *heap,u8 *p,int key)
{
    if(*(int *)(p+0x124)) {
        func_02015EA0(*(void **)(p+0xc));
        if(*(void **)(p+0x94))func_02015EA0(*(void **)(p+0x94));
        *(int *)(p+0x124)=0;
    } else {
        func_02015EA0(*(void **)(p+0x50));
        if(*(void **)(p+0xd8))func_02015EA0(*(void **)(p+0xd8));
        *(int *)(p+0x124)=1;
    }
    func_021C595C(heap,p,key);
    if(*(int *)(p+0x124)) {
        func_02015EB0(*(void **)(p+0xc));
        if(*(void **)(p+0x94))func_02015EB0(*(void **)(p+0x94));
    } else {
        func_02015EB0(*(void **)(p+0x50));
        if(*(void **)(p+0xd8))func_02015EB0(*(void **)(p+0xd8));
    }
}
