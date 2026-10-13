/*
 * function: func_0220E82C
 * address: 0x0220E82C
 * packet: pkt_ov198_0220E82C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x020275EC has no witness outside caller; the integrator owns it.
 * Verified scratch one: EXACT 12 bytes, Thumb, dsi/1.1p1 -O4,p.
 * typedef unsigned char u8;
 * extern const u8 _PokeTypePltOffset[];
 * unsigned func_020275EC(u8 index){return _PokeTypePltOffset[index];}
 * symbols: _PokeTypePltOffset 0x0209FCF8 data a1
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_020275F8 0x020275F8 thumb
 *   ARC_UTIL_LoadScreenDataFromHandle 0x02049E74 arm
 *   CLACT_TransferCharacter 0x0204A9D0 arm
 *   func_020307B0 0x020307B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020275EC 0x020275EC thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef unsigned int   u32;
struct Obj;
extern u32 func_020275F8(u32 a);
extern void *ARC_UTIL_LoadScreenDataFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
struct Sub0204A9D0;
extern void CLACT_TransferCharacter(int,struct Sub0204A9D0 *);
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *);
extern u8 func_020275EC(int i);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
void func_0220E82C(char *p,void *obj,int index,int which)
{
    void *owner,*data;
    struct Sub0204A9D0 *out;
    owner=func_020490F4(83,(u16)((*(u16 *)(*(char **)p+16)&0x7fff)|0x8000));
    data=ARC_UTIL_LoadScreenDataFromHandle((void *)((unsigned)owner),func_020275F8((u8)which),0,(unsigned)&out,(*(u16 *)(*(char **)p+16)&0x7fff)|0x8000);
    CLACT_TransferCharacter(*(unsigned *)(p+index*4+0x24a4),out);
    func_020307B0(data);
    ARC_TOOL_DeleteHandle(owner);
    CLACT_SetActorPaletteOffset(obj,(unsigned)func_020275EC((u8)which),1);
}
