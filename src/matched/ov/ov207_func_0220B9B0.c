/*
 * function: func_0220B9B0
 * address: 0x0220B9B0
 * packet: pkt_ov207_0220B9B0
 * region: ov207
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: pooled FS overlay ID is the overlay94 linker symbol address, as in matched ov207 0220B048; literal 94 compiles as movs.
 * symbols:
 *   func_022021F4 0x022021F4 thumb ov094
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_02034A5C 0x02034A5C arm
 *   overlay94 0x0000005E data
 */
typedef struct Obj Obj;struct PalAnmSlot;extern void func_022021F4(Obj *);extern void func_020215A0(struct PalAnmSlot *,unsigned);extern void func_02021540(struct PalAnmSlot *);extern void func_02034A5C(int);
extern char overlay94[];
void func_0220B9B0(char *p){func_022021F4(*(Obj **)(p+84));func_020215A0(*(struct PalAnmSlot **)(p+88),1);func_020215A0(*(struct PalAnmSlot **)(p+88),3);func_02021540(*(struct PalAnmSlot **)(p+88));*(unsigned *)(p+88)=0;func_02034A5C((int)overlay94);}
