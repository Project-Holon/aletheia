/*
 * function: func_0220E8B4
 * address: 0x0220E8B4
 * packet: pkt_ov198_0220E8B4
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x02027604 has no witness outside caller; the integrator owns it.
 * Verified scratch one: EXACT 12 bytes, Thumb, dsi/1.1p1 -O4,p.
 * typedef unsigned char u8;
 * extern const u8 _WazaKindPltOffset[];
 * unsigned func_02027604(u8 index){return _WazaKindPltOffset[index];}
 * symbols: _WazaKindPltOffset 0x0209FCEC data a1
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02027610 0x02027610 thumb
 *   func_02049E74 0x02049E74 arm
 *   func_0204A9D0 0x0204A9D0 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049238 0x02049238 arm
 *   func_02027604 0x02027604 thumb
 *   func_0204B6F4 0x0204B6F4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {u8 low:7;u8 flip:1;} Flags;
struct Sub0204A9D0;
extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef unsigned int   u32;
struct Obj;
extern u32 func_02027610(u32 a);
extern void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_0204A9D0(int,struct Sub0204A9D0 *);
extern u32 func_020307B0(void *p);
extern void func_02049238(void *);
extern u8 func_02027604(u8 i);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
void func_0220E8B4(char *p,int first,int index,int which)
{
    void *owner,*data;
    struct Sub0204A9D0 *out;
    int toggle;
    toggle=((Flags *)(p+0x2175))->flip;
    first+=toggle;
    index+=toggle;
    owner=func_020490F4(83,(u16)((*(u16 *)(*(char **)p+16)&0x7fff)|0x8000));
    data=func_02049E74((void *)((unsigned)owner),func_02027610((u8)which),0,(unsigned)&out,(*(u16 *)(*(char **)p+16)&0x7fff)|0x8000);
    func_0204A9D0(*(int *)(p+index*4+0x24a4),out);
    func_020307B0(data);
    func_02049238(owner);
    func_0204B6F4(*(void **)(p+first*4+0x1ebc),(unsigned)func_02027604(which),1);
    ((Flags *)(p+0x2175))->flip^=1;
}
