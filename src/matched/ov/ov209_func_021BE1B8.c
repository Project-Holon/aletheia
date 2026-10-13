/*
 * function: func_021BE1B8
 * address: 0x021BE1B8
 * packet: pkt_ov209_021BE1B8
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Halfword stack input is widened into a saved local; its final callee takes the observed full-width value.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   POKE_TOOL_CalcGraphicIndex 0x0201BABC thumb
 *   func_02049E74 0x02049E74 arm
 *   CLACT_GetActorCharacterIndex 0x0204B7F0 arm
 *   CLACT_TransferCharacterPart 0x0204AA94 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049238 0x02049238 arm
 *   func_0201BB5C 0x0201BB5C thumb
 *   func_0204B6F4 0x0204B6F4 arm
 */
typedef unsigned short u16;
typedef unsigned char u8;
struct Out { char pad[20]; void *f14; };
struct Obj;
extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef unsigned int   u32;
extern u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);
extern void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern u16 CLACT_GetActorCharacterIndex(u8 *);
extern void CLACT_TransferCharacterPart(int,void *,unsigned,int,int);
extern u32 func_020307B0(void *p);
extern void func_02049238(void *);
extern unsigned func_0201BB5C(unsigned,unsigned,unsigned,unsigned);
extern void func_0204B6F4(struct Obj *,unsigned,unsigned);
void func_021BE1B8(char *p, int index, unsigned species, u16 form, u16 half, int mode)
{
    void *owner;
    void *data;
    struct Out *out;
    struct Obj **slot;
    unsigned saved;
    owner=func_020490F4(7,0x806b);
    saved=half;
    data=func_02049E74((void *)((unsigned)owner),POKE_TOOL_CalcGraphicIndex(species,form,saved,0),0,(unsigned)&out,0x806b);
    if (mode==1) {
        slot=(struct Obj **)(p+0xa74+index*4);
        CLACT_TransferCharacterPart(CLACT_GetActorCharacterIndex((u8 *)*slot),out->f14,1024,0,0);
    } else {
        slot=(struct Obj **)(p+0xa74+index*4);
        CLACT_TransferCharacterPart(CLACT_GetActorCharacterIndex((u8 *)*slot),out->f14,1024,0,1);
    }
    func_020307B0(data);
    func_02049238(owner);
    func_0204B6F4(*slot,func_0201BB5C(species,form,saved,0),1);
}
